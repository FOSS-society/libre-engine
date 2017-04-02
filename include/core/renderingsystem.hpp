#ifndef RENDERINGSYSTEM_HPP
#define RENDERINGSYSTEM_HPP

#include "System.hpp"
#include "graphics/Renderer.hpp"
#include "graphics/Camera.hpp"
namespace libre{

    namespace core{

class RenderingSystem : public System
{
private:
    graphics::Renderer *m_renderer;
    graphics::Camera *m_camera;

public:
    RenderingSystem(graphics::Renderer *renderer);
    RenderingSystem(graphics::Renderer *renderer, Entity *root);

    // System interface
public:
    void initialize();
    void update();
    void fixedUpdate();
    void destroyed();
};

    }
}

#endif // RENDERINGSYSTEM_HPP
