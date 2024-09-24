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
#include "src\data\LaneConfig.h"

enum class FileUnitType{
	IPU,
	LANE,
	REMOTE,
    FTP
};

enum class SectionUnitType{
	DATA,
	OPTYPE,
	SYSTEMTYPE,
	POSITION,
	TRIGGERTYPE,
	COMU
};


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
	TButton *m_btnLaneFileLoad;
	TButton *m_btnLaneFileSave;
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
	TEdit *m_EditImgServerIP;
	TEdit *m_EditImgServerPort;
	TStaticText *StaticText8;
	TStaticText *StaticText9;
	TEdit *m_EditMCServerIP;
	TStaticText *StaticText10;
	TEdit *m_EditMCPort;
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
	TEdit *m_EditOneIPU;
	TStaticText *StaticText18;
	TEdit *m_EditAxisWeight;
	TStaticText *StaticText19;
	TEdit *m_EditOpType;
	TStaticText *StaticText20;
	TEdit *m_EditSystemType;
	TEdit *m_EditComPort;
	TStaticText *StaticText21;
	TEdit *m_EditComType;
	TStaticText *StaticText22;
	TEdit *m_EditTriggerType;
	TStaticText *StaticText23;
	TEdit *m_EditPosition;
	TStaticText *StaticText24;
	TStaticText *StaticText25;
	TEdit *m_EditComBaudRate;
	TComboBox *m_cbOneipu;
	TComboBox *m_cbAxisWeight;
	TComboBox *m_cbOpType;
	TComboBox *m_cbSystemType;
	TComboBox *m_cbPosition;
	TComboBox *m_cbTriggerType;
	TComboBox *m_cbComType;
	TComboBox *m_cbPort;
	TComboBox *m_cbBaudRate;
	void __fastcall m_btnIpuFileLoadClick(TObject *Sender);
	void __fastcall m_btnIpuFileSaveClick(TObject *Sender);
	void __fastcall m_btnLaneFileLoadClick(TObject *Sender);
	void __fastcall m_btnLaneFileSaveClick(TObject *Sender);
private:	// User declarations
	void loadValues(const String &strFilePath, const FileUnitType nSelectType);
	void displayValues_IPU(const IpuConfig &configValues);
	void displayValues_LANE(const LaneConfig &configValues);
	void InitComboBox();
	String selectIniFile(TComponent* Owner);
	/** String Split*/
	std::vector<std::string> SplitString(const std::string& str, char delimiter);
	String m_strFilePath;
	void changeDataFromUI(IpuConfig &configValues);
	void changeDataFromUI_LANE(LaneConfig &configValues);
	bool NetworkConfigChange(const std::string& adapterName, const std::string& ipAddress, const std::string& subnetMask, const std::string& gateway);
	bool ExecuteNetshCommand(const std::string& command);

	Variant ChangeValue_RealToShow(const String strValue, const SectionUnitType Unit);
	Variant ChangeValue_ShowToReal(const String strValue, const SectionUnitType Unit);
public:		// User declarations
	__fastcall TFrame_ConfigSetting(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_ConfigSetting *Frame_ConfigSetting;
//---------------------------------------------------------------------------
#endif
