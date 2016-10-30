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
      this->m_mouse = new system::Mouse(this->m_event.get());
      this->m_keyboard = new system::Keyboard(this->m_event.get());

      this->m_Initialized = true;
      this->m_Running = true;
    }

    void Engine::update(){
      //Handle Events
      this->m_mouse->MousePositionCallback();
      this->m_keyboard->KeyboardCallback();
#ifdef DEBUG
       std::cout << "Mouse Position: " << m_mouse->getMousePosition().toString() << std::endl;

#endif // debug

        // Update logic

      //Render to screen

        switch(this->m_renderer->getType()){
            case graphics::RendererType::RT_2D: //treat as SDL
                SDL_RenderPresent(this->m_renderer->getContext()->asSDL);
            break;
            case graphics::RendererType::RT_3D:
                //treat as OpenGL.... figure out how to do that..
            break;

       }


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
