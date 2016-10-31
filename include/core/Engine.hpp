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

/**
      * @brief The Engine class
      *
      * The engine class is self explanatory, it contains these variables so far:
      *
      * Boolean: IsRunning
      * Boolean: IsInitialized
      * Vector<System*> SystemList
      * Vector<Entity*> EntityList
      * Window: Window
      * Renderer: Renderer
      * Keyboard: Keyboard
      * Mouse:Mouse
      * sharedPointer<SDL_Event> eventHandle
      *
      *
      * Engines Update function goes through the application loop. depending on the systems , it will check
      * calculations (such as physics) and determine if things can happen
      *
      * TODO: Add getters to this class
      *       Extend to more then just bools
      *
      * Notes: No setters, just vector's push back wrapping
      *
      *
      * TODO: ADD MORE TO THIS CLASS
      *
      *

*/




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
