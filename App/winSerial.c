#include "winSerial.h"
#include <windows.h>
#include <stdio.h>

HANDLE hSerial = NULL;
int8_t winSerial_Open(uint8_t port, uint32_t baudrate)
{
    char portName[10];
    sprintf(portName, "COM%d", port);
    hSerial = CreateFile(portName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
    if (hSerial == INVALID_HANDLE_VALUE)
    {
        printf("Error: Cannot open serial port %s\n", portName);
        return 0;
    }
    DCB dcb;
    if (!GetCommState(hSerial, &dcb))
    {
        printf("Error: Cannot get serial port state\n");
        CloseHandle(hSerial);
        return 0; 
    }
    dcb.BaudRate = baudrate;
    dcb.ByteSize = 8;
    dcb.Parity = NOPARITY;
    dcb.StopBits = ONESTOPBIT;
    if (!SetCommState(hSerial, &dcb))
    {
        printf("Error: Cannot set serial port state\n");
        CloseHandle(hSerial);
        return 0;
    }
    COMMTIMEOUTS timeouts;
    timeouts.ReadIntervalTimeout = 50;
    timeouts.ReadTotalTimeoutConstant = 50;
    timeouts.ReadTotalTimeoutMultiplier = 10;
    timeouts.WriteTotalTimeoutConstant = 50;
    timeouts.WriteTotalTimeoutMultiplier = 10;
    if (!SetCommTimeouts(hSerial, &timeouts))
    {
        printf("Error: Cannot set serial port timeouts\n");
        CloseHandle(hSerial);
        return 0;
    }
    printf("Serial port %s opened with baudrate %d\n", portName, baudrate);
    return 1;
}

void winSerial_Close(void)
{
    CloseHandle(hSerial);
    printf("Serial port closed\n");
}

void winSerial_Write(uint8_t *data, uint32_t len)
{
    DWORD dwBytesWritten;
    if (!WriteFile(hSerial, data, len, &dwBytesWritten, NULL))
    {
        printf("Error: Cannot write to serial port\n");
    }
}
void winSerial_Read(uint8_t *data, uint32_t len)
{
    DWORD dwBytesRead;
    if (!ReadFile(hSerial, data, len, &dwBytesRead, NULL))
    {
        printf("Error: Cannot read from serial port\n");
    }
}

/*
传输由从机发起，主机配合。
从机上电后，不断发送0x55
主机将固件分成4kb大小的包，依次发送给从机，每发送1包，就等到从机回复0x56，然后再发送下一包。
*/

void winSerial_SendBuffAndWaitAck(uint8_t *data, uint32_t len)
{
    uint8_t ack = 0;
    // do
    // {
    //     ack = 0;
    //     winSerial_Read(ack, 1);
    // } while (ack != 0x55);

    uint32_t offset = 0;
    uint32_t packID = 0;
    while(1)
    {
        winSerial_Write(data + offset, 4096);
        offset += 4096;
        packID ++;
        do
        {
            ack = 0;
            winSerial_Read(&ack, 1);
        } while (ack != 0x56);

        do
        {
            ack = 0;
            winSerial_Read(&ack, 1);
        } while (ack == 0x56);

        if (offset > len)
        {
            break;
        }
        

        printf(">>>>>>%s, send %d bytes, offset:%.3f kb, id:%d\n", __FUNCTION__, 4096, offset/1024.0, packID);
    }
    
}
