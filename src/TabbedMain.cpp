//---------------------------------------------------------------------------
/**
* 2024-09-09 TabControl + Frame을 사용한 TabVeiw 예제
*
* [TTabControl]
* 구성: TTabControl은 단순히 탭을 표시하는 컴포넌트.
* 사용 용도: 주로 여러 개의 탭을 나열하고, 각 탭을 클릭하여 다른 내용을 표시하는 데 사용됩니다.
* 동작 방식: 각 탭에 대한 콘텐츠는 별도의 컨테이너나 컴포넌트에 표시해야 하며,
*		     탭을 클릭할 때 해당 콘텐츠를 수동으로 업데이트해야 합니다.
*/

#include <vcl.h>
#include <vector>

// 사용자 정의 class
#include "src\frame\First.h"
#include "src\frame\Second.h"

#pragma hdrstop

#include "TabbedMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TFormTabbed* FormTabbed;
TTabControl* m_pTabControl;
std::vector<TFrame*> m_frameVector;

//---------------------------------------------------------------------------
__fastcall TFormTabbed::TFormTabbed(TComponent* Owner) : TForm(Owner) {}

void __fastcall TFormTabbed::FormCreate(TObject* Sender)
{
    InitComponet();
}

void __fastcall TFormTabbed::InitComponet()
{
	m_pTabControl = new TTabControl(this);
	m_pTabControl->Parent = this;
    m_pTabControl->Align = alClient;

    // add tab
    m_pTabControl->Tabs->Add("first_Tab");
    m_pTabControl->Tabs->Add("second_Tab");

	// add frame
	TFrame *frameFirst = new TFrameFirst(this, "frameFist");
	TFrame *frameSecond = new TFrameSecond(this, "frameSecond");

	m_frameVector.push_back(frameFirst);
	m_frameVector.push_back(frameSecond);

	frameFirst = nullptr;
	frameSecond = nullptr;

	/**
	커스텀한 프레임의 경우, 여러번 선언하여 재사용이 가능함.
	재사용을 할 때,  프레임의 Name을 프로그램에서 유일한 이름으로 지정해야 함.
	(유일하지 않을 경우,  A compnent named <Name> is already exists. 예외 발생.)
    (Frame을 선언할 때 사용한 Frame과도 달라야 함.)

	EX)
	new TFrameFirst(this, "frameFist");
    new TFrameSecond(this, "frameSecond");
	*/

    for (int i = 0; i < m_frameVector.size(); ++i) {
        m_frameVector[i]->Parent = m_pTabControl;
		m_frameVector[i]->Align = alClient;
        m_frameVector[i]->Visible = (i == 0); // 첫 번째 탭만 보이도록 설정
    }

    // evnet
    m_pTabControl->OnChange = fnChangeTab;
}

//---------------------------------------------------------------------------

void __fastcall TFormTabbed::fnChangeTab(TObject* Sender)
{
    // 현재 선택된 탭의 인덱스를 가져옵니다.
    int selectedIndex = m_pTabControl->TabIndex;

    // 모든 프레임을 숨깁니다.
    for (int i = 0; i < m_frameVector.size(); ++i) {
        m_frameVector[i]->Visible = false; // 모든 프레임 숨기기
    }

    // 선택된 탭에 해당하는 프레임을 보이도록 설정합니다.
    if (selectedIndex >= 0 && selectedIndex < m_frameVector.size()) {
        m_frameVector[selectedIndex]->Visible = true; // 선택된 프레임 보이기
    }
}
//---------------------------------------------------------------------------

/**
FormCreate: 폼이 생성될 때 호출됩니다. 여기에서 초기화 작업을 수행할 수 있습니다.
FormShow: 폼이 화면에 표시될 때 호출됩니다. UI 관련 초기화 작업을 수행할 수 있습니다.
FormCloseQuery: 사용자가 폼을 닫으려고 할 때 호출됩니다. 이 이벤트에서 CanClose 플래그를 통해 폼의 종료 여부를 제어할 수 있습니다.
FormClose: 폼이 닫힐 때 호출됩니다. 이곳에서 리소스를 정리하거나 최종적인 작업을 수행할 수 있습니다.
FormDestroy: 폼이 파괴될 때 호출됩니다. 여기에서 동적으로 할당된 메모리나 리소스를 해제해야 합니다.
*/
void __fastcall TFormTabbed::FormDestroy(TObject *Sender)
{
	for (size_t i = 0; i < m_frameVector.size(); ++i) {
        if (m_frameVector[i] != nullptr) {
			delete m_frameVector[i];
			m_frameVector[i] = nullptr;
        }
    }
	m_frameVector.clear();

	delete m_pTabControl;
	m_pTabControl = nullptr;
}

//---------------------------------------------------------------------------

