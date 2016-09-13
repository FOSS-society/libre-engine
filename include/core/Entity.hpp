#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <iostream>
#include <vector>

#include "ComponentList.hpp"

namespace libre{
  namespace core{

      class Component;

    class Entity{

    private:
      std::string m_name;
     ComponentList m_ComponentList;
      Entity * m_parent;
      int m_id;
      bool m_active;

    public:
      Entity(std::string name, Entity * parent, int id);
      Entity(const Entity &&move);

      ~Entity();

      void setActive(bool a);
      bool isActive();
      bool Active()const;

      void setID(int id);
      int getID();
      int ID();

      template <class comp>
      comp getComponent(std::string name){
          return this->m_ComponentList.getComponent(name);
      }

      Component getComponent(int id);

    };
  }
}

#endif //Entity.hpp
