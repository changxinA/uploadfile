#include "SysUtil.h"
//-----------------------------------------------------------------
DWORD GetSizeOfFile(LPCTSTR FileName)
{
	WIN32_FIND_DATA FindData;
	HANDLE  h= FindFirstFile(FileName, &FindData);
	if (h != INVALID_HANDLE_VALUE )
	{
		FindClose(h);
		//ÎÄ¼þ±ØÐë < 4G
		return FindData.nFileSizeLow;
	}else
		return 0;
}
//-----------------------------------------------------------------
bool IsDirExist(const char *dir){
	DWORD ret = GetFileAttributesA(dir);
	return ((ret!=INVALID_FILE_ATTRIBUTES)&&(ret&FILE_ATTRIBUTE_DIRECTORY)!=0);
}
//-----------------------------------------------------------------
bool IsFileExist(const char *dir){
	DWORD ret = GetFileAttributesA(dir);
	return ret!=INVALID_FILE_ATTRIBUTES;
}
/*add hotspot by changxin 2019-1-6 below*/
void printfile(const char* str)
{
	print("%s",str);
}
/*add hotspot by changxin 2019-1-6 above*/