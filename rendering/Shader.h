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
    explicit Shader(GLuint id);

public:
    static Shader* Build(const char* vertex_shader, const char* fragment_shader);
    void Bind() const;
    void Unbind() const;
    ~Shader();
};

#endif GLRAYTRACING_SHADER_H
