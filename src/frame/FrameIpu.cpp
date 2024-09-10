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
	ConfigValues configValues;
	readFileValues(m_edtPath->Text, configValues);
    displayValues(configValues);
}

void TFrameIpuNet::readFileValues(String strFilePath, ConfigValues &configValues) {
    INIFileManager *pIniManager = new INIFileManager(strFilePath);

    // CONFIG 섹션의 값 읽기
    configValues.defaultSlot = pIniManager->Read("CONFIG", "DEFAULT_SLOT", INIFileManager::DataType::String);
    configValues.lastSlot = pIniManager->Read("CONFIG", "LASTSLOT", INIFileManager::DataType::String);
    configValues.lastSet = pIniManager->Read("CONFIG", "LASTSET", INIFileManager::DataType::String);

    // SLOT_A 섹션의 값 읽기
    configValues.interfaceIn = pIniManager->Read("SLOT_A", "INTERFACE_IN", INIFileManager::DataType::String);
    configValues.ipIn = pIniManager->Read("SLOT_A", "IP_IN", INIFileManager::DataType::String);
    configValues.interfaceOut = pIniManager->Read("SLOT_A", "INTERFACE_OUT", INIFileManager::DataType::String);
    configValues.ipOut = pIniManager->Read("SLOT_A", "IP_OUT", INIFileManager::DataType::String);
    configValues.interfaceCam1 = pIniManager->Read("SLOT_A", "INTERFACE_CAM1", INIFileManager::DataType::String);
    configValues.ipCam1 = pIniManager->Read("SLOT_A", "IP_CAM1", INIFileManager::DataType::String);

	pIniManager = nullptr;
}

void TFrameIpuNet::displayValues(const ConfigValues &configValues) {
    // 편집 필드에 할당
    m_edtDefaultSlot->Text = configValues.defaultSlot;
    m_edtLastSlot->Text = configValues.lastSlot;
    m_edtLastset->Text = configValues.lastSet;
    m_edtInterfaceIn->Text = configValues.interfaceIn;
    m_edtIpIn->Text = configValues.ipIn;
    m_edtInterfaceOut->Text = configValues.interfaceOut;
    m_edtIpOut->Text = configValues.ipOut;
    m_edtInterfaceCam1->Text = configValues.interfaceCam1;
    m_edtIpCam1->Text = configValues.ipCam1;
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
    // find file
	m_edtPath->Text = selectIniFile(this);

	// load data
    ConfigValues configValues;
	readFileValues(m_edtPath->Text, configValues);
    displayValues(configValues);
}
//---------------------------------------------------------------------------

void __fastcall TFrameIpuNet::m_btnLoadClick(TObject *Sender)
{
	ConfigValues configValues;
	readFileValues(m_edtPath->Text, configValues);
    displayValues(configValues);
}

//---------------------------------------------------------------------------
void TFrameIpuNet::getDataFromUI(ConfigValues &configValues) {
    configValues.defaultSlot = m_edtDefaultSlot->Text;
    configValues.lastSlot = m_edtLastSlot->Text;
    configValues.lastSet = m_edtLastset->Text;
    configValues.interfaceIn = m_edtInterfaceIn->Text;
    configValues.ipIn = m_edtIpIn->Text;
    configValues.interfaceOut = m_edtInterfaceOut->Text;
    configValues.ipOut = m_edtIpOut->Text;
    configValues.interfaceCam1 = m_edtInterfaceCam1->Text;
    configValues.ipCam1 = m_edtIpCam1->Text;
}

void __fastcall TFrameIpuNet::writeData(String strFilePath, ConfigValues &configValues) {
    // 데이터 쓰기
    INIFileManager *pIniManager = new INIFileManager(strFilePath);

    // CONFIG 섹션에 데이터 쓰기
    pIniManager->Write("CONFIG", "DEFAULT_SLOT", configValues.defaultSlot);
    pIniManager->Write("CONFIG", "LASTSLOT", configValues.lastSlot);
    pIniManager->Write("CONFIG", "LASTSET", configValues.lastSet);

    // SLOT_A 섹션에 데이터 쓰기
    pIniManager->Write("SLOT_A", "INTERFACE_IN", configValues.interfaceIn);
    pIniManager->Write("SLOT_A", "IP_IN", configValues.ipIn);
    pIniManager->Write("SLOT_A", "INTERFACE_OUT", configValues.interfaceOut);
    pIniManager->Write("SLOT_A", "IP_OUT", configValues.ipOut);
    pIniManager->Write("SLOT_A", "INTERFACE_CAM1", configValues.interfaceCam1);
    pIniManager->Write("SLOT_A", "IP_CAM1", configValues.ipCam1);

    pIniManager = nullptr;
}


void __fastcall TFrameIpuNet::m_btnApplyClick(TObject *Sender)
{
	ConfigValues configValues;
	getDataFromUI(configValues);
	writeData(m_edtPath->Text, configValues);
}
//---------------------------------------------------------------------------

