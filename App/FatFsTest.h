#ifndef _FATFSTEST_H_
#define _FATFSTEST_H_

#include "ff.h"
#include <stdint.h>
#include "main.h"

int8_t FatFs_test(void);

void LimeFatFsTester_TraverseSDCardRoot();

int8_t FatFs_checkWriteAndCreatFile(char* filename, uint8_t* data, uint32_t size);

int8_t FatFs_CreateFile(char allFilesName[100], uint8_t* data, uint32_t size);

#endif /* _FATFSTEST_H_ */
