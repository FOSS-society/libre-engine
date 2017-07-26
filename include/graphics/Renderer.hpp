#ifndef RENDERER_HPP_
#define RENDERER_HPP_

#include "graphics_common.hpp"
#include "Window.hpp"

namespace libre{
  namespace graphics{



  class RendererException: public std::runtime_error{
  public:
      RendererException(const std::string& error):std::runtime_error(error){}
  };


      enum class RendererType {RT_2D, RT_3D};


   /**
   * @brief The Renderer class
   * 
   * Allows for rendering onto a context.
   * 
   * Window* : windowhandle
   * (Enum) RendererType: Type 
   * (union) RendererContext: Context
   * 
   * Notes: This class is const compatible
   *        Use this class to encapsulate a RenderingComponent
   * 
   * 
   */
  class Renderer{

  private:
    Window *m_window;
    RendererType m_type;
    SDL_GLContext *m_context;

  public:
    Renderer(Window *parent,RendererType type);
    ~Renderer(){

      SDL_GL_DeleteContext(this->m_context);

      delete m_window;
    }

    void Update();

    Window *getWindowHandle();
    Window *WindowHandle()const;

    RendererType getType();
    RendererType Type()const;

    SDL_GLContext *getContext();
    SDL_GLContext *context() const;
    void setContext(SDL_GLContext *context);
  };
  
  }
}
#endif //Base Renderer
