//---------------------------------------------------------------------------

#pragma hdrstop

#include "CustomThread.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

__fastcall TCustomThread::TCustomThread(
    int nInterval, std::function<void()> fnCallback, TDateTime dtStartTime) :
    TThread(true),
	m_nInterval(nInterval), m_fnCallback(fnCallback), m_bIsRunning(false)
{
	//FreeOnTerminate = true; // 자동으로 메모리 해제
}

void __fastcall TCustomThread::Execute()
{
	m_bIsRunning = true;
	m_dtStartTime = Now();

    // 시작 시간 설정
    while (!Terminated) {
		TDateTime dtCurrentTime = Now();
        if (dtCurrentTime >= m_dtStartTime) {
            // 콜백 실행
            if (m_fnCallback) {
                m_fnCallback();
            }
            // 다음 실행 시간 설정
			m_dtStartTime += m_nInterval / 86400.0; // 초를 일수로 변환
        }
        Sleep(1000); // 1초 간격으로 현재 시간을 확인
    }

    m_bIsRunning = false;
}

void TCustomThread::StartThread()
{
    if (!m_bIsRunning) {
        Start(); // TThread의 Start() 메서드 호출
    }
}

void TCustomThread::StopThread()
{
    if (m_bIsRunning) {
		Terminate(); // 스레드 종료 요청
        WaitFor(); // 스레드가 종료될 때까지 대기
    }
}

bool TCustomThread::IsRunning()
{
    return m_bIsRunning;
}

void TCustomThread::SetInterval(int nInterval)
{
    if (m_bIsRunning) {
        throw std::runtime_error(
            "Thread is running. Please stop it before changing the interval.");
    }
    m_nInterval = nInterval;
}

