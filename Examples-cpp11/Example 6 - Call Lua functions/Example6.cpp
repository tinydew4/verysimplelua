#include <vcl.h>
#include <windows.h>

#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <memory>
#include "../../Source/VerySimple.Lua.Lib.hpp"
#include "../../Source/VerySimple.Lua.hpp"

#if defined(UNICODE) || defined(_UNICODE)
    #define tcout std::wcout
#else
    #define tcout std::cout
#endif

int __fastcall LuaAdd(lua_State L, int x, int y)
{
    lua_getglobal(L, "add"); // name of the funciton
    lua_pushinteger(L, x); // first parameter
    lua_pushinteger(L, y); // second parameter
    lua_call(L, 2, 1); // call function with 2 parameters and 1 result
    int iResult = lua_tointeger(L, -1); // get reuslt
    lua_pop(L, 1); // remove result from stack
    return iResult;
}

int _tmain(int argc, _TCHAR* argv[])
{
    /* Example 6 - Call a lua function */
    try {
        const std::unique_ptr<TVerySimpleLua> Lua(std::make_unique<TVerySimpleLua>());
        Lua->LibraryPath = String("../../DLL/Win32/") + LUA_LIBRARY;
        Lua->DoFile("example6.lua");
        tcout << LuaAdd(Lua->LuaState, 10, 20) << std::endl;
        std::cin.get();
    } catch (Exception &E) {
        tcout << E.ClassName().c_str() << ": " << E.Message.c_str() << std::endl;
    }
	return 0;
}

