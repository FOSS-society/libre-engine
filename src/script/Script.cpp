#include "../../include/script/Script.hpp"


namespace libre{

  namespace scripting{

    Script::Script(std::string name, std::string filePath): m_Name(name), m_FilePath(filePath){

    }

    std::string Script::getName(){
      return m_Name;
    }
    std::string Script::getFilePath(){
      return m_FilePath;
    }
    std::string Script::Name()const{
      return m_Name;
    }
    std::string Script::FilePath()const{
      return m_FilePath;
    }


    void Script::setName(std::string name){
      m_Name = name;
    }
    void Script::setFilePath(std::string filepath){
      m_FilePath = filepath;
    }

  }
}
