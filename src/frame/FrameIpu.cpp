//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrameIpu.h"

// custom class
#include "src\util\INIFileManager.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FrameLabelEdit"
#pragma resource "*.dfm"
TFrameIpuNet *FrameIpuNet;
//---------------------------------------------------------------------------
__fastcall TFrameIpuNet::TFrameIpuNet(TComponent* Owner)
	: TFrame(Owner)
{
    loadFileValue();
}

void __fastcall TFrameIpuNet::loadFileValue(){
	String strFilePath = "C:\\Users\\youngyin\\Downloads\\handlerResource\\init\\Init\\IPU_netconfig.ini";
    String strSection;

	// [CONFIG] section 값 읽기
	strSection = "CONFIG";
	TIniFile* m_pIniFile = new TIniFile(strFilePath);
	m_edtDefaultSlot->Text = m_pIniFile->ReadString(strSection, "DEFAULT_SLOT", "");
	m_edtLastSlot->Text = m_pIniFile->ReadString(strSection, "LASTSLOT", "");
	m_edtLastset->Text = m_pIniFile->ReadString(strSection, "LASTSET", "");

	// [SLOT_A] section 값 읽기
	strSection = "SLOT_A";
	m_edtInterfaceIn->Text = m_pIniFile->ReadString(strSection, "INTERFACE_IN", "");
	m_edtIpIn->Text = m_pIniFile->ReadString(strSection, "IP_IN", "");
	m_edtInterfaceOut->Text = m_pIniFile->ReadString(strSection, "INTERFACE_OUT", "");
	m_edtIpOut->Text = m_pIniFile->ReadString(strSection, "IP_OUT", "");
	m_edtInterfaceCam1->Text = m_pIniFile->ReadString(strSection, "INTERFACE_CAM1", "");
	m_edtIpCam1->Text = m_pIniFile->ReadString(strSection, "IP_CAM1", "");

	delete m_pIniFile;
	m_pIniFile = nullptr;
}
//---------------------------------------------------------------------------



