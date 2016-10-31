#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_

#include <vector>

namespace libre{

  namespace core{

//foward declare Entity
class Entity;

/**
       * @brief The System class
       *
       * Base System class which will be extended by
       * a renderer, a physics system, audio system, etc
       *
       * so far it only contains a list of Entity Pointers.
       * Im not sure this is the best way to go so research this more
       *
       *
       */



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
