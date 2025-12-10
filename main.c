#include "main.h"
#include <stdio.h>
#include "FatFsTest.h"
#include "winHal.h"
#include "logicApp.h"
#include "winSerial.h"

uint8_t simBuffer[SIM_BUFFER_SIZE] = {0};

char *workSpaceOfPackFilePath = "../workingSpace/filesToBePackd";  
char allFilesName[GLOBAL_FILE_NUM][100] = {0};


int main()
{
    delFile("../workingSpace/fsft.bin");

    //加载FatFs固件
    checkReadAndCreatFile("../workingSpace/fsft.bin", simBuffer, SIM_BUFFER_SIZE);

    //对FatFs固件进行读写测试，同时若没有FatFs系统，则新建
    int8_t res = FatFs_test();

    //扫描工作树
    listFilesAndSaveName(workSpaceOfPackFilePath, allFilesName);
    printNameList(allFilesName);

    //将工作树中的文件复制到FatFs固件
    LogicApp_CopyWinFilesToFatFs(allFilesName);
    
    //扫FatFs固件，确认写入
    LimeFatFsTester_TraverseSDCardRoot();

    if(res == 1)
    {   //测试通过，导出固件
        checkWriteAndCreateFile("../workingSpace/fsft.bin", simBuffer, SIM_BUFFER_SIZE);
    }

    //将固件发送到STM32
    // res = winSerial_Open(6, 921600);
    // if (res == 1)
    // {
    //     winSerial_SendBuffAndWaitAck(simBuffer, SIM_BUFFER_SIZE);
    //     winSerial_Close();
    // }
    

    return 0;
}

