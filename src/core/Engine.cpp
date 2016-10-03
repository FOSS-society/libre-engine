#include "../../include/core/Engine.hpp"
#include "../../include/system/Logger.hpp"

namespace libre{

  namespace core{

    Engine::Engine(graphics::Renderer *renderer){

      system::Logger::LogInstance()->Log("Initializing Engine");

      this->m_SystemList = std::vector<System*>();
      this->m_EntityList = std::vector<Entity*>();
      this->m_renderer = renderer;
      this->m_window = this->m_renderer->getWindowHandle();

      this->m_time = new system::Time();

      this->m_initialized = true;
    }

    void Engine::update(){
      //Handle Events

      // Update logic

      //Render to screen

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
