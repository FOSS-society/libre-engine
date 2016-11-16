#include "../../include/system/Logger.hpp"
#include "../../include/system/Time.hpp"

namespace libre{
  namespace system{

    const std::string Logger::sFilePath = "EngineLog.txt";
    Logger* Logger::sThis = NULL;
    std::ofstream Logger::sLogFile;

    Logger::Logger(){

    }
    Logger* Logger::LogInstance(){
      if(sThis == NULL){
        sThis = new Logger();
        sLogFile.open(sFilePath.c_str(),std::ios::out |std::ios::app);
      }
      return sThis;
    }

    void Logger::Log(const char * format,...){
    char* sMessage = NULL;
    int nLength = 0;
    va_list args;
    va_start(args, format);
    //  Return the number of characters in the string referenced the list of arguments.
    // _vscprintf doesn't count terminating '\0' (that's why +1)
    nLength = printf(format, args);
    sMessage = new char[nLength];
    snprintf(sMessage, nLength, format, args);
    //vsprintf(sMessage, format, args);
    sLogFile << Time::getCurrentTime() << ":\t";
    sLogFile << sMessage << "\n";
    va_end(args);
    sLogFile.flush();

    delete [] sMessage;
}

void Logger::Log(const std::string& sMessage)
{
    sLogFile <<  Time::getCurrentTime() << ":\t";
    sLogFile << sMessage << "\n";
    sLogFile.flush();
}

Logger& Logger::operator<<(const std::string& sMessage)
{
    sLogFile << "\n" << Time::getCurrentTime()<< ":\t";
    sLogFile << sMessage << "\n";
    sLogFile.flush();
    return *this;
}

  }
}
