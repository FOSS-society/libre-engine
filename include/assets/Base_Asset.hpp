#ifndef BASE_ASSET_HPP_
#define BASE_ASSET_HPP_

#include <iostream>

namespace libre{
  namespace asset{

      class Base_Asset{
      protected:
          std::string m_Name;
          std::string m_FilePath;

      public:
        Base_Asset(std::string name, std::string filePath);
        ~Base_Asset();

        void setName(std::string name);
        void setFilePath(std::string filepath);

        std::string getName();
        std::string Name() const;

        std::string getFilePath();
        std::string FilePath() const;

      };


  }
}


#endif //Base_Asset
