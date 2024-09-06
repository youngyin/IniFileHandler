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
	ssNone: ��ũ�� �� ����
	ssVertical: ���� ��ũ�� �ٸ� ǥ��
	ssHorizontal: ���� ��ũ�� �ٸ� ǥ��
	ssBoth: ���� �� ���� ��ũ�� �� ��� ǥ��
	*/
	MmResult->ScrollBars = System::Uitypes::TScrollStyle::ssBoth;
	MmResultMove->ScrollBars = System::Uitypes::TScrollStyle::ssBoth;
}

//---------------------------------------------------------------------------
void __fastcall TFormMain::btnSaveClick(TObject *Sender)
{
	UnicodeString strFolderPath = EdtFolderPath->Text; // ����� �Է°��� ������

    // ��� ��ȿ�� üũ
	if (!TDirectory::Exists(strFolderPath)) {
		ShowMessage("��ȿ���� ���� ���� ����Դϴ�.");
		return;
	}

	UnicodeString strFilePath = TPath::Combine(strFolderPath, "sample.ini");  //���� �̸� �� ��� ����
	TIniFile* pIniFile = new TIniFile(strFilePath);
	try {
		UnicodeString strSection = "Settings";
		UnicodeString strTestString = "TestString";

		// INI ���Ͽ� �� ����
		pIniFile->WriteBool(strSection, "testFalse", false);
		pIniFile->WriteBool(strSection, "testTrue", true);
		pIniFile->WriteDate(strSection, "testDate", TDateTime::CurrentDateTime());
		pIniFile->WriteDateTime(strSection, "testDateTime", TDateTime::CurrentDateTime());
		pIniFile->WriteTime(strSection, "testTime", TDateTime::CurrentDateTime());
		pIniFile->WriteFloat(strSection, "testFloat", 2.13111999999999999999999); //�ݿø�ó����.
		pIniFile->WriteString(strSection, "testString", strTestString);


        ShowMessage("INI ������ ���������� ����Ǿ����ϴ�.");

    } catch (const Exception &e) {
        ShowMessage("���� �߻�: " + e.Message);

	}

	delete pIniFile; // �׻� �޸� ����
	pIniFile = nullptr;
}
//---------------------------------------------------------------------------


void __fastcall TFormMain::btnOpenFolderVclClick(TObject *Sender)
{
    // Windows API�� ����Ͽ� ���� ���� ���̾�α� ����
    BROWSEINFO bi = {0};
    bi.lpszTitle = L"������ �����ϼ���"; // ���̾�α� ����

    // ���� ���� ��ȭ ���� ����
    LPITEMIDLIST pidl = SHBrowseForFolder(&bi);
    if (pidl != NULL)
    {
        TCHAR path[MAX_PATH];
        // ���õ� ������ ��� ��������
        if (SHGetPathFromIDList(pidl, path))
        {
            // ���õ� ��θ� TEdit�� ǥ��
            EdtFolderPath->Text = path;
        }
        CoTaskMemFree(pidl); // �޸� ����
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
		ShowMessage("���� ��ΰ� ��� �ֽ��ϴ�.");
        return;
    }

    TStringList *FileContent = new TStringList();
	try
	{
		LblStatus->Caption = "������ �д� ��...";
        FileContent->LoadFromFile(EdtFilePath->Text);
		MmResult->Lines->Assign(FileContent);
		LblStatus->Caption = "ccomplete!!";
    }
	catch (const Exception &e)
    {
        LblStatus->Caption = "���� �߻�: " + e.Message;
		ShowMessage("������ �д� �� ������ �߻��߽��ϴ�: " + e.Message);
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
        ShowMessage("���ǳ��� ���� 0���� Ŀ�� �մϴ�.");
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
        ShowMessage("������ ���� �� ���� �߻�: " + e.Message);
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
