#ifndef SCENE_HPP
#define SCENE_HPP

#include "Entity.hpp"
#include "System.hpp"
#include <vector>

namespace libre{
    namespace core{


        class Scene
        {
        private:
            Entity * m_root; //define the root entity of the scene
            std::vector<System *> m_systems; //systems which would be updated
        public:
            Scene();
            ~Scene();

            void AttachSystem(System * sys);
            void Update();

        };


    }
}
#endif // SCENE_HPP
