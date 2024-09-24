//---------------------------------------------------------------------------

#pragma hdrstop

#include "FtpConfig.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
void __fastcall FtpConfig::writeValues(String strFilePath) {
	INIFileManager *pIniManager = new INIFileManager(strFilePath);

	// CONFIG 섹션에 데이터 쓰기
	if (ftpServerAddress.isChange()) pIniManager->Write("CONFIG", "FTPServerAddress", ftpServerAddress.get());
	if (ftpServerPort.isChange()) pIniManager->Write("CONFIG", "FTPServerPort", ftpServerPort.get());
	if (ftpLoginID.isChange()) pIniManager->Write("CONFIG", "FTPLoginID", ftpLoginID.get());
	if (ftpLoginPW.isChange()) pIniManager->Write("CONFIG", "FTPLoginPW", ftpLoginPW.get());

	pIniManager = nullptr;
}

//---------------------------------------------------------------------------
void FtpConfig::readFileValues(String strFilePath) {
    INIFileManager *pIniManager = new INIFileManager(strFilePath);

	// CONFIG 섹션의 값 읽기
	ftpServerAddress.init(pIniManager->Read("CONFIG", "FTPServerAddress"));
	ftpServerPort.init(pIniManager->Read("CONFIG", "FTPServerPort"));
	ftpLoginID.init(pIniManager->Read("CONFIG", "FTPLoginID"));
	ftpLoginPW.init(pIniManager->Read("CONFIG", "FTPLoginPW"));

	pIniManager = nullptr;
}