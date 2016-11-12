#include "../../include/system/Buffer.hpp"
#include "../../include/system/OpenGL.hpp"



namespace libre{
  namespace system{
  Buffer::Buffer(GLBufferUsage usage):m_usage(usage){

  }

    void *Buffer::InternalPointer()
    {
        return OpenGL::MapBuffer(GL_ARRAY_BUFFER,GL_WRITE_ONLY);
    }

    Buffer::~Buffer(){
        OpenGL::deleteBuffer(1, &m_bufferID);
    }

    void Buffer::resize(unsigned int size)
    {
        m_size = size;

        OpenGL::bindBuffers(GL_ARRAY_BUFFER, m_bufferID);
        OpenGL::createBufferData(GL_ARRAY_BUFFER, size, NULL, system::UsageToGLEnum(m_usage));

    }

    void Buffer::setLayout(const BufferLayout &blayout)
    {
        m_layout = blayout;
                const std::vector<BufferElement>& layout = blayout.Layout();
                for (uint i = 0; i < layout.size(); i++)
                {
                    const BufferElement& element = layout[i];
                    OpenGL::enableVertexArrays(i);
                    OpenGL::VertexAttributePointer(i, element.Count(), element.Type(), element.Normalized(), m_layout.getStride(), (const void*)element.Offset());
                }
    }

    void Buffer::setData(unsigned int size, const void *data)
    {
        OpenGL::bindBuffers(GL_ARRAY_BUFFER, m_bufferID);
        OpenGL::createBufferData(GL_ARRAY_BUFFER, size, data, system::UsageToGLEnum(m_usage));
    }
    void Buffer::bind()const{
      OpenGL::bindBuffers(GL_ARRAY_BUFFER,m_bufferID);
    }
    void Buffer::unbind()const{
        OpenGL::bindBuffers(GL_ARRAY_BUFFER, 0);
    }

    void Buffer::ReleasePointer()
    {
        OpenGL::UnmapBuffer(GL_ARRAY_BUFFER);
    }

  }
}
