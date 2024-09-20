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
#include <Vcl.Mask.hpp>

// custom class
#include "src\data\IpuConfig.h"

//---------------------------------------------------------------------------
class TFrame_IpuNet : public TFrame
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
	TButton *m_btnFind;
	TLabeledEdit *m_edtPath;
	TButton *m_btnLoad;
	TGroupBox *m_gbNetWorkInfo;
	TLabeledEdit *m_edtNetWorkInfo1;
	TLabeledEdit *m_edtNetWorkInfo2;
	TLabeledEdit *m_edtNetWorkInfo3;
	TLabeledEdit *m_edtNetWorkInfo5;
	TLabeledEdit *m_edtNetWorkInfo6;
	TLabeledEdit *m_edtNetWorkInfo4;
	TMemo *Memo1;
	TMemo *Memo2;
	void __fastcall m_btnFindClick(TObject *Sender);
	void __fastcall m_btnLoadClick(TObject *Sender);
	void __fastcall m_btnApplyClick(TObject *Sender);

  private: // User declarations
	void displayValues(const IpuConfig &configValues);
	void readFileValues(String strFilePath, IpuConfig &configValues);
	void __fastcall writeData(String strFilePath, IpuConfig &configValues);
	void changeDataFromUI(IpuConfig &configValues);
	void GetNetworkAdapters();
	void GetNetworkAdapters(String strAdapterName);
	String selectIniFile(TComponent* Owner);
	void loadValues();
	void getNetworkAdapter2();
	void GetSubnetMask();
	void SetIPAddress(const String& adapterName, const String& ipAddress, const String& subnetMask);
	void SetIPAddress(const std::string& adapterName, const std::string& ipAddress, const std::string& subnetMask);
	DWORD GetAdapterIndexByName(const std::string& adapterName);
	DWORD ChangeGateway(const std::string& gatewayAddress, const DWORD interfaceIndex);
	bool NetworkConfigChange(const std::string& adapterName);
	bool ExecuteNetshCommand(const std::string& command);

  public: // User declarations

	__fastcall TFrame_IpuNet(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_IpuNet* Frame_IpuNet;
//---------------------------------------------------------------------------
#endif

