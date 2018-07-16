/*
 * Created by Maximiliano Levi on 12/07/2018.
 */

#ifndef GLRAYTRACING_VBO_H
#define GLRAYTRACING_VBO_H

#define BUFFER_OFFSET(i) ((void*)(i))
#include <GL/glew.h>

template<class T> class VBO{
private:
    GLuint _id;
    GLsizeiptr _size;
    GLenum _target;
    GLenum _hint;
    void Initialize(T* data, GLsizeiptr size, GLenum target, GLenum hint);
public:
    VBO(T* data, GLsizeiptr size);
    VBO(T* data, GLsizeiptr size, GLenum target, GLenum hint);
    ~VBO();
    const void Use();
};


#endif //GLRAYTRACING_VBO_H
