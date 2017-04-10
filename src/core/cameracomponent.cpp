#include "../../include/core/cameracomponent.hpp"

#include "../../include/core/transformcomponent.hpp"
#include "../../include/core/Entity.hpp"

namespace libre{

    namespace core{


    CameraComponent::CameraComponent(Entity *parent, const char *name):Component(parent,(char*)name)
    {
        math::Vector3<float> position;
        math::Vector4<float>rotation;
        float fov = 5.0f;
        if(Parent()->findComponentOfType<TransformComponent*>() == nullptr){
            position = math::Vector3<float>(0.0f,0.0f,0.0f);
            rotation = math::Vector4<float>(0.0f,0.0f,0.0f,0.0f);
        }else{
            position = Parent()->findComponentOfType<TransformComponent*>()->position();
            rotation = Parent()->findComponentOfType<TransformComponent*>()->rotation();
        }
        m_camera = new graphics::Camera(position,rotation,5.0f);
        this->Parent()->addComponent(this);
    }

    graphics::Camera *CameraComponent::getCamera()
    {
        return m_camera;
    }

    graphics::Camera *CameraComponent::camera() const
        {
            return m_camera;
        }

        void CameraComponent::setCamera(graphics::Camera *camera)
        {
            m_camera = camera;
        }
    }
}
