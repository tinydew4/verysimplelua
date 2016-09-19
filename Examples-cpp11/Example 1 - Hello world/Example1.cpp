#include <vcl.h>
#include <windows.h>

#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <memory>
#include <iostream>
#include "../../Source/VerySimple.Lua.hpp"
#include "../../Source/VerySimple.Lua.Lib.hpp"

#if defined(UNICODE) || defined(_UNICODE)
    #define tcout std::wcout
#else
    #define tcout std::cout
#endif

int _tmain(int argc, _TCHAR* argv[])
{
    try {
        std::unique_ptr<TVerySimpleLua> Lua(std::make_unique<TVerySimpleLua>());
        Lua->LibraryPath = String("..\\..\\DLL\\Win32\\") + LUA_LIBRARY;
        Lua->DoFile("example1.lua");
        std::cin.get();
    } catch (Exception &E) {
        tcout << E.ClassName().c_str() << __T(": ") << E.Message.c_str() << std::endl;
    }
	return 0;
}
