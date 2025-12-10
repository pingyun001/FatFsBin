#ifndef __LOGIC_APP_H__
#define __LOGIC_APP_H__

#include <stdint.h>
#include "FatFsTest.h"

void LogicApp_CopyWinFileToFatFs(char* winFileName, char* fatFsFileName);

void LogicApp_CopyWinFilesToFatFs(char allFilesName[GLOBAL_FILE_NUM][100]);

#endif /* __LOGIC_APP_H__ */
