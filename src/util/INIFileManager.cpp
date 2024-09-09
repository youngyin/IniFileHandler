//---------------------------------------------------------------------------

#pragma hdrstop

#include "INIFileManager.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

INIFileManager::INIFileManager(const String& folderPath, const String& fileName) {
    m_strFilePath = TPath::Combine(folderPath, fileName);
    m_pIniFile = new TIniFile(m_strFilePath);
}

INIFileManager::INIFileManager(const String& filePath) {
	m_strFilePath = filePath;
	m_pIniFile = new TIniFile(m_strFilePath);
}

INIFileManager::~INIFileManager() {
    delete m_pIniFile;
    m_pIniFile = nullptr;
}

//---------------------------------------------------------------------------
void INIFileManager::Write(const String& section, const String& key, bool value) {
    m_pIniFile->WriteBool(section, key, value);
}

void INIFileManager::Write(const String& section, const String& key, const int value) {
    m_pIniFile->WriteInteger(section, key, value);
}

void INIFileManager::Write(const String& section, const String& key, const TDateTime& value) {
	m_pIniFile->WriteDate(section, key, value);
}

void INIFileManager::Write(const String& section, const String& key, float value) {
    m_pIniFile->WriteFloat(section, key, value);
}

void INIFileManager::Write(const String& section, const String& key, const String& value) {
    m_pIniFile->WriteString(section, key, value);
}

//---------------------------------------------------------------------------


