#ifndef TIME_HPP_
#define TIME_HPP_

#include <ctime>

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

    };
  }
}


#endif // Time.hpp
