//---------------------------------------------------------------------------
#ifndef fSelectionImageH
#define fSelectionImageH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "Graphics/GraphicsBuffers.h"
//---------------------------------------------------------------------------
class TSelectionImageFrame : public TFrame
{
__published:// IDE-managed Components
    TImage *imgBitmap;
    void __fastcall imgBitmapClick(TObject *Sender);
private:	// User declarations
    const Agdx::GraphicsBuffer& m_Image;
    bool                m_Selected;
    int                 m_Scale;
    TNotifyEvent        FOnClick;

    void    __fastcall  SetSelected(bool state);
    void    __fastcall  SetScale(int scale);
public:		// User declarations
            __fastcall  TSelectionImageFrame(TComponent* Owner, const Agdx::GraphicsBuffer& image);

    void    __fastcall  Update();

    bool    __property  Selected = { read = m_Selected, write = SetSelected };
    int     __property  Scale = { read = m_Scale, write = SetScale };

            // click events
            __property  TNotifyEvent OnSelectedClick = { read = FOnClick, write = FOnClick };
};
//---------------------------------------------------------------------------
#endif
