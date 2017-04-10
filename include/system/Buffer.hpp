#ifndef BUFFER_HPP_
#define BUFFER_HPP_

#include "../graphics/graphics_common.hpp"
#include "BufferLayout.hpp"

namespace libre{
  namespace system{

  enum class GLBufferUsage{
  STATIC_DRAW,STREAM_DRAW,DYNAMIC_DRAW,
  STATIC_READ,STREAM_READ,DYNAMIC_READ,
  STATIC_COPY,STREAM_COPY,DYNAMIC_COPY

  };

 inline GLenum UsageToGLEnum(const GLBufferUsage &usage){

     switch(usage){
     case GLBufferUsage::STATIC_DRAW: return GL_STATIC_DRAW;
     case GLBufferUsage::STREAM_DRAW: return GL_STREAM_DRAW;
     case GLBufferUsage::DYNAMIC_DRAW: return GL_DYNAMIC_DRAW;

     case GLBufferUsage::STATIC_COPY: return GL_STATIC_COPY;
     case GLBufferUsage::STREAM_COPY: return GL_STREAM_COPY;
     case GLBufferUsage::DYNAMIC_COPY: return GL_DYNAMIC_COPY;

     case GLBufferUsage::STATIC_READ: return GL_STATIC_READ;
     case GLBufferUsage::STREAM_READ: return GL_STREAM_READ;
     case GLBufferUsage::DYNAMIC_READ: return GL_DYNAMIC_READ;

     }


     return 0;
 }


    class Buffer{
    private:
      unsigned int m_bufferID;
      GLBufferUsage m_usage;
      unsigned int m_size;
      BufferLayout m_layout;

      void *InternalPointer();

    public:
      Buffer(GLBufferUsage usage);
      ~Buffer();

      void resize(unsigned int size);
      void setLayout(const BufferLayout &layout);
      void setData(unsigned int size,const void *data);

      void bind()const;
      void unbind()const;

      void ReleasePointer();



    };

  }
}

#endif //Buffer.hpp
