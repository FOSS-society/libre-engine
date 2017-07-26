#include "../../include/core/Engine.hpp"
#include "../../include/system/Logger.hpp"

#include "../../include/system/Keyboard.hpp"
#include "../../include/system/Mouse.hpp"

#define DEBUG


namespace libre{

  namespace core{

    Engine::Engine(graphics::Renderer *renderer){

      system::Logger::LogInstance()->Log("Initializing Engine");
      this->m_event = std::make_shared<SDL_Event>();
      this->m_SystemList = std::vector<System*>();
      this->m_EntityList = std::vector<Entity*>();
      this->m_renderer = renderer;
      this->m_window = this->m_renderer->getWindowHandle();

      this->m_time = new system::Time();

      //Handle input creation
      this->m_mouse = new system::Mouse();
      this->m_keyboard = new system::Keyboard();

      this->m_Initialized = true;
      this->m_Running = true;
    }

    void Engine::update(){

#ifdef DEBUG
       std::cout << "Mouse Position: " << m_mouse->getMousePosition().toString() << std::endl;
       std::cout << "Time: "<< m_time->timeElapsed() << std::endl;

#endif // debug

        // Update logic

      //Render to screen.
                SDL_GL_SwapWindow(this->m_window->SDLWIN());




      //update the time
      this->m_time->Update();

    }

    void Engine::addSystem(System *system){
      this->m_SystemList.push_back(system);
   }
    void Engine::addEntity(Entity *entity){
      this->m_EntityList.push_back(entity);
    }

  }

}
