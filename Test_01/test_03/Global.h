/*
 * Global.h
 *
 *  Created on: Jun 21, 2018
 *      Author: JJimene6
 */
#include "myHeaderFile.h"
#include "MCP23S17_EXP.h"

#ifndef GLOBAL_H_
#define GLOBAL_H_



void SSI_Init_0(void);
void writeSPI_0(uint8_t data);
void IOCON_setup(uint8_t address);
void xPORTA_setup_X(uint8_t address);
void xPORTB_setup_X(uint8_t address);
void xGPIOA_out_1(uint8_t address, uint8_t value);
void delay(int time);


#define SS      (1U<<2)
#define RST     (1U<<1)

#define TX0     (1u<<5)
#define CLK0    (1u<<2)

#define TX2     (1U<<7)
#define CLK2    (1U<<4)


#endif /* GLOBAL_H_ */
