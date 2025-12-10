#include "FatFsTest.h"

#include "ff.h"
#include "diskio.h"
#include <stdio.h>
#include <string.h>

// #define TEST_FILE_CONTENT testPoemString
#define TEST_FILE_CONTENT "hello FatFs!\nhello Megahunt\n"

char testPoemString[] = 
"Once upon the silent night, the world so still and deep,\n \
The stars above began to dance, awakening from their sleep.\n \
A gentle breeze embraced the hills, and whispered to the trees,\n \
Of ancient tales and timeless dreams carried on the seas.\n \
\n \
The moonlit path through forest glades, a silver ribbon bright,\n \
Led wanderers through the shadowed woods, beneath the pale moonlight.\n \
The whispers grew, the forest sang, its song of life and lore,\n \
A melody both vast and soft, that stretched from shore to shore.\n \
\n \
The river gleamed, a mirrored stream, reflecting skies aglow,\n \
It carried stories far and wide, of lands it used to know.\n \
Through valleys deep and mountains tall, its song forever ran,\n \
A witness to the countless dreams and lives of fleeting man.\n \
\n \
Beneath the towering ancient oak, a place of calm and rest,\n \
A poet sat with quill in hand, to pen what he loved best.\n \
Of fleeting clouds and morning dew, of twilight's crimson hue,\n \
He poured his soul into the page, his words both old and new.\n \
\n \
The world itself, a canvas vast, of colors rich and rare,\n \
A masterpiece of fleeting time, beyond what we compare.\n \
And in its folds, a secret lies, for all who dare to seek,\n \
The threads of wonder, love, and joy, that weave the strong and weak.\n \
\n \
The ocean sang a roaring hymn, a chorus wild and free,\n \
Its waves like hands that reached to grasp the heavens' mystery.\n \
The sailor, brave and steadfast still, who sailed that endless blue,\n \
Knew well the call of destiny, and dreams he must pursue.\n \
\n \
Through tempests fierce and skies alight with bolts of lightning's fire,\n \
He charted courses unexplored, each step a new desire.\n \
The wind became his guiding voice, the stars his trusted map,\n \
A navigator bound to fate, wrapped in its endless trap.\n \
\n \
Yet not all journeys lead to gold, nor glory's fleeting fame,\n \
Some find the worth of quiet hearts, and love that lights the flame.\n \
Among the meadows vast and green, where daisies bend and sway,\n \
The wanderer finds a peace within, that nothing takes away.\n \
\n \
The poet closed his weathered tome, the quill set softly down,\n \
The moon descended past the hills, its light behind the town.\n \
Yet in his words, the night remained, immortal and serene,\n \
A testament to worlds unseen, and all that lies between.\n \
\n \
So take these words and let them guide, to realms of endless dreams,\n \
Where mountains rise and rivers flow, and sunlight softly gleams.\n \
Beyond the bounds of what you know, the world will always show,\n \
That life itself's a poem vast, with endless paths to go.\n \
The stars above began to dance, awakening from their sleep.\n \
A gentle breeze embraced the hills, and whispered to the trees,\n \
Of ancient tales and timeless dreams carried on the seas.\n \
\n \
The moonlit path through forest glades, a silver ribbon bright,\n \
Led wanderers through the shadowed woods, beneath the pale moonlight.\n \
The whispers grew, the forest sang, its song of life and lore,\n \
A melody both vast and soft, that stretched from shore to shore.\n \
\n \
The river gleamed, a mirrored stream, reflecting skies aglow,\n \
It carried stories far and wide, of lands it used to know.\n \
Through valleys deep and mountains tall, its song forever ran,\n \
A witness to the countless dreams and lives of fleeting man.\n \
\n \
Beneath the towering ancient oak, a place of calm and rest,\n \
A poet sat with quill in hand, to pen what he loved best.\n \
Of fleeting clouds and morning dew, of twilight's crimson hue,\n \
He poured his soul into the page, his words both old and new.\n \
\n \
The world itself, a canvas vast, of colors rich and rare,\n \
A masterpiece of fleeting time, beyond what we compare.\n \
And in its folds, a secret lies, for all who dare to seek,\n \
The threads of wonder, love, and joy, that weave the strong and weak.\n \
\n \
The ocean sang a roaring hymn, a chorus wild and free,\n \
Its waves like hands that reached to grasp the heavens' mystery.\n \
The sailor, brave and steadfast still, who sailed that endless blue,\n \
Knew well the call of destiny, and dreams he must pursue.\n \
\n \
Through tempests fierce and skies alight with bolts of lightning's fire,\n \
He charted courses unexplored, each step a new desire.\n \
The wind became his guiding voice, the stars his trusted map,\n \
A navigator bound to fate, wrapped in its endless trap.\n \
\n \
Yet not all journeys lead to gold, nor glory's fleeting fame,\n \
Some find the worth of quiet hearts, and love that lights the flame.\n \
Among the meadows vast and green, where daisies bend and sway,\n \
The wanderer finds a peace within, that nothing takes away.\n \
\n \
The poet closed his weathered tome, the quill set softly down,\n \
The moon descended past the hills, its light behind the town.\n \
Yet in his words, the night remained, immortal and serene,\n \
A testament to worlds unseen, and all that lies between.\n \
\n \
So take these words and let them guide, to realms of endless dreams,\n \
Where mountains rise and rivers flow, and sunlight softly gleams.\n \
Beyond the bounds of what you know, the world will always show,\n \
That life itself's a poem vast, with endless paths to go.\n \
The stars above began to dance, awakening from their sleep.\n \
A gentle breeze embraced the hills, and whispered to the trees,\n \
Of ancient tales and timeless dreams carried on the seas.\n \
\n \
The moonlit path through forest glades, a silver ribbon bright,\n \
Led wanderers through the shadowed woods, beneath the pale moonlight.\n \
The whispers grew, the forest sang, its song of life and lore,\n \
A melody both vast and soft, that stretched from shore to shore.\n \
\n \
The river gleamed, a mirrored stream, reflecting skies aglow,\n \
It carried stories far and wide, of lands it used to know.\n \
Through valleys deep and mountains tall, its song forever ran,\n \
A witness to the countless dreams and lives of fleeting man.\n \
\n \
Beneath the towering ancient oak, a place of calm and rest,\n \
A poet sat with quill in hand, to pen what he loved best.\n \
Of fleeting clouds and morning dew, of twilight's crimson hue,\n \
He poured his soul into the page, his words both old and new.\n \
\n \
The world itself, a canvas vast, of colors rich and rare,\n \
A masterpiece of fleeting time, beyond what we compare.\n \
And in its folds, a secret lies, for all who dare to seek,\n \
The threads of wonder, love, and joy, that weave the strong and weak.\n \
\n \
The ocean sang a roaring hymn, a chorus wild and free,\n \
Its waves like hands that reached to grasp the heavens' mystery.\n \
The sailor, brave and steadfast still, who sailed that endless blue,\n \
Knew well the call of destiny, and dreams he must pursue.\n \
\n \
Through tempests fierce and skies alight with bolts of lightning's fire,\n \
He charted courses unexplored, each step a new desire.\n \
The wind became his guiding voice, the stars his trusted map,\n \
A navigator bound to fate, wrapped in its endless trap.\n \
\n \
Yet not all journeys lead to gold, nor glory's fleeting fame,\n \
Some find the worth of quiet hearts, and love that lights the flame.\n \
Among the meadows vast and green, where daisies bend and sway,\n \
The wanderer finds a peace within, that nothing takes away.\n \
\n \
The poet closed his weathered tome, the quill set softly down,\n \
The moon descended past the hills, its light behind the town.\n \
Yet in his words, the night remained, immortal and serene,\n \
A testament to worlds unseen, and all that lies between.\n \
\n \
So take these words and let them guide, to realms of endless dreams,\n \
Where mountains rise and rivers flow, and sunlight softly gleams.\n \
Beyond the bounds of what you know, the world will always show,\n \
That life itself's a poem vast, with endless paths to go.\n \
The stars above began to dance, awakening from their sleep.\n \
A gentle breeze embraced the hills, and whispered to the trees,\n \
Of ancient tales and timeless dreams carried on the seas.\n \
\n \
The moonlit path through forest glades, a silver ribbon bright,\n \
Led wanderers through the shadowed woods, beneath the pale moonlight.\n \
The whispers grew, the forest sang, its song of life and lore,\n \
A melody both vast and soft, that stretched from shore to shore.\n \
\n \
The river gleamed, a mirrored stream, reflecting skies aglow,\n \
It carried stories far and wide, of lands it used to know.\n \
Through valleys deep and mountains tall, its song forever ran,\n \
A witness to the countless dreams and lives of fleeting man.\n \
\n \
Beneath the towering ancient oak, a place of calm and rest,\n \
A poet sat with quill in hand, to pen what he loved best.\n \
Of fleeting clouds and morning dew, of twilight's crimson hue,\n \
He poured his soul into the page, his words both old and new.\n \
\n \
The world itself, a canvas vast, of colors rich and rare,\n \
A masterpiece of fleeting time, beyond what we compare.\n \
And in its folds, a secret lies, for all who dare to seek,\n \
The threads of wonder, love, and joy, that weave the strong and weak.\n \
\n \
The ocean sang a roaring hymn, a chorus wild and free,\n \
Its waves like hands that reached to grasp the heavens' mystery.\n \
The sailor, brave and steadfast still, who sailed that endless blue,\n \
Knew well the call of destiny, and dreams he must pursue.\n \
\n \
Through tempests fierce and skies alight with bolts of lightning's fire,\n \
He charted courses unexplored, each step a new desire.\n \
The wind became his guiding voice, the stars his trusted map,\n \
A navigator bound to fate, wrapped in its endless trap.\n \
\n \
Yet not all journeys lead to gold, nor glory's fleeting fame,\n \
Some find the worth of quiet hearts, and love that lights the flame.\n \
Among the meadows vast and green, where daisies bend and sway,\n \
The wanderer finds a peace within, that nothing takes away.\n \
\n \
The poet closed his weathered tome, the quill set softly down,\n \
The moon descended past the hills, its light behind the town.\n \
Yet in his words, the night remained, immortal and serene,\n \
A testament to worlds unseen, and all that lies between.\n \
\n \
So take these words and let them guide, to realms of endless dreams,\n \
Where mountains rise and rivers flow, and sunlight softly gleams.\n \
Beyond the bounds of what you know, the world will always show,\n \
That life itself's a poem vast, with endless paths to go.\n \
";


