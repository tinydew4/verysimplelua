//---------------------------------------------------------------------------
#ifndef MyLuaH
#define MyLuaH
//---------------------------------------------------------------------------
#include "../../Source/VerySimple.Lua.hpp"
#include "../../Source/VerySimple.Lua.Lib.hpp"
//---------------------------------------------------------------------------
class DELPHICLASS TMyLua : public TVerySimpleLua
{
    typedef Verysimple::Lua::TVerySimpleLua inherited;

public:
    /* TVerySimpleLua.Create */ inline __fastcall virtual TMyLua(void) : inherited() {}
    /* TVerySimpleLua.Destroy */ inline __fastcall virtual ~TMyLua(void) {}

__published:
    // lua functions this published methods are automatically added
    // to the lua function table if called with TLua.Create(True) or Create()
    int HelloWorld(lua_State LuaState);
    __classmethod int __fastcall HelloWorld2(lua_State LuaState);
    static int __cdecl HelloWorld3(lua_State LuaState);

};
//---------------------------------------------------------------------------
#endif
