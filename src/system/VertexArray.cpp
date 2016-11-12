#include "../../include/system/VertexArray.hpp"
#include "../../include/system/OpenGL.hpp"

namespace libre{
  namespace system{

    VertexArray::VertexArray()
	{
	}

	VertexArray::~VertexArray()
	{
	}

    void VertexArray::addBuffer(Buffer* buffer)
	{
        this->m_Buffers.push_back(buffer);
	}

	void VertexArray::bind() const
	{
        m_Buffers.front()->bind();
	}

	void VertexArray::unbind() const
	{
        m_Buffers.front()->unbind();
    }

    void VertexArray::draw(unsigned int count){
        OpenGL::drawElements(GL_TRIANGLES,count,GL_UNSIGNED_INT,NULL);
    }

  }
}
