#include <libre-engine/Application.hpp>

using namespace libre;

int main(int argc, char *argv[]){


    /**


    libre::graphics::s_sdlIsInitialized = false;
    libre::graphics::s_glewIsInitialized = false;    
    libre::graphics::initializeSDLWithEverything();

    graphics::Window *window = new graphics::Window("Libre-Engine Sandbox",640,480);
    std::cout << " Window created" <<std::endl;
    graphics::Renderer *renderer = new graphics::Renderer(window,graphics::RendererType::RT_2D);
    std::cout << "Renderer created for " << renderer->WindowHandle()->Title() << std::endl;




    glewExperimental = GL_TRUE;
    libre::graphics::initializeGlew();


    system::ComputerDetails details;



    std::cout << "OpenGL Info: " << details.getOpenGLInfo().version.toString()<< std::endl;
    std::cout << "OpenGL Version VIA glfunc:" << (const char *)glGetString(GL_VERSION)<< std::endl;
    std::cout << "Vendor: " <<details.getOpenGLInfo().vendor<< std::endl;
    std::cout << "Renderer: " << details.getOpenGLInfo().renderer<< std::endl;
    std::cout << "SDL Version : " << details.getSDLVersion().toString()<< std::endl;

    std::cout << "########################################" << std::endl;

    std::cout << "OpenGL Version from OpenGLVersionCompat(): "
              << libre::Utility::getOpenGLVersionCompat().toString();




    core::Engine *engine = new core::Engine(renderer);

    while(engine->isRunning()){
        engine->update();
    }

    delete window;
    delete renderer;
    delete engine;





    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch(event.key.keysym.sym){
            case SDLK_ESCAPE:
            SDL_Quit();
            return -1;
            break;
        default:
            SDL_GL_SwapWindow(window->SDLWIN());
        }
    }
    */

    while(Application::Instance()->Run());

    return 0;


}
