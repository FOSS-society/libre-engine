#include "../../include/system/OpenGL.hpp"

#include <iostream>
namespace libre{
  namespace OpenGL{

     GLenum GLError(){
       return glGetError();
    }
     bool GLLogCall(const char * function,const char * file, int32_t line){
      GLenum error = GLError();
		if (error != GL_NO_ERROR)
		{

      std::cerr << "OpenGL Error : "<< error << " during function " << function << " in file : " << file << " line: " << line;
      return false;
		}
		return true;
    }



  }
}
