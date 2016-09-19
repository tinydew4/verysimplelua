//---------------------------------------------------------------------------
#ifndef MyPackage2H
#define MyPackage2H
//---------------------------------------------------------------------------
#include "../../Source/VerySimple.Lua.Lib.hpp"
#include "../../Source/VerySimple.Lua.hpp"
//---------------------------------------------------------------------------
class TMyPackage2 : public TPersistent
{
__published:
    int __fastcall Double(lua_State L);

};
//---------------------------------------------------------------------------
#endif
