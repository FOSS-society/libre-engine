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


  };


  }
}

#endif// Component.hpp
