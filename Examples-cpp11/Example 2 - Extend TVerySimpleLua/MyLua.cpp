//---------------------------------------------------------------------------
#pragma hdrstop

#include "MyLua.h"
#include <iostream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
#if defined(UNICODE) || defined(_UNICODE)
    #define tcout std::wcout
#else
    #define tcout std::cout
#endif
//---------------------------------------------------------------------------
// Print arguments and return two values (101 and 102)
int TMyLua::HelloWorld(lua_State LuaState)
{
    int ArgCount = lua_gettop(LuaState);

    tcout << __T("Hello World from C++Builder") << std::endl;
    tcout << __T("Arguments: ") << ArgCount << std::endl;

    for (int i = 1, a = ArgCount; a-- > 0; i++) {
        tcout << __T("Arg") << i << __T(": ") << lua_tointeger(LuaState, i) << std::endl;
    }

    // Clear stack
    lua_pop(LuaState, lua_gettop(LuaState));

    // Push return values
    lua_pushinteger(LuaState, 101);
    lua_pushinteger(LuaState, 102);
    return 2;
}
//---------------------------------------------------------------------------
int __fastcall TMyLua::HelloWorld2(lua_State LuaState)
{
    tcout << __T("Hello World2 from C++Builder") << std::endl;
    return 0;
}
//---------------------------------------------------------------------------
int __cdecl TMyLua::HelloWorld3(lua_State LuaState)
{
    tcout << __T("Hello World3 from C++Builder") << std::endl;
    return 0;
}
//---------------------------------------------------------------------------

