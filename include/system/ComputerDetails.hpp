#ifndef COMPUTERDETAILS_HPP
#define COMPUTERDETAILS_HPP

#include <sys/utsname.h>


#include "../math/libremath.hpp"

namespace libre{

    namespace system{




    class ComputerDetails{

    private:
        math::Vector2<uint8_t> m_oglVersion;
        math::Vector3<uint8_t> m_sdlVersion;
        utsname m_LinuxVersion;

    public:
        ComputerDetails();
    };


    }

}



#endif // COMPUTERDETAILS_HPP
