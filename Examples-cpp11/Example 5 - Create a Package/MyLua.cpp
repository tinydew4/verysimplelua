//---------------------------------------------------------------------------
#pragma hdrstop

#include "MyLua.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TMyLua::TMyLua(void)
    : inherited()
    , MyPackage(std::make_unique<TMyPackage>())
    , MyPackage2(std::make_unique<TMyPackage2>())
{
    LibraryPath = String("../../DLL/Win32/") + LUA_LIBRARY;
}
//---------------------------------------------------------------------------
__fastcall TMyLua::~TMyLua(void)
{
}
//---------------------------------------------------------------------------
void __fastcall TMyLua::Open(void)
{
    // We're regstering two packages: one called "MyPackage"
    MyPackage->PackageReg(LuaState); // call our own package register function

    // and create a second package and auto register those package functions
    RegisterPackage("MyPackage2", MyPackage2.get());
}
//---------------------------------------------------------------------------
