#include "../QtGuiApplication3/GlobalDefine.h"
#include "osadapter_global.h"

int OSADAPTER_EXPORT VAZRemoveFile(const tchar * psFile);
int OSADAPTER_EXPORT VAZRenameFile(const tchar* psFileOld, const tchar* psFileNew);

#define MOVEFILE_REPLACE_EXISTING       0x00000001
#define MOVEFILE_COPY_ALLOWED           0x00000002
#define MOVEFILE_DELAY_UNTIL_REBOOT     0x00000004
#define MOVEFILE_WRITE_THROUGH          0x00000008
bool OSADAPTER_EXPORT VAZMoveFile(const tchar* lpExistingFileName,const tchar* lpNewFileName,unsigned long dwFlags);
bool OSADAPTER_EXPORT VAZCopyFile(const tchar* lpExistingFileName,const tchar* lpNewFileName,bool bFailIfExists);


