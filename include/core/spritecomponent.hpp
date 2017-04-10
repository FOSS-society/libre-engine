#ifndef SPRITECOMPONENT_HPP
#define SPRITECOMPONENT_HPP

#include "Component.hpp"
#include "../asset/Image.hpp"

namespace libre{
    namespace core{


            class SpriteComponent : public Component
            {

            private:
                asset::Image *m_Image;
            public:
                SpriteComponent(Entity * parent,char * name, asset::Image *image);
            };


    }
}
#endif // SPRITECOMPONENT_HPP
