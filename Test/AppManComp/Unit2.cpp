//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm2 *Form2;

//---------------------------------------------------------------------------

__fastcall TForm2::TForm2(TComponent* Owner)
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
