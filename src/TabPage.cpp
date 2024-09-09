/**
* 2024-09-09 PageControl + Frame을 사용한 TabVeiw 예제
*
* [TPageControl]
* TPageControl은 여러 개의 페이지를 관리할 수 있는 컴포넌트로, 각 페이지는 TTabSheet라는 독립적인 컨테이너를 포함합니다.
* 주로 복잡한 사용자 인터페이스를 요구하는 애플리케이션에서 사용되며, 설정 마법사나 다단계 입력 폼 등에서 유용합니다.
*	각 페이지에 다른 UI 요소를 추가하여 다양한 기능을 제공할 수 있습니다.
*/
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TabPage.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FrameIpu"
#pragma link "FrameRemote"
#pragma resource "*.dfm"
TFormTabView *FormTabView;
//---------------------------------------------------------------------------
__fastcall TFormTabView::TFormTabView(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormTabView::N1Click(TObject *Sender)
{
	// Setting ... 클릭시

}
//---------------------------------------------------------------------------

