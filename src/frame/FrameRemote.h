//---------------------------------------------------------------------------

#ifndef FrameRemoteH
#define FrameRemoteH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TFrameForRemote : public TFrame
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
	__fastcall TFrameForRemote(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrameForRemote *FrameForRemote;
//---------------------------------------------------------------------------
#endif
