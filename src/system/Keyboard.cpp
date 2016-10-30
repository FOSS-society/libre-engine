#include "../../include/system/Keyboard.hpp"

namespace libre{
    namespace system{

    Keyboard::Keyboard():m_event(new SDL_Event)
    {
        for(int i = 0;i< 323;i++){
            m_keys[i] = false;
            m_keysHeld[i] = false;
        }
    }

    Keyboard::Keyboard(SDL_Event *event):m_event(event)
    {
        for(int i = 0;i< 323;i++){
            m_keys[i] = false;
            m_keysHeld[i] = false;
        }
    }

    void Keyboard::KeyboardCallback()
{
    if(SDL_PollEvent(this->m_event)){
    switch(this->m_event->type){
    case SDL_KEYDOWN:
       if(m_keys[m_event->key.keysym.sym]){
        m_keysHeld[m_event->key.keysym.sym] = true;
        }else
        m_keys[m_event->key.keysym.sym] = true;
        break;
    case SDL_KEYUP:
     if(m_keys[m_event->key.keysym.sym]){
     m_keysHeld[m_event->key.keysym.sym] = false;
     m_keys[m_event->key.keysym.sym] = false;
     }else
     m_keys[m_event->key.keysym.sym] = false;
     break;
     }
    }



    }

   }

}
