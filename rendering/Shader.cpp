/*
 * Created by Maximiliano Levi on 12/07/2018.
 */

#include "Shader.h"
#include "iostream"

Shader::Shader(GLuint id)
{
    this->_id = id;
};

static Shader* Shader::Build(const std::string* vertex_shader, const std::string* fragment_shader)
{
    GLuint vertex_id = Shader::CompileShader(vertex_shader, GL_VERTEX_SHADER);
    GLuint fragment_id = Shader::CompileShader(fragment_shader, GL_FRAGMENT_SHADER);
    return new Shader(Shader::CreateProgram(vertex_id, fragment_id));
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
    delete[] p;
}

static GLuint Shader::CreateProgram(GLuint vertex_shader_id, GLuint fragment_shader_id)
{
    GLuint programId = glCreateProgram();
    glAttachShader(programId, vertex_shader_id);
    glAttachShader(programId, fragment_shader_id);
    glLinkProgram(programId);
    glDetachShader(programId, vertex_shader_id);
    glDetachShader(programId, fragment_shader_id);
    glDeleteShader(vertex_shader_id);
    glDeleteShader(fragment_shader_id);
    return programId;
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