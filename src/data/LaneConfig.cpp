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
	if (nImagePort.isChange()) pIniManager->Write("MIS", "IMAGERSERVERPORT", nImagePort.get());

	// ������⼭��
	if (strMCImageServer.isChange()) pIniManager->Write("MIS", "MCIMAGESERVER", strMCImageServer.get());
	if (nMCImagePort.isChange()) pIniManager->Write("MIS", "MCIMAGERSERVERPORT", nMCImagePort.get());

	pIniManager = nullptr;
}

//---------------------------------------------------------------------------
void LaneConfig::readFileValues(String strFilePath) {
	INIFileManager *pIniManager = new INIFileManager(strFilePath);

	// CONFIG ������ �� �б�
	nOneipuOnly.init(pIniManager->Read("SYSTEM", "ONEIPU_ONLY", INIFileManager::DataType::Int));
	nAxisWeight.init(pIniManager->Read("SYSTEM", "AXISWEIGHT", INIFileManager::DataType::Int));
	nOpType.init(pIniManager->Read("SYSTEM", "OP_TYPE", INIFileManager::DataType::Int));
	strSystemType.init(pIniManager->Read("SYSTEM", "SYSTEMTYPE", INIFileManager::DataType::String));
	strPostion.init(pIniManager->Read("SYSTEM", "POSITION", INIFileManager::DataType::String));
	nTriggerType.init(pIniManager->Read("SYSTEM", "TRIGGERTYPE", INIFileManager::DataType::Int));

	// HIPASS ������ �� �б�
	strComType.init(pIniManager->Read("HIPASS", "COM_TYPE", INIFileManager::DataType::String));
	strPort.init(pIniManager->Read("HIPASS", "PORT1", INIFileManager::DataType::String));
	nBaudRate.init(pIniManager->Read("HIPASS", "BAUDRATE1", INIFileManager::DataType::Int));

	// CAMERA#1
	nDevType.init(pIniManager->Read("CAMERA#1", "DEVTYPE", INIFileManager::DataType::Int));

	// MIS ������ �� �б�
	strImageServer.init(pIniManager->Read("MIS", "IMAGESERVER", INIFileManager::DataType::String));
	nImagePort.init(pIniManager->Read("MIS", "IMAGERSERVERPORT", INIFileManager::DataType::Int));

	strMCImageServer.init(pIniManager->Read("MIS", "MCIMAGESERVER", INIFileManager::DataType::String));
	nMCImagePort.init(pIniManager->Read("MIS", "MCIMAGERSERVERPORT", INIFileManager::DataType::Int));

	//TDateTime dtlastSet = pIniManager->Read("CONFIG", "LASTSET", INIFileManager::DataType::DateTime);
	//lastSet.init(dtlastSet);

	pIniManager = nullptr;
}
