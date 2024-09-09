//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("src\TabPage.cpp", FormTabView);
USEFORM("src\TabbedMain.cpp", FormTabbed);
USEFORM("src\Main.cpp", FormMain);
USEFORM("src\frame\ThreadTest.cpp", FrameForThread); /* TFrame: File Type */
USEFORM("src\frame\FrameIpu.cpp", FrameIpuNet); /* TFrame: File Type */
USEFORM("src\frame\FrameRemote.cpp", FrameForRemote); /* TFrame: File Type */
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		//Application->MainFormOnTaskBar = true;
		//Application->CreateForm(__classid(TFormMain), &FormMain);
		Application->CreateForm(__classid(TFormTabView), &FormTabView);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
