#include "../../include/system/Mouse.hpp"

namespace libre{
namespace system{

Mouse::Mouse()
{
    m_ButtonPress = ButtonPress::NONE;
    mousePosition = math::Vector2<int32_t>(0,0);
    m_event = new SDL_Event;
}

Mouse::Mouse(SDL_Event *event)
{
    m_ButtonPress = ButtonPress::NONE;
    mousePosition = math::Vector2<int32_t>(0,0);
    m_event = event;
}

const Mouse *Mouse::MousePositionCallback()
{
    if(SDL_PollEvent(this->m_event)){
    switch(this->m_event->type){
    case SDL_MOUSEMOTION:
        this->mousePosition.setX(m_event->motion.x);
        this->mousePosition.setY(m_event->motion.y);
        break;
    case SDL_MOUSEBUTTONDOWN:
        switch(m_event->button.button){
        case SDL_BUTTON_LEFT:
            this->m_ButtonPress = ButtonPress::LEFT;
                break;
        case SDL_BUTTON_RIGHT:
            this->m_ButtonPress = ButtonPress::RIGHT;
                break;
        case SDL_BUTTON_MIDDLE:
            this->m_ButtonPress = ButtonPress::MIDDLE;
                break;
        case SDL_BUTTON_X1:
            this->m_ButtonPress = ButtonPress::X1;
                break;
        case SDL_BUTTON_X2:
            this->m_ButtonPress = ButtonPress::X2;
            break;
        default:
            this->m_ButtonPress = ButtonPress::NONE;
            break;
       }
        default:
            break;


    }
 }

        return this;

}




    }
}
