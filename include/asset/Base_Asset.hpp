#ifndef BASE_ASSET_HPP_
#define BASE_ASSET_HPP_

#include <iostream>

namespace libre{
  namespace asset{

      class Base_Asset{
      private:
          std::string m_name;
          std::string m_filepath;
          bool m_isLoaded;

      public:
        Base_Asset(std::string name, std::string filePath):m_name(name),m_filepath(filePath),m_isLoaded(false){}
        Base_Asset():m_isLoaded(false){}
        ~Base_Asset() = default;

        inline void setName(std::string name){this->m_name = name;}
        inline void setFilePath(std::string filepath){this->m_filepath = filepath;}
        inline void setLoad(bool loaded){this->m_isLoaded = loaded;}

        inline std::string getName(){ return m_name;}
        inline std::string Name() const{ return m_name;}

        inline std::string getFilePath(){ return m_filepath;}
        inline std::string FilePath() const{ return m_filepath;}

        inline bool isLoaded(){ return m_isLoaded;}
        inline bool Loaded()const { return m_isLoaded;}
      };
  }
}
#endif //Base_Asset.hpp
