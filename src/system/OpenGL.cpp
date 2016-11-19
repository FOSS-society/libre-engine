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

	void genBuffers(int amount, unsigned* id)
		{
			glGenBuffers(amount, id);
		}

		void bindBuffers(GLenum type,unsigned id)
		{
			glBindBuffer(type, static_cast<GLuint>(id));
		}
		void deleteBuffer(unsigned* id)
		{
			glDeleteBuffers(1,id);
		}

		void deleteBuffer(int amount, unsigned* id)
		{
			glDeleteBuffers(amount, id);
		}

		void drawArrays(GLenum mode, int first, int count)
		{
			glDrawArrays(mode, first, count);
		}

		void drawElements(GLenum mode, int count, GLenum type, void* indices)
		{
			glDrawElements(mode, count, type, indices);
		}

		void BatchDrawArray(GLenum mode, GLint* first, int* count, int primcount)
		{
			glMultiDrawArrays(mode, first, count, primcount);
		}

		void VertexAttributePointer(unsigned index, int size, GLenum type, bool normalized, int stride, const void* offset)
		{
			glVertexAttribPointer(index, size, type, normalized, stride, offset);
		}

		void VertexAttributeIPointer(unsigned index, int size, GLenum type, int stride, const void* offset)
		{
			glVertexAttribIPointer(index, size, type, stride, offset);
		}
		void VertexAttributeLPointer(unsigned index, int size, GLenum type, int stride, const void* offset)
		{
			glVertexAttribLPointer(index, size, type, stride, offset);
		}

		void genVertexArrays(int size, unsigned* arrays)
		{
			glGenVertexArrays(size, arrays);
		}

		void deleteVertexArrays(int size, unsigned* arrays)
		{
			glDeleteVertexArrays(size, arrays);
		}

		void enableVertexArrays(unsigned index)
		{
			glEnableVertexAttribArray(index);
		}

		unsigned createShaderProgram()
		{
			return glCreateProgram();
		}

		unsigned createShader(GLenum type)
		{
			return glCreateShader(type);
		}

		void compileShader(unsigned shader)
		{
			glCompileShader(shader);
		}

		void setShaderSource(unsigned shader, int count, char* source, int* length)
		{
			glShaderSource(shader, count, (const GLchar**)&source, length);
		}

		void getShaderParameter(unsigned shader, GLenum pname, int* params)
		{
			glGetShaderiv(shader, pname, params);
		}

		void getShaderInfoLog(unsigned shader, int maxLength, int* length, char* infolog)
		{
			glGetShaderInfoLog(shader, maxLength, length, infolog);
		}



		void deleteShader(unsigned shader)
		{
			glDeleteShader(shader);
		}

		void attachShader(unsigned program, unsigned shader)
		{
			glAttachShader(program, shader);
		}

		void linkProgram(unsigned program)
		{
			glLinkProgram(program);
		}

		void ValidateProgram(unsigned program)
		{
			glValidateProgram(program);
		}

		void genTextures(int amount, unsigned* textures)
		{
			glGenTextures(amount, textures);
		}

		void bindTexture(GLenum target, unsigned texture)
		{
			glBindTexture(target, texture);
		}

		void setTextureParameteri(GLenum target, GLenum pname, int param)
		{
			glTexParameteri(target, pname, param);
		}


		void setTextureParameterf(GLenum target, GLenum pname, float param)
		{
			glTexParameterf(target, pname, param);
		}

		void setTextureParameterip(GLenum target, GLenum pname, int* param)
		{
		glTexParameteriv(target, pname, param);
		}

		void setTextureParameterfp(GLenum target, GLenum pname, float* param)
		{
		glTexParameterfv(target, pname, param);
		}

		void defineTextureImage(GLenum target, int level, int internalformat, math::Vector2<int> size, int border, GLenum format, GLenum type, void* data)
		{
			glTexImage2D(target, level, internalformat, size.X(), size.Y(), border, format, type, data);
		}

		void deleteTexture(int amount, unsigned textures)
		{
			glDeleteTextures(amount, &textures);
		}

		void useProgram(unsigned program)
		{
			glUseProgram(program);
		}

		void BindVertexArray(unsigned id)
		{
			glBindVertexArray(id);
		}

		void createBufferData(GLenum target, GLsizeiptr size, const void* data, GLenum usage)
		{
            glBufferData(target, size, data, usage);
        }

        void *MapBuffer(GLenum target, GLenum access)
        {
            glMapBuffer(target,access);
        }

        GLboolean UnmapBuffer(GLenum target)
        {
            glUnmapBuffer(target);
        }

        void getIntegerVariable(GLenum name, GLint *data)
        {
            glGetIntegerv(name,data);
        }

        void getBooleanVariable(GLenum name, GLboolean *data)
        {
            glGetBooleanv(name,data);
        }

        void getDoubleVariable(GLenum name, GLdouble *data)
        {
            glGetDoublev(name,data);
        }

        void getFloatVariable(GLenum name, GLfloat *data)
        {
            glGetFloatv(name,data);
        }
        void getInteger64Variable(GLenum name, GLint64 *data)
        {
            glGetInteger64v(name,data);
        }
        void getIndexedBooleanVariable(GLenum name, GLuint index, GLboolean *data){
            glGetBooleani_v(name,index,data);
        }

        void getIndexedIntegerVariable(GLenum name, GLuint index, GLint *data){
            glGetIntegeri_v(name,index,data);
        }

        void getIndexedDoubleVariable(GLenum name, GLuint index, GLdouble *data){
            glGetDoublei_v(name,index,data);
        }

        void getIndexedFloatVariable(GLenum name, GLuint index, GLfloat *data){
            glGetFloati_v(name,index,data);
        }

        void getIndexedInteger64Variable(GLenum name, GLuint index, GLint64 *data){
            glGetInteger64i_v(name,index,data);
        }

        void getString(GLenum name, const GLubyte *out)
        {
            out = glGetString(name);
        }

        void ClearColor(GLclampf r, GLclampf g, GLclampf b, GLclampf a)
        {
            glClearColor(r,g,b,a);
        }

        void ClearColor(const math::Vector4<GLclampf> color)
        {
            glClearColor(color.X(),color.Y(),color.Z(),color.W());
        }

        void ClearFlags(GLbitfield mask)
        {
            glClear(mask);
        }

        void getProgramParameter(unsigned int program, GLenum pname, int *params)
        {
            glGetProgramiv(program,pname,params);
        }

        void GetActiveUniform(unsigned int program, unsigned int index, int bufferSize, int *length, int *size, GLenum *type, char *name)
        {
            glGetActiveUniform(program,index,bufferSize,length,size,type,name);
        }






  }
}
