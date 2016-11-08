#ifndef VERTEXFORMAT_H
#define VERTEXFORMAT_H

#include "../math/libremath.hpp"

namespace libre{

    namespace system{

    class vertexFormat{

    private:
        math::Vector3<float> m_position;


    public:
        vertexFormat(const math::Vector3<float> &pos):m_position(pos){}

        void setPosition(const math::Vector3<float> &pos){
            m_position = pos;
        }

        inline math::Vector3<float> getPosition(){ return m_position;}
        inline math::Vector3<float> Position()const {return m_position;}



    };



    }
}




#endif // VERTEXFORMAT_H
