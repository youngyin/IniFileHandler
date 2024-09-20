//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrameIpu.h"

#include <vcl.h>
#include <WinSock2.h>
#include <iphlpapi.h>
#include <memory.h>
#include <windows.h>
#include <Dialogs.hpp>
#include <System.UITypes.hpp>
#include <System.SysUtils.hpp>
#include <iostream>
#include <string>

#pragma comment(lib, "iphlpapi.lib")
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TFrame_IpuNet *Frame_IpuNet;

//---------------------------------------------------------------------------
__fastcall TFrame_IpuNet::TFrame_IpuNet(TComponent* Owner)
	: TFrame(Owner)
{
	loadValues();
}

void __fastcall TFrame_IpuNet::m_btnFindClick(TObject *Sender)
{
    // find file
	m_edtPath->Text = selectIniFile(this);

	// load data
	loadValues();
}

void __fastcall TFrame_IpuNet::m_btnLoadClick(TObject *Sender)
{
	loadValues();
	GetNetworkAdapters();
	getNetworkAdapter2();
}

void __fastcall TFrame_IpuNet::m_btnApplyClick(TObject *Sender)
{
	IpuConfig m_fileConfigData;
    m_fileConfigData.readFileValues(m_edtPath->Text);
	changeDataFromUI(m_fileConfigData);

	// 사용자에게 alert
	String message = "";
	if (m_fileConfigData.defaultSlot.isChange()) message += m_edtDefaultSlot->EditLabel->Caption + ", ";
	if (m_fileConfigData.lastSlot.isChange()) message += m_edtLastSlot->EditLabel->Caption + ", ";
	if (m_fileConfigData.lastSet.isChange()) message += m_edtLastset->EditLabel->Caption + ", ";
	if (m_fileConfigData.interfaceIn.isChange()) message += m_edtInterfaceIn->EditLabel->Caption + ", ";
	if (m_fileConfigData.ipIn.isChange()) message += m_edtIpIn->EditLabel->Caption + ", ";
	if (m_fileConfigData.interfaceOut.isChange()) message += m_edtInterfaceOut->EditLabel->Caption + ", ";
	if (m_fileConfigData.ipOut.isChange()) message += m_edtIpOut->EditLabel->Caption + ", ";
	if (m_fileConfigData.interfaceCam1.isChange()) message += m_edtInterfaceCam1->EditLabel->Caption + ", ";
	if (m_fileConfigData.ipCam1.isChange()) message += m_edtIpCam1->EditLabel->Caption + ", ";

	// 결과 메시지 표시
	if (message != "") {
		message = message.SubString(1, message.Length() - 2);
		int result = Application->MessageBox((message+"를 변경하시겠습니까?").c_str(), L"확인", MB_YESNO | MB_ICONQUESTION);
		if (result == mrYes) {
			m_fileConfigData.writeValues(m_edtPath->Text);
			loadValues();

			//네트워크 설정 변경.
			//std::string adapterName = AnsiString(m_edtInterfaceIn->Text).c_str();
			std::string adapterName = AnsiString(m_edtInterfaceOut->Text).c_str();
			NetworkConfigChange(adapterName);

			ShowMessage("저장되었습니다.");
		}
		else if (result == mrNo) {
			//ShowMessage("값을 다시 불러옵니다.");
			//loadValues();
		}

	} else {
		ShowMessage("변경된 값이 없습니다.");
	}
}

//---------------------------------------------------------------------------

void TFrame_IpuNet::changeDataFromUI(IpuConfig &configValues) {
	configValues.defaultSlot.change(m_edtDefaultSlot->Text);
	configValues.lastSlot.change(m_edtLastSlot->Text);
	configValues.lastSet.change(m_edtLastset->Text);
	configValues.interfaceIn.change(m_edtInterfaceIn->Text);
	configValues.ipIn.change(m_edtIpIn->Text);
	configValues.interfaceOut.change(m_edtInterfaceOut->Text);
	configValues.ipOut.change(m_edtIpOut->Text);
	configValues.interfaceCam1.change(m_edtInterfaceCam1->Text);
	configValues.ipCam1.change(m_edtIpCam1->Text);
}

void TFrame_IpuNet::GetNetworkAdapters(){
	Memo2->Clear(); // 이전 내용을 지웁니다.
	DWORD dwSize = 0;
	GetAdaptersInfo(NULL, &dwSize);  // Get required size
	IP_ADAPTER_INFO *pAdapterInfo = (IP_ADAPTER_INFO *)malloc(dwSize);

	if (GetAdaptersInfo(pAdapterInfo, &dwSize) == NO_ERROR)
	{
		IP_ADAPTER_INFO *pAdapter = pAdapterInfo;
		while (pAdapter)
		{
			Memo2->Lines->Add("Adapter : " + AnsiString(pAdapter->AdapterName));
			Memo2->Lines->Add("Description : " + AnsiString(pAdapter->Description));
			Memo2->Lines->Add("IP Address : " + AnsiString(pAdapter->IpAddressList.IpAddress.String));
			Memo2->Lines->Add("IP Mask : " + AnsiString(pAdapter->IpAddressList.IpMask.String));
			Memo2->Lines->Add("GatewayList.IpAddress : " + AnsiString(pAdapter->GatewayList.IpAddress.String));
			Memo2->Lines->Add("GatewayList.IpMask : " + AnsiString(pAdapter->GatewayList.IpMask.String));
			Memo2->Lines->Add("DhcpServer : " + AnsiString(pAdapter->DhcpServer.IpAddress.String));
			Memo2->Lines->Add("-------------------------------------------------");

			pAdapter = pAdapter->Next;
		}
	}
	free(pAdapterInfo);
}

