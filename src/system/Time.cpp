#include "../../include/system/Time.hpp"

namespace libre{

   namespace system{

     Time::Time(){
       this->m_start = time(0);
       this->m_current = time(0);
     }

     void Time::Update(){
       this->m_current = time(0);
     }

     double Time::timeElapsed(){
       this->Update();
       return  difftime (this->m_current, this->m_start );
     }

     char * Time::startCString(){
       return ctime(&this->m_start);
     }
     char * Time::currentCString(){
       return ctime(&this->m_current);
     }

   }

}
