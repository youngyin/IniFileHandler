//---------------------------------------------------------------------------

#ifndef INIFileManagerH
#define INIFileManagerH
//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <System.IOUtils.hpp>
#include <System.IniFiles.hpp>

class INIFileManager {
public:
private:
	TIniFile* m_pIniFile;
	String m_strFilePath;
    ~INIFileManager();

public:
    INIFileManager(const String& folderPath, const String& fileName);


    void Write(const String& section, const String& key, bool value);
    void Write(const String& section, const String& key, const TDateTime& value);
    void Write(const String& section, const String& key, float value);
    void Write(const String& section, const String& key, const String& value);

	template <typename T>
	T Read(const String& section, const String& key, const T& defaultValue);
};

#endif // INIFILEMANAGER_H

