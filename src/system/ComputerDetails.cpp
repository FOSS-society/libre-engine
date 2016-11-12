#include "../../include/system/ComputerDetails.hpp"
#include "../../include/system/Utility.hpp"

#include <iostream>

namespace libre{

namespace system{

ComputerDetails::ComputerDetails()
{
    this->m_oglVersion = Utility::getOpenGLVersionCompat();
    this->m_sdlVersion = Utility::getSDLVersion();

    std::cout << "uname returns as : " << uname(&this->m_LinuxVersion);


}




    }
}
