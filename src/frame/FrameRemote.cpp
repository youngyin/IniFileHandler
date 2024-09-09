//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrameRemote.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrameForRemote *FrameForRemote;
//---------------------------------------------------------------------------
__fastcall TFrameForRemote::TFrameForRemote(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------
