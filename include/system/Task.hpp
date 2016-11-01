#ifndef TASK_HPP
#define TASK_HPP

#include <functional>
#include <mutex>
#include <vector>

namespace libre{
    namespace system{
    struct Argument{
        int m_arg;
        char *m_argv[];

        Argument(int arg, char *argv[]):m_arg(arg),m_argv(argv)
        {    
        }
    };

    enum class ThreadState{
        ts_START,
        ts_PAUSE,
        ts_RESUME,
        ts_STOP,
        ts_NULL
    };

   void empty()
   {
   }

    class Task{

    private:
        ThreadState state;
        std::function<void()> m_runningFunction;
        std::function<void()> m_stopFunction;
        std::function<void()> m_pauseFunction;
        std::function<void()> m_reStartFunction;
        std::mutex m_callbackMutex;
        std::vector<std::function<void()>> m_callbacks;
    public:
    Task();
    Task(std::function<void()> task);
    Task(std::function<void()> task, std::function<void()> pause, std::function<void()> restart);


   std::function<void()> getRunningFunc();
   std::function<void()> getStopFunc();
   std::function<void()> getpauseFunc();
   std::function<void()> getreStartFunc();
   std::function<void()> getCallback(int index);

   std::vector<std::function<void()>> getCallbacks();

   void setRunning(std::function<void()> run);
   void setStop(std::function<void()> stop);
   void setPause(std::function<void()> pause);
   void setRestart(std::function<void()> restart);
   void setMutex(std::mutex mutex);
   void addCallback(std::function<void()> callback);
   void removeCallback(std::function<void()> callback);

    void Update();

    };



    }
}


#endif // TASK_HPP
