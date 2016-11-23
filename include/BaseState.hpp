#ifndef BASESTATE_HPP
#define BASESTATE_HPP



namespace libre{

//Foward Declare
class Application;


    class BaseState{

    private:
       Application *m_app;

    public:
        virtual ~BaseState(){}

        virtual bool initialize()=0;
        virtual bool FixedUpdate()=0;
        virtual bool Update()=0;
        virtual bool destroy()=0;
        virtual Application *getApp(){return m_app;}
        virtual void setApp(Application *app){ m_app = app;}
    };



}


#endif // BASESTATE_HPP