FATFS FatFs;                    // FatFs 文件系统对象
FIL fil;                        // 文件对象
FRESULT fr;                     // 文件操作返回结果
char buffer[100];               // 用于读取文件的缓冲区
char mkfsBuffer[4096] = {0};

int8_t FatFs_test(void)
{
    // 挂载磁盘编号 0 的文件系统
    fr = f_mount(&FatFs, "0:", 1);
    if (fr != FR_OK) {
        printf("Mount failed with error code: %d\n", fr);
        printf("Attempting to create new file system...\n");

        // 格式化磁盘 0，创建新的文件系统
        fr = f_mkfs("0:", 0, mkfsBuffer, FF_MAX_SS);  // 格式化为 FAT32 文件系统
        if (fr != FR_OK) {
            printf("File system creation failed with error code: %d\n", fr);
            return 0;
        }
        printf("File system created successfully.\n");

        // 重新挂载文件系统
        fr = f_mount(&FatFs, "0:", 1);  
        if (fr != FR_OK) {
            printf("Mount failed twice with error code: %d\n", fr);
            return 0;
        }
    } else {
        printf("File system mounted successfully.\n");
    }

    // 尝试打开文件 "test.txt"
    fr = f_open(&fil, "0:test.txt", FA_READ);  
    if (fr == FR_OK) {
        // 如果文件存在，则读取文件内容
        printf("File opened for reading.\n");

        // 读取文件内容
        unsigned int bytesRead;
        fr = f_read(&fil, buffer, sizeof(buffer) - 1, &bytesRead);  
        if (fr != FR_OK) {
            printf("File read failed with error code: %d\n", fr);
            f_close(&fil);
            f_mount(NULL, "", 1);  // 卸载文件系统
            return 0;
        }
        buffer[bytesRead] = '\0';  // 确保读取的数据以'\0'结尾
        printf("Read data: %s\n", buffer);

        // 关闭文件
        f_close(&fil);

    } else if (fr == FR_NO_FILE) {
        // 如果文件不存在，则创建并写入内容
        printf("File not found. Creating new file...\n");

        // 创建文件并打开
        fr = f_open(&fil, "0:test.txt", FA_CREATE_ALWAYS | FA_WRITE);  
        if (fr != FR_OK) {
            printf("File creation failed with error code: %d\n", fr);
            f_mount(NULL, "", 1);  // 卸载文件系统
            return 0;
        }
        printf("File created successfully.\n");

        // 向文件写入数据
        const char *data = TEST_FILE_CONTENT;
        unsigned int bytesWritten;
        fr = f_write(&fil, data, strlen(data), &bytesWritten);  
        if (fr != FR_OK || bytesWritten != strlen(data)) {
            printf("File write failed with error code: %d\n", fr);
            f_close(&fil);
            f_mount(NULL, "", 1);  // 卸载文件系统
            return 0;
        }
        printf("Data written to file successfully.\n");

        // 关闭文件
        f_close(&fil);
    } else {
        printf("File open failed with error code: %d\n", fr);
        f_mount(NULL, "", 1);  // 卸载文件系统
        return 0;
    }

    // 卸载文件系统
    f_mount(NULL, "0", 1);  
    printf("File system unmounted.\n");
    return 1;
}

