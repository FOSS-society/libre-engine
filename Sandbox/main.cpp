#include <libre-engine/Application.hpp>
#include <libre-engine/asset/Image.hpp>


using namespace libre;

class TestState:public DefaultState{

private:
    asset::Image *ball;


    // BaseState interface
public:
    SDL_Rect rect;
    math::Vector2<int> winSize;
    math::Vector2<int> velocity;
    math::Vector2<int> pos;
    TestState():ball(new asset::Image("ball","ball.png",128,128)),
                winSize(480,640),
                velocity(1,1),
                pos(math::Vector2<int>(50,50))
          {

}
    bool initialize()
    {
        ball->load(m_app->getRenderer()->getContext()->asSDL);
        winSize = math::Vector2<int>(480,640);
        rect.h = 32;
        rect.w = 32;
        rect.x = pos.getX();
        rect.y = pos.getY();
        return true;
    }
    bool FixedUpdate()
    {
        return true;
    }
    bool Update()
    {

        std::cout << "WinSize: X: " << winSize.getX() << ", Y: " <<winSize.getY() <<std::endl;
        std::cout <<" RectPosition:X: " << rect.x << ", Y: " << rect.y << std::endl;
        std::cout << "Velocity:X: " << velocity.getX() << ", Y: " << velocity.getY()<< std::endl;
        if(rect.x+rect.w >= winSize.getX() || rect.y+rect.h >=winSize.getY()){
            velocity.setX(-2);
            velocity.setY(-2);
        }else if(rect.x <=0 || rect.y <=0){
            velocity.setX(2);
            velocity.setY(2);
        }

        rect.x +=velocity.getX();
        rect.y +=velocity.getY();

        if (SDL_RenderCopy(this->getApp()->getRenderer()->getContext()->asSDL,ball->texture(),NULL,&rect) !=0){
        std::cout << "SDL Error: " << SDL_GetError();
    }
        //SDL_RenderDrawRect(this->getApp()->Renderer()->getContext()->asSDL,&rect);
        return true;
    }
    bool destroy()
    {

        return true;
    }

    // BaseState interface
public:
    Application *getApp()
    {
        return m_app;
    }
    void setApp(Application *app)
    {
        m_app = app;
    }
};





int main(int argc, char *argv[]){

    TestState *ts = new TestState();
    Application::Instance = new Application(std::string("Libre-Engine v0.2.0 Test").c_str(),480,640,graphics::RendererType::RT_2D, ts);
    Application::Instance->Initialize();
    while(Application::Instance->Run());

    return 0;


}
