/*
 * @file tlv320adcx140_page4.h
 *
 * @brief TLV320ADCx140 Descriptor
 *
 * @copyright Copyright (C) 2021 Texas Instruments Incorporated - http://www.ti.com/
 *
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef TLV320ADCX140_PAGE4_H_
#define TLV320ADCX140_PAGE4_H_

#include <stdint.h>


//**********************************************************************************
//
// Function prototypes
//
//**********************************************************************************



//**********************************************************************************
//
// Device commands
//
//**********************************************************************************



//**********************************************************************************
//
// Register definitions
//
//**********************************************************************************


/* Register 0x00 (PAGE_CFG) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                       PAGE[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* PAGE_CFG register */
    #define PAGE_CFG_ADDRESS												((uint8_t) 0x00)
    #define PAGE_CFG_DEFAULT												((uint8_t) 0x00)

    /* PAGE field */
    #define PAGE_CFG_PAGE_MASK												((uint8_t) 0xFF)
    #define PAGE_CFG_PAGE_0													((uint8_t) 0x00)    // DEFAULT
    #define PAGE_CFG_PAGE_1													((uint8_t) 0x01)
    #define PAGE_CFG_PAGE_2													((uint8_t) 0x02)
    #define PAGE_CFG_PAGE_3													((uint8_t) 0x03)
    #define PAGE_CFG_PAGE_4													((uint8_t) 0x04)
    #define PAGE_CFG_PAGE_5													((uint8_t) 0x05)
    #define PAGE_CFG_PAGE_6													((uint8_t) 0x06)



/* Register 0x08 (MIX1_CH1_BYTE1) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        MSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX1_CH1_BYTE1 register */
    #define MIX1_CH1_BYTE1_ADDRESS											((uint8_t) 0x08)
    #define MIX1_CH1_BYTE1_DEFAULT											((uint8_t) 0x7F)



/* Register 0x09 (MIX1_CH1_BYTE2) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B2[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX1_CH1_BYTE2 register */
    #define MIX1_CH1_BYTE2_ADDRESS											((uint8_t) 0x09)
    #define MIX1_CH1_BYTE2_DEFAULT											((uint8_t) 0xFF)



/* Register 0x0A (MIX1_CH1_BYTE3) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B1[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX1_CH1_BYTE3 register */
    #define MIX1_CH1_BYTE3_ADDRESS											((uint8_t) 0x0A)
    #define MIX1_CH1_BYTE3_DEFAULT											((uint8_t) 0xFF)



/* Register 0x0B (MIX1_CH1_BYTE4) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        LSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX1_CH1_BYTE4 register */
    #define MIX1_CH1_BYTE4_ADDRESS											((uint8_t) 0x0B)
    #define MIX1_CH1_BYTE4_DEFAULT											((uint8_t) 0xFF)



/* Register 0x0C (MIX1_CH2_BYTE1) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        MSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX1_CH2_BYTE1 register */
    #define MIX1_CH2_BYTE1_ADDRESS											((uint8_t) 0x0C)
    #define MIX1_CH2_BYTE1_DEFAULT											((uint8_t) 0x00)



/* Register 0x0D (MIX1_CH2_BYTE2) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B2[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX1_CH2_BYTE2 register */
    #define MIX1_CH2_BYTE2_ADDRESS											((uint8_t) 0x0D)
    #define MIX1_CH2_BYTE2_DEFAULT											((uint8_t) 0x00)



/* Register 0x0E (MIX1_CH2_BYTE3) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B1[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX1_CH2_BYTE3 register */
    #define MIX1_CH2_BYTE3_ADDRESS											((uint8_t) 0x0E)
    #define MIX1_CH2_BYTE3_DEFAULT											((uint8_t) 0x00)



/* Register 0x0F (MIX1_CH2_BYTE4) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        LSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX1_CH2_BYTE4 register */
    #define MIX1_CH2_BYTE4_ADDRESS											((uint8_t) 0x0F)
    #define MIX1_CH2_BYTE4_DEFAULT											((uint8_t) 0x00)



