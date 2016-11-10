#ifndef INDEXBUFFER_HPP
#define INDEXBUFFER_HPP

#include <GL/glew.h>

namespace libre{

    namespace system{

    class IndexBuffer{

    private:
       GLuint m_ID;
       GLuint m_count;
    public:
       IndexBuffer(GLushort* data, GLsizei count);

       void bind() const;
       void unbind()const;

       inline GLuint getCount()const { return m_count;}

    };

    }
}



#endif // INDEXBUFFER_HPP
