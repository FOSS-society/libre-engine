#include "../../include/system/Buffer.hpp"
#include "../../include/system/OpenGL.hpp"



namespace libre{
  namespace system{
    Buffer::Buffer(float * data, unsigned int count, unsigned int componentCount): m_componentCount(componentCount)
		{
            OpenGL::genBuffers(1, &m_bufferID);
            OpenGL::bindBuffers(GL_ARRAY_BUFFER, m_bufferID);
            OpenGL::createBufferData(GL_ARRAY_BUFFER, count * sizeof(float), data, GL_STATIC_DRAW);
            OpenGL::bindBuffers(GL_ARRAY_BUFFER, 0);

    }
    Buffer::~Buffer(){
      OpenGL::deleteBuffer(1, &m_bufferID);
    }
    void Buffer::bind()const{
      OpenGL::bindBuffers(GL_ARRAY_BUFFER,m_bufferID);
    }
    void Buffer::unbind()const{
      OpenGL::bindBuffers(GL_ARRAY_BUFFER, 0);
    }
    unsigned int Buffer::getComponentCount()const{
      return m_componentCount;
    }
  }
}
