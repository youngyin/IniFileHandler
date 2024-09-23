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
//#Watchdog=0 # �ǹ̾���
//RECOG_AI=1
//MTIMEOUT=3000
//FRCFRM_TIMEOUT = 120 - # f/r Ȯ�� - ������ timeout,  0 �ΰ��, Ȯ�������� ó������
//ONEIPU_ONLY = 0 - # hipass - 1 : Ȯ������ �� - "H",  0 : ��/�ĸ� ���� + Ȯ��TXT
//AXISWEIGHT=0 - # ���� : 1 - Connect,  0 - no use
//RERECOG=1 - #���տ��󼭹� ���ν� ���� : 0 : no use
//IDTABLE_MATCH=0 - #OBUTable Match ���� : 0 : no use
//OP_TYPE = 15 -# 10 : TCS      - 11 : TCS Normal, 15 : UTC tcs, 18 : MINJA tcs, - # 20 : HIPASS   - 22 : Hipass 2022 New,     21 : Hipass old type... ,     // 25 : Hipass2022 + �������� //
//SYSTEMTYPE=O
//POSITION = "FRONT" - # FRONT or REAR  -  Camera LANETYPE ����, Position �� ����!
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
#recogmoduleno = ��ⰹ��+1
#�ⱸ:O, �Ա� I, ���� U, ����:D
#OFFICE_NO=101 - ����ó������ ����
#LANE_NO=72    - ����ó������ ����

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
# in : 01 - out 11  : ����,  in 01 != out 12 : ȸ��
# 1 : Up , 2 : Down
LANEDIRECTION = TO_SEOUL
#0338116183 �������� ��Ʈ�� ����
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