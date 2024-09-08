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
#include <Vcl.Samples.Spin.hpp>

//전영인 클라스
#include "scheduler/TFileMoverThread.h"
#include "scheduler/TLogThread.h"
#include "ThreadTest.h"

//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
	TButton *BtnSave;
	TEdit *EdtFolderPath;
	TButton *BtnOpenFolderVcl;
	TButton *BtnRead;
	TMemo *MmResult;
    TMemo *MmResultMove;
	TEdit *EdtFilePath;
	TButton *BtnOpenFile;
	TLabel *LblStatus;
	TSpinEdit *SpinEditInterval;
	TButton *BtnStopMoveThread;
	TButton *BtnResumeMoveThread;
	TFrameForThread *FrameForThread1;
	void __fastcall btnSaveClick(TObject *Sender);
	void __fastcall btnOpenFolderVclClick(TObject *Sender);
	void __fastcall BtnOpenFileClick(TObject *Sender);
	void __fastcall BtnReadClick(TObject *Sender);
	void __fastcall BtnResumeMoveThreadClick(TObject *Sender);
	void __fastcall BtnStopMoveThreadClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
	void initStyleComponet();
	void initThread();
public:		// User declarations
	__fastcall TFormMain(TComponent* Owner);
protected:
	TLogThread *m_logThread;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