void TFrame_IpuNet::GetNetworkAdapters(String strAdapterName){
	//Memo2->Clear(); // 이전 내용을 지웁니다.
	DWORD dwSize = 0;
	GetAdaptersInfo(NULL, &dwSize);  // Get required size
	IP_ADAPTER_INFO *pAdapterInfo = (IP_ADAPTER_INFO *)malloc(dwSize);

	if (GetAdaptersInfo(pAdapterInfo, &dwSize) == NO_ERROR)
	{
		IP_ADAPTER_INFO *pAdapter = pAdapterInfo;
		while (pAdapter)
		{
			if(AnsiString(pAdapter->AdapterName) ==  strAdapterName)
			{
				m_edtNetWorkInfo1->Text = AnsiString(pAdapter->AdapterName);//Adapter Name
				m_edtNetWorkInfo2->Text = AnsiString(pAdapter->IpAddressList.IpAddress.String);//IP Address
				m_edtNetWorkInfo3->Text = AnsiString(pAdapter->IpAddressList.IpMask.String);//GatewayList.IpMask
				m_edtNetWorkInfo4->Text = AnsiString(pAdapter->GatewayList.IpAddress.String);//GatewayList.IpAddress

				break;
			}
			else
			{
				pAdapter = pAdapter->Next;
            }
		}
	}
	free(pAdapterInfo);
}

void TFrame_IpuNet::getNetworkAdapter2(){
	Memo1->Clear(); // 이전 내용을 지웁니다.

	// IP_ADAPTER_ADDRESSES 구조체 사용
	ULONG outBufLen = 15000;
	PIP_ADAPTER_ADDRESSES pAddresses = (IP_ADAPTER_ADDRESSES*)malloc(outBufLen);

	if (GetAdaptersAddresses(AF_UNSPEC, 0, NULL, pAddresses, &outBufLen) == NO_ERROR)
	{
		PIP_ADAPTER_ADDRESSES pCurrentAddresses = pAddresses;

		while (pCurrentAddresses)
		{
			// 어댑터 이름 및 설명
			String adapterName = pCurrentAddresses->AdapterName;
			String friendlyName = pCurrentAddresses->FriendlyName;
			String stripv4;
			String strgatewayAddr;
			String strdhcpServer;

			Memo1->Lines->Add("어댑터 이름: " + friendlyName);
			Memo1->Lines->Add("어댑터 ID: " + adapterName); //  시스템에서 각 어댑터를 식별하는 데 사용되는 문자열

			//Slot_A Interface_in과 네트워크 이름 비교해서 데이터 가져오기
			if(m_edtInterfaceIn->Text == friendlyName)
			{
                //Adapter이름으로 IP/GateWay/SubNet 주소 가져오기.
				GetNetworkAdapters(adapterName);
				Memo1->Lines->Add("Found -------------------------------------------------");
				break;
			}
			else
			{
				Memo1->Lines->Add("Finding -------------------------------------------------");
				pCurrentAddresses = pCurrentAddresses->Next;
            }
		}
	}

	free(pAddresses);
}

DWORD TFrame_IpuNet::GetAdapterIndexByName(const std::string& adapterName) {
	PIP_ADAPTER_INFO pAdapterInfo = nullptr;
	ULONG ulOutBufLen = sizeof(IP_ADAPTER_INFO);
    DWORD dwRetVal = 0;

    pAdapterInfo = (IP_ADAPTER_INFO *)malloc(ulOutBufLen);
    if (pAdapterInfo == nullptr) {
        std::cerr << "Error allocating memory needed to call GetAdaptersInfo" << std::endl;
        return 0;
    }

    // Make an initial call to GetAdaptersInfo to get the necessary size into the ulOutBufLen variable
    if (GetAdaptersInfo(pAdapterInfo, &ulOutBufLen) == ERROR_BUFFER_OVERFLOW) {
        free(pAdapterInfo);
        pAdapterInfo = (IP_ADAPTER_INFO *)malloc(ulOutBufLen);
        if (pAdapterInfo == nullptr) {
            std::cerr << "Error allocating memory needed to call GetAdaptersInfo" << std::endl;
            return 0;
        }
    }

    // Make a second call to GetAdaptersInfo to get the actual data we want
    if ((dwRetVal = GetAdaptersInfo(pAdapterInfo, &ulOutBufLen)) == NO_ERROR) {
        PIP_ADAPTER_INFO pAdapter = pAdapterInfo;
        while (pAdapter) {
            if (adapterName == pAdapter->AdapterName) {
                DWORD index = pAdapter->Index;
                free(pAdapterInfo);
                return index;
            }
            pAdapter = pAdapter->Next;
        }
    } else {
        std::cerr << "GetAdaptersInfo failed with error: " << dwRetVal << std::endl;
    }

    if (pAdapterInfo)
        free(pAdapterInfo);

    return 0; // Return 0 if adapter not found
}

