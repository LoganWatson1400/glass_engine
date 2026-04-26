
#ifndef GLASS_ENGINE_SHADER_HH
#define GLASS_ENGINE_SHADER_HH

#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>

class Shader {
public:
    GLuint id = 0;

    bool compile(const char* vertSrc, const char* fragSrc);
    void use() const;
    void setMat4(const std::string& name, const glm::mat4& mat) const;
    void free();
};

#endif //GLASS_ENGINE_SHADER_HH