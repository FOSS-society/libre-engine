#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <iostream>
#include <fstream>
#include <cstdarg>
#include <string>

namespace libre{
  namespace system{

  /**
     * @brief The Logger class
     *
     *
     * A Class that represents a logger.
     *
     * This is a singleton class
     */
    class Logger{
    private:
      Logger();
      Logger(const Logger&){}
      Logger &operator=(const Logger&){return *this;}
      static const std::string sFilePath;
      static Logger *sThis;
      static std::ofstream sLogFile;


    public:
      void Log(const std::string &message);
      void Log(const char * format,...);
      Logger &operator<<(const std::string &message);
      static Logger* LogInstance();
    };

    static void LogToConsoleAndFile( char const * format,...){
        Logger::LogInstance()->Log(format);
        std::cout << format << std::endl;
    }

  }
}

#endif // Logger.hpp
