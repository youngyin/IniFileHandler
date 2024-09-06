#ifndef LogThreadH
#define LogThreadH

#include <System.Classes.hpp>
#include <Vcl.StdCtrls.hpp> // TMemo 포함

class TLogThread : public TThread
{
private:
    int Interval; // 스레드 실행 간격
    TMemo *Memo; // 로그를 추가할 메모 컴포넌트
    bool ShouldStop; // 스레드 멈춤 플래그

protected:
    void __fastcall Execute() override;

public:
    __fastcall TLogThread(TMemo *memo, int interval);
    void Start(); // interval을 받아서 시작
    void Stop(); // 스레드 멈추기
};

#endif

