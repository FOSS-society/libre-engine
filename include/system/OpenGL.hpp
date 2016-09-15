#ifndef OPENGL_HPP_
#define OPENGL_HPP_
#include <GL/glew.h>
#include <stdint.h>

namespace libre{
  namespace OpenGL{

     GLenum GLError();
     bool GLLogCall(const char * function,const char * file, int32_t line);



  }
}


#endif // OpenGl.hpp
