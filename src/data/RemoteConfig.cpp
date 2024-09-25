//---------------------------------------------------------------------------

#pragma hdrstop

#include "RemoteConfig.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void __fastcall RemoteConfig::writeValues(String strFilePath) {
	INIFileManager *pIniManager = new INIFileManager(strFilePath);

	// SYSTEM ���ǿ� ������ ����
	if (RemoteServerAddress.isChange()) pIniManager->Write("SYSTEM", "SERVER", RemoteServerAddress.get());
	if (RemoteServerPort.isChange()) pIniManager->Write("SYSTEM", "PORT", RemoteServerPort.get());

	pIniManager = nullptr;
}

//---------------------------------------------------------------------------
void RemoteConfig::readFileValues(String strFilePath) {
    INIFileManager *pIniManager = new INIFileManager(strFilePath);

	// SYSTEM ������ �� �б�
	RemoteServerAddress.init(pIniManager->Read("SYSTEM", "SERVER"));
	RemoteServerPort.init(pIniManager->Read("SYSTEM", "PORT"));

	pIniManager = nullptr;
}