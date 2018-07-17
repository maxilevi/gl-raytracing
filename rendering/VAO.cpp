/*
 * Created by Maximiliano Levi on 12/07/2018.
 */

#include "VAO.h"

template <class T1, class T2, class T3>
VAO<T1, T2, T3>::VAO(VBO<T1>* Buffer1, VBO<T2>* Buffer2, VBO<T3>* Buffer3) : VAO<T1, T2>::VAO(Buffer1, Buffer2)
{
    VAO<T1, T2>::Bind();
    this->_buffer3 = Buffer3;
    glVertexAttribPointer(1, this->_buffer3->getSize(), this->_buffer3->getPointerType(), GL_FALSE, 0, 0);
    VAO<T1, T2>::Unbind();
}

template <class T1, class T2, class T3>
VAO<T1, T2, T3>::~VAO()
{
    VAO<T1, T2>::~VAO();
    delete *(this->_buffer3);
}

template <class T1, class T2>
VAO<T1, T2>::VAO(VBO<T1>* Buffer1, VBO<T2>* Buffer2) : VAO<T1>::VAO(Buffer1)
{
    VAO<T1>::Bind();
    this->_buffer2 = Buffer2;
    glVertexAttribPointer(1, this->_buffer2->getSize(), this->_buffer2->getPointerType(), GL_FALSE, 0, 0);
    VAO<T1>::Unbind();
}

template <class T1, class T2>
VAO<T1, T2>::~VAO()
{
    VAO<T1>::~VAO();
    delete *(this->_buffer2);
}

using VAO::Bind;
template <class T1>
VAO<T1>::VAO(VBO<T1>* Buffer1) : VAO()
{
    VAO::Bind();
    this->_buffer1 = Buffer1;
    glVertexAttribPointer(0, this->_buffer1->getSize(), this->_buffer1->getPointerType(), GL_FALSE, 0, 0);
    VAO::Unbind();
}

template <class T1>
VAO<T1>::~VAO()
{
    delete *(this->_buffer1);
}

VAO::VAO()
{
    glCreateVertexArrays(1, &this->_id);
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