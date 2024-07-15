//
// Created by guoliang on 9/4/2023.
//
#include "stm32f1xx.h"
#include "main.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_conf.h"

#ifndef SPI_RW_W25Q64_WITH_GPIO_SPI_H
#define SPI_RW_W25Q64_WITH_GPIO_SPI_H

void SPI_W_SS(uint8_t value);
void SPI_W_SCK(uint8_t value);
void SPI_W_MOSI(uint8_t value);
uint8_t SPI_R_MISO(void);

void SPI_INIT();
void SPI_INIT_MODE3();
void SPI_Start(void);
void SPI_Stop(void);

uint8_t SPI_RW_Byte_Mode0(uint8_t ByteSend);
uint8_t SPI_RW_Byte_Mode1(uint8_t ByteSend);
uint8_t SPI_RW_Byte_Mode2(uint8_t ByteSend);
uint8_t SPI_RW_Byte_Mode3(uint8_t ByteSend);

#endif //SPI_RW_W25Q64_WITH_GPIO_SPI_H
