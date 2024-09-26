//---------------------------------------------------------------------------

#pragma hdrstop

#include "LaneConfig.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
void __fastcall LaneConfig::writeValues(String strFilePath) {
    INIFileManager *pIniManager = new INIFileManager(strFilePath);

	// SYSTEM ���ǿ� ������ ����
	if (nOneipuOnly.isChange()) pIniManager->Write("SYSTEM", "ONEIPU_ONLY", nOneipuOnly.get());
	if (nAxisWeight.isChange()) pIniManager->Write("SYSTEM", "AXISWEIGHT", nAxisWeight.get());
	if (nOpType.isChange()) pIniManager->Write("SYSTEM", "OP_TYPE", nOpType.get());
	if (strSystemType.isChange()) pIniManager->Write("SYSTEM", "SYSTEMTYPE", strSystemType.get());
	if (strPostion.isChange()) pIniManager->Write("SYSTEM", "POSITION", strPostion.get());
	if (nTriggerType.isChange()) pIniManager->Write("SYSTEM", "TRIGGERTYPE", nTriggerType.get());

	// HIPASS ���ǿ� ������ ����
	if (strComType.isChange()) pIniManager->Write("HIPASS", "COM_TYPE", strComType.get());
	if (strPort.isChange()) pIniManager->Write("HIPASS", "PORT1", strPort.get());
	if (nBaudRate.isChange()) pIniManager->Write("HIPASS", "BAUDRATE1", nBaudRate.get());

	// CAMERA#1 ���ǿ� ������ ����
	if (nDevType.isChange()) pIniManager->Write("CAMERA#1", "DEVTYPE", nDevType.get());

    // MIS ���ǿ� ������ ����
	// ���νļ���
	if (strImageServer.isChange()) pIniManager->Write("MIS", "IMAGESERVER", strImageServer.get());
	if (strImagePort.isChange()) pIniManager->Write("MIS", "IMAGERSERVERPORT", strImagePort.get());

	// ������⼭��
	if (strMCImageServer.isChange()) pIniManager->Write("MIS", "MCIMAGESERVER", strMCImageServer.get());
	if (strMCImagePort.isChange()) pIniManager->Write("MIS", "MCIMAGERSERVERPORT", strMCImagePort.get());

	pIniManager = nullptr;
}

//---------------------------------------------------------------------------
void LaneConfig::readFileValues(String strFilePath) {
	INIFileManager *pIniManager = new INIFileManager(strFilePath);

	// CONFIG ������ �� �б�
	nOneipuOnly.init(pIniManager->Read("SYSTEM", "ONEIPU_ONLY"));
	nAxisWeight.init(pIniManager->Read("SYSTEM", "AXISWEIGHT"));
	nOpType.init(pIniManager->Read("SYSTEM", "OP_TYPE"));
	strSystemType.init(pIniManager->Read("SYSTEM", "SYSTEMTYPE"));
	strPostion.init(pIniManager->Read("SYSTEM", "POSITION"));
	nTriggerType.init(pIniManager->Read("SYSTEM", "TRIGGERTYPE"));

	// HIPASS ������ �� �б�
	strComType.init(pIniManager->Read("HIPASS", "COM_TYPE"));
	strPort.init(pIniManager->Read("HIPASS", "PORT1"));
	nBaudRate.init(pIniManager->Read("HIPASS", "BAUDRATE1"));

	// CAMERA#1
	nDevType.init(pIniManager->Read("CAMERA#1", "DEVTYPE"));

	// MIS ������ �� �б�
	strImageServer.init(pIniManager->Read("MIS", "IMAGESERVER"));
	strImagePort.init(pIniManager->Read("MIS", "IMAGERSERVERPORT"));

	strMCImageServer.init(pIniManager->Read("MIS", "MCIMAGESERVER"));
	strMCImagePort.init(pIniManager->Read("MIS", "MCIMAGERSERVERPORT"));

	//TDateTime dtlastSet = pIniManager->Read("CONFIG", "LASTSET", INIFileManager::DataType::DateTime);
	//lastSet.init(dtlastSet);

	pIniManager = nullptr;
}
