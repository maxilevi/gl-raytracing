/*
 * Created by Maximiliano Levi on 12/07/2018.
 */

#include "VBO.h"

template <class T>
VBO::VBO(T* data, GLsizeiptr size_in_bytes, GLint size, GLenum pointer_type, GLenum target, GLenum hint)
{
    this->Initialize(data, size_in_bytes, size, pointer_type, target, hint);
};

template <class T>
VBO::VBO(T* data, GLsizeiptr size_in_bytes, GLint size, GLenum pointer_type)
{
    this->Initialize(data, size_in_bytes, size, pointer_type, GL_ARRAY_BUFFER, GL_STATIC_DRAW);
};

template <class T>
void VBO::Initialize(T* data, GLsizeiptr size_in_bytes, GLint size, GLenum pointer_type, GLenum target, GLenum hint)
{
    this->_hint = hint;
    this->_target = target;
    this->_sizeInBytes = size_in_bytes;
    this->_pointerType = pointer_type;
    glGenBuffers(1, &this->_id);
    this->Bind();
    glBufferData(this->_target, this->_sizeInBytes, data, this->_hint);
};

VBO::~VBO()
{
    glDeleteBuffers(1, &this->_id);
}

const void VBO::Bind()
{
    glBindBuffer(this->_target, this->_id);
}

const void VBO::Unbind()
{
    glBindBuffer(this->_target, 0);
}

GLenum VBO::getPointerType()
{
    return this->_pointerType;
};

GLint VBO::getSize()
{
    return this->_size;
};

