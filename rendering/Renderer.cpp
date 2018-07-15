/*
 * Created by Maximiliano Levi on 12/07/2018.
 */

#include "Renderer.h"

Renderer::Renderer()
{
}

void Renderer::Draw(const Shader* Shader, const VAO* VertexArray)
{
    Shader->Bind();
    VertexArray->Bind();
    VertexArray->Draw();
    VertexArray->Unbind();
    Shader->Unbind();
}