//---------------------------------------------------------------------------

#pragma hdrstop

#include <algorithm>

#include "LedControl.h"
#include "VclGdiplus.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
#if defined( SCLLEDCTRL_USE_NAMESPACE )
namespace Vcl {
namespace SclLedCtrl {
#endif
//---------------------------------------------------------------------------

Gdiplus::Color TColorToGdiplusColor( TColor Val, BYTE Alpha = 0xFF )
{
    int const Cl = ColorToRGB( Val );
    return Gdiplus::Color(
        Alpha, Cl & 0xFF, ( Cl >> 8 ) & 0xFF, ( Cl >> 16 ) & 0xFF
    );
}
//---------------------------------------------------------------------------

__fastcall TCustomScalableLed::TCustomScalableLed(TComponent* Owner)
  : inherited( Owner )
  , state_( true )
  , trueColor_( clLime )
  , falseColor_( TColor( 0x181818 ) )
  , ringColor_( TColor( 0x101010 ) )
  , ringSizePercent_( 5.0F )
{
}
//---------------------------------------------------------------------------

bool __fastcall TCustomScalableLed::GetState() const
{
    return state_;
}
//---------------------------------------------------------------------------

void __fastcall TCustomScalableLed::SetState( bool Val )
{
    if ( Val != state_ ) {
        state_ = Val;
        Invalidate();
    }
}
//---------------------------------------------------------------------------

void __fastcall TCustomScalableLed::SetTrueColor( TColor Val )
{
    if ( Val != trueColor_ ) {
        trueColor_ = Val;
        Invalidate();
    }
}
//---------------------------------------------------------------------------

void __fastcall TCustomScalableLed::SetFalseColor( TColor Val )
{
    if ( Val != falseColor_ ) {
        falseColor_ = Val;
        Invalidate();
    }
}
//---------------------------------------------------------------------------

void __fastcall TCustomScalableLed::SetRingColor( TColor Val )
{
    if ( Val != ringColor_ ) {
        ringColor_ = Val;
        Invalidate();
    }
}
//---------------------------------------------------------------------------

void __fastcall TCustomScalableLed::SetRingSizePercent( float Val )
{
    if ( Val != ringSizePercent_ ) {
        ringSizePercent_ = Val;
        Invalidate();
    }
}
//---------------------------------------------------------------------------

float TCustomScalableLed::GetRingSize()
{
    return GetLedSize( ClientWidth, ClientHeight ) * ringSizePercent_ * 0.02F;
}
//---------------------------------------------------------------------------

void __fastcall TCustomScalableLed::Paint( void )
{
    if ( led_ ) {
        Gdiplus::Graphics g( Canvas->Handle );
        g.SetSmoothingMode( Gdiplus::SmoothingModeAntiAlias );
        led_->Draw(
            g,
            TColorToGdiplusColor( state_ ? trueColor_ : falseColor_ ),
            Gdiplus::PointF( 0.0F, 0.0F ),
            TColorToGdiplusColor( ringColor_ ),
            GetRingSize()
        );
    }
    else {
        CreateLed( Width, Height );
        Paint();
    }
}
//---------------------------------------------------------------------------

int TCustomScalableLed::GetLedSize( int AWidth, int AHeight ) const
{
    return std::min( AWidth, AHeight );
}
//---------------------------------------------------------------------------

void TCustomScalableLed::CreateLed( int AWidth, int AHeight )
{
    std::unique_ptr<SclLedCtrl::Led> Led(
        new SclLedCtrl::Led(
            GetLedSize( AWidth, AHeight ) - 2.0F * GetRingSize()
        )
    );
    led_.swap( Led );
}
//---------------------------------------------------------------------------

void __fastcall TCustomScalableLed::Resize()
{
    CreateLed( ClientWidth, ClientHeight );
}
//---------------------------------------------------------------------------

void __fastcall TCustomScalableLed::SetBounds( int ALeft, int ATop,
                                               int AWidth, int AHeight )
{
    inherited::SetBounds( ALeft, ATop, AWidth, AHeight );
    CreateLed( ClientWidth, ClientHeight );
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TScalableLed::TScalableLed(TComponent* Owner)
  : inherited( Owner )
{
}
//---------------------------------------------------------------------------

#if defined( SCLLEDCTRL_USE_NAMESPACE )
} /* End of namespace SclLedCtrl */
} /* End of namespace Vcl */
#endif

