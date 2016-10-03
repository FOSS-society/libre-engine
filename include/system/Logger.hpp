#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <iostream>
#include <fstream>
#include <cstdarg>
#include <string>

namespace libre{
  namespace system{

    class Logger{
    private:
      Logger();
      Logger(const Logger&){};
      Logger &operator=(const Logger&){return *this;};
      static const std::string sFilePath;
      static Logger *sThis;
      static std::ofstream sLogFile;


    public:
      void Log(const std::string &message);
      void Log(const char * format,...);
      Logger &operator<<(const std::string &message);
      static Logger* LogInstance();
    };


  }
}

#endif // Logger.hpp
