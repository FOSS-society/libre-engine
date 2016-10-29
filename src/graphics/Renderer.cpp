#include "../../include/graphics/Renderer.hpp"

namespace libre{
  namespace graphics{

    Renderer::Renderer(Window *parent,RendererType type): m_window(parent),m_type(type){
      switch(type){
        case RendererType::RT_2D:
        this->m_context->asSDL = SDL_CreateRenderer(this->m_window->SDLWIN(),-1,SDL_RENDERER_ACCELERATED);
        break;
        case RendererType::RT_3D:
        this->m_context->asOGL = (SDL_GLContext*)SDL_GL_CreateContext(this->m_window->SDLWIN());
        break;
      }
}

      Window *Renderer::getWindowHandle(){
          return this->m_window;
      }

      Window *Renderer::WindowHandle() const
      {
          return this->m_window;
      }

      RenderingContext *Renderer::getContext(){
          return this->m_context;
      }

      RenderingContext *Renderer::Context() const
      {
          return this->m_context;
      }

      RendererType Renderer::getType(){
        return this->m_type;
      }
      RendererType Renderer::Type()const{
          return this->m_type;
      }

      void createRenderingContext(RendererType type, Renderer *renderer)
      {
          switch(type){
            case RendererType::RT_2D:
            renderer->getContext()->asSDL = SDL_CreateRenderer(renderer->getWindowHandle()->SDLWIN(),-1,SDL_RENDERER_ACCELERATED);
            break;
            case RendererType::RT_3D:
            renderer->getContext()->asOGL = (SDL_GLContext*)SDL_GL_CreateContext(renderer->getWindowHandle()->SDLWIN());
            break;
          }


      }





  }
}
