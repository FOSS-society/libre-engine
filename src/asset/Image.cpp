#include "../../include/asset/Image.hpp"


namespace libre{
  namespace asset{
    Image::Image(std::string name, std::string filepath,unsigned int width, unsigned int height):
    Base_Asset(name,filepath), m_dimensions(width,height)
    {
      m_texture = NULL;
      m_surface = NULL;
    }
    Image::Image(std::string name, std::string filepath, math::Vector2<unsigned int> dimensions):
    Base_Asset(name,filepath), m_dimensions(dimensions)
    {
      m_texture = NULL;
      m_surface = NULL;
    }

    Image::~Image(){
    }

    void Image::load(SDL_Renderer *renderer){
      if(graphics::s_sdlIsInitialized){
        if(!this->m_isLoaded){
          this->m_surface = IMG_Load(this->m_filepath.c_str());
          this->m_texture = SDL_CreateTextureFromSurface(renderer,m_surface);
          this->m_isLoaded = true;
          }
        }else{
            std::cout << "Error, SDL is not initialized!";
        }
      }


  }
}
