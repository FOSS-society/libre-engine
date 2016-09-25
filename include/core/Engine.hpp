#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include <vector>

#include "../graphics/Window.hpp"
#include "../graphics/Renderer.hpp"
#include "Entity.hpp"
#include "System.hpp"
#include "Component.hpp"
#include "../system/Time.hpp"

namespace libre{
   namespace core{



     class Engine{

     private:
       bool m_initialized;
       std::vector<System*> m_SystemList;
       std::vector<Entity*> m_EntityList;

       graphics::Window *m_window;
       system::Time *m_Time;



     };

   }
}

#endif //Engine.hpp
