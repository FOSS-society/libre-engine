#include "../../include/system/IndexBuffer.hpp"
#include "../../include/system/OpenGL.hpp"

namespace libre{

    namespace system{

        IndexBuffer::IndexBuffer(GLushort *data, GLsizei count):m_count(count){

            OpenGL::genBuffers(1,&m_ID);
            OpenGL::bindBuffers(GL_ELEMENT_ARRAY_BUFFER,m_ID);
            OpenGL::createBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLushort),data,GL_STATIC_DRAW);
            OpenGL::bindBuffers(GL_ELEMENT_ARRAY_BUFFER,0);

        }

        void IndexBuffer::bind() const{
            OpenGL::bindBuffers(GL_ELEMENT_ARRAY_BUFFER,m_ID);

        }
        void IndexBuffer::unbind()const{
            OpenGL::bindBuffers(GL_ELEMENT_ARRAY_BUFFER,0);
        }


    }
}
