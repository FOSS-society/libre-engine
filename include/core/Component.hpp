#ifndef COMPONENT_HPP_
#define COMPONENT_HPP

#include <iostream>

namespace libre{
  namespace core{

class Entity;

  class Component {

  private:
    Entity *m_parent;
    std::string m_name;

  public:
    Component(Entity * parent,std::string name):m_parent(parent),m_name(name){}
    ~Component();

    void setParent(Entity *parent){
      this->m_parent = parent;
    }

    Entity *getParent(){
      return this->m_parent;
    }
    Entity *Parent()const{
      return this->m_parent;
    }

    void setName(std::string name){
      this->m_name = name;
    }


    std::string getName(){
      return this->m_name;
    }
    std::string Name()const{
      return this->m_name;
    }


  };


  }
}

#endif// Component.hpp
