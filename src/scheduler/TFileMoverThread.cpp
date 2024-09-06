//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "TFileMoverThread.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TFileMoverThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TFileMoverThread::TFileMoverThread(bool CreateSuspended)
	: TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall TFileMoverThread::Execute()
{
	while (!Terminated) {
		Sleep(1*60*1000); // 1�� ��� (�и���)

        // ���� �̵� �۾�
		String sourcePath = "C:/Users/youngyin/Downloads/mydata/sample.ini"; // ���� ���
        String destPath = "C:/Users/youngyin/Downloads/mydata/old/sample.ini";  // ��� ���

		if (RenameFile(sourcePath, destPath)) {
            Synchronize([=]() {
                ShowMessage("���� �̵� ����!");
            });
        } else {
            Synchronize([=]() {
                ShowMessage("���� �̵� ����!");
            });
        }
    }
}
//---------------------------------------------------------------------------
