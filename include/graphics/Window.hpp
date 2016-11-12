#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "graphics_common.hpp"

namespace libre{
    namespace graphics{


    /**
         * @brief The Window class
         *
         * A Class that represents the window of the program
         *
         * Const Char*: Title
         * SDL_Window*: WindowHandle
         * Vector2<unsigned int>: size_t
         *
         * This encapsulates an SDL Window object to allow creation of more moduler windows
         * upon creation.
         */
        class Window{

        private:
          const char * m_title;
          SDL_Window *m_window;
          math::Vector2<unsigned int> m_size;
          bool setOpenGLAttributes();
          bool setOpenGLAttributes(const uint8_t maj, const uint8_t min);
          bool setOpenGLAttributes(const math::Vector2<uint8_t> &version);


        public:
          Window(const char * t,const unsigned int width,const unsigned int height);
          Window(const char * t,math::Vector2<unsigned int> size);

          const char * Title();
          SDL_Window * SDLWIN();
          math::Vector2<unsigned int> Size();




        };

    }
}
#endif //Window
