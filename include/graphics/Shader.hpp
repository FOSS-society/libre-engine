#ifndef SHADER_HPP_
#define SHADER_HPP_

#include <string>
#include <vector>
#include "graphics_common.hpp"
#include "../graphics/ShaderVariable.hpp"


namespace libre{

  namespace graphics{

  //Let Tessalation1 be Tessalation Control and Tessalation2 be Tessalation Evaluation

    enum class ShaderType{ VERTEX , TESSALATION1,TESSALATION2,GEOMETRY, FRAGMENT,COMPUTE};



    /**
     * @brief The Shader class
     * This class will be fed into a ShaderProgram class, in order for it to be rendered
     *
     * String: Name
     * (Enum)ShaderType: Type
     * Vector<ShaderVariable> *attributes;
     * Vector<ShaderVariable> *uniforms;
     *
     * Notes: Needs to be worked on
     *        All possible OpenGL Functions are wrapped in the OpenGL namespace
     *              This is found under system/Opengl.hpp
     */

    class Shader{
    private:

      std::string m_name;
      ShaderType m_type;
      std::string m_filePath;
      std::string m_Source;
      std::vector<ShaderVariable> *m_attributes;
      std::vector<ShaderVariable> *m_uniforms;
      bool m_compiled;
      bool m_linked;
      GLuint m_handle;

    public:
      Shader(std::string name, std::string filepath, ShaderType type);

       ShaderType getType();
       ShaderType Type()const;

       std::string getFilePath();
       std::string FilePath()const;

       std::string getSource();
       std::string Source()const;

       std::string getName();
       std::string Name()const;


       //Compile the shader
       bool compile();



       bool linked() const;
       void setLinked(bool linked);
    };

  }

}

#endif //Shader.hpp
