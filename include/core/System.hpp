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
       * Variables: m_list: This is the list of objects which will be
       * usable within the system.
       *
       * m_root: The whole scenegraph in memory.
       *
       */



      class System{

      private:
        std::vector<Entity*> *m_list;
        Entity* m_root;
      public:
        System();
        System(Entity* root);
        ~System();

        virtual void initialize();
        virtual void update();
        virtual void fixedUpdate();
        virtual void destroyed();
        inline void addEntity(Entity* ent);
        Entity * entityAt(int index);

        std::vector<Entity*> *getList();
        std::vector<Entity *> *list() const;
        void setList(std::vector<Entity *> *list);

        Entity *getRoot();
        Entity *root() const;
        void setRoot(Entity *root);
      };

      Entity *System::root() const
      {
          return m_root;
      }

      void System::setRoot(Entity *root)
      {
          m_root = root;
      }
      System::System():m_list(new std::vector<Entity*>(20)){
          m_root = m_list->at(0);
      }

      System::System(Entity *root):m_list(new std::vector<Entity*>(20)),m_root(root)
      {
          m_list->push_back(root);
      }

      void System::addEntity(Entity *ent){m_list->push_back(ent);}

      Entity *System::entityAt(int index) { return m_list->at(index);}

      std::vector<Entity *> *System::getList()
      {
          return m_list;
      }

      std::vector<Entity *> *System::list() const
      {
          return m_list;
      }

      void System::setList(std::vector<Entity *> *list)
      {
          m_list = list;
      }

      Entity *System::getRoot()
      {
          return m_root;
      }


  }

}



#endif
