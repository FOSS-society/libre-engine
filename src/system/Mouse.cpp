#include "../../include/system/Mouse.hpp"

namespace libre{
namespace system{

Mouse::Mouse()
{
    m_ButtonPress = ButtonPress::NONE;
    mousePosition = math::Vector2<int32_t>(0,0);
}


void Mouse::setMousePosition(int x, int y)
{
    this->mousePosition = math::Vector2<int32_t>(x,y);
}

void Mouse::setButtonPress(ButtonPress press)
{
    this->m_ButtonPress = press;
}








    }
}
