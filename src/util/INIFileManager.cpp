//---------------------------------------------------------------------------

#pragma hdrstop

#include "INIFileManager.h"
#include <vcl.h>

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


//overwriting---------------------------------------------------------------------------
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

Variant INIFileManager::Read(const String& section, const String& key, const DataType dataType) {
		UnicodeString strUnicodeString = "readNotString";

		switch (dataType) {
			case DataType::String:
				return m_pIniFile->ReadString(section, key, strUnicodeString);
			case DataType::Int:
				return m_pIniFile->ReadInteger(section, key, 0);
			case DataType::Float:
				return m_pIniFile->ReadFloat(section, key, 0);
			case DataType::Bool:
				return m_pIniFile->ReadBool(section, key, false);
			case DataType::DateTime:
				return m_pIniFile->ReadDateTime(section, key, 0);
			default:
				throw Exception("Unsupported type");
		}
	}



