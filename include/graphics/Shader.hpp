#ifndef SHADER_HPP_
#define SHADER_HPP_

#include <string>
#include <vector>
#include "graphics_common.hpp"
#include "../graphics/ShaderVariable.hpp"


namespace libre{

  namespace graphics{

    enum class ShaderType{ VERTEX , TESSALATION1,TESSALATION2,GEOMETRY, FRAGMENT};

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
