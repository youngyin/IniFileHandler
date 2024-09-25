//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrameRemote.h"

#include <vcl.h>
#include <vector>
#include <string>
#include <sstream>

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
	m_In_MaskEdit_IPAddress->EditMask = "000.000.000.000;1;_";
	m_In_MaskEdit_SubNetAddress->EditMask = "000.000.000.000;1;_";
	m_In_MaskEdit_GateWayAddress->EditMask = "000.000.000.000;1;_";
	m_Ex_MaskEdit_IPAddress->EditMask = "000.000.000.000;1;_";
	m_Ex_MaskEdit_SubNetAddress->EditMask = "000.000.000.000;1;_";
	m_Ex_MaskEdit_GateWayAddress->EditMask = "000.000.000.000;1;_";
	m_MaskEditFtpServerAddress->EditMask = "000.000.000.000;1;_";
	m_MaskEditRemoteServerAddress->EditMask = "000.000.000.000;1;_";
	m_MaskEditImgServerIP->EditMask = "000.000.000.000;1;_";
	m_MaskEditMCServerIP->EditMask = "000.000.000.000;1;_";
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
	if(strInipAddress[2] != ""){ m_In_MaskEdit_GateWayAddress->Text = strInipAddress[2];}


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
	if(strExipAddress[2] != ""){ m_Ex_MaskEdit_GateWayAddress->Text = strExipAddress[2];}
}

void TFrame_ConfigSetting::displayValues_LANE(const LaneConfig &configValues){
	//Real로 읽은 값을 Show 값으로 치환 후 Add된 것과 같은게 있으면 해당 부분을 CurSel한다.
	int nIndex = 0;
	//SYSTEM
	m_EditOneIPU->Text = configValues.nOneipuOnly.get();
	nIndex = m_cbOneipu->Items->IndexOf(ChangeValue_RealToShow(configValues.nOneipuOnly.get(), SectionUnitType::DATA));
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
	nIndex = m_cbAxisWeight->Items->IndexOf(ChangeValue_RealToShow(configValues.nAxisWeight.get(), SectionUnitType::DATA));
	m_cbAxisWeight->ItemIndex = nIndex;

	m_EditOpType->Text = configValues.nOpType.get();
	nIndex = m_cbOpType->Items->IndexOf(ChangeValue_RealToShow(configValues.nOpType.get(), SectionUnitType::OPTYPE));
	m_cbOpType->ItemIndex = nIndex;

	m_EditSystemType->Text = configValues.nSystemType.get();
	nIndex = m_cbSystemType->Items->IndexOf(ChangeValue_RealToShow(configValues.nSystemType.get(), SectionUnitType::SYSTEMTYPE));
	m_cbSystemType->ItemIndex = nIndex;

	m_EditPosition->Text = configValues.strPostion.get();
	nIndex = m_cbPosition->Items->IndexOf(ChangeValue_RealToShow(configValues.strPostion.get(), SectionUnitType::POSITION));
	m_cbPosition->ItemIndex = nIndex;

	m_EditTriggerType->Text = configValues.nTriggerType.get();
	nIndex = m_cbTriggerType->Items->IndexOf(ChangeValue_RealToShow(configValues.nTriggerType.get(), SectionUnitType::TRIGGERTYPE));
	m_cbTriggerType->ItemIndex = nIndex;

	//HIPASS
	m_EditComType->Text = configValues.strComType.get();
	nIndex = m_cbComType->Items->IndexOf(ChangeValue_RealToShow(configValues.strComType.get(), SectionUnitType::COMU));
	m_cbComType->ItemIndex = nIndex;

	m_EditComPort->Text = configValues.strPort.get();
	nIndex = m_cbPort->Items->IndexOf(ChangeValue_RealToShow(configValues.strPort.get(), SectionUnitType::COMU));
	m_cbPort->ItemIndex = nIndex;

	m_EditComBaudRate->Text = configValues.nBaudRate.get();
	nIndex = m_cbBaudRate->Items->IndexOf(ChangeValue_RealToShow(configValues.nBaudRate.get(), SectionUnitType::COMU));
	m_cbBaudRate->ItemIndex = nIndex;

	//MIS(재인식서버)
	m_MaskEditImgServerIP->Text = configValues.strImageServer.get();
	m_EditImgServerPort->Text = configValues.strImagePort.get();

	//MIS(주제어기 서버)
	m_MaskEditMCServerIP->Text = configValues.strMCImageServer.get();
	m_EditMCPort->Text = configValues.strMCImagePort.get();

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
	String strExIPText = m_Ex_MaskEdit_IPAddress->Text + "/" + m_Ex_MaskEdit_SubNetAddress->Text + "/" + m_Ex_MaskEdit_GateWayAddress->Text;
	String strInIPText = m_In_MaskEdit_IPAddress->Text + "/" + m_In_MaskEdit_SubNetAddress->Text + "/" + m_In_MaskEdit_GateWayAddress->Text;

	configValues.ipIn.change(strInIPText);
	configValues.ipOut.change(strExIPText);
}

