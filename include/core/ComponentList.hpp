#ifndef COMPONENTLIST_HPP_
#define COMPONENTLIST_HPP_

#include "Component.hpp"

namespace libre{
  namespace core{

      class ComponentList{
      private:
        unsigned short m_amount;
        Component * m_components;

      public:
        ComponentList(unsigned short amount);
        ComponentList(unsigned short amount, Component component);
        ComponentList(unsigned short amount, Component * components);

        ~ComponentList();

        void addComponent(Component * component);
        void removeComponent(Component * component);

        void setComponent(unsigned short index, Component * component);
        void resize(unsigned short amount);

        Component * getComponent(unsigned short index);
        Component * getComponent(std::string name);
        Component * component(unsigned short index)const;
        Component * component(std::string name)const;

      };


  }
}


#endif
