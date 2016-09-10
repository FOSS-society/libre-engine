#include "../../include/graphics/graphics_common.hpp"

#include <iostream>

namespace libre{

  namespace graphics{


    bool s_sdlIsInitialized = false;
    bool s_glewIsInitialized = false;

    GLenum initializeGlew(){
      if(s_glewIsInitialized){
        return GLEW_OK;
      }
      GLenum error = glewInit();
      if(error != GLEW_OK){
        std::cerr << "Error: " <<  glewGetErrorString(error);
      }else{
        std::cout << "Status: Using GLEW " << glewGetString(GLEW_VERSION);
        s_glewIsInitialized = true;
      }
        return error;
  }
    void initializeSDL(uint32_t flags){
        if(s_sdlIsInitialized){
          std::cerr << "Warning, SDL is already Initialized." <<std::endl;
          std::cerr <<"Seen from: graphics_common";
        }
        else{

          SDL_Init(flags);
          s_sdlIsInitialized = true;
          }
    }


  void initializeSDLWithEverything(){
    if(s_sdlIsInitialized){
      std::cerr<< "Warning, SDL is already initialized" << std::endl;
      std::cerr<< "SEEN FROM: graphics_common.c line 24: initializeSDLWithEverything" << std::endl;
      }else{
        SDL_Init(SDL_INIT_EVERYTHING);
        s_sdlIsInitialized = true;
      }
    }

  uint32_t colorToUInt(Color4 *color){
    uint32_t color32;
    color32 = color->getX() | (color->getY() << 8) | (color->getZ() <<16) | (color->getW() << 24);
    return color32;
  }

void logSDLError(const char * message){

  std::cerr << message << " error: " << SDL_GetError() << std::endl;
}



  }
}
