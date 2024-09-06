#include <System.SysUtils.hpp>
#include "TLogThread.h"
#pragma package(smart_init)

__fastcall TLogThread::TLogThread(TMemo *memo, int interval)
    : TThread(true), Memo(memo), ShouldStop(false)
{
}

void TLogThread::Start()
{
    ShouldStop = false; // ���� �÷��� �ʱ�ȭ
    TThread::Start(); // ������ ����
}

void __fastcall TLogThread::Execute()
{
    while (!Terminated && !ShouldStop)
    {
        // �α� �޽��� ����
        String logMessage = FormatDateTime("yyyy-mm-dd hh:nn:ss", Now()) + " - �α� �޽���";

        // �޸� �߰�
		Synchronize([this, logMessage]() {
			Memo->Lines->Add(logMessage);
		});

        Sleep(Interval); // �־��� ���ݸ�ŭ ���
    }
}

void TLogThread::Stop()
{
	ShouldStop = true; // ���߱� �÷��� ����
	Synchronize([this]() {
    	String logMessage = FormatDateTime("yyyy-mm-dd hh:nn:ss", Now()) + " - Thread has been stopped.";
		Memo->Lines->Add(logMessage);
	});
}

