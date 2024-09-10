//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrameIpu.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TFrameIpuNet *FrameIpuNet;

//---------------------------------------------------------------------------
__fastcall TFrameIpuNet::TFrameIpuNet(TComponent* Owner)
	: TFrame(Owner)
{
	loadFileValue(m_edtPath->Text);
}

void __fastcall TFrameIpuNet::loadFileValue(String strFilePath){
    INIFileManager *pIniManager;
	pIniManager = new INIFileManager(strFilePath);

	// CONFIG 섹션의 값 읽기
	String strDefaultSlot = pIniManager->Read("CONFIG", "DEFAULT_SLOT", INIFileManager::DataType::String);
	String strLastSlot = pIniManager->Read("CONFIG", "LASTSLOT", INIFileManager::DataType::String);
	String strLastSet = pIniManager->Read("CONFIG", "LASTSET", INIFileManager::DataType::String);

	// SLOT_A 섹션의 값 읽기
	String strInterfaceIn = pIniManager->Read("SLOT_A", "INTERFACE_IN", INIFileManager::DataType::String);
	String strIpIn = pIniManager->Read("SLOT_A", "IP_IN", INIFileManager::DataType::String);
	String strInterfaceOut = pIniManager->Read("SLOT_A", "INTERFACE_OUT", INIFileManager::DataType::String);
	String strIpOut = pIniManager->Read("SLOT_A", "IP_OUT", INIFileManager::DataType::String);
	String strInterfaceCam1 = pIniManager->Read("SLOT_A", "INTERFACE_CAM1", INIFileManager::DataType::String);
	String strIpCam1 = pIniManager->Read("SLOT_A", "IP_CAM1", INIFileManager::DataType::String);

	pIniManager = nullptr;

	// 편집 필드에 할당
	m_edtDefaultSlot->Text = strDefaultSlot;
	m_edtLastSlot->Text = strLastSlot;
	m_edtLastset->Text = strLastSet;
	m_edtInterfaceIn->Text = strInterfaceIn;
	m_edtIpIn->Text = strIpIn;
	m_edtInterfaceOut->Text = strInterfaceOut;
	m_edtIpOut->Text = strIpOut;
	m_edtInterfaceCam1->Text = strInterfaceCam1;
	m_edtIpCam1->Text = strIpCam1;
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



void __fastcall TFrameIpuNet::btnFindClick(TObject *Sender)
{
	m_edtPath->Text = selectIniFile(this);
}
//---------------------------------------------------------------------------

void __fastcall TFrameIpuNet::m_btnLoadClick(TObject *Sender)
{
    loadFileValue(m_edtPath->Text);
}
//---------------------------------------------------------------------------

