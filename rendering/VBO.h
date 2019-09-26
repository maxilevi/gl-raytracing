/*
 * Created by Maximiliano Levi on 12/07/2018.
 */

#ifndef GLRAYTRACING_VBO_H
#define GLRAYTRACING_VBO_H

#define BUFFER_OFFSET(i) ((void*)(i))
#include <GL/glew.h>

class BaseVBO {
	protected:
		GLuint _id;
		GLint _size;
		GLsizeiptr _sizeInBytes;
		GLenum _target;
		GLenum _hint;
		GLenum _pointerType;
	public:
		~BaseVBO();
		GLenum getPointerType();
		GLint getSize();
		const void bind();
		const void unbind();
};

template<class T> class VBO : BaseVBO
{
	private:
		void Initialize(T* data, GLsizeiptr size_in_bytes, GLint size, GLenum pointer_type, GLenum target, GLenum hint);
	public:
		VBO(T* data, GLsizeiptr size_in_bytes, GLint size, GLenum pointer_type);
		VBO(T* data, GLsizeiptr size_in_bytes, GLint size, GLenum pointer_type, GLenum target, GLenum hint);
};


#endif //GLRAYTRACING_VBO_H
