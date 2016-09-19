//---------------------------------------------------------------------------
#pragma hdrstop

#include "MyPackage2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
int __fastcall TMyPackage2::Double(lua_State L)
{
    int ArgCount = lua_gettop(L);

    // Get last argument as value - ArgCount is different if called via MyPackage2.Double() or MayPackage2:Double()!
    int Value = lua_tointeger(L, ArgCount);

    // Double the value
    Value <<= 1;

    // Push the result
    lua_pushinteger(L, Value);

    // There is one value on the result stack
    return 1;
}
//---------------------------------------------------------------------------

