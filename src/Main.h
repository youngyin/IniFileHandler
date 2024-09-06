//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
	TButton *BtnSave;
	TEdit *EdtFolderPath;
	TButton *BtnOpenFolderVcl;
	TButton *BtnRead;
	TMemo *MmResult;
	TEdit *EdtFilePath;
	TButton *BtnOpenFile;
	TLabel *LblStatus;
	void __fastcall btnSaveClick(TObject *Sender);
	void __fastcall btnOpenFolderVclClick(TObject *Sender);
	void __fastcall BtnOpenFileClick(TObject *Sender);
	void __fastcall BtnReadClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
    void FnsettingMmResult();
public:		// User declarations
	__fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
