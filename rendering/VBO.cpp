/*
 * Created by Maximiliano Levi on 12/07/2018.
 */

#include "VBO.h"

VBO::VBO(T* data, int size)
{
    glGenBuffers(1, &this->_id);
    glBufferData(this->_target, sizeof(data) * 3, data, this->_usage);
};

VBO::~VBO()
{
    glDeleteBuffers(1, &this->_id);
}

void VBO::Use()
{
    glBindBuffer(this->_target, this->_id);
};

