#ifndef UTILITY_HPP_
#define UTILITY_HPP_

#include <iostream>
#include "../graphics/graphics_common.hpp"
#include "../math/vector4.hpp"


namespace libre{

  namespace Utility{

    inline void logSDLError(std::string message){
      std::cout << message << "\nSDL Error: " << SDL_GetError() << std::endl;
    }

    inline uint32_t ColorToUint32(math::Vector4<uint8_t> *color){
      uint32_t ret = color->X() | (color->Y() << 8) | (color->Z() << 16) | (color->W() <<24);
      return ret;
    }

    inline math::Vector4<uint8_t> uint32ToColor(uint32_t color){
      return math::Vector4<uint8_t>((color & 0x000000ff),
                          (color & 0x0000ff00) >> 8,
                          (color & 0x00ff0000) >> 16,
                          (color & 0xff000000) >> 24);
    }

  }
}


#endif //Utility.hpp
