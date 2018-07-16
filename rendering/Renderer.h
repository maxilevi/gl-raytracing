/*
 * Created by Maximiliano Levi on 12/07/2018.
 */

#ifndef GLRAYTRACING_RENDERER_H
#define GLRAYTRACING_RENDERER_H

#include "Shader.h"
#include "VAO.h"

class Renderer {
private:
    Shader* _mainShader;
    VAO* _mainVAO;
    void DrawObject(const Shader* Shader, const VAO* VertexArray);
public:
    Renderer();
    void Draw();
    ~Renderer();
};


#endif //GLRAYTRACING_RENDERER_H
