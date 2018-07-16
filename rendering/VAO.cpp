/*
 * Created by Maximiliano Levi on 12/07/2018.
 */

#include "VAO.h"

VAO::VAO(VBO** buffers, int count)
{
    this->_count = count;
    this->_buffers = buffers;
    glCreateVertexArrays(1, &this->_id);
    this->Bind();
    GLuint i = 0;
    for(VBO* buffer = *buffers; buffer < *buffers + count; buffer++)
    {
        buffer->Bind();
        glVertexAttribPointer(i, buffer->getSize(), buffer->getPointerType(), GL_FALSE, 0, 0);
        i++;
    }
    this->Unbind();
}

void VAO::Draw() const
{
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

void VAO::Bind() const
{
    glBindVertexArray(this->_id);
    for(GLuint i = 0; i < this->_count; i++)
    {
        glEnableVertexAttribArray(i);
    }
}

void VAO::Unbind() const
{
    glBindVertexArray(0);
    for(GLuint i = 0; i < this->_count; i++)
    {
        glDisableVertexAttribArray(i);
    }
}

VAO::~VAO()
{
    glDeleteVertexArrays(1, &this->_id);
    for(VBO* buffer = *this->_buffers; buffer < *this->_buffers + this->_count; buffer++)
    {
        delete *buffer;
    }
    delete this->_count;
}