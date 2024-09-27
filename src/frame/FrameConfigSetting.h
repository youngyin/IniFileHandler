//---------------------------------------------------------------------------

#ifndef FrameConfigSettingH
#define FrameConfigSettingH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Mask.hpp>
//---------------------------------------------------------------------------
#include <vector>

// custom class
#include "src\data\IpuConfig.h"
#include "src\data\LaneConfig.h"
#include "src\data\FtpConfig.h"
#include "src\data\RemoteConfig.h"



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
	COMU,
	CAMERA,
	ETC
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
	TButton *m_btnRemoteFiledLoad;
	TButton *m_btnRemoteFiledSave;
	TButton *m_btnFtpFiledSave;
	TButton *m_btnFtpFiledLoad;
	TGroupBox *GroupBox7;
	TGroupBox *GroupBox8;
	TGroupBox *GroupBox3;
	TStaticText *StaticText1;
	TStaticText *StaticText2;
	TStaticText *StaticText3;
	TStaticText *StaticText4;
	TStaticText *StaticText5;
	TStaticText *StaticText6;
	TStaticText *StaticText7;
	TEdit *m_EditImgServerPort;
	TStaticText *StaticText8;
	TStaticText *StaticText9;
	TStaticText *StaticText10;
	TEdit *m_EditMCPort;
	TStaticText *StaticText11;
	TStaticText *StaticText12;
	TEdit *m_EditRemoteServerPort;
	TStaticText *StaticText13;
	TStaticText *StaticText14;
	TEdit *m_EditFtpServerPort;
	TStaticText *StaticText15;
	TEdit *m_EditFtpLoginID;
	TStaticText *StaticText16;
	TEdit *m_EditFtpLoginPW;
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
	TMaskEdit *m_In_MaskEdit_IPAddress;
	TMaskEdit *m_In_MaskEdit_SubNetAddress;
	TMaskEdit *m_In_MaskEdit_GateWayAddress;
	TMaskEdit *m_Ex_MaskEdit_IPAddress;
	TMaskEdit *m_Ex_MaskEdit_SubNetAddress;
	TMaskEdit *m_Ex_MaskEdit_GateWayAddress;
	TMaskEdit *m_MaskEditFtpServerAddress;
	TMaskEdit *m_MaskEditRemoteServerAddress;
	TMaskEdit *m_MaskEditImgServerIP;
	TMaskEdit *m_MaskEditMCServerIP;
	TLabel *m_Label_OneIPUSelectExpaln;
	TLabel *m_Label_InNetChgExplan;
	TLabel *m_Label_ExNetChgExplan;
	void __fastcall m_btnIpuFileLoadClick(TObject *Sender);
	void __fastcall m_btnIpuFileSaveClick(TObject *Sender);
	void __fastcall m_btnLaneFileLoadClick(TObject *Sender);
	void __fastcall m_btnLaneFileSaveClick(TObject *Sender);
	void __fastcall m_btnFtpFiledLoadClick(TObject *Sender);
	void __fastcall m_btnFtpFiledSaveClick(TObject *Sender);
	void __fastcall m_btnRemoteFiledSaveClick(TObject *Sender);
	void __fastcall m_btnRemoteFiledLoadClick(TObject *Sender);
	void __fastcall m_cbOpTypeChange(TObject *Sender);
	void __fastcall m_EditFtpServerPortKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall m_EditFtpLoginPWKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall m_EditRemoteServerPortKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall m_EditImgServerPortKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall m_EditMCPortKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall m_cbOneipuChange(TObject *Sender);
	void __fastcall m_Ex_MaskEdit_IPAddressKeyPress(TObject *Sender, System::WideChar &Key);
	bool __fastcall IsValidIP(const AnsiString &ip);

private:	// User declarations
	void loadValues(const String &strFilePath, const FileUnitType nSelectType);
	void displayValues_IPU(const IpuConfig &configValues);
	void displayValues_LANE(const LaneConfig &configValues);
	void displayValues_FTP(const FtpConfig &configValues);
	void displayValues_REMOTE(const RemoteConfig &configValues);

	void InitComboBox();
	void InitComboBoxStyle();
	void InitEdit();
	void InitLoadConfigData();
	void InitMaskEdit();

	String selectIniFile(TComponent* Owner);
	/** String Split*/
	std::vector<std::string> SplitString(const std::string& str, char delimiter);

	void changeDataFromUI(IpuConfig &configValues);
	void changeDataFromUI(LaneConfig &configValues);
	void changeDataFromUI(FtpConfig &configValues);
	void changeDataFromUI(RemoteConfig &configValues);

	bool NetworkConfigChange(const std::string& adapterName, const std::string& ipAddress, const std::string& subnetMask, const std::string& gateway);
	bool ExecuteNetshCommand(const std::string& command);
	Variant ChangeValue_RealToShow(const String strValue, const SectionUnitType Unit);
	Variant ChangeValue_ShowToReal(const String strValue, const SectionUnitType Unit);

	String m_strFilePath;
	String GetFinalFilePath() { return m_strFilePath; }
    String RemoveSpacesFromIP(const String &ip);
	void SetFinalFilePath(String strFilePath) { m_strFilePath = strFilePath; }
	bool IsValidIP(const String &ip);
public:		// User declarations
	__fastcall TFrame_ConfigSetting(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_ConfigSetting *Frame_ConfigSetting;
//---------------------------------------------------------------------------
#endif
