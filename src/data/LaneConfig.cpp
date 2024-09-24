//---------------------------------------------------------------------------

#pragma hdrstop

#include "LaneConfig.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
void __fastcall LaneConfig::writeValues(String strFilePath) {
    INIFileManager *pIniManager = new INIFileManager(strFilePath);

	// SYSTEM 섹션에 데이터 쓰기
	if (nOneipuOnly.isChange()) pIniManager->Write("SYSTEM", "ONEIPU_ONLY", nOneipuOnly.get());
	if (nAxisWeight.isChange()) pIniManager->Write("SYSTEM", "AXISWEIGHT", nAxisWeight.get());
	if (nOpType.isChange()) pIniManager->Write("SYSTEM", "OP_TYPE", nOpType.get());
	if (nSystemType.isChange()) pIniManager->Write("SYSTEM", "SYSTEMTYPE", nSystemType.get());
	if (strPostion.isChange()) pIniManager->Write("SYSTEM", "POSITION", strPostion.get());
	if (nTriggerType.isChange()) pIniManager->Write("SYSTEM", "TRIGGERTYPE", nTriggerType.get());

	// HIPASS 섹션에 데이터 쓰기
	if (strComType.isChange()) pIniManager->Write("HIPASS", "COM_TYPE", strComType.get());
	if (strPort.isChange()) pIniManager->Write("HIPASS", "PORT1", strPort.get());
	if (nBaudRate.isChange()) pIniManager->Write("HIPASS", "BAUDRATE1", nBaudRate.get());

    // MIS 섹션에 데이터 쓰기
	// 재인식서버
	if (strImageServer.isChange()) pIniManager->Write("MIS", "IMAGESERVER", strImageServer.get());
	if (strImagePort.isChange()) pIniManager->Write("MIS", "IMAGERSERVERPORT", strImagePort.get());

	// 주제어기서버
	if (strMCImageServer.isChange()) pIniManager->Write("MIS", "MCIMAGESERVER", strMCImageServer.get());
	if (strMCImagePort.isChange()) pIniManager->Write("MIS", "MCIMAGERSERVERPORT", strMCImagePort.get());

	pIniManager = nullptr;
}

//---------------------------------------------------------------------------
void LaneConfig::readFileValues(String strFilePath) {
	INIFileManager *pIniManager = new INIFileManager(strFilePath);

	// CONFIG 섹션의 값 읽기
	nOneipuOnly.init(pIniManager->Read("SYSTEM", "ONEIPU_ONLY"));
	nAxisWeight.init(pIniManager->Read("SYSTEM", "AXISWEIGHT"));
	nOpType.init(pIniManager->Read("SYSTEM", "OP_TYPE"));
	nSystemType.init(pIniManager->Read("SYSTEM", "SYSTEMTYPE"));
	strPostion.init(pIniManager->Read("SYSTEM", "POSITION"));
	nTriggerType.init(pIniManager->Read("SYSTEM", "TRIGGERTYPE"));

	// HIPASS 섹션의 값 읽기
	strComType.init(pIniManager->Read("HIPASS", "COM_TYPE"));
	strPort.init(pIniManager->Read("HIPASS", "PORT1"));
	nBaudRate.init(pIniManager->Read("HIPASS", "BAUDRATE1"));

	// MIS 섹션의 값 읽기
	strImageServer.init(pIniManager->Read("MIS", "IMAGESERVER"));
	strImagePort.init(pIniManager->Read("MIS", "IMAGERSERVERPORT"));

	strMCImageServer.init(pIniManager->Read("MIS", "MCIMAGESERVER"));
	strMCImagePort.init(pIniManager->Read("MIS", "MCIMAGERSERVERPORT"));

	//TDateTime dtlastSet = pIniManager->Read("CONFIG", "LASTSET", INIFileManager::DataType::DateTime);
	//lastSet.init(dtlastSet);

	pIniManager = nullptr;
}

Variant LaneConfig::ChangeValue_ShowToReal(String strValue) {
	Variant strRetunValue = strValue;

	if(strValue == SHOW_DATA_O) { return strRetunValue = REAL_DATA_O;}
	else if(strValue == SHOW_DATA_X) { return strRetunValue = REAL_DATA_X;}

	else if(strValue == SHOW_OPTYPE_22) { return strRetunValue = REAL_OPTYPE_22;}
	else if(strValue == SHOW_OPTYPE_21) { return strRetunValue = REAL_OPTYPE_21;}
	else if(strValue == SHOW_OPTYPE_11) { return strRetunValue = REAL_OPTYPE_11;}

	else if(strValue == SHOW_SYSTEMTYPE_O) { return strRetunValue = REAL_SYSTEMTYPE_O;}
	else if(strValue == SHOW_SYSTEMTYPE_I) { return strRetunValue = REAL_SYSTEMTYPE_I;}
	else if(strValue == SHOW_SYSTEMTYPE_U) { return strRetunValue = REAL_SYSTEMTYPE_U;}
	else if(strValue == SHOW_SYSTEMTYPE_D) { return strRetunValue = REAL_SYSTEMTYPE_D;}

	else if(strValue == SHOW_TRIGGERTYPE_1) { return strRetunValue = REAL_TRIGGERTYPE_1;}
	else if(strValue == SHOW_TRIGGERTYPE_99) { return strRetunValue = REAL_TRIGGERTYPE_99;}

	else if(strValue == SHOW_COMU_SERIAL) { return strRetunValue = REAL_COMU_SERIAL;}
	else if(strValue == SHOW_COMU_TCPIP) { return strRetunValue = REAL_COMU_TCPIP;}

	return strRetunValue;
}
