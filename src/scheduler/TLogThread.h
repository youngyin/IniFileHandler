#ifndef LogThreadH
#define LogThreadH

#include <System.Classes.hpp>
#include <Vcl.StdCtrls.hpp> // TMemo ����

class TLogThread : public TThread
{
private:
    int Interval; // ������ ���� ����
    TMemo *Memo; // �α׸� �߰��� �޸� ������Ʈ
    bool ShouldStop; // ������ ���� �÷���

protected:
    void __fastcall Execute() override;

public:
    __fastcall TLogThread(TMemo *memo, int interval);
    void Start(); // interval�� �޾Ƽ� ����
    void Stop(); // ������ ���߱�
};

#endif

