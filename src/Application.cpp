#include "../include/Application.hpp"
#include "../include/system/Logger.hpp"
#include "../include/graphics/graphics_common.hpp"
#include "../include/system/OpenGL.hpp"
#include "../include/system/Utility.hpp"
#include "system/ComputerDetails.hpp"


#include <SDL2/SDL_events.h>

namespace libre{

Application * Application::Instance = nullptr;

Application::Application(const char *t, int width, int height,graphics::RendererType rt){
    system::LogToConsoleAndFile("Initializing Application/n");
    try{
        if(graphics::s_initializeSDLWithEverything() != 0){
            throw ApplicationException(SDL_GetError());
        }else{

            if(rt == graphics::RendererType::RT_3D){
                this->m_Window = new graphics::Window(t,width,height, true);
                system::LogToConsoleAndFile("Initializing SDL_GL_Context/n");

            }else{
                this->m_Window = new graphics::Window(t,width,height,false);
                 system::LogToConsoleAndFile("Initializing SDL_Renderer/n");

            }

            this->m_Renderer  = new graphics::Renderer(this->m_Window,rt);
            this->m_Mouse = new system::Mouse();
            this->m_Keyboard = new system::Keyboard();
            this->m_HostInfo = new system::ComputerDetails();
            this->m_state = new DefaultState();
            this->m_state->setApp(this);



          try{
                GLenum glew = graphics::initializeGlew();
                if(glew != GLEW_OK){
                    throw ApplicationException(std::string((char *)glewGetErrorString(glew)));
                }
            }catch(ApplicationException &apex){
                system::LogToConsoleAndFile("Glew Initialization Exception Caught:");
                system::LogToConsoleAndFile(apex.what());
                std::cout << "Glew Initialization Exception caught: " << apex.what() << std::endl ;
          }

        }
    }catch(ApplicationException &appex){
        system::LogToConsoleAndFile("Application Exception Caught:");
        system::LogToConsoleAndFile(appex.what());
        std::cout << "Application Exception caught: " << appex.what() << std::endl ;
    }catch(graphics::WindowException &winex){
        system::LogToConsoleAndFile("Window Exception Caught:");
        system::LogToConsoleAndFile(winex.what());
        std::cout << "Window Exception caught: " << winex.what() << std::endl ;
    }catch(graphics::RendererException &rendex){
        system::LogToConsoleAndFile("Renderer Exception Caught:");
        system::LogToConsoleAndFile(rendex.what());
        std::cout << "Window Exception caught: " << rendex.what() << std::endl ;
    }


    m_active = true;

}

Application::Application(const char *t, int width, int height, graphics::RendererType rt, BaseState *state)
{
    system::LogToConsoleAndFile("Initializing Application /n");
    try{
        if(graphics::s_initializeSDLWithEverything() != 0){
            throw ApplicationException(SDL_GetError());
        }else{

            if(rt == graphics::RendererType::RT_3D){
                this->m_Window = new graphics::Window(t,width,height, true);
            }else{
                this->m_Window = new graphics::Window(t,width,height,false);

            }

            this->m_Renderer  = new graphics::Renderer(this->m_Window,rt);
            this->m_Mouse = new system::Mouse();
            this->m_Keyboard = new system::Keyboard();
            this->m_HostInfo = new system::ComputerDetails();
            this->m_state = state;
            this->m_state->setApp(this);



          try{
                GLenum glew = graphics::initializeGlew();
                if(glew != GLEW_OK){
                    throw ApplicationException(std::string((char *)glewGetErrorString(glew)));
                }
            }catch(ApplicationException &apex){
                system::LogToConsoleAndFile("Glew Initialization Exception Caught:");
                system::LogToConsoleAndFile(apex.what());
                std::cout << "Glew Initialization Exception caught: " << apex.what() << std::endl ;
          }

        }
    }catch(ApplicationException &appex){
        system::LogToConsoleAndFile("Application Exception Caught:");
        system::LogToConsoleAndFile(appex.what());
    }catch(graphics::WindowException &winex){
        system::LogToConsoleAndFile("Window Exception Caught:");
        system::LogToConsoleAndFile(winex.what());
    }catch(graphics::RendererException &rendex){
        system::LogToConsoleAndFile("Renderer Exception Caught:");
        system::LogToConsoleAndFile(rendex.what());
    }


    m_active = true;

}

void Application::Initialize()
{
    this->m_state->initialize();
}

Application::~Application(){
    m_state->destroy();
    delete m_state;
    delete m_Renderer;
    delete m_Window;
    SDL_Quit();
}
BaseState *Application::state() const
{
    return m_state;
}

BaseState *Application::getState()
{
    return m_state;
}

void Application::setState(BaseState *state)
{
    m_state = state;
}

graphics::Window *Application::Window() const
{
    return m_Window;
}

libre::graphics::Window *libre::Application::getWindow()
{
    return m_Window;
}

void Application::setWindow(graphics::Window *Window)
{
    m_Window = Window;
}

system::ComputerDetails *Application::HostInfo() const
{
    return m_HostInfo;
}

system::ComputerDetails *Application::getHostInfo()
{
    return m_HostInfo;
}

void Application::setHostInfo(system::ComputerDetails *HostInfo)
{
    m_HostInfo = HostInfo;
}

system::Keyboard *Application::Keyboard() const
{
    return m_Keyboard;
}

system::Keyboard *Application::getKeyboard()
{
    return m_Keyboard;
}

void Application::setKeyboard(system::Keyboard *Keyboard)
{
    m_Keyboard = Keyboard;
}

system::Mouse *Application::Mouse() const
{
    return m_Mouse;
}

system::Mouse *Application::getMouse()
{
    return m_Mouse;
}

void Application::setMouse(system::Mouse *Mouse)
{
    m_Mouse = Mouse;
}

graphics::Renderer *Application::Renderer() const
{
    return m_Renderer;
}

graphics::Renderer *Application::getRenderer()
{
    return m_Renderer;
}

void Application::setRenderer(graphics::Renderer *Renderer)
{
    m_Renderer = Renderer;
}


bool Application::Run()
{
    if(this->m_active){
        SDL_Event ev;
        while(SDL_PollEvent(&ev)){
            switch(ev.type){
            
            case SDL_QUIT:
                this->Stop();
               break;
            case SDL_MOUSEMOTION:
              this->m_Mouse->setMousePosition(ev.motion.x,ev.motion.y);
              break;
           case SDL_MOUSEBUTTONDOWN:
               switch(ev.button.button){
               case SDL_BUTTON_LEFT:
                   this->m_Mouse->setButtonPress(system::ButtonPress::LEFT);
                       break;
               case SDL_BUTTON_RIGHT:
                   this->m_Mouse->setButtonPress(system::ButtonPress::RIGHT);
                       break;
               case SDL_BUTTON_MIDDLE:
                   this->m_Mouse->setButtonPress(system::ButtonPress::MIDDLE);
                       break;
               case SDL_BUTTON_X1:
                   this->m_Mouse->setButtonPress(system::ButtonPress::X1);
                       break;
               case SDL_BUTTON_X2:
                   this->m_Mouse->setButtonPress(system::ButtonPress::X2);
                   break;
               default:
                   this->m_Mouse->setButtonPress(system::ButtonPress::NONE);
                   break;
              }
           case SDL_KEYDOWN:

               if(this->m_Keyboard->keyDown(ev.key.keysym.sym)){
                   m_Keyboard->setKeyHeldDown(ev.key.keysym.sym);
               }else
                   m_Keyboard->setKeyDown(ev.key.keysym.sym);

                   break;

            case SDL_KEYUP:

               if(this->m_Keyboard->keyDown(ev.key.keysym.sym)){
                   m_Keyboard->setKeyHeldUp(ev.key.keysym.sym);
               }else
                   m_Keyboard->setKeyUp(ev.key.keysym.sym);

               break;

            case SDL_WINDOWEVENT_RESIZED:
                SDL_SetWindowSize(m_Window->SDLWIN(),ev.window.data1,ev.window.data2);
                m_Window->setSize((unsigned int)ev.window.data1,(unsigned int)ev.window.data2);
                break;
            default:
                break;

             }



           }
        OpenGL::ClearColor(1,0,0,1);
        OpenGL::ClearFlags(GL_COLOR_BUFFER_BIT);
        this->m_state->Update();
        this->m_Renderer->Update();
       }
    return this->m_active;
}

void Application::Stop()
{
    this->m_active = false;
}



}



