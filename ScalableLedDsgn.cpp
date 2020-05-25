//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop
#pragma package(smart_init)

#include "LedControl.h"

//---------------------------------------------------------------------------
//   Package source.
//---------------------------------------------------------------------------

#pragma argsused

extern "C" int _libmain(unsigned long reason)
{
    return 1;
}

//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//
//---------------------------------------------------------------------------

static inline void ValidCtrCheck( TScalableLed * )
{
	new TScalableLed( NULL );
}
//---------------------------------------------------------------------------

namespace Scalableleddsgn
{
	void __fastcall PACKAGE Register()
	{
		TComponentClass classes[1] = { __classid( TScalableLed ) };
		RegisterComponents( _T( "Samples" ), classes, 0 );
	}
}
//---------------------------------------------------------------------------


