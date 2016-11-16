#include "../../include/system/ComputerDetails.hpp"
#include "../../include/system/Utility.hpp"

#include <iostream>

namespace libre{

namespace system{

ComputerDetails::ComputerDetails()
{
    this->m_GLinformation = OpenGLInformation();
    this->m_sdlVersion = Utility::getSDLVersion();

    printLinuxVersion();



}

void ComputerDetails::printLinuxVersion()
{
    std::cout << "uname returns as : " << uname(&this->m_LinuxVersion);
    std::cout << "System Name: " << m_LinuxVersion.sysname << std::endl;
    std::cout << "Machine: " << m_LinuxVersion.machine << std::endl;
    std::cout << "Version: " << m_LinuxVersion.version << std::endl;
    std::cout << "Release: " << m_LinuxVersion.release << std::endl;
}

OpenGLInformation::OpenGLInformation(){
    version = math::Vector2<uint8_t>(Utility::getOpenGLVersionCompat());
    OpenGL::getString(GL_VENDOR,vendor);
    OpenGL::getString(GL_RENDERER,renderer);
    OpenGL::getString(GL_SHADING_LANGUAGE_VERSION,shader_version);
}




}
}
