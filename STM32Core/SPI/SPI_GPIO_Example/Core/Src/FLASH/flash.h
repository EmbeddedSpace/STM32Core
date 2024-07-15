//
// Created by guoliang on 9/4/2023.
//

#ifndef SPI_RW_W25Q64_WITH_GPIO_FLASH_H
#define SPI_RW_W25Q64_WITH_GPIO_FLASH_H

void Flash_Init();
void Flash_Init_Mode0();
void Flash_ReadID(uint8_t *MID, uint16_t *DID);
void Flash_ReadID_Mode1(uint8_t *MID, uint16_t *DID);
void Flash_ReadID_Mode3(uint8_t *MID, uint16_t *DID);

#endif //SPI_RW_W25Q64_WITH_GPIO_FLASH_H
