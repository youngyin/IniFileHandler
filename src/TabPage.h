//---------------------------------------------------------------------------

#ifndef TabPageH
#define TabPageH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include "FrameIpu.h"
#include <Vcl.Menus.hpp>
#include "FrameRemote.h"
//---------------------------------------------------------------------------
class TFormTabView : public TForm
{
__published:	// IDE-managed Components
	TPageControl *m_pageControl;
	TTabSheet *m_tabIpu;
	TTabSheet *m_tabRemote;
	TFrameIpuNet *FrameIpuNet1;
	TMainMenu *m_mainMenu;
	TMenuItem *Setting1;
	TMenuItem *N1;
	TFrameForRemote *m_frameForRemote;
	void __fastcall N1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormTabView(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormTabView *FormTabView;
//---------------------------------------------------------------------------
#endif
