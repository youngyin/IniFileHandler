//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Second.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrameSecond* FrameSecond;
//---------------------------------------------------------------------------
__fastcall TFrameSecond::TFrameSecond(TComponent* Owner) : TFrame(Owner)
{
}

__fastcall TFrameSecond::TFrameSecond(TComponent* Owner, const String &strName) : TFrame(Owner)
{
    this->Name = strName;
}
//---------------------------------------------------------------------------

