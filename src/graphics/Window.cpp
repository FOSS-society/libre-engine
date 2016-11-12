#include "../../include/graphics/Window.hpp"

namespace libre{
  namespace graphics{

  bool Window::setOpenGLAttributes()
  {

          // Set our OpenGL version.
          // SDL_GL_CONTEXT_CORE gives us only the newer version, deprecated functions are disabled
          SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

          // 3.2 is part of the modern versions of OpenGL, but most video cards whould be able to run it
          SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
          SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

          // Turn on double buffering with a 24bit Z buffer.
          // You may need to change this to 16 or 32 for your system
          SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

          return true;

  }

  bool Window::setOpenGLAttributes(const uint8_t maj, const uint8_t min)
  {

          // Set our OpenGL version.
          // SDL_GL_CONTEXT_CORE gives us only the newer version, deprecated functions are disabled
          SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

          SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, maj);
          SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, min);

          // Turn on double buffering with a 24bit Z buffer.
          // You may need to change this to 16 or 32 for your system
          SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

          return true;

  }


  bool Window::setOpenGLAttributes(const math::Vector2<uint8_t> &version)
  {

          // Set our OpenGL version.
          // SDL_GL_CONTEXT_CORE gives us only the newer version, deprecated functions are disabled
          SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

          SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, version.X());
          SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, version.Y());

          // Turn on double buffering with a 24bit Z buffer.
          // You may need to change this to 16 or 32 for your system
          SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

          return true;

  }



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