void TFrame_ConfigSetting::changeDataFromUI(LaneConfig &configValues) {
	//ChangeValue_ShowToReal
	//[SYSTEM]
	int nSelectIndex = 0;
	String strValue = "NULL";

	nSelectIndex = m_cbOneipu->ItemIndex;
	configValues.nOneipuOnly.change(ChangeValue_ShowToReal(m_cbOneipu->Items->Strings[nSelectIndex], SectionUnitType::DATA));

	nSelectIndex = m_cbAxisWeight->ItemIndex;
	configValues.nAxisWeight.change(ChangeValue_ShowToReal(m_cbAxisWeight->Items->Strings[nSelectIndex], SectionUnitType::DATA));

	nSelectIndex = m_cbOpType->ItemIndex;
	configValues.nOpType.change(ChangeValue_ShowToReal(m_cbOpType->Items->Strings[nSelectIndex], SectionUnitType::OPTYPE));

	nSelectIndex = m_cbSystemType->ItemIndex;
	configValues.nSystemType.change(ChangeValue_ShowToReal(m_cbSystemType->Items->Strings[nSelectIndex], SectionUnitType::SYSTEMTYPE));

	nSelectIndex = m_cbPosition->ItemIndex;
	configValues.strPostion.change(ChangeValue_ShowToReal(m_cbPosition->Items->Strings[nSelectIndex], SectionUnitType::POSITION));
	//CAMERA
	//Position변경 시 CAMERA#1 Section에 DevType도 같이 변경 필수
	configValues.nDevType.change(ChangeValue_ShowToReal(m_cbPosition->Items->Strings[nSelectIndex], SectionUnitType::CAMERA));

	nSelectIndex = m_cbTriggerType->ItemIndex;
	configValues.nTriggerType.change(ChangeValue_ShowToReal(m_cbTriggerType->Items->Strings[nSelectIndex], SectionUnitType::TRIGGERTYPE));

	//[HIPASS]
	nSelectIndex = m_cbComType->ItemIndex;
	configValues.strComType.change(ChangeValue_ShowToReal(m_cbComType->Items->Strings[nSelectIndex], SectionUnitType::COMU));

	nSelectIndex = m_cbPort->ItemIndex;
	configValues.strPort.change(ChangeValue_ShowToReal(m_cbPort->Items->Strings[nSelectIndex], SectionUnitType::ETC));

	nSelectIndex = m_cbBaudRate->ItemIndex;
	configValues.nBaudRate.change(ChangeValue_ShowToReal(m_cbBaudRate->Items->Strings[nSelectIndex], SectionUnitType::ETC));

	//[MIS]

	//재인식 서버
	configValues.strImageServer.change(m_MaskEditImgServerIP->Text);
	configValues.strImagePort.change(StrToInt(m_EditImgServerPort->Text));

    //주제어기 서버
	configValues.strMCImageServer.change(m_MaskEditMCServerIP->Text);
	configValues.strMCImagePort.change(StrToInt(m_EditMCPort->Text));
}

void TFrame_ConfigSetting::changeDataFromUI(FtpConfig &configValues) {
	String strFtpServerAdress = m_MaskEditFtpServerAddress->Text;
	String strFtpServerPort   = m_EditFtpServerPort->Text;
	String strFtpLoginID      = m_EditFtpLoginID->Text;
	String strFtpLoginPW      = m_EditFtpLoginPW->Text;

	configValues.ftpServerAddress.change(strFtpServerAdress);
	configValues.ftpServerPort.change(strFtpServerPort);
	configValues.ftpLoginID.change(strFtpLoginID);
	configValues.ftpLoginPW.change(strFtpLoginPW);
}

void TFrame_ConfigSetting::changeDataFromUI(RemoteConfig &configValues) {
	String strRemoteServerAddress = m_MaskEditRemoteServerAddress->Text;
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

	m_fileConfigData.readFileValues(strFilePath);
	changeDataFromUI(m_fileConfigData);

	int result = Application->MessageBox((message+" 하시겠습니까?").c_str(), L"확인", MB_YESNO | MB_ICONQUESTION);
	if (result == mrYes) {
		m_fileConfigData.writeValues(strFilePath);//쓰기
		loadValues(strFilePath, FileUnitType::IPU);//쓰기 완료 후 읽기

		//네트워크 설정 변경.
		//std::string adapterName = AnsiString(m_edtInterfaceIn->Text).c_str();
		NetworkConfigChange("IN"
		, AnsiString(m_In_MaskEdit_IPAddress->Text).c_str()
		, AnsiString(m_In_MaskEdit_SubNetAddress->Text).c_str()
		, AnsiString(m_In_MaskEdit_GateWayAddress->Text).c_str() );
		//std::string adapterName = AnsiString(m_edtInterfaceOut->Text).c_str();
		NetworkConfigChange("EX"
		, AnsiString(m_Ex_MaskEdit_IPAddress->Text).c_str()
		, AnsiString(m_Ex_MaskEdit_SubNetAddress->Text).c_str()
		, AnsiString(m_Ex_MaskEdit_GateWayAddress->Text).c_str() );

		ShowMessage("저장되었습니다(IPU).");
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

