//---------------------------------------------------------------------------

#ifndef FirstH
#define FirstH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TFrameFirst : public TFrame
{
__published:	// IDE-managed Components
	TLabel *LblFirst;
private:	// User declarations
public:		// User declarations
	__fastcall TFrameFirst(TComponent* Owner);
    __fastcall TFrameFirst(TComponent* Owner, const String &strName);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrameFirst *FrameFirst;
//---------------------------------------------------------------------------
#endif
