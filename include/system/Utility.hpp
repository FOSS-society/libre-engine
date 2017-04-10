#ifndef UTILITY_HPP_
#define UTILITY_HPP_


#include<cstring>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "../math/vector2.hpp"
#include "../math/vector3.hpp"
#include "../math/vector4.hpp"

//Bullshit typedef
typedef int GLint;

namespace libre{

  namespace Utility{

    inline void logSDLError(std::string message);

    inline uint32_t ColorToUint32(math::Vector4<uint8_t> *color);

    inline math::Vector4<uint8_t> uint32ToColor(uint32_t color);

    std::string readFile(const char * filePath);

    math::Vector2<GLint> getOpenGLVersion();

    math::Vector2<uint8_t> getOpenGLVersionCompat();

    math::Vector3<uint8_t> getSDLVersion();


   std::vector<std::string> tokenize(const std::string &contents, const char * delimiter);

   int RandomNumber();




  }
}


#endif //Utility.hpp
