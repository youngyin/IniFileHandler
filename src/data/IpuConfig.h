//---------------------------------------------------------------------------

#ifndef IpuConfigH
#define IpuConfigH
//---------------------------------------------------------------------------

// custom class
#include "src\util\INIFileManager.h"
#include "src\data\CValue.h"

class IpuConfig {
public :
	CValue<String> defaultSlot;
	CValue<String> lastSlot;
	CValue<TDateTime> lastSet;
	CValue<String> interfaceIn;
	CValue<String> ipIn;
	CValue<String> interfaceOut;
	CValue<String> ipOut;
	CValue<String> interfaceCam1;
	CValue<String> ipCam1;

	void readFileValues(String strFilePath);
	void __fastcall writeValues(String strFilePath);
};
#endif

