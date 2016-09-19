//---------------------------------------------------------------------------
#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
#include <memory>
#include "../../Source/VerySimple.Lua.Lib.hpp"
#include "../../Source/VerySimple.Lua.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : inherited(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    std::unique_ptr<TVerySimpleLua> Lua(std::make_unique<TVerySimpleLua>());
    #if defined(__WIN32__)
    Lua->LibraryPath = String("../../DLL/WIN32/") + LUA_LIBRARY;
    #elif defined(_WIN64)
    Lua->LibraryPath = String("../../DLL/WIN64/") + LUA_LIBRARY;
    #endif

    Lua->OnPrint = OnPrint; // Redirect console output to memo
    Lua->DoFile("example3.lua");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OnPrint(String Msg)
{
    Memo1->Lines->Add(Msg);
    Memo1->GoToTextEnd();
}
//---------------------------------------------------------------------------

