#ifndef GRAPHICS_COMMON_HPP_
#define GRAPHICS_COMMON_HPP_

//SDL Includes
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>

//GLEW Include
#include <GL/glew.h>

//Standard types
#include <stdint.h>

//Vector Library
#include "../math/vector2.hpp"
#include "../math/vector3.hpp"
#include "../math/vector4.hpp"


namespace libre{
  namespace graphics{


  
  //Static Booleans to Initialize systems needing initialization before the engine
    extern bool s_sdlIsInitialized;
    extern bool s_glewIsInitialized;

    
    GLenum initializeGlew();



    void initializeSDL(uint32_t flags);
    void initializeSDLWithEverything();

    int s_initializeSDL(uint32_t flags);
    int s_initializeSDLWithEverything();

    typedef math::Vector4<uint8_t> Color4;

    uint32_t colorToUInt(Color4 *color);
    Color4 UIntToColor(uint32_t color);

    void logSDLError(const char * message);


  }

}

#endif
