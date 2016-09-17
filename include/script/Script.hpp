#ifndef SCRIPT_HPP_
#define SCRIPT_HPP_

#include <lua5.2/lua.hpp>
#include <iostream>

namespace libre{

  namespace scripting{

    class Script{

    private:
      std::string m_Name;
      std::string m_FilePath;


    public:
      Script(std::string name, std::string filePath);

      std::string getName();
      std::string getFilePath();
      std::string Name()const;
      std::string FilePath()const;


      void setName(std::string name);
      void setFilePath(std::string filepath);

    };

  }
}

#endif //Script.hpp