void TFrame_IpuNet::SetIPAddress(const std::string& adapterName, const std::string& ipAddress, const std::string& subnetMask) {
    ULONG nteContext = 0;
    ULONG nteInstance = 0;
    DWORD dwRetVal;

    // Get the adapter index
	DWORD adapterIndex = GetAdapterIndexByName(adapterName);
    if (adapterIndex == 0) {
        std::cerr << "Adapter not found: " << adapterName << std::endl;
        return;
    }

    // Set the IP address
	dwRetVal = AddIPAddress(
		inet_addr(ipAddress.c_str()),
        inet_addr(subnetMask.c_str()),
		adapterIndex,
		&nteContext,
        &nteInstance
	);

	// Set the GateWay address
	std::string newGateway = "192.168.1.1";
	dwRetVal = ChangeGateway(newGateway, adapterIndex);

    //관리자 권한으로 실행해야 동작 함.
	if (dwRetVal != NO_ERROR) {
		String strMsg = "AddIPAddress failed with error: ";
		ShowMessage(strMsg);
	} else {
		ShowMessage("IP address added successfully.");
    }
}

DWORD TFrame_IpuNet::ChangeGateway(const std::string& gatewayAddress, const DWORD interfaceIndex) {
	MIB_IPFORWARDROW row;
    DWORD dwRetVal = 0;
    ZeroMemory(&row, sizeof(MIB_IPFORWARDROW));

    row.dwForwardDest = 0;
	row.dwForwardMask = 0;
    row.dwForwardPolicy = 0;
    row.dwForwardNextHop = inet_addr(gatewayAddress.c_str());
	row.dwForwardIfIndex = interfaceIndex;
    row.dwForwardType = 3; // MIB_IPROUTE_TYPE_INDIRECT
    row.dwForwardProto = 3; // MIB_IPPROTO_NETMGMT
    row.dwForwardAge = 0;
    row.dwForwardNextHopAS = 0;
	row.dwForwardMetric1 = 1;

	dwRetVal = CreateIpForwardEntry(&row);
	if (dwRetVal != NO_ERROR) {
	    String strMsg = "ChangeGateway failed with error: ";
		ShowMessage(strMsg);
		//return true;
	} else {
		ShowMessage("ChangeGateway successfully.");
    }

	return dwRetVal;
}

bool TFrame_IpuNet::NetworkConfigChange(const std::string& adapterName) {
	//std::string adapterName = AnsiString(m_edtInterfaceIn->Text).c_str();
	std::string ipAddress = "192.168.1.107"; // 설정할 IP 주소
	std::string subnetMask = "255.255.255.0"; // 서브넷 마스크
	std::string gateway = "192.168.1.1"; // 게이트웨이 주소

	std::string command = "interface ip set address name=\"" + adapterName + "\" static " + ipAddress + " " + subnetMask + " " + gateway;

    if (ExecuteNetshCommand(command)) {
        std::cout << "IP address set successfully." << std::endl;
    } else {
        std::cerr << "Failed to set IP address." << std::endl;
        return 1;
    }

    return 0;
}

bool TFrame_IpuNet::ExecuteNetshCommand(const std::string& command) {
	std::string fullCommand = "netsh " + command;
    int result = system(fullCommand.c_str());
    return (result == 0);
}

void TFrame_IpuNet::loadValues(){
	IpuConfig m_fileConfigData;
	m_fileConfigData.readFileValues(m_edtPath->Text);
	displayValues(m_fileConfigData);
}

void TFrame_IpuNet::displayValues(const IpuConfig &configValues) {
	m_edtDefaultSlot->Text = configValues.defaultSlot.get();
	m_edtLastSlot->Text = configValues.lastSlot.get();
	m_edtLastset->Text = configValues.lastSet.get();
	m_edtInterfaceIn->Text = configValues.interfaceIn.get();
	m_edtIpIn->Text = configValues.ipIn.get();
	m_edtInterfaceOut->Text = configValues.interfaceOut.get();
	m_edtIpOut->Text = configValues.ipOut.get();
	m_edtInterfaceCam1->Text = configValues.interfaceCam1.get();
    m_edtIpCam1->Text = configValues.ipCam1.get();
}

String TFrame_IpuNet::selectIniFile(TComponent* Owner){
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

