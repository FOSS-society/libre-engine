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

      RenderingContext *Renderer::getContext(){
        return this->m_context;
      }

      RendererType Renderer::getType(){
        return this->m_type;
      }
      RendererType Renderer::Type()const{
        return this->m_type;
      }





  }
}
