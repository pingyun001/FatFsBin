/*-----------------------------------------------------------------------*/
/* Low level disk I/O module SKELETON for FatFs     (C)ChaN, 2019        */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control modules to the FatFs module with a defined API.       */
/*-----------------------------------------------------------------------*/

#include "ff.h"			/* Obtains integer types */
#include "diskio.h"		/* Declarations of disk functions */
#include "main.h"
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>
/* Definitions of physical drive number for each drive */
#define SIM_RAM		0	/* Example: Map Ramdisk to physical drive 0 */


const uint32_t sectorSize = 4096;
const uint32_t blockSize = 16;
const uint32_t sectorNum = SIM_BUFFER_SIZE / sectorSize;

/*-----------------------------------------------------------------------*/
/* Get Drive Status                                                      */
/*-----------------------------------------------------------------------*/

DSTATUS disk_status (
	BYTE pdrv		/* Physical drive nmuber to identify the drive */
)
{
	DSTATUS stat;

	switch (pdrv) {
	case SIM_RAM :
		return RES_OK;
	}

	return STA_NOINIT;
}



/*-----------------------------------------------------------------------*/
/* Inidialize a Drive                                                    */
/*-----------------------------------------------------------------------*/

DSTATUS disk_initialize (
	BYTE pdrv				/* Physical drive nmuber to identify the drive */
)
{
	DSTATUS stat;

	switch (pdrv) {
	case SIM_RAM :

		// translate the reslut code here

		return RES_OK;
	}
	return STA_NOINIT;
}



/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */
/*-----------------------------------------------------------------------*/

DRESULT disk_read (
	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
	BYTE *buff,		/* Data buffer to store read data */
	LBA_t sector,	/* Start sector in LBA */
	UINT count		/* Number of sectors to read */
)
{
	DRESULT res;
	int result;

	switch (pdrv) {
	case SIM_RAM :
		// translate the arguments here
		memcpy(buff, simBuffer + sector * sectorSize, sectorSize * count);

		// translate the reslut code here

		return RES_OK;
	}

	return RES_PARERR;
}



/*-----------------------------------------------------------------------*/
/* Write Sector(s)                                                       */
/*-----------------------------------------------------------------------*/

#if FF_FS_READONLY == 0

DRESULT disk_write (
	BYTE pdrv,			/* Physical drive nmuber to identify the drive */
	const BYTE *buff,	/* Data to be written */
	LBA_t sector,		/* Start sector in LBA */
	UINT count			/* Number of sectors to write */
)
{
	DRESULT res;
	int result;

	switch (pdrv) {
	case SIM_RAM :
		
		memcpy(simBuffer + sector * sectorSize, buff, sectorSize * count);

		return RES_OK;
	}

	return RES_PARERR;
}

#endif


/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */
/*-----------------------------------------------------------------------*/

DRESULT disk_ioctl (
	BYTE pdrv,		/* Physical drive nmuber (0..) */
	BYTE cmd,		/* Control code */
	void *buff		/* Buffer to send/receive control data */
)
{
	DRESULT res;
	int result;

	switch (pdrv) {
	case SIM_RAM :
		switch (cmd) {
			case GET_SECTOR_COUNT :
				*(LBA_t*)buff = sectorNum;
				break;

			case GET_SECTOR_SIZE :
				*(WORD*)buff = sectorSize;
				break;

			case GET_BLOCK_SIZE :
				*(WORD*)buff = blockSize;
				break;

			case CTRL_SYNC :
				break;
		}

		return RES_OK;
	}

	return RES_PARERR;
}



DWORD get_fattime(void) {
    SYSTEMTIME st;
    GetSystemTime(&st);  // 获取系统时间

    // FAT时间格式：((Year - 1980) << 25) | (Month << 21) | (Day << 16) |
    //                (Hour << 11) | (Minute << 5) | (Second / 2)

    DWORD fattime = 0;
    
    // 计算 FAT 时间值
    fattime |= ((DWORD)(st.wYear - 1980) << 25);  // Year (1980年为基准)
    fattime |= ((DWORD)(st.wMonth) << 21);        // Month (1-12)
    fattime |= ((DWORD)(st.wDay) << 16);          // Day (1-31)
    fattime |= ((DWORD)(st.wHour) << 11);         // Hour (0-23)
    fattime |= ((DWORD)(st.wMinute) << 5);        // Minute (0-59)
    fattime |= ((DWORD)(st.wSecond / 2));         // Second (0-59, but divided by 2)

    return fattime;
}

