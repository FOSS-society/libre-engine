#include "../../include/system/Buffer.hpp"
#include <GL/gl.h>
#inc


namespace libre{
  namespace system{
    Buffer::Buffer(float * data, unsigned int count, unsigned int componentCount): m_componentCount(componentCount)
		{
            OpenGL::glGenBuffers(1, &m_bufferID);
            OpenGL::glBindBuffer(GL_ARRAY_BUFFER, m_bufferID);
            OpenGL::glBufferData(GL_ARRAY_BUFFER, count * sizeof(float), data, GL_STATIC_DRAW);
            OpenGL::glBindBuffer(GL_ARRAY_BUFFER, 0);

    }
    Buffer::~Buffer();
    void Buffer::bind()const;
    void Buffer::unbind()const;
    unsigned int Buffer::getComponentCount()const;
  }
}
