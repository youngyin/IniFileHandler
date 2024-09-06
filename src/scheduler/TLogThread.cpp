#include <System.SysUtils.hpp>
#include "TLogThread.h"
#pragma package(smart_init)

__fastcall TLogThread::TLogThread(TMemo *memo, int interval)
    : TThread(true), Memo(memo), ShouldStop(false)
{
}

void TLogThread::Start()
{
    ShouldStop = false; // 멈춤 플래그 초기화
    TThread::Start(); // 스레드 시작
}

void __fastcall TLogThread::Execute()
{
    while (!Terminated && !ShouldStop)
    {
        // 로그 메시지 생성
        String logMessage = FormatDateTime("yyyy-mm-dd hh:nn:ss", Now()) + " - 로그 메시지";

        // 메모에 추가
		Synchronize([this, logMessage]() {
			Memo->Lines->Add(logMessage);
		});

        Sleep(Interval); // 주어진 간격만큼 대기
    }
}

void TLogThread::Stop()
{
	ShouldStop = true; // 멈추기 플래그 설정
	Synchronize([this]() {
    	String logMessage = FormatDateTime("yyyy-mm-dd hh:nn:ss", Now()) + " - Thread has been stopped.";
		Memo->Lines->Add(logMessage);
	});
}

