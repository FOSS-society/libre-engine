#ifndef CAMERACOMPONENT_HPP
#define CAMERACOMPONENT_HPP


#include "../graphics/Camera.hpp"
#include "Component.hpp"
namespace libre{
namespace core{


class CameraComponent : public Component
{
private:
    graphics::Camera *m_camera;
public:
    CameraComponent(Entity *parent, const char *name);

    graphics::Camera *getCamera();
    graphics::Camera *camera() const;
    void setCamera(graphics::Camera *camera);
};

}
}

#endif // CAMERACOMPONENT_HPP
