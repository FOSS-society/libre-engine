#ifndef DEFAULTSTATE_HPP
#define DEFAULTSTATE_HPP

#include "BaseState.hpp"

namespace libre{

    class DefaultState : public BaseState{





    public:
        DefaultState();
         // BaseState interface
        bool initialize()override;
        bool FixedUpdate()override;
        bool Update()override;
        bool destroy()override;

        // BaseState interface
    public:


    };


}


#endif // DEFAULTSTATE_HPP
