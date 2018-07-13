/*
 * Created by Maximiliano Levi on 12/07/2018.
 */

#include "Shader.h"

Shader::Shader()
{

};

static Shader Shader::Build(std::string const& vertex_shader, std::string const& fragment_shader) {
    return Shader();
};

void operator[](std::string const& uniform_name)
{

}

void Shader::Use()
{
    glUseProgram(this->_id);
};

Shader::~Shader()
{
    glDeleteProgram(this->_id);
}

const void Shader::operator[](std::string uniform_name) const
{
    return;
};