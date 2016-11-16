#ifndef COMPUTERDETAILS_HPP
#define COMPUTERDETAILS_HPP

#include <sys/utsname.h>
#include "OpenGL.hpp"
#include "../math/vector3.hpp"




namespace libre{

    namespace system{

    struct OpenGLInformation{
        math::Vector2<uint8_t> version;
        GLubyte * vendor;
        GLubyte * renderer;
        GLubyte * shader_version;

        OpenGLInformation();

    };


    class ComputerDetails{

    private:
        OpenGLInformation m_GLinformation;
        math::Vector3<uint8_t> m_sdlVersion;
        utsname m_LinuxVersion;

    public:
        ComputerDetails();

        void printLinuxVersion();

        OpenGLInformation OpenGLInfo()const{return m_GLinformation;}
        OpenGLInformation getOpenGLInfo(){return m_GLinformation;}

        math::Vector3<uint8_t> getSDLVersion(){return m_sdlVersion;}
        math::Vector3<uint8_t> SDLVersion()const{return m_sdlVersion;}

        utsname getLinuxInfo(){return m_LinuxVersion;}
        utsname LinuxInfo()const{return m_LinuxVersion;}


    };


    }

}



#endif // COMPUTERDETAILS_HPP
