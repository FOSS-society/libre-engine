#include "../../include/core/Engine.hpp"


namespace libre{

  namespace core{

    Engine::Engine(graphics::Renderer *renderer){
      this->m_SystemList = std::vector<System*>();
      this->m_EntityList = std::vector<Entity*>();
      this->m_renderer = renderer;
      this->m_window = this->m_renderer->getWindowHandle();

      this->m_time = new system::Time();

      this->m_initialized = true;
    }

    void Engine::update(){
      this->m_time->Update();
    }


  }

}
