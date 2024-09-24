//---------------------------------------------------------------------------

#ifndef LaneConfigH
#define LaneConfigH
//---------------------------------------------------------------------------
#endif

#include "src\util\INIFileManager.h"
#include "src\data\CValue.h"
#include "src\data\DefineValue.h"

class LaneConfig {
public :
	//*���μ���(LaneSetting.ini)

	//[SYSTEM]
	CValue<int> nOneipuOnly; //Ȯ������- O,X
	CValue<int> nAxisWeight; //��������- O,X
	CValue<int> nOpType;     //�������̽� ����-Hipass ����, Hipass ����, TCS/���������(22,21,11)
	CValue<String> nSystemType; //����Ÿ��- ���� �ⱸ, ���� �Ա�, ����� ����, ����� ����(O,I,U,D)

	CValue<String> strPostion; //��/�ĸ�- ����,�ĸ�(FRONT,REAR) * CAMERA section�� devType ���� ���� �����ؾ� ��.
	CValue<int> nTriggerType; //���� - Ʈ���� ����, ������ ����(1,99)

	//[HIPASS]
	CValue<String> strComType; //��Ź�� - SERIAL, TCP/IP(SERIAL,ETHERNET)
	CValue<String> strPort; //��Ʈ - COM1 ~ 10, COM3(�⺻)(COM1~COM10) - USE�� ���� ��� �ϴ� �� ����(Ȯ�� �ʿ�)
	CValue<int> nBaudRate; //BaudRate - 9600,14400,19200,38400,57600,115200

	//[MIS]
	//���νļ���
	CValue<String> strImageServer;
	CValue<int> strImagePort;

	//������� ����(�������̽� ����(TCP/��������� ����)�� ���� ������� ���� IP/Port ���� �����ϰ� �ؾ� ��.)
	CValue<String> strMCImageServer;
	CValue<int> strMCImagePort;


	//*FTP ����, ���ݰ��� ����(RemoteSetting.ini)

	//[SYSTEM]
	CValue<String> strRemoteServer;
	CValue<int> nRemotePort;

	//[FTP_FW]
	CValue<String> strFTPServer;
	CValue<int> nFTPPort;
	CValue<String> strFTPServerID;
	CValue<String> strFTPServerPW;

	void readFileValues(String strFilePath);
	void __fastcall writeValues(String strFilePath);
	Variant ChangeValue_ShowToReal(String strValue);
	Variant ChangeValue_RealToShow(String strValue);
private:
	CValue<int> nTestOneipuOnly; //Ȯ������- O,X
};