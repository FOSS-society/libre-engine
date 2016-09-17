#include "../../include/script/ScriptEngine.hpp"

namespace libre{
  namespace scripting{


          lua_State *ScriptEngine::getInterpreter(){
            return m_interpreter;
          }
          lua_State *ScriptEngine::interpreter()const{
            return m_interpreter;
          }

          bool ScriptEngine::loadScript(Script *script){

            return luaL_dofile(m_interpreter,script->getFilePath().c_str());
          }


  }
}
