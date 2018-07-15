/*
 * Created by Maximiliano Levi on 12/07/2018.
 */

#ifndef GLRAYTRACING_RENDERER_H
#define GLRAYTRACING_RENDERER_H

#include "Shader.h"
#include "VAO.h"

class Renderer {
private:
    Renderer();

public:
    static void Draw(const Shader* Shader, const VAO* VertexArray);
};


#endif //GLRAYTRACING_RENDERER_H
