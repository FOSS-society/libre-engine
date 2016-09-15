#ifndef SHADERVARIABLE_HPP_
#define SHADERVARIABLE_HPP_

#include "graphics_common.hpp"
#include "../core/LEVariant.hpp"

namespace libre{

  namespace graphics{

    class ShaderVariable{
    private:
      std::string m_name;
      core::Variant m_data;

    public:
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
