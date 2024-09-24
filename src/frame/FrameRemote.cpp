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
			break;
		case FileUnitType::FTP:
			break;
		default:
			break;
    }

	m_strFilePath = strFilePath;
}

//---------------------------------------------------------------------------


void TFrame_ConfigSetting::displayValues_IPU(const IpuConfig &configValues) {
	//configValues.defaultSlot.get();
	//configValues.lastSlot.get();
	//configValues.lastSet.get();
	//configValues.interfaceIn.get();

	configValues.ipIn.get();
	configValues.ipOut.get();

	//configValues.interfaceOut.get();
	//configValues.ipOut.get();
	//configValues.interfaceCam1.get();
	//configValues.ipCam1.get();

	std::vector<std::string> result_In = SplitString(AnsiString(configValues.ipIn.get()).c_str(), '/');

	int a = 0;
	String strInipAddress[3];
	for(const auto& part : result_In)
	{
		strInipAddress[a] = part.c_str();
		a++;
	}

	m_In_IPAddress->Text = strInipAddress[0];
	m_In_SubNetAddress->Text = strInipAddress[1];
	if(strInipAddress[2] != ""){ m_In_GateWayAddress->Text = strInipAddress[2];}


	std::vector<std::string> result_Ex = SplitString(AnsiString(configValues.ipOut.get()).c_str(), '/');

	int b = 0;
	String strExipAddress[3];
	for(const auto& part : result_Ex)
	{
		strExipAddress[b] = part.c_str();
		b++;
	}

	m_Ex_IPAddress->Text = strExipAddress[0];
	m_Ex_SubNetAddress->Text = strExipAddress[1];
	if(strExipAddress[2] != ""){ m_Ex_GateWayAddress->Text = strExipAddress[2];}
}

//---------------------------------------------------------------------------

void TFrame_ConfigSetting::displayValues_LANE(const LaneConfig &configValues){
    //SYSTEM
	m_EditOneIPU->Text = configValues.nOneipuOnly.get();
	m_EditAxisWeight->Text = configValues.nAxisWeight.get();
	m_EditOpType->Text = configValues.nOpType.get();
	m_EditSystemType->Text = configValues.nSystemType.get();

	m_EditPosition->Text = configValues.strPostion.get();
	m_EditTriggerType->Text = configValues.nTriggerType.get();

	//HIPASS
	m_EditComType->Text = configValues.strComType.get();
	m_EditComPort->Text = configValues.strPort.get();
	m_EditComBaudRate->Text = configValues.nBaudRate.get();

	//MIS(재인식서버)
	m_EditImgServerIP->Text = configValues.strImageServer.get();
	m_EditImgServerPort->Text = configValues.strImagePort.get();

	//MIS(주제어기 서버)
	m_EditMCServerIP->Text = configValues.strMCImageServer.get();
	m_EditMCPort->Text = configValues.strMCImagePort.get();
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

void __fastcall TFrame_ConfigSetting::m_btnIpuFileSaveClick(TObject *Sender)
{
	String message = "저장 후 적용";
	IpuConfig m_fileConfigData;
	m_fileConfigData.readFileValues(m_strFilePath);
	changeDataFromUI(m_fileConfigData);

	int result = Application->MessageBox((message+" 하시겠습니까?").c_str(), L"확인", MB_YESNO | MB_ICONQUESTION);
	if (result == mrYes) {
		m_fileConfigData.writeValues(m_strFilePath);//쓰기
		loadValues(m_strFilePath, FileUnitType::IPU);//쓰기 완료 후 읽기

		//네트워크 설정 변경.
		//std::string adapterName = AnsiString(m_edtInterfaceIn->Text).c_str();
		NetworkConfigChange("IN"
		, AnsiString(m_In_IPAddress->Text).c_str()
		, AnsiString(m_In_SubNetAddress->Text).c_str()
		, AnsiString(m_In_GateWayAddress->Text).c_str() );
		//std::string adapterName = AnsiString(m_edtInterfaceOut->Text).c_str();
		NetworkConfigChange("EX"
		, AnsiString(m_Ex_IPAddress->Text).c_str()
		, AnsiString(m_Ex_SubNetAddress->Text).c_str()
		, AnsiString(m_Ex_GateWayAddress->Text).c_str() );

		ShowMessage("저장되었습니다.");
	}
	else if (result == mrNo) {
		//ShowMessage("값을 다시 불러옵니다.");
		//loadValues();
	}
}

void TFrame_ConfigSetting::changeDataFromUI(IpuConfig &configValues) {
	String strExIPText = m_Ex_IPAddress->Text + "/" + m_Ex_SubNetAddress->Text + "/" + m_Ex_GateWayAddress->Text;
	String strInIPText = m_In_IPAddress->Text + "/" + m_In_SubNetAddress->Text + "/" + m_In_GateWayAddress->Text;

	configValues.ipIn.change(strInIPText);
	configValues.ipOut.change(strExIPText);
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

//---------------------------------------------------------------------------


//차로설정 SECSION
void __fastcall TFrame_ConfigSetting::m_btnLaneFileLoadClick(TObject *Sender)
{
	// find file
	String strFilePath = selectIniFile(this);

	// load data
	loadValues(strFilePath, FileUnitType::LANE);
}
//---------------------------------------------------------------------------

void __fastcall TFrame_ConfigSetting::m_btnIpuFileLoadClick(TObject *Sender)
{
	// find file
	String strFilePath = selectIniFile(this);

	// load data
	loadValues(strFilePath, FileUnitType::IPU);
}


void __fastcall TFrame_ConfigSetting::Button9Click(TObject *Sender)
{
   int a = 0;
}
//---------------------------------------------------------------------------


void __fastcall TFrame_ConfigSetting::Button8Click(TObject *Sender)
{
    int b = 0;
}
//---------------------------------------------------------------------------


void __fastcall TFrame_ConfigSetting::Button5Click(TObject *Sender)
{
	String message = "저장 후 적용";
	LaneConfig m_fileConfigData;
	m_fileConfigData.readFileValues(m_strFilePath);
	//changeDataFromUI(m_fileConfigData);

	int result = Application->MessageBox((message+" 하시겠습니까?").c_str(), L"확인", MB_YESNO | MB_ICONQUESTION);
	if (result == mrYes) {
		m_fileConfigData.writeValues(m_strFilePath);//쓰기
		loadValues(m_strFilePath, FileUnitType::LANE);//쓰기 완료 후 읽기

		ShowMessage("저장되었습니다(LANE).");
	}
	else if (result == mrNo) {
		//ShowMessage("값을 다시 불러옵니다.");
		//loadValues();
	}
}
//---------------------------------------------------------------------------

