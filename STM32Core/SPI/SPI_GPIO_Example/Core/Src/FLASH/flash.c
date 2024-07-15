//
// Created by guoliang on 9/4/2023.
//

#include "../SPI/spi.h"

#include "flash.h"

void Flash_Init()
{
    SPI_INIT();
}

void Flash_Init_Mode0()
{
    SPI_W_SS(1);
    SPI_W_SCK(0);
    SPI_W_SS(0);
    SPI_W_SS(1);
}

void Flash_ReadID(uint8_t *MID, uint16_t *DID)
{
    SPI_Start();
    SPI_RW_Byte_Mode0(0x9F);

    *MID = SPI_RW_Byte_Mode0(0xFF);

    *DID |= SPI_RW_Byte_Mode0(0xFF) << 8;
    *DID |= SPI_RW_Byte_Mode0(0xFF);

    SPI_Stop();
}
void Flash_ReadID_Mode1(uint8_t *MID, uint16_t *DID)
{
    SPI_Start();
    SPI_RW_Byte_Mode1(0x90);
    SPI_RW_Byte_Mode1(0x00);
    SPI_RW_Byte_Mode1(0x00);
    SPI_RW_Byte_Mode1(0x00);

    *DID |= SPI_RW_Byte_Mode1(0xFF) << 8;
    *DID |= SPI_RW_Byte_Mode1(0xFF);

    SPI_Stop();
}
void Flash_ReadID_Mode3(uint8_t *MID, uint16_t *DID)
{
    SPI_Start();
    SPI_RW_Byte_Mode3(0x9F);

    *MID = SPI_RW_Byte_Mode3(0xFF);

    *DID |= SPI_RW_Byte_Mode3(0xFF) << 8;
    *DID |= SPI_RW_Byte_Mode3(0xFF);

    SPI_Stop();
}
