//---------------------------------------------------------------------------

#ifndef TabPageH
#define TabPageH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Menus.hpp>

// custom class
#include "FrameIpu.h"
#include "FrameConfigSetting.h"
//---------------------------------------------------------------------------
class TFormTabView : public TForm
{
__published:	// IDE-managed Components
	TPageControl *m_pageControl;
	TTabSheet *m_tabRemote;
	TFrame_ConfigSetting *Frame_ConfigSetting;
private:	// User declarations
public:		// User declarations
	__fastcall TFormTabView(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormTabView *FormTabView;
//---------------------------------------------------------------------------
#endif
