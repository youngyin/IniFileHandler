//---------------------------------------------------------------------------

#ifndef CustomThreadH
#define CustomThreadH
//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <functional>
#include <atomic>

class TCustomThread : public TThread
{
  private:
    std::atomic<bool> m_bIsRunning; // 스레드 실행 상태
    int m_nInterval; // Interval in seconds
    TDateTime m_dtStartTime; // 시작 시간
    std::function<void()> m_fnCallback; // 콜백 함수
  protected:
    void __fastcall Execute() override;
  public:
    __fastcall TCustomThread(int nInterval, std::function<void()> fnCallback,
        TDateTime dtStartTime = 0);
    void StartThread();
    void StopThread();
    bool IsRunning();
    void SetInterval(int nInterval);
};

#endif

