#include "logicApp.h"
#include "winHal.h"
#include <stdio.h>
#include "FatFsTest.h"


void LogicApp_CopyWinFileToFatFs(char* winFileName, char* fatFsFileName)
{
    uint8_t* tempBuf = malloc(1024*1024*1);
    size_t readLength = 0;
    
    FILE* pf = fopen(winFileName,"rb");
    if(pf == NULL)
    {
        printf(">>>LogicApp_CopyWinFileToFatFs: open file %s fail\n", winFileName);
        return;
    }
    readLength = fread(tempBuf, 1, 1024*1024*1, pf);
    fclose(pf);

    if(readLength > 0)
    {
        printf(">>>%s{ }: Read file from win success, length %d\n", __FUNCTION__,  readLength);

        int ret = FatFs_checkWriteAndCreatFile(fatFsFileName, tempBuf, readLength);
        if(ret == 1)
        {
            printf(">>>%s{ }: Write file to fatfs success\n", __FUNCTION__);
        }
        else
        {
            printf(">>>%s{ }: Write file to fatfs fail\n", __FUNCTION__);
        }
    }
    else
    {
        printf(">>>%s{ }: Read file from win fail, length %d\n", __FUNCTION__, readLength);
    }
    free(tempBuf);
}


void LogicApp_CopyWinFilesToFatFs(char allFilesName[GLOBAL_FILE_NUM][100])
{
    int i = 0;
    for(i = 0; i < GLOBAL_FILE_NUM; i++)
    {
        if(allFilesName[i][0] != '\0')
        {
            printf(">>>%s{ }: Copy file %s to fatfs\n", __FUNCTION__, allFilesName[i]);
            char getFilePath[100] = {0};
            sprintf(getFilePath, "%s/%s", workSpaceOfPackFilePath, allFilesName[i]);
            LogicApp_CopyWinFileToFatFs(getFilePath, allFilesName[i]);
        }
    }
}

