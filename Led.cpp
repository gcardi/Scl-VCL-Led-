//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <memory>

#include "Led.h"

using std::unique_ptr;

//---------------------------------------------------------------------------

#pragma package(smart_init)

namespace SclLedCtrl {

//---------------------------------------------------------------------------

using Gdiplus::GdiplusStartup;
using Gdiplus::GdiplusShutdown;

GdiPlusSessionManager::GdiPlusSessionManager()
{
    GdiplusStartup( &gdiplusToken_, &gdiplusStartupInput_, NULL );
}
//---------------------------------------------------------------------------

GdiPlusSessionManager::~GdiPlusSessionManager() /* throw() */
{
    try {
        GdiplusShutdown( gdiplusToken_ );
    }
    catch ( ... ) {
    }
}

//---------------------------------------------------------------------------

Led::Led( float Size )
  : size_( Size )
{
    glowCurvePoints_.reserve( 13 );
    glowCurvePoints_.push_back( Gdiplus::PointF( size_ * 0.4274      , size_ * 0.428250455 ) );
    glowCurvePoints_.push_back( Gdiplus::PointF( size_ * 0.520608636 , size_ * 0.335055    ) );
    glowCurvePoints_.push_back( Gdiplus::PointF( size_ * 0.542190455 , size_ * 0.205563182 ) );
    glowCurvePoints_.push_back( Gdiplus::PointF( size_ * 0.475615    , size_ * 0.138987727 ) );
    glowCurvePoints_.push_back( Gdiplus::PointF( size_ * 0.409039545 , size_ * 0.072412273 ) );
    glowCurvePoints_.push_back( Gdiplus::PointF( size_ * 0.279547727 , size_ * 0.093994091 ) );
    glowCurvePoints_.push_back( Gdiplus::PointF( size_ * 0.186352273 , size_ * 0.187202727 ) );
    glowCurvePoints_.push_back( Gdiplus::PointF( size_ * 0.093144091 , size_ * 0.280398182 ) );
    glowCurvePoints_.push_back( Gdiplus::PointF( size_ * 0.071561818 , size_ * 0.409889545 ) );
    glowCurvePoints_.push_back( Gdiplus::PointF( size_ * 0.138137273 , size_ * 0.476465455 ) );
    glowCurvePoints_.push_back( Gdiplus::PointF( size_ * 0.204713182 , size_ * 0.543040909 ) );
    glowCurvePoints_.push_back( Gdiplus::PointF( size_ * 0.334204545 , size_ * 0.521458636 ) );
    glowCurvePoints_.push_back( Gdiplus::PointF( size_ * 0.4274      , size_ * 0.428250455 ) );
}
//---------------------------------------------------------------------------

void Led::Draw( Gdiplus::Graphics& Canvas, Gdiplus::Color Color,
                Gdiplus::PointF Offset, Gdiplus::Color RingColor,
                float RingSize ) const
{
    const float RingSize2 = RingSize * 2;

    Gdiplus::Bitmap Bmp( size_ + RingSize2, size_ + RingSize2 );

    unique_ptr<Gdiplus::Graphics> g( Gdiplus::Graphics::FromImage( &Bmp ) );
    g->SetSmoothingMode( Canvas.GetSmoothingMode() );

    Gdiplus::RectF Rect( 0, 0, size_, size_ );

    g->TranslateTransform( RingSize, RingSize );

    Gdiplus::SolidBrush const BkBrush( Gdiplus::Color::Black );
    Gdiplus::SolidBrush const ClBrush = Color;
    g->FillEllipse( &BkBrush, Rect );
    g->FillEllipse( &ClBrush, Rect );

    Gdiplus::GraphicsPath GlowBezierPath;
    GlowBezierPath.AddBeziers( &glowCurvePoints_[0], glowCurvePoints_.size() );

    Gdiplus::LinearGradientBrush GlowLinearGradientBrush(
       Gdiplus::PointF( size_ * 0.2, size_ * 0.2 ),
       Gdiplus::PointF( size_ * 0.45, size_ * 0.45 ),
       Gdiplus::Color( 255, 255, 255, 255 ),
       Gdiplus::Color(   0, 255, 255, 255 )
    );

    g->FillPath( &GlowLinearGradientBrush, &GlowBezierPath );
    Gdiplus::Pen const RingPen( RingColor, RingSize );
    g->DrawEllipse( &RingPen, Rect );

    Canvas.DrawImage( &Bmp, Offset.X, Offset.Y );
}
//---------------------------------------------------------------------------

} // End of namespace SclLedCtrl

