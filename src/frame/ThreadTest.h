//---------------------------------------------------------------------------

#ifndef ThreadTestH
#define ThreadTestH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------

// custom thread
#include "src\scheduler\CustomThread.h"
#include <Vcl.Samples.Spin.hpp>

class TFrameForThread : public TFrame
{
__published:	// IDE-managed Components
	TGridPanel *GridPanel;
	TButton *m_btnStart;
	TButton *m_btnStop;
	TButton *m_btnStatus;
	TSpinEdit *m_spinEditSec;
	TLabel *Label3;
	void __fastcall m_btnStartClick(TObject *Sender);
	void __fastcall m_btnStopClick(TObject *Sender);
	void __fastcall m_btnStatusClick(TObject *Sender);
private:	// User declarations
	void LogExecution(const String& logFilePath);
    TCustomThread* m_customThread;
public:		// User declarations
	__fastcall TFrameForThread(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrameForThread *FrameForThread;
//---------------------------------------------------------------------------
#endif
