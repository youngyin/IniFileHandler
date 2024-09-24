//---------------------------------------------------------------------------

#ifndef FtpConfigH
#define FtpConfigH
//---------------------------------------------------------------------------
// custom class
#include "src\util\INIFileManager.h"
#include "src\data\CValue.h"

class FtpConfig {
public :
	CValue<String> ftpServerAddress;
	CValue<String> ftpServerPort;
	CValue<String> ftpLoginID;
	CValue<String> ftpLoginPW;

	void readFileValues(String strFilePath);
	void __fastcall writeValues(String strFilePath);
};
#endif
