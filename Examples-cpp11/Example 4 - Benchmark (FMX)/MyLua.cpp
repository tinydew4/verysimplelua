//---------------------------------------------------------------------------
#pragma hdrstop

#include "MyLua.h"
#include <System.SysUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TMyLua::TMyLua(void)
    : inherited()
    , Sw(std::make_unique<TStopwatch>())
{
    #if defined(__WIN32__)
    LibraryPath = String("../../DLL/WIN32/") + LUA_LIBRARY;
    #elif defined(_WIN64)
    LibraryPath = String("../../DLL/WIN64/") + LUA_LIBRARY;
    #endif
}
//---------------------------------------------------------------------------
int __fastcall TMyLua::Start(lua_State LuaState)
{
    MilliSeconds = lua_tointeger(LuaState, 1) * 1000;
    lastbench = 0;
    Sw->Reset();
    Sw->Start();
    return 0;
}
//---------------------------------------------------------------------------
int __fastcall TMyLua::Finished(lua_State LuaState)
{
    __int64 ElapsedSeconds = Sw->ElapsedMilliseconds / 1000;
    if (ElapsedSeconds > lastbench) {
        lastbench = ElapsedSeconds;
        OnPrint("...");
    }
    if (Sw->ElapsedMilliseconds > MilliSeconds) {
        lua_pushboolean(LuaState, 1);
    } else {
        lua_pushboolean(LuaState, 0);
    }
    return 1;
}
//---------------------------------------------------------------------------
int __fastcall TMyLua::HelloWorld(lua_State LuaState)
{
    lua_pushinteger(LuaState, lua_tointeger(LuaState, 1) * 2);
    return 1;
}
//---------------------------------------------------------------------------
__classmethod int __fastcall TMyLua::HelloWorld2(lua_State LuaState)
{
    lua_pushinteger(LuaState, lua_tointeger(LuaState, 1) * 2);
    return 1;
}
//---------------------------------------------------------------------------
int __cdecl TMyLua::HelloWorld3(lua_State LuaState)
{
    lua_pushinteger(LuaState, lua_tointeger(LuaState, 1) * 2);
    return 1;
}
//---------------------------------------------------------------------------

