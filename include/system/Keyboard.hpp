#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SDL2/SDL.h>

namespace libre{
    namespace system{

    class Keyboard{

    private:

    bool m_keys[323];
    bool m_keysHeld[323];


    public:
    Keyboard();
    ~Keyboard();

    void setKeyDown(int index);
    void setKeyUp(int index);
    void setKeyHeldDown(int index);
    void setKeyHeldUp(int index);

    bool keyDown(int index);
    bool keyHeld(int index);
    };


    }
}


#endif // KEYBOARD_H
