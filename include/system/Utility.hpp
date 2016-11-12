#ifndef UTILITY_HPP_
#define UTILITY_HPP_


#include<cstring>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "../graphics/graphics_common.hpp"
#include "OpenGL.hpp"
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

    std::string readFile(const char * filePath){
        std::ifstream ifFP;
        ifFP.open(filePath);

        std::stringstream strStream;
        strStream << ifFP.rdbuf();
        ifFP.close();

        return strStream.str();
    }

    math::Vector2<GLint> getOpenGLVersion(){

        GLint version[2];

        OpenGL::getIntegerVariable(GL_MAJOR_VERSION,&version[0]);
        OpenGL::getIntegerVariable(GL_MINOR_VERSION,&version[1]);

        return math::Vector2<GLint>(version[0],version[1]);

    }

    math::Vector2<uint8_t> getOpenGLVersionCompat(){

        GLint version[2];

        OpenGL::getIntegerVariable(GL_MAJOR_VERSION,&version[0]);
        OpenGL::getIntegerVariable(GL_MINOR_VERSION,&version[1]);

        return math::Vector2<uint8_t>((uint8_t)version[0],(uint8_t)version[1]);

    }

    math::Vector3<uint8_t> getSDLVersion(){
        SDL_version resultv;
        SDL_GetVersion(&resultv);
        math::Vector3<uint8_t> result(resultv.major,resultv.minor,resultv.patch);
       return result;
    }


   std::vector<std::string> tokenize(const std::string &contents, const char * delimiter){

       std::vector<std::string> result = std::vector<std::string>();
      char *input = (char *)contents.c_str();
       char *token = std::strtok(input, delimiter);
       while (token != NULL){
           result.push_back(std::string(token));
           token = std::strtok(NULL,delimiter);
       }

        return result;
    }

   int RandomNumber(){
       srand(time(0));
       return rand();
   }




  }
}


#endif //Utility.hpp
