#ifndef SHADER_HPP_
#define SHADER_HPP_

#include <string>
#include <vector>
#include "graphics_common.hpp"
#include "../graphics/ShaderVariable.hpp"


namespace libre{

  namespace graphics{

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



    };

  }

}

#endif //Shader.hpp
