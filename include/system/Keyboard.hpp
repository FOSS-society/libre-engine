#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SDL2/SDL.h>

namespace libre{
    namespace system{

    class Keyboard{

    private:
    SDL_Event *m_event;
    bool m_keys[323];
    bool m_keysHeld[323];


    public:
    Keyboard();
    Keyboard(SDL_Event *event);

    const Keyboard *KeyboardCallback();


    };


    }
}


#endif // KEYBOARD_H
