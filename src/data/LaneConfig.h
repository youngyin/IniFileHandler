//---------------------------------------------------------------------------

#ifndef LaneConfigH
#define LaneConfigH
//---------------------------------------------------------------------------
#endif

#include "src\util\INIFileManager.h"
#include "src\data\CValue.h"

class LaneConfig {
public :

//[SYSTEM]
//#Watchdog=0 # 의미없음
//RECOG_AI=1
//MTIMEOUT=3000
//FRCFRM_TIMEOUT = 120 - # f/r 확정 - 없으면 timeout,  0 인경우, 확정없으면 처리안함
//ONEIPU_ONLY = 0 - # hipass - 1 : 확정차량 만 - "H",  0 : 전/후면 영상 + 확정TXT
//AXISWEIGHT=0 - # 축중 : 1 - Connect,  0 - no use
//RERECOG=1 - #통합영상서버 재인식 여부 : 0 : no use
//IDTABLE_MATCH=0 - #OBUTable Match 여부 : 0 : no use
//OP_TYPE = 15 -# 10 : TCS      - 11 : TCS Normal, 15 : UTC tcs, 18 : MINJA tcs, - # 20 : HIPASS   - 22 : Hipass 2022 New,     21 : Hipass old type... ,     // 25 : Hipass2022 + 제한차량 //
//SYSTEMTYPE=O
//POSITION = "FRONT" - # FRONT or REAR  -  Camera LANETYPE 연동, Position 이 우위!
//VERSION=100
//FTPCONNECT=0
//FTPCONNECT2=0
//DATAREMAIN=7
//PASSWORD=32333337
//TRIGGERTYPE = 1 - # TriggerType  1 - Trigger Signal, 99 - Detect Plate


/*
[HIPASS]
COM_TYPE	= SERIAL
# or ETHERNET
USE1	= 1
PORT1 =COM3
BAUDRATE1=9600
IP1	= ""
EPORT1	= 0

USE2	= 0
PORT2 =COM4
BAUDRATE2=9600
IP2	= ""
EPORT2	= 0

[TCS]
#SERVER =127.0.0.1
LISTEN = 8010

OFFICE_NO = 0
LANE_NO = 0
WORK_NO = 0

[MIS]
RERECOG = 1
IMAGESERVER = 197.184.8.2
IMAGERSERVERPORT = 54000

MCIMAGESERVER = 197.184.8.79
MCIMAGERSERVERPORT = 54000
#IMAGERSERVERPORT = 1944

[AXIS_WEIGHT]
USE	= 0
IP	= ""
PORT	= 0

[comment]
#recogmoduleno = 모듈갯수+1
#출구:O, 입구 I, 상행 U, 하행:D
#OFFICE_NO=101 - 원격처리위한 설정
#LANE_NO=72    - 원격처리위한 설정

[CAMERA#1]
Device="F0001"
RLEFT=20
RTOP=100
RRIGHT=1900
RBOTTOM=1075
INTERSECT_WIDTH=700
DEVTYPE=1
#lanetype : 1 = front, 2 = rear, 0 : no exist	: FIX

[CAMERA#2]
Device="F0002"
RLEFT=20
RTOP=350
RRIGHT=1970
RBOTTOM=1070
INTERSECT_WIDTH=700
DEVTYPE=0
#lanetype : 1 = front, 2 = rear, 0 : no exist	: FIX

[ROUNDS]
ISROUNDS = 0
LANEFR = 1
#fr : 1 = front, 2 = rear
LANEID = 8801
#LaneID : id ( 88 ) + in(01) // 01, 02, 03 - in,  11,12,13 - out
# in : 01 - out 11  : 정상,  in 01 != out 12 : 회차
# 1 : Up , 2 : Down
LANEDIRECTION = TO_SEOUL
#0338116183 강원본부 네트웍 연결
*/

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