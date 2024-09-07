//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>

// ����� ���� class
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
    m_pTabControl->Parent = this; // ���� ���� �߰�
    m_pTabControl->Align = alClient; // Ŭ���̾�Ʈ ������ ���߱�

    // �� �߰�
	m_pTabControl->Tabs->Add("first_Tab");
    m_pTabControl->Tabs->Add("second_Tab");

	// ������ �߰�.
	m_frameVector.push_back(new TFrameFirst(this));
	m_frameVector.push_back(new TFrameSecond(this));

	for (int i = 0; i < m_frameVector.size(); ++i) {
		m_frameVector[i]->Parent = m_pTabControl;
		m_frameVector[i]->Align = alClient; // �ǿ� ���߱�
		m_frameVector[i]->Visible = (i == 0); // ù ��° �Ǹ� ���̵��� ����
    }

	//
	m_pTabControl->OnChange = fnChangeTab;
}
//---------------------------------------------------------------------------

void __fastcall TFormTabbed::fnChangeTab(TObject *Sender)
{
    // ���� ���õ� ���� �ε����� �����ɴϴ�.
    int selectedIndex = m_pTabControl->TabIndex;

    // ��� �������� ����ϴ�.
    for (int i = 0; i < m_frameVector.size(); ++i) {
        m_frameVector[i]->Visible = false; // ��� ������ �����
    }

    // ���õ� �ǿ� �ش��ϴ� �������� ���̵��� �����մϴ�.
    if (selectedIndex >= 0 && selectedIndex < m_frameVector.size()) {
        m_frameVector[selectedIndex]->Visible = true; // ���õ� ������ ���̱�
    }
}

