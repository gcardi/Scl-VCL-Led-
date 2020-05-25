//---------------------------------------------------------------------------

#ifndef LedControlH
#define LedControlH

#include <Vcl.Controls.hpp>

#include <memory>

#include "Led.h"

//---------------------------------------------------------------------------
#if defined( SCLLEDCTRL_USE_NAMESPACE )
namespace Vcl {
namespace SclLedCtrl {
#endif
//---------------------------------------------------------------------------

class PACKAGE TCustomScalableLed : public Vcl::Controls::TGraphicControl
{
private:
	typedef Vcl::Controls::TGraphicControl inherited;

    std::unique_ptr<SclLedCtrl::Led> led_;
    bool state_;
    TColor trueColor_;
    TColor falseColor_;
    TColor ringColor_;
    //float size_;
    float ringSizePercent_;

    bool __fastcall GetState() const;;
    void __fastcall SetState( bool Val );
    void __fastcall SetTrueColor( TColor Val );
    void __fastcall SetFalseColor( TColor Val );
    void __fastcall SetRingColor( TColor Val );
    void __fastcall SetRingSizePercent( float Val );
    float GetRingSize();
    int GetLedSize( int AWidth, int AHeight ) const;
    void CreateLed( int AWidth, int AHeight );
protected:
    virtual void __fastcall Paint( void );
	DYNAMIC void __fastcall Resize();

    __property bool State = { read = GetState, write = SetState };
    __property TColor TrueColor = { read = trueColor_, write = SetTrueColor };
    __property TColor FalseColor = { read = falseColor_, write = SetFalseColor };
    __property TColor RingColor = { read = ringColor_, write = SetRingColor };
    __property float RingSizePercent = { read = ringSizePercent_, write = SetRingSizePercent };
public:
    __fastcall TCustomScalableLed(TComponent* Owner);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
};

class PACKAGE TScalableLed : public TCustomScalableLed
{
private:
    typedef  TCustomScalableLed  inherited;
protected:
public:
    __fastcall TScalableLed(TComponent* Owner);
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property Color = {default=-16777211};
	__property Constraints;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnGesture;
	__property OnMouseActivate;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
	__property OnStartDrag;
	__property ParentColor = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ShowHint;
	__property Touch;
	__property Visible = {default=1};
    __property FalseColor = {default=1579032};
    __property RingColor = {default=1052688};
    __property RingSizePercent = {default=5};
    __property State = {default=1};
    __property TrueColor = {default=65280};
};

#if defined( SCLLEDCTRL_USE_NAMESPACE )
} /* End of namespace SclLedCtrl */
} /* End of namespace Vcl */
#endif

//---------------------------------------------------------------------------
#endif
