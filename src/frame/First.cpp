//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "First.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrameFirst* FrameFirst;
//---------------------------------------------------------------------------
__fastcall TFrameFirst::TFrameFirst(TComponent* Owner) : TFrame(Owner)
{

}

__fastcall TFrameFirst::TFrameFirst(TComponent* Owner, const String &strName) : TFrame(Owner)
{
    this->Name = strName;
}
//---------------------------------------------------------------------------

