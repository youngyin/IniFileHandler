//---------------------------------------------------------------------------

#ifndef TFileMoverThreadH
#define TFileMoverThreadH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class TFileMoverThread : public TThread
{
private:
protected:
	void __fastcall Execute();
public:
	__fastcall TFileMoverThread(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
