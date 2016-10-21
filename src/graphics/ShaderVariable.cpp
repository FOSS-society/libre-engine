#include "../../include/graphics/ShaderVariable.hpp"

namespace libre{
    namespace graphics{

    ShaderVariable::ShaderVariable(std::string name, core::Variant variant):m_name(name),m_data(variant)
    {

    }

    std::string &ShaderVariable::getName()
    {
        return this->m_name;
    }

    core::Variant &ShaderVariable::getData()
    {
        return this->m_data;
    }

    std::string ShaderVariable::Name() const
    {
        return this->m_name;
    }

    core::Variant ShaderVariable::Data() const
    {
        return this->m_data;
    }

    void ShaderVariable::setName(std::string name)
    {
        this->m_name = name;
    }

    void ShaderVariable::setData(core::Variant data)
    {
        this->m_data = data;
    }

}
}
