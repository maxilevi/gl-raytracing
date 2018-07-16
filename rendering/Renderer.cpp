/*
 * Created by Maximiliano Levi on 12/07/2018.
 */

#include "Renderer.h"
#include "../IO.h"

Renderer::Renderer()
{
    const std::string* vertexShader = IO::ReadString("Shaders/default.vert");
    const std::string* fragmentShader = IO::ReadString("Shaders/default.frag");
    this->_mainShader = Shader::Build(vertexShader, fragmentShader);
    GLfloat vertices[] = {0f,0f, .5f,1f, 1f,0f};//{1.0f,1.0f, -1.0f,1.0f, -1.0f,-1.0f, 1.0f,-1.0f, 1.0f,1.0f, -1.0f,-1.0f};
    VBO<GLfloat>* vertexBuffer = new VBO<GLfloat>(vertices, 6 * sizeof(GLfloat), 1, GL_FLOAT);//12 * sizeof(GLfloat));
    this->_mainVAO = new VAO(&vertexBuffer, 1);
}

void Renderer::Draw()
{
    this->DrawObject(this->_mainShader, this->_mainVAO);
}

void Renderer::DrawObject(const Shader* Shader, const VAO* VertexArray)
{
    Shader->Bind();
    VertexArray->Bind();
    VertexArray->Draw();
    VertexArray->Unbind();
    Shader->Unbind();
}

Renderer::~Renderer()
{
    delete this->_mainVAO;
    delete this->_mainShader;
}
