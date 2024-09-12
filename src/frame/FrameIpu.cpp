//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrameIpu.h"

#include <vcl.h>
#include <WinSock2.h>
#include <Iphlpapi.h>
#include <Dialogs.hpp>
#include <System.UITypes.hpp>
#include <vcl.h>
#include <winsock2.h>
#include <iphlpapi.h>
#include <memory.h>
#include <System.SysUtils.hpp>
#pragma comment(lib, "Iphlpapi.lib")

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TFrameIpuNet *FrameIpuNet;

//---------------------------------------------------------------------------
__fastcall TFrameIpuNet::TFrameIpuNet(TComponent* Owner)
	: TFrame(Owner)
{
    loadValues();
}

void TFrameIpuNet::loadValues(){
    IpuConfig m_fileConfigData;
	m_fileConfigData.readFileValues(m_edtPath->Text);
	displayValues(m_fileConfigData);
}

void TFrameIpuNet::displayValues(const IpuConfig &configValues) {
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
//---------------------------------------------------------------------------

String TFrameIpuNet::selectIniFile(TComponent* Owner){
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


void __fastcall TFrameIpuNet::m_btnFindClick(TObject *Sender)
{
    // find file
	m_edtPath->Text = selectIniFile(this);

	// load data
	loadValues();
}
//---------------------------------------------------------------------------

void __fastcall TFrameIpuNet::m_btnLoadClick(TObject *Sender)
{
	loadValues();
	GetNetworkAdapters();
    getNetworkAdapter2();
}

//---------------------------------------------------------------------------
void TFrameIpuNet::changeDataFromUI(IpuConfig &configValues) {
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

void __fastcall TFrameIpuNet::m_btnApplyClick(TObject *Sender)
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

/*
struct _IP_ADAPTER_INFO* Next;
DWORD ComboIndex;
char AdapterName[MAX_ADAPTER_NAME_LENGTH + 4];
char Description[MAX_ADAPTER_DESCRIPTION_LENGTH + 4];
UINT AddressLength;
BYTE Address[MAX_ADAPTER_ADDRESS_LENGTH];
DWORD Index;
UINT Type;
UINT DhcpEnabled;
PIP_ADDR_STRING CurrentIpAddress;
IP_ADDR_STRING IpAddressList;
IP_ADDR_STRING GatewayList;
IP_ADDR_STRING DhcpServer;
BOOL HaveWins;
IP_ADDR_STRING PrimaryWinsServer;
IP_ADDR_STRING SecondaryWinsServer;
time_t LeaseObtained;
time_t LeaseExpires;
*/

void TFrameIpuNet::GetNetworkAdapters()
{
	DWORD dwSize = 0;
	GetAdaptersInfo(NULL, &dwSize);  // Get required size
	IP_ADAPTER_INFO *pAdapterInfo = (IP_ADAPTER_INFO *)malloc(dwSize);
	if (GetAdaptersInfo(pAdapterInfo, &dwSize) == NO_ERROR)
	{
		IP_ADAPTER_INFO *pAdapter = pAdapterInfo;
		while (pAdapter)
		{
			m_edtNetWorkInfo1->Text = AnsiString(pAdapter->AdapterName);//Adapter Name
			m_edtNetWorkInfo2->Text = AnsiString(pAdapter->Description);//Description
			m_edtNetWorkInfo3->Text = AnsiString(pAdapter->IpAddressList.IpAddress.String);//IP Address
			m_edtNetWorkInfo4->Text = AnsiString(pAdapter->GatewayList.IpAddress.String);//GatewayList.IpAddress
			m_edtNetWorkInfo5->Text = AnsiString(pAdapter->GatewayList.IpMask.String);//GatewayList.IpMask
			m_edtNetWorkInfo6->Text = AnsiString(pAdapter->DhcpServer.IpAddress.String);//DhcpServer

			pAdapter = pAdapter->Next;
        }
    }
	free(pAdapterInfo);
}


void TFrameIpuNet::getNetworkAdapter2(){
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

            Memo1->Lines->Add("어댑터 이름: " + friendlyName);
            Memo1->Lines->Add("어댑터 ID: " + adapterName); //  시스템에서 각 어댑터를 식별하는 데 사용되는 문자열

            // IPv4 주소 가져오기
            for (PIP_ADAPTER_UNICAST_ADDRESS addr = pCurrentAddresses->FirstUnicastAddress; addr != NULL; addr = addr->Next)
            {
                if (addr->Address.lpSockaddr->sa_family == AF_INET)
                {
                    sockaddr_in* ipv4 = (sockaddr_in*)addr->Address.lpSockaddr;
                    Memo1->Lines->Add("IPv4 주소: " + String(inet_ntoa(ipv4->sin_addr)));
                }
            }

            // 게이트웨이 정보 가져오기
            for (PIP_ADAPTER_GATEWAY_ADDRESS gateway = pCurrentAddresses->FirstGatewayAddress; gateway != NULL; gateway = gateway->Next)
            {
                if (gateway->Address.lpSockaddr->sa_family == AF_INET)
                {
                    sockaddr_in* gatewayAddr = (sockaddr_in*)gateway->Address.lpSockaddr;
                    Memo1->Lines->Add("게이트웨이: " + String(inet_ntoa(gatewayAddr->sin_addr)));
                }
            }

            // DHCP 서버 정보 가져오기
            if (pCurrentAddresses->Dhcpv4Server.lpSockaddr)
			{
				sockaddr_in* dhcpServer = (sockaddr_in*)pCurrentAddresses->Dhcpv4Server.lpSockaddr;
				Memo1->Lines->Add("DHCP 서버: " + String(inet_ntoa(dhcpServer->sin_addr)));
			}

            Memo1->Lines->Add("-------------------------------------------------");
            pCurrentAddresses = pCurrentAddresses->Next;
        }
    }

    free(pAddresses);
}
