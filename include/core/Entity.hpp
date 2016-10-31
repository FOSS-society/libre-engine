#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <iostream>
#include <vector>



namespace libre{
  namespace core{

//foward declare
  class Component;


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

    class Entity{

    private:
      std::string m_name;
      std::vector<Component*> m_ComponentList;
      Entity *m_parent;
      int m_id;
      bool m_active;

    public:
      Entity(std::string name, Entity * parent, int id):m_name(name), m_parent(parent), m_id(id){}
      Entity(Entity &&m) = default;




      ~Entity(){

      }

      void setName(std::string name){
        this->m_name = name;
      }

      std::string Name()const{
        return this->m_name;
      }

      std::string getName(){
        return this->m_name;
      }

      void setComponentList(std::vector<Component*> list){
        this->m_ComponentList = list;
      }
      void setComponentList(std::nullptr_t np){
        this->m_ComponentList.clear();
      }

      void addComponent(Component *c){
        this->m_ComponentList.push_back(c);
      }

      std::vector<Component*> componentList()const{
        return this->m_ComponentList;
      }

      std::vector<Component*> getComponentList(){
        return this->m_ComponentList;
      }

      void setParent(Entity *e){
        this->m_parent = e;
        }

        Entity *Parent()const{
          return this->m_parent;
        }

        Entity *getParent(){
          return this->m_parent;
        }

      void setActive(bool a){
        this->m_active = a;
      }
      bool isActive(){
        return this->m_active;
      }
      bool Active()const{
        return this->m_active;
      }

      void setID(int id){
        this->m_id = id;
      }
      int getID(){
        return this->m_id;
      }
      int ID(){
        return this->m_id;
      }


    };
  }
}

#endif //Entity.hpp
