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


        SDL_Event *m_event;

    public:
        Mouse();
        Mouse(SDL_Event *event);

        const Mouse *MousePositionCallback();


    };


    }
}


#endif // MOUSE_HPP
