//---------------------------------------------------------------------------
#pragma hdrstop

#include "MyPackage.h"
#include <System.SysUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
int __fastcall TMyPackage::LoadPackage(lua_State L)
{
    lua_newtable(L);

    // Manually and MyFunction1
    TVerySimpleLua::PushFunction(L, this, MethodAddress((String)"Myfunction1"), "Myfunction1");
    lua_rawset(L, -3);

    // Manually add Myfunction2
    TVerySimpleLua::PushFunction(L, this, MethodAddress((String)"Myfunction2"), "Myfunction2");
    lua_rawset(L, -3);

    return 1;
}
//---------------------------------------------------------------------------
int __fastcall TMyPackage::Myfunction1(lua_State L)
{
    // Push a return value
    lua_pushinteger(L, 54);
    return 1;
}
//---------------------------------------------------------------------------
int __fastcall TMyPackage::Myfunction2(lua_State L)
{
    // Push a return value
    lua_pushinteger(L, 174);
    return 1;
}
//---------------------------------------------------------------------------
void __fastcall TMyPackage::PackageReg(lua_State L)
{
    // Register Lua package "MyPackage" with the TMyPackage package loader procedure
    TVerySimpleLua::RegisterPackage(L, "MyPackage", this, "LoadPackage");
}
//---------------------------------------------------------------------------
