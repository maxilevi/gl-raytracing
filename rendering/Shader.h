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
    GLuint CompileShader(const std::string* source, GLenum type);
    GLuint CreateProgram(GLuint vertex_shader_id, GLuint fragment_shader_id);

public:
    static Shader* Build(const std::string* vertex_shader, const std::string* fragment_shader);
    void operator[](std::string uniform_name) const;
    void Bind() const;
    void Unbind() const;
    ~Shader();
};

#endif GLRAYTRACING_SHADER_H
