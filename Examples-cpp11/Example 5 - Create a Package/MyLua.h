//---------------------------------------------------------------------------
#ifndef MyLuaH
#define MyLuaH
//---------------------------------------------------------------------------
#include <memory>
#include "../../Source/VerySimple.Lua.Lib.hpp"
#include "../../Source/VerySimple.Lua.hpp"
#include "MyPackage.h"
#include "MyPackage2.h"
//---------------------------------------------------------------------------
class TMyLua : public TVerySimpleLua
{
    typedef Verysimple::Lua::TVerySimpleLua inherited;

private:
    std::unique_ptr<TMyPackage> MyPackage;
    std::unique_ptr<TMyPackage2> MyPackage2;

public:
    __fastcall TMyLua(void);
    __fastcall virtual ~TMyLua(void);

    virtual void __fastcall Open(void);

};
//---------------------------------------------------------------------------
#endif
