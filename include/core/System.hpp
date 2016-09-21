#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_

#include <vector>

namespace libre{

  namespace core{

//foward declare Entity
class Entity;

      class System{

      private:
        std::vector<Entity*> *m_list;

      public:
        System():m_list(new std::vector<Entity*>(20)){
        }
        ~System();

        virtual void initialize();
        virtual void update();
        virtual void fixedUpdate();
        virtual void destroyed();


      };

  }

}



#endif
