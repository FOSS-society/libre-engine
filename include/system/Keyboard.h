#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SDL2/SDL.h>

namespace libre{
    namespace system{

    class Keyboard{

    private:
    SDL_Event *m_event;
    bool keys[323];


    public:
    Keyboard();
    Keyboard(SDL_Event *event);
    };


    }
}


#endif // KEYBOARD_H
