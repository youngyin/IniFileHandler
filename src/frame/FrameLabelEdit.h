//---------------------------------------------------------------------------

#ifndef FrameLabelEditH
#define FrameLabelEditH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFrameForLabelEdit : public TFrame
{
__published:	// IDE-managed Components
	TGridPanel *GridPanel1;
	TLabel *m_lblName;
	TEdit *m_edtValue;
private:	// User declarations
public:		// User declarations
	__fastcall TFrameForLabelEdit(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrameForLabelEdit *FrameForLabelEdit;
//---------------------------------------------------------------------------
#endif
