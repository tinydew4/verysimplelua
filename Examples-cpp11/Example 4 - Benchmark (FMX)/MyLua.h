//---------------------------------------------------------------------------
#ifndef MyLuaH
#define MyLuaH
//---------------------------------------------------------------------------
#include <System.Diagnostics.hpp>
#include <memory>
#include "../../Source/VerySimple.Lua.Lib.hpp"
#include "../../Source/VerySimple.Lua.hpp"
//---------------------------------------------------------------------------
class TMyLua : public TVerySimpleLua
{
    typedef Verysimple::Lua::TVerySimpleLua inherited;

public:
    __int64 MilliSeconds;
    std::unique_ptr<TStopwatch> Sw;
    __int64 lastbench;

__published:
    __fastcall TMyLua(void);

    int __fastcall Start(lua_State LuaState);
    int __fastcall Finished(lua_State LuaState);
    int __fastcall HelloWorld(lua_State LuaState);
    __classmethod int __fastcall HelloWorld2(lua_State LuaState);
    static int __cdecl HelloWorld3(lua_State LuaState);

};
//---------------------------------------------------------------------------
#endif
