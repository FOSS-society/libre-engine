#ifndef IMAGE_HPP_
#define IMAGE_HPP_

#include "../graphics/graphics_common.hpp"
#include "Base_Asset.hpp"

namespace libre{
  namespace asset{
    /**
      * Class: Image
      * Description: a class which describes an Image Asset
      *
      * Vector2<Unsigned Int>: Dimension
      * SDL_Texture*: Texture
      * SDL_Surface*: Surface
      *
      * the Images load function loads the image into a texture as well as a surface.

    */

    class Image: private Base_Asset{
    private:
      math::Vector2<unsigned int> m_dimensions;
      SDL_Texture * m_texture;
      SDL_Surface * m_surface;
    public:
      Image(std::string name, std::string filepath, unsigned int width, unsigned int height);
      Image(std::string name, std::string filepath, math::Vector2<unsigned int> dimensions);
      ~Image();

      void load(SDL_Renderer* renderer);


    };


  }
}



#endif //Image.hpp
