//---------------------------------------------------------------------------

#include <vcl.h>
#include <System.IniFiles.hpp>
#include <System.IOUtils.hpp>
#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::btnSaveClick(TObject *Sender)
{
	UnicodeString strFolderPath = edtFilePath->Text; // ����� �Է°��� ������

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


void __fastcall TForm1::btnOpenFolderVclClick(TObject *Sender)
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
            edtFilePath->Text = path;
        }
        CoTaskMemFree(pidl); // �޸� ����
    }
}
//---------------------------------------------------------------------------

