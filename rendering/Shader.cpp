/*
 * Created by Maximiliano Levi on 12/07/2018.
 */

#include "Shader.h"
#include "iostream"

Shader::Shader()
{

};

static Shader* Shader::Build(const std::string* vertex_shader, const std::string* fragment_shader) {
    return new Shader();
};

static GLuint Shader::CompileShader(const std::string* source, GLenum type)
{
    GLuint id = glCreateShader(type);
    const GLchar* as_char_array = source->c_str();
    glShaderSource(id, 1, &as_char_array, NULL);
    glCompileShader(id);
    GLint compilation_result = -1;
    glGetShaderiv(id, GL_COMPILE_STATUS, &compilation_result);
    int size = 512;
    GLchar* p = new char[size];
    glGetShaderInfoLog(id, size, nullptr, p);
    std::cout << (compilation_result == -1 ? "[OK]" : "[FAIL]") << "Compiled " << type << " shader " << id << std::endl;
    if(compilation_result != -1) {
        std::cout << log << std::endl;
    }
}

static GLuint Shader::CreateProgram(GLuint vertex_shader_id, GLuint fragment_shader_id)
{

}

void Shader::Bind() const
{
    glUseProgram(this->_id);
};

void Shader::Unbind() const
{
    glUseProgram(0);
};

Shader::~Shader()
{
    glDeleteProgram(this->_id);
}

void Shader::operator[](std::string uniform_name) const
{
    return;
};