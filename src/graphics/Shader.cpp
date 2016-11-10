#include "../../include/graphics/Shader.hpp"
#include "../../include/system/Utility.hpp"

namespace libre{

namespace graphics{

libre::graphics::Shader::Shader(std::string name, std::string filepath, libre::graphics::ShaderType type):
    m_name(name),m_filePath(filepath),m_type(type)
{
    this->m_Source = Utility::readFile(filepath.c_str());
}

ShaderType Shader::getType()
{
    return m_type;
}

ShaderType Shader::Type()const
{
    return m_type;
}



    }
}
