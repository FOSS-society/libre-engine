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
        std::cerr << "GLEW Error: " <<  glewGetErrorString(error) << std::endl;
        std::cerr << "File: " << __FILE__ << std::endl << "Line: "  << __LINE__ << std::endl;
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
          std::cout << "Image Initialization return code: "<< IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG|IMG_INIT_TIF);
          s_sdlIsInitialized = true;
          }
    }


  void initializeSDLWithEverything(){
    if(s_sdlIsInitialized){
      std::cerr<< "Warning, SDL is already initialized" << std::endl;
      std::cerr<< "SEEN FROM: graphics_common.c line 24: initializeSDLWithEverything" << std::endl;
      }else{
        SDL_Init(SDL_INIT_EVERYTHING);
        //std::cerr << "Image Initialization return code: " << IMG_Init(IMG_INIT_JPG\| IMG_INIT_PNG |IMG_INIT_TIF);
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

Color4 UIntToColor(uint32_t color)
{
    Color4 temp;
    uint8_t varray[4];
    memcpy(varray,&color,sizeof(varray));
    temp.setX(varray[0]);
    temp.setY(varray[1]);
    temp.setZ(varray[2]);
    temp.setW(varray[3]);

    return temp;

}



  }
}
