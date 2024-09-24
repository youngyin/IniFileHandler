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
	//*차로설정(LaneSetting.ini)

	//[SYSTEM]
	CValue<int> nOneipuOnly; //확정영상- O,X
	CValue<int> nAxisWeight; //축중차로- O,X
	CValue<int> nOpType;     //인터페이스 설정-Hipass 신형, Hipass 구형, TCS/무인정산기(22,21,11)
	CValue<String> nSystemType; //차로타입- 폐쇄식 출구, 폐쇄식 입구, 개방식 상행, 개방식 하행(O,I,U,D)

	CValue<String> strPostion; //전/후면- 전면,후면(FRONT,REAR) * CAMERA section에 devType 값도 같이 변경해야 함.
	CValue<int> nTriggerType; //검지 - 트리거 검지, 동영상 검지(1,99)

	//[HIPASS]
	CValue<String> strComType; //통신방식 - SERIAL, TCP/IP(SERIAL,ETHERNET)
	CValue<String> strPort; //포트 - COM1 ~ 10, COM3(기본)(COM1~COM10) - USE에 따라서 사용 하는 것 같음(확인 필요)
	CValue<int> nBaudRate; //BaudRate - 9600,14400,19200,38400,57600,115200

	//[MIS]
	//재인식서버
	CValue<String> strImageServer;
	CValue<int> strImagePort;

	//주제어기 서버(인터페이스 설정(TCP/무인정산기 선택)에 따라서 주제어기 서버 IP/Port 수정 가능하게 해야 함.)
	CValue<String> strMCImageServer;
	CValue<int> strMCImagePort;


	//*FTP 설정, 원격관제 설정(RemoteSetting.ini)

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
	CValue<int> nTestOneipuOnly; //확정영상- O,X
};