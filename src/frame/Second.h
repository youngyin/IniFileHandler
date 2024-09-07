//---------------------------------------------------------------------------

#ifndef SecondH
#define SecondH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TFrameSecond : public TFrame
{
__published:	// IDE-managed Components
	TLabel *LblSecond;
private:	// User declarations
public:		// User declarations
	__fastcall TFrameSecond(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrameSecond *FrameSecond;
//---------------------------------------------------------------------------
#endif
