/*
 * Created by Maximiliano Levi on 12/07/2018.
 */

#ifndef GLRAYTRACING_VAO_H
#define GLRAYTRACING_VAO_H


#include <GL/glew.h>
#include "VBO.h"

class VAO {

protected:
    GLuint _id;
    int _count;
    VBO** _buffers;
public:
    VAO(VBO** buffers, int count);
    ~VAO();
    void Bind() const;
    void Unbind() const;
    void Draw() const;
};

template< class T1 >
class VAO<T1> : VAO {
public:
    VAO(VBO<T1> Buffer1);
    ~VAO();
};
#endif //GLRAYTRACING_VAO_H
