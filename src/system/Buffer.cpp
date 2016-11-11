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

        OpenGL::bindBuffers(GL_ARRAY_BUFFER, m_Handle);
        OpenGL::createBufferData(GL_ARRAY_BUFFER, size, NULL, system::UsageToGLEnum(m_usage));

    }

    void Buffer::setLayout(const BufferLayout &layout)
    {
        m_Layout = bufferLayout;
                const std::vector<BufferElement>& layout = bufferLayout.GetLayout();
                for (uint i = 0; i < layout.size(); i++)
                {
                    const BufferElement& element = layout[i];
                    OpenGL::enableVertexAttribArray(i);
                    OpenGL::VertexAttributePointer(i, element.count, element.type, element.normalized, bufferLayout.GetStride(), (const void*)element.offset);
                }
    }

    void Buffer::setData(unsigned int size, const void *data)
    {
        OpenGL::bindBuffers(GL_ARRAY_BUFFER, m_Handle);
        OpenGL::createBufferData(GL_ARRAY_BUFFER, size, NULL, system::UsageToGLEnum(m_usage));
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
