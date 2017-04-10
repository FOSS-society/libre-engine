#ifndef VERTEX_ARRAY_HPP_
#define VERTEX_ARRAY_HPP_

#include <vector>
#include "Buffer.hpp"

namespace libre{
  namespace system{

    class VertexArray{
    private:
      unsigned int m_ID;
      std::vector<Buffer*> m_Buffers;

    public:
      VertexArray();
      ~VertexArray();

      void addBuffer(Buffer * buff);

      inline Buffer* getBuffer(unsigned int index) { return m_Buffers[index];}

      void bind()const;
      void unbind()const;

      void draw(unsigned int count);

    };

  }
}

#endif
