#ifndef ENTITY_IMPL_HPP
#define ENTITY_IMPL_HPP

#include <vector>
#include "Component.hpp"


namespace libre{
    namespace core{

    void Entity::setChildren(const std::vector<Entity *> &children)
    {
        m_children = children;
    }

    template<class T>
    T Entity::findComponentOfType()		{
        for(unsigned int x = 0; x < m_ComponentList.size();x++){
            //for (component_Itr itr = listOfComponents.begin(); itr != listOfComponents.end(), ++itr){
            if (T type = dynamic_cast<T>(m_ComponentList.at(x)))
            {
                return type;
            }else{
                //if its not in the components:
                for(Entity * e : m_children){
                    e->findComponentOfType<T>();
                }
            }

        }
            return nullptr;
}

    template<class T>
    T Entity::findComponentByName(const char * name){
        for(auto i : this->m_ComponentList){
            if(i->Name() == name){
               return i;
            }
        }
        return nullptr;
    }


    Entity::Entity(std::string name, Entity *parent, int id):m_name(name), m_parent(parent), m_id(id)
    {
    }

    Entity::~Entity(){

    }

    Entity *Entity::child(std::string name) const
    {
        unsigned int x = 0;
        do{
            if(this->m_children.at(x)->Name().compare(name))
                return this->m_children.at(x);
            else
                x++;
        } while ( x < this->m_children.size());

        return nullptr;
    }

    void Entity::setName(std::string name){
        this->m_name = name;
    }

    std::vector<Entity *> Entity::children() const
    {
        return m_children;
    }

    Entity *Entity::child(int index) const
    {
        return m_children[index];
    }

    Entity *Entity::getChild(int index)
    {
        return m_children[index];
    }

    Entity *Entity::getChild(std::string name)
    {
        unsigned int x = 0;
        do{
            if(this->m_children.at(x)->Name().compare(name))
                return this->m_children.at(x);
            else
                x++;
        } while ( x < this->m_children.size());

        return nullptr;
    }


    std::vector<Entity *> Entity::getChildren()
    {
        return m_children;
    }

    void Entity::setComponentList(std::vector<Component *> list){
        this->m_ComponentList = list;
    }

    void Entity::setID(int id){
        this->m_id = id;
    }

    int Entity::getID(){
        return this->m_id;
    }

    int Entity::ID(){
        return this->m_id;
    }

    Entity *Entity::getParent(){
        return this->m_parent;
    }

    void Entity::setActive(bool a){
        this->m_active = a;
    }

    bool Entity::isActive(){
        return this->m_active;
    }

    bool Entity::Active() const{
        return this->m_active;
    }


    std::string Entity::Name() const{
        return this->m_name;
    }

    void Entity::setComponentList(std::nullptr_t np){
        this->m_ComponentList.clear();
    }

    void Entity::addComponent(Component *c){
        this->m_ComponentList.push_back(c);

    }

    std::vector<Component *> Entity::componentList() const{
        return this->m_ComponentList;
    }

    std::vector<Component *> Entity::getComponentList(){
        return this->m_ComponentList;
    }

    void Entity::setParent(Entity *e){
        this->m_parent = e;
    }

    Entity *Entity::Parent() const{
        return this->m_parent;
    }

    std::string Entity::getName(){
        return this->m_name;
    }

    }
}


#endif // ENTITY_IMPL_HPP
