/*
 * API_SPI.c
 *
 *  Created on: Jun 21, 2018
 *      Author: JJimene6
 */
#include "Global.h"

void SSI_Init_0(void) {
//    To enable and initialize the SSI, the following steps are necessary:

//    1. Enable the SSI module using the RCGCSSI register (see page 346).
    //RCGCSSI |= (1 << 3);
        SYSCTL->RCGCSSI = (1<<0);
//    SYSCTL->RCGCSSI = (1<<0);
//    2. Enable the clock to the appropriate GPIO module via the RCGCGPIO register (see page 340).
//    To find out which GPIO port to enable, refer to Table 23-5 on page 1351.
    //RCGCGPIO |= (1 << 1);
      SYSCTL->RCGCGPIO |= (1<<0);
//    SYSCTL->RCGCGPIO = (1<<0);
//    3. Set the GPIO AFSEL bits for the appropriate pins (see page 671). To determine which GPIOs to
//    configure, see Table 23-4 on page 1344.
      GPIOA->AFSEL |= (1<<2) | (1<<3) | (1<<4) | (1<<5);
//    GPIOA->AFSEL |= (1<<2) | (1<<4) | (1<<5);

//    4. Configure the PMCn fields in the GPIOPCTL register to assign the SSI signals to the appropriate
//    pins. See page 688 and Table 23-5 on page 1351.
    GPIOA->PCTL |= (2<<8) | (2<<12) | (2<<16) | (2<<20);
//    GPIOA->PCTL |= (2<<8) | (2<<16) | (2<<24) | (2<<20);

//    5. Program the GPIODEN register to enable the pin's digital function. In addition, the drive strength,
//    drain select and pull-up/pull-down functions must be configured. Refer to “General-Purpose
//    Input/Outputs (GPIOs)” on page 649 for more information.
//    Note: Pull-ups can be used to avoid unnecessary toggles on the SSI pins, which can take the
//    slave to a wrong state. In addition, if the SSIClk signal is programmed to steady state
//    High through the SPO bit in the SSICR0 register, then software must also configure the
//    GPIO port pin corresponding to the SSInClk signal as a pull-up in the GPIO Pull-Up
//    Select (GPIOPUR) register.
    //GPIOA->DEN |=  (TX0 | Clk0);
    GPIOA->DEN |= (TX0 | CLK0);
//        For each of the frame formats, the SSI is configured using the following steps:
//        1. Ensure that the SSE bit in the SSICR1 register is clear before making any configuration changes.
//    SSI2->CR1 &= ~(1<<1);
    SSI0->CR1 &= 0x00;
//        2. Select whether the SSI is a master or slave:
//        a. For master operations, set the SSICR1 register to 0x0000.0000.
//        b. For slave mode (output enabled), set the SSICR1 register to 0x0000.0004.
//        c. For slave mode (output disabled), set the SSICR1 register to 0x0000.000C
    SSI0->CR1 = 0x00;

//    3. Configure the SSI clock source by writing to the SSICC register.
    SSI0->CC = 0x00;

//    4. Configure the clock prescale divisor by writing the SSICPSR register.
    SSI0->CPSR = 10;

//    5. Write the SSICR0 register with the following configuration:
//    - Serial clock rate (SCR)
//    - Desired clock phase/polarity, if using Freescale SPI mode (SPH and SPO)
//    - The protocol mode: Freescale SPI, TI SSF, MICROWIRE (FRF)
//    - The data size (DSS)
    SSI0->CR0 = (0x7 << 0);

//    SSI0->CR0 |= (1U << 7);
//    6. Optionally, configure the SSI module for uDMA use with the following steps:
//    a. Configure a uDMA for SSI use. See “Micro Direct Memory Access (uDMA)” on page 585 for
//    more information.
//    b. Enable the SSI Module's TX FIFO or RX FIFO by setting the TXDMAE or RXDMAE bit in the
//    SSIDMACTL register.

//    7. Enable the SSI by setting the SSE bit in the SSICR1 register.
//    As an example, assume the SSI must be configured to operate with the following parameters:
//    - Master operation
//    - Freescale SPI mode (SPO=1, SPH=1)
//    - 1 Mbps bit rate
//    - 8 data bits

    SSI0->CR1 |= 0X02;
}



void writeSPI_0(uint8_t data) {
    SSI0->DR = data;
    while((SSI0->SR & (1<<0)) == 0);
}
