#include <libre-engine/graphics/Window.hpp>
#include <libre-engine/graphics/Renderer.hpp>
#include <libre-engine/core/Engine.hpp>


using namespace libre;

int main(int argc, char *argv[]){

    libre::graphics::s_sdlIsInitialized = false;
    libre::graphics::s_glewIsInitialized = false;

    libre::graphics::initializeSDLWithEverything();
    libre::graphics::initializeGlew();

    graphics::Window *window = new graphics::Window("Libre-Engine Sandbox",640,480);
    std::cout << " Window created" <<std::endl;
    graphics::Renderer *renderer = new graphics::Renderer(window,graphics::RendererType::RT_2D);
    std::cout << "Renderer created for SDL(2D)" << std::endl;

    core::Engine *engine = new core::Engine(renderer);

    while(engine->isRunning()){
        engine->update();
    }

    delete window;
    delete renderer;
    delete engine;

    return 0;


}
