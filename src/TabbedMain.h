//---------------------------------------------------------------------------

#ifndef TabbedMainH
#define TabbedMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TFormTabbed : public TForm
{
__published:	// IDE-managed Components
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
    void __fastcall TFormTabbed::InitComponet();
    void __fastcall fnChangeTab(TObject* Sender);
public:		// User declarations
	__fastcall TFormTabbed(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormTabbed *FormTabbed;
//---------------------------------------------------------------------------
#endif
