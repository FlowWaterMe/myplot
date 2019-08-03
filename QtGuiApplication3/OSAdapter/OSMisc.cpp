#include <OSMisc.h>
#include <Windows.h>

//�����ļ���Ŀ¼ΪNormal���ԣ���Ҫ��Ϊ�˷�ֹֻ����
BOOL VAZSetFileAttrNomal(const TCHAR* psFile)
{
	if(psFile==NULL) return -2;

	DWORD dwFileAttributes = FILE_ATTRIBUTE_NORMAL; 
	return SetFileAttributes(psFile, dwFileAttributes);
}

int VAZRemoveFile(const tchar* psFile)
{
	if(psFile==NULL) return -2;

	VAZSetFileAttrNomal(psFile);
	//if(_tunlink(psFile)!=0) return -1;
	if(!DeleteFile(psFile)) return -1;
	return 0;
}

int VAZRenameFile(const tchar* psFileOld, const TCHAR* psFileNew)
{
	if(psFileOld==NULL || psFileNew==NULL) return -2;

	if(MoveFile(psFileOld, psFileNew)) return 0;
	return -1;
}

bool VAZMoveFile(const tchar* lpExistingFileName,const tchar* lpNewFileName,unsigned long dwFlags)
{
	return MoveFileEx( lpExistingFileName, lpNewFileName, dwFlags);
}

bool VAZCopyFile(const tchar* lpExistingFileName,const tchar* lpNewFileName,bool bFailIfExists)
{
	return CopyFile( lpExistingFileName, lpNewFileName, bFailIfExists);	
}