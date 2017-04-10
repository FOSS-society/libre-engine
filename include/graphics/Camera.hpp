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
        math::Vector4<float> m_rotation;
        float m_fov;

    public:
        Camera(const math::Vector3<float> pos,const math::Vector4<float> rot,
               const float fov);






        math::Vector3<float> position() const;
        math::Vector3<float> getPostition();
        void setPosition(const math::Vector3<float> &position);
        math::Vector4<float> rotation() const;
        math::Vector4<float> getRotation();
        void setRotation(const math::Vector4<float> &rotation);
        float fov() const;
        void setFov(float fov);
    };




}


}


#endif // CAMERA_HPP
