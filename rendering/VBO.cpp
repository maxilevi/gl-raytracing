/*
 * Created by Maximiliano Levi on 12/07/2018.
 */

#include "VBO.h"

template <class T>
VBO::VBO(T* data, GLsizeiptr size, GLenum target, GLenum hint)
{
    this->Initialize(data, size, target, hint);
};

template <class T>
VBO::VBO(T* data, GLsizeiptr size)
{
    this->Initialize(data, size, GL_ARRAY_BUFFER, GL_STATIC_DRAW);
};

template <class T>
void VBO::Initialize(T* data, GLsizeiptr size, GLenum target, GLenum hint)
{
    this->_hint = hint;
    this->_target = target;
    this->_size = size;

    glGenBuffers(1, &this->_id);
    glBufferData(this->_target, this->_size, data, this->_hint);
};


VBO::~VBO()
{
    glDeleteBuffers(1, &this->_id);
}

const void VBO::Use()
{
    glBindBuffer(this->_target, this->_id);
};

