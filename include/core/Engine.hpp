#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include <vector>

#include "../graphics/Window.hpp"
#include "../graphics/Renderer.hpp"
#include "Entity.hpp"
#include "System.hpp"
#include "Component.hpp"
#include "../system/Time.hpp"
#include<memory>

namespace libre{

    //foward declare input classes

    namespace system{
    class Keyboard;
    class Mouse;
    }

namespace core{



     class Engine{

     private:
       bool m_Initialized;
       bool m_Running;
       std::vector<System*> m_SystemList;
       std::vector<Entity*> m_EntityList;
       graphics::Window *m_window;
       graphics::Renderer *m_renderer;
       system::Time *m_time;
       system::Keyboard *m_keyboard;
       system::Mouse *m_mouse;
       std::shared_ptr<SDL_Event> m_event;


     public:
       Engine(graphics::Renderer *renderer);

       void update();
       void addSystem(System *system);
       void addEntity(Entity *entity);

       bool isInitialized(){
           return this->m_Initialized;
       }

       bool isRunning(){
           return this->m_Running;
       }

     };

   }
}

#endif //Engine.hpp
