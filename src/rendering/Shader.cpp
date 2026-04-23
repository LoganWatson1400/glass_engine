#include "rendering/Shader.h"
#include <glm/gtc/type_ptr.hpp>
#include <cstdio>

static GLuint compileStage(GLenum type, const char* src)
{
    GLuint s = glCreateShader(type);
    glShaderSource(s, 1, &src, nullptr);
    glCompileShader(s);

    GLint ok;
    glGetShaderiv(s, GL_COMPILE_STATUS, &ok);
    if (!ok) {
        char log[512];
        glGetShaderInfoLog(s, sizeof(log), nullptr, log);
        printf("Shader compile error:\n%s\n", log);
        glDeleteShader(s);
        return 0;
    }
    return s;
}

bool Shader::compile(const char* vertSrc, const char* fragSrc)
{
    GLuint vert = compileStage(GL_VERTEX_SHADER,   vertSrc);
    GLuint frag = compileStage(GL_FRAGMENT_SHADER, fragSrc);
    if (!vert || !frag) return false;

    id = glCreateProgram();
    glAttachShader(id, vert);
    glAttachShader(id, frag);
    glLinkProgram(id);

    GLint ok;
    glGetProgramiv(id, GL_LINK_STATUS, &ok);
    if (!ok) {
        char log[512];
        glGetProgramInfoLog(id, sizeof(log), nullptr, log);
        printf("Shader link error:\n%s\n", log);
        glDeleteProgram(id);
        id = 0;
    }

    glDeleteShader(vert);
    glDeleteShader(frag);
    return id != 0;
}

void Shader::use() const
{
    glUseProgram(id);
}

void Shader::setMat4(const std::string& name, const glm::mat4& mat) const
{
    GLint loc = glGetUniformLocation(id, name.c_str());
    glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::free()
{
    if (id) { glDeleteProgram(id); id = 0; }
}
