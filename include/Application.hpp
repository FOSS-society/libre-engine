#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "graphics/Renderer.hpp"
#include "system/Mouse.hpp"

/////////////////////////////////
///
/// Current Notes, I will depreciating the
/// engine class and changing the ideology to
/// use this application class instead.
/////////////////////////////////

namespace libre{

    class ApplicationException:public std::runtime_error{
    public:
        ApplicationException(const std::string& error):std::runtime_error(error){}
    };

    class Application{

    private:
        Application(const char *t, int width, int height, graphics::RendererType rt);
        ~Application();
      static Application *m_instance;
        bool m_active;
        graphics::Window *m_Window;
        graphics::Renderer *m_Renderer;
        system::Mouse *m_Mouse;



    public:
        bool Run();
        void Stop();
        static Application *Instance();

    };


}
#endif // APPLICATION_HPP
