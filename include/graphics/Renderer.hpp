#ifndef RENDERER_HPP_
#define RENDERER_HPP_

#include "graphics_common.hpp"
#include "Window.hpp"

namespace libre{
  namespace graphics{
      enum class RendererType {RT_2D, RT_3D};
      union RenderingContext{
        SDL_Renderer *asSDL;
        SDL_GLContext *asOGL;
      };

      RenderingContext createRenderingContext(RendererType type);

  class Renderer{

  private:
    Window *m_window;
    RenderingContext *m_context;
    RendererType m_type;

  public:
    Renderer(Window *parent,RendererType type);
    ~Renderer(){
      delete m_context;
      delete m_window;
    }

    };
  }
}
#endif //Base Renderer
