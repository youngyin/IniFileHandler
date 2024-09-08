//---------------------------------------------------------------------------

#ifndef TabPageH
#define TabPageH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include "First.h"
#include "Second.h"
//---------------------------------------------------------------------------
class TFormTabView : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TFrameFirst *FrameFirst1;
	TFrameSecond *FrameSecond1;
private:	// User declarations
public:		// User declarations
	__fastcall TFormTabView(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormTabView *FormTabView;
//---------------------------------------------------------------------------
#endif
