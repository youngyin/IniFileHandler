#include <System.SysUtils.hpp>
#include "TLogThread.h"
#pragma package(smart_init)

__fastcall TLogThread::TLogThread(TMemo *memo, int interval)
	: TThread(true), Memo(memo), ShouldStop(false), Interval(interval)
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
		Queue([this]() {
			String logMessage = FormatDateTime("yyyy-mm-dd hh:nn:ss", Now()) + " - 로그 메시지";
			Memo->Lines->Add(logMessage);
		});

        Sleep(Interval);
    }
}

void TLogThread::Stop()
{
	ShouldStop = true;
	Queue([this]() {
    	String logMessage = FormatDateTime("yyyy-mm-dd hh:nn:ss", Now()) + " - Thread has been stopped.";
		Memo->Lines->Add(logMessage);
	});
}

