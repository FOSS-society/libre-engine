#include "../../include/graphics/Renderer.hpp"
#include "../../include/system/Logger.hpp"
#include <assert.h>
namespace libre{
  namespace graphics{

  
  SDL_GLContext *Renderer::context() const
  {
      return m_context;
  }
  
  void Renderer::setContext(SDL_GLContext *context)
  {
      m_context = context;
  }
  Renderer::Renderer(Window *parent,RendererType type): m_window(parent),m_type(type){
      switch(m_type){
      case RendererType::RT_2D:
          /**
            Debugging Purposes
            */
          system::Logger::LogInstance()->Log("Creating 2D SDL_Renderer");

          this->m_context = SDL_GL_CreateContext(this->m_window->SDLWIN());
        break;

        case RendererType::RT_3D:
          /**
            Debugging Purposes
            */
          system::Logger::LogInstance()->Log("Creating 3D SDL_GL_Context\n");

        this->m_context = SDL_GL_CreateContext(this->m_window->SDLWIN());
        break;
      default:
          std::cout <<" Invalid Renderer type" << std::endl;
          assert(type == RendererType::RT_2D || type == RendererType::RT_3D );


          break;
      }

        if(this->m_context == nullptr){
            throw RendererException(SDL_GetError());
        }

    }

    void Renderer::Update()
    {

            SDL_GL_SwapWindow(this->m_window->SDLWIN());


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

      SDL_GLContext *Renderer::getContext()
      {
          return m_context;
      }




      }





  }
}
