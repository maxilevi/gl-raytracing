/*
 * Created by Maximiliano Levi on 12/07/2018.
 */

#ifndef GLRAYTRACING_SHADER_H
#define GLRAYTRACING_SHADER_H

#include <GL/glew.h>
#include <string>

class Shader {

private:
    GLuint _id;
    Shader();

public:
    static Shader Build(std::string const& vertex_shader, std::string const& fragment_shader);
    const void operator[](std::string uniform_name) const;
    void Use();
    ~Shader();
};

#endif GLRAYTRACING_SHADER_H
