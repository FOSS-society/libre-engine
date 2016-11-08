#include "../../include/system/VertexArray.hpp"
#include "../../include/system/OpenGL.hpp"

namespace libre{
  namespace system{

    VertexArray::VertexArray()
	{
		OpenGL::genVertexArrays(1, &m_ID);
	}

	VertexArray::~VertexArray()
	{
		for (unsigned int i = 0; i < m_Buffers.size(); i++)
			delete m_Buffers[i];

		OpenGL::deleteVertexArrays(1, &m_ID);
	}

	void VertexArray::addBuffer(Buffer* buffer, GLuint index)
	{
		bind();
		buffer->bind();

		OpenGL::enableVertexArrays(index);

        OpenGL::VertexAttributePointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);

		buffer->unbind();
		unbind();
	}

	void VertexArray::bind() const
	{
        OpenGL::BindVertexArray(m_ID);
	}

	void VertexArray::unbind() const
	{
        OpenGL::BindVertexArray(0);
	}

  }
}
