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
    GLint _size;
    GLsizeiptr _sizeInBytes;
    GLenum _target;
    GLenum _hint;
    GLenum _pointerType;
    void Initialize(T* data, GLsizeiptr size_in_bytes, GLint size, GLenum pointer_type, GLenum target, GLenum hint);
public:
    VBO(T* data, GLsizeiptr size_in_bytes, GLint size, GLenum pointer_type);
    VBO(T* data, GLsizeiptr size_in_bytes, GLint size, GLenum pointer_type, GLenum target, GLenum hint);
    ~VBO();
    GLenum getPointerType();
    GLint getSize();
    const void Bind();
    const void Unbind();
};


#endif //GLRAYTRACING_VBO_H
