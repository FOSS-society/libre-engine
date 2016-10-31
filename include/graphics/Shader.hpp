#ifndef SHADER_HPP_
#define SHADER_HPP_

#include <string>
#include <vector>
#include "graphics_common.hpp"
#include "../graphics/ShaderVariable.hpp"


namespace libre{

  namespace graphics{

    enum class ShaderType{ VERTEX , TESSALATION1,TESSALATION2,GEOMETRY, FRAGMENT};


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
      std::string m_sourceFile;
      std::vector<ShaderVariable> *m_attributes;
      std::vector<ShaderVariable> *m_uniforms;

    public:
      Shader(std::string name, std::string source, ShaderType type);

      void setUniform(std::string name, core::Variant data);
      void setAttribute(std::string name, core::Variant data);

      void addUniform(std::string name, core::Variant data);
      void addAttribute(std::string name, core::Variant data);

      core::Variant getUniform(std::string variableName);
      core::Variant getAttribute(std::string variableName);




    };

  }

}

#endif //Shader.hpp
