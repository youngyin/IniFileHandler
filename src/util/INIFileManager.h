//---------------------------------------------------------------------------

#ifndef INIFileManagerH
#define INIFileManagerH
//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <System.IOUtils.hpp>
#include <System.IniFiles.hpp>
#include <string>
#include <typeindex>
#include <stdexcept>

class INIFileManager {
public:
    enum class DataType {
		Bool,
        DateTime,
		Float,
		String,
        Int
	};

private:
	TIniFile* m_pIniFile;
	String m_strFilePath;
    ~INIFileManager();

public:
	INIFileManager(const String& folderPath, const String& fileName);
    INIFileManager(const String& filePath);

    /** Write */
	void Write(const String& section, const String& key, bool value);
	void Write(const String& section, const String& key, const TDateTime& value);
	void Write(const String& section, const String& key, float value);
	void Write(const String& section, const String& key, const String& value);
	void Write(const String& section, const String& key, const int value);

	/** READ */
	Variant Read(const String& section, const String& key, const DataType dataType = DataType::String);
};

#endif // INIFILEMANAGER_H

