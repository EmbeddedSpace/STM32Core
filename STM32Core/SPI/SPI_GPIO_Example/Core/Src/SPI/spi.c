//
// Created by guoliang on 9/4/2023.
//
#include "spi.h"

void SPI_W_SS(uint8_t value) {
    HAL_GPIO_WritePin(F_CS_GPIO_Port, F_CS_Pin, value);
}

void SPI_W_SCK(uint8_t value) {
    HAL_GPIO_WritePin(SCK_GPIO_Port, SCK_Pin, value);
}

void SPI_W_MOSI(uint8_t value) {
    HAL_GPIO_WritePin(MOSI_GPIO_Port, MOSI_Pin, value);
}

uint8_t SPI_R_MISO(void) {
    return HAL_GPIO_ReadPin(MISO_GPIO_Port,MISO_Pin);
}

// NOTE: config the mode 0
void SPI_INIT()
{
    SPI_W_SS(1);
    SPI_W_SCK(0);
}
void SPI_INIT_MODE3()
{
    SPI_W_SS(1);
    SPI_W_SCK(1);
}
void SPI_Start(void)
{
    SPI_W_SS(0);
}
void SPI_Stop(void)
{
    SPI_W_SS(1);
}

uint8_t SPI_RW_Byte_Mode0(uint8_t ByteSend)
{
    uint8_t i = 0;
    uint8_t  ByteReceive = 0x00;

    for (i = 0; i < 8; ++i)
    {
        SPI_W_MOSI(ByteSend & (0x80 >> i));
        SPI_W_SCK(1);
        if(SPI_R_MISO() == 1)
        {
            ByteReceive |= (0x80 >> i);
        }
        SPI_W_SCK(0);
    }

    return ByteReceive;
}
uint8_t SPI_RW_Byte_Mode1(uint8_t ByteSend)
{
    uint8_t i = 0;
    uint8_t  ByteReceive = 0x00;

    for (i = 0; i < 8; ++i)
    {
        SPI_W_SCK(1);
        SPI_W_MOSI(ByteSend & (0x80 >> i));
        SPI_W_SCK(0);
        if(SPI_R_MISO() == 1)
        {
            ByteReceive |= (0x80 >> i);
        }
    }

    return ByteReceive;
}
uint8_t SPI_RW_Byte_Mode2(uint8_t ByteSend)
{

    return 0;
}
uint8_t SPI_RW_Byte_Mode3(uint8_t ByteSend)
{

    uint8_t i = 0;
    uint8_t  ByteReceive = 0x00;

    for (i = 0; i < 8; ++i)
    {
        SPI_W_MOSI(ByteSend & (0x80 >> i));
        SPI_W_SCK(0);
        if(SPI_R_MISO() == 1)
        {
            ByteReceive |= (0x80 >> i);
        }
        SPI_W_SCK(1);
    }

    return ByteReceive;
}
