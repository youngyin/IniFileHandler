//---------------------------------------------------------------------------

#pragma hdrstop

#include "INIFileManager.h"
#include <string>
#include <typeindex>
#include <stdexcept>
//---------------------------------------------------------------------------
#pragma package(smart_init)

INIFileManager::INIFileManager(const String& folderPath, const String& fileName) {
    m_strFilePath = TPath::Combine(folderPath, fileName);
    m_pIniFile = new TIniFile(m_strFilePath);
}

INIFileManager::~INIFileManager() {
    delete m_pIniFile;
    m_pIniFile = nullptr;
}

void INIFileManager::Write(const String& section, const String& key, bool value) {
    m_pIniFile->WriteBool(section, key, value);
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

template <typename T>
T INIFileManager::Read(const String& section, const String& key, const T& defaultValue) {
	std::type_index typeIndex = std::type_index(typeid(T));

    if (typeIndex == std::type_index(typeid(bool))) {
        return static_cast<T>(m_pIniFile->ReadBool(section, key, defaultValue == true));
	}
	else if (typeIndex == std::type_index(typeid(int))) {
		return m_pIniFile->ReadInteger(section, key, defaultValue);
	}
    else if (typeIndex == std::type_index(typeid(__int64))) {
		return m_pIniFile->ReadInt64(section, key, defaultValue);
	}
    else if (typeIndex == std::type_index(typeid(System::UnicodeString))) {
		return m_pIniFile->ReadString(section, key, defaultValue);
	}
    else if (typeIndex == std::type_index(typeid(double))) {
        return static_cast<T>(m_pIniFile->ReadFloat(section, key, defaultValue));
    }
    else if (typeIndex == std::type_index(typeid(TDateTime))) {
        return m_pIniFile->ReadDateTime(section, key, defaultValue);
    }
    else {
        throw std::invalid_argument("Unsupported type");
	}
}
