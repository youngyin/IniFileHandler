//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrameRemote.h"

#include <vcl.h>
#include <vector>
#include <string>
#include <sstream>
#include <System.RegularExpressions.hpp>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrame_ConfigSetting *Frame_ConfigSetting;
//---------------------------------------------------------------------------
__fastcall TFrame_ConfigSetting::TFrame_ConfigSetting(TComponent* Owner)
	: TFrame(Owner)
{
	InitComboBox();
    InitComboBoxStyle();
	InitEdit();
	InitMaskEdit();
}

void TFrame_ConfigSetting::InitComboBox(){
	//확정영상
	m_cbOneipu->Items->Add("O");//0
	m_cbOneipu->Items->Add("X");//1

	//축중자료
	m_cbAxisWeight->Items->Add("O");//1
	m_cbAxisWeight->Items->Add("X");//0

	//인터페이스 설정
	m_cbOpType->Items->Add("Hipass 신형");//22
	m_cbOpType->Items->Add("Hipass 구형");//21
	m_cbOpType->Items->Add("TCS/무인정산기");//11
	m_cbOpType->Items->Add("TCS");//10
	m_cbOpType->Items->Add("UTC tcs");//15
	m_cbOpType->Items->Add("MINJA tcs");//18

	//차로타입
	m_cbSystemType->Items->Add("폐쇄식 출구");//"O"
	m_cbSystemType->Items->Add("폐쇄식 입구");//"I"
	m_cbSystemType->Items->Add("개방식 상행");//"U"
	m_cbSystemType->Items->Add("개방식 하행");//"D"

	//전/후면
	m_cbPosition->Items->Add("전면");//"FRONT"
	m_cbPosition->Items->Add("후면");//"REAR"

	//검지
	m_cbTriggerType->Items->Add("트리거 검지");//1
	m_cbTriggerType->Items->Add("동영상 검지");//99

	//통신방식
	m_cbComType->Items->Add("SERIAL");//"SERIAL"
	m_cbComType->Items->Add("TCP/IP");//"ETHERNET"

	//포트
	String strComName = "COM";
	for(int a = 0; a < 10; ++a)
	{
		String strInputData = strComName + String(a);
		m_cbPort->Items->Add(strInputData);//"COM1~10"
	}

	//BaudRate
	m_cbBaudRate->Items->Add("9600");//9600
	m_cbBaudRate->Items->Add("14400");//14400
	m_cbBaudRate->Items->Add("19200");//19200
	m_cbBaudRate->Items->Add("38400");//38400
	m_cbBaudRate->Items->Add("57600");//57600
	m_cbBaudRate->Items->Add("115200");//115200

	//재인식서버

    //주제어기서버
}

void TFrame_ConfigSetting::InitComboBoxStyle(){
	//확정영상
	m_cbOneipu->Style = csDropDownList;
	//축중자료
	m_cbAxisWeight->Style = csDropDownList;
	//인터페이스 설정
	m_cbOpType->Style = csDropDownList;
	//차로타입
	m_cbSystemType->Style = csDropDownList;
	//전/후면
	m_cbPosition->Style = csDropDownList;
	//검지
	m_cbTriggerType->Style = csDropDownList;
	//통신방식
	m_cbComType->Style = csDropDownList;
	//포트
	m_cbPort->Style = csDropDownList;
	//BaudRate
	m_cbBaudRate->Style = csDropDownList;
}

void TFrame_ConfigSetting::InitMaskEdit(){

}

void TFrame_ConfigSetting::InitEdit(){
	m_MaskEditMCServerIP->Enabled = FALSE;
	m_EditMCPort->Enabled = FALSE;
}

void TFrame_ConfigSetting::InitLoadConfigData(){

	String strFilePath;

	strFilePath = "D:\\SmartTolling\\Init\\LaneSetting.ini";
	if(!strFilePath.IsEmpty()) { loadValues(strFilePath, FileUnitType::LANE); }

	strFilePath = "D:\\SmartTolling\\Init\\IPU_netconfig.ini";
	if(!strFilePath.IsEmpty()) { loadValues(strFilePath, FileUnitType::IPU); }

	strFilePath = "D:\\SmartTolling\\SUpload\\FTPUpload.ini";
	if(!strFilePath.IsEmpty()) { loadValues(strFilePath, FileUnitType::FTP); }

	strFilePath = "D:\\SmartTolling\\Init\\REMOTESetting.ini";
	if(!strFilePath.IsEmpty()) { loadValues(strFilePath, FileUnitType::REMOTE); }
}

String TFrame_ConfigSetting::selectIniFile(TComponent* Owner){
	String strFilePath;
	TOpenDialog* OpenDialog = new TOpenDialog(Owner);
	OpenDialog->Filter = "INI Files (*.ini)|*.ini";
	OpenDialog->Title = "Open a File";

	if (OpenDialog->Execute()) {
		strFilePath = OpenDialog->FileName;
	}

	delete OpenDialog;
	OpenDialog = nullptr;

	return strFilePath;
}

