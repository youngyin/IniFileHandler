//----------------------------------------------------------------------------
#ifndef SettingH
#define SettingH
//----------------------------------------------------------------------------
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Graphics.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <Winapi.Windows.hpp>
#include <System.hpp>
//----------------------------------------------------------------------------
class TDlgSetting : public TForm
{
__published:
	TButton *OKBtn;
	TButton *CancelBtn;
	TBevel *Bevel1;
private:
public:
	virtual __fastcall TDlgSetting(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TDlgSetting *DlgSetting;
//----------------------------------------------------------------------------
#endif    
