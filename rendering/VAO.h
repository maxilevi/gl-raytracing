/*
 * Created by Maximiliano Levi on 12/07/2018.
 */

#ifndef GLRAYTRACING_VAO_H
#define GLRAYTRACING_VAO_H


#include <GL/glew.h>

class VAO {

private:
    GLuint _id;
public:
    VAO();
    ~VAO();
    void Bind() const;
    void Unbind() const;
    void Draw() const;
};


#endif //GLRAYTRACING_VAO_H
