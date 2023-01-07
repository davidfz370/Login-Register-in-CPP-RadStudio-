//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Main.h"
#include "RegistrationForm.h"
#include "LoginForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMyMainForm *MyMainForm;
//---------------------------------------------------------------------------
__fastcall TMyMainForm::TMyMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TMyMainForm::loginButtonClick(TObject *Sender)
{
   MyLoginForm ->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMyMainForm::registerButtonClick(TObject *Sender)
{
	MyRegistrationForm->Show();
}
//---------------------------------------------------------------------------

