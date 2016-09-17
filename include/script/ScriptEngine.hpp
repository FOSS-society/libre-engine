#ifndef SCRIPT_ENGINE_HPP_
#define SCRIPT_ENGINE_HPP

#include <lua5.2/lua.hpp>

#include "Script.hpp"

namespace libre{

  namespace scripting{

    class ScriptEngine{

    private:
      lua_State *m_interpreter;


    public:
      ScriptEngine(){
        this->m_interpreter = luaL_newstate();
        luaL_openlibs(this->m_interpreter);

      }
      ~ScriptEngine(){
        lua_close(this->m_interpreter);
      }

      lua_State *getInterpreter();
      lua_State *interpreter()const;

      bool loadScript(Script *script);



    };

  }

}

#endif// ScriptEngine.hpp