/* Register 0x10 (MIX1_CH3_BYTE1) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        MSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX1_CH3_BYTE1 register */
    #define MIX1_CH3_BYTE1_ADDRESS											((uint8_t) 0x10)
    #define MIX1_CH3_BYTE1_DEFAULT											((uint8_t) 0x00)



/* Register 0x11 (MIX1_CH3_BYTE2) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B2[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX1_CH3_BYTE2 register */
    #define MIX1_CH3_BYTE2_ADDRESS											((uint8_t) 0x11)
    #define MIX1_CH3_BYTE2_DEFAULT											((uint8_t) 0x00)



/* Register 0x12 (MIX1_CH3_BYTE3) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B1[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX1_CH3_BYTE3 register */
    #define MIX1_CH3_BYTE3_ADDRESS											((uint8_t) 0x12)
    #define MIX1_CH3_BYTE3_DEFAULT											((uint8_t) 0x00)



/* Register 0x13 (MIX1_CH3_BYTE4) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        LSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX1_CH3_BYTE4 register */
    #define MIX1_CH3_BYTE4_ADDRESS											((uint8_t) 0x13)
    #define MIX1_CH3_BYTE4_DEFAULT											((uint8_t) 0x00)



/* Register 0x14 (MIX1_CH4_BYTE1) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        MSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX1_CH4_BYTE1 register */
    #define MIX1_CH4_BYTE1_ADDRESS											((uint8_t) 0x14)
    #define MIX1_CH4_BYTE1_DEFAULT											((uint8_t) 0x00)



/* Register 0x15 (MIX1_CH4_BYTE2) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B2[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX1_CH4_BYTE2 register */
    #define MIX1_CH4_BYTE2_ADDRESS											((uint8_t) 0x15)
    #define MIX1_CH4_BYTE2_DEFAULT											((uint8_t) 0x00)



/* Register 0x16 (MIX1_CH4_BYTE3) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B1[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX1_CH4_BYTE3 register */
    #define MIX1_CH4_BYTE3_ADDRESS											((uint8_t) 0x16)
    #define MIX1_CH4_BYTE3_DEFAULT											((uint8_t) 0x00)



/* Register 0x17 (MIX1_CH4_BYTE4) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        LSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX1_CH4_BYTE4 register */
    #define MIX1_CH4_BYTE4_ADDRESS											((uint8_t) 0x17)
    #define MIX1_CH4_BYTE4_DEFAULT											((uint8_t) 0x00)



/* Register 0x18 (MIX2_CH1_BYTE1) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        MSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX2_CH1_BYTE1 register */
    #define MIX2_CH1_BYTE1_ADDRESS											((uint8_t) 0x18)
    #define MIX2_CH1_BYTE1_DEFAULT											((uint8_t) 0x00)



/* Register 0x19 (MIX2_CH1_BYTE2) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B2[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX2_CH1_BYTE2 register */
    #define MIX2_CH1_BYTE2_ADDRESS											((uint8_t) 0x19)
    #define MIX2_CH1_BYTE2_DEFAULT											((uint8_t) 0x00)



/* Register 0x1A (MIX2_CH1_BYTE3) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B1[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX2_CH1_BYTE3 register */
    #define MIX2_CH1_BYTE3_ADDRESS											((uint8_t) 0x1A)
    #define MIX2_CH1_BYTE3_DEFAULT											((uint8_t) 0x00)



/* Register 0x1B (MIX2_CH1_BYTE4) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        LSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX2_CH1_BYTE4 register */
    #define MIX2_CH1_BYTE4_ADDRESS											((uint8_t) 0x1B)
    #define MIX2_CH1_BYTE4_DEFAULT											((uint8_t) 0x00)



/* Register 0x1C (MIX2_CH2_BYTE1) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        MSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX2_CH2_BYTE1 register */
    #define MIX2_CH2_BYTE1_ADDRESS											((uint8_t) 0x1C)
    #define MIX2_CH2_BYTE1_DEFAULT											((uint8_t) 0x7F)



/* Register 0x1D (MIX2_CH2_BYTE2) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B2[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX2_CH2_BYTE2 register */
    #define MIX2_CH2_BYTE2_ADDRESS											((uint8_t) 0x1D)
    #define MIX2_CH2_BYTE2_DEFAULT											((uint8_t) 0xFF)



/* Register 0x1E (MIX2_CH2_BYTE3) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B1[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX2_CH2_BYTE3 register */
    #define MIX2_CH2_BYTE3_ADDRESS											((uint8_t) 0x1E)
    #define MIX2_CH2_BYTE3_DEFAULT											((uint8_t) 0xFF)



/* Register 0x1F (MIX2_CH2_BYTE4) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        LSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX2_CH2_BYTE4 register */
    #define MIX2_CH2_BYTE4_ADDRESS											((uint8_t) 0x1F)
    #define MIX2_CH2_BYTE4_DEFAULT											((uint8_t) 0xFF)



/* Register 0x20 (MIX2_CH3_BYTE1) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        MSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX2_CH3_BYTE1 register */
    #define MIX2_CH3_BYTE1_ADDRESS											((uint8_t) 0x20)
    #define MIX2_CH3_BYTE1_DEFAULT											((uint8_t) 0x00)



/* Register 0x21 (MIX2_CH3_BYTE2) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B2[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX2_CH3_BYTE2 register */
    #define MIX2_CH3_BYTE2_ADDRESS											((uint8_t) 0x21)
    #define MIX2_CH3_BYTE2_DEFAULT											((uint8_t) 0x00)



/* Register 0x22 (MIX2_CH3_BYTE3) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B1[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX2_CH3_BYTE3 register */
    #define MIX2_CH3_BYTE3_ADDRESS											((uint8_t) 0x22)
    #define MIX2_CH3_BYTE3_DEFAULT											((uint8_t) 0x00)



/* Register 0x23 (MIX2_CH3_BYTE4) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        LSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX2_CH3_BYTE4 register */
    #define MIX2_CH3_BYTE4_ADDRESS											((uint8_t) 0x23)
    #define MIX2_CH3_BYTE4_DEFAULT											((uint8_t) 0x00)



/* Register 0x24 (MIX2_CH4_BYTE1) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        MSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX2_CH4_BYTE1 register */
    #define MIX2_CH4_BYTE1_ADDRESS											((uint8_t) 0x24)
    #define MIX2_CH4_BYTE1_DEFAULT											((uint8_t) 0x00)



/* Register 0x25 (MIX2_CH4_BYTE2) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B2[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX2_CH4_BYTE2 register */
    #define MIX2_CH4_BYTE2_ADDRESS											((uint8_t) 0x25)
    #define MIX2_CH4_BYTE2_DEFAULT											((uint8_t) 0x00)



/* Register 0x26 (MIX2_CH4_BYTE3) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B1[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX2_CH4_BYTE3 register */
    #define MIX2_CH4_BYTE3_ADDRESS											((uint8_t) 0x26)
    #define MIX2_CH4_BYTE3_DEFAULT											((uint8_t) 0x00)



/* Register 0x27 (MIX2_CH4_BYTE4) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        LSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX2_CH4_BYTE4 register */
    #define MIX2_CH4_BYTE4_ADDRESS											((uint8_t) 0x27)
    #define MIX2_CH4_BYTE4_DEFAULT											((uint8_t) 0x00)



/* Register 0x28 (MIX3_CH1_BYTE1) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        MSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX3_CH1_BYTE1 register */
    #define MIX3_CH1_BYTE1_ADDRESS											((uint8_t) 0x28)
    #define MIX3_CH1_BYTE1_DEFAULT											((uint8_t) 0x00)



/* Register 0x29 (MIX3_CH1_BYTE2) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B2[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX3_CH1_BYTE2 register */
    #define MIX3_CH1_BYTE2_ADDRESS											((uint8_t) 0x29)
    #define MIX3_CH1_BYTE2_DEFAULT											((uint8_t) 0x00)



/* Register 0x2A (MIX3_CH1_BYTE3) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B1[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX3_CH1_BYTE3 register */
    #define MIX3_CH1_BYTE3_ADDRESS											((uint8_t) 0x2A)
    #define MIX3_CH1_BYTE3_DEFAULT											((uint8_t) 0x00)



/* Register 0x2B (MIX3_CH1_BYTE4) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        LSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX3_CH1_BYTE4 register */
    #define MIX3_CH1_BYTE4_ADDRESS											((uint8_t) 0x2B)
    #define MIX3_CH1_BYTE4_DEFAULT											((uint8_t) 0x00)



/* Register 0x2C (MIX3_CH2_BYTE1) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        MSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX3_CH2_BYTE1 register */
    #define MIX3_CH2_BYTE1_ADDRESS											((uint8_t) 0x2C)
    #define MIX3_CH2_BYTE1_DEFAULT											((uint8_t) 0x00)



/* Register 0x2D (MIX3_CH2_BYTE2) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B2[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX3_CH2_BYTE2 register */
    #define MIX3_CH2_BYTE2_ADDRESS											((uint8_t) 0x2D)
    #define MIX3_CH2_BYTE2_DEFAULT											((uint8_t) 0x00)



/* Register 0x2E (MIX3_CH2_BYTE3) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B1[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX3_CH2_BYTE3 register */
    #define MIX3_CH2_BYTE3_ADDRESS											((uint8_t) 0x2E)
    #define MIX3_CH2_BYTE3_DEFAULT											((uint8_t) 0x00)



/* Register 0x2F (MIX3_CH2_BYTE4) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        LSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX3_CH2_BYTE4 register */
    #define MIX3_CH2_BYTE4_ADDRESS											((uint8_t) 0x2F)
    #define MIX3_CH2_BYTE4_DEFAULT											((uint8_t) 0x00)



/* Register 0x30 (MIX3_CH3_BYTE1) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        MSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX3_CH3_BYTE1 register */
    #define MIX3_CH3_BYTE1_ADDRESS											((uint8_t) 0x30)
    #define MIX3_CH3_BYTE1_DEFAULT											((uint8_t) 0x7F)



/* Register 0x31 (MIX3_CH3_BYTE2) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B2[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX3_CH3_BYTE2 register */
    #define MIX3_CH3_BYTE2_ADDRESS											((uint8_t) 0x31)
    #define MIX3_CH3_BYTE2_DEFAULT											((uint8_t) 0xFF)



/* Register 0x32 (MIX3_CH3_BYTE3) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B1[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX3_CH3_BYTE3 register */
    #define MIX3_CH3_BYTE3_ADDRESS											((uint8_t) 0x32)
    #define MIX3_CH3_BYTE3_DEFAULT											((uint8_t) 0xFF)



/* Register 0x33 (MIX3_CH3_BYTE4) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        LSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX3_CH3_BYTE4 register */
    #define MIX3_CH3_BYTE4_ADDRESS											((uint8_t) 0x33)
    #define MIX3_CH3_BYTE4_DEFAULT											((uint8_t) 0xFF)



/* Register 0x34 (MIX3_CH4_BYTE1) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        MSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX3_CH4_BYTE1 register */
    #define MIX3_CH4_BYTE1_ADDRESS											((uint8_t) 0x34)
    #define MIX3_CH4_BYTE1_DEFAULT											((uint8_t) 0x00)



/* Register 0x35 (MIX3_CH4_BYTE2) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B2[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX3_CH4_BYTE2 register */
    #define MIX3_CH4_BYTE2_ADDRESS											((uint8_t) 0x35)
    #define MIX3_CH4_BYTE2_DEFAULT											((uint8_t) 0x00)



/* Register 0x36 (MIX3_CH4_BYTE3) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B1[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX3_CH4_BYTE3 register */
    #define MIX3_CH4_BYTE3_ADDRESS											((uint8_t) 0x36)
    #define MIX3_CH4_BYTE3_DEFAULT											((uint8_t) 0x00)



/* Register 0x37 (MIX3_CH4_BYTE4) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        LSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX3_CH4_BYTE4 register */
    #define MIX3_CH4_BYTE4_ADDRESS											((uint8_t) 0x37)
    #define MIX3_CH4_BYTE4_DEFAULT											((uint8_t) 0x00)



/* Register 0x38 (MIX4_CH1_BYTE1) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        MSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX4_CH1_BYTE1 register */
    #define MIX4_CH1_BYTE1_ADDRESS											((uint8_t) 0x38)
    #define MIX4_CH1_BYTE1_DEFAULT											((uint8_t) 0x00)



/* Register 0x39 (MIX4_CH1_BYTE2) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B2[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX4_CH1_BYTE2 register */
    #define MIX4_CH1_BYTE2_ADDRESS											((uint8_t) 0x39)
    #define MIX4_CH1_BYTE2_DEFAULT											((uint8_t) 0x00)



/* Register 0x3A (MIX4_CH1_BYTE3) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B1[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX4_CH1_BYTE3 register */
    #define MIX4_CH1_BYTE3_ADDRESS											((uint8_t) 0x3A)
    #define MIX4_CH1_BYTE3_DEFAULT											((uint8_t) 0x00)



/* Register 0x3B (MIX4_CH1_BYTE4) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        LSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX4_CH1_BYTE4 register */
    #define MIX4_CH1_BYTE4_ADDRESS											((uint8_t) 0x3B)
    #define MIX4_CH1_BYTE4_DEFAULT											((uint8_t) 0x00)



/* Register 0x3C (MIX4_CH2_BYTE1) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        MSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX4_CH2_BYTE1 register */
    #define MIX4_CH2_BYTE1_ADDRESS											((uint8_t) 0x3C)
    #define MIX4_CH2_BYTE1_DEFAULT											((uint8_t) 0x00)



/* Register 0x3D (MIX4_CH2_BYTE2) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B2[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX4_CH2_BYTE2 register */
    #define MIX4_CH2_BYTE2_ADDRESS											((uint8_t) 0x3D)
    #define MIX4_CH2_BYTE2_DEFAULT											((uint8_t) 0x00)



/* Register 0x3E (MIX4_CH2_BYTE3) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B1[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX4_CH2_BYTE3 register */
    #define MIX4_CH2_BYTE3_ADDRESS											((uint8_t) 0x3E)
    #define MIX4_CH2_BYTE3_DEFAULT											((uint8_t) 0x00)



/* Register 0x3F (MIX4_CH2_BYTE4) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        LSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX4_CH2_BYTE4 register */
    #define MIX4_CH2_BYTE4_ADDRESS											((uint8_t) 0x3F)
    #define MIX4_CH2_BYTE4_DEFAULT											((uint8_t) 0x00)



/* Register 0x40 (MIX4_CH3_BYTE1) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        MSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX4_CH3_BYTE1 register */
    #define MIX4_CH3_BYTE1_ADDRESS											((uint8_t) 0x40)
    #define MIX4_CH3_BYTE1_DEFAULT											((uint8_t) 0x00)



/* Register 0x41 (MIX4_CH3_BYTE2) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B2[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX4_CH3_BYTE2 register */
    #define MIX4_CH3_BYTE2_ADDRESS											((uint8_t) 0x41)
    #define MIX4_CH3_BYTE2_DEFAULT											((uint8_t) 0x00)



/* Register 0x42 (MIX4_CH3_BYTE3) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B1[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX4_CH3_BYTE3 register */
    #define MIX4_CH3_BYTE3_ADDRESS											((uint8_t) 0x42)
    #define MIX4_CH3_BYTE3_DEFAULT											((uint8_t) 0x00)



/* Register 0x43 (MIX4_CH3_BYTE4) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        LSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX4_CH3_BYTE4 register */
    #define MIX4_CH3_BYTE4_ADDRESS											((uint8_t) 0x43)
    #define MIX4_CH3_BYTE4_DEFAULT											((uint8_t) 0x00)



/* Register 0x44 (MIX4_CH4_BYTE1) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        MSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX4_CH4_BYTE1 register */
    #define MIX4_CH4_BYTE1_ADDRESS											((uint8_t) 0x44)
    #define MIX4_CH4_BYTE1_DEFAULT											((uint8_t) 0x7F)



/* Register 0x45 (MIX4_CH4_BYTE2) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B2[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX4_CH4_BYTE2 register */
    #define MIX4_CH4_BYTE2_ADDRESS											((uint8_t) 0x45)
    #define MIX4_CH4_BYTE2_DEFAULT											((uint8_t) 0xFF)



/* Register 0x46 (MIX4_CH4_BYTE3) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B1[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX4_CH4_BYTE3 register */
    #define MIX4_CH4_BYTE3_ADDRESS											((uint8_t) 0x46)
    #define MIX4_CH4_BYTE3_DEFAULT											((uint8_t) 0xFF)



/* Register 0x47 (MIX4_CH4_BYTE4) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        LSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* MIX4_CH4_BYTE4 register */
    #define MIX4_CH4_BYTE4_ADDRESS											((uint8_t) 0x47)
    #define MIX4_CH4_BYTE4_DEFAULT											((uint8_t) 0xFF)



/* Register 0x48 (IIR_N0_BYTE1) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        MSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* IIR_N0_BYTE1 register */
    #define IIR_N0_BYTE1_ADDRESS											((uint8_t) 0x48)
    #define IIR_N0_BYTE1_DEFAULT											((uint8_t) 0x7F)



/* Register 0x49 (IIR_N0_BYTE2) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B2[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* IIR_N0_BYTE2 register */
    #define IIR_N0_BYTE2_ADDRESS											((uint8_t) 0x49)
    #define IIR_N0_BYTE2_DEFAULT											((uint8_t) 0xFF)



/* Register 0x4A (IIR_N0_BYTE3) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B1[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* IIR_N0_BYTE3 register */
    #define IIR_N0_BYTE3_ADDRESS											((uint8_t) 0x4A)
    #define IIR_N0_BYTE3_DEFAULT											((uint8_t) 0xFF)



/* Register 0x4B (IIR_N0_BYTE4) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        LSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* IIR_N0_BYTE4 register */
    #define IIR_N0_BYTE4_ADDRESS											((uint8_t) 0x4B)
    #define IIR_N0_BYTE4_DEFAULT											((uint8_t) 0xFF)



/* Register 0x4C (IIR_N1_BYTE1) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        MSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* IIR_N1_BYTE1 register */
    #define IIR_N1_BYTE1_ADDRESS											((uint8_t) 0x4C)
    #define IIR_N1_BYTE1_DEFAULT											((uint8_t) 0x00)



/* Register 0x4D (IIR_N1_BYTE2) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B2[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* IIR_N1_BYTE2 register */
    #define IIR_N1_BYTE2_ADDRESS											((uint8_t) 0x4D)
    #define IIR_N1_BYTE2_DEFAULT											((uint8_t) 0x00)



/* Register 0x4E (IIR_N1_BYTE3) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B1[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* IIR_N1_BYTE3 register */
    #define IIR_N1_BYTE3_ADDRESS											((uint8_t) 0x4E)
    #define IIR_N1_BYTE3_DEFAULT											((uint8_t) 0x00)



/* Register 0x4F (IIR_N1_BYTE4) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        LSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* IIR_N1_BYTE4 register */
    #define IIR_N1_BYTE4_ADDRESS											((uint8_t) 0x4F)
    #define IIR_N1_BYTE4_DEFAULT											((uint8_t) 0x00)



/* Register 0x50 (IIR_D1_BYTE1) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        MSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* IIR_D1_BYTE1 register */
    #define IIR_D1_BYTE1_ADDRESS											((uint8_t) 0x50)
    #define IIR_D1_BYTE1_DEFAULT											((uint8_t) 0x00)



/* Register 0x51 (IIR_D1_BYTE2) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B2[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* IIR_D1_BYTE2 register */
    #define IIR_D1_BYTE2_ADDRESS											((uint8_t) 0x51)
    #define IIR_D1_BYTE2_DEFAULT											((uint8_t) 0x00)



/* Register 0x52 (IIR_D1_BYTE3) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B1[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* IIR_D1_BYTE3 register */
    #define IIR_D1_BYTE3_ADDRESS											((uint8_t) 0x52)
    #define IIR_D1_BYTE3_DEFAULT											((uint8_t) 0x00)



/* Register 0x53 (IIR_D1_BYTE4) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        LSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* IIR_D1_BYTE4 register */
    #define IIR_D1_BYTE4_ADDRESS											((uint8_t) 0x53)
    #define IIR_D1_BYTE4_DEFAULT											((uint8_t) 0x00)



#endif /* TLV320ADCX140_PAGE4_H_ */
