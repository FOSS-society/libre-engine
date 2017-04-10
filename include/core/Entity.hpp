#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>

namespace libre{
  namespace core{


  /**
     * @brief The Entity class
     *
     * A Class that represents an Entity in the Engine
     *
     * String: Name
     * Vector<Component*> ComponentList
     * Entity*: parent
     * int: id
     * bool: Active
     *
     * Notes this class is all contained within this header file
     *
     */

  class Component;

    class Entity{

    private:
      std::string m_name;
      std::vector<Component*> m_ComponentList;
      Entity *m_parent;
      std::vector<Entity *> m_children;
      int m_id;
      bool m_active;

    public:
      Entity(std::string name, Entity * parent, int id);
      Entity(Entity &&m) = default;

      template<typename T>
      T findComponentOfType();

      template<typename T>
      T findComponentByName(const char * name);


      ~Entity();

      void setName(std::string name);

      std::string Name()const;

      std::string getName();

      void setComponentList(std::vector<Component*> list);
      void setComponentList(std::nullptr_t np);

      void addComponent(Component *c);

      std::vector<Component*> componentList()const;

      std::vector<Component*> getComponentList();

      void setParent(Entity *e);

        Entity *Parent()const;

        Entity *getParent();

      void setActive(bool a);
      bool isActive();
      bool Active()const;

      void setID(int id);
      int getID();
      int ID();


      std::vector<Entity *> children() const;
      std::vector<Entity *> getChildren();

      Entity * child(int index)const;

      Entity *child(std::string name)const;

      Entity * getChild(int index);
      Entity *getChild(std::string name);

      void setChildren(const std::vector<Entity *> &children);


    };




  }
}

#include "Entity_impl.hpp"

#endif //Entity.hpp
