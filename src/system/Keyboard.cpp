#include "../../include/system/Keyboard.hpp"

namespace libre{
    namespace system{

    Keyboard::Keyboard()
    {
        for(int i = 0;i< 323;i++){
            m_keys[i] = false;
            m_keysHeld[i] = false;
        }
    }

    bool Keyboard::keyDown(int index)
    {
        return m_keys[index];
    }

   bool Keyboard::keyHeld(int index){
       return m_keysHeld[index];
   }

   void Keyboard::setKeyDown(int index){
        this->m_keys[index] = true;
   }
   void Keyboard::setKeyUp(int index){
        this->m_keys[index] = false;
   }

   void Keyboard::setKeyHeldDown(int index){
        this->m_keysHeld[index] = true;
   }

   void Keyboard::setKeyHeldUp(int index){
       this->m_keysHeld[index] = false;
    }



   }

}
