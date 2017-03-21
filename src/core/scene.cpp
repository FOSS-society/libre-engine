#include "include/core/scene.hpp"

namespace libre{
    namespace core{


            Scene::Scene()
            {
                m_root = new Entity("root",0);
                m_systems = std::vector<System *>();
            }

            Scene::~Scene()
            {
                delete m_root;
                delete m_systems;
            }

            void Scene::AttachSystem(System *sys)
            {
                m_systems.push_back(sys);
            }
    }
}
