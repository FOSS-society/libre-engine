#ifndef SHADERVARIABLE_HPP_
#define SHADERVARIABLE_HPP_

#include "graphics_common.hpp"
#include "../core/LEVariant.hpp"

namespace libre{

  namespace graphics{

  /**
     * @brief The ShaderVariable class
     *
     * A Class to represent variables within GLSL code
     *
     * String: Name
     * Variant: Data
     *
     * Notes: Can hold a series of types, i may have to work on more types in the Variant
     * but until then, this will suffice.
     *
     */

    class ShaderVariable{
    private:
      std::string m_name;
      core::Variant m_data;

    public:
      ShaderVariable():m_name(std::string()),m_data(core::Variant()){}
      ShaderVariable(std::string name, core::Variant variant);

      std::string &getName();
      core::Variant &getData();
      std::string Name()const;
      core::Variant Data()const;

      void setName(std::string name);
      void setData(core::Variant data);
    };

  }

}

#endif //Shadervariable.hpp
