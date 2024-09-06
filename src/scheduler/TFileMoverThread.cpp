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
		Sleep(1*60*1000); // 1분 대기 (밀리초)

        // 파일 이동 작업
		String sourcePath = "C:/Users/youngyin/Downloads/mydata/sample.ini"; // 원본 경로
        String destPath = "C:/Users/youngyin/Downloads/mydata/old/sample.ini";  // 대상 경로

		if (RenameFile(sourcePath, destPath)) {
            Synchronize([=]() {
                ShowMessage("파일 이동 성공!");
            });
        } else {
            Synchronize([=]() {
                ShowMessage("파일 이동 실패!");
            });
        }
    }
}
//---------------------------------------------------------------------------
