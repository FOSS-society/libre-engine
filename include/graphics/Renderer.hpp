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

      union RenderingContext{
        SDL_Renderer *asSDL;
        SDL_GLContext *asOGL;

        RenderingContext(){}
        RenderingContext(SDL_Renderer *sdl){
            asSDL = sdl;
        }

        RenderingContext(SDL_GLContext *opengl){
            asOGL = opengl;
        }

        ~RenderingContext(){
            SDL_DestroyRenderer(this->asSDL);
            SDL_GL_DeleteContext(this->asOGL);
        }
      };

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
    RenderingContext *m_context;

  public:
    Renderer(Window *parent,RendererType type);
    ~Renderer(){
      switch(m_type){
        case RendererType::RT_2D:
          SDL_DestroyRenderer(this->m_context->asSDL);
          break;
      case RendererType::RT_3D:
          SDL_GL_DeleteContext(this->m_context->asOGL);
          break;
      }

      delete m_window;
    }

    void Update();

    Window *getWindowHandle();
    Window *WindowHandle()const;
    RenderingContext *getContext();
    RenderingContext *Context()const;
    RendererType getType();
    RendererType Type()const;


    };

    void createRenderingContext(RendererType type, Renderer *renderer);
  }
}
#endif //Base Renderer
