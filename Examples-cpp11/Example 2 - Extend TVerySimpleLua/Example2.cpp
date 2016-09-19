#include <vcl.h>
#include <windows.h>

#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <memory>
#include <iostream>
#include "MyLua.h"

#if defined(UNICODE) || defined(_UNICODE)
    #define tcout std::wcout
#else
    #define tcout std::cout
#endif

int _tmain(int argc, _TCHAR* argv[])
{
    try {
        std::unique_ptr<TMyLua> Lua(std::make_unique<TMyLua>());
        Lua->LibraryPath = String("../../DLL/Win64/") + LUA_LIBRARY;
        Lua->AutoRegister = false;
        Lua->RegisterFunction("HelloWorld");
        Lua->RegisterFunction("HelloWorld2");
        Lua->RegisterFunction("HelloWorld3");
        Lua->DoFile("example2.lua");
        std::cin.get();
    } catch (Exception &E) {
        tcout << E.ClassName().c_str() << __T(": ") << E.Message.c_str() << std::endl;
    }
	return 0;
}
