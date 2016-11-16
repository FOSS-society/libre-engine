#include "../../include/graphics/Renderer.hpp"
#include <assert.h>
namespace libre{
  namespace graphics{

    Renderer::Renderer(Window *parent,RendererType type): m_window(parent),m_type(type){
      switch(m_type){
        case RendererType::RT_2D:
        this->m_context = new RenderingContext(SDL_CreateRenderer(this->m_window->SDLWIN(),-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
        break;
        case RendererType::RT_3D:
        this->m_context = new RenderingContext((SDL_GLContext*)SDL_GL_CreateContext(this->m_window->SDLWIN()));
        break;
      default:
          std::cout <<" Invalid Renderer type" << std::endl;
          assert(type == RendererType::RT_2D || type == RendererType::RT_3D );


          break;
      }

        if(this->getContext()->asOGL == nullptr && this->getContext()->asSDL == nullptr){
            throw RendererException(SDL_GetError());
        }

    }

    void Renderer::Update()
    {
        switch(this->m_type){
        case RendererType::RT_2D:
            SDL_RenderPresent(this->m_context->asSDL);
            break;
        case RendererType::RT_3D:
            SDL_GL_SwapWindow(this->m_window->SDLWIN());
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
