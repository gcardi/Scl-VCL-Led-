//---------------------------------------------------------------------------

#ifndef LedH
#define LedH

#include <System.hpp>

#include <vector>

#include "VclGdiplus.h"

namespace SclLedCtrl {

class GdiPlusSessionManager {
public:
    GdiPlusSessionManager();
    ~GdiPlusSessionManager();
private:
    GdiPlusSessionManager( GdiPlusSessionManager const & );
    GdiPlusSessionManager& operator =( GdiPlusSessionManager const & );
    Gdiplus::GdiplusStartupInput gdiplusStartupInput_;
    ULONG_PTR gdiplusToken_;
};

class Led {
public:
    Led( float Size );
    long GetIntensity() const;
    void SetIntensity( long Val );
    void Draw( Gdiplus::Graphics& Canvas,
               Gdiplus::Color Color,
               Gdiplus::PointF Offset = Gdiplus::PointF(),
               Gdiplus::Color RingColor = Gdiplus::Color( 255, 8, 8, 8 ),
               float RingSize = 2.0F ) const;
    float GetSize() const { return size_; }
private:
    typedef  std::vector<Gdiplus::PointF>  GlowCurvePointCont;

    GdiPlusSessionManager gdiPlusSessionMngr_;
    float size_;
    GlowCurvePointCont glowCurvePoints_;
};

} // End of namespace SclLedCtrl

//---------------------------------------------------------------------------
#endif
