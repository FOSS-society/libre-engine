#ifndef BUFFERLAYOUT_H
#define BUFFERLAYOUT_H

#include <vector>



#include "../math/libremath.hpp"
#include "BufferElement.hpp"
#include "../system/Logger.hpp"
namespace libre{

namespace system {


    class BufferLayout{

    private:
        unsigned int m_size;
        std::vector<BufferElement> m_layout;

    public:
        BufferLayout();

        void pushElementf(const std::string& name, unsigned int count, bool normalized)
        {
            pushElement(name,GL_FLOAT,sizeof(float),count,normalized);
        }

        void pushElementui32(const std::string &name, unsigned int count, bool normalized){
            pushElement(name,GL_UNSIGNED_INT,sizeof(uint32_t),count,normalized);
        }

        void pushElementui8(const std::string &name, unsigned int count, bool normalized){
            pushElement(name,GL_UNSIGNED_BYTE,sizeof(uint8_t),count,normalized);
        }

        void pushElementvec2(const std::string &name, unsigned int count, bool normalized){
            pushElement(name,GL_FLOAT, sizeof(float), 2, normalized);
        }

        void pushElementvec3(const std::string &name, unsigned int count, bool normalized){
            pushElement(name,GL_FLOAT, sizeof(float), 3, normalized);
        }

        void pushElementvec4(const std::string &name, unsigned int count, bool normalized){
            pushElement(name,GL_FLOAT, sizeof(float), 4, normalized);
        }


        inline const std::vector<BufferElement> &Layout() const { return m_layout;}
        inline unsigned int getStride() const {return m_size;}

    private:
        void pushElement(const std::string& name, unsigned int type,
                  unsigned int size, unsigned int count,
                  bool normalized);


    };



}


}

#endif // BUFFERLAYOUT_H
