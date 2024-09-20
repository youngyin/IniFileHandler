//---------------------------------------------------------------------------

#ifndef FrameRemoteH
#define FrameRemoteH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
#include <vector>

// custom class
#include "src\data\IpuConfig.h"

class TFrame_ConfigSetting : public TFrame
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox4;
	TGroupBox *GroupBox5;
	TGroupBox *GroupBox6;
	TGroupBox *GroupBox2;
	TGroupBox *GroupBox1;
	TButton *m_btnIpuFileLoad;
	TButton *m_btnIpuFileSave;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TGroupBox *GroupBox7;
	TGroupBox *GroupBox8;
	TGroupBox *GroupBox3;
	TStaticText *StaticText1;
	TStaticText *StaticText2;
	TStaticText *StaticText3;
	TEdit *m_In_GateWayAddress;
	TEdit *m_In_SubNetAddress;
	TEdit *m_In_IPAddress;
	TStaticText *StaticText4;
	TEdit *m_Ex_IPAddress;
	TStaticText *StaticText5;
	TEdit *m_Ex_SubNetAddress;
	TStaticText *StaticText6;
	TEdit *m_Ex_GateWayAddress;
	TStaticText *StaticText7;
	TEdit *Edit7;
	TEdit *Edit8;
	TStaticText *StaticText8;
	TStaticText *StaticText9;
	TEdit *Edit9;
	TStaticText *StaticText10;
	TEdit *Edit10;
	TStaticText *StaticText11;
	TEdit *Edit11;
	TStaticText *StaticText12;
	TEdit *Edit12;
	TStaticText *StaticText13;
	TStaticText *StaticText14;
	TEdit *Edit13;
	TEdit *Edit14;
	TStaticText *StaticText15;
	TEdit *Edit15;
	TStaticText *StaticText16;
	TEdit *Edit16;
	TStaticText *StaticText17;
	TEdit *Edit17;
	TStaticText *StaticText18;
	TEdit *Edit18;
	TStaticText *StaticText19;
	TEdit *Edit19;
	TStaticText *StaticText20;
	TEdit *Edit20;
	TEdit *Edit21;
	TStaticText *StaticText21;
	TEdit *Edit22;
	TStaticText *StaticText22;
	TEdit *Edit23;
	TStaticText *StaticText23;
	TEdit *Edit24;
	TStaticText *StaticText24;
	TStaticText *StaticText25;
	TEdit *Edit25;
	void __fastcall m_btnIpuFileLoadClick(TObject *Sender);
	void __fastcall m_btnIpuFileSaveClick(TObject *Sender);
private:	// User declarations
	void loadValues(const String &strFilePath);
	void displayValues(const IpuConfig &configValues);
	String selectIniFile(TComponent* Owner);
	/** String Split*/
	std::vector<std::string> SplitString(const std::string& str, char delimiter);
	String m_strFilePath;
	void changeDataFromUI(IpuConfig &configValues);
	bool NetworkConfigChange(const std::string& adapterName, const std::string& ipAddress, const std::string& subnetMask, const std::string& gateway);
    bool ExecuteNetshCommand(const std::string& command);
public:		// User declarations
	__fastcall TFrame_ConfigSetting(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_ConfigSetting *Frame_ConfigSetting;
//---------------------------------------------------------------------------
#endif
