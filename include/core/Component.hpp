#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include <iostream>


namespace libre{
  namespace core{

    class Entity;
  /**
   * @brief The Component class
   *
   * The base class for Components inside the engine
   * such as: SpriteComponent, TransformComponent,PhysicsComponent,
   * etc
   *
   * Entity: Parent
   * String: Name
   *
   * Notes: Completely written in this header file
   *        Supports const objects.
   *
   *
   */


  class Component {




  private:
    Entity *m_parent;
    char * m_name;

  public:
    Component(Entity * parent,char * name):m_parent(parent),m_name(name){

    }
   virtual ~Component();

    void setParent(Entity *parent){
      this->m_parent = parent;
    }

    Entity *getParent(){
      return this->m_parent;
    }
    Entity *Parent()const{
      return this->m_parent;
    }

    void setName(const char * name){
      this->m_name = (char *)name;
    }


    const char * getName(){
      return this->m_name;
    }
    const char * Name()const{
      return this->m_name;
    }


  };


  }
}

#endif// Component.hpp
