//---------------------------------------------------------------------------

#pragma hdrstop

#include "IpuConfig.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
void __fastcall IpuConfig::writeValues(String strFilePath) {
    INIFileManager *pIniManager = new INIFileManager(strFilePath);

	// CONFIG 섹션에 데이터 쓰기
	if (defaultSlot.isChange()) pIniManager->Write("CONFIG", "DEFAULT_SLOT", defaultSlot.get());
	if (lastSlot.isChange()) pIniManager->Write("CONFIG", "LASTSLOT", lastSlot.get());
	if (lastSet.isChange()) pIniManager->Write("CONFIG", "LASTSET", lastSet.get());

	// SLOT_A 섹션에 데이터 쓰기
	if (interfaceIn.isChange()) pIniManager->Write("SLOT_A", "INTERFACE_IN", interfaceIn.get());
	if (ipIn.isChange()) pIniManager->Write("SLOT_A", "IP_IN", ipIn.get());
	if (interfaceOut.isChange()) pIniManager->Write("SLOT_A", "INTERFACE_OUT", interfaceOut.get());
	if (ipOut.isChange()) pIniManager->Write("SLOT_A", "IP_OUT", ipOut.get());
	if (interfaceCam1.isChange()) pIniManager->Write("SLOT_A", "INTERFACE_CAM1", interfaceCam1.get());
	if (ipCam1.isChange()) pIniManager->Write("SLOT_A", "IP_CAM1", ipCam1.get());

	pIniManager = nullptr;
}

//---------------------------------------------------------------------------
void IpuConfig::readFileValues(String strFilePath) {
    INIFileManager *pIniManager = new INIFileManager(strFilePath);

    // CONFIG 섹션의 값 읽기
	defaultSlot.init(pIniManager->Read("CONFIG", "DEFAULT_SLOT", INIFileManager::DataType::String));
	lastSlot.init(pIniManager->Read("CONFIG", "LASTSLOT", INIFileManager::DataType::String));
	TDateTime dtlastSet = pIniManager->Read("CONFIG", "LASTSET", INIFileManager::DataType::DateTime);
	lastSet.init(dtlastSet);

	// SLOT_A 섹션의 값 읽기
	interfaceIn.init(pIniManager->Read("SLOT_A", "INTERFACE_IN", INIFileManager::DataType::String));
	ipIn.init(pIniManager->Read("SLOT_A", "IP_IN", INIFileManager::DataType::String));
	interfaceOut.init(pIniManager->Read("SLOT_A", "INTERFACE_OUT", INIFileManager::DataType::String));
	ipOut.init(pIniManager->Read("SLOT_A", "IP_OUT", INIFileManager::DataType::String));
	interfaceCam1.init(pIniManager->Read("SLOT_A", "INTERFACE_CAM1", INIFileManager::DataType::String));
	ipCam1.init(pIniManager->Read("SLOT_A", "IP_CAM1", INIFileManager::DataType::String));

	pIniManager = nullptr;
}

