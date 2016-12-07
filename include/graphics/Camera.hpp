#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "graphics_common.hpp"

namespace libre{

namespace graphics{

enum class Direction2D{
    NORTH,NORTHEAST,EAST,
    SOUTHEAST,SOUTH,SOUTHWEST,
    WEST,NORTHWEST
};



    class Camera{

    private:
        math::Vector3<float> m_position;
        math::Vector3<float> m_rotation;

    public:
        Camera(const math::Vector3<float> pos,const math::Vector3<float> rot);






        math::Vector3<float> position() const;
        math::Vector3<float> getPostition();
        void setPosition(const math::Vector3<float> &position);
        math::Vector3<float> rotation() const;
        math::Vector3<float> getRotation();
        void setRotation(const math::Vector3<float> &rotation);
    };




}


}


#endif // CAMERA_HPP
