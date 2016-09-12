#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "graphics_common.hpp"

namespace libre{
    namespace graphics{

        class Window{

        private:
          char * m_title;
          SDL_Window *m_window;
          math::Vector2<unsigned int> m_size;

        public:
          Window(char * t,const unsigned int width,const unsigned int height);
          Window(char * t,math::Vector2<unsigned int> size);

          const char * Title();
          SDL_Window * SDLWIN();
          math::Vector2<unsigned int> Size();


        };

    }
}
#endif //Window
