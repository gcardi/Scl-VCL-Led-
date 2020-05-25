//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>

#include <memory>

#include "LedControl.h"

#pragma comment( lib, "ScalableLedRun" )

//---------------------------------------------------------------------------

class TForm2 : public TForm
{
__published:	// IDE-managed Components
private:	// User declarations
        std::unique_ptr<TScalableLed> led_;
public:		// User declarations
    __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif


