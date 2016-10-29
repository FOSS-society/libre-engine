#include "../../include/graphics/Window.hpp"

namespace libre{
  namespace graphics{

    Window::Window(const char * t,const unsigned int width,const unsigned int height)
     : m_title(t),m_size(math::Vector2<unsigned int>(width,height)){


        this->m_window = (SDL_Window*)SDL_CreateWindow(t,SDL_WINDOWPOS_UNDEFINED,
                                      SDL_WINDOWPOS_UNDEFINED, width,height,SDL_WINDOW_SHOWN);
     }
    Window::Window(const char * t,math::Vector2<unsigned int> size) : m_title(t), m_size(size){
      this->m_window = (SDL_Window*)SDL_CreateWindow(t,SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED, size.X(),size.Y(),SDL_WINDOW_SHOWN);
    }

    const char * Window::Title(){
      return this->m_title;
    }
    SDL_Window * Window::SDLWIN(){
      return this->m_window;
    }
    math::Vector2<unsigned int> Window::Size(){
      return this->m_size;
    }





  }
}
