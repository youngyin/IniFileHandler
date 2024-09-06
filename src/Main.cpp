//---------------------------------------------------------------------------

#include <vcl.h>
#include <System.IniFiles.hpp>
#include <System.IOUtils.hpp>
#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
	: TForm(Owner)
{
	FnsettingMmResult();
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

	UnicodeString strFilePath = TPath::Combine(strFolderPath, "sample.ini");
    TIniFile* pIniFile = new TIniFile(strFilePath);
    try {
        UnicodeString strSection = "Settings";

        // INI ���Ͽ� �� ����
        pIniFile->WriteBool(strSection, "testFalse", false);
        pIniFile->WriteBool(strSection, "testTrue", true);
        pIniFile->WriteDate(strSection, "testDate", TDateTime::CurrentDateTime());
        pIniFile->WriteDateTime(strSection, "testDateTime", TDateTime::CurrentDateTime());
        pIniFile->WriteTime(strSection, "testTime", TDateTime::CurrentDateTime());
        pIniFile->WriteFloat(strSection, "testFloat", 2.13111999999999999999999); //�ݿø�ó����.

        ShowMessage("INI ������ ���������� ����Ǿ����ϴ�.");

    } catch (const Exception &e) {
        ShowMessage("���� �߻�: " + e.Message);

	}

	delete pIniFile; // �׻� �޸� ����
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
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::BtnReadClick(TObject *Sender)
{
    if (EdtFilePath->Text.IsEmpty())
    {
        ShowMessage("���� ��ΰ� ��� �ֽ��ϴ�.");
        return;
    }

    TStringList *FileContent = new TStringList();
    try
    {
        FileContent->LoadFromFile(EdtFilePath->Text);
		MmResult->Lines->Assign(FileContent);
    }
    catch (const Exception &e)
    {
        ShowMessage("������ �д� �� ������ �߻��߽��ϴ�: " + e.Message);
    }

    delete FileContent;
}

void TFormMain::FnsettingMmResult() {
	/**
	ssNone: ��ũ�� �� ����
	ssVertical: ���� ��ũ�� �ٸ� ǥ��
	ssHorizontal: ���� ��ũ�� �ٸ� ǥ��
	ssBoth: ���� �� ���� ��ũ�� �� ��� ǥ��
	*/
	MmResult->ScrollBars = System::Uitypes::TScrollStyle::ssBoth;
}
//---------------------------------------------------------------------------

