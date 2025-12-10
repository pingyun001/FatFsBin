#include "winHal.h"
#include <stdio.h>
#include <windows.h>
#include <dirent.h>
#include <sys/stat.h>

int32_t checkReadAndCreatFile(char *filename, uint8_t *outBuf, uint32_t size)
{
    FILE* pf = fopen(filename,"r");
	//判断是否打开成功
	if (pf == NULL)
	{
		printf("winHal: open file %s failed\n", filename);
        pf = fopen(filename,"wb+");
		if (pf == NULL)
		{
			printf("winHal: create file %s failed\n", filename);
			return 0;
		}
        printf("winHal: create file %s success\n", filename);
	}
    fseek(pf, 0, SEEK_SET);
    size_t res = fread(outBuf, 1, size, pf);
    printf("winHal: read file %s , length %d, success\n", filename, res);
    fclose(pf);
    return res;
}

int32_t checkWriteAndCreateFile(char *filename, uint8_t *inBuf, uint32_t size)
{
    FILE* pf = fopen(filename,"wb");
    if (pf == NULL)
	{
		perror("fopen");
		return 0;
	}
    size_t res = fwrite(inBuf, 1, size, pf);
    if (res != size)
    {
        perror("fwrite");
        return 0;
    }
    fclose(pf);
    printf("winHal: write file %s , length : %d, success\n", filename, res);
    return 1;
}

int32_t delFile(char *filename)
{
    return remove(filename);
}

void listFiles(char *path)
{
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
 
    // 打开目录
    dir = opendir(path);
    if (dir == NULL)
    {
        printf("can not open dir %s\n", path);
        return;
    }
 
    // 循环读取目录
    while ((entry = readdir(dir)) != NULL) // readdir() 函数在一个循环中使用，以逐个读取目录中的文件和子目录
    {
        // 作用是将一个基本路径 path 和一个文件或子目录的名称 entry->d_name 连接起来，从而创建完整的文件路径，并将其存储在 file_path 字符数组中。同时，它通过使用 sizeof(file_path) 限制了字符串的长度，以确保不会超出 file_path 的大小
        char file_path[1024];
        snprintf(file_path, sizeof(file_path), "%s/%s", path, entry->d_name);
 
        // 获取文件/文件夹信息
        // 检查文件的属性，如文件大小、权限、创建时间等
        if (stat(file_path, &statbuf) == -1)
        {
            continue;
        }
 
        if (S_ISDIR(statbuf.st_mode))
        {  
            // 是文件夹
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) // 检查它是否是特殊目录 .（当前目录）或 ..（上级目录）
            {
                continue; // 忽略当前目录和上级目录
            }
 
            printf("folder: %s\n", entry->d_name);
 
            // traverse_path(file_path); // 递归遍历子文件夹
        }
        else if (S_ISREG(statbuf.st_mode))
        {
            // 是文件
            printf("file: %s\n", entry->d_name);
        }
    }
 
    // 关闭目录
    closedir(dir);
}

void listFilesAndSaveName(char *path, char allFilesName[GLOBAL_FILE_NUM][100])
{
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
    int i = 0;
 
    // 打开目录
    dir = opendir(path);
    if (dir == NULL)
    {
        printf("can not open dir %s\n", path);
        return;
    }
 
    // 循环读取目录
    while ((entry = readdir(dir)) != NULL) // readdir() 函数在一个循环中使用，以逐个读取目录中的文件和子目录
    {
        // 作用是将一个基本路径 path 和一个文件或子目录的名称 entry->d_name 连接起来，从而创建完整的文件路径，并将其存储在 file_path 字符数组中。同时，它通过使用 sizeof(file_path) 限制了字符串的长度，以确保不会超出 file_path 的大小
        char file_path[1024];
        snprintf(file_path, sizeof(file_path), "%s/%s", path, entry->d_name);
 
        // 获取文件/文件夹信息
        // 检查文件的属性，如文件大小、权限、创建时间等
        if (stat(file_path, &statbuf) == -1)
        {
            continue;
        }
 
        if (S_ISDIR(statbuf.st_mode))
        {  
            // 是文件夹
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) // 检查它是否是特殊目录 .（当前目录）或 ..（上级目录）
            {
                continue; // 忽略当前目录和上级目录
            }
 
            // printf("folder: %s\n", entry->d_name);
 
            // traverse_path(file_path); // 递归遍历子文件夹
        }
        else if (S_ISREG(statbuf.st_mode))
        {
            // 是文件
            // printf("file: %s\n", entry->d_name);
            if (i < GLOBAL_FILE_NUM)
            {
                strcpy(allFilesName[i], entry->d_name);
                i++;
            }
        }
    }
 
    // 关闭目录
    closedir(dir);
}

void printNameList(char allFilesName[GLOBAL_FILE_NUM][100])
{
    int i = 0;
    while (i < GLOBAL_FILE_NUM)
    {
        if(allFilesName[i][0] == '\0')
            break;

        printf("nameList[ %d ] = %s\n", i, allFilesName[i]);
        i++;
    }
}

