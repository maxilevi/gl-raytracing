/*
 * Created by Maximiliano Levi on 12/07/2018.
 */

#ifndef GLRAYTRACING_VBO_H
#define GLRAYTRACING_VBO_H

#define BUFFER_OFFSET(i) ((void*)(i))
#include <GL/glew.h>

template<class T> class VBO {
private:
    GLuint _id;
    GLenum _target;
    GLenum _usage;
public:
    VBO(T* data, int size);
    ~VBO();
    void Use();
};


#endif //GLRAYTRACING_VBO_H
