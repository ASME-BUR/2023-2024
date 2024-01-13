/*
 * @file tlv320adcx140_page5.h
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

#ifndef TLV320ADCX140_PAGE5_H_
#define TLV320ADCX140_PAGE5_H_

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



/* Register 0x7C (DRE_REL_ALPHA_BYTE1) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        MSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* DRE_REL_ALPHA_BYTE1 register */
    #define DRE_REL_ALPHA_BYTE1_ADDRESS										((uint8_t) 0x7C)
    #define DRE_REL_ALPHA_BYTE1_DEFAULT										((uint8_t) 0x7F)



/* Register 0x7D (DRE_REL_ALPHA_BYTE2) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B2[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* DRE_REL_ALPHA_BYTE2 register */
    #define DRE_REL_ALPHA_BYTE2_ADDRESS										((uint8_t) 0x7D)
    #define DRE_REL_ALPHA_BYTE2_DEFAULT										((uint8_t) 0xB5)



/* Register 0x7E (DRE_REL_ALPHA_BYTE3) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        B1[7:0]                                        |
 * |---------------------------------------------------------------------------------------|
 */

    /* DRE_REL_ALPHA_BYTE3 register */
    #define DRE_REL_ALPHA_BYTE3_ADDRESS										((uint8_t) 0x7E)
    #define DRE_REL_ALPHA_BYTE3_DEFAULT										((uint8_t) 0x16)



/* Register 0x7F (DRE_REL_ALPHA_BYTE4) definition
 * |---------------------------------------------------------------------------------------|
 * |   Bit 7  |   Bit 6  |   Bit 5  |   Bit 4  |   Bit 3  |   Bit 2  |   Bit 1  |   Bit 0  |
 * |---------------------------------------------------------------------------------------|
 * |                                        LSB[7:0]                                       |
 * |---------------------------------------------------------------------------------------|
 */

    /* DRE_REL_ALPHA_BYTE4 register */
    #define DRE_REL_ALPHA_BYTE4_ADDRESS										((uint8_t) 0x7F)
    #define DRE_REL_ALPHA_BYTE4_DEFAULT										((uint8_t) 0x50)



#endif /* TLV320ADCX140_PAGE5_H_ */
