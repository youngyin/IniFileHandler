//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("src\frame\FrameRemote.cpp", Frame_ConfigSetting); /* TFrame: File Type */
USEFORM("src\frame\FrameIpu.cpp", Frame_IpuNet); /* TFrame: File Type */
USEFORM("src\TabPage.cpp", FormTabView);
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
