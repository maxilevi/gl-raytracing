/*
 * Created by Maximiliano Levi on 12/07/2018.
 */

#include "VAO.h"

VAO::VAO()
{
    glCreateVertexArrays(1, &this->_id);
}

void VAO::Draw() const
{

}

void VAO::Bind() const
{
    //glEnableVertexAttribArray();
}

VAO::~VAO()
{
    glDeleteVertexArrays(this._id);
}