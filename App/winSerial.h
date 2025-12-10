#ifndef __WINSERIAL_H__
#define __WINSERIAL_H__

#include <stdint.h>

int8_t winSerial_Open(uint8_t port, uint32_t baudrate);
void winSerial_Close(void);

void winSerial_Write(uint8_t *data, uint32_t len);
void winSerial_Read(uint8_t *data, uint32_t len);

void winSerial_SendBuffAndWaitAck(uint8_t *data, uint32_t len);

#endif /* __WINSERIAL_H__ */
