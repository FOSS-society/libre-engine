#ifndef GRAPHICS_COMMON_HPP_
#define GRAPHICS_COMMON_HPP_


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>

#include <GL/glew.h>

#include <stdint.h>

#include "../math/vector2.hpp"
#include "../math/vector3.hpp"
#include "../math/vector4.hpp"


namespace libre{
  namespace graphics{

    extern bool s_sdlIsInitialized;
    extern bool s_glewIsInitialized;

    GLenum initializeGlew();


    void initializeSDL(uint32_t flags);
    void initializeSDLWithEverything();


    typedef math::Vector4<uint8_t> Color4;

    uint32_t colorToUInt(Color4 *color);

    void logSDLError(const char * message);


  }

}

#endif