//扫描根目录下所有文件并打印出来
void LimeFatFsTester_TraverseSDCardRoot(void) 
{
    FATFS fs = {0};             // 文件系统对象
    DIR dir = {0};              // 目录对象
    FILINFO fno = {0};          // 文件信息对象
    FRESULT res = 0;            // FatFs函数结果

    res = f_mount(&fs, "0:", 1);
    if (res == FR_OK) 
    {
        res = f_opendir(&dir, "0:");
        if (res == FR_OK) 
        {
            // 读取目录中的每个条目
            while ((res = f_readdir(&dir, &fno)) == FR_OK && fno.fname[0]) 
            {
                // 如果是文件或文件夹，则打印名称
                if (fno.fattrib & AM_DIR) 
                {
                    printf("DIR: %s\n", fno.fname);
                } 
                else 
                {
                    printf("FILE: %s, size:%d bytes\n", fno.fname, (int)fno.fsize);
                }
            }
            f_closedir(&dir);
        } 
        else 
        {
            printf("Failed to open root directory!\n");
        }
        f_mount(NULL, "0:", 1);
        printf("ScanFinish\n");
    } 
    else 
    {
        printf("Failed to mount SD card!\n");
    }
}

int8_t FatFs_checkWriteAndCreatFile(char* filename, uint8_t* data, uint32_t size)
{
    FATFS fs = {0};             // 文件系统对象
    FIL fil = {0};              // 文件对象
    FRESULT res = 0;            // FatFs函数结果

    res = f_mount(&fs, "0:", 1);
    if (res == FR_OK) 
    {
        // 尝试打开文件
        res = f_open(&fil, filename, FA_WRITE | FA_CREATE_ALWAYS);
        if (res == FR_OK) 
        {
            // 写入数据
            unsigned int bytesWritten;
            res = f_write(&fil, data, size, &bytesWritten);
            if (res == FR_OK && bytesWritten == size) 
            {
                printf("FatFs:Data written to file successfully.\n");
            }
            else 
            {
                printf("FatFs:File write failed with error code: %d\n", res);
            }
            // 关闭文件
            f_close(&fil);
        } 
        else if (res == FR_NO_FILE) 
        {
            printf("FatFs:File not found. Creating new file...\n");
            // 创建文件并打开
            res = f_open(&fil, filename, FA_CREATE_ALWAYS | FA_WRITE);
            if (res == FR_OK) 
            {
                // 写入数据
                unsigned int bytesWritten;
                res = f_write(&fil, data, size, &bytesWritten);
                if (res == FR_OK && bytesWritten == size) 
                {
                    printf("FatFs:Data written to file successfully.\n");
                }
                else 
                {
                    printf("FatFs:File write failed with error code: %d\n", res);
                }
                // 关闭文件
                f_close(&fil);
            } 
            else 
            {
                printf("FatFs:File creation failed with error code: %d\n", res);
            }
        } 
        else 
        {
            printf("FatFs:File open failed with error code: %d\n", res);
        }
        f_mount(NULL, "0:", 1);
        return 1;
    } 
    else 
    {
        printf("FatFs:Failed to mount SD card!\n");
        return 0;
    }
}

