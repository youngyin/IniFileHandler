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
#include <Vcl.Mask.hpp>

// custom class
#include "src\util\INIFileManager.h"

//---------------------------------------------------------------------------
class TFrameIpuNet : public TFrame
{
  __published: // IDE-managed Components
    TGroupBox* m_gbConfig;
    TGroupBox* m_gbSlotA;
	TLabeledEdit *m_edtDefaultSlot;
	TLabeledEdit *m_edtLastset;
	TLabeledEdit *m_edtLastSlot;
	TLabeledEdit *m_edtInterfaceIn;
	TLabeledEdit *m_edtIpIn;
	TLabeledEdit *m_edtInterfaceOut;
	TLabeledEdit *m_edtIpOut;
	TLabeledEdit *m_edtInterfaceCam1;
	TLabeledEdit *m_edtIpCam1;
	TButton *m_btnApply;
	TButton *btnFind;
	TLabeledEdit *m_edtPath;
	TButton *m_btnLoad;
	void __fastcall btnFindClick(TObject *Sender);
	void __fastcall m_btnLoadClick(TObject *Sender);

  private: // User declarations
	void __fastcall loadFileValue(String strFilePath);
	void __fastcall initDialog();
    String selectIniFile(TComponent* Owner);

  public: // User declarations
    __fastcall TFrameIpuNet(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrameIpuNet* FrameIpuNet;
//---------------------------------------------------------------------------
#endif