//---------------------------------------------------------------------------
void TFrame_ConfigSetting::loadValues(const String &strFilePath, const FileUnitType nSelectType){
	IpuConfig Ipu_fileConfigData;
	LaneConfig Lane_fileConfigData;
	FtpConfig Ftp_fileConfigData;
    RemoteConfig Remote_fileConfigData;

	String strPath = strFilePath;

	switch(nSelectType)
	{
		case FileUnitType::IPU:
			Ipu_fileConfigData.readFileValues(strPath);
            displayValues_IPU(Ipu_fileConfigData);
			break;
		case FileUnitType::LANE:
			Lane_fileConfigData.readFileValues(strPath);
			displayValues_LANE(Lane_fileConfigData);
			break;
		case FileUnitType::REMOTE:
			Remote_fileConfigData.readFileValues(strPath);
			displayValues_REMOTE(Remote_fileConfigData);
			break;
		case FileUnitType::FTP:
			Ftp_fileConfigData.readFileValues(strPath);
			displayValues_FTP(Ftp_fileConfigData);
			break;
		default:
			break;
    }

	SetFinalFilePath(strFilePath);
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void TFrame_ConfigSetting::displayValues_IPU(const IpuConfig &configValues) {
	//configValues.defaultSlot.get();
	//configValues.lastSlot.get();
	//configValues.lastSet.get();
	//configValues.interfaceIn.get();
	//configValues.interfaceOut.get();
	//configValues.ipOut.get();
	//configValues.interfaceCam1.get();
	//configValues.ipCam1.get();

	configValues.ipIn.get();
	configValues.ipOut.get();

	std::vector<std::string> result_In = SplitString(AnsiString(configValues.ipIn.get()).c_str(), '/');

	int a = 0;
	String strInipAddress[3];
	for(const auto& part : result_In)
	{
		strInipAddress[a] = part.c_str();
		a++;
	}

	m_In_MaskEdit_IPAddress->Text = strInipAddress[0];
	m_In_MaskEdit_SubNetAddress->Text = strInipAddress[1];
	if(strInipAddress[2] != ""){ m_In_MaskEdit_GateWayAddress->Text = strInipAddress[2]; }

	std::vector<std::string> result_Ex = SplitString(AnsiString(configValues.ipOut.get()).c_str(), '/');

	int b = 0;
	String strExipAddress[3];
	for(const auto& part : result_Ex)
	{
		strExipAddress[b] = part.c_str();
		b++;
	}

	m_Ex_MaskEdit_IPAddress->Text = strExipAddress[0];
	m_Ex_MaskEdit_SubNetAddress->Text = strExipAddress[1];

	if(strExipAddress[2] != ""){ m_Ex_MaskEdit_GateWayAddress->Text = strExipAddress[2]; }
}

void TFrame_ConfigSetting::displayValues_LANE(const LaneConfig &configValues){
	//Real로 읽은 값을 Show 값으로 치환 후 Add된 것과 같은게 있으면 해당 부분을 CurSel한다.
	int nIndex = 0;
	String strValue;

	//SYSTEM
	m_EditOneIPU->Text = configValues.nOneipuOnly.get();
	nIndex = m_cbOneipu->Items->IndexOf(ChangeValue_RealToShow(IntToStr(configValues.nOneipuOnly.get()), SectionUnitType::DATA));
	m_cbOneipu->ItemIndex = nIndex;

	if(configValues.nOneipuOnly.get() == REAL_DATA_O)
	{
		m_Label_OneIPUSelectExpaln->Caption = SHOW_ONEIPUSELECT_STREXPLAN_O;
	}
	else if(configValues.nOneipuOnly.get() == REAL_DATA_X)
	{
		m_Label_OneIPUSelectExpaln->Caption = SHOW_ONEIPUSELECT_STREXPLAN_X;
	}

	m_EditAxisWeight->Text = configValues.nAxisWeight.get();
	nIndex = m_cbAxisWeight->Items->IndexOf(ChangeValue_RealToShow(IntToStr(configValues.nAxisWeight.get()), SectionUnitType::DATA));
	m_cbAxisWeight->ItemIndex = nIndex;

	m_EditOpType->Text = configValues.nOpType.get();
	nIndex = m_cbOpType->Items->IndexOf(ChangeValue_RealToShow(IntToStr(configValues.nOpType.get()), SectionUnitType::OPTYPE));
	m_cbOpType->ItemIndex = nIndex;

	m_EditSystemType->Text = configValues.strSystemType.get();
	nIndex = m_cbSystemType->Items->IndexOf(ChangeValue_RealToShow(configValues.strSystemType.get(), SectionUnitType::SYSTEMTYPE));
	m_cbSystemType->ItemIndex = nIndex;

	m_EditPosition->Text = configValues.strPostion.get();
	nIndex = m_cbPosition->Items->IndexOf(ChangeValue_RealToShow(configValues.strPostion.get(), SectionUnitType::POSITION));
	m_cbPosition->ItemIndex = nIndex;

	m_EditTriggerType->Text = configValues.nTriggerType.get();
	nIndex = m_cbTriggerType->Items->IndexOf(ChangeValue_RealToShow(IntToStr(configValues.nTriggerType.get()), SectionUnitType::TRIGGERTYPE));
	m_cbTriggerType->ItemIndex = nIndex;

	//HIPASS
	m_EditComType->Text = configValues.strComType.get();
	nIndex = m_cbComType->Items->IndexOf(ChangeValue_RealToShow(configValues.strComType.get(), SectionUnitType::COMU));
	m_cbComType->ItemIndex = nIndex;

	m_EditComPort->Text = configValues.strPort.get();
	nIndex = m_cbPort->Items->IndexOf(ChangeValue_RealToShow(configValues.strPort.get(), SectionUnitType::COMU));
	m_cbPort->ItemIndex = nIndex;

	m_EditComBaudRate->Text = configValues.nBaudRate.get();
	nIndex = m_cbBaudRate->Items->IndexOf(ChangeValue_RealToShow(IntToStr(configValues.nBaudRate.get()), SectionUnitType::COMU));
	m_cbBaudRate->ItemIndex = nIndex;

	//MIS(재인식서버)
	strValue = configValues.strImageServer.get();
	if(strValue != "readNotString" ) { m_MaskEditImgServerIP->Text = strValue; }
	m_EditImgServerPort->Text = IntToStr(configValues.nImagePort.get());

	//MIS(주제어기 서버)
	strValue = configValues.strMCImageServer.get();
	if(strValue != "readNotString" ) { m_MaskEditMCServerIP->Text = strValue; }
	m_EditMCPort->Text = IntToStr(configValues.nMCImagePort.get());

	//"TCS/무인정산기"인 경우만 주제어기 서버 Enabled 처리 그외는 Disabled
	if(m_EditOpType->Text == REAL_OPTYPE_11)
	{
		m_MaskEditMCServerIP->Enabled = TRUE;
		m_EditMCPort->Enabled = TRUE;
	}
	else
	{
		m_MaskEditMCServerIP->Enabled = FALSE;
        m_EditMCPort->Enabled = FALSE;
	}
}

void TFrame_ConfigSetting::displayValues_FTP(const FtpConfig &configValues){
	//CONFIG
	m_MaskEditFtpServerAddress->Text = configValues.ftpServerAddress.get();
	m_EditFtpServerPort->Text = configValues.ftpServerPort.get();
	m_EditFtpLoginID->Text = configValues.ftpLoginID.get();
	m_EditFtpLoginPW->Text = configValues.ftpLoginPW.get();
}

void TFrame_ConfigSetting::displayValues_REMOTE(const RemoteConfig &configValues){
	//CONFIG
	m_MaskEditRemoteServerAddress->Text = configValues.RemoteServerAddress.get();
	m_EditRemoteServerPort->Text = configValues.RemoteServerPort.get();
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
Variant TFrame_ConfigSetting::ChangeValue_RealToShow(const String strValue, const SectionUnitType Unit) {
	Variant strRetunValue = strValue;

	switch(Unit)
	{
		case SectionUnitType::DATA:
			if(strValue == REAL_DATA_O) { return strRetunValue = SHOW_DATA_O;}
			else if(strValue == REAL_DATA_X) { return strRetunValue = SHOW_DATA_X;}
			break;
		case SectionUnitType::OPTYPE:
			if(strValue == REAL_OPTYPE_22) { return strRetunValue = SHOW_OPTYPE_22;}
			else if(strValue == REAL_OPTYPE_21) { return strRetunValue = SHOW_OPTYPE_21;}
			else if(strValue == REAL_OPTYPE_11) { return strRetunValue = SHOW_OPTYPE_11;}
			else if(strValue == REAL_OPTYPE_10) { return strRetunValue = SHOW_OPTYPE_10;}
			else if(strValue == REAL_OPTYPE_15) { return strRetunValue = SHOW_OPTYPE_15;}
			else if(strValue == REAL_OPTYPE_18) { return strRetunValue = SHOW_OPTYPE_18;}
			break;
		case SectionUnitType::SYSTEMTYPE:
			if(strValue == REAL_SYSTEMTYPE_O) { return strRetunValue = SHOW_SYSTEMTYPE_O;}
			else if(strValue == REAL_SYSTEMTYPE_I) { return strRetunValue = SHOW_SYSTEMTYPE_I;}
			else if(strValue == REAL_SYSTEMTYPE_U) { return strRetunValue = SHOW_SYSTEMTYPE_U;}
			else if(strValue == REAL_SYSTEMTYPE_D) { return strRetunValue = SHOW_SYSTEMTYPE_D;}
			break;
		case SectionUnitType::TRIGGERTYPE:
			if(strValue == REAL_TRIGGERTYPE_1) { return strRetunValue = SHOW_TRIGGERTYPE_1;}
			else if(strValue == REAL_TRIGGERTYPE_99) { return strRetunValue = SHOW_TRIGGERTYPE_99;}
			break;
		case SectionUnitType::COMU:
			if(strValue == REAL_COMU_SERIAL) { return strRetunValue = SHOW_COMU_SERIAL;}
			else if(strValue == REAL_COMU_TCPIP) { return strRetunValue = SHOW_COMU_TCPIP;}
			break;
		case SectionUnitType::POSITION:
			if(strValue == REAL_POSITION_FRONT) { return strRetunValue = SHOW_POSITION_FRONT;}
			else if(strValue == REAL_POSITION_REAR) { return strRetunValue = SHOW_POSITION_REAR;}
			break;
		default:
            strRetunValue = "Not Exist";
            break;
	}

	return strRetunValue;
}

Variant TFrame_ConfigSetting::ChangeValue_ShowToReal(const String strValue, const SectionUnitType Unit) {
	Variant strRetunValue = strValue;

    if(strValue.IsEmpty()) { return "Emtpy"; }

	switch(Unit)
	{
		case SectionUnitType::DATA:
			if(strValue == SHOW_DATA_O) { return strRetunValue = REAL_DATA_O;}
			else if(strValue == SHOW_DATA_X) { return strRetunValue = REAL_DATA_X;}
			break;
		case SectionUnitType::OPTYPE:
			if(strValue == SHOW_OPTYPE_22) { return strRetunValue = REAL_OPTYPE_22;}
			else if(strValue == SHOW_OPTYPE_21) { return strRetunValue = REAL_OPTYPE_21;}
			else if(strValue == SHOW_OPTYPE_11) { return strRetunValue = REAL_OPTYPE_11;}
			else if(strValue == SHOW_OPTYPE_10) { return strRetunValue = REAL_OPTYPE_10;}
			else if(strValue == SHOW_OPTYPE_15) { return strRetunValue = REAL_OPTYPE_15;}
			else if(strValue == SHOW_OPTYPE_18) { return strRetunValue = REAL_OPTYPE_18;}
			break;
		case SectionUnitType::SYSTEMTYPE:
			if(strValue == SHOW_SYSTEMTYPE_O) { return strRetunValue = REAL_SYSTEMTYPE_O;}
			else if(strValue == SHOW_SYSTEMTYPE_I) { return strRetunValue = REAL_SYSTEMTYPE_I;}
			else if(strValue == SHOW_SYSTEMTYPE_U) { return strRetunValue = REAL_SYSTEMTYPE_U;}
			else if(strValue == SHOW_SYSTEMTYPE_D) { return strRetunValue = REAL_SYSTEMTYPE_D;}
			break;
		case SectionUnitType::TRIGGERTYPE:
			if(strValue == SHOW_TRIGGERTYPE_1) { return strRetunValue = REAL_TRIGGERTYPE_1;}
			else if(strValue == SHOW_TRIGGERTYPE_99) { return strRetunValue = REAL_TRIGGERTYPE_99;}
			break;
		case SectionUnitType::COMU:
			if(strValue == SHOW_COMU_SERIAL) { return strRetunValue = REAL_COMU_SERIAL;}
			else if(strValue == SHOW_COMU_TCPIP) { return strRetunValue = REAL_COMU_TCPIP;}
			break;
		case SectionUnitType::POSITION:
			if(strValue == SHOW_POSITION_FRONT) { return strRetunValue = REAL_POSITION_FRONT;}
			else if(strValue == SHOW_POSITION_REAR) { return strRetunValue = REAL_POSITION_REAR;}
			break;
		case SectionUnitType::CAMERA:
			if(strValue == SHOW_POSITION_FRONT) { return strRetunValue = REAL_CAMERA_DEVTYPE_FRONT;}
			else if(strValue == SHOW_POSITION_REAR) { return strRetunValue = REAL_CAMERA_DEVTYPE_REAR;}
			break;
		case SectionUnitType::ETC:
			return strValue;
			break;
		default:

            break;
	}

	return strRetunValue;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void TFrame_ConfigSetting::changeDataFromUI(IpuConfig &configValues) {
	String strExIPText = "\"" + RemoveSpacesFromIP(m_Ex_MaskEdit_IPAddress->Text.Trim()) + "/" + RemoveSpacesFromIP(m_Ex_MaskEdit_SubNetAddress->Text.Trim()) + "/" + RemoveSpacesFromIP(m_Ex_MaskEdit_GateWayAddress->Text.Trim()) + "\"";
	String strInIPText = "\"" + RemoveSpacesFromIP(m_In_MaskEdit_IPAddress->Text.Trim()) + "/" + RemoveSpacesFromIP(m_In_MaskEdit_SubNetAddress->Text.Trim()) + "/" + RemoveSpacesFromIP(m_In_MaskEdit_GateWayAddress->Text.Trim()) + "\"";

	configValues.ipIn.change(strInIPText);
	configValues.ipOut.change(strExIPText);
}

void TFrame_ConfigSetting::changeDataFromUI(LaneConfig &configValues) {
	//ChangeValue_ShowToReal
	//[SYSTEM]
	int nSelectIndex = 0;
	String strValue = "NULL";

	nSelectIndex = m_cbOneipu->ItemIndex;
	configValues.nOneipuOnly.change(StrToInt(ChangeValue_ShowToReal(m_cbOneipu->Items->Strings[nSelectIndex], SectionUnitType::DATA)));

	nSelectIndex = m_cbAxisWeight->ItemIndex;
	configValues.nAxisWeight.change(StrToInt(ChangeValue_ShowToReal(m_cbAxisWeight->Items->Strings[nSelectIndex], SectionUnitType::DATA)));

	nSelectIndex = m_cbOpType->ItemIndex;
	configValues.nOpType.change(StrToInt(ChangeValue_ShowToReal(m_cbOpType->Items->Strings[nSelectIndex], SectionUnitType::OPTYPE)));

	nSelectIndex = m_cbSystemType->ItemIndex;
	configValues.strSystemType.change(ChangeValue_ShowToReal(m_cbSystemType->Items->Strings[nSelectIndex], SectionUnitType::SYSTEMTYPE));

	nSelectIndex = m_cbPosition->ItemIndex;
	configValues.strPostion.change(ChangeValue_ShowToReal(m_cbPosition->Items->Strings[nSelectIndex], SectionUnitType::POSITION));
	//CAMERA
	//Position변경 시 CAMERA#1 Section에 DevType도 같이 변경 필수
	configValues.nDevType.change(StrToInt(ChangeValue_ShowToReal(m_cbPosition->Items->Strings[nSelectIndex], SectionUnitType::CAMERA)));

	nSelectIndex = m_cbTriggerType->ItemIndex;
	configValues.nTriggerType.change(StrToInt(ChangeValue_ShowToReal(m_cbTriggerType->Items->Strings[nSelectIndex], SectionUnitType::TRIGGERTYPE)));

	//[HIPASS]
	nSelectIndex = m_cbComType->ItemIndex;
	configValues.strComType.change(ChangeValue_ShowToReal(m_cbComType->Items->Strings[nSelectIndex], SectionUnitType::COMU));

	nSelectIndex = m_cbPort->ItemIndex;
	configValues.strPort.change(ChangeValue_ShowToReal(m_cbPort->Items->Strings[nSelectIndex], SectionUnitType::ETC));

	nSelectIndex = m_cbBaudRate->ItemIndex;
	configValues.nBaudRate.change(StrToInt(ChangeValue_ShowToReal(m_cbBaudRate->Items->Strings[nSelectIndex], SectionUnitType::ETC)));

	//[MIS]
	//재인식 서버
	configValues.strImageServer.change(RemoveSpacesFromIP(m_MaskEditImgServerIP->Text.Trim()));
	configValues.nImagePort.change(StrToInt(m_EditImgServerPort->Text.Trim()));

    //주제어기 서버
	configValues.strMCImageServer.change(RemoveSpacesFromIP(m_MaskEditMCServerIP->Text.Trim()));
	configValues.nMCImagePort.change(StrToInt(m_EditMCPort->Text));
}

void TFrame_ConfigSetting::changeDataFromUI(FtpConfig &configValues) {
	String strFtpServerAdress = RemoveSpacesFromIP(m_MaskEditFtpServerAddress->Text.Trim());
	String strFtpServerPort   = m_EditFtpServerPort->Text;
	String strFtpLoginID      = m_EditFtpLoginID->Text;
	String strFtpLoginPW      = m_EditFtpLoginPW->Text;

	configValues.ftpServerAddress.change(strFtpServerAdress);
	configValues.ftpServerPort.change(strFtpServerPort);
	configValues.ftpLoginID.change(strFtpLoginID);
	configValues.ftpLoginPW.change(strFtpLoginPW);
}

void TFrame_ConfigSetting::changeDataFromUI(RemoteConfig &configValues) {
	String strRemoteServerAddress = RemoveSpacesFromIP(m_MaskEditRemoteServerAddress->Text.Trim());
	String strRemoteServerPort = m_EditRemoteServerPort->Text;

	configValues.RemoteServerAddress.change(strRemoteServerAddress);
	configValues.RemoteServerPort.change(StrToInt(strRemoteServerPort));
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//네트워크 설정 변경 함수
bool TFrame_ConfigSetting::NetworkConfigChange(const std::string& adapterName, const std::string& ipAddress, const std::string& subnetMask, const std::string& gateway) {

	std::string command = "interface ip set address name=\"" + adapterName + "\" static " + ipAddress + " " + subnetMask + " " + gateway;

	if (ExecuteNetshCommand(command)) {
		std::cout << "IP address set successfully." << std::endl;
	} else {
		std::cerr << "Failed to set IP address." << std::endl;
		return 1;
	}

	return 0;
}
//네트워크 설정 변경 쉘 스크립트 동작 함수
bool TFrame_ConfigSetting::ExecuteNetshCommand(const std::string& command) {
	std::string fullCommand = "netsh " + command;
    int result = system(fullCommand.c_str());
    return (result == 0);
}

String TFrame_ConfigSetting::RemoveSpacesFromIP(const String &ip)
{
	String result;
	for(int i =1; i <= ip.Length(); i++)
	{
		if(ip[i] != ' ')
		{
			result += ip[i];
		}
	}
	if(result == "...") {result = "";}
    return result;
}

std::vector<std::string> TFrame_ConfigSetting::SplitString(const std::string& str, char delimiter)
{
	std::vector<std::string> tokens;
	std::stringstream ss(str);
	std::string token;

	while (std::getline(ss, token, delimiter))
	{
		tokens.push_back(token);
	}

	return tokens;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void __fastcall TFrame_ConfigSetting::m_btnLaneFileLoadClick(TObject *Sender)
{
	// find file
	//String strFilePath = selectIniFile(this);
	String strFilePath = "D:\\SmartTolling\\Init\\LaneSetting.ini";
	if(!strFilePath.IsEmpty()) { loadValues(strFilePath, FileUnitType::LANE); }
}

void __fastcall TFrame_ConfigSetting::m_btnIpuFileLoadClick(TObject *Sender)
{
	// find file
	//String strFilePath = selectIniFile(this);
	String strFilePath = "D:\\SmartTolling\\Init\\IPU_netconfig.ini";

	// load data
	if(!strFilePath.IsEmpty()) { loadValues(strFilePath, FileUnitType::IPU); }
}

void __fastcall TFrame_ConfigSetting::m_btnFtpFiledLoadClick(TObject *Sender)
{
	// find file
	//String strFilePath = selectIniFile(this);
	String strFilePath = "D:\\SmartTolling\\SUpload\\FTPUpload.ini";

	// load data
	if(!strFilePath.IsEmpty()) { loadValues(strFilePath, FileUnitType::FTP); }
}

void __fastcall TFrame_ConfigSetting::m_btnRemoteFiledLoadClick(TObject *Sender)
{
	// find file
	//String strFilePath = selectIniFile(this);
	String strFilePath = "D:\\SmartTolling\\Init\\REMOTESetting.ini";

	// load data
	if(!strFilePath.IsEmpty()) { loadValues(strFilePath, FileUnitType::REMOTE); }
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TFrame_ConfigSetting::m_btnFtpFiledSaveClick(TObject *Sender)
{
	String message = "저장 후 적용";
	FtpConfig m_fileConfigData;
	String strFilePath = FTP_FILE_PATH;

	m_fileConfigData.readFileValues(strFilePath);
	changeDataFromUI(m_fileConfigData);

	int result = Application->MessageBox((message+" 하시겠습니까?").c_str(), L"확인", MB_YESNO | MB_ICONQUESTION);
	if (result == mrYes) {
		m_fileConfigData.writeValues(strFilePath);//쓰기
		loadValues(strFilePath, FileUnitType::FTP);//쓰기 완료 후 읽기

		ShowMessage("저장되었습니다(FTP).");
	}
	else if (result == mrNo) {
		//ShowMessage("값을 다시 불러옵니다.");
		//loadValues();
	}
}

void __fastcall TFrame_ConfigSetting::m_btnIpuFileSaveClick(TObject *Sender)
{
	String message = "저장 후 적용";
	IpuConfig m_fileConfigData;
	String strFilePath = IPU_FILE_PATH;
	bool bRet = False;

	m_fileConfigData.readFileValues(strFilePath);
	changeDataFromUI(m_fileConfigData);

	int result = Application->MessageBox((message+" 하시겠습니까?").c_str(), L"확인", MB_YESNO | MB_ICONQUESTION);
	if (result == mrYes) {
		m_fileConfigData.writeValues(strFilePath);//쓰기
		loadValues(strFilePath, FileUnitType::IPU);//쓰기 완료 후 읽기
			
		//네트워크 설정 변경.
		//std::string adapterName = AnsiString(m_edtInterfaceIn->Text).c_str();
		bRet = NetworkConfigChange("IN"
		, AnsiString(RemoveSpacesFromIP(AnsiString(m_In_MaskEdit_IPAddress->Text).c_str())).c_str()
		, AnsiString(RemoveSpacesFromIP(AnsiString(m_In_MaskEdit_SubNetAddress->Text).c_str())).c_str()
		, AnsiString(RemoveSpacesFromIP(AnsiString(m_In_MaskEdit_GateWayAddress->Text).c_str())).c_str() );

		if(bRet) {m_Label_InNetChgExplan->Caption = NETWORK_CHG_RESULT_FALIL_STR;}
		else {m_Label_InNetChgExplan->Caption = NETWORK_CHG_RESULT_SUCCESS_STR;}

		//std::string adapterName = AnsiString(m_edtInterfaceOut->Text).c_str();
		bRet = NetworkConfigChange("EX"
		, AnsiString(RemoveSpacesFromIP(AnsiString(m_Ex_MaskEdit_IPAddress->Text).c_str())).c_str()
		, AnsiString(RemoveSpacesFromIP(AnsiString(m_Ex_MaskEdit_SubNetAddress->Text).c_str())).c_str()
		, AnsiString(RemoveSpacesFromIP(AnsiString(m_Ex_MaskEdit_GateWayAddress->Text).c_str())).c_str() );

		if(bRet) {m_Label_ExNetChgExplan->Caption = NETWORK_CHG_RESULT_FALIL_STR;}
		else {m_Label_ExNetChgExplan->Caption = NETWORK_CHG_RESULT_SUCCESS_STR;}

		if(bRet) 
		{		
			//ShowMessage("저장이 실패 되었습니다(IPU).");
			ShowMessage("네트워크 변경 실패 및 설정 값 저장 성공(IPU).");
		}
		else
		{
			ShowMessage("네트워크 변경 성공 및 설정 값 저장 성공 (IPU).");
		}

	}
	else if (result == mrNo) {
		//ShowMessage("값을 다시 불러옵니다.");
		//loadValues();
	}
}

void __fastcall TFrame_ConfigSetting::m_btnLaneFileSaveClick(TObject *Sender)
{
	String message = "저장 후 적용";
	LaneConfig m_fileConfigData;
	String strFilePath = LANE_FILE_PATH;

	m_fileConfigData.readFileValues(strFilePath);
	changeDataFromUI(m_fileConfigData);

	int result = Application->MessageBox((message+" 하시겠습니까?").c_str(), L"확인", MB_YESNO | MB_ICONQUESTION);
	if (result == mrYes) {
		m_fileConfigData.writeValues(strFilePath);//쓰기
		loadValues(strFilePath, FileUnitType::LANE);//쓰기 완료 후 읽기

		ShowMessage("저장되었습니다(LANE).");
	}
	else if (result == mrNo) {
		//ShowMessage("값을 다시 불러옵니다.");
		//loadValues();
	}
}

void __fastcall TFrame_ConfigSetting::m_btnRemoteFiledSaveClick(TObject *Sender)
{
	String message = "저장 후 적용";
	RemoteConfig m_fileConfigData;
	String strFilePath = REMOTE_FILE_PATH;

	m_fileConfigData.readFileValues(strFilePath);
	changeDataFromUI(m_fileConfigData);

	int result = Application->MessageBox((message+" 하시겠습니까?").c_str(), L"확인", MB_YESNO | MB_ICONQUESTION);
	if (result == mrYes) {
		m_fileConfigData.writeValues(strFilePath);//쓰기
		loadValues(strFilePath, FileUnitType::REMOTE);//쓰기 완료 후 읽기

		ShowMessage("저장되었습니다(REMOTE).");
	}
	else if (result == mrNo) {
		//ShowMessage("값을 다시 불러옵니다.");
		//loadValues();
	}
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TFrame_ConfigSetting::m_cbOpTypeChange(TObject *Sender)
{
	int nSelectIndex = 0;

	nSelectIndex = m_cbOpType->ItemIndex;
	if(m_cbOpType->Items->Strings[nSelectIndex] == SHOW_OPTYPE_11)
	{
		m_MaskEditMCServerIP->Enabled = TRUE;
		m_EditMCPort->Enabled = TRUE;
	}
	else
	{
		m_MaskEditMCServerIP->Enabled = FALSE;
        m_EditMCPort->Enabled = FALSE;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrame_ConfigSetting::m_EditFtpServerPortKeyPress(TObject *Sender,
          System::WideChar &Key)
{
	if (!isdigit(Key) && Key != VK_BACK && Key != '.' && Key != '-')
	{
		Key = 0; // 입력된 키를 무시
		ShowMessage("숫자만 입력 가능 합니다.");
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrame_ConfigSetting::m_EditFtpLoginPWKeyPress(TObject *Sender, System::WideChar &Key)

{
	if (!isdigit(Key) && Key != VK_BACK && Key != '.' && Key != '-')
	{
		Key = 0; // 입력된 키를 무시
		ShowMessage("숫자만 입력 가능 합니다.");
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrame_ConfigSetting::m_EditRemoteServerPortKeyPress(TObject *Sender,
          System::WideChar &Key)
{
	if (!isdigit(Key) && Key != VK_BACK && Key != '.' && Key != '-')
	{
		Key = 0; // 입력된 키를 무시
		ShowMessage("숫자만 입력 가능 합니다.");
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrame_ConfigSetting::m_EditImgServerPortKeyPress(TObject *Sender,
          System::WideChar &Key)
{
	if (!isdigit(Key) && Key != VK_BACK && Key != '.' && Key != '-')
	{
		Key = 0; // 입력된 키를 무시
		ShowMessage("숫자만 입력 가능 합니다.");
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrame_ConfigSetting::m_EditMCPortKeyPress(TObject *Sender, System::WideChar &Key)

{
 	if (!isdigit(Key) && Key != VK_BACK && Key != '.' && Key != '-')
	{
		Key = 0; // 입력된 키를 무시
		ShowMessage("숫자만 입력 가능 합니다.");
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrame_ConfigSetting::m_cbOneipuChange(TObject *Sender)
{
	int nSelectIndex = 0;

	nSelectIndex = m_cbOneipu->ItemIndex;
    String strValue = m_cbOneipu->Items->Strings[nSelectIndex];
	if(strValue == SHOW_DATA_O)
	{
		m_Label_OneIPUSelectExpaln->Caption = SHOW_ONEIPUSELECT_STREXPLAN_O;
	}
	else if(strValue == SHOW_DATA_X)
	{
		m_Label_OneIPUSelectExpaln->Caption = SHOW_ONEIPUSELECT_STREXPLAN_X;
	}
}
//---------------------------------------------------------------------------


void __fastcall TFrame_ConfigSetting::m_Ex_MaskEdit_IPAddressKeyPress(TObject *Sender,
          System::WideChar &Key)
{
    TMaskEdit *edit = dynamic_cast<TMaskEdit*>(Sender);
	if (edit)
	{
		// 숫자, 점(.) 및 백스페이스만 허용
		if (!isdigit(Key) && Key != '.' && Key != VK_BACK && Key != VK_TAB)
		{
			Key = 0; // 잘못된 키 입력을 무시
			ShowMessage("숫자만 입력 해주세요.");
		}
		/*
		else if (Key == VK_BACK) {
			 // 현재 텍스트 가져오기
			AnsiString Text = edit->Text;
			AnsiString NewText;
			int i;

			// 공백과 점(.)을 제외한 숫자만 추출
			for (i = 1; i <= Text.Length(); i++)
			{
				if (Text[i] >= '0' && Text[i] <= '9')
				{
					NewText += Text[i];
				}
			}

			// 추출한 숫자를 다시 IP 형식으로 변환
			AnsiString FormattedText;
			int len = NewText.Length();
			for (i = 1; i <= len; i++)
			{
				FormattedText += NewText[i];
				if (i % 3 == 0 && i < len)
				{
					FormattedText += '.';
				}
			}

			// 포맷된 텍스트를 MaskEdit에 설정
			edit->Text = FormattedText;
			edit->SelStart = FormattedText.Length(); // 커서를 텍스트 끝으로 이동                 
			}
			*/
	}
}
//---------------------------------------------------------------------------


bool TFrame_ConfigSetting::IsValidIP(const String &ip)
{
    // IP 주소의 유효성을 검사하는 간단한 함수
	/*
	TRegEx regex("^\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}$");
	if (!regex.IsMatch(ip))
		return false;
	*/

	const String pattern = "^\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}$";
	if (!TRegEx::IsMatch(ip, pattern))
		return false;

    TStringList *parts = new TStringList();
    try
    {
        parts->Delimiter = '.';
        parts->DelimitedText = ip;
        if (parts->Count != 4)
            return false;

        for (int i = 0; i < parts->Count; i++)
        {
            int part = StrToIntDef(parts->Strings[i], -1);
            if (part < 0 || part > 255)
                return false;
        }
    }
    __finally
    {
        delete parts;
    }

    return true;
}
//---------------------------------------------------------------------------


// OnKeyPress 이벤트 핸들러
void __fastcall TFrame_ConfigSetting::EditIPKeyPress(TObject *Sender, System::WideChar &Key)
{
    // 숫자, 점(.) 및 백스페이스만 허용
    if (!((Key >= '0' && Key <= '9') || Key == '.' || Key == '\b'))
    {
        Key = 0;
    }
}

// OnExit 이벤트 핸들러
bool __fastcall TFrame_ConfigSetting::IsValidIP(const AnsiString &ip)
{
    // IP 주소를 '.'으로 분할
    TStringList *parts = new TStringList();
    parts->Delimiter = '.';
    parts->DelimitedText = ip;

    // 분할된 부분이 4개인지 확인
    if (parts->Count != 4)
    {
        delete parts;
        return false;
	}

    // 각 부분이 0에서 255 사이의 숫자인지 확인
    for (int i = 0; i < parts->Count; i++)
    {
        int value = StrToIntDef(parts->Strings[i], -1);
        if (value < 0 || value > 255)
        {
            delete parts;
            return false;
        }
    }

    delete parts;
    return true;
}

