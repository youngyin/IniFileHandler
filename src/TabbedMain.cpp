//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>

// 사용자 정의 class
# include "src\frame\First.h"
# include "src\frame\Second.h"

#pragma hdrstop

#include "TabbedMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TFormTabbed* FormTabbed;
TTabControl* m_pTabControl;
std::vector<TFrame*> m_frameVector;

//---------------------------------------------------------------------------
__fastcall TFormTabbed::TFormTabbed(TComponent* Owner) : TForm(Owner)
{
    m_pTabControl = new TTabControl(this);
    m_pTabControl->Parent = this; // 메인 폼에 추가
    m_pTabControl->Align = alClient; // 클라이언트 영역에 맞추기

    // 탭 추가
	m_pTabControl->Tabs->Add("first_Tab");
    m_pTabControl->Tabs->Add("second_Tab");

	// 프레임 추가.
	m_frameVector.push_back(new TFrameFirst(this));
	m_frameVector.push_back(new TFrameSecond(this));

	for (int i = 0; i < m_frameVector.size(); ++i) {
		m_frameVector[i]->Parent = m_pTabControl;
		m_frameVector[i]->Align = alClient; // 탭에 맞추기
		m_frameVector[i]->Visible = (i == 0); // 첫 번째 탭만 보이도록 설정
    }

	//
	m_pTabControl->OnChange = fnChangeTab;
}
//---------------------------------------------------------------------------

void __fastcall TFormTabbed::fnChangeTab(TObject *Sender)
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

