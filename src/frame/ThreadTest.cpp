#include <vcl.h>
#include <fstream>
#pragma hdrstop

#include "ThreadTest.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"
TFrameForThread *FrameForThread;

//---------------------------------------------------------------------------

__fastcall TFrameForThread::TFrameForThread(TComponent* Owner)
	: TFrame(Owner)
{
	m_customThread = nullptr;
}

//---------------------------------------------------------------------------

void __fastcall TFrameForThread::m_btnStartClick(TObject *Sender)
{
	int iSpinnerValue = StrToInt(m_spinEditSec->Text);
	if (iSpinnerValue <= 0) {
        ShowMessage("스피너의 값이 0보다 커야 합니다.");
        return;
	}

    if (!m_customThread || !m_customThread->IsRunning()) {
		TDateTime dtStartTime = Now();
        String strLogFilePath = "C:\\Users\\youngyin\\Downloads\\mydata\\logfile.txt";

		m_customThread = new TCustomThread(iSpinnerValue, [this, strLogFilePath]() {
			this->LogExecution(strLogFilePath);
		}, dtStartTime);

        m_customThread->StartThread();
    }
}

//---------------------------------------------------------------------------

void TFrameForThread::LogExecution(const String& logFilePath)
{
	TDateTime dtCurrentTime = Now();
    String strLogMessage = Format("실행 결과: %s\n", ARRAYOFCONST((dtCurrentTime.FormatString("yyyy-mm-dd hh:nn:ss"))));

	// UTF-8로 파일을 열기 위해 std::wofstream 사용
	std::wofstream logFile(logFilePath.w_str(), std::ios::app);
	logFile.imbue(std::locale(logFile.getloc(), new std::codecvt_utf8<wchar_t>));

	if (logFile.is_open()) {
		logFile << strLogMessage.w_str();
		logFile.close();
    } else {
        ShowMessage("로그 파일을 열 수 없습니다.");
    }
}

//---------------------------------------------------------------------------

void __fastcall TFrameForThread::m_btnStopClick(TObject *Sender)
{
    if (m_customThread && m_customThread->IsRunning()) {
        m_customThread->StopThread();
        delete m_customThread;
        m_customThread = nullptr;
    }
}

//---------------------------------------------------------------------------

void __fastcall TFrameForThread::m_btnStatusClick(TObject *Sender)
{
	if (m_customThread && (m_customThread->IsRunning())) {
		ShowMessage("스레드가 실행 중입니다.");
    } else {
        ShowMessage("스레드가 중지되었습니다.");
    }
}
//---------------------------------------------------------------------------