#include "ff.h"
#include "string.h"
#include <stdio.h>

int8_t FatFs_CreateFile(char allFilesName[100], uint8_t* data, uint32_t size) {
    FIL fil;               // 文件对象
    FRESULT fr;            // FatFs 返回值
    uint32_t bytesWritten; // 写入字节数

    // 1. 尝试打开文件，如果文件存在，删除它
    fr = f_open(&fil, allFilesName, FA_READ);
    if (fr == FR_OK) {
        // 文件存在，先关闭文件，然后删除
        f_close(&fil);
        fr = f_unlink(allFilesName);  // 删除文件
        if (fr != FR_OK) {
            printf("Error deleting file: %d\n", fr);
            return 0;  // 删除失败，返回 0
        }
        printf("File %s deleted successfully.\n", allFilesName);
    }

    // 2. 创建新文件并打开（如果文件不存在，直接创建）
    fr = f_open(&fil, allFilesName, FA_CREATE_ALWAYS | FA_WRITE);
    if (fr != FR_OK) {
        printf("Error opening/creating file: %d\n", fr);
        return 0;  // 文件创建失败，返回 0
    }
    printf("File %s created successfully.\n", allFilesName);

    // 3. 写入数据到文件
    fr = f_write(&fil, data, size, &bytesWritten);
    if (fr != FR_OK || bytesWritten != size) {
        printf("Error writing to file: %d\n", fr);
        f_close(&fil);
        return 0;  // 写入失败，返回 0
    }
    printf("Data written to file successfully. Bytes written: %lu\n", bytesWritten);

    // 4. 关闭文件
    f_close(&fil);

    return 1;  // 成功返回 1
}

