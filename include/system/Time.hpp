#ifndef TIME_HPP_
#define TIME_HPP_

#include <iostream>
#include <time.h>
#include <string>

namespace libre {
  namespace system{

    class Time{

    private:
        time_t m_start;
        time_t m_current;

    public:
      Time();

      void Update();

      double timeElapsed();

      char * startCString();
      char * currentCString();

      static inline const std::string getCurrentTime() {
        time_t now = time(NULL);
        struct tm *times;
        char buffer[64];
        times = localtime(&now);
        strftime(buffer,sizeof(buffer), "%Y-%m-%d.%X", times);
        return buffer;
      }

    };
  }
}


#endif // Time.hpp
