#include <libre-engine/Application.hpp>
#include <libre-engine/asset/Image.hpp>


using namespace libre;

class TestState:public BaseState{

    asset::Image *ball;


    // BaseState interface
public:
    SDL_Rect rect;
    math::Vector2<int> pos;
    TestState(){}
    bool initialize()
    {
        pos = math::Vector2<int>(50,50);
        rect.h = 128;
        rect.w = 128;
        ball = new asset::Image("ball","ball.png",128,128);
        rect.x = pos.X();
        rect.y = pos.Y();
        return true;
    }
    bool FixedUpdate()
    {
        return true;
    }
    bool Update()
    {
        SDL_RenderCopy(this->getApp()->Renderer()->getContext()->asSDL,ball->texture(),NULL,&rect);
        //SDL_RenderDrawRect(this->getApp()->Renderer()->getContext()->asSDL,&rect);
        return true;
    }
    bool destroy()
    {

        return true;
    }
};





int main(int argc, char *argv[]){


    Application *test = new Application(std::string("Libre-Engine v0.2.0 Test").c_str(),480,640,graphics::RendererType::RT_2D,new TestState());
    test->getState()->setApp(test);

    while(test->Run());

    return 0;


}
