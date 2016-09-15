#ifndef SHADER_HPP_
#define SHADER_HPP_

#include <string>
#include <vector>
#include "graphics_common.hpp"
#include "../core/LEVariant.hpp"

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


    };

  }

}

#endif //Shader.hpp
