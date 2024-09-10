//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrameIpu.h"
//#include "src\util\INIFileManager.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrameIpuNet *FrameIpuNet;
//---------------------------------------------------------------------------
__fastcall TFrameIpuNet::TFrameIpuNet(TComponent* Owner)
	: TFrame(Owner)
{
	loadFileValue();
	//initDialog();
}

void __fastcall TFrameIpuNet::loadFileValue(){
	String strFilePath = "C:\\Users\\youngyin\\Downloads\\handlerResource\\init\\Init\\IPU_netconfig.ini";
    String strSection;

	// [CONFIG] section 값 읽기
	strSection = "CONFIG";
	TIniFile* pIniFile = new TIniFile(strFilePath);
	m_edtDefaultSlot->Text = pIniFile->ReadString(strSection, "DEFAULT_SLOT", "");
	m_edtLastSlot->Text = pIniFile->ReadString(strSection, "LASTSLOT", "");
	m_edtLastset->Text = pIniFile->ReadString(strSection, "LASTSET", "");

	// [SLOT_A] section 값 읽기
	strSection = "SLOT_A";
	m_edtInterfaceIn->Text = pIniFile->ReadString(strSection, "INTERFACE_IN", "");
	m_edtIpIn->Text = pIniFile->ReadString(strSection, "IP_IN", "");
	m_edtInterfaceOut->Text = pIniFile->ReadString(strSection, "INTERFACE_OUT", "");
	m_edtIpOut->Text = pIniFile->ReadString(strSection, "IP_OUT", "");
	m_edtInterfaceCam1->Text = pIniFile->ReadString(strSection, "INTERFACE_CAM1", "");
	m_edtIpCam1->Text = pIniFile->ReadString(strSection, "IP_CAM1", "");

	delete pIniFile;
	pIniFile = nullptr;

	/*INIFileManager *pIniManager;
	pIniManager = new INIFileManager(strFilePath);
	m_edtLastset->Text = DateTimeToStr(pIniManager->Read("CONFIG", "LASTSET", INIFileManager::DataType::DateTime));
	m_edtIpOut->Text = pIniManager->Read("SLOT_A", "IP_OUT", INIFileManager::DataType::String);
	pIniManager = nullptr; */
}

/*void __fastcall TFrameIpuNet::initDialog(){
	settingDialog = new TOKRightDlg(this);
} */
//---------------------------------------------------------------------------



void __fastcall TFrameIpuNet::m_BtnApplyClick(TObject *Sender)
{
	//settingDialog::Show();
}
//---------------------------------------------------------------------------

