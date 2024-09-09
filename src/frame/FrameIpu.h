//---------------------------------------------------------------------------

#ifndef FrameIpuH
#define FrameIpuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ValEdit.hpp>
#include <System.IniFiles.hpp>

#include "src\dialog\Setting.h"

//---------------------------------------------------------------------------
class TFrameIpuNet : public TFrame
{
  __published: // IDE-managed Components
    TGroupBox* m_gbConfig;
    TGroupBox* m_gbSlotA;
	TGridPanel *m_gpSlotA;
    TLabel* m_lblKey4;
    TEdit* m_edtInterfaceIn;
    TLabel* m_lblKey5;
    TEdit* m_edtIpIn;
    TLabel* m_lblKey6;
    TEdit* m_edtInterfaceOut;
	TLabel *m_lblKey7;
    TEdit* m_edtIpOut;
	TLabel *m_lblKey8;
    TEdit* m_edtInterfaceCam1;
	TLabel *m_lblKey9;
    TEdit* m_edtIpCam1;
	TGridPanel *m_gpConfig;
	TLabel *m_lblKey1;
	TEdit *m_edtDefaultSlot;
	TLabel *m_lblKey2;
	TEdit *m_edtLastset;
	TLabel *m_lblKey3;
	TEdit *m_edtLastSlot;
	TButton *m_BtnApply;
	void __fastcall m_BtnApplyClick(TObject *Sender);
  private: // User declarations
  	//TOKRightDlg *settingDialog;
	void __fastcall loadFileValue();
    void __fastcall initDialog();
  public: // User declarations
    __fastcall TFrameIpuNet(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrameIpuNet* FrameIpuNet;
//---------------------------------------------------------------------------
#endif

