#include "rendering/Shader.hh"
#include "core/log/Log.hh"

#include <glm/gtc/type_ptr.hpp>

static GLuint compileStage(GLenum type, const char *src) {
	GLuint s = glCreateShader(type);

	glShaderSource(s, 1, &src, nullptr);
	glCompileShader(s);

	GLint ok = 0;
	glGetShaderiv(s, GL_COMPILE_STATUS, &ok);

	if (!ok) {
		GLint logLen = 0;
		glGetShaderiv(s, GL_INFO_LOG_LENGTH, &logLen);

		if (logLen > 1) {
			std::string log(logLen, '\0');

			glGetShaderInfoLog(s, logLen, nullptr, log.data());

			LOG_ERROR(log.c_str());
		} else {
			LOG_ERROR("Shader compilation failed with no driver log");
		}

		glDeleteShader(s);
		return 0;
	}

	return s;
}

bool Shader::compile(const char *vertSrc, const char *fragSrc) {
	GLuint vert = compileStage(GL_VERTEX_SHADER, vertSrc);
	GLuint frag = compileStage(GL_FRAGMENT_SHADER, fragSrc);

	if (!vert || !frag)
		return false;

	id = glCreateProgram();

	glAttachShader(id, vert);
	glAttachShader(id, frag);

	glLinkProgram(id);

	GLint ok = 0;
	glGetProgramiv(id, GL_LINK_STATUS, &ok);

	if (!ok) {
		GLint logLen = 0;
		glGetProgramiv(id, GL_INFO_LOG_LENGTH, &logLen);

		std::string log(logLen, '\0');

		glGetProgramInfoLog(id, logLen, nullptr, log.data());

		LOG_ERROR(log.c_str());

		glDeleteProgram(id);
		id = 0;
	}

	glDeleteShader(vert);
	glDeleteShader(frag);

	return id != 0;
}

void Shader::use() const {
	glUseProgram(id);
}

void Shader::setMat4(const std::string &name, const glm::mat4 &mat) const {
	GLint loc = glGetUniformLocation(id, name.c_str());

	glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::free() {
	if (id) {
		glDeleteProgram(id);
		id = 0;
	}
}