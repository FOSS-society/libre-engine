#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "graphics/Renderer.hpp"
#include "system/Mouse.hpp"
#include "system/Keyboard.hpp"

#include "system/ComputerDetails.hpp"

#include "DefaultState.hpp"

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

        ~Application();

      BaseState *m_state;
      bool m_active;
        graphics::Window *m_Window;
        graphics::Renderer *m_Renderer;
        system::Mouse *m_Mouse;
        system::Keyboard *m_Keyboard;
        system::ComputerDetails * m_HostInfo;


    public:
        Application(const char *t, int width, int height, graphics::RendererType rt);
        Application(const char *t, int width, int height, graphics::RendererType rt, BaseState *state);
        void Initialize();
        bool Run();
        void Stop();
        static Application *Instance;

        graphics::Renderer *Renderer() const;
        graphics::Renderer *getRenderer();

        void setRenderer(graphics::Renderer *Renderer);
        system::Mouse *Mouse() const;
        system::Mouse *getMouse();

        void setMouse(system::Mouse *Mouse);
        system::Keyboard *Keyboard() const;
        system::Keyboard *getKeyboard();

        void setKeyboard(system::Keyboard *Keyboard);
        system::ComputerDetails *HostInfo() const;
        system::ComputerDetails *getHostInfo();

        void setHostInfo(system::ComputerDetails *HostInfo);
        graphics::Window *Window() const;
        graphics::Window *getWindow();

        void setWindow(graphics::Window *Window);
        BaseState *state() const;
        BaseState *getState();
        void setState(BaseState *state);
    };


}
#endif // APPLICATION_HPP
