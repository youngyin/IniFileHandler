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

}

void __fastcall TFrame_ConfigSetting::m_btnIpuFileLoadClick(TObject *Sender)
{
    // find file
	String strFilePath = selectIniFile(this);

	// load data
	loadValues(strFilePath);
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
void TFrame_ConfigSetting::loadValues(const String &strFilePath){
	IpuConfig m_fileConfigData;
	String strPath = strFilePath;

	m_fileConfigData.readFileValues(strPath);
	displayValues(m_fileConfigData);

	m_strFilePath = strFilePath;
}

//---------------------------------------------------------------------------


void TFrame_ConfigSetting::displayValues(const IpuConfig &configValues) {
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
		m_fileConfigData.writeValues(m_strFilePath);
		loadValues(m_strFilePath);

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

bool TFrame_ConfigSetting::ExecuteNetshCommand(const std::string& command) {
	std::string fullCommand = "netsh " + command;
    int result = system(fullCommand.c_str());
    return (result == 0);
}

//---------------------------------------------------------------------------

