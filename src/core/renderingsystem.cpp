#include "../../include/core/renderingsystem.hpp"
#include "../../include/core/Entity.hpp"
#include "../../include/core/cameracomponent.hpp"
#include "../../include/core/spritecomponent.hpp"


namespace libre{
    namespace core{

        RenderingSystem::RenderingSystem(graphics::Renderer *renderer): System(), m_renderer(renderer)
        {

        }

        RenderingSystem::RenderingSystem(graphics::Renderer *renderer, Entity *root) : System(root),m_renderer(renderer)
        {

        }

        void RenderingSystem::initialize()
        {
            m_camera = getRoot()->findComponentOfType<CameraComponent*>()->getCamera();
            switch(m_renderer->getType()){
            case graphics::RendererType::RT_2D:
                for(Entity *i  : getRoot()->getChildren()){
                    if(i->findComponentOfType<SpriteComponent*>() != nullptr){
                        this->getList()->push_back(i);
                    }
                }
                break;
            case graphics::RendererType::RT_3D:
              // for(Entity *i  : getRoot()->getChildren()){
              //     if(i->findComponentOfType<SpriteComponent>() != nullptr){
              //         m_list->push_back(i);
              //      }
              //  }
                break;
            default:
                throw graphics::RendererException("Unable to determine renderer type");
                break;
            }

        }

        void RenderingSystem::update()
        {

        }

        void RenderingSystem::destroyed()
        {

        }
    }
}
