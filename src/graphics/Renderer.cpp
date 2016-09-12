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
  }
}
