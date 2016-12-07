#include "../../include/graphics/Camera.hpp"


namespace libre{

namespace graphics{


math::Vector3<float> Camera::rotation() const
{
    return m_rotation;
}

math::Vector3<float> Camera::getRotation()
{
    return m_rotation;
}

void Camera::setRotation(const math::Vector3<float> &rotation)
{
    m_rotation = rotation;
}
math::Vector3<float> Camera::position() const
{
    return m_position;
}

math::Vector3<float> Camera::getPostition()
{
    return m_position;
}

void Camera::setPosition(const math::Vector3<float> &position)
{
    m_position = position;
}

}
}
