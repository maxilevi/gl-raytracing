/*
 * Created by Maximiliano Levi on 12/07/2018.
 */

#include "VBO.h"

template< class T >
VBO::VBO(T* data, GLsizeiptr size)
{
    glGenBuffers(1, &this->_id);
    glBufferData(this->_target, size, data, this->_usage);
};

VBO::~VBO()
{
    glDeleteBuffers(1, &this->_id);
}

const void VBO::Use()
{
    glBindBuffer(this->_target, this->_id);
};

