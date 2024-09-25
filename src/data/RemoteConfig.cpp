//---------------------------------------------------------------------------

#pragma hdrstop

#include "RemoteConfig.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void __fastcall RemoteConfig::writeValues(String strFilePath) {
	INIFileManager *pIniManager = new INIFileManager(strFilePath);

	// SYSTEM 섹션에 데이터 쓰기
	if (RemoteServerAddress.isChange()) pIniManager->Write("SYSTEM", "SERVER", RemoteServerAddress.get());
	if (RemoteServerPort.isChange()) pIniManager->Write("SYSTEM", "PORT", RemoteServerPort.get());

	pIniManager = nullptr;
}

//---------------------------------------------------------------------------
void RemoteConfig::readFileValues(String strFilePath) {
    INIFileManager *pIniManager = new INIFileManager(strFilePath);

	// SYSTEM 섹션의 값 읽기
	RemoteServerAddress.init(pIniManager->Read("SYSTEM", "SERVER"));
	RemoteServerPort.init(pIniManager->Read("SYSTEM", "PORT"));

	pIniManager = nullptr;
}