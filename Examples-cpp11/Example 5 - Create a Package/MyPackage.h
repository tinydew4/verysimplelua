//---------------------------------------------------------------------------
#ifndef MyPackageH
#define MyPackageH
//---------------------------------------------------------------------------
#include "../../Source/VerySimple.Lua.Lib.hpp"
#include "../../Source/VerySimple.Lua.hpp"
//---------------------------------------------------------------------------
class TMyPackage : public TPersistent
{
public:
    int __fastcall LoadPackage(lua_State L);
    void __fastcall PackageReg(lua_State L);

__published:
    int __fastcall Myfunction1(lua_State L);
    int __fastcall Myfunction2(lua_State L);

};
//---------------------------------------------------------------------------
#endif
