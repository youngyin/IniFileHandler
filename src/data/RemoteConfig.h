//---------------------------------------------------------------------------

#ifndef RemoteConfigH
#define RemoteConfigH
//---------------------------------------------------------------------------
// custom class
#include "src\util\INIFileManager.h"
#include "src\data\CValue.h"

class RemoteConfig {
public :
	CValue<String> RemoteServerAddress;
	CValue<int> RemoteServerPort;

	void readFileValues(String strFilePath);
	void __fastcall writeValues(String strFilePath);
};
#endif
