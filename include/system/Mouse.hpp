#ifndef MOUSE_HPP
#define MOUSE_HPP

#include "../math/vector2.hpp"
#include <SDL2/SDL.h>

namespace libre{
    namespace system{

    enum class ButtonPress{
      LEFT,MIDDLE,RIGHT,X1 , X2, NONE
    };


    class Mouse{

    private:
        math::Vector2<int32_t> mousePosition;
        ButtonPress m_ButtonPress;



    public:
        Mouse();


        void setMousePosition(int x, int y);
        void setButtonPress(ButtonPress press);
        inline math::Vector2<int32_t> getMousePosition(){ return this->mousePosition;}
        inline ButtonPress getButtonPress(){return this->m_ButtonPress;}

    };


    }
}


#endif // MOUSE_HPP
