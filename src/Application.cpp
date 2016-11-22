#include "../include/Application.hpp"
#include "../include/system/Logger.hpp"
#include "../include/graphics/graphics_common.hpp"
#include "../include/system/OpenGL.hpp"
#include "../include/system/Utility.hpp"
#include "system/ComputerDetails.hpp"


#include <SDL2/SDL_events.h>

namespace libre{

Application * Application::m_instance = nullptr;

Application::Application(const char *t, int width, int height,graphics::RendererType rt){
    system::Logger::LogInstance()->Log("Initializing Application /n");
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



          try{
                GLenum glew = graphics::initializeGlew();
                if(glew != GLEW_OK){
                    throw ApplicationException(std::string((char *)glewGetErrorString(glew)));
                }
            }catch(ApplicationException &apex){
                system::Logger::LogInstance()->Log("Glew Initialization Exception Caught:");
                system::Logger::LogInstance()->Log(apex.what());
                std::cout << "Glew Initialization Exception caught: " << apex.what() << std::endl ;
          }

        }
    }catch(ApplicationException &appex){
        system::Logger::LogInstance()->Log("Application Exception Caught:");
        system::Logger::LogInstance()->Log(appex.what());
        std::cout << "Application Exception caught: " << appex.what() << std::endl ;
    }catch(graphics::WindowException &winex){
        system::Logger::LogInstance()->Log("Window Exception Caught:");
        system::Logger::LogInstance()->Log(winex.what());
        std::cout << "Window Exception caught: " << winex.what() << std::endl ;
    }catch(graphics::RendererException &rendex){
        system::Logger::LogInstance()->Log("Renderer Exception Caught:");
        system::Logger::LogInstance()->Log(rendex.what());
        std::cout << "Window Exception caught: " << rendex.what() << std::endl ;
    }


    m_active = true;

}

Application::~Application(){
    delete m_Renderer;
    delete m_Window;
    SDL_Quit();
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

             }

        OpenGL::ClearColor(1,0,0,1);
        OpenGL::ClearFlags(GL_COLOR_BUFFER_BIT);
        this->m_Renderer->Update();

           }
       }
    return this->m_active;
}

void Application::Stop()
{
    this->m_active = false;
}

Application *Application::Instance()
{
    if(Application::m_instance == nullptr){
        Application::m_instance = new Application("Libre-Engine Default",640,480,graphics::RendererType::RT_3D);
    }
    return Application::m_instance;

}


}



