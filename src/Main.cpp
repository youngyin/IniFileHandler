//---------------------------------------------------------------------------

#include <vcl.h>
#include <System.IniFiles.hpp>
#include <System.IOUtils.hpp>
#pragma hdrstop

#include "Main.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------

TFormMain *FormMain;
__fastcall TFormMain::TFormMain(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TFormMain::FormCreate(TObject *Sender)
{
	initThread();
	initStyleComponet();
}

void TFormMain::initThread(){

	TFileMoverThread *fileMoverThread = new TFileMoverThread(true);
	fileMoverThread->Resume();
}

void TFormMain::initStyleComponet(){
	/**
	ssNone: 스크롤 바 없음
	ssVertical: 수직 스크롤 바만 표시
	ssHorizontal: 수평 스크롤 바만 표시
	ssBoth: 수직 및 수평 스크롤 바 모두 표시
	*/
	MmResult->ScrollBars = System::Uitypes::TScrollStyle::ssBoth;
	MmResultMove->ScrollBars = System::Uitypes::TScrollStyle::ssBoth;
}

//---------------------------------------------------------------------------
void __fastcall TFormMain::btnSaveClick(TObject *Sender)
{
	UnicodeString strFolderPath = EdtFolderPath->Text; // 사용자 입력값을 가져옴

    // 경로 유효성 체크
	if (!TDirectory::Exists(strFolderPath)) {
		ShowMessage("유효하지 않은 폴더 경로입니다.");
		return;
	}

	UnicodeString strFilePath = TPath::Combine(strFolderPath, "sample.ini");  //파일 이름 및 경로 생성
	TIniFile* pIniFile = new TIniFile(strFilePath);
	try {
		UnicodeString strSection = "Settings";
		UnicodeString strTestString = "TestString";

		// INI 파일에 값 쓰기
		pIniFile->WriteBool(strSection, "testFalse", false);
		pIniFile->WriteBool(strSection, "testTrue", true);
		pIniFile->WriteDate(strSection, "testDate", TDateTime::CurrentDateTime());
		pIniFile->WriteDateTime(strSection, "testDateTime", TDateTime::CurrentDateTime());
		pIniFile->WriteTime(strSection, "testTime", TDateTime::CurrentDateTime());
		pIniFile->WriteFloat(strSection, "testFloat", 2.13111999999999999999999); //반올림처리됨.
		pIniFile->WriteString(strSection, "testString", strTestString);


        ShowMessage("INI 파일이 성공적으로 저장되었습니다.");

    } catch (const Exception &e) {
        ShowMessage("오류 발생: " + e.Message);

	}

	delete pIniFile; // 항상 메모리 해제
	pIniFile = nullptr;
}
//---------------------------------------------------------------------------


void __fastcall TFormMain::btnOpenFolderVclClick(TObject *Sender)
{
    // Windows API를 사용하여 폴더 선택 다이얼로그 생성
    BROWSEINFO bi = {0};
    bi.lpszTitle = L"폴더를 선택하세요"; // 다이얼로그 제목

    // 폴더 선택 대화 상자 열기
    LPITEMIDLIST pidl = SHBrowseForFolder(&bi);
    if (pidl != NULL)
    {
        TCHAR path[MAX_PATH];
        // 선택된 폴더의 경로 가져오기
        if (SHGetPathFromIDList(pidl, path))
        {
            // 선택된 경로를 TEdit에 표시
            EdtFolderPath->Text = path;
        }
        CoTaskMemFree(pidl); // 메모리 해제
    }
}
//---------------------------------------------------------------------------


void __fastcall TFormMain::BtnOpenFileClick(TObject *Sender)
{
	TOpenDialog *OpenDialog = new TOpenDialog(this);
    OpenDialog->Filter = "INI Files (*.ini)|*.ini|All Files (*.*)|*.*";
    OpenDialog->Title = "Open a File";

    if (OpenDialog->Execute())
    {
        EdtFilePath->Text = OpenDialog->FileName;
    }

	delete OpenDialog;
    OpenDialog = nullptr;
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::BtnReadClick(TObject *Sender)
{
    LblStatus->Caption = "";
	if (EdtFilePath->Text.IsEmpty())
	{
		ShowMessage("파일 경로가 비어 있습니다.");
        return;
    }

    TStringList *FileContent = new TStringList();
	try
	{
		LblStatus->Caption = "파일을 읽는 중...";
        FileContent->LoadFromFile(EdtFilePath->Text);
		MmResult->Lines->Assign(FileContent);
		LblStatus->Caption = "ccomplete!!";
    }
	catch (const Exception &e)
    {
        LblStatus->Caption = "오류 발생: " + e.Message;
		ShowMessage("파일을 읽는 데 오류가 발생했습니다: " + e.Message);
    }

	delete FileContent;
    FileContent = nullptr;
}

//---------------------------------------------------------------------------

void __fastcall TFormMain::BtnResumeMoveThreadClick(TObject *Sender)
{
    int spinnerValue = StrToInt(SpinEditInterval->Text);

	if (spinnerValue <= 0)
    {
        ShowMessage("스피너의 값이 0보다 커야 합니다.");
        return;
    }

	if (m_logThread )
	{
        ShowMessage("logThread is running!!");
        return;
    }

	m_logThread = new TLogThread(MmResultMove, spinnerValue * 60 * 1000);
	try
    {
		m_logThread->Start();
        m_logThread->WaitFor();
	}
    catch (const Exception &e)
    {
		delete m_logThread;
		m_logThread = nullptr;
        ShowMessage("스레드 시작 중 오류 발생: " + e.Message);
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::BtnStopMoveThreadClick(TObject *Sender)
{
    if (m_logThread)
	{
		m_logThread->Stop();
		m_logThread->WaitFor();
		delete m_logThread;
		m_logThread = nullptr;
    }
    else
    {
        ShowMessage("The thread is already stopped.");
	}
}
//---------------------------------------------------------------------------
