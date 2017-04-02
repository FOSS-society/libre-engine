#include "../../include/core/spritecomponent.hpp"




namespace libre{
    namespace core{


            SpriteComponent::SpriteComponent(Entity *parent, char *name, asset::Image *image):Component(parent,name),m_Image(image)
            {
            }

    }
}
