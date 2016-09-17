#ifndef OPENGL_HPP_
#define OPENGL_HPP_
#define GLEW_STATIC
#include <GL/glew.h>
#include <stdint.h>

#include "../math/libremath.hpp"

namespace libre{
  namespace OpenGL{

     GLenum GLError();
     bool GLLogCall(const char * function,const char * file, int32_t line);

     ///////////////////////////////
     // Buffer Functions
     ///////////////////////////////
     void genBuffers(int amount, unsigned int* id);
     void bindBuffers(GLenum type, unsigned int id);
     void deleteBuffer(unsigned int* id);
     void deleteBuffer(int amount, unsigned int* id);
     void drawArrays(GLenum mode, int first, int count);
     void drawElements(GLenum mode, int count, GLenum type, void *indices);
     void BatchDrawArray(GLenum mode, GLint *first, int *count, int primcount);
     void VertexAttributePointer(unsigned int index, int size, GLenum type, bool normalized, int stride, const void* offset);
     void VertexAttributeIPointer(unsigned int index, int size, GLenum type,int stride, const void *offset);
     void VertexAttributeLPointer(unsigned int index, int size, GLenum type, int stride, const void *offset);
     void createBufferData(GLenum target, GLsizeiptr size, const void* data, GLenum usage);
     void genVertexArrays(int size, unsigned int *arrays);
     void deleteVertexArrays(int size, unsigned int *arrays);
     void enableVertexArrays(unsigned int index);
     void BindVertexArray(unsigned int id);

     ////////////////////////////
     //Shader Functions
     ///////////////////////////
     unsigned int createShaderProgram();
     unsigned int createShader(GLenum type);
     void compileShader(unsigned int shader);
     void setShaderSource(unsigned int shader, int count, char* source, int *length);
     void getShaderParameter(unsigned int shader, GLenum pname, int *params);
     void getShaderInfoLog(unsigned int shader, int maxLength, int *length, char *infolog);
     void deleteShader(unsigned int shader);
     void attachShader(unsigned int program, unsigned int shader);
     void linkProgram(unsigned int program);
     void ValidateProgram(unsigned int program);
     void useProgram(unsigned int program);

     //////////////////////////////
     // Texture Functions
     /////////////////////////////
     void genTextures(int amount, unsigned int* textures);
     void bindTexture(GLenum target, unsigned int texture);
     void setTextureParameteri(GLenum target, GLenum pname,  int param);
     void setTextureParameterf(GLenum target, GLenum pname, float param);
     void setTextureParameterip(GLenum target, GLenum pname, int *param);
     void setTextureParameterfp(GLenum target, GLenum pname, float* param);
     void defineTextureImage(GLenum target, int level, int internalformat, math::Vector2<int> size, int border, GLenum format, GLenum type, void *data);
     void deleteTexture(int amount, unsigned int textures);



  }
}


#endif // OpenGl.hpp
