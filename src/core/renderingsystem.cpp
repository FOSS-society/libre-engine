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
              //Not Yet Implemented
               //for(Entity *i  : getRoot()->getChildren()){
               //    if(i->findComponentOfType<MeshComponent>() != nullptr){
               //        this->getList()->push_back(i);
               //     }
               // }
                break;
            default:
                throw graphics::RendererException("Unable to determine renderer type");
                break;
            }

        }

        void RenderingSystem::update()
        {
            switch(m_renderer->Type())
            {
            case graphics::RendererType::RT_2D:

                // Grab each Entity which is in view
                // All must be IN ORDER from camera's Z variable

                //load them into the renderer

                // swap Rendering buffers

                break;
            case graphics::RendererType::RT_3D:
                // Grab each Entity which is in view

                //load them into the renderer

               //Deal with post-processing

                //Swap buffers

                break;
            }

        }

        void RenderingSystem::destroyed()
        {
         delete this->m_camera;
         delete this->m_list;
         delete this->m_renderer;
         delete this->m_root;

        }
    }
}
