/*
 * Created by Maximiliano Levi on 12/07/2018.
 */

#include "Shader.h"
#include "iostream"

Shader::Shader(GLuint id)
{
    this->_id = id;
};

static GLuint CompileShader(const char* source, GLenum type)
{
    GLuint id = glCreateShader(type);
    const GLchar* as_char_array = source;
    glShaderSource(id, 1, &as_char_array, nullptr);
    glCompileShader(id);
    GLint compilation_result = -1;
    glGetShaderiv(id, GL_COMPILE_STATUS, &compilation_result);
    int size = 512;
    GLchar* p = new char[size];
    glGetShaderInfoLog(id, size, nullptr, p);
    std::cout << (compilation_result == -1 ? "[OK]" : "[FAIL]") << "Compiled " << type << " shader " << id << std::endl;
    if(compilation_result != -1) {
        std::cout << p << std::endl;
    }
    delete[] p;
	return id;
}

static GLuint CreateProgram(GLuint vertex_shader_id, GLuint fragment_shader_id)
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

Shader* Shader::Build(const char* vertex_shader, const char* fragment_shader)
{
	GLuint vertex_id = CompileShader(vertex_shader, GL_VERTEX_SHADER);
	GLuint fragment_id = CompileShader(fragment_shader, GL_FRAGMENT_SHADER);
	Shader* shader = new Shader(CreateProgram(vertex_id, fragment_id));
	return shader;
};

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