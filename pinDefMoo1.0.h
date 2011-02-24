
/*
Copyright (c) 2009, Intel Corporation
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following
conditions are met:

* Redistributions of source code must retain the above copyright notice, this list of conditions and the following
disclaimer.
* Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
disclaimer in the documentation and/or other materials provided with the distribution.
* Neither the name of Intel Corporation nor the names of its contributors may be used to endorse or promote products
derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

// Pin definitions
// WISP 4.1 DL
// "Blue WISP"

// MSP430F2132

// See wisp.wikispaces.com for a schematic.

// Port 1
#define TEMP_POWER     BIT0       // output
#define TX_PIN         BIT1       // output
#define RX_PIN         BIT2       // input
#define RX_EN_PIN      BIT3       // output
#define ACCEL_POWER    BIT4       // output
#define DEBUG_1_5      BIT5       // output/input
#define DEBUG_1_6      BIT6       // output/input
#define DEBUG_1_7      BIT7       // output/input

// Port 2
//Supervisor in: PCB is designed to P6.7, should wire connect P6.7 and P2.0
#define VOLTAGE_SV_PIN      BIT0       // output/input
#define DEBUG_2_1      BIT1       // output/input
#define DEBUG_2_2      BIT2       // output/input
#define IDLE_2_3       BIT3       // idle pin
#define IDLE_2_4       BIT4       // idle pin
#define IDLE_2_5       BIT5       // idle pin
#define IDLE_2_6       BIT6       // idle pin
#define IDLE_2_7       BIT7       // idle pin

// Port 3
#define CLK_A          BIT0       // output unless externally driven
#define SDA_B          BIT1       // input (connected to 10k pullup res)
#define SCL_B          BIT2       // input (connected to 10k pullup res)
#define CLK_B          BIT3       // output unless externally driven
#define TX_A           BIT4       // output unless externally driven
#define RX_A           BIT5       // output unless externally driven
#define DEBUG_3_6      BIT6       // output/input
#define DEBUG_3_7      BIT7       // output/input

// Port 4
#define DEBUG_4_0      BIT0       // connect to SV_IN by 0 ohm
#define CAP_SENSE      BIT1       // output/input
#define LED_POWER      BIT2       // output
#define VSENSE_POWER   BIT3       // output
#define DEBUG_4_4      BIT4       // output/input
#define DEBUG_4_5      BIT5       // output/input
#define DEBUG_4_6      BIT6       // output/input
#define DEBUG_4_7      BIT7       // output/input

// Port 5
#define FLASH_CE       BIT0       // output
#define FLASH_SIMO     BIT1       // output
#define FLASH_SOMI     BIT2       // input
#define FLASH_SCK      BIT3       // output
#define DEBUG_5_4      BIT4       // output unless externally driven
#define DEBUG_5_5      BIT5       // output unless externally driven
#define IDLE_5_6       BIT6       // idle pin
#define DEBUG_5_7      BIT7       // output unless externally driven

// Port 6
#define ACCEL_Z        BIT0       // input
#define ACCEL_Y        BIT1       // input
#define ACCEL_X        BIT2       // input
#define TEMP_EXT_IN    BIT3       // input
#define VSENSE_IN      BIT4       // input
#define DEBUG_6_5      BIT5       // output unless externally driven
#define DEBUG_6_6      BIT6       // output unless externally driven
#define DEBUG_6_7      BIT7       // input

// Port 8: Zhangh, need to reconfirm
#define CRYSTAL_IN     BIT7       // input
#define CRYSTAL_OUT    BIT6       // output



// Analog Inputs (ADC In Channel)
#define INCH_ACCEL_Z     INCH_0
#define INCH_ACCEL_Y     INCH_1
#define INCH_ACCEL_X     INCH_2
#define INCH_TEMP_EXT_IN INCH_3
#define INCH_VSENSE_IN   INCH_4
#define INCH_DEBUG_6_5   INCH_5
#define INCH_DEBUG_6_6   INCH_6


//#define INCH_2_4 INCH_4   // not accessible
// #define INCH_3_5 INCH_5  // ??

#define DRIVE_ALL_PINS  \
  P1OUT = 0;  \
  P2OUT = 0;  \
  P3OUT = 0;  \
  P4OUT = 0;  \
  P5OUT = 0;  \
  P6OUT = 0;  \
  P8OUT = 0;  \
  P1DIR = TEMP_POWER | ACCEL_POWER | TX_PIN | RX_EN_PIN; \
  P4DIR = CAP_SENSE | LED_POWER | VSENSE_POWER; \
  P5DIR = FLASH_CE | FLASH_SIMO | FLASH_SCK; \
  P8DIR = CRYSTAL_OUT; 