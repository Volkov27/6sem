//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "lab4_2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
ADOQuery1->Close();
ADOQuery1->SQL->Clear();
ADOQuery1->SQL->Add("select * from test1 where val=:param1");
ADOQuery1->Parameters->ParamByName("param1")->Value = Edit1->Text;
ADOQuery1->Open();
AnsiString str = ADOQuery1->FieldByName("id")->AsString;
Label1->Caption = str;
}
