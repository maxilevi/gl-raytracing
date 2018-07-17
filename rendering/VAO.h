/*
 * Created by Maximiliano Levi on 12/07/2018.
 */

#ifndef GLRAYTRACING_VAO_H
#define GLRAYTRACING_VAO_H


#include <GL/glew.h>
#include "VBO.h"

class VAO {

protected:
    GLuint _id;
    int _count;
    VAO();
public:
    void Bind() const;
    void Unbind() const;
    void Draw() const;
};

template< class T1 >
class VAO<T1> : public VAO {
private:
    VBO<T1>* _buffer1;
public:
    VAO(VBO<T1>* Buffer1);
    virtual ~VAO();
};

template< class T1, class T2 >
class VAO<T1, T2> : public VAO<T1> {
private:
    VBO<T2>* _buffer2;
public:
    VAO(VBO<T1>* Buffer1, VBO<T1>* Buffer2);
    virtual ~VAO();
};

template< class T1, class T2, class T3 >
class VAO<T1, T2, T3> : public VAO<T1, T2> {
private:
    VBO<T3>* _buffer3;
public:
    VAO(VBO<T1>* Buffer1, VBO<T2>* Buffer2, VBO<T3>* Buffer3);
    virtual ~VAO();
};
#endif //GLRAYTRACING_VAO_H
