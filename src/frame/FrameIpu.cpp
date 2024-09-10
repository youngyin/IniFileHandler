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
    //m_edtPath->Text = strFilePath;
	loadFileValue(m_edtPath->Text);
}

void __fastcall TFrameIpuNet::loadFileValue(String strFilePath){
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

