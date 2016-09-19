//---------------------------------------------------------------------------
#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
#include <memory>
#include "MyLua.h"
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
    std::unique_ptr<TMyLua> Lua(std::make_unique<TMyLua>());
    Lua->OnPrint = OnPrint; // Redirect console output to memo
    Lua->DoFile("example4.lua");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OnPrint(String Msg)
{
    Memo1->Lines->Add(Msg);
    Memo1->GoToTextEnd();
}
//---------------------------------------------------------------------------

