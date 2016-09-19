#include <vcl.h>
#include <windows.h>

#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <iostream>
#include <memory>
#include "MyLua.h"

#if defined(UNICODE) || defined(_UNICODE)
    #define tcout std::wcout
#else
    #define tcout std::cout
#endif

int _tmain(int argc, _TCHAR* argv[])
{
    try {
        std::unique_ptr<TMyLua> MyLua(std::make_unique<TMyLua>());
        MyLua->DoFile("example5.lua");
        std::cin.get();
    } catch (Exception &E) {
        tcout << E.ClassName().c_str() << __T(": ") << E.Message.c_str() << std::endl;
    }
	return 0;
}
