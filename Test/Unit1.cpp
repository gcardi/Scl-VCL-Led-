//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    led_.reset( new TScalableLed( NULL ) );
    led_->Parent = this;
    led_->Left = 40;
    led_->Top = 32;
    led_->Width = 33;
    led_->Height = 33;
    led_->Anchors = TAnchors() << akLeft << akTop << akRight << akBottom;
    led_->ControlStyle = led_->ControlStyle << csOpaque;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
    led_->State = CheckBox1->Checked;
}
//---------------------------------------------------------------------------

