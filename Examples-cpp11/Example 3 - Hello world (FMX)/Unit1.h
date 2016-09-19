//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
    typedef TForm inherited;

__published:	// IDE-managed Components
    TMemo *Memo1;
    TButton *Button1;
    void __fastcall Button1Click(TObject *Sender);

private:	// User declarations
    void __fastcall OnPrint(String Msg);

public:		// User declarations
    __fastcall TForm1(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
