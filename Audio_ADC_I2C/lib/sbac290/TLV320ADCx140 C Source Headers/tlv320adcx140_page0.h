/*
 * @file tlv320adcx140_page0.h
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

#ifndef TLV320ADCX140_PAGE0_H_
#define TLV320ADCX140_PAGE0_H_

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
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                                                   PAGE[7:0]                                                                                   |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
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



/* Register 0x01 (SW_RESET) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                                      RESERVED[6:0]                                                                      |       SW_RESET      |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* SW_RESET register */
    #define SW_RESET_ADDRESS												((uint8_t) 0x01)
    #define SW_RESET_DEFAULT												((uint8_t) 0x00)

    /* SW_RESET field */
    #define SW_RESET_MASK													((uint8_t) 0x01)
    #define SW_RESET_NOP													((uint8_t) 0x00)    // DEFAULT
    #define SW_RESET_RESET													((uint8_t) 0x01)



/* Register 0x02 (SLEEP_CFG) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |     AREG_SELECT     |               RESERVED[1:0]               |               VREF_QCHG[1:0]              |    I2C_BRDCAST_EN   |       RESERVED      |      SLEEP_ENZ      |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* SLEEP_CFG register */
    #define SLEEP_CFG_ADDRESS												((uint8_t) 0x02)
    #define SLEEP_CFG_DEFAULT												((uint8_t) 0x00)

    /* AREG_SELECT field */
    #define SLEEP_CFG_AREG_SELECT_MASK										((uint8_t) 0x80)
    #define SLEEP_CFG_AREG_SELECT_EXTERNAL									((uint8_t) 0x00)    // DEFAULT
    #define SLEEP_CFG_AREG_SELECT_INTERNAL									((uint8_t) 0x80)

    /* VREF_QCHG field */
    #define SLEEP_CFG_VREF_QCHG_MASK										((uint8_t) 0x18)
    #define SLEEP_CFG_VREF_QCHG_3P5_MS										((uint8_t) 0x00)    // DEFAULT
    #define SLEEP_CFG_VREF_QCHG_10_MS										((uint8_t) 0x08)
    #define SLEEP_CFG_VREF_QCHG_50_MS										((uint8_t) 0x10)
    #define SLEEP_CFG_VREF_QCHG_100_MS										((uint8_t) 0x18)

    /* I2C_BRDCAST_EN field */
    #define SLEEP_CFG_I2C_BRDCAST_EN_MASK									((uint8_t) 0x04)
    #define SLEEP_CFG_I2C_BRDCAST_EN_DISABLED								((uint8_t) 0x00)    // DEFAULT
    #define SLEEP_CFG_I2C_BRDCAST_EN_ENABLED								((uint8_t) 0x04)

    /* SLEEP_ENZ field */
    #define SLEEP_CFG_SLEEP_ENZ_MASK										((uint8_t) 0x01)
    #define SLEEP_CFG_SLEEP_ENZ_SLEEP										((uint8_t) 0x00)    // DEFAULT
    #define SLEEP_CFG_SLEEP_ENZ_ACTIVE										((uint8_t) 0x01)



/* Register 0x05 (SHDN_CFG) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |               RESERVED[1:0]               |              INCAP_QCHG[1:0]              |               SHDNZ_CFG[1:0]              |             DREG_KA_TIME[1:0]             |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* SHDN_CFG register */
    #define SHDN_CFG_ADDRESS												((uint8_t) 0x05)
    #define SHDN_CFG_DEFAULT												((uint8_t) 0x05)

    /* INCAP_QCHG field */
    #define SHDN_CFG_INCAP_QCHG_MASK										((uint8_t) 0x30)
    #define SHDN_CFG_INCAP_QCHG_2P5_MS										((uint8_t) 0x00)    // DEFAULT
    #define SHDN_CFG_INCAP_QCHG_12P5_MS										((uint8_t) 0x10)
    #define SHDN_CFG_INCAP_QCHG_25_MS										((uint8_t) 0x20)
    #define SHDN_CFG_INCAP_QCHG_50_MS										((uint8_t) 0x30)

    /* SHDNZ_CFG field */
    #define SHDN_CFG_SHDNZ_CFG_MASK											((uint8_t) 0x0C)
    #define SHDN_CFG_SHDNZ_CFG_IMMEDIATE									((uint8_t) 0x00)
    #define SHDN_CFG_SHDNZ_CFG_TIME_OUT										((uint8_t) 0x04)    // DEFAULT
    #define SHDN_CFG_SHDNZ_CFG_ACTIVE										((uint8_t) 0x08)

    /* DREG_KA_TIME field */
    #define SHDN_CFG_DREG_KA_TIME_MASK										((uint8_t) 0x03)
    #define SHDN_CFG_DREG_KA_TIME_30mS										((uint8_t) 0x00)
    #define SHDN_CFG_DREG_KA_TIME_25mS										((uint8_t) 0x01)    // DEFAULT
    #define SHDN_CFG_DREG_KA_TIME_10mS										((uint8_t) 0x02)
    #define SHDN_CFG_DREG_KA_TIME_5mS										((uint8_t) 0x03)



/* Register 0x07 (ASI_CFG0) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                FORMAT[1:0]                |                 WLEN[1:0]                 |      FSYNC_POL      |       BCLK_POL      |       TX_EDGE       |       TX_FILL       |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* ASI_CFG0 register */
    #define ASI_CFG0_ADDRESS												((uint8_t) 0x07)
    #define ASI_CFG0_DEFAULT												((uint8_t) 0x30)

    /* FORMAT field */
    #define ASI_CFG0_FORMAT_MASK											((uint8_t) 0xC0)
    #define ASI_CFG0_FORMAT_TDM												((uint8_t) 0x00)    // DEFAULT
    #define ASI_CFG0_FORMAT_I2S												((uint8_t) 0x40)
    #define ASI_CFG0_FORMAT_LJ												((uint8_t) 0x80)

    /* WLEN field */
    #define ASI_CFG0_WLEN_MASK												((uint8_t) 0x30)
    #define ASI_CFG0_WLEN_16_BITS											((uint8_t) 0x00)
    #define ASI_CFG0_WLEN_20_BITS											((uint8_t) 0x10)
    #define ASI_CFG0_WLEN_24_BITS											((uint8_t) 0x20)
    #define ASI_CFG0_WLEN_32_BITS											((uint8_t) 0x30)    // DEFAULT

    /* FSYNC_POL field */
    #define ASI_CFG0_FSYNC_POL_MASK											((uint8_t) 0x08)
    #define ASI_CFG0_FSYNC_POL_DEFAULT										((uint8_t) 0x00)    // DEFAULT
    #define ASI_CFG0_FSYNC_POL_INVERTED										((uint8_t) 0x08)

    /* BCLK_POL field */
    #define ASI_CFG0_BCLK_POL_MASK											((uint8_t) 0x04)
    #define ASI_CFG0_BCLK_POL_DEFAULT										((uint8_t) 0x00)    // DEFAULT
    #define ASI_CFG0_BCLK_POL_INVERTED										((uint8_t) 0x04)

    /* TX_EDGE field */
    #define ASI_CFG0_TX_EDGE_MASK											((uint8_t) 0x02)
    #define ASI_CFG0_TX_EDGE_DEFAULT										((uint8_t) 0x00)    // DEFAULT
    #define ASI_CFG0_TX_EDGE_INVERTED										((uint8_t) 0x02)

    /* TX_FILL field */
    #define ASI_CFG0_TX_FILL_MASK											((uint8_t) 0x01)
    #define ASI_CFG0_TX_FILL_ZERO											((uint8_t) 0x00)    // DEFAULT
    #define ASI_CFG0_TX_FILL_HIZ											((uint8_t) 0x01)



/* Register 0x08 (ASI_CFG1) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        TX_LSB       |               TX_KEEPER[1:0]              |                                                TX_OFFSET[4:0]                                               |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* ASI_CFG1 register */
    #define ASI_CFG1_ADDRESS												((uint8_t) 0x08)
    #define ASI_CFG1_DEFAULT												((uint8_t) 0x00)

    /* TX_LSB field */
    #define ASI_CFG1_TX_LSB_MASK											((uint8_t) 0x80)
    #define ASI_CFG1_TX_LSB_FULL_CYCLE										((uint8_t) 0x00)    // DEFAULT
    #define ASI_CFG1_TX_LSB_HALF_CYCLE										((uint8_t) 0x80)

    /* TX_KEEPER field */
    #define ASI_CFG1_TX_KEEPER_MASK											((uint8_t) 0x60)
    #define ASI_CFG1_TX_KEEPER_DISABLED										((uint8_t) 0x00)    // DEFAULT
    #define ASI_CFG1_TX_KEEPER_ENABLED										((uint8_t) 0x20)
    #define ASI_CFG1_TX_KEEPER_1_CYCLE										((uint8_t) 0x40)
    #define ASI_CFG1_TX_KEEPER_1P5_CYCLE									((uint8_t) 0x60)

    /* TX_OFFSET field */
    #define ASI_CFG1_TX_OFFSET_MASK											((uint8_t) 0x1F)
    #define ASI_CFG1_TX_OFFSET_0											((uint8_t) 0x00)    // DEFAULT
    #define ASI_CFG1_TX_OFFSET_1											((uint8_t) 0x01)
    #define ASI_CFG1_TX_OFFSET_2											((uint8_t) 0x02)
    #define ASI_CFG1_TX_OFFSET_3											((uint8_t) 0x03)
    #define ASI_CFG1_TX_OFFSET_4											((uint8_t) 0x04)
    #define ASI_CFG1_TX_OFFSET_5											((uint8_t) 0x05)
    #define ASI_CFG1_TX_OFFSET_6											((uint8_t) 0x06)
    #define ASI_CFG1_TX_OFFSET_7											((uint8_t) 0x07)
    #define ASI_CFG1_TX_OFFSET_8											((uint8_t) 0x08)
    #define ASI_CFG1_TX_OFFSET_9											((uint8_t) 0x09)
    #define ASI_CFG1_TX_OFFSET_10											((uint8_t) 0x0A)
    #define ASI_CFG1_TX_OFFSET_11											((uint8_t) 0x0B)
    #define ASI_CFG1_TX_OFFSET_12											((uint8_t) 0x0C)
    #define ASI_CFG1_TX_OFFSET_13											((uint8_t) 0x0D)
    #define ASI_CFG1_TX_OFFSET_14											((uint8_t) 0x0E)
    #define ASI_CFG1_TX_OFFSET_15											((uint8_t) 0x0F)
    #define ASI_CFG1_TX_OFFSET_16											((uint8_t) 0x10)
    #define ASI_CFG1_TX_OFFSET_17											((uint8_t) 0x11)
    #define ASI_CFG1_TX_OFFSET_18											((uint8_t) 0x12)
    #define ASI_CFG1_TX_OFFSET_19											((uint8_t) 0x13)
    #define ASI_CFG1_TX_OFFSET_20											((uint8_t) 0x14)
    #define ASI_CFG1_TX_OFFSET_21											((uint8_t) 0x15)
    #define ASI_CFG1_TX_OFFSET_22											((uint8_t) 0x16)
    #define ASI_CFG1_TX_OFFSET_23											((uint8_t) 0x17)
    #define ASI_CFG1_TX_OFFSET_24											((uint8_t) 0x18)
    #define ASI_CFG1_TX_OFFSET_25											((uint8_t) 0x19)
    #define ASI_CFG1_TX_OFFSET_26											((uint8_t) 0x1A)
    #define ASI_CFG1_TX_OFFSET_27											((uint8_t) 0x1B)
    #define ASI_CFG1_TX_OFFSET_28											((uint8_t) 0x1C)
    #define ASI_CFG1_TX_OFFSET_29											((uint8_t) 0x1D)
    #define ASI_CFG1_TX_OFFSET_30											((uint8_t) 0x1E)
    #define ASI_CFG1_TX_OFFSET_31											((uint8_t) 0x1F)



/* Register 0x09 (ASI_CFG2) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |      ASI_DAISY      |       RESERVED      |       ASI_ERR       |     ASI_ERR_RCOV    |                                     RESERVED[3:0]                                     |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* ASI_CFG2 register */
    #define ASI_CFG2_ADDRESS												((uint8_t) 0x09)
    #define ASI_CFG2_DEFAULT												((uint8_t) 0x00)

    /* ASI_DAISY field */
    #define ASI_CFG2_ASI_DAISY_MASK											((uint8_t) 0x80)
    #define ASI_CFG2_ASI_DAISY_N0											((uint8_t) 0x00)    // DEFAULT
    #define ASI_CFG2_ASI_DAISY_YES											((uint8_t) 0x80)

    /* ASI_ERR field */
    #define ASI_CFG2_ASI_ERR_MASK											((uint8_t) 0x20)
    #define ASI_CFG2_ASI_ERR_ENABLE											((uint8_t) 0x00)    // DEFAULT
    #define ASI_CFG2_ASI_ERR_DISABLE										((uint8_t) 0x20)

    /* ASI_ERR_RCOV field */
    #define ASI_CFG2_ASI_ERR_RCOV_MASK										((uint8_t) 0x10)
    #define ASI_CFG2_ASI_ERR_RCOV_ENABLE									((uint8_t) 0x00)    // DEFAULT
    #define ASI_CFG2_ASI_ERR_RCOV_DISABLE									((uint8_t) 0x10)



/* Register 0x0B (ASI_CH1) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       RESERVED      |      CH1_OUTPUT     |                                                           CH1_SLOT[5:0]                                                           |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* ASI_CH1 register */
    #define ASI_CH1_ADDRESS													((uint8_t) 0x0B)
    #define ASI_CH1_DEFAULT													((uint8_t) 0x00)

    /* CH1_OUTPUT field */
    #define ASI_CH1_CH1_OUTPUT_MASK											((uint8_t) 0x40)
    #define ASI_CH1_CH1_OUTPUT_PRIMARY										((uint8_t) 0x00)    // DEFAULT
    #define ASI_CH1_CH1_OUTPUT_SECONDARY									((uint8_t) 0x40)

    /* CH1_SLOT field */
    #define ASI_CH1_CH1_SLOT_MASK											((uint8_t) 0x3F)
    #define ASI_CH1_CH1_SLOT_0												((uint8_t) 0x00)    // DEFAULT
    #define ASI_CH1_CH1_SLOT_1												((uint8_t) 0x01)
    #define ASI_CH1_CH1_SLOT_2												((uint8_t) 0x02)
    #define ASI_CH1_CH1_SLOT_3												((uint8_t) 0x03)
    #define ASI_CH1_CH1_SLOT_4												((uint8_t) 0x04)
    #define ASI_CH1_CH1_SLOT_5												((uint8_t) 0x05)
    #define ASI_CH1_CH1_SLOT_6												((uint8_t) 0x06)
    #define ASI_CH1_CH1_SLOT_7												((uint8_t) 0x07)
    #define ASI_CH1_CH1_SLOT_8												((uint8_t) 0x08)
    #define ASI_CH1_CH1_SLOT_9												((uint8_t) 0x09)
    #define ASI_CH1_CH1_SLOT_10												((uint8_t) 0x0A)
    #define ASI_CH1_CH1_SLOT_11												((uint8_t) 0x0B)
    #define ASI_CH1_CH1_SLOT_12												((uint8_t) 0x0C)
    #define ASI_CH1_CH1_SLOT_13												((uint8_t) 0x0D)
    #define ASI_CH1_CH1_SLOT_14												((uint8_t) 0x0E)
    #define ASI_CH1_CH1_SLOT_15												((uint8_t) 0x0F)
    #define ASI_CH1_CH1_SLOT_16												((uint8_t) 0x10)
    #define ASI_CH1_CH1_SLOT_17												((uint8_t) 0x11)
    #define ASI_CH1_CH1_SLOT_18												((uint8_t) 0x12)
    #define ASI_CH1_CH1_SLOT_19												((uint8_t) 0x13)
    #define ASI_CH1_CH1_SLOT_20												((uint8_t) 0x14)
    #define ASI_CH1_CH1_SLOT_21												((uint8_t) 0x15)
    #define ASI_CH1_CH1_SLOT_22												((uint8_t) 0x16)
    #define ASI_CH1_CH1_SLOT_23												((uint8_t) 0x17)
    #define ASI_CH1_CH1_SLOT_24												((uint8_t) 0x18)
    #define ASI_CH1_CH1_SLOT_25												((uint8_t) 0x19)
    #define ASI_CH1_CH1_SLOT_26												((uint8_t) 0x1A)
    #define ASI_CH1_CH1_SLOT_27												((uint8_t) 0x1B)
    #define ASI_CH1_CH1_SLOT_28												((uint8_t) 0x1C)
    #define ASI_CH1_CH1_SLOT_29												((uint8_t) 0x1D)
    #define ASI_CH1_CH1_SLOT_30												((uint8_t) 0x1E)
    #define ASI_CH1_CH1_SLOT_31												((uint8_t) 0x1F)
    #define ASI_CH1_CH1_SLOT_32												((uint8_t) 0x20)
    #define ASI_CH1_CH1_SLOT_33												((uint8_t) 0x21)
    #define ASI_CH1_CH1_SLOT_34												((uint8_t) 0x22)
    #define ASI_CH1_CH1_SLOT_35												((uint8_t) 0x23)
    #define ASI_CH1_CH1_SLOT_36												((uint8_t) 0x24)
    #define ASI_CH1_CH1_SLOT_37												((uint8_t) 0x25)
    #define ASI_CH1_CH1_SLOT_38												((uint8_t) 0x26)
    #define ASI_CH1_CH1_SLOT_39												((uint8_t) 0x27)
    #define ASI_CH1_CH1_SLOT_40												((uint8_t) 0x28)
    #define ASI_CH1_CH1_SLOT_41												((uint8_t) 0x29)
    #define ASI_CH1_CH1_SLOT_42												((uint8_t) 0x2A)
    #define ASI_CH1_CH1_SLOT_43												((uint8_t) 0x2B)
    #define ASI_CH1_CH1_SLOT_44												((uint8_t) 0x2C)
    #define ASI_CH1_CH1_SLOT_45												((uint8_t) 0x2D)
    #define ASI_CH1_CH1_SLOT_46												((uint8_t) 0x2E)
    #define ASI_CH1_CH1_SLOT_47												((uint8_t) 0x2F)
    #define ASI_CH1_CH1_SLOT_48												((uint8_t) 0x30)
    #define ASI_CH1_CH1_SLOT_49												((uint8_t) 0x31)
    #define ASI_CH1_CH1_SLOT_50												((uint8_t) 0x32)
    #define ASI_CH1_CH1_SLOT_51												((uint8_t) 0x33)
    #define ASI_CH1_CH1_SLOT_52												((uint8_t) 0x34)
    #define ASI_CH1_CH1_SLOT_53												((uint8_t) 0x35)
    #define ASI_CH1_CH1_SLOT_54												((uint8_t) 0x36)
    #define ASI_CH1_CH1_SLOT_55												((uint8_t) 0x37)
    #define ASI_CH1_CH1_SLOT_56												((uint8_t) 0x38)
    #define ASI_CH1_CH1_SLOT_57												((uint8_t) 0x39)
    #define ASI_CH1_CH1_SLOT_58												((uint8_t) 0x3A)
    #define ASI_CH1_CH1_SLOT_59												((uint8_t) 0x3B)
    #define ASI_CH1_CH1_SLOT_60												((uint8_t) 0x3C)
    #define ASI_CH1_CH1_SLOT_61												((uint8_t) 0x3D)
    #define ASI_CH1_CH1_SLOT_62												((uint8_t) 0x3E)
    #define ASI_CH1_CH1_SLOT_63												((uint8_t) 0x3F)



/* Register 0x0C (ASI_CH2) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       RESERVED      |      CH2_OUTPUT     |                                                           CH2_SLOT[5:0]                                                           |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* ASI_CH2 register */
    #define ASI_CH2_ADDRESS													((uint8_t) 0x0C)
    #define ASI_CH2_DEFAULT													((uint8_t) 0x01)

    /* CH2_OUTPUT field */
    #define ASI_CH2_CH2_OUTPUT_MASK											((uint8_t) 0x40)
    #define ASI_CH2_CH2_OUTPUT_PRIMARY										((uint8_t) 0x00)    // DEFAULT
    #define ASI_CH2_CH2_OUTPUT_SECONDARY									((uint8_t) 0x40)

    /* CH2_SLOT field */
    #define ASI_CH2_CH2_SLOT_MASK											((uint8_t) 0x3F)
    #define ASI_CH2_CH2_SLOT_0												((uint8_t) 0x00)
    #define ASI_CH2_CH2_SLOT_1												((uint8_t) 0x01)    // DEFAULT
    #define ASI_CH2_CH2_SLOT_2												((uint8_t) 0x02)
    #define ASI_CH2_CH2_SLOT_3												((uint8_t) 0x03)
    #define ASI_CH2_CH2_SLOT_4												((uint8_t) 0x04)
    #define ASI_CH2_CH2_SLOT_5												((uint8_t) 0x05)
    #define ASI_CH2_CH2_SLOT_6												((uint8_t) 0x06)
    #define ASI_CH2_CH2_SLOT_7												((uint8_t) 0x07)
    #define ASI_CH2_CH2_SLOT_8												((uint8_t) 0x08)
    #define ASI_CH2_CH2_SLOT_9												((uint8_t) 0x09)
    #define ASI_CH2_CH2_SLOT_10												((uint8_t) 0x0A)
    #define ASI_CH2_CH2_SLOT_11												((uint8_t) 0x0B)
    #define ASI_CH2_CH2_SLOT_12												((uint8_t) 0x0C)
    #define ASI_CH2_CH2_SLOT_13												((uint8_t) 0x0D)
    #define ASI_CH2_CH2_SLOT_14												((uint8_t) 0x0E)
    #define ASI_CH2_CH2_SLOT_15												((uint8_t) 0x0F)
    #define ASI_CH2_CH2_SLOT_16												((uint8_t) 0x10)
    #define ASI_CH2_CH2_SLOT_17												((uint8_t) 0x11)
    #define ASI_CH2_CH2_SLOT_18												((uint8_t) 0x12)
    #define ASI_CH2_CH2_SLOT_19												((uint8_t) 0x13)
    #define ASI_CH2_CH2_SLOT_20												((uint8_t) 0x14)
    #define ASI_CH2_CH2_SLOT_21												((uint8_t) 0x15)
    #define ASI_CH2_CH2_SLOT_22												((uint8_t) 0x16)
    #define ASI_CH2_CH2_SLOT_23												((uint8_t) 0x17)
    #define ASI_CH2_CH2_SLOT_24												((uint8_t) 0x18)
    #define ASI_CH2_CH2_SLOT_25												((uint8_t) 0x19)
    #define ASI_CH2_CH2_SLOT_26												((uint8_t) 0x1A)
    #define ASI_CH2_CH2_SLOT_27												((uint8_t) 0x1B)
    #define ASI_CH2_CH2_SLOT_28												((uint8_t) 0x1C)
    #define ASI_CH2_CH2_SLOT_29												((uint8_t) 0x1D)
    #define ASI_CH2_CH2_SLOT_30												((uint8_t) 0x1E)
    #define ASI_CH2_CH2_SLOT_31												((uint8_t) 0x1F)
    #define ASI_CH2_CH2_SLOT_32												((uint8_t) 0x20)
    #define ASI_CH2_CH2_SLOT_33												((uint8_t) 0x21)
    #define ASI_CH2_CH2_SLOT_34												((uint8_t) 0x22)
    #define ASI_CH2_CH2_SLOT_35												((uint8_t) 0x23)
    #define ASI_CH2_CH2_SLOT_36												((uint8_t) 0x24)
    #define ASI_CH2_CH2_SLOT_37												((uint8_t) 0x25)
    #define ASI_CH2_CH2_SLOT_38												((uint8_t) 0x26)
    #define ASI_CH2_CH2_SLOT_39												((uint8_t) 0x27)
    #define ASI_CH2_CH2_SLOT_40												((uint8_t) 0x28)
    #define ASI_CH2_CH2_SLOT_41												((uint8_t) 0x29)
    #define ASI_CH2_CH2_SLOT_42												((uint8_t) 0x2A)
    #define ASI_CH2_CH2_SLOT_43												((uint8_t) 0x2B)
    #define ASI_CH2_CH2_SLOT_44												((uint8_t) 0x2C)
    #define ASI_CH2_CH2_SLOT_45												((uint8_t) 0x2D)
    #define ASI_CH2_CH2_SLOT_46												((uint8_t) 0x2E)
    #define ASI_CH2_CH2_SLOT_47												((uint8_t) 0x2F)
    #define ASI_CH2_CH2_SLOT_48												((uint8_t) 0x30)
    #define ASI_CH2_CH2_SLOT_49												((uint8_t) 0x31)
    #define ASI_CH2_CH2_SLOT_50												((uint8_t) 0x32)
    #define ASI_CH2_CH2_SLOT_51												((uint8_t) 0x33)
    #define ASI_CH2_CH2_SLOT_52												((uint8_t) 0x34)
    #define ASI_CH2_CH2_SLOT_53												((uint8_t) 0x35)
    #define ASI_CH2_CH2_SLOT_54												((uint8_t) 0x36)
    #define ASI_CH2_CH2_SLOT_55												((uint8_t) 0x37)
    #define ASI_CH2_CH2_SLOT_56												((uint8_t) 0x38)
    #define ASI_CH2_CH2_SLOT_57												((uint8_t) 0x39)
    #define ASI_CH2_CH2_SLOT_58												((uint8_t) 0x3A)
    #define ASI_CH2_CH2_SLOT_59												((uint8_t) 0x3B)
    #define ASI_CH2_CH2_SLOT_60												((uint8_t) 0x3C)
    #define ASI_CH2_CH2_SLOT_61												((uint8_t) 0x3D)
    #define ASI_CH2_CH2_SLOT_62												((uint8_t) 0x3E)
    #define ASI_CH2_CH2_SLOT_63												((uint8_t) 0x3F)



/* Register 0x0D (ASI_CH3) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       RESERVED      |      CH3_OUTPUT     |                                                           CH3_SLOT[5:0]                                                           |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* ASI_CH3 register */
    #define ASI_CH3_ADDRESS													((uint8_t) 0x0D)
    #define ASI_CH3_DEFAULT													((uint8_t) 0x02)

    /* CH3_OUTPUT field */
    #define ASI_CH3_CH3_OUTPUT_MASK											((uint8_t) 0x40)
    #define ASI_CH3_CH3_OUTPUT_PRIMARY										((uint8_t) 0x00)    // DEFAULT
    #define ASI_CH3_CH3_OUTPUT_SECONDARY									((uint8_t) 0x40)

    /* CH3_SLOT field */
    #define ASI_CH3_CH3_SLOT_MASK											((uint8_t) 0x3F)
    #define ASI_CH3_CH3_SLOT_0												((uint8_t) 0x00)
    #define ASI_CH3_CH3_SLOT_1												((uint8_t) 0x01)
    #define ASI_CH3_CH3_SLOT_2												((uint8_t) 0x02)    // DEFAULT
    #define ASI_CH3_CH3_SLOT_3												((uint8_t) 0x03)
    #define ASI_CH3_CH3_SLOT_4												((uint8_t) 0x04)
    #define ASI_CH3_CH3_SLOT_5												((uint8_t) 0x05)
    #define ASI_CH3_CH3_SLOT_6												((uint8_t) 0x06)
    #define ASI_CH3_CH3_SLOT_7												((uint8_t) 0x07)
    #define ASI_CH3_CH3_SLOT_8												((uint8_t) 0x08)
    #define ASI_CH3_CH3_SLOT_9												((uint8_t) 0x09)
    #define ASI_CH3_CH3_SLOT_10												((uint8_t) 0x0A)
    #define ASI_CH3_CH3_SLOT_11												((uint8_t) 0x0B)
    #define ASI_CH3_CH3_SLOT_12												((uint8_t) 0x0C)
    #define ASI_CH3_CH3_SLOT_13												((uint8_t) 0x0D)
    #define ASI_CH3_CH3_SLOT_14												((uint8_t) 0x0E)
    #define ASI_CH3_CH3_SLOT_15												((uint8_t) 0x0F)
    #define ASI_CH3_CH3_SLOT_16												((uint8_t) 0x10)
    #define ASI_CH3_CH3_SLOT_17												((uint8_t) 0x11)
    #define ASI_CH3_CH3_SLOT_18												((uint8_t) 0x12)
    #define ASI_CH3_CH3_SLOT_19												((uint8_t) 0x13)
    #define ASI_CH3_CH3_SLOT_20												((uint8_t) 0x14)
    #define ASI_CH3_CH3_SLOT_21												((uint8_t) 0x15)
    #define ASI_CH3_CH3_SLOT_22												((uint8_t) 0x16)
    #define ASI_CH3_CH3_SLOT_23												((uint8_t) 0x17)
    #define ASI_CH3_CH3_SLOT_24												((uint8_t) 0x18)
    #define ASI_CH3_CH3_SLOT_25												((uint8_t) 0x19)
    #define ASI_CH3_CH3_SLOT_26												((uint8_t) 0x1A)
    #define ASI_CH3_CH3_SLOT_27												((uint8_t) 0x1B)
    #define ASI_CH3_CH3_SLOT_28												((uint8_t) 0x1C)
    #define ASI_CH3_CH3_SLOT_29												((uint8_t) 0x1D)
    #define ASI_CH3_CH3_SLOT_30												((uint8_t) 0x1E)
    #define ASI_CH3_CH3_SLOT_31												((uint8_t) 0x1F)
    #define ASI_CH3_CH3_SLOT_32												((uint8_t) 0x20)
    #define ASI_CH3_CH3_SLOT_33												((uint8_t) 0x21)
    #define ASI_CH3_CH3_SLOT_34												((uint8_t) 0x22)
    #define ASI_CH3_CH3_SLOT_35												((uint8_t) 0x23)
    #define ASI_CH3_CH3_SLOT_36												((uint8_t) 0x24)
    #define ASI_CH3_CH3_SLOT_37												((uint8_t) 0x25)
    #define ASI_CH3_CH3_SLOT_38												((uint8_t) 0x26)
    #define ASI_CH3_CH3_SLOT_39												((uint8_t) 0x27)
    #define ASI_CH3_CH3_SLOT_40												((uint8_t) 0x28)
    #define ASI_CH3_CH3_SLOT_41												((uint8_t) 0x29)
    #define ASI_CH3_CH3_SLOT_42												((uint8_t) 0x2A)
    #define ASI_CH3_CH3_SLOT_43												((uint8_t) 0x2B)
    #define ASI_CH3_CH3_SLOT_44												((uint8_t) 0x2C)
    #define ASI_CH3_CH3_SLOT_45												((uint8_t) 0x2D)
    #define ASI_CH3_CH3_SLOT_46												((uint8_t) 0x2E)
    #define ASI_CH3_CH3_SLOT_47												((uint8_t) 0x2F)
    #define ASI_CH3_CH3_SLOT_48												((uint8_t) 0x30)
    #define ASI_CH3_CH3_SLOT_49												((uint8_t) 0x31)
    #define ASI_CH3_CH3_SLOT_50												((uint8_t) 0x32)
    #define ASI_CH3_CH3_SLOT_51												((uint8_t) 0x33)
    #define ASI_CH3_CH3_SLOT_52												((uint8_t) 0x34)
    #define ASI_CH3_CH3_SLOT_53												((uint8_t) 0x35)
    #define ASI_CH3_CH3_SLOT_54												((uint8_t) 0x36)
    #define ASI_CH3_CH3_SLOT_55												((uint8_t) 0x37)
    #define ASI_CH3_CH3_SLOT_56												((uint8_t) 0x38)
    #define ASI_CH3_CH3_SLOT_57												((uint8_t) 0x39)
    #define ASI_CH3_CH3_SLOT_58												((uint8_t) 0x3A)
    #define ASI_CH3_CH3_SLOT_59												((uint8_t) 0x3B)
    #define ASI_CH3_CH3_SLOT_60												((uint8_t) 0x3C)
    #define ASI_CH3_CH3_SLOT_61												((uint8_t) 0x3D)
    #define ASI_CH3_CH3_SLOT_62												((uint8_t) 0x3E)
    #define ASI_CH3_CH3_SLOT_63												((uint8_t) 0x3F)



/* Register 0x0E (ASI_CH4) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       RESERVED      |      CH4_OUTPUT     |                                                           CH4_SLOT[5:0]                                                           |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* ASI_CH4 register */
    #define ASI_CH4_ADDRESS													((uint8_t) 0x0E)
    #define ASI_CH4_DEFAULT													((uint8_t) 0x03)

    /* CH4_OUTPUT field */
    #define ASI_CH4_CH4_OUTPUT_MASK											((uint8_t) 0x40)
    #define ASI_CH4_CH4_OUTPUT_PRIMARY										((uint8_t) 0x00)    // DEFAULT
    #define ASI_CH4_CH4_OUTPUT_SECONDARY									((uint8_t) 0x40)

    /* CH4_SLOT field */
    #define ASI_CH4_CH4_SLOT_MASK											((uint8_t) 0x3F)
    #define ASI_CH4_CH4_SLOT_0												((uint8_t) 0x00)
    #define ASI_CH4_CH4_SLOT_1												((uint8_t) 0x01)
    #define ASI_CH4_CH4_SLOT_2												((uint8_t) 0x02)
    #define ASI_CH4_CH4_SLOT_3												((uint8_t) 0x03)    // DEFAULT
    #define ASI_CH4_CH4_SLOT_4												((uint8_t) 0x04)
    #define ASI_CH4_CH4_SLOT_5												((uint8_t) 0x05)
    #define ASI_CH4_CH4_SLOT_6												((uint8_t) 0x06)
    #define ASI_CH4_CH4_SLOT_7												((uint8_t) 0x07)
    #define ASI_CH4_CH4_SLOT_8												((uint8_t) 0x08)
    #define ASI_CH4_CH4_SLOT_9												((uint8_t) 0x09)
    #define ASI_CH4_CH4_SLOT_10												((uint8_t) 0x0A)
    #define ASI_CH4_CH4_SLOT_11												((uint8_t) 0x0B)
    #define ASI_CH4_CH4_SLOT_12												((uint8_t) 0x0C)
    #define ASI_CH4_CH4_SLOT_13												((uint8_t) 0x0D)
    #define ASI_CH4_CH4_SLOT_14												((uint8_t) 0x0E)
    #define ASI_CH4_CH4_SLOT_15												((uint8_t) 0x0F)
    #define ASI_CH4_CH4_SLOT_16												((uint8_t) 0x10)
    #define ASI_CH4_CH4_SLOT_17												((uint8_t) 0x11)
    #define ASI_CH4_CH4_SLOT_18												((uint8_t) 0x12)
    #define ASI_CH4_CH4_SLOT_19												((uint8_t) 0x13)
    #define ASI_CH4_CH4_SLOT_20												((uint8_t) 0x14)
    #define ASI_CH4_CH4_SLOT_21												((uint8_t) 0x15)
    #define ASI_CH4_CH4_SLOT_22												((uint8_t) 0x16)
    #define ASI_CH4_CH4_SLOT_23												((uint8_t) 0x17)
    #define ASI_CH4_CH4_SLOT_24												((uint8_t) 0x18)
    #define ASI_CH4_CH4_SLOT_25												((uint8_t) 0x19)
    #define ASI_CH4_CH4_SLOT_26												((uint8_t) 0x1A)
    #define ASI_CH4_CH4_SLOT_27												((uint8_t) 0x1B)
    #define ASI_CH4_CH4_SLOT_28												((uint8_t) 0x1C)
    #define ASI_CH4_CH4_SLOT_29												((uint8_t) 0x1D)
    #define ASI_CH4_CH4_SLOT_30												((uint8_t) 0x1E)
    #define ASI_CH4_CH4_SLOT_31												((uint8_t) 0x1F)
    #define ASI_CH4_CH4_SLOT_32												((uint8_t) 0x20)
    #define ASI_CH4_CH4_SLOT_33												((uint8_t) 0x21)
    #define ASI_CH4_CH4_SLOT_34												((uint8_t) 0x22)
    #define ASI_CH4_CH4_SLOT_35												((uint8_t) 0x23)
    #define ASI_CH4_CH4_SLOT_36												((uint8_t) 0x24)
    #define ASI_CH4_CH4_SLOT_37												((uint8_t) 0x25)
    #define ASI_CH4_CH4_SLOT_38												((uint8_t) 0x26)
    #define ASI_CH4_CH4_SLOT_39												((uint8_t) 0x27)
    #define ASI_CH4_CH4_SLOT_40												((uint8_t) 0x28)
    #define ASI_CH4_CH4_SLOT_41												((uint8_t) 0x29)
    #define ASI_CH4_CH4_SLOT_42												((uint8_t) 0x2A)
    #define ASI_CH4_CH4_SLOT_43												((uint8_t) 0x2B)
    #define ASI_CH4_CH4_SLOT_44												((uint8_t) 0x2C)
    #define ASI_CH4_CH4_SLOT_45												((uint8_t) 0x2D)
    #define ASI_CH4_CH4_SLOT_46												((uint8_t) 0x2E)
    #define ASI_CH4_CH4_SLOT_47												((uint8_t) 0x2F)
    #define ASI_CH4_CH4_SLOT_48												((uint8_t) 0x30)
    #define ASI_CH4_CH4_SLOT_49												((uint8_t) 0x31)
    #define ASI_CH4_CH4_SLOT_50												((uint8_t) 0x32)
    #define ASI_CH4_CH4_SLOT_51												((uint8_t) 0x33)
    #define ASI_CH4_CH4_SLOT_52												((uint8_t) 0x34)
    #define ASI_CH4_CH4_SLOT_53												((uint8_t) 0x35)
    #define ASI_CH4_CH4_SLOT_54												((uint8_t) 0x36)
    #define ASI_CH4_CH4_SLOT_55												((uint8_t) 0x37)
    #define ASI_CH4_CH4_SLOT_56												((uint8_t) 0x38)
    #define ASI_CH4_CH4_SLOT_57												((uint8_t) 0x39)
    #define ASI_CH4_CH4_SLOT_58												((uint8_t) 0x3A)
    #define ASI_CH4_CH4_SLOT_59												((uint8_t) 0x3B)
    #define ASI_CH4_CH4_SLOT_60												((uint8_t) 0x3C)
    #define ASI_CH4_CH4_SLOT_61												((uint8_t) 0x3D)
    #define ASI_CH4_CH4_SLOT_62												((uint8_t) 0x3E)
    #define ASI_CH4_CH4_SLOT_63												((uint8_t) 0x3F)



/* Register 0x0F (ASI_CH5) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       RESERVED      |      CH5_OUTPUT     |                                                           CH5_SLOT[5:0]                                                           |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* ASI_CH5 register */
    #define ASI_CH5_ADDRESS													((uint8_t) 0x0F)
    #define ASI_CH5_DEFAULT													((uint8_t) 0x04)

    /* CH5_OUTPUT field */
    #define ASI_CH5_CH5_OUTPUT_MASK											((uint8_t) 0x40)
    #define ASI_CH5_CH5_OUTPUT_PRIMARY										((uint8_t) 0x00)    // DEFAULT
    #define ASI_CH5_CH5_OUTPUT_SECONDARY									((uint8_t) 0x40)

    /* CH5_SLOT field */
    #define ASI_CH5_CH5_SLOT_MASK											((uint8_t) 0x3F)
    #define ASI_CH5_CH5_SLOT_0												((uint8_t) 0x00)
    #define ASI_CH5_CH5_SLOT_1												((uint8_t) 0x01)
    #define ASI_CH5_CH5_SLOT_2												((uint8_t) 0x02)
    #define ASI_CH5_CH5_SLOT_3												((uint8_t) 0x03)
    #define ASI_CH5_CH5_SLOT_4												((uint8_t) 0x04)    // DEFAULT
    #define ASI_CH5_CH5_SLOT_5												((uint8_t) 0x05)
    #define ASI_CH5_CH5_SLOT_6												((uint8_t) 0x06)
    #define ASI_CH5_CH5_SLOT_7												((uint8_t) 0x07)
    #define ASI_CH5_CH5_SLOT_8												((uint8_t) 0x08)
    #define ASI_CH5_CH5_SLOT_9												((uint8_t) 0x09)
    #define ASI_CH5_CH5_SLOT_10												((uint8_t) 0x0A)
    #define ASI_CH5_CH5_SLOT_11												((uint8_t) 0x0B)
    #define ASI_CH5_CH5_SLOT_12												((uint8_t) 0x0C)
    #define ASI_CH5_CH5_SLOT_13												((uint8_t) 0x0D)
    #define ASI_CH5_CH5_SLOT_14												((uint8_t) 0x0E)
    #define ASI_CH5_CH5_SLOT_15												((uint8_t) 0x0F)
    #define ASI_CH5_CH5_SLOT_16												((uint8_t) 0x10)
    #define ASI_CH5_CH5_SLOT_17												((uint8_t) 0x11)
    #define ASI_CH5_CH5_SLOT_18												((uint8_t) 0x12)
    #define ASI_CH5_CH5_SLOT_19												((uint8_t) 0x13)
    #define ASI_CH5_CH5_SLOT_20												((uint8_t) 0x14)
    #define ASI_CH5_CH5_SLOT_21												((uint8_t) 0x15)
    #define ASI_CH5_CH5_SLOT_22												((uint8_t) 0x16)
    #define ASI_CH5_CH5_SLOT_23												((uint8_t) 0x17)
    #define ASI_CH5_CH5_SLOT_24												((uint8_t) 0x18)
    #define ASI_CH5_CH5_SLOT_25												((uint8_t) 0x19)
    #define ASI_CH5_CH5_SLOT_26												((uint8_t) 0x1A)
    #define ASI_CH5_CH5_SLOT_27												((uint8_t) 0x1B)
    #define ASI_CH5_CH5_SLOT_28												((uint8_t) 0x1C)
    #define ASI_CH5_CH5_SLOT_29												((uint8_t) 0x1D)
    #define ASI_CH5_CH5_SLOT_30												((uint8_t) 0x1E)
    #define ASI_CH5_CH5_SLOT_31												((uint8_t) 0x1F)
    #define ASI_CH5_CH5_SLOT_32												((uint8_t) 0x20)
    #define ASI_CH5_CH5_SLOT_33												((uint8_t) 0x21)
    #define ASI_CH5_CH5_SLOT_34												((uint8_t) 0x22)
    #define ASI_CH5_CH5_SLOT_35												((uint8_t) 0x23)
    #define ASI_CH5_CH5_SLOT_36												((uint8_t) 0x24)
    #define ASI_CH5_CH5_SLOT_37												((uint8_t) 0x25)
    #define ASI_CH5_CH5_SLOT_38												((uint8_t) 0x26)
    #define ASI_CH5_CH5_SLOT_39												((uint8_t) 0x27)
    #define ASI_CH5_CH5_SLOT_40												((uint8_t) 0x28)
    #define ASI_CH5_CH5_SLOT_41												((uint8_t) 0x29)
    #define ASI_CH5_CH5_SLOT_42												((uint8_t) 0x2A)
    #define ASI_CH5_CH5_SLOT_43												((uint8_t) 0x2B)
    #define ASI_CH5_CH5_SLOT_44												((uint8_t) 0x2C)
    #define ASI_CH5_CH5_SLOT_45												((uint8_t) 0x2D)
    #define ASI_CH5_CH5_SLOT_46												((uint8_t) 0x2E)
    #define ASI_CH5_CH5_SLOT_47												((uint8_t) 0x2F)
    #define ASI_CH5_CH5_SLOT_48												((uint8_t) 0x30)
    #define ASI_CH5_CH5_SLOT_49												((uint8_t) 0x31)
    #define ASI_CH5_CH5_SLOT_50												((uint8_t) 0x32)
    #define ASI_CH5_CH5_SLOT_51												((uint8_t) 0x33)
    #define ASI_CH5_CH5_SLOT_52												((uint8_t) 0x34)
    #define ASI_CH5_CH5_SLOT_53												((uint8_t) 0x35)
    #define ASI_CH5_CH5_SLOT_54												((uint8_t) 0x36)
    #define ASI_CH5_CH5_SLOT_55												((uint8_t) 0x37)
    #define ASI_CH5_CH5_SLOT_56												((uint8_t) 0x38)
    #define ASI_CH5_CH5_SLOT_57												((uint8_t) 0x39)
    #define ASI_CH5_CH5_SLOT_58												((uint8_t) 0x3A)
    #define ASI_CH5_CH5_SLOT_59												((uint8_t) 0x3B)
    #define ASI_CH5_CH5_SLOT_60												((uint8_t) 0x3C)
    #define ASI_CH5_CH5_SLOT_61												((uint8_t) 0x3D)
    #define ASI_CH5_CH5_SLOT_62												((uint8_t) 0x3E)
    #define ASI_CH5_CH5_SLOT_63												((uint8_t) 0x3F)



/* Register 0x10 (ASI_CH6) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       RESERVED      |      CH6_OUTPUT     |                                                           CH6_SLOT[5:0]                                                           |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* ASI_CH6 register */
    #define ASI_CH6_ADDRESS													((uint8_t) 0x10)
    #define ASI_CH6_DEFAULT													((uint8_t) 0x05)

    /* CH6_OUTPUT field */
    #define ASI_CH6_CH6_OUTPUT_MASK											((uint8_t) 0x40)
    #define ASI_CH6_CH6_OUTPUT_PRIMARY										((uint8_t) 0x00)    // DEFAULT
    #define ASI_CH6_CH6_OUTPUT_SECONDARY									((uint8_t) 0x40)

    /* CH6_SLOT field */
    #define ASI_CH6_CH6_SLOT_MASK											((uint8_t) 0x3F)
    #define ASI_CH6_CH6_SLOT_0												((uint8_t) 0x00)
    #define ASI_CH6_CH6_SLOT_1												((uint8_t) 0x01)
    #define ASI_CH6_CH6_SLOT_2												((uint8_t) 0x02)
    #define ASI_CH6_CH6_SLOT_3												((uint8_t) 0x03)
    #define ASI_CH6_CH6_SLOT_4												((uint8_t) 0x04)
    #define ASI_CH6_CH6_SLOT_5												((uint8_t) 0x05)    // DEFAULT
    #define ASI_CH6_CH6_SLOT_6												((uint8_t) 0x06)
    #define ASI_CH6_CH6_SLOT_7												((uint8_t) 0x07)
    #define ASI_CH6_CH6_SLOT_8												((uint8_t) 0x08)
    #define ASI_CH6_CH6_SLOT_9												((uint8_t) 0x09)
    #define ASI_CH6_CH6_SLOT_10												((uint8_t) 0x0A)
    #define ASI_CH6_CH6_SLOT_11												((uint8_t) 0x0B)
    #define ASI_CH6_CH6_SLOT_12												((uint8_t) 0x0C)
    #define ASI_CH6_CH6_SLOT_13												((uint8_t) 0x0D)
    #define ASI_CH6_CH6_SLOT_14												((uint8_t) 0x0E)
    #define ASI_CH6_CH6_SLOT_15												((uint8_t) 0x0F)
    #define ASI_CH6_CH6_SLOT_16												((uint8_t) 0x10)
    #define ASI_CH6_CH6_SLOT_17												((uint8_t) 0x11)
    #define ASI_CH6_CH6_SLOT_18												((uint8_t) 0x12)
    #define ASI_CH6_CH6_SLOT_19												((uint8_t) 0x13)
    #define ASI_CH6_CH6_SLOT_20												((uint8_t) 0x14)
    #define ASI_CH6_CH6_SLOT_21												((uint8_t) 0x15)
    #define ASI_CH6_CH6_SLOT_22												((uint8_t) 0x16)
    #define ASI_CH6_CH6_SLOT_23												((uint8_t) 0x17)
    #define ASI_CH6_CH6_SLOT_24												((uint8_t) 0x18)
    #define ASI_CH6_CH6_SLOT_25												((uint8_t) 0x19)
    #define ASI_CH6_CH6_SLOT_26												((uint8_t) 0x1A)
    #define ASI_CH6_CH6_SLOT_27												((uint8_t) 0x1B)
    #define ASI_CH6_CH6_SLOT_28												((uint8_t) 0x1C)
    #define ASI_CH6_CH6_SLOT_29												((uint8_t) 0x1D)
    #define ASI_CH6_CH6_SLOT_30												((uint8_t) 0x1E)
    #define ASI_CH6_CH6_SLOT_31												((uint8_t) 0x1F)
    #define ASI_CH6_CH6_SLOT_32												((uint8_t) 0x20)
    #define ASI_CH6_CH6_SLOT_33												((uint8_t) 0x21)
    #define ASI_CH6_CH6_SLOT_34												((uint8_t) 0x22)
    #define ASI_CH6_CH6_SLOT_35												((uint8_t) 0x23)
    #define ASI_CH6_CH6_SLOT_36												((uint8_t) 0x24)
    #define ASI_CH6_CH6_SLOT_37												((uint8_t) 0x25)
    #define ASI_CH6_CH6_SLOT_38												((uint8_t) 0x26)
    #define ASI_CH6_CH6_SLOT_39												((uint8_t) 0x27)
    #define ASI_CH6_CH6_SLOT_40												((uint8_t) 0x28)
    #define ASI_CH6_CH6_SLOT_41												((uint8_t) 0x29)
    #define ASI_CH6_CH6_SLOT_42												((uint8_t) 0x2A)
    #define ASI_CH6_CH6_SLOT_43												((uint8_t) 0x2B)
    #define ASI_CH6_CH6_SLOT_44												((uint8_t) 0x2C)
    #define ASI_CH6_CH6_SLOT_45												((uint8_t) 0x2D)
    #define ASI_CH6_CH6_SLOT_46												((uint8_t) 0x2E)
    #define ASI_CH6_CH6_SLOT_47												((uint8_t) 0x2F)
    #define ASI_CH6_CH6_SLOT_48												((uint8_t) 0x30)
    #define ASI_CH6_CH6_SLOT_49												((uint8_t) 0x31)
    #define ASI_CH6_CH6_SLOT_50												((uint8_t) 0x32)
    #define ASI_CH6_CH6_SLOT_51												((uint8_t) 0x33)
    #define ASI_CH6_CH6_SLOT_52												((uint8_t) 0x34)
    #define ASI_CH6_CH6_SLOT_53												((uint8_t) 0x35)
    #define ASI_CH6_CH6_SLOT_54												((uint8_t) 0x36)
    #define ASI_CH6_CH6_SLOT_55												((uint8_t) 0x37)
    #define ASI_CH6_CH6_SLOT_56												((uint8_t) 0x38)
    #define ASI_CH6_CH6_SLOT_57												((uint8_t) 0x39)
    #define ASI_CH6_CH6_SLOT_58												((uint8_t) 0x3A)
    #define ASI_CH6_CH6_SLOT_59												((uint8_t) 0x3B)
    #define ASI_CH6_CH6_SLOT_60												((uint8_t) 0x3C)
    #define ASI_CH6_CH6_SLOT_61												((uint8_t) 0x3D)
    #define ASI_CH6_CH6_SLOT_62												((uint8_t) 0x3E)
    #define ASI_CH6_CH6_SLOT_63												((uint8_t) 0x3F)



/* Register 0x11 (ASI_CH7) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       RESERVED      |      CH7_OUTPUT     |                                                           CH7_SLOT[5:0]                                                           |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* ASI_CH7 register */
    #define ASI_CH7_ADDRESS													((uint8_t) 0x11)
    #define ASI_CH7_DEFAULT													((uint8_t) 0x06)

    /* CH7_OUTPUT field */
    #define ASI_CH7_CH7_OUTPUT_MASK											((uint8_t) 0x40)
    #define ASI_CH7_CH7_OUTPUT_PRIMARY										((uint8_t) 0x00)    // DEFAULT
    #define ASI_CH7_CH7_OUTPUT_SECONDARY									((uint8_t) 0x40)

    /* CH7_SLOT field */
    #define ASI_CH7_CH7_SLOT_MASK											((uint8_t) 0x3F)
    #define ASI_CH7_CH7_SLOT_0												((uint8_t) 0x00)
    #define ASI_CH7_CH7_SLOT_1												((uint8_t) 0x01)
    #define ASI_CH7_CH7_SLOT_2												((uint8_t) 0x02)
    #define ASI_CH7_CH7_SLOT_3												((uint8_t) 0x03)
    #define ASI_CH7_CH7_SLOT_4												((uint8_t) 0x04)
    #define ASI_CH7_CH7_SLOT_5												((uint8_t) 0x05)
    #define ASI_CH7_CH7_SLOT_6												((uint8_t) 0x06)    // DEFAULT
    #define ASI_CH7_CH7_SLOT_7												((uint8_t) 0x07)
    #define ASI_CH7_CH7_SLOT_8												((uint8_t) 0x08)
    #define ASI_CH7_CH7_SLOT_9												((uint8_t) 0x09)
    #define ASI_CH7_CH7_SLOT_10												((uint8_t) 0x0A)
    #define ASI_CH7_CH7_SLOT_11												((uint8_t) 0x0B)
    #define ASI_CH7_CH7_SLOT_12												((uint8_t) 0x0C)
    #define ASI_CH7_CH7_SLOT_13												((uint8_t) 0x0D)
    #define ASI_CH7_CH7_SLOT_14												((uint8_t) 0x0E)
    #define ASI_CH7_CH7_SLOT_15												((uint8_t) 0x0F)
    #define ASI_CH7_CH7_SLOT_16												((uint8_t) 0x10)
    #define ASI_CH7_CH7_SLOT_17												((uint8_t) 0x11)
    #define ASI_CH7_CH7_SLOT_18												((uint8_t) 0x12)
    #define ASI_CH7_CH7_SLOT_19												((uint8_t) 0x13)
    #define ASI_CH7_CH7_SLOT_20												((uint8_t) 0x14)
    #define ASI_CH7_CH7_SLOT_21												((uint8_t) 0x15)
    #define ASI_CH7_CH7_SLOT_22												((uint8_t) 0x16)
    #define ASI_CH7_CH7_SLOT_23												((uint8_t) 0x17)
    #define ASI_CH7_CH7_SLOT_24												((uint8_t) 0x18)
    #define ASI_CH7_CH7_SLOT_25												((uint8_t) 0x19)
    #define ASI_CH7_CH7_SLOT_26												((uint8_t) 0x1A)
    #define ASI_CH7_CH7_SLOT_27												((uint8_t) 0x1B)
    #define ASI_CH7_CH7_SLOT_28												((uint8_t) 0x1C)
    #define ASI_CH7_CH7_SLOT_29												((uint8_t) 0x1D)
    #define ASI_CH7_CH7_SLOT_30												((uint8_t) 0x1E)
    #define ASI_CH7_CH7_SLOT_31												((uint8_t) 0x1F)
    #define ASI_CH7_CH7_SLOT_32												((uint8_t) 0x20)
    #define ASI_CH7_CH7_SLOT_33												((uint8_t) 0x21)
    #define ASI_CH7_CH7_SLOT_34												((uint8_t) 0x22)
    #define ASI_CH7_CH7_SLOT_35												((uint8_t) 0x23)
    #define ASI_CH7_CH7_SLOT_36												((uint8_t) 0x24)
    #define ASI_CH7_CH7_SLOT_37												((uint8_t) 0x25)
    #define ASI_CH7_CH7_SLOT_38												((uint8_t) 0x26)
    #define ASI_CH7_CH7_SLOT_39												((uint8_t) 0x27)
    #define ASI_CH7_CH7_SLOT_40												((uint8_t) 0x28)
    #define ASI_CH7_CH7_SLOT_41												((uint8_t) 0x29)
    #define ASI_CH7_CH7_SLOT_42												((uint8_t) 0x2A)
    #define ASI_CH7_CH7_SLOT_43												((uint8_t) 0x2B)
    #define ASI_CH7_CH7_SLOT_44												((uint8_t) 0x2C)
    #define ASI_CH7_CH7_SLOT_45												((uint8_t) 0x2D)
    #define ASI_CH7_CH7_SLOT_46												((uint8_t) 0x2E)
    #define ASI_CH7_CH7_SLOT_47												((uint8_t) 0x2F)
    #define ASI_CH7_CH7_SLOT_48												((uint8_t) 0x30)
    #define ASI_CH7_CH7_SLOT_49												((uint8_t) 0x31)
    #define ASI_CH7_CH7_SLOT_50												((uint8_t) 0x32)
    #define ASI_CH7_CH7_SLOT_51												((uint8_t) 0x33)
    #define ASI_CH7_CH7_SLOT_52												((uint8_t) 0x34)
    #define ASI_CH7_CH7_SLOT_53												((uint8_t) 0x35)
    #define ASI_CH7_CH7_SLOT_54												((uint8_t) 0x36)
    #define ASI_CH7_CH7_SLOT_55												((uint8_t) 0x37)
    #define ASI_CH7_CH7_SLOT_56												((uint8_t) 0x38)
    #define ASI_CH7_CH7_SLOT_57												((uint8_t) 0x39)
    #define ASI_CH7_CH7_SLOT_58												((uint8_t) 0x3A)
    #define ASI_CH7_CH7_SLOT_59												((uint8_t) 0x3B)
    #define ASI_CH7_CH7_SLOT_60												((uint8_t) 0x3C)
    #define ASI_CH7_CH7_SLOT_61												((uint8_t) 0x3D)
    #define ASI_CH7_CH7_SLOT_62												((uint8_t) 0x3E)
    #define ASI_CH7_CH7_SLOT_63												((uint8_t) 0x3F)



/* Register 0x12 (ASI_CH8) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       RESERVED      |      CH8_OUTPUT     |                                                           CH8_SLOT[5:0]                                                           |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* ASI_CH8 register */
    #define ASI_CH8_ADDRESS													((uint8_t) 0x12)
    #define ASI_CH8_DEFAULT													((uint8_t) 0x07)

    /* CH8_OUTPUT field */
    #define ASI_CH8_CH8_OUTPUT_MASK											((uint8_t) 0x40)
    #define ASI_CH8_CH8_OUTPUT_PRIMARY										((uint8_t) 0x00)    // DEFAULT
    #define ASI_CH8_CH8_OUTPUT_SECONDARY									((uint8_t) 0x40)

    /* CH8_SLOT field */
    #define ASI_CH8_CH8_SLOT_MASK											((uint8_t) 0x3F)
    #define ASI_CH8_CH8_SLOT_0												((uint8_t) 0x00)
    #define ASI_CH8_CH8_SLOT_1												((uint8_t) 0x01)
    #define ASI_CH8_CH8_SLOT_2												((uint8_t) 0x02)
    #define ASI_CH8_CH8_SLOT_3												((uint8_t) 0x03)
    #define ASI_CH8_CH8_SLOT_4												((uint8_t) 0x04)
    #define ASI_CH8_CH8_SLOT_5												((uint8_t) 0x05)
    #define ASI_CH8_CH8_SLOT_6												((uint8_t) 0x06)
    #define ASI_CH8_CH8_SLOT_7												((uint8_t) 0x07)    // DEFAULT
    #define ASI_CH8_CH8_SLOT_8												((uint8_t) 0x08)
    #define ASI_CH8_CH8_SLOT_9												((uint8_t) 0x09)
    #define ASI_CH8_CH8_SLOT_10												((uint8_t) 0x0A)
    #define ASI_CH8_CH8_SLOT_11												((uint8_t) 0x0B)
    #define ASI_CH8_CH8_SLOT_12												((uint8_t) 0x0C)
    #define ASI_CH8_CH8_SLOT_13												((uint8_t) 0x0D)
    #define ASI_CH8_CH8_SLOT_14												((uint8_t) 0x0E)
    #define ASI_CH8_CH8_SLOT_15												((uint8_t) 0x0F)
    #define ASI_CH8_CH8_SLOT_16												((uint8_t) 0x10)
    #define ASI_CH8_CH8_SLOT_17												((uint8_t) 0x11)
    #define ASI_CH8_CH8_SLOT_18												((uint8_t) 0x12)
    #define ASI_CH8_CH8_SLOT_19												((uint8_t) 0x13)
    #define ASI_CH8_CH8_SLOT_20												((uint8_t) 0x14)
    #define ASI_CH8_CH8_SLOT_21												((uint8_t) 0x15)
    #define ASI_CH8_CH8_SLOT_22												((uint8_t) 0x16)
    #define ASI_CH8_CH8_SLOT_23												((uint8_t) 0x17)
    #define ASI_CH8_CH8_SLOT_24												((uint8_t) 0x18)
    #define ASI_CH8_CH8_SLOT_25												((uint8_t) 0x19)
    #define ASI_CH8_CH8_SLOT_26												((uint8_t) 0x1A)
    #define ASI_CH8_CH8_SLOT_27												((uint8_t) 0x1B)
    #define ASI_CH8_CH8_SLOT_28												((uint8_t) 0x1C)
    #define ASI_CH8_CH8_SLOT_29												((uint8_t) 0x1D)
    #define ASI_CH8_CH8_SLOT_30												((uint8_t) 0x1E)
    #define ASI_CH8_CH8_SLOT_31												((uint8_t) 0x1F)
    #define ASI_CH8_CH8_SLOT_32												((uint8_t) 0x20)
    #define ASI_CH8_CH8_SLOT_33												((uint8_t) 0x21)
    #define ASI_CH8_CH8_SLOT_34												((uint8_t) 0x22)
    #define ASI_CH8_CH8_SLOT_35												((uint8_t) 0x23)
    #define ASI_CH8_CH8_SLOT_36												((uint8_t) 0x24)
    #define ASI_CH8_CH8_SLOT_37												((uint8_t) 0x25)
    #define ASI_CH8_CH8_SLOT_38												((uint8_t) 0x26)
    #define ASI_CH8_CH8_SLOT_39												((uint8_t) 0x27)
    #define ASI_CH8_CH8_SLOT_40												((uint8_t) 0x28)
    #define ASI_CH8_CH8_SLOT_41												((uint8_t) 0x29)
    #define ASI_CH8_CH8_SLOT_42												((uint8_t) 0x2A)
    #define ASI_CH8_CH8_SLOT_43												((uint8_t) 0x2B)
    #define ASI_CH8_CH8_SLOT_44												((uint8_t) 0x2C)
    #define ASI_CH8_CH8_SLOT_45												((uint8_t) 0x2D)
    #define ASI_CH8_CH8_SLOT_46												((uint8_t) 0x2E)
    #define ASI_CH8_CH8_SLOT_47												((uint8_t) 0x2F)
    #define ASI_CH8_CH8_SLOT_48												((uint8_t) 0x30)
    #define ASI_CH8_CH8_SLOT_49												((uint8_t) 0x31)
    #define ASI_CH8_CH8_SLOT_50												((uint8_t) 0x32)
    #define ASI_CH8_CH8_SLOT_51												((uint8_t) 0x33)
    #define ASI_CH8_CH8_SLOT_52												((uint8_t) 0x34)
    #define ASI_CH8_CH8_SLOT_53												((uint8_t) 0x35)
    #define ASI_CH8_CH8_SLOT_54												((uint8_t) 0x36)
    #define ASI_CH8_CH8_SLOT_55												((uint8_t) 0x37)
    #define ASI_CH8_CH8_SLOT_56												((uint8_t) 0x38)
    #define ASI_CH8_CH8_SLOT_57												((uint8_t) 0x39)
    #define ASI_CH8_CH8_SLOT_58												((uint8_t) 0x3A)
    #define ASI_CH8_CH8_SLOT_59												((uint8_t) 0x3B)
    #define ASI_CH8_CH8_SLOT_60												((uint8_t) 0x3C)
    #define ASI_CH8_CH8_SLOT_61												((uint8_t) 0x3D)
    #define ASI_CH8_CH8_SLOT_62												((uint8_t) 0x3E)
    #define ASI_CH8_CH8_SLOT_63												((uint8_t) 0x3F)



/* Register 0x13 (MST_CFG0) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |     MST_SLV_CFG     |     AUTO_CLK_CFG    |  AUTO_MODE_PLL_DIS  |   BCLK_FSYNC_GATE   |       FS_MODE       |                        MCLK_FREQ_SEL[2:0]                       |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* MST_CFG0 register */
    #define MST_CFG0_ADDRESS												((uint8_t) 0x13)
    #define MST_CFG0_DEFAULT												((uint8_t) 0x02)

    /* MST_SLV_CFG field */
    #define MST_CFG0_MST_SLV_CFG_MASK										((uint8_t) 0x80)
    #define MST_CFG0_MST_SLV_CFG_SLAVE										((uint8_t) 0x00)    // DEFAULT
    #define MST_CFG0_MST_SLV_CFG_MASTER										((uint8_t) 0x80)

    /* AUTO_CLK_CFG field */
    #define MST_CFG0_AUTO_CLK_CFG_MASK										((uint8_t) 0x40)
    #define MST_CFG0_AUTO_CLK_CFG_ENABLED									((uint8_t) 0x00)    // DEFAULT
    #define MST_CFG0_AUTO_CLK_CFG_DISABLED									((uint8_t) 0x40)

    /* AUTO_MODE_PLL_DIS field */
    #define MST_CFG0_AUTO_MODE_PLL_DIS_MASK									((uint8_t) 0x20)
    #define MST_CFG0_AUTO_MODE_PLL_DIS_ENABLED								((uint8_t) 0x00)    // DEFAULT
    #define MST_CFG0_AUTO_MODE_PLL_DIS_DISABLED								((uint8_t) 0x20)

    /* BCLK_FSYNC_GATE field */
    #define MST_CFG0_BCLK_FSYNC_GATE_MASK									((uint8_t) 0x10)
    #define MST_CFG0_BCLK_FSYNC_GATE_NO_GATING								((uint8_t) 0x00)    // DEFAULT
    #define MST_CFG0_BCLK_FSYNC_GATE_FORCED_GATING							((uint8_t) 0x10)

    /* FS_MODE field */
    #define MST_CFG0_FS_MODE_MASK											((uint8_t) 0x08)
    #define MST_CFG0_FS_MODE_48_KHZ											((uint8_t) 0x00)    // DEFAULT
    #define MST_CFG0_FS_MODE_44P1_KHZ										((uint8_t) 0x08)

    /* MCLK_FREQ_SEL field */
    #define MST_CFG0_MCLK_FREQ_SEL_MASK										((uint8_t) 0x07)
    #define MST_CFG0_MCLK_FREQ_SEL_12_MHZ									((uint8_t) 0x00)
    #define MST_CFG0_MCLK_FREQ_SEL_12P288_MHZ								((uint8_t) 0x01)
    #define MST_CFG0_MCLK_FREQ_SEL_13_MHZ									((uint8_t) 0x02)    // DEFAULT
    #define MST_CFG0_MCLK_FREQ_SEL_16_MHZ									((uint8_t) 0x03)
    #define MST_CFG0_MCLK_FREQ_SEL_19P2_MHZ									((uint8_t) 0x04)
    #define MST_CFG0_MCLK_FREQ_SEL_19P68_MHz								((uint8_t) 0x05)
    #define MST_CFG0_MCLK_FREQ_SEL_24_MHZ									((uint8_t) 0x06)
    #define MST_CFG0_MCLK_FREQ_SEL_24P576_MHZ								((uint8_t) 0x07)



/* Register 0x14 (MST_CFG1) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                      FS_RATE[3:0]                                     |                                   FS_BCLK_RATIO[3:0]                                  |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* MST_CFG1 register */
    #define MST_CFG1_ADDRESS												((uint8_t) 0x14)
    #define MST_CFG1_DEFAULT												((uint8_t) 0x48)

    /* FS_RATE field */
    #define MST_CFG1_FS_RATE_MASK											((uint8_t) 0xF0)
    #define MST_CFG1_FS_RATE_7P35_8_KHZ										((uint8_t) 0x00)
    #define MST_CFG1_FS_RATE_14P7_16_KHZ									((uint8_t) 0x10)
    #define MST_CFG1_FS_RATE_22P05_24_KHZ									((uint8_t) 0x20)
    #define MST_CFG1_FS_RATE_29P4_32_KHZ									((uint8_t) 0x30)
    #define MST_CFG1_FS_RATE_44P1_48_KHZ									((uint8_t) 0x40)    // DEFAULT
    #define MST_CFG1_FS_RATE_88P2_96_KHZ									((uint8_t) 0x50)
    #define MST_CFG1_FS_RATE_176P4_192_KHZ									((uint8_t) 0x60)
    #define MST_CFG1_FS_RATE_352P8_384_KHZ									((uint8_t) 0x70)
    #define MST_CFG1_FS_RATE_705P6_768_KHZ									((uint8_t) 0x80)

    /* FS_BCLK_RATIO field */
    #define MST_CFG1_FS_BCLK_RATIO_MASK										((uint8_t) 0x0F)
    #define MST_CFG1_FS_BCLK_RATIO_16										((uint8_t) 0x00)
    #define MST_CFG1_FS_BCLK_RATIO_24										((uint8_t) 0x01)
    #define MST_CFG1_FS_BCLK_RATIO_32										((uint8_t) 0x02)
    #define MST_CFG1_FS_BCLK_RATIO_48										((uint8_t) 0x03)
    #define MST_CFG1_FS_BCLK_RATIO_64										((uint8_t) 0x04)
    #define MST_CFG1_FS_BCLK_RATIO_96										((uint8_t) 0x05)
    #define MST_CFG1_FS_BCLK_RATIO_128										((uint8_t) 0x06)
    #define MST_CFG1_FS_BCLK_RATIO_192										((uint8_t) 0x07)
    #define MST_CFG1_FS_BCLK_RATIO_256										((uint8_t) 0x08)    // DEFAULT
    #define MST_CFG1_FS_BCLK_RATIO_384										((uint8_t) 0x09)
    #define MST_CFG1_FS_BCLK_RATIO_512										((uint8_t) 0x0A)
    #define MST_CFG1_FS_BCLK_RATIO_1024										((uint8_t) 0x0B)
    #define MST_CFG1_FS_BCLK_RATIO_2048										((uint8_t) 0x0C)



/* Register 0x15 (ASI_STS) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                    FS_RATE_STS[3:0]                                   |                                   FS_RATIO_STS[3:0]                                   |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* ASI_STS register */
    #define ASI_STS_ADDRESS													((uint8_t) 0x15)
    #define ASI_STS_DEFAULT													((uint8_t) 0xFF)

    /* FS_RATE_STS field */
    #define ASI_STS_FS_RATE_STS_MASK										((uint8_t) 0xF0)
    #define ASI_STS_FS_RATE_STS_7P35_8_KHZ									((uint8_t) 0x00)
    #define ASI_STS_FS_RATE_STS_14P7_16_KHZ									((uint8_t) 0x10)
    #define ASI_STS_FS_RATE_STS_22P05_24_KHZ								((uint8_t) 0x20)
    #define ASI_STS_FS_RATE_STS_29P4_32_KHZ									((uint8_t) 0x30)
    #define ASI_STS_FS_RATE_STS_44P1_48_KHZ									((uint8_t) 0x40)
    #define ASI_STS_FS_RATE_STS_88P2_96_KHZ									((uint8_t) 0x50)
    #define ASI_STS_FS_RATE_STS_176P4_192_KHZ								((uint8_t) 0x60)
    #define ASI_STS_FS_RATE_STS_352P8_384_KHZ								((uint8_t) 0x70)
    #define ASI_STS_FS_RATE_STS_705P6_768_KHZ								((uint8_t) 0x80)

    /* FS_RATIO_STS field */
    #define ASI_STS_FS_RATIO_STS_MASK										((uint8_t) 0x0F)
    #define ASI_STS_FS_RATIO_STS_16											((uint8_t) 0x00)
    #define ASI_STS_FS_RATIO_STS_24											((uint8_t) 0x01)
    #define ASI_STS_FS_RATIO_STS_32											((uint8_t) 0x02)
    #define ASI_STS_FS_RATIO_STS_48											((uint8_t) 0x03)
    #define ASI_STS_FS_RATIO_STS_64											((uint8_t) 0x04)
    #define ASI_STS_FS_RATIO_STS_96											((uint8_t) 0x05)
    #define ASI_STS_FS_RATIO_STS_128										((uint8_t) 0x06)
    #define ASI_STS_FS_RATIO_STS_192										((uint8_t) 0x07)
    #define ASI_STS_FS_RATIO_STS_256										((uint8_t) 0x08)
    #define ASI_STS_FS_RATIO_STS_384										((uint8_t) 0x09)
    #define ASI_STS_FS_RATIO_STS_512										((uint8_t) 0x0A)
    #define ASI_STS_FS_RATIO_STS_1024										((uint8_t) 0x0B)
    #define ASI_STS_FS_RATIO_STS_2048										((uint8_t) 0x0C)



/* Register 0x16 (CLK_SRC) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * | DIS_PLL_SLV_CLK_SRC |  MCLK_FREQ_SEL_MODE |                       MCLK_RATIO_SEL[2:0]                       |                          RESERVED[2:0]                          |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CLK_SRC register */
    #define CLK_SRC_ADDRESS													((uint8_t) 0x16)
    #define CLK_SRC_DEFAULT													((uint8_t) 0x10)

    /* DIS_PLL_SLV_CLK_SRC field */
    #define CLK_SRC_DIS_PLL_SLV_CLK_SRC_MASK								((uint8_t) 0x80)
    #define CLK_SRC_DIS_PLL_SLV_CLK_SRC_BCLK								((uint8_t) 0x00)    // DEFAULT
    #define CLK_SRC_DIS_PLL_SLV_CLK_SRC_MCLK								((uint8_t) 0x80)

    /* MCLK_FREQ_SEL_MODE field */
    #define CLK_SRC_MCLK_FREQ_SEL_MODE_MASK									((uint8_t) 0x40)
    #define CLK_SRC_MCLK_FREQ_SEL_MODE_MCLK_FREQ_SEL						((uint8_t) 0x00)    // DEFAULT
    #define CLK_SRC_MCLK_FREQ_SEL_MODE_MCLK_RATIO_SEL						((uint8_t) 0x40)

    /* MCLK_RATIO_SEL field */
    #define CLK_SRC_MCLK_RATIO_SEL_MASK										((uint8_t) 0x38)
    #define CLK_SRC_MCLK_RATIO_SEL_64										((uint8_t) 0x00)
    #define CLK_SRC_MCLK_RATIO_SEL_256										((uint8_t) 0x08)
    #define CLK_SRC_MCLK_RATIO_SEL_384										((uint8_t) 0x10)    // DEFAULT
    #define CLK_SRC_MCLK_RATIO_SEL_512										((uint8_t) 0x18)
    #define CLK_SRC_MCLK_RATIO_SEL_768										((uint8_t) 0x20)
    #define CLK_SRC_MCLK_RATIO_SEL_1024										((uint8_t) 0x28)
    #define CLK_SRC_MCLK_RATIO_SEL_1536										((uint8_t) 0x30)
    #define CLK_SRC_MCLK_RATIO_SEL_2304										((uint8_t) 0x38)



/* Register 0x1D (CLKGEN_CFG6) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                                               PLL_DMUL_LSB[7:0]                                                                               |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CLKGEN_CFG6 register */
    #define CLKGEN_CFG6_ADDRESS												((uint8_t) 0x1D)
    #define CLKGEN_CFG6_DEFAULT												((uint8_t) 0x00)



/* Register 0x20 (PDMIN_CFG) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |     PDMDIN1_EDGE    |     PDMDIN2_EDGE    |     PDMDIN3_EDGE    |     PDMDIN4_EDGE    |                                     RESERVED[3:0]                                     |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* PDMIN_CFG register */
    #define PDMIN_CFG_ADDRESS												((uint8_t) 0x20)
    #define PDMIN_CFG_DEFAULT												((uint8_t) 0x00)

    /* PDMDIN1_EDGE field */
    #define PDMIN_CFG_PDMDIN1_EDGE_MASK										((uint8_t) 0x80)
    #define PDMIN_CFG_PDMDIN1_EDGE_1NEG_2POS								((uint8_t) 0x00)    // DEFAULT
    #define PDMIN_CFG_PDMDIN1_EDGE_1POS_2NEG								((uint8_t) 0x80)

    /* PDMDIN2_EDGE field */
    #define PDMIN_CFG_PDMDIN2_EDGE_MASK										((uint8_t) 0x40)
    #define PDMIN_CFG_PDMDIN2_EDGE_3NEG_4POS								((uint8_t) 0x00)    // DEFAULT
    #define PDMIN_CFG_PDMDIN2_EDGE_3POS_4NEG								((uint8_t) 0x40)

    /* PDMDIN3_EDGE field */
    #define PDMIN_CFG_PDMDIN3_EDGE_MASK										((uint8_t) 0x20)
    #define PDMIN_CFG_PDMDIN3_EDGE_5NEG_6POS								((uint8_t) 0x00)    // DEFAULT
    #define PDMIN_CFG_PDMDIN3_EDGE_5POS_6NEG								((uint8_t) 0x20)

    /* PDMDIN4_EDGE field */
    #define PDMIN_CFG_PDMDIN4_EDGE_MASK										((uint8_t) 0x10)
    #define PDMIN_CFG_PDMDIN4_EDGE_7NEG_8POS								((uint8_t) 0x00)    // DEFAULT
    #define PDMIN_CFG_PDMDIN4_EDGE_7POS_8NEG								((uint8_t) 0x10)



/* Register 0x21 (GPIO_CFG0) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                     GPIO1_CFG[3:0]                                    |       RESERVED      |                          GPIO1_DRV[2:0]                         |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* GPIO_CFG0 register */
    #define GPIO_CFG0_ADDRESS												((uint8_t) 0x21)
    #define GPIO_CFG0_DEFAULT												((uint8_t) 0x22)

    /* GPIO1_CFG field */
    #define GPIO_CFG0_GPIO1_CFG_MASK										((uint8_t) 0xF0)
    #define GPIO_CFG0_GPIO1_CFG_DISABLED									((uint8_t) 0x00)
    #define GPIO_CFG0_GPIO1_CFG_GPO											((uint8_t) 0x10)
    #define GPIO_CFG0_GPIO1_CFG_IRQ											((uint8_t) 0x20)    // DEFAULT
    #define GPIO_CFG0_GPIO1_CFG_SDOUT2										((uint8_t) 0x30)
    #define GPIO_CFG0_GPIO1_CFG_PDMCLK										((uint8_t) 0x40)
    #define GPIO_CFG0_GPIO1_CFG_MICBIAS_EN									((uint8_t) 0x80)
    #define GPIO_CFG0_GPIO1_CFG_GPI											((uint8_t) 0x90)
    #define GPIO_CFG0_GPIO1_CFG_MCLK										((uint8_t) 0xA0)
    #define GPIO_CFG0_GPIO1_CFG_SDIN										((uint8_t) 0xB0)
    #define GPIO_CFG0_GPIO1_CFG_PDMIN1										((uint8_t) 0xC0)
    #define GPIO_CFG0_GPIO1_CFG_PDMIN2										((uint8_t) 0xD0)
    #define GPIO_CFG0_GPIO1_CFG_PDMIN3										((uint8_t) 0xE0)
    #define GPIO_CFG0_GPIO1_CFG_PDMIN4										((uint8_t) 0xF0)

    /* GPIO1_DRV field */
    #define GPIO_CFG0_GPIO1_DRV_MASK										((uint8_t) 0x07)
    #define GPIO_CFG0_GPIO1_DRV_HIZ											((uint8_t) 0x00)
    #define GPIO_CFG0_GPIO1_DRV_ACTLOW_ACTHIGH								((uint8_t) 0x01)
    #define GPIO_CFG0_GPIO1_DRV_ACTLOW_WEAKHIGH								((uint8_t) 0x02)    // DEFAULT
    #define GPIO_CFG0_GPIO1_DRV_ACTLOW_HIZ									((uint8_t) 0x03)
    #define GPIO_CFG0_GPIO1_DRV_WEAKLOW_ACTHIGH								((uint8_t) 0x04)
    #define GPIO_CFG0_GPIO1_DRV_HIZ_ACTHIGH									((uint8_t) 0x05)



/* Register 0x22 (GPO_CFG0) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                     GPO1_CFG[3:0]                                     |       RESERVED      |                          GPO1_DRV[2:0]                          |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* GPO_CFG0 register */
    #define GPO_CFG0_ADDRESS												((uint8_t) 0x22)
    #define GPO_CFG0_DEFAULT												((uint8_t) 0x00)

    /* GPO1_CFG field */
    #define GPO_CFG0_GPO1_CFG_MASK											((uint8_t) 0xF0)
    #define GPO_CFG0_GPO1_CFG_DISABLED										((uint8_t) 0x00)    // DEFAULT
    #define GPO_CFG0_GPO1_CFG_GPO											((uint8_t) 0x10)
    #define GPO_CFG0_GPO1_CFG_IRQ											((uint8_t) 0x20)
    #define GPO_CFG0_GPO1_CFG_SDOUT2										((uint8_t) 0x30)
    #define GPO_CFG0_GPO1_CFG_PDMCLK										((uint8_t) 0x40)

    /* GPO1_DRV field */
    #define GPO_CFG0_GPO1_DRV_MASK											((uint8_t) 0x07)
    #define GPO_CFG0_GPO1_DRV_HIZ											((uint8_t) 0x00)    // DEFAULT
    #define GPO_CFG0_GPO1_DRV_ACTLOW_ACTHIGH								((uint8_t) 0x01)
    #define GPO_CFG0_GPO1_DRV_ACTLOW_WEAKHIGH								((uint8_t) 0x02)
    #define GPO_CFG0_GPO1_DRV_ACTLOW_HIZ									((uint8_t) 0x03)
    #define GPO_CFG0_GPO1_DRV_WEAKLOW_ACTHIGH								((uint8_t) 0x04)
    #define GPO_CFG0_GPO1_DRV_HIZ_ACTHIGH									((uint8_t) 0x05)



/* Register 0x23 (GPO_CFG1) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                     GPO2_CFG[3:0]                                     |       RESERVED      |                          GPO2_DRV[2:0]                          |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* GPO_CFG1 register */
    #define GPO_CFG1_ADDRESS												((uint8_t) 0x23)
    #define GPO_CFG1_DEFAULT												((uint8_t) 0x00)

    /* GPO2_CFG field */
    #define GPO_CFG1_GPO2_CFG_MASK											((uint8_t) 0xF0)
    #define GPO_CFG1_GPO2_CFG_DISABLED										((uint8_t) 0x00)    // DEFAULT
    #define GPO_CFG1_GPO2_CFG_GPO											((uint8_t) 0x10)
    #define GPO_CFG1_GPO2_CFG_IRQ											((uint8_t) 0x20)
    #define GPO_CFG1_GPO2_CFG_SDOUT2										((uint8_t) 0x30)
    #define GPO_CFG1_GPO2_CFG_PDMCLK										((uint8_t) 0x40)

    /* GPO2_DRV field */
    #define GPO_CFG1_GPO2_DRV_MASK											((uint8_t) 0x07)
    #define GPO_CFG1_GPO2_DRV_HIZ											((uint8_t) 0x00)    // DEFAULT
    #define GPO_CFG1_GPO2_DRV_ACTLOW_ACTHIGH								((uint8_t) 0x01)
    #define GPO_CFG1_GPO2_DRV_ACTLOW_WEAKHIGH								((uint8_t) 0x02)
    #define GPO_CFG1_GPO2_DRV_ACTLOW_HIZ									((uint8_t) 0x03)
    #define GPO_CFG1_GPO2_DRV_WEAKLOW_ACTHIGH								((uint8_t) 0x04)
    #define GPO_CFG1_GPO2_DRV_HIZ_ACTHIGH									((uint8_t) 0x05)



/* Register 0x24 (GPO_CFG2) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                     GPO3_CFG[3:0]                                     |       RESERVED      |                          GPO3_DRV[2:0]                          |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* GPO_CFG2 register */
    #define GPO_CFG2_ADDRESS												((uint8_t) 0x24)
    #define GPO_CFG2_DEFAULT												((uint8_t) 0x00)

    /* GPO3_CFG field */
    #define GPO_CFG2_GPO3_CFG_MASK											((uint8_t) 0xF0)
    #define GPO_CFG2_GPO3_CFG_DISABLED										((uint8_t) 0x00)    // DEFAULT
    #define GPO_CFG2_GPO3_CFG_GPO											((uint8_t) 0x10)
    #define GPO_CFG2_GPO3_CFG_IRQ											((uint8_t) 0x20)
    #define GPO_CFG2_GPO3_CFG_SDOUT2										((uint8_t) 0x30)
    #define GPO_CFG2_GPO3_CFG_PDMCLK										((uint8_t) 0x40)

    /* GPO3_DRV field */
    #define GPO_CFG2_GPO3_DRV_MASK											((uint8_t) 0x07)
    #define GPO_CFG2_GPO3_DRV_HIZ											((uint8_t) 0x00)    // DEFAULT
    #define GPO_CFG2_GPO3_DRV_ACTLOW_ACTHIGH								((uint8_t) 0x01)
    #define GPO_CFG2_GPO3_DRV_ACTLOW_WEAKHIGH								((uint8_t) 0x02)
    #define GPO_CFG2_GPO3_DRV_ACTLOW_HIZ									((uint8_t) 0x03)
    #define GPO_CFG2_GPO3_DRV_WEAKLOW_ACTHIGH								((uint8_t) 0x04)
    #define GPO_CFG2_GPO3_DRV_HIZ_ACTHIGH									((uint8_t) 0x05)



/* Register 0x25 (GPO_CFG3) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                     GPO4_CFG[3:0]                                     |       RESERVED      |                          GPO4_DRV[2:0]                          |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* GPO_CFG3 register */
    #define GPO_CFG3_ADDRESS												((uint8_t) 0x25)
    #define GPO_CFG3_DEFAULT												((uint8_t) 0x00)

    /* GPO4_CFG field */
    #define GPO_CFG3_GPO4_CFG_MASK											((uint8_t) 0xF0)
    #define GPO_CFG3_GPO4_CFG_DISABLED										((uint8_t) 0x00)    // DEFAULT
    #define GPO_CFG3_GPO4_CFG_GPO											((uint8_t) 0x10)
    #define GPO_CFG3_GPO4_CFG_IRQ											((uint8_t) 0x20)
    #define GPO_CFG3_GPO4_CFG_SDOUT2										((uint8_t) 0x30)
    #define GPO_CFG3_GPO4_CFG_PDMCLK										((uint8_t) 0x40)

    /* GPO4_DRV field */
    #define GPO_CFG3_GPO4_DRV_MASK											((uint8_t) 0x07)
    #define GPO_CFG3_GPO4_DRV_HIZ											((uint8_t) 0x00)    // DEFAULT
    #define GPO_CFG3_GPO4_DRV_ACTLOW_ACTHIGH								((uint8_t) 0x01)
    #define GPO_CFG3_GPO4_DRV_ACTLOW_WEAKHIGH								((uint8_t) 0x02)
    #define GPO_CFG3_GPO4_DRV_ACTLOW_HIZ									((uint8_t) 0x03)
    #define GPO_CFG3_GPO4_DRV_WEAKLOW_ACTHIGH								((uint8_t) 0x04)
    #define GPO_CFG3_GPO4_DRV_HIZ_ACTHIGH									((uint8_t) 0x05)



/* Register 0x29 (GPO_VAL) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |      GPIO1_VAL      |       GPO1_VAL      |       GPO2_VAL      |       GPO3_VAL      |       GPO4_VAL      |                          RESERVED[2:0]                          |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* GPO_VAL register */
    #define GPO_VAL_ADDRESS													((uint8_t) 0x29)
    #define GPO_VAL_DEFAULT													((uint8_t) 0x00)

    /* GPIO1_VAL field */
    #define GPO_VAL_GPIO1_VAL_MASK											((uint8_t) 0x80)
    #define GPO_VAL_GPIO1_VAL_0												((uint8_t) 0x00)    // DEFAULT
    #define GPO_VAL_GPIO1_VAL_1												((uint8_t) 0x80)

    /* GPO1_VAL field */
    #define GPO_VAL_GPO1_VAL_MASK											((uint8_t) 0x40)
    #define GPO_VAL_GPO1_VAL_0												((uint8_t) 0x00)    // DEFAULT
    #define GPO_VAL_GPO1_VAL_1												((uint8_t) 0x40)

    /* GPO2_VAL field */
    #define GPO_VAL_GPO2_VAL_MASK											((uint8_t) 0x20)
    #define GPO_VAL_GPO2_VAL_0												((uint8_t) 0x00)    // DEFAULT
    #define GPO_VAL_GPO2_VAL_1												((uint8_t) 0x20)

    /* GPO3_VAL field */
    #define GPO_VAL_GPO3_VAL_MASK											((uint8_t) 0x10)
    #define GPO_VAL_GPO3_VAL_0												((uint8_t) 0x00)    // DEFAULT
    #define GPO_VAL_GPO3_VAL_1												((uint8_t) 0x10)

    /* GPO4_VAL field */
    #define GPO_VAL_GPO4_VAL_MASK											((uint8_t) 0x08)
    #define GPO_VAL_GPO4_VAL_0												((uint8_t) 0x00)    // DEFAULT
    #define GPO_VAL_GPO4_VAL_1												((uint8_t) 0x08)



/* Register 0x2A (GPIO_MON) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |      GPIO1_MON      |                                                                      RESERVED[6:0]                                                                      |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* GPIO_MON register */
    #define GPIO_MON_ADDRESS												((uint8_t) 0x2A)
    #define GPIO_MON_DEFAULT												((uint8_t) 0x00)

    /* GPIO1_MON field */
    #define GPIO_MON_GPIO1_MON_MASK											((uint8_t) 0x80)
    #define GPIO_MON_GPIO1_MON_0											((uint8_t) 0x00)    // DEFAULT
    #define GPIO_MON_GPIO1_MON_1											((uint8_t) 0x80)



/* Register 0x2B (GPI_CFG0) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       RESERVED      |                          GPI1_CFG[2:0]                          |       RESERVED      |                          GPI2_CFG[2:0]                          |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* GPI_CFG0 register */
    #define GPI_CFG0_ADDRESS												((uint8_t) 0x2B)
    #define GPI_CFG0_DEFAULT												((uint8_t) 0x00)

    /* GPI1_CFG field */
    #define GPI_CFG0_GPI1_CFG_MASK											((uint8_t) 0x70)
    #define GPI_CFG0_GPI1_CFG_DISABLED										((uint8_t) 0x00)    // DEFAULT
    #define GPI_CFG0_GPI1_CFG_GPI											((uint8_t) 0x10)
    #define GPI_CFG0_GPI1_CFG_MCLK											((uint8_t) 0x20)
    #define GPI_CFG0_GPI1_CFG_SDIN											((uint8_t) 0x30)
    #define GPI_CFG0_GPI1_CFG_PDMDIN1										((uint8_t) 0x40)
    #define GPI_CFG0_GPI1_CFG_PDMDIN2										((uint8_t) 0x50)
    #define GPI_CFG0_GPI1_CFG_PDMDIN3										((uint8_t) 0x60)
    #define GPI_CFG0_GPI1_CFG_PDMDIN4										((uint8_t) 0x70)

    /* GPI2_CFG field */
    #define GPI_CFG0_GPI2_CFG_MASK											((uint8_t) 0x07)
    #define GPI_CFG0_GPI2_CFG_DISABLED										((uint8_t) 0x00)    // DEFAULT
    #define GPI_CFG0_GPI2_CFG_GPI											((uint8_t) 0x01)
    #define GPI_CFG0_GPI2_CFG_MCLK											((uint8_t) 0x02)
    #define GPI_CFG0_GPI2_CFG_SDIN											((uint8_t) 0x03)
    #define GPI_CFG0_GPI2_CFG_PDMDIN1										((uint8_t) 0x04)
    #define GPI_CFG0_GPI2_CFG_PDMDIN2										((uint8_t) 0x05)
    #define GPI_CFG0_GPI2_CFG_PDMDIN3										((uint8_t) 0x06)
    #define GPI_CFG0_GPI2_CFG_PDMDIN4										((uint8_t) 0x07)



/* Register 0x2C (GPI_CFG1) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       RESERVED      |                          GPI3_CFG[2:0]                          |       RESERVED      |                          GPI4_CFG[2:0]                          |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* GPI_CFG1 register */
    #define GPI_CFG1_ADDRESS												((uint8_t) 0x2C)
    #define GPI_CFG1_DEFAULT												((uint8_t) 0x00)

    /* GPI3_CFG field */
    #define GPI_CFG1_GPI3_CFG_MASK											((uint8_t) 0x70)
    #define GPI_CFG1_GPI3_CFG_DISABLED										((uint8_t) 0x00)    // DEFAULT
    #define GPI_CFG1_GPI3_CFG_GPI											((uint8_t) 0x10)
    #define GPI_CFG1_GPI3_CFG_MCLK											((uint8_t) 0x20)
    #define GPI_CFG1_GPI3_CFG_SDIN											((uint8_t) 0x30)
    #define GPI_CFG1_GPI3_CFG_PDMDIN1										((uint8_t) 0x40)
    #define GPI_CFG1_GPI3_CFG_PDMDIN2										((uint8_t) 0x50)
    #define GPI_CFG1_GPI3_CFG_PDMDIN3										((uint8_t) 0x60)
    #define GPI_CFG1_GPI3_CFG_PDMDIN4										((uint8_t) 0x70)

    /* GPI4_CFG field */
    #define GPI_CFG1_GPI4_CFG_MASK											((uint8_t) 0x07)
    #define GPI_CFG1_GPI4_CFG_DISABLED										((uint8_t) 0x00)    // DEFAULT
    #define GPI_CFG1_GPI4_CFG_GPI											((uint8_t) 0x01)
    #define GPI_CFG1_GPI4_CFG_MCLK											((uint8_t) 0x02)
    #define GPI_CFG1_GPI4_CFG_SDIN											((uint8_t) 0x03)
    #define GPI_CFG1_GPI4_CFG_PDMDIN1										((uint8_t) 0x04)
    #define GPI_CFG1_GPI4_CFG_PDMDIN2										((uint8_t) 0x05)
    #define GPI_CFG1_GPI4_CFG_PDMDIN3										((uint8_t) 0x06)
    #define GPI_CFG1_GPI4_CFG_PDMDIN4										((uint8_t) 0x07)



/* Register 0x2F (GPI_MON) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       GPI1_MON      |       GPI2_MON      |       GPI3_MON      |       GPI4_MON      |                                     RESERVED[3:0]                                     |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* GPI_MON register */
    #define GPI_MON_ADDRESS													((uint8_t) 0x2F)
    #define GPI_MON_DEFAULT													((uint8_t) 0x00)

    /* GPI1_MON field */
    #define GPI_MON_GPI1_MON_MASK											((uint8_t) 0x80)
    #define GPI_MON_GPI1_MON_0												((uint8_t) 0x00)    // DEFAULT
    #define GPI_MON_GPI1_MON_1												((uint8_t) 0x80)

    /* GPI2_MON field */
    #define GPI_MON_GPI2_MON_MASK											((uint8_t) 0x40)
    #define GPI_MON_GPI2_MON_0												((uint8_t) 0x00)    // DEFAULT
    #define GPI_MON_GPI2_MON_1												((uint8_t) 0x40)

    /* GPI3_MON field */
    #define GPI_MON_GPI3_MON_MASK											((uint8_t) 0x20)
    #define GPI_MON_GPI3_MON_0												((uint8_t) 0x00)    // DEFAULT
    #define GPI_MON_GPI3_MON_1												((uint8_t) 0x20)

    /* GPI4_MON field */
    #define GPI_MON_GPI4_MON_MASK											((uint8_t) 0x10)
    #define GPI_MON_GPI4_MON_0												((uint8_t) 0x00)    // DEFAULT
    #define GPI_MON_GPI4_MON_1												((uint8_t) 0x10)



/* Register 0x32 (INT_CFG) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       INT_POL       |               INT_EVENT[1:0]              |               RESERVED[1:0]               |    LTCH_READ_CFG    |               RESERVED[1:0]               |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* INT_CFG register */
    #define INT_CFG_ADDRESS													((uint8_t) 0x32)
    #define INT_CFG_DEFAULT													((uint8_t) 0x00)

    /* INT_POL field */
    #define INT_CFG_INT_POL_MASK											((uint8_t) 0x80)
    #define INT_CFG_INT_POL_LOW												((uint8_t) 0x00)    // DEFAULT
    #define INT_CFG_INT_POL_HIGH											((uint8_t) 0x80)

    /* INT_EVENT field */
    #define INT_CFG_INT_EVENT_MASK											((uint8_t) 0x60)
    #define INT_CFG_INT_EVENT_ASSERTS										((uint8_t) 0x00)    // DEFAULT
    #define INT_CFG_INT_EVENT_DURATION4mS									((uint8_t) 0x40)
    #define INT_CFG_INT_EVENT_PULSE2mS										((uint8_t) 0x60)

    /* LTCH_READ_CFG field */
    #define INT_CFG_LTCH_READ_CFG_MASK										((uint8_t) 0x04)
    #define INT_CFG_LTCH_READ_CFG_ALL										((uint8_t) 0x00)    // DEFAULT
    #define INT_CFG_LTCH_READ_CFG_UNMASKED									((uint8_t) 0x04)



/* Register 0x33 (INT_MASK0) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |     ASI_CLK_ERR     |       PLL_LOCK      |                                                           RESERVED[5:0]                                                           |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* INT_MASK0 register */
    #define INT_MASK0_ADDRESS												((uint8_t) 0x33)
    #define INT_MASK0_DEFAULT												((uint8_t) 0xC1)

    /* ASI_CLK_ERR field */
    #define INT_MASK0_ASI_CLK_ERR_MASK										((uint8_t) 0x80)
    #define INT_MASK0_ASI_CLK_ERR_UNMASKED									((uint8_t) 0x00)
    #define INT_MASK0_ASI_CLK_ERR_MASK										((uint8_t) 0x80)    // DEFAULT

    /* PLL_LOCK field */
    #define INT_MASK0_PLL_LOCK_MASK											((uint8_t) 0x40)
    #define INT_MASK0_PLL_LOCK_UNMASKED										((uint8_t) 0x00)
    #define INT_MASK0_PLL_LOCK_MASK											((uint8_t) 0x40)    // DEFAULT



/* Register 0x36 (INT_LTCH0) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |     ASI_CLK_ERR     |       PLL_LOCK      |                                                           RESERVED[5:0]                                                           |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* INT_LTCH0 register */
    #define INT_LTCH0_ADDRESS												((uint8_t) 0x36)
    #define INT_LTCH0_DEFAULT												((uint8_t) 0x00)

    /* ASI_CLK_ERR field */
    #define INT_LTCH0_ASI_CLK_ERR_MASK										((uint8_t) 0x80)
    #define INT_LTCH0_ASI_CLK_ERR_NOINT										((uint8_t) 0x00)    // DEFAULT
    #define INT_LTCH0_ASI_CLK_ERR_INT										((uint8_t) 0x80)

    /* PLL_LOCK field */
    #define INT_LTCH0_PLL_LOCK_MASK											((uint8_t) 0x40)
    #define INT_LTCH0_PLL_LOCK_NOINT										((uint8_t) 0x00)    // DEFAULT
    #define INT_LTCH0_PLL_LOCK_INT											((uint8_t) 0x40)



/* Register 0x3B (BIAS_CFG) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       RESERVED      |                          MBIAS_VAL[2:0]                         |               RESERVED[1:0]               |              ADC_FSCALE[1:0]              |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* BIAS_CFG register */
    #define BIAS_CFG_ADDRESS												((uint8_t) 0x3B)
    #define BIAS_CFG_DEFAULT												((uint8_t) 0x00)

    /* MBIAS_VAL field */
    #define BIAS_CFG_MBIAS_VAL_MASK											((uint8_t) 0x70)
    #define BIAS_CFG_MBIAS_VAL_VREF											((uint8_t) 0x00)    // DEFAULT
    #define BIAS_CFG_MBIAS_VAL_VREF1P095									((uint8_t) 0x10)
    #define BIAS_CFG_MBIAS_VAL_AVDD											((uint8_t) 0x60)

    /* ADC_FSCALE field */
    #define BIAS_CFG_ADC_FSCALE_MASK										((uint8_t) 0x03)
    #define BIAS_CFG_ADC_FSCALE_2VRMS										((uint8_t) 0x00)    // DEFAULT
    #define BIAS_CFG_ADC_FSCALE_1P818VRMS									((uint8_t) 0x01)
    #define BIAS_CFG_ADC_FSCALE_1VRMS										((uint8_t) 0x02)



/* Register 0x3C (CH1_CFG0) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        INTYP        |                 INSRC[1:0]                |          DC         |                  IMP[1:0]                 |       RESERVED      |        DREEN        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH1_CFG0 register */
    #define CH1_CFG0_ADDRESS												((uint8_t) 0x3C)
    #define CH1_CFG0_DEFAULT												((uint8_t) 0x00)

    /* INTYP field */
    #define CH1_CFG0_INTYP_MASK												((uint8_t) 0x80)
    #define CH1_CFG0_INTYP_MIC												((uint8_t) 0x00)    // DEFAULT
    #define CH1_CFG0_INTYP_LINE												((uint8_t) 0x80)

    /* INSRC field */
    #define CH1_CFG0_INSRC_MASK												((uint8_t) 0x60)
    #define CH1_CFG0_INSRC_DIFF												((uint8_t) 0x00)    // DEFAULT
    #define CH1_CFG0_INSRC_SINGLE											((uint8_t) 0x20)
    #define CH1_CFG0_INSRC_PDM												((uint8_t) 0x40)

    /* DC field */
    #define CH1_CFG0_DC_MASK												((uint8_t) 0x10)
    #define CH1_CFG0_DC_AC													((uint8_t) 0x00)    // DEFAULT
    #define CH1_CFG0_DC_DC													((uint8_t) 0x10)

    /* IMP field */
    #define CH1_CFG0_IMP_MASK												((uint8_t) 0x0C)
    #define CH1_CFG0_IMP_2P5k												((uint8_t) 0x00)    // DEFAULT
    #define CH1_CFG0_IMP_10k												((uint8_t) 0x04)
    #define CH1_CFG0_IMP_20k												((uint8_t) 0x08)

    /* DREEN field */
    #define CH1_CFG0_DREEN_MASK												((uint8_t) 0x01)
    #define CH1_CFG0_DREEN_DISABLED											((uint8_t) 0x00)    // DEFAULT
    #define CH1_CFG0_DREEN_ENABLED											((uint8_t) 0x01)



/* Register 0x3D (CH1_CFG1) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                             GAIN[5:0]                                                             |               RESERVED[1:0]               |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH1_CFG1 register */
    #define CH1_CFG1_ADDRESS												((uint8_t) 0x3D)
    #define CH1_CFG1_DEFAULT												((uint8_t) 0x00)

    /* GAIN field */
    #define CH1_CFG1_GAIN_MASK												((uint8_t) 0xFC)
    #define CH1_CFG1_GAIN_0dB												((uint8_t) 0x00)    // DEFAULT
    #define CH1_CFG1_GAIN_1dB												((uint8_t) 0x04)
    #define CH1_CFG1_GAIN_2dB												((uint8_t) 0x08)
    #define CH1_CFG1_GAIN_3dB												((uint8_t) 0x0C)
    #define CH1_CFG1_GAIN_4dB												((uint8_t) 0x10)
    #define CH1_CFG1_GAIN_5dB												((uint8_t) 0x14)
    #define CH1_CFG1_GAIN_6dB												((uint8_t) 0x18)
    #define CH1_CFG1_GAIN_7dB												((uint8_t) 0x1C)
    #define CH1_CFG1_GAIN_8dB												((uint8_t) 0x20)
    #define CH1_CFG1_GAIN_9dB												((uint8_t) 0x24)
    #define CH1_CFG1_GAIN_10dB												((uint8_t) 0x28)
    #define CH1_CFG1_GAIN_11dB												((uint8_t) 0x2C)
    #define CH1_CFG1_GAIN_12dB												((uint8_t) 0x30)
    #define CH1_CFG1_GAIN_13dB												((uint8_t) 0x34)
    #define CH1_CFG1_GAIN_14dB												((uint8_t) 0x38)
    #define CH1_CFG1_GAIN_15dB												((uint8_t) 0x3C)
    #define CH1_CFG1_GAIN_16dB												((uint8_t) 0x40)
    #define CH1_CFG1_GAIN_17dB												((uint8_t) 0x44)
    #define CH1_CFG1_GAIN_18dB												((uint8_t) 0x48)
    #define CH1_CFG1_GAIN_19dB												((uint8_t) 0x4C)
    #define CH1_CFG1_GAIN_20dB												((uint8_t) 0x50)
    #define CH1_CFG1_GAIN_21dB												((uint8_t) 0x54)
    #define CH1_CFG1_GAIN_22dB												((uint8_t) 0x58)
    #define CH1_CFG1_GAIN_23dB												((uint8_t) 0x5C)
    #define CH1_CFG1_GAIN_24dB												((uint8_t) 0x60)
    #define CH1_CFG1_GAIN_25dB												((uint8_t) 0x64)
    #define CH1_CFG1_GAIN_26dB												((uint8_t) 0x68)
    #define CH1_CFG1_GAIN_27dB												((uint8_t) 0x6C)
    #define CH1_CFG1_GAIN_28dB												((uint8_t) 0x70)
    #define CH1_CFG1_GAIN_29dB												((uint8_t) 0x74)
    #define CH1_CFG1_GAIN_30dB												((uint8_t) 0x78)
    #define CH1_CFG1_GAIN_31dB												((uint8_t) 0x7C)
    #define CH1_CFG1_GAIN_32dB												((uint8_t) 0x80)
    #define CH1_CFG1_GAIN_33dB												((uint8_t) 0x84)
    #define CH1_CFG1_GAIN_34dB												((uint8_t) 0x88)
    #define CH1_CFG1_GAIN_35dB												((uint8_t) 0x8C)
    #define CH1_CFG1_GAIN_36dB												((uint8_t) 0x90)
    #define CH1_CFG1_GAIN_37dB												((uint8_t) 0x94)
    #define CH1_CFG1_GAIN_38dB												((uint8_t) 0x98)
    #define CH1_CFG1_GAIN_39dB												((uint8_t) 0x9C)
    #define CH1_CFG1_GAIN_40dB												((uint8_t) 0xA0)
    #define CH1_CFG1_GAIN_41dB												((uint8_t) 0xA4)
    #define CH1_CFG1_GAIN_42dB												((uint8_t) 0xA8)



/* Register 0x3E (CH1_CFG2) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                                                   DVOL[7:0]                                                                                   |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH1_CFG2 register */
    #define CH1_CFG2_ADDRESS												((uint8_t) 0x3E)
    #define CH1_CFG2_DEFAULT												((uint8_t) 0xC9)

    /* DVOL field */
    #define CH1_CFG2_DVOL_MASK												((uint8_t) 0xFF)
    #define CH1_CFG2_DVOL_MUTE												((uint8_t) 0x00)
    #define CH1_CFG2_DVOL_M100dB											((uint8_t) 0x01)
    #define CH1_CFG2_DVOL_M99P5dB											((uint8_t) 0x02)
    #define CH1_CFG2_DVOL_M99dB												((uint8_t) 0x03)
    #define CH1_CFG2_DVOL_M98P5dB											((uint8_t) 0x04)
    #define CH1_CFG2_DVOL_M98dB												((uint8_t) 0x05)
    #define CH1_CFG2_DVOL_M97P5dB											((uint8_t) 0x06)
    #define CH1_CFG2_DVOL_M97dB												((uint8_t) 0x07)
    #define CH1_CFG2_DVOL_M96P5dB											((uint8_t) 0x08)
    #define CH1_CFG2_DVOL_M96dB												((uint8_t) 0x09)
    #define CH1_CFG2_DVOL_M95P5dB											((uint8_t) 0x0A)
    #define CH1_CFG2_DVOL_M95dB												((uint8_t) 0x0B)
    #define CH1_CFG2_DVOL_M94P5dB											((uint8_t) 0x0C)
    #define CH1_CFG2_DVOL_M94dB												((uint8_t) 0x0D)
    #define CH1_CFG2_DVOL_M93P5dB											((uint8_t) 0x0E)
    #define CH1_CFG2_DVOL_M93dB												((uint8_t) 0x0F)
    #define CH1_CFG2_DVOL_M92P5dB											((uint8_t) 0x10)
    #define CH1_CFG2_DVOL_M92dB												((uint8_t) 0x11)
    #define CH1_CFG2_DVOL_M91P5dB											((uint8_t) 0x12)
    #define CH1_CFG2_DVOL_M91dB												((uint8_t) 0x13)
    #define CH1_CFG2_DVOL_M90P5dB											((uint8_t) 0x14)
    #define CH1_CFG2_DVOL_M90dB												((uint8_t) 0x15)
    #define CH1_CFG2_DVOL_M89P5dB											((uint8_t) 0x16)
    #define CH1_CFG2_DVOL_M89dB												((uint8_t) 0x17)
    #define CH1_CFG2_DVOL_M88P5dB											((uint8_t) 0x18)
    #define CH1_CFG2_DVOL_M88dB												((uint8_t) 0x19)
    #define CH1_CFG2_DVOL_M87P5dB											((uint8_t) 0x1A)
    #define CH1_CFG2_DVOL_M87dB												((uint8_t) 0x1B)
    #define CH1_CFG2_DVOL_M86P5dB											((uint8_t) 0x1C)
    #define CH1_CFG2_DVOL_M86dB												((uint8_t) 0x1D)
    #define CH1_CFG2_DVOL_M85P5dB											((uint8_t) 0x1E)
    #define CH1_CFG2_DVOL_M85dB												((uint8_t) 0x1F)
    #define CH1_CFG2_DVOL_M84P5dB											((uint8_t) 0x20)
    #define CH1_CFG2_DVOL_M84dB												((uint8_t) 0x21)
    #define CH1_CFG2_DVOL_M83P5dB											((uint8_t) 0x22)
    #define CH1_CFG2_DVOL_M83dB												((uint8_t) 0x23)
    #define CH1_CFG2_DVOL_M82P5dB											((uint8_t) 0x24)
    #define CH1_CFG2_DVOL_M82dB												((uint8_t) 0x25)
    #define CH1_CFG2_DVOL_M81P5dB											((uint8_t) 0x26)
    #define CH1_CFG2_DVOL_M81dB												((uint8_t) 0x27)
    #define CH1_CFG2_DVOL_M80P5dB											((uint8_t) 0x28)
    #define CH1_CFG2_DVOL_M80dB												((uint8_t) 0x29)
    #define CH1_CFG2_DVOL_M79P5dB											((uint8_t) 0x2A)
    #define CH1_CFG2_DVOL_M79dB												((uint8_t) 0x2B)
    #define CH1_CFG2_DVOL_M78P5dB											((uint8_t) 0x2C)
    #define CH1_CFG2_DVOL_M78dB												((uint8_t) 0x2D)
    #define CH1_CFG2_DVOL_M77P5dB											((uint8_t) 0x2E)
    #define CH1_CFG2_DVOL_M77dB												((uint8_t) 0x2F)
    #define CH1_CFG2_DVOL_M76P5dB											((uint8_t) 0x30)
    #define CH1_CFG2_DVOL_M76dB												((uint8_t) 0x31)
    #define CH1_CFG2_DVOL_M75P5dB											((uint8_t) 0x32)
    #define CH1_CFG2_DVOL_M75dB												((uint8_t) 0x33)
    #define CH1_CFG2_DVOL_M74P5dB											((uint8_t) 0x34)
    #define CH1_CFG2_DVOL_M74dB												((uint8_t) 0x35)
    #define CH1_CFG2_DVOL_M73P5dB											((uint8_t) 0x36)
    #define CH1_CFG2_DVOL_M73dB												((uint8_t) 0x37)
    #define CH1_CFG2_DVOL_M72P5dB											((uint8_t) 0x38)
    #define CH1_CFG2_DVOL_M72dB												((uint8_t) 0x39)
    #define CH1_CFG2_DVOL_M71P5dB											((uint8_t) 0x3A)
    #define CH1_CFG2_DVOL_M71dB												((uint8_t) 0x3B)
    #define CH1_CFG2_DVOL_M70P5dB											((uint8_t) 0x3C)
    #define CH1_CFG2_DVOL_M70dB												((uint8_t) 0x3D)
    #define CH1_CFG2_DVOL_M69P5dB											((uint8_t) 0x3E)
    #define CH1_CFG2_DVOL_M69dB												((uint8_t) 0x3F)
    #define CH1_CFG2_DVOL_M68P5dB											((uint8_t) 0x40)
    #define CH1_CFG2_DVOL_M68dB												((uint8_t) 0x41)
    #define CH1_CFG2_DVOL_M67P5dB											((uint8_t) 0x42)
    #define CH1_CFG2_DVOL_M67dB												((uint8_t) 0x43)
    #define CH1_CFG2_DVOL_M66P5dB											((uint8_t) 0x44)
    #define CH1_CFG2_DVOL_M66dB												((uint8_t) 0x45)
    #define CH1_CFG2_DVOL_M65P5dB											((uint8_t) 0x46)
    #define CH1_CFG2_DVOL_M65dB												((uint8_t) 0x47)
    #define CH1_CFG2_DVOL_M64P5dB											((uint8_t) 0x48)
    #define CH1_CFG2_DVOL_M64dB												((uint8_t) 0x49)
    #define CH1_CFG2_DVOL_M63P5dB											((uint8_t) 0x4A)
    #define CH1_CFG2_DVOL_M63dB												((uint8_t) 0x4B)
    #define CH1_CFG2_DVOL_M62P5dB											((uint8_t) 0x4C)
    #define CH1_CFG2_DVOL_M62dB												((uint8_t) 0x4D)
    #define CH1_CFG2_DVOL_M61P5dB											((uint8_t) 0x4E)
    #define CH1_CFG2_DVOL_M61dB												((uint8_t) 0x4F)
    #define CH1_CFG2_DVOL_M60P5dB											((uint8_t) 0x50)
    #define CH1_CFG2_DVOL_M60dB												((uint8_t) 0x51)
    #define CH1_CFG2_DVOL_M59P5dB											((uint8_t) 0x52)
    #define CH1_CFG2_DVOL_M59dB												((uint8_t) 0x53)
    #define CH1_CFG2_DVOL_M58P5dB											((uint8_t) 0x54)
    #define CH1_CFG2_DVOL_M58dB												((uint8_t) 0x55)
    #define CH1_CFG2_DVOL_M57P5dB											((uint8_t) 0x56)
    #define CH1_CFG2_DVOL_M57dB												((uint8_t) 0x57)
    #define CH1_CFG2_DVOL_M56P5dB											((uint8_t) 0x58)
    #define CH1_CFG2_DVOL_M56dB												((uint8_t) 0x59)
    #define CH1_CFG2_DVOL_M55P5dB											((uint8_t) 0x5A)
    #define CH1_CFG2_DVOL_M55dB												((uint8_t) 0x5B)
    #define CH1_CFG2_DVOL_M54P5dB											((uint8_t) 0x5C)
    #define CH1_CFG2_DVOL_M54dB												((uint8_t) 0x5D)
    #define CH1_CFG2_DVOL_M53P5dB											((uint8_t) 0x5E)
    #define CH1_CFG2_DVOL_M53dB												((uint8_t) 0x5F)
    #define CH1_CFG2_DVOL_M52P5dB											((uint8_t) 0x60)
    #define CH1_CFG2_DVOL_M52dB												((uint8_t) 0x61)
    #define CH1_CFG2_DVOL_M51P5dB											((uint8_t) 0x62)
    #define CH1_CFG2_DVOL_M51dB												((uint8_t) 0x63)
    #define CH1_CFG2_DVOL_M50P5dB											((uint8_t) 0x64)
    #define CH1_CFG2_DVOL_M50dB												((uint8_t) 0x65)
    #define CH1_CFG2_DVOL_M49P5dB											((uint8_t) 0x66)
    #define CH1_CFG2_DVOL_M49dB												((uint8_t) 0x67)
    #define CH1_CFG2_DVOL_M48P5dB											((uint8_t) 0x68)
    #define CH1_CFG2_DVOL_M48dB												((uint8_t) 0x69)
    #define CH1_CFG2_DVOL_M47P5dB											((uint8_t) 0x6A)
    #define CH1_CFG2_DVOL_M47dB												((uint8_t) 0x6B)
    #define CH1_CFG2_DVOL_M46P5dB											((uint8_t) 0x6C)
    #define CH1_CFG2_DVOL_M46dB												((uint8_t) 0x6D)
    #define CH1_CFG2_DVOL_M45P5dB											((uint8_t) 0x6E)
    #define CH1_CFG2_DVOL_M45dB												((uint8_t) 0x6F)
    #define CH1_CFG2_DVOL_M44P5dB											((uint8_t) 0x70)
    #define CH1_CFG2_DVOL_M44dB												((uint8_t) 0x71)
    #define CH1_CFG2_DVOL_M43P5dB											((uint8_t) 0x72)
    #define CH1_CFG2_DVOL_M43dB												((uint8_t) 0x73)
    #define CH1_CFG2_DVOL_M42P5dB											((uint8_t) 0x74)
    #define CH1_CFG2_DVOL_M42dB												((uint8_t) 0x75)
    #define CH1_CFG2_DVOL_M41P5dB											((uint8_t) 0x76)
    #define CH1_CFG2_DVOL_M41dB												((uint8_t) 0x77)
    #define CH1_CFG2_DVOL_M40P5dB											((uint8_t) 0x78)
    #define CH1_CFG2_DVOL_M40dB												((uint8_t) 0x79)
    #define CH1_CFG2_DVOL_M39P5dB											((uint8_t) 0x7A)
    #define CH1_CFG2_DVOL_M39dB												((uint8_t) 0x7B)
    #define CH1_CFG2_DVOL_M38P5dB											((uint8_t) 0x7C)
    #define CH1_CFG2_DVOL_M38dB												((uint8_t) 0x7D)
    #define CH1_CFG2_DVOL_M37P5dB											((uint8_t) 0x7E)
    #define CH1_CFG2_DVOL_M37dB												((uint8_t) 0x7F)
    #define CH1_CFG2_DVOL_M36P5dB											((uint8_t) 0x80)
    #define CH1_CFG2_DVOL_M36dB												((uint8_t) 0x81)
    #define CH1_CFG2_DVOL_M35P5dB											((uint8_t) 0x82)
    #define CH1_CFG2_DVOL_M35dB												((uint8_t) 0x83)
    #define CH1_CFG2_DVOL_M34P5dB											((uint8_t) 0x84)
    #define CH1_CFG2_DVOL_M34dB												((uint8_t) 0x85)
    #define CH1_CFG2_DVOL_M33P5dB											((uint8_t) 0x86)
    #define CH1_CFG2_DVOL_M33dB												((uint8_t) 0x87)
    #define CH1_CFG2_DVOL_M32P5dB											((uint8_t) 0x88)
    #define CH1_CFG2_DVOL_M32dB												((uint8_t) 0x89)
    #define CH1_CFG2_DVOL_M31P5dB											((uint8_t) 0x8A)
    #define CH1_CFG2_DVOL_M31dB												((uint8_t) 0x8B)
    #define CH1_CFG2_DVOL_M30P5dB											((uint8_t) 0x8C)
    #define CH1_CFG2_DVOL_M30dB												((uint8_t) 0x8D)
    #define CH1_CFG2_DVOL_M29P5dB											((uint8_t) 0x8E)
    #define CH1_CFG2_DVOL_M29dB												((uint8_t) 0x8F)
    #define CH1_CFG2_DVOL_M28P5dB											((uint8_t) 0x90)
    #define CH1_CFG2_DVOL_M28dB												((uint8_t) 0x91)
    #define CH1_CFG2_DVOL_M27P5dB											((uint8_t) 0x92)
    #define CH1_CFG2_DVOL_M27dB												((uint8_t) 0x93)
    #define CH1_CFG2_DVOL_M26P5dB											((uint8_t) 0x94)
    #define CH1_CFG2_DVOL_M26dB												((uint8_t) 0x95)
    #define CH1_CFG2_DVOL_M25P5dB											((uint8_t) 0x96)
    #define CH1_CFG2_DVOL_M25dB												((uint8_t) 0x97)
    #define CH1_CFG2_DVOL_M24P5dB											((uint8_t) 0x98)
    #define CH1_CFG2_DVOL_M24dB												((uint8_t) 0x99)
    #define CH1_CFG2_DVOL_M23P5dB											((uint8_t) 0x9A)
    #define CH1_CFG2_DVOL_M23dB												((uint8_t) 0x9B)
    #define CH1_CFG2_DVOL_M22P5dB											((uint8_t) 0x9C)
    #define CH1_CFG2_DVOL_M22dB												((uint8_t) 0x9D)
    #define CH1_CFG2_DVOL_M21P5dB											((uint8_t) 0x9E)
    #define CH1_CFG2_DVOL_M21dB												((uint8_t) 0x9F)
    #define CH1_CFG2_DVOL_M20P5dB											((uint8_t) 0xA0)
    #define CH1_CFG2_DVOL_M20dB												((uint8_t) 0xA1)
    #define CH1_CFG2_DVOL_M19P5dB											((uint8_t) 0xA2)
    #define CH1_CFG2_DVOL_M19dB												((uint8_t) 0xA3)
    #define CH1_CFG2_DVOL_M18P5dB											((uint8_t) 0xA4)
    #define CH1_CFG2_DVOL_M18dB												((uint8_t) 0xA5)
    #define CH1_CFG2_DVOL_M17P5dB											((uint8_t) 0xA6)
    #define CH1_CFG2_DVOL_M17dB												((uint8_t) 0xA7)
    #define CH1_CFG2_DVOL_M16P5dB											((uint8_t) 0xA8)
    #define CH1_CFG2_DVOL_M16dB												((uint8_t) 0xA9)
    #define CH1_CFG2_DVOL_M15P5dB											((uint8_t) 0xAA)
    #define CH1_CFG2_DVOL_M15dB												((uint8_t) 0xAB)
    #define CH1_CFG2_DVOL_M14P5dB											((uint8_t) 0xAC)
    #define CH1_CFG2_DVOL_M14dB												((uint8_t) 0xAD)
    #define CH1_CFG2_DVOL_M13P5dB											((uint8_t) 0xAE)
    #define CH1_CFG2_DVOL_M13dB												((uint8_t) 0xAF)
    #define CH1_CFG2_DVOL_M12P5dB											((uint8_t) 0xB0)
    #define CH1_CFG2_DVOL_M12dB												((uint8_t) 0xB1)
    #define CH1_CFG2_DVOL_M11P5dB											((uint8_t) 0xB2)
    #define CH1_CFG2_DVOL_M11dB												((uint8_t) 0xB3)
    #define CH1_CFG2_DVOL_M10P5dB											((uint8_t) 0xB4)
    #define CH1_CFG2_DVOL_M10dB												((uint8_t) 0xB5)
    #define CH1_CFG2_DVOL_M9P5dB											((uint8_t) 0xB6)
    #define CH1_CFG2_DVOL_M9dB												((uint8_t) 0xB7)
    #define CH1_CFG2_DVOL_M8P5dB											((uint8_t) 0xB8)
    #define CH1_CFG2_DVOL_M8dB												((uint8_t) 0xB9)
    #define CH1_CFG2_DVOL_M7P5dB											((uint8_t) 0xBA)
    #define CH1_CFG2_DVOL_M7dB												((uint8_t) 0xBB)
    #define CH1_CFG2_DVOL_M6P5dB											((uint8_t) 0xBC)
    #define CH1_CFG2_DVOL_M6dB												((uint8_t) 0xBD)
    #define CH1_CFG2_DVOL_M5P5dB											((uint8_t) 0xBE)
    #define CH1_CFG2_DVOL_M5dB												((uint8_t) 0xBF)
    #define CH1_CFG2_DVOL_M4P5dB											((uint8_t) 0xC0)
    #define CH1_CFG2_DVOL_M4dB												((uint8_t) 0xC1)
    #define CH1_CFG2_DVOL_M3P5dB											((uint8_t) 0xC2)
    #define CH1_CFG2_DVOL_M3dB												((uint8_t) 0xC3)
    #define CH1_CFG2_DVOL_M2P5dB											((uint8_t) 0xC4)
    #define CH1_CFG2_DVOL_M2dB												((uint8_t) 0xC5)
    #define CH1_CFG2_DVOL_M1P5dB											((uint8_t) 0xC6)
    #define CH1_CFG2_DVOL_M1dB												((uint8_t) 0xC7)
    #define CH1_CFG2_DVOL_M0P5dB											((uint8_t) 0xC8)
    #define CH1_CFG2_DVOL_0dB												((uint8_t) 0xC9)    // DEFAULT
    #define CH1_CFG2_DVOL_0P5dB												((uint8_t) 0xCA)
    #define CH1_CFG2_DVOL_1dB												((uint8_t) 0xCB)
    #define CH1_CFG2_DVOL_1P5dB												((uint8_t) 0xCC)
    #define CH1_CFG2_DVOL_2dB												((uint8_t) 0xCD)
    #define CH1_CFG2_DVOL_2P5dB												((uint8_t) 0xCE)
    #define CH1_CFG2_DVOL_3dB												((uint8_t) 0xCF)
    #define CH1_CFG2_DVOL_3P5dB												((uint8_t) 0xD0)
    #define CH1_CFG2_DVOL_4dB												((uint8_t) 0xD1)
    #define CH1_CFG2_DVOL_4P5dB												((uint8_t) 0xD2)
    #define CH1_CFG2_DVOL_5dB												((uint8_t) 0xD3)
    #define CH1_CFG2_DVOL_5P5dB												((uint8_t) 0xD4)
    #define CH1_CFG2_DVOL_6dB												((uint8_t) 0xD5)
    #define CH1_CFG2_DVOL_6P5dB												((uint8_t) 0xD6)
    #define CH1_CFG2_DVOL_7dB												((uint8_t) 0xD7)
    #define CH1_CFG2_DVOL_7P5dB												((uint8_t) 0xD8)
    #define CH1_CFG2_DVOL_8dB												((uint8_t) 0xD9)
    #define CH1_CFG2_DVOL_8P5dB												((uint8_t) 0xDA)
    #define CH1_CFG2_DVOL_9dB												((uint8_t) 0xDB)
    #define CH1_CFG2_DVOL_9P5dB												((uint8_t) 0xDC)
    #define CH1_CFG2_DVOL_10dB												((uint8_t) 0xDD)
    #define CH1_CFG2_DVOL_10P5dB											((uint8_t) 0xDE)
    #define CH1_CFG2_DVOL_11dB												((uint8_t) 0xDF)
    #define CH1_CFG2_DVOL_11P5dB											((uint8_t) 0xE0)
    #define CH1_CFG2_DVOL_12dB												((uint8_t) 0xE1)
    #define CH1_CFG2_DVOL_12P5dB											((uint8_t) 0xE2)
    #define CH1_CFG2_DVOL_13dB												((uint8_t) 0xE3)
    #define CH1_CFG2_DVOL_13P5dB											((uint8_t) 0xE4)
    #define CH1_CFG2_DVOL_14dB												((uint8_t) 0xE5)
    #define CH1_CFG2_DVOL_14P5dB											((uint8_t) 0xE6)
    #define CH1_CFG2_DVOL_15dB												((uint8_t) 0xE7)
    #define CH1_CFG2_DVOL_15P5dB											((uint8_t) 0xE8)
    #define CH1_CFG2_DVOL_16dB												((uint8_t) 0xE9)
    #define CH1_CFG2_DVOL_16P5dB											((uint8_t) 0xEA)
    #define CH1_CFG2_DVOL_17dB												((uint8_t) 0xEB)
    #define CH1_CFG2_DVOL_17P5dB											((uint8_t) 0xEC)
    #define CH1_CFG2_DVOL_18dB												((uint8_t) 0xED)
    #define CH1_CFG2_DVOL_18P5dB											((uint8_t) 0xEE)
    #define CH1_CFG2_DVOL_19dB												((uint8_t) 0xEF)
    #define CH1_CFG2_DVOL_19P5dB											((uint8_t) 0xF0)
    #define CH1_CFG2_DVOL_20dB												((uint8_t) 0xF1)
    #define CH1_CFG2_DVOL_20P5dB											((uint8_t) 0xF2)
    #define CH1_CFG2_DVOL_21dB												((uint8_t) 0xF3)
    #define CH1_CFG2_DVOL_21P5dB											((uint8_t) 0xF4)
    #define CH1_CFG2_DVOL_22dB												((uint8_t) 0xF5)
    #define CH1_CFG2_DVOL_22P5dB											((uint8_t) 0xF6)
    #define CH1_CFG2_DVOL_23dB												((uint8_t) 0xF7)
    #define CH1_CFG2_DVOL_23P5dB											((uint8_t) 0xF8)
    #define CH1_CFG2_DVOL_24dB												((uint8_t) 0xF9)
    #define CH1_CFG2_DVOL_24P5dB											((uint8_t) 0xFA)
    #define CH1_CFG2_DVOL_25dB												((uint8_t) 0xFB)
    #define CH1_CFG2_DVOL_25P5dB											((uint8_t) 0xFC)
    #define CH1_CFG2_DVOL_26dB												((uint8_t) 0xFD)
    #define CH1_CFG2_DVOL_26P5dB											((uint8_t) 0xFE)
    #define CH1_CFG2_DVOL_27dB												((uint8_t) 0xFF)



/* Register 0x3F (CH1_CFG3) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                       GCAL[3:0]                                       |                                     RESERVED[3:0]                                     |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH1_CFG3 register */
    #define CH1_CFG3_ADDRESS												((uint8_t) 0x3F)
    #define CH1_CFG3_DEFAULT												((uint8_t) 0x80)

    /* GCAL field */
    #define CH1_CFG3_GCAL_MASK												((uint8_t) 0xF0)
    #define CH1_CFG3_GCAL_M0P8dB											((uint8_t) 0x00)
    #define CH1_CFG3_GCAL_M0P7dB											((uint8_t) 0x10)
    #define CH1_CFG3_GCAL_M0P6dB											((uint8_t) 0x20)
    #define CH1_CFG3_GCAL_M0P5dB											((uint8_t) 0x30)
    #define CH1_CFG3_GCAL_M0P4dB											((uint8_t) 0x40)
    #define CH1_CFG3_GCAL_M0P3dB											((uint8_t) 0x50)
    #define CH1_CFG3_GCAL_M0P2dB											((uint8_t) 0x60)
    #define CH1_CFG3_GCAL_M0P1dB											((uint8_t) 0x70)
    #define CH1_CFG3_GCAL_0dB												((uint8_t) 0x80)    // DEFAULT
    #define CH1_CFG3_GCAL_0P1dB												((uint8_t) 0x90)
    #define CH1_CFG3_GCAL_0P2dB												((uint8_t) 0xA0)
    #define CH1_CFG3_GCAL_0P3dB												((uint8_t) 0xB0)
    #define CH1_CFG3_GCAL_0P4dB												((uint8_t) 0xC0)
    #define CH1_CFG3_GCAL_0P5dB												((uint8_t) 0xD0)
    #define CH1_CFG3_GCAL_0P6dB												((uint8_t) 0xE0)
    #define CH1_CFG3_GCAL_0P7dB												((uint8_t) 0xF0)



/* Register 0x40 (CH1_CFG4) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                                                   PCAL[7:0]                                                                                   |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH1_CFG4 register */
    #define CH1_CFG4_ADDRESS												((uint8_t) 0x40)
    #define CH1_CFG4_DEFAULT												((uint8_t) 0x00)

    /* PCAL field */
    #define CH1_CFG4_PCAL_MASK												((uint8_t) 0xFF)
    #define CH1_CFG4_PCAL_0													((uint8_t) 0x00)    // DEFAULT
    #define CH1_CFG4_PCAL_1													((uint8_t) 0x01)
    #define CH1_CFG4_PCAL_2													((uint8_t) 0x02)
    #define CH1_CFG4_PCAL_3													((uint8_t) 0x03)
    #define CH1_CFG4_PCAL_4													((uint8_t) 0x04)
    #define CH1_CFG4_PCAL_5													((uint8_t) 0x05)
    #define CH1_CFG4_PCAL_6													((uint8_t) 0x06)
    #define CH1_CFG4_PCAL_7													((uint8_t) 0x07)
    #define CH1_CFG4_PCAL_8													((uint8_t) 0x08)
    #define CH1_CFG4_PCAL_9													((uint8_t) 0x09)
    #define CH1_CFG4_PCAL_10												((uint8_t) 0x0A)
    #define CH1_CFG4_PCAL_11												((uint8_t) 0x0B)
    #define CH1_CFG4_PCAL_12												((uint8_t) 0x0C)
    #define CH1_CFG4_PCAL_13												((uint8_t) 0x0D)
    #define CH1_CFG4_PCAL_14												((uint8_t) 0x0E)
    #define CH1_CFG4_PCAL_15												((uint8_t) 0x0F)
    #define CH1_CFG4_PCAL_16												((uint8_t) 0x10)
    #define CH1_CFG4_PCAL_17												((uint8_t) 0x11)
    #define CH1_CFG4_PCAL_18												((uint8_t) 0x12)
    #define CH1_CFG4_PCAL_19												((uint8_t) 0x13)
    #define CH1_CFG4_PCAL_20												((uint8_t) 0x14)
    #define CH1_CFG4_PCAL_21												((uint8_t) 0x15)
    #define CH1_CFG4_PCAL_22												((uint8_t) 0x16)
    #define CH1_CFG4_PCAL_23												((uint8_t) 0x17)
    #define CH1_CFG4_PCAL_24												((uint8_t) 0x18)
    #define CH1_CFG4_PCAL_25												((uint8_t) 0x19)
    #define CH1_CFG4_PCAL_26												((uint8_t) 0x1A)
    #define CH1_CFG4_PCAL_27												((uint8_t) 0x1B)
    #define CH1_CFG4_PCAL_28												((uint8_t) 0x1C)
    #define CH1_CFG4_PCAL_29												((uint8_t) 0x1D)
    #define CH1_CFG4_PCAL_30												((uint8_t) 0x1E)
    #define CH1_CFG4_PCAL_31												((uint8_t) 0x1F)
    #define CH1_CFG4_PCAL_32												((uint8_t) 0x20)
    #define CH1_CFG4_PCAL_33												((uint8_t) 0x21)
    #define CH1_CFG4_PCAL_34												((uint8_t) 0x22)
    #define CH1_CFG4_PCAL_35												((uint8_t) 0x23)
    #define CH1_CFG4_PCAL_36												((uint8_t) 0x24)
    #define CH1_CFG4_PCAL_37												((uint8_t) 0x25)
    #define CH1_CFG4_PCAL_38												((uint8_t) 0x26)
    #define CH1_CFG4_PCAL_39												((uint8_t) 0x27)
    #define CH1_CFG4_PCAL_40												((uint8_t) 0x28)
    #define CH1_CFG4_PCAL_41												((uint8_t) 0x29)
    #define CH1_CFG4_PCAL_42												((uint8_t) 0x2A)
    #define CH1_CFG4_PCAL_43												((uint8_t) 0x2B)
    #define CH1_CFG4_PCAL_44												((uint8_t) 0x2C)
    #define CH1_CFG4_PCAL_45												((uint8_t) 0x2D)
    #define CH1_CFG4_PCAL_46												((uint8_t) 0x2E)
    #define CH1_CFG4_PCAL_47												((uint8_t) 0x2F)
    #define CH1_CFG4_PCAL_48												((uint8_t) 0x30)
    #define CH1_CFG4_PCAL_49												((uint8_t) 0x31)
    #define CH1_CFG4_PCAL_50												((uint8_t) 0x32)
    #define CH1_CFG4_PCAL_51												((uint8_t) 0x33)
    #define CH1_CFG4_PCAL_52												((uint8_t) 0x34)
    #define CH1_CFG4_PCAL_53												((uint8_t) 0x35)
    #define CH1_CFG4_PCAL_54												((uint8_t) 0x36)
    #define CH1_CFG4_PCAL_55												((uint8_t) 0x37)
    #define CH1_CFG4_PCAL_56												((uint8_t) 0x38)
    #define CH1_CFG4_PCAL_57												((uint8_t) 0x39)
    #define CH1_CFG4_PCAL_58												((uint8_t) 0x3A)
    #define CH1_CFG4_PCAL_59												((uint8_t) 0x3B)
    #define CH1_CFG4_PCAL_60												((uint8_t) 0x3C)
    #define CH1_CFG4_PCAL_61												((uint8_t) 0x3D)
    #define CH1_CFG4_PCAL_62												((uint8_t) 0x3E)
    #define CH1_CFG4_PCAL_63												((uint8_t) 0x3F)
    #define CH1_CFG4_PCAL_64												((uint8_t) 0x40)
    #define CH1_CFG4_PCAL_65												((uint8_t) 0x41)
    #define CH1_CFG4_PCAL_66												((uint8_t) 0x42)
    #define CH1_CFG4_PCAL_67												((uint8_t) 0x43)
    #define CH1_CFG4_PCAL_68												((uint8_t) 0x44)
    #define CH1_CFG4_PCAL_69												((uint8_t) 0x45)
    #define CH1_CFG4_PCAL_70												((uint8_t) 0x46)
    #define CH1_CFG4_PCAL_71												((uint8_t) 0x47)
    #define CH1_CFG4_PCAL_72												((uint8_t) 0x48)
    #define CH1_CFG4_PCAL_73												((uint8_t) 0x49)
    #define CH1_CFG4_PCAL_74												((uint8_t) 0x4A)
    #define CH1_CFG4_PCAL_75												((uint8_t) 0x4B)
    #define CH1_CFG4_PCAL_76												((uint8_t) 0x4C)
    #define CH1_CFG4_PCAL_77												((uint8_t) 0x4D)
    #define CH1_CFG4_PCAL_78												((uint8_t) 0x4E)
    #define CH1_CFG4_PCAL_79												((uint8_t) 0x4F)
    #define CH1_CFG4_PCAL_80												((uint8_t) 0x50)
    #define CH1_CFG4_PCAL_81												((uint8_t) 0x51)
    #define CH1_CFG4_PCAL_82												((uint8_t) 0x52)
    #define CH1_CFG4_PCAL_83												((uint8_t) 0x53)
    #define CH1_CFG4_PCAL_84												((uint8_t) 0x54)
    #define CH1_CFG4_PCAL_85												((uint8_t) 0x55)
    #define CH1_CFG4_PCAL_86												((uint8_t) 0x56)
    #define CH1_CFG4_PCAL_87												((uint8_t) 0x57)
    #define CH1_CFG4_PCAL_88												((uint8_t) 0x58)
    #define CH1_CFG4_PCAL_89												((uint8_t) 0x59)
    #define CH1_CFG4_PCAL_90												((uint8_t) 0x5A)
    #define CH1_CFG4_PCAL_91												((uint8_t) 0x5B)
    #define CH1_CFG4_PCAL_92												((uint8_t) 0x5C)
    #define CH1_CFG4_PCAL_93												((uint8_t) 0x5D)
    #define CH1_CFG4_PCAL_94												((uint8_t) 0x5E)
    #define CH1_CFG4_PCAL_95												((uint8_t) 0x5F)
    #define CH1_CFG4_PCAL_96												((uint8_t) 0x60)
    #define CH1_CFG4_PCAL_97												((uint8_t) 0x61)
    #define CH1_CFG4_PCAL_98												((uint8_t) 0x62)
    #define CH1_CFG4_PCAL_99												((uint8_t) 0x63)
    #define CH1_CFG4_PCAL_100												((uint8_t) 0x64)
    #define CH1_CFG4_PCAL_101												((uint8_t) 0x65)
    #define CH1_CFG4_PCAL_102												((uint8_t) 0x66)
    #define CH1_CFG4_PCAL_103												((uint8_t) 0x67)
    #define CH1_CFG4_PCAL_104												((uint8_t) 0x68)
    #define CH1_CFG4_PCAL_105												((uint8_t) 0x69)
    #define CH1_CFG4_PCAL_106												((uint8_t) 0x6A)
    #define CH1_CFG4_PCAL_107												((uint8_t) 0x6B)
    #define CH1_CFG4_PCAL_108												((uint8_t) 0x6C)
    #define CH1_CFG4_PCAL_109												((uint8_t) 0x6D)
    #define CH1_CFG4_PCAL_110												((uint8_t) 0x6E)
    #define CH1_CFG4_PCAL_111												((uint8_t) 0x6F)
    #define CH1_CFG4_PCAL_112												((uint8_t) 0x70)
    #define CH1_CFG4_PCAL_113												((uint8_t) 0x71)
    #define CH1_CFG4_PCAL_114												((uint8_t) 0x72)
    #define CH1_CFG4_PCAL_115												((uint8_t) 0x73)
    #define CH1_CFG4_PCAL_116												((uint8_t) 0x74)
    #define CH1_CFG4_PCAL_117												((uint8_t) 0x75)
    #define CH1_CFG4_PCAL_118												((uint8_t) 0x76)
    #define CH1_CFG4_PCAL_119												((uint8_t) 0x77)
    #define CH1_CFG4_PCAL_120												((uint8_t) 0x78)
    #define CH1_CFG4_PCAL_121												((uint8_t) 0x79)
    #define CH1_CFG4_PCAL_122												((uint8_t) 0x7A)
    #define CH1_CFG4_PCAL_123												((uint8_t) 0x7B)
    #define CH1_CFG4_PCAL_124												((uint8_t) 0x7C)
    #define CH1_CFG4_PCAL_125												((uint8_t) 0x7D)
    #define CH1_CFG4_PCAL_126												((uint8_t) 0x7E)
    #define CH1_CFG4_PCAL_127												((uint8_t) 0x7F)
    #define CH1_CFG4_PCAL_128												((uint8_t) 0x80)
    #define CH1_CFG4_PCAL_129												((uint8_t) 0x81)
    #define CH1_CFG4_PCAL_130												((uint8_t) 0x82)
    #define CH1_CFG4_PCAL_131												((uint8_t) 0x83)
    #define CH1_CFG4_PCAL_132												((uint8_t) 0x84)
    #define CH1_CFG4_PCAL_133												((uint8_t) 0x85)
    #define CH1_CFG4_PCAL_134												((uint8_t) 0x86)
    #define CH1_CFG4_PCAL_135												((uint8_t) 0x87)
    #define CH1_CFG4_PCAL_136												((uint8_t) 0x88)
    #define CH1_CFG4_PCAL_137												((uint8_t) 0x89)
    #define CH1_CFG4_PCAL_138												((uint8_t) 0x8A)
    #define CH1_CFG4_PCAL_139												((uint8_t) 0x8B)
    #define CH1_CFG4_PCAL_140												((uint8_t) 0x8C)
    #define CH1_CFG4_PCAL_141												((uint8_t) 0x8D)
    #define CH1_CFG4_PCAL_142												((uint8_t) 0x8E)
    #define CH1_CFG4_PCAL_143												((uint8_t) 0x8F)
    #define CH1_CFG4_PCAL_144												((uint8_t) 0x90)
    #define CH1_CFG4_PCAL_145												((uint8_t) 0x91)
    #define CH1_CFG4_PCAL_146												((uint8_t) 0x92)
    #define CH1_CFG4_PCAL_147												((uint8_t) 0x93)
    #define CH1_CFG4_PCAL_148												((uint8_t) 0x94)
    #define CH1_CFG4_PCAL_149												((uint8_t) 0x95)
    #define CH1_CFG4_PCAL_150												((uint8_t) 0x96)
    #define CH1_CFG4_PCAL_151												((uint8_t) 0x97)
    #define CH1_CFG4_PCAL_152												((uint8_t) 0x98)
    #define CH1_CFG4_PCAL_153												((uint8_t) 0x99)
    #define CH1_CFG4_PCAL_154												((uint8_t) 0x9A)
    #define CH1_CFG4_PCAL_155												((uint8_t) 0x9B)
    #define CH1_CFG4_PCAL_156												((uint8_t) 0x9C)
    #define CH1_CFG4_PCAL_157												((uint8_t) 0x9D)
    #define CH1_CFG4_PCAL_158												((uint8_t) 0x9E)
    #define CH1_CFG4_PCAL_159												((uint8_t) 0x9F)
    #define CH1_CFG4_PCAL_160												((uint8_t) 0xA0)
    #define CH1_CFG4_PCAL_161												((uint8_t) 0xA1)
    #define CH1_CFG4_PCAL_162												((uint8_t) 0xA2)
    #define CH1_CFG4_PCAL_163												((uint8_t) 0xA3)
    #define CH1_CFG4_PCAL_164												((uint8_t) 0xA4)
    #define CH1_CFG4_PCAL_165												((uint8_t) 0xA5)
    #define CH1_CFG4_PCAL_166												((uint8_t) 0xA6)
    #define CH1_CFG4_PCAL_167												((uint8_t) 0xA7)
    #define CH1_CFG4_PCAL_168												((uint8_t) 0xA8)
    #define CH1_CFG4_PCAL_169												((uint8_t) 0xA9)
    #define CH1_CFG4_PCAL_170												((uint8_t) 0xAA)
    #define CH1_CFG4_PCAL_171												((uint8_t) 0xAB)
    #define CH1_CFG4_PCAL_172												((uint8_t) 0xAC)
    #define CH1_CFG4_PCAL_173												((uint8_t) 0xAD)
    #define CH1_CFG4_PCAL_174												((uint8_t) 0xAE)
    #define CH1_CFG4_PCAL_175												((uint8_t) 0xAF)
    #define CH1_CFG4_PCAL_176												((uint8_t) 0xB0)
    #define CH1_CFG4_PCAL_177												((uint8_t) 0xB1)
    #define CH1_CFG4_PCAL_178												((uint8_t) 0xB2)
    #define CH1_CFG4_PCAL_179												((uint8_t) 0xB3)
    #define CH1_CFG4_PCAL_180												((uint8_t) 0xB4)
    #define CH1_CFG4_PCAL_181												((uint8_t) 0xB5)
    #define CH1_CFG4_PCAL_182												((uint8_t) 0xB6)
    #define CH1_CFG4_PCAL_183												((uint8_t) 0xB7)
    #define CH1_CFG4_PCAL_184												((uint8_t) 0xB8)
    #define CH1_CFG4_PCAL_185												((uint8_t) 0xB9)
    #define CH1_CFG4_PCAL_186												((uint8_t) 0xBA)
    #define CH1_CFG4_PCAL_187												((uint8_t) 0xBB)
    #define CH1_CFG4_PCAL_188												((uint8_t) 0xBC)
    #define CH1_CFG4_PCAL_189												((uint8_t) 0xBD)
    #define CH1_CFG4_PCAL_190												((uint8_t) 0xBE)
    #define CH1_CFG4_PCAL_191												((uint8_t) 0xBF)
    #define CH1_CFG4_PCAL_192												((uint8_t) 0xC0)
    #define CH1_CFG4_PCAL_193												((uint8_t) 0xC1)
    #define CH1_CFG4_PCAL_194												((uint8_t) 0xC2)
    #define CH1_CFG4_PCAL_195												((uint8_t) 0xC3)
    #define CH1_CFG4_PCAL_196												((uint8_t) 0xC4)
    #define CH1_CFG4_PCAL_197												((uint8_t) 0xC5)
    #define CH1_CFG4_PCAL_198												((uint8_t) 0xC6)
    #define CH1_CFG4_PCAL_199												((uint8_t) 0xC7)
    #define CH1_CFG4_PCAL_200												((uint8_t) 0xC8)
    #define CH1_CFG4_PCAL_201												((uint8_t) 0xC9)
    #define CH1_CFG4_PCAL_202												((uint8_t) 0xCA)
    #define CH1_CFG4_PCAL_203												((uint8_t) 0xCB)
    #define CH1_CFG4_PCAL_204												((uint8_t) 0xCC)
    #define CH1_CFG4_PCAL_205												((uint8_t) 0xCD)
    #define CH1_CFG4_PCAL_206												((uint8_t) 0xCE)
    #define CH1_CFG4_PCAL_207												((uint8_t) 0xCF)
    #define CH1_CFG4_PCAL_208												((uint8_t) 0xD0)
    #define CH1_CFG4_PCAL_209												((uint8_t) 0xD1)
    #define CH1_CFG4_PCAL_210												((uint8_t) 0xD2)
    #define CH1_CFG4_PCAL_211												((uint8_t) 0xD3)
    #define CH1_CFG4_PCAL_212												((uint8_t) 0xD4)
    #define CH1_CFG4_PCAL_213												((uint8_t) 0xD5)
    #define CH1_CFG4_PCAL_214												((uint8_t) 0xD6)
    #define CH1_CFG4_PCAL_215												((uint8_t) 0xD7)
    #define CH1_CFG4_PCAL_216												((uint8_t) 0xD8)
    #define CH1_CFG4_PCAL_217												((uint8_t) 0xD9)
    #define CH1_CFG4_PCAL_218												((uint8_t) 0xDA)
    #define CH1_CFG4_PCAL_219												((uint8_t) 0xDB)
    #define CH1_CFG4_PCAL_220												((uint8_t) 0xDC)
    #define CH1_CFG4_PCAL_221												((uint8_t) 0xDD)
    #define CH1_CFG4_PCAL_222												((uint8_t) 0xDE)
    #define CH1_CFG4_PCAL_223												((uint8_t) 0xDF)
    #define CH1_CFG4_PCAL_224												((uint8_t) 0xE0)
    #define CH1_CFG4_PCAL_225												((uint8_t) 0xE1)
    #define CH1_CFG4_PCAL_226												((uint8_t) 0xE2)
    #define CH1_CFG4_PCAL_227												((uint8_t) 0xE3)
    #define CH1_CFG4_PCAL_228												((uint8_t) 0xE4)
    #define CH1_CFG4_PCAL_229												((uint8_t) 0xE5)
    #define CH1_CFG4_PCAL_230												((uint8_t) 0xE6)
    #define CH1_CFG4_PCAL_231												((uint8_t) 0xE7)
    #define CH1_CFG4_PCAL_232												((uint8_t) 0xE8)
    #define CH1_CFG4_PCAL_233												((uint8_t) 0xE9)
    #define CH1_CFG4_PCAL_234												((uint8_t) 0xEA)
    #define CH1_CFG4_PCAL_235												((uint8_t) 0xEB)
    #define CH1_CFG4_PCAL_236												((uint8_t) 0xEC)
    #define CH1_CFG4_PCAL_237												((uint8_t) 0xED)
    #define CH1_CFG4_PCAL_238												((uint8_t) 0xEE)
    #define CH1_CFG4_PCAL_239												((uint8_t) 0xEF)
    #define CH1_CFG4_PCAL_240												((uint8_t) 0xF0)
    #define CH1_CFG4_PCAL_241												((uint8_t) 0xF1)
    #define CH1_CFG4_PCAL_242												((uint8_t) 0xF2)
    #define CH1_CFG4_PCAL_243												((uint8_t) 0xF3)
    #define CH1_CFG4_PCAL_244												((uint8_t) 0xF4)
    #define CH1_CFG4_PCAL_245												((uint8_t) 0xF5)
    #define CH1_CFG4_PCAL_246												((uint8_t) 0xF6)
    #define CH1_CFG4_PCAL_247												((uint8_t) 0xF7)
    #define CH1_CFG4_PCAL_248												((uint8_t) 0xF8)
    #define CH1_CFG4_PCAL_249												((uint8_t) 0xF9)
    #define CH1_CFG4_PCAL_250												((uint8_t) 0xFA)
    #define CH1_CFG4_PCAL_251												((uint8_t) 0xFB)
    #define CH1_CFG4_PCAL_252												((uint8_t) 0xFC)
    #define CH1_CFG4_PCAL_253												((uint8_t) 0xFD)
    #define CH1_CFG4_PCAL_254												((uint8_t) 0xFE)
    #define CH1_CFG4_PCAL_255												((uint8_t) 0xFF)



/* Register 0x41 (CH2_CFG0) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                     |                 INSRC[1:0]                |                     |                     |                     |                     |                     |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH2_CFG0 register */
    #define CH2_CFG0_ADDRESS												((uint8_t) 0x41)
    #define CH2_CFG0_DEFAULT												((uint8_t) 0x00)

    /* INSRC field */
    #define CH2_CFG0_INSRC_MASK												((uint8_t) 0x60)
    #define CH2_CFG0_INSRC_DIFF												((uint8_t) 0x00)    // DEFAULT
    #define CH2_CFG0_INSRC_SINGLE											((uint8_t) 0x20)
    #define CH2_CFG0_INSRC_PDM												((uint8_t) 0x40)



/* Register 0x42 (CH2_CFG1) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                             GAIN[5:0]                                                             |               RESERVED[1:0]               |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH2_CFG1 register */
    #define CH2_CFG1_ADDRESS												((uint8_t) 0x42)
    #define CH2_CFG1_DEFAULT												((uint8_t) 0x00)

    /* GAIN field */
    #define CH2_CFG1_GAIN_MASK												((uint8_t) 0xFC)
    #define CH2_CFG1_GAIN_0dB												((uint8_t) 0x00)    // DEFAULT
    #define CH2_CFG1_GAIN_1dB												((uint8_t) 0x04)
    #define CH2_CFG1_GAIN_2dB												((uint8_t) 0x08)
    #define CH2_CFG1_GAIN_3dB												((uint8_t) 0x0C)
    #define CH2_CFG1_GAIN_4dB												((uint8_t) 0x10)
    #define CH2_CFG1_GAIN_5dB												((uint8_t) 0x14)
    #define CH2_CFG1_GAIN_6dB												((uint8_t) 0x18)
    #define CH2_CFG1_GAIN_7dB												((uint8_t) 0x1C)
    #define CH2_CFG1_GAIN_8dB												((uint8_t) 0x20)
    #define CH2_CFG1_GAIN_9dB												((uint8_t) 0x24)
    #define CH2_CFG1_GAIN_10dB												((uint8_t) 0x28)
    #define CH2_CFG1_GAIN_11dB												((uint8_t) 0x2C)
    #define CH2_CFG1_GAIN_12dB												((uint8_t) 0x30)
    #define CH2_CFG1_GAIN_13dB												((uint8_t) 0x34)
    #define CH2_CFG1_GAIN_14dB												((uint8_t) 0x38)
    #define CH2_CFG1_GAIN_15dB												((uint8_t) 0x3C)
    #define CH2_CFG1_GAIN_16dB												((uint8_t) 0x40)
    #define CH2_CFG1_GAIN_17dB												((uint8_t) 0x44)
    #define CH2_CFG1_GAIN_18dB												((uint8_t) 0x48)
    #define CH2_CFG1_GAIN_19dB												((uint8_t) 0x4C)
    #define CH2_CFG1_GAIN_20dB												((uint8_t) 0x50)
    #define CH2_CFG1_GAIN_21dB												((uint8_t) 0x54)
    #define CH2_CFG1_GAIN_22dB												((uint8_t) 0x58)
    #define CH2_CFG1_GAIN_23dB												((uint8_t) 0x5C)
    #define CH2_CFG1_GAIN_24dB												((uint8_t) 0x60)
    #define CH2_CFG1_GAIN_25dB												((uint8_t) 0x64)
    #define CH2_CFG1_GAIN_26dB												((uint8_t) 0x68)
    #define CH2_CFG1_GAIN_27dB												((uint8_t) 0x6C)
    #define CH2_CFG1_GAIN_28dB												((uint8_t) 0x70)
    #define CH2_CFG1_GAIN_29dB												((uint8_t) 0x74)
    #define CH2_CFG1_GAIN_30dB												((uint8_t) 0x78)
    #define CH2_CFG1_GAIN_31dB												((uint8_t) 0x7C)
    #define CH2_CFG1_GAIN_32dB												((uint8_t) 0x80)
    #define CH2_CFG1_GAIN_33dB												((uint8_t) 0x84)
    #define CH2_CFG1_GAIN_34dB												((uint8_t) 0x88)
    #define CH2_CFG1_GAIN_35dB												((uint8_t) 0x8C)
    #define CH2_CFG1_GAIN_36dB												((uint8_t) 0x90)
    #define CH2_CFG1_GAIN_37dB												((uint8_t) 0x94)
    #define CH2_CFG1_GAIN_38dB												((uint8_t) 0x98)
    #define CH2_CFG1_GAIN_39dB												((uint8_t) 0x9C)
    #define CH2_CFG1_GAIN_40dB												((uint8_t) 0xA0)
    #define CH2_CFG1_GAIN_41dB												((uint8_t) 0xA4)
    #define CH2_CFG1_GAIN_42dB												((uint8_t) 0xA8)



/* Register 0x43 (CH2_CFG2) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                                                   DVOL[7:0]                                                                                   |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH2_CFG2 register */
    #define CH2_CFG2_ADDRESS												((uint8_t) 0x43)
    #define CH2_CFG2_DEFAULT												((uint8_t) 0xC9)

    /* DVOL field */
    #define CH2_CFG2_DVOL_MASK												((uint8_t) 0xFF)
    #define CH2_CFG2_DVOL_MUTE												((uint8_t) 0x00)
    #define CH2_CFG2_DVOL_M100dB											((uint8_t) 0x01)
    #define CH2_CFG2_DVOL_M99P5dB											((uint8_t) 0x02)
    #define CH2_CFG2_DVOL_M99dB												((uint8_t) 0x03)
    #define CH2_CFG2_DVOL_M98P5dB											((uint8_t) 0x04)
    #define CH2_CFG2_DVOL_M98dB												((uint8_t) 0x05)
    #define CH2_CFG2_DVOL_M97P5dB											((uint8_t) 0x06)
    #define CH2_CFG2_DVOL_M97dB												((uint8_t) 0x07)
    #define CH2_CFG2_DVOL_M96P5dB											((uint8_t) 0x08)
    #define CH2_CFG2_DVOL_M96dB												((uint8_t) 0x09)
    #define CH2_CFG2_DVOL_M95P5dB											((uint8_t) 0x0A)
    #define CH2_CFG2_DVOL_M95dB												((uint8_t) 0x0B)
    #define CH2_CFG2_DVOL_M94P5dB											((uint8_t) 0x0C)
    #define CH2_CFG2_DVOL_M94dB												((uint8_t) 0x0D)
    #define CH2_CFG2_DVOL_M93P5dB											((uint8_t) 0x0E)
    #define CH2_CFG2_DVOL_M93dB												((uint8_t) 0x0F)
    #define CH2_CFG2_DVOL_M92P5dB											((uint8_t) 0x10)
    #define CH2_CFG2_DVOL_M92dB												((uint8_t) 0x11)
    #define CH2_CFG2_DVOL_M91P5dB											((uint8_t) 0x12)
    #define CH2_CFG2_DVOL_M91dB												((uint8_t) 0x13)
    #define CH2_CFG2_DVOL_M90P5dB											((uint8_t) 0x14)
    #define CH2_CFG2_DVOL_M90dB												((uint8_t) 0x15)
    #define CH2_CFG2_DVOL_M89P5dB											((uint8_t) 0x16)
    #define CH2_CFG2_DVOL_M89dB												((uint8_t) 0x17)
    #define CH2_CFG2_DVOL_M88P5dB											((uint8_t) 0x18)
    #define CH2_CFG2_DVOL_M88dB												((uint8_t) 0x19)
    #define CH2_CFG2_DVOL_M87P5dB											((uint8_t) 0x1A)
    #define CH2_CFG2_DVOL_M87dB												((uint8_t) 0x1B)
    #define CH2_CFG2_DVOL_M86P5dB											((uint8_t) 0x1C)
    #define CH2_CFG2_DVOL_M86dB												((uint8_t) 0x1D)
    #define CH2_CFG2_DVOL_M85P5dB											((uint8_t) 0x1E)
    #define CH2_CFG2_DVOL_M85dB												((uint8_t) 0x1F)
    #define CH2_CFG2_DVOL_M84P5dB											((uint8_t) 0x20)
    #define CH2_CFG2_DVOL_M84dB												((uint8_t) 0x21)
    #define CH2_CFG2_DVOL_M83P5dB											((uint8_t) 0x22)
    #define CH2_CFG2_DVOL_M83dB												((uint8_t) 0x23)
    #define CH2_CFG2_DVOL_M82P5dB											((uint8_t) 0x24)
    #define CH2_CFG2_DVOL_M82dB												((uint8_t) 0x25)
    #define CH2_CFG2_DVOL_M81P5dB											((uint8_t) 0x26)
    #define CH2_CFG2_DVOL_M81dB												((uint8_t) 0x27)
    #define CH2_CFG2_DVOL_M80P5dB											((uint8_t) 0x28)
    #define CH2_CFG2_DVOL_M80dB												((uint8_t) 0x29)
    #define CH2_CFG2_DVOL_M79P5dB											((uint8_t) 0x2A)
    #define CH2_CFG2_DVOL_M79dB												((uint8_t) 0x2B)
    #define CH2_CFG2_DVOL_M78P5dB											((uint8_t) 0x2C)
    #define CH2_CFG2_DVOL_M78dB												((uint8_t) 0x2D)
    #define CH2_CFG2_DVOL_M77P5dB											((uint8_t) 0x2E)
    #define CH2_CFG2_DVOL_M77dB												((uint8_t) 0x2F)
    #define CH2_CFG2_DVOL_M76P5dB											((uint8_t) 0x30)
    #define CH2_CFG2_DVOL_M76dB												((uint8_t) 0x31)
    #define CH2_CFG2_DVOL_M75P5dB											((uint8_t) 0x32)
    #define CH2_CFG2_DVOL_M75dB												((uint8_t) 0x33)
    #define CH2_CFG2_DVOL_M74P5dB											((uint8_t) 0x34)
    #define CH2_CFG2_DVOL_M74dB												((uint8_t) 0x35)
    #define CH2_CFG2_DVOL_M73P5dB											((uint8_t) 0x36)
    #define CH2_CFG2_DVOL_M73dB												((uint8_t) 0x37)
    #define CH2_CFG2_DVOL_M72P5dB											((uint8_t) 0x38)
    #define CH2_CFG2_DVOL_M72dB												((uint8_t) 0x39)
    #define CH2_CFG2_DVOL_M71P5dB											((uint8_t) 0x3A)
    #define CH2_CFG2_DVOL_M71dB												((uint8_t) 0x3B)
    #define CH2_CFG2_DVOL_M70P5dB											((uint8_t) 0x3C)
    #define CH2_CFG2_DVOL_M70dB												((uint8_t) 0x3D)
    #define CH2_CFG2_DVOL_M69P5dB											((uint8_t) 0x3E)
    #define CH2_CFG2_DVOL_M69dB												((uint8_t) 0x3F)
    #define CH2_CFG2_DVOL_M68P5dB											((uint8_t) 0x40)
    #define CH2_CFG2_DVOL_M68dB												((uint8_t) 0x41)
    #define CH2_CFG2_DVOL_M67P5dB											((uint8_t) 0x42)
    #define CH2_CFG2_DVOL_M67dB												((uint8_t) 0x43)
    #define CH2_CFG2_DVOL_M66P5dB											((uint8_t) 0x44)
    #define CH2_CFG2_DVOL_M66dB												((uint8_t) 0x45)
    #define CH2_CFG2_DVOL_M65P5dB											((uint8_t) 0x46)
    #define CH2_CFG2_DVOL_M65dB												((uint8_t) 0x47)
    #define CH2_CFG2_DVOL_M64P5dB											((uint8_t) 0x48)
    #define CH2_CFG2_DVOL_M64dB												((uint8_t) 0x49)
    #define CH2_CFG2_DVOL_M63P5dB											((uint8_t) 0x4A)
    #define CH2_CFG2_DVOL_M63dB												((uint8_t) 0x4B)
    #define CH2_CFG2_DVOL_M62P5dB											((uint8_t) 0x4C)
    #define CH2_CFG2_DVOL_M62dB												((uint8_t) 0x4D)
    #define CH2_CFG2_DVOL_M61P5dB											((uint8_t) 0x4E)
    #define CH2_CFG2_DVOL_M61dB												((uint8_t) 0x4F)
    #define CH2_CFG2_DVOL_M60P5dB											((uint8_t) 0x50)
    #define CH2_CFG2_DVOL_M60dB												((uint8_t) 0x51)
    #define CH2_CFG2_DVOL_M59P5dB											((uint8_t) 0x52)
    #define CH2_CFG2_DVOL_M59dB												((uint8_t) 0x53)
    #define CH2_CFG2_DVOL_M58P5dB											((uint8_t) 0x54)
    #define CH2_CFG2_DVOL_M58dB												((uint8_t) 0x55)
    #define CH2_CFG2_DVOL_M57P5dB											((uint8_t) 0x56)
    #define CH2_CFG2_DVOL_M57dB												((uint8_t) 0x57)
    #define CH2_CFG2_DVOL_M56P5dB											((uint8_t) 0x58)
    #define CH2_CFG2_DVOL_M56dB												((uint8_t) 0x59)
    #define CH2_CFG2_DVOL_M55P5dB											((uint8_t) 0x5A)
    #define CH2_CFG2_DVOL_M55dB												((uint8_t) 0x5B)
    #define CH2_CFG2_DVOL_M54P5dB											((uint8_t) 0x5C)
    #define CH2_CFG2_DVOL_M54dB												((uint8_t) 0x5D)
    #define CH2_CFG2_DVOL_M53P5dB											((uint8_t) 0x5E)
    #define CH2_CFG2_DVOL_M53dB												((uint8_t) 0x5F)
    #define CH2_CFG2_DVOL_M52P5dB											((uint8_t) 0x60)
    #define CH2_CFG2_DVOL_M52dB												((uint8_t) 0x61)
    #define CH2_CFG2_DVOL_M51P5dB											((uint8_t) 0x62)
    #define CH2_CFG2_DVOL_M51dB												((uint8_t) 0x63)
    #define CH2_CFG2_DVOL_M50P5dB											((uint8_t) 0x64)
    #define CH2_CFG2_DVOL_M50dB												((uint8_t) 0x65)
    #define CH2_CFG2_DVOL_M49P5dB											((uint8_t) 0x66)
    #define CH2_CFG2_DVOL_M49dB												((uint8_t) 0x67)
    #define CH2_CFG2_DVOL_M48P5dB											((uint8_t) 0x68)
    #define CH2_CFG2_DVOL_M48dB												((uint8_t) 0x69)
    #define CH2_CFG2_DVOL_M47P5dB											((uint8_t) 0x6A)
    #define CH2_CFG2_DVOL_M47dB												((uint8_t) 0x6B)
    #define CH2_CFG2_DVOL_M46P5dB											((uint8_t) 0x6C)
    #define CH2_CFG2_DVOL_M46dB												((uint8_t) 0x6D)
    #define CH2_CFG2_DVOL_M45P5dB											((uint8_t) 0x6E)
    #define CH2_CFG2_DVOL_M45dB												((uint8_t) 0x6F)
    #define CH2_CFG2_DVOL_M44P5dB											((uint8_t) 0x70)
    #define CH2_CFG2_DVOL_M44dB												((uint8_t) 0x71)
    #define CH2_CFG2_DVOL_M43P5dB											((uint8_t) 0x72)
    #define CH2_CFG2_DVOL_M43dB												((uint8_t) 0x73)
    #define CH2_CFG2_DVOL_M42P5dB											((uint8_t) 0x74)
    #define CH2_CFG2_DVOL_M42dB												((uint8_t) 0x75)
    #define CH2_CFG2_DVOL_M41P5dB											((uint8_t) 0x76)
    #define CH2_CFG2_DVOL_M41dB												((uint8_t) 0x77)
    #define CH2_CFG2_DVOL_M40P5dB											((uint8_t) 0x78)
    #define CH2_CFG2_DVOL_M40dB												((uint8_t) 0x79)
    #define CH2_CFG2_DVOL_M39P5dB											((uint8_t) 0x7A)
    #define CH2_CFG2_DVOL_M39dB												((uint8_t) 0x7B)
    #define CH2_CFG2_DVOL_M38P5dB											((uint8_t) 0x7C)
    #define CH2_CFG2_DVOL_M38dB												((uint8_t) 0x7D)
    #define CH2_CFG2_DVOL_M37P5dB											((uint8_t) 0x7E)
    #define CH2_CFG2_DVOL_M37dB												((uint8_t) 0x7F)
    #define CH2_CFG2_DVOL_M36P5dB											((uint8_t) 0x80)
    #define CH2_CFG2_DVOL_M36dB												((uint8_t) 0x81)
    #define CH2_CFG2_DVOL_M35P5dB											((uint8_t) 0x82)
    #define CH2_CFG2_DVOL_M35dB												((uint8_t) 0x83)
    #define CH2_CFG2_DVOL_M34P5dB											((uint8_t) 0x84)
    #define CH2_CFG2_DVOL_M34dB												((uint8_t) 0x85)
    #define CH2_CFG2_DVOL_M33P5dB											((uint8_t) 0x86)
    #define CH2_CFG2_DVOL_M33dB												((uint8_t) 0x87)
    #define CH2_CFG2_DVOL_M32P5dB											((uint8_t) 0x88)
    #define CH2_CFG2_DVOL_M32dB												((uint8_t) 0x89)
    #define CH2_CFG2_DVOL_M31P5dB											((uint8_t) 0x8A)
    #define CH2_CFG2_DVOL_M31dB												((uint8_t) 0x8B)
    #define CH2_CFG2_DVOL_M30P5dB											((uint8_t) 0x8C)
    #define CH2_CFG2_DVOL_M30dB												((uint8_t) 0x8D)
    #define CH2_CFG2_DVOL_M29P5dB											((uint8_t) 0x8E)
    #define CH2_CFG2_DVOL_M29dB												((uint8_t) 0x8F)
    #define CH2_CFG2_DVOL_M28P5dB											((uint8_t) 0x90)
    #define CH2_CFG2_DVOL_M28dB												((uint8_t) 0x91)
    #define CH2_CFG2_DVOL_M27P5dB											((uint8_t) 0x92)
    #define CH2_CFG2_DVOL_M27dB												((uint8_t) 0x93)
    #define CH2_CFG2_DVOL_M26P5dB											((uint8_t) 0x94)
    #define CH2_CFG2_DVOL_M26dB												((uint8_t) 0x95)
    #define CH2_CFG2_DVOL_M25P5dB											((uint8_t) 0x96)
    #define CH2_CFG2_DVOL_M25dB												((uint8_t) 0x97)
    #define CH2_CFG2_DVOL_M24P5dB											((uint8_t) 0x98)
    #define CH2_CFG2_DVOL_M24dB												((uint8_t) 0x99)
    #define CH2_CFG2_DVOL_M23P5dB											((uint8_t) 0x9A)
    #define CH2_CFG2_DVOL_M23dB												((uint8_t) 0x9B)
    #define CH2_CFG2_DVOL_M22P5dB											((uint8_t) 0x9C)
    #define CH2_CFG2_DVOL_M22dB												((uint8_t) 0x9D)
    #define CH2_CFG2_DVOL_M21P5dB											((uint8_t) 0x9E)
    #define CH2_CFG2_DVOL_M21dB												((uint8_t) 0x9F)
    #define CH2_CFG2_DVOL_M20P5dB											((uint8_t) 0xA0)
    #define CH2_CFG2_DVOL_M20dB												((uint8_t) 0xA1)
    #define CH2_CFG2_DVOL_M19P5dB											((uint8_t) 0xA2)
    #define CH2_CFG2_DVOL_M19dB												((uint8_t) 0xA3)
    #define CH2_CFG2_DVOL_M18P5dB											((uint8_t) 0xA4)
    #define CH2_CFG2_DVOL_M18dB												((uint8_t) 0xA5)
    #define CH2_CFG2_DVOL_M17P5dB											((uint8_t) 0xA6)
    #define CH2_CFG2_DVOL_M17dB												((uint8_t) 0xA7)
    #define CH2_CFG2_DVOL_M16P5dB											((uint8_t) 0xA8)
    #define CH2_CFG2_DVOL_M16dB												((uint8_t) 0xA9)
    #define CH2_CFG2_DVOL_M15P5dB											((uint8_t) 0xAA)
    #define CH2_CFG2_DVOL_M15dB												((uint8_t) 0xAB)
    #define CH2_CFG2_DVOL_M14P5dB											((uint8_t) 0xAC)
    #define CH2_CFG2_DVOL_M14dB												((uint8_t) 0xAD)
    #define CH2_CFG2_DVOL_M13P5dB											((uint8_t) 0xAE)
    #define CH2_CFG2_DVOL_M13dB												((uint8_t) 0xAF)
    #define CH2_CFG2_DVOL_M12P5dB											((uint8_t) 0xB0)
    #define CH2_CFG2_DVOL_M12dB												((uint8_t) 0xB1)
    #define CH2_CFG2_DVOL_M11P5dB											((uint8_t) 0xB2)
    #define CH2_CFG2_DVOL_M11dB												((uint8_t) 0xB3)
    #define CH2_CFG2_DVOL_M10P5dB											((uint8_t) 0xB4)
    #define CH2_CFG2_DVOL_M10dB												((uint8_t) 0xB5)
    #define CH2_CFG2_DVOL_M9P5dB											((uint8_t) 0xB6)
    #define CH2_CFG2_DVOL_M9dB												((uint8_t) 0xB7)
    #define CH2_CFG2_DVOL_M8P5dB											((uint8_t) 0xB8)
    #define CH2_CFG2_DVOL_M8dB												((uint8_t) 0xB9)
    #define CH2_CFG2_DVOL_M7P5dB											((uint8_t) 0xBA)
    #define CH2_CFG2_DVOL_M7dB												((uint8_t) 0xBB)
    #define CH2_CFG2_DVOL_M6P5dB											((uint8_t) 0xBC)
    #define CH2_CFG2_DVOL_M6dB												((uint8_t) 0xBD)
    #define CH2_CFG2_DVOL_M5P5dB											((uint8_t) 0xBE)
    #define CH2_CFG2_DVOL_M5dB												((uint8_t) 0xBF)
    #define CH2_CFG2_DVOL_M4P5dB											((uint8_t) 0xC0)
    #define CH2_CFG2_DVOL_M4dB												((uint8_t) 0xC1)
    #define CH2_CFG2_DVOL_M3P5dB											((uint8_t) 0xC2)
    #define CH2_CFG2_DVOL_M3dB												((uint8_t) 0xC3)
    #define CH2_CFG2_DVOL_M2P5dB											((uint8_t) 0xC4)
    #define CH2_CFG2_DVOL_M2dB												((uint8_t) 0xC5)
    #define CH2_CFG2_DVOL_M1P5dB											((uint8_t) 0xC6)
    #define CH2_CFG2_DVOL_M1dB												((uint8_t) 0xC7)
    #define CH2_CFG2_DVOL_M0P5dB											((uint8_t) 0xC8)
    #define CH2_CFG2_DVOL_0dB												((uint8_t) 0xC9)    // DEFAULT
    #define CH2_CFG2_DVOL_0P5dB												((uint8_t) 0xCA)
    #define CH2_CFG2_DVOL_1dB												((uint8_t) 0xCB)
    #define CH2_CFG2_DVOL_1P5dB												((uint8_t) 0xCC)
    #define CH2_CFG2_DVOL_2dB												((uint8_t) 0xCD)
    #define CH2_CFG2_DVOL_2P5dB												((uint8_t) 0xCE)
    #define CH2_CFG2_DVOL_3dB												((uint8_t) 0xCF)
    #define CH2_CFG2_DVOL_3P5dB												((uint8_t) 0xD0)
    #define CH2_CFG2_DVOL_4dB												((uint8_t) 0xD1)
    #define CH2_CFG2_DVOL_4P5dB												((uint8_t) 0xD2)
    #define CH2_CFG2_DVOL_5dB												((uint8_t) 0xD3)
    #define CH2_CFG2_DVOL_5P5dB												((uint8_t) 0xD4)
    #define CH2_CFG2_DVOL_6dB												((uint8_t) 0xD5)
    #define CH2_CFG2_DVOL_6P5dB												((uint8_t) 0xD6)
    #define CH2_CFG2_DVOL_7dB												((uint8_t) 0xD7)
    #define CH2_CFG2_DVOL_7P5dB												((uint8_t) 0xD8)
    #define CH2_CFG2_DVOL_8dB												((uint8_t) 0xD9)
    #define CH2_CFG2_DVOL_8P5dB												((uint8_t) 0xDA)
    #define CH2_CFG2_DVOL_9dB												((uint8_t) 0xDB)
    #define CH2_CFG2_DVOL_9P5dB												((uint8_t) 0xDC)
    #define CH2_CFG2_DVOL_10dB												((uint8_t) 0xDD)
    #define CH2_CFG2_DVOL_10P5dB											((uint8_t) 0xDE)
    #define CH2_CFG2_DVOL_11dB												((uint8_t) 0xDF)
    #define CH2_CFG2_DVOL_11P5dB											((uint8_t) 0xE0)
    #define CH2_CFG2_DVOL_12dB												((uint8_t) 0xE1)
    #define CH2_CFG2_DVOL_12P5dB											((uint8_t) 0xE2)
    #define CH2_CFG2_DVOL_13dB												((uint8_t) 0xE3)
    #define CH2_CFG2_DVOL_13P5dB											((uint8_t) 0xE4)
    #define CH2_CFG2_DVOL_14dB												((uint8_t) 0xE5)
    #define CH2_CFG2_DVOL_14P5dB											((uint8_t) 0xE6)
    #define CH2_CFG2_DVOL_15dB												((uint8_t) 0xE7)
    #define CH2_CFG2_DVOL_15P5dB											((uint8_t) 0xE8)
    #define CH2_CFG2_DVOL_16dB												((uint8_t) 0xE9)
    #define CH2_CFG2_DVOL_16P5dB											((uint8_t) 0xEA)
    #define CH2_CFG2_DVOL_17dB												((uint8_t) 0xEB)
    #define CH2_CFG2_DVOL_17P5dB											((uint8_t) 0xEC)
    #define CH2_CFG2_DVOL_18dB												((uint8_t) 0xED)
    #define CH2_CFG2_DVOL_18P5dB											((uint8_t) 0xEE)
    #define CH2_CFG2_DVOL_19dB												((uint8_t) 0xEF)
    #define CH2_CFG2_DVOL_19P5dB											((uint8_t) 0xF0)
    #define CH2_CFG2_DVOL_20dB												((uint8_t) 0xF1)
    #define CH2_CFG2_DVOL_20P5dB											((uint8_t) 0xF2)
    #define CH2_CFG2_DVOL_21dB												((uint8_t) 0xF3)
    #define CH2_CFG2_DVOL_21P5dB											((uint8_t) 0xF4)
    #define CH2_CFG2_DVOL_22dB												((uint8_t) 0xF5)
    #define CH2_CFG2_DVOL_22P5dB											((uint8_t) 0xF6)
    #define CH2_CFG2_DVOL_23dB												((uint8_t) 0xF7)
    #define CH2_CFG2_DVOL_23P5dB											((uint8_t) 0xF8)
    #define CH2_CFG2_DVOL_24dB												((uint8_t) 0xF9)
    #define CH2_CFG2_DVOL_24P5dB											((uint8_t) 0xFA)
    #define CH2_CFG2_DVOL_25dB												((uint8_t) 0xFB)
    #define CH2_CFG2_DVOL_25P5dB											((uint8_t) 0xFC)
    #define CH2_CFG2_DVOL_26dB												((uint8_t) 0xFD)
    #define CH2_CFG2_DVOL_26P5dB											((uint8_t) 0xFE)
    #define CH2_CFG2_DVOL_27dB												((uint8_t) 0xFF)



/* Register 0x44 (CH2_CFG3) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                       GCAL[3:0]                                       |                                     RESERVED[3:0]                                     |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH2_CFG3 register */
    #define CH2_CFG3_ADDRESS												((uint8_t) 0x44)
    #define CH2_CFG3_DEFAULT												((uint8_t) 0x80)

    /* GCAL field */
    #define CH2_CFG3_GCAL_MASK												((uint8_t) 0xF0)
    #define CH2_CFG3_GCAL_M0P8dB											((uint8_t) 0x00)
    #define CH2_CFG3_GCAL_M0P7dB											((uint8_t) 0x10)
    #define CH2_CFG3_GCAL_M0P6dB											((uint8_t) 0x20)
    #define CH2_CFG3_GCAL_M0P5dB											((uint8_t) 0x30)
    #define CH2_CFG3_GCAL_M0P4dB											((uint8_t) 0x40)
    #define CH2_CFG3_GCAL_M0P3dB											((uint8_t) 0x50)
    #define CH2_CFG3_GCAL_M0P2dB											((uint8_t) 0x60)
    #define CH2_CFG3_GCAL_M0P1dB											((uint8_t) 0x70)
    #define CH2_CFG3_GCAL_0dB												((uint8_t) 0x80)    // DEFAULT
    #define CH2_CFG3_GCAL_0P1dB												((uint8_t) 0x90)
    #define CH2_CFG3_GCAL_0P2dB												((uint8_t) 0xA0)
    #define CH2_CFG3_GCAL_0P3dB												((uint8_t) 0xB0)
    #define CH2_CFG3_GCAL_0P4dB												((uint8_t) 0xC0)
    #define CH2_CFG3_GCAL_0P5dB												((uint8_t) 0xD0)
    #define CH2_CFG3_GCAL_0P6dB												((uint8_t) 0xE0)
    #define CH2_CFG3_GCAL_0P7dB												((uint8_t) 0xF0)



/* Register 0x45 (CH2_CFG4) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                                                   PCAL[7:0]                                                                                   |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH2_CFG4 register */
    #define CH2_CFG4_ADDRESS												((uint8_t) 0x45)
    #define CH2_CFG4_DEFAULT												((uint8_t) 0x00)

    /* PCAL field */
    #define CH2_CFG4_PCAL_MASK												((uint8_t) 0xFF)
    #define CH2_CFG4_PCAL_0													((uint8_t) 0x00)    // DEFAULT
    #define CH2_CFG4_PCAL_1													((uint8_t) 0x01)
    #define CH2_CFG4_PCAL_2													((uint8_t) 0x02)
    #define CH2_CFG4_PCAL_3													((uint8_t) 0x03)
    #define CH2_CFG4_PCAL_4													((uint8_t) 0x04)
    #define CH2_CFG4_PCAL_5													((uint8_t) 0x05)
    #define CH2_CFG4_PCAL_6													((uint8_t) 0x06)
    #define CH2_CFG4_PCAL_7													((uint8_t) 0x07)
    #define CH2_CFG4_PCAL_8													((uint8_t) 0x08)
    #define CH2_CFG4_PCAL_9													((uint8_t) 0x09)
    #define CH2_CFG4_PCAL_10												((uint8_t) 0x0A)
    #define CH2_CFG4_PCAL_11												((uint8_t) 0x0B)
    #define CH2_CFG4_PCAL_12												((uint8_t) 0x0C)
    #define CH2_CFG4_PCAL_13												((uint8_t) 0x0D)
    #define CH2_CFG4_PCAL_14												((uint8_t) 0x0E)
    #define CH2_CFG4_PCAL_15												((uint8_t) 0x0F)
    #define CH2_CFG4_PCAL_16												((uint8_t) 0x10)
    #define CH2_CFG4_PCAL_17												((uint8_t) 0x11)
    #define CH2_CFG4_PCAL_18												((uint8_t) 0x12)
    #define CH2_CFG4_PCAL_19												((uint8_t) 0x13)
    #define CH2_CFG4_PCAL_20												((uint8_t) 0x14)
    #define CH2_CFG4_PCAL_21												((uint8_t) 0x15)
    #define CH2_CFG4_PCAL_22												((uint8_t) 0x16)
    #define CH2_CFG4_PCAL_23												((uint8_t) 0x17)
    #define CH2_CFG4_PCAL_24												((uint8_t) 0x18)
    #define CH2_CFG4_PCAL_25												((uint8_t) 0x19)
    #define CH2_CFG4_PCAL_26												((uint8_t) 0x1A)
    #define CH2_CFG4_PCAL_27												((uint8_t) 0x1B)
    #define CH2_CFG4_PCAL_28												((uint8_t) 0x1C)
    #define CH2_CFG4_PCAL_29												((uint8_t) 0x1D)
    #define CH2_CFG4_PCAL_30												((uint8_t) 0x1E)
    #define CH2_CFG4_PCAL_31												((uint8_t) 0x1F)
    #define CH2_CFG4_PCAL_32												((uint8_t) 0x20)
    #define CH2_CFG4_PCAL_33												((uint8_t) 0x21)
    #define CH2_CFG4_PCAL_34												((uint8_t) 0x22)
    #define CH2_CFG4_PCAL_35												((uint8_t) 0x23)
    #define CH2_CFG4_PCAL_36												((uint8_t) 0x24)
    #define CH2_CFG4_PCAL_37												((uint8_t) 0x25)
    #define CH2_CFG4_PCAL_38												((uint8_t) 0x26)
    #define CH2_CFG4_PCAL_39												((uint8_t) 0x27)
    #define CH2_CFG4_PCAL_40												((uint8_t) 0x28)
    #define CH2_CFG4_PCAL_41												((uint8_t) 0x29)
    #define CH2_CFG4_PCAL_42												((uint8_t) 0x2A)
    #define CH2_CFG4_PCAL_43												((uint8_t) 0x2B)
    #define CH2_CFG4_PCAL_44												((uint8_t) 0x2C)
    #define CH2_CFG4_PCAL_45												((uint8_t) 0x2D)
    #define CH2_CFG4_PCAL_46												((uint8_t) 0x2E)
    #define CH2_CFG4_PCAL_47												((uint8_t) 0x2F)
    #define CH2_CFG4_PCAL_48												((uint8_t) 0x30)
    #define CH2_CFG4_PCAL_49												((uint8_t) 0x31)
    #define CH2_CFG4_PCAL_50												((uint8_t) 0x32)
    #define CH2_CFG4_PCAL_51												((uint8_t) 0x33)
    #define CH2_CFG4_PCAL_52												((uint8_t) 0x34)
    #define CH2_CFG4_PCAL_53												((uint8_t) 0x35)
    #define CH2_CFG4_PCAL_54												((uint8_t) 0x36)
    #define CH2_CFG4_PCAL_55												((uint8_t) 0x37)
    #define CH2_CFG4_PCAL_56												((uint8_t) 0x38)
    #define CH2_CFG4_PCAL_57												((uint8_t) 0x39)
    #define CH2_CFG4_PCAL_58												((uint8_t) 0x3A)
    #define CH2_CFG4_PCAL_59												((uint8_t) 0x3B)
    #define CH2_CFG4_PCAL_60												((uint8_t) 0x3C)
    #define CH2_CFG4_PCAL_61												((uint8_t) 0x3D)
    #define CH2_CFG4_PCAL_62												((uint8_t) 0x3E)
    #define CH2_CFG4_PCAL_63												((uint8_t) 0x3F)
    #define CH2_CFG4_PCAL_64												((uint8_t) 0x40)
    #define CH2_CFG4_PCAL_65												((uint8_t) 0x41)
    #define CH2_CFG4_PCAL_66												((uint8_t) 0x42)
    #define CH2_CFG4_PCAL_67												((uint8_t) 0x43)
    #define CH2_CFG4_PCAL_68												((uint8_t) 0x44)
    #define CH2_CFG4_PCAL_69												((uint8_t) 0x45)
    #define CH2_CFG4_PCAL_70												((uint8_t) 0x46)
    #define CH2_CFG4_PCAL_71												((uint8_t) 0x47)
    #define CH2_CFG4_PCAL_72												((uint8_t) 0x48)
    #define CH2_CFG4_PCAL_73												((uint8_t) 0x49)
    #define CH2_CFG4_PCAL_74												((uint8_t) 0x4A)
    #define CH2_CFG4_PCAL_75												((uint8_t) 0x4B)
    #define CH2_CFG4_PCAL_76												((uint8_t) 0x4C)
    #define CH2_CFG4_PCAL_77												((uint8_t) 0x4D)
    #define CH2_CFG4_PCAL_78												((uint8_t) 0x4E)
    #define CH2_CFG4_PCAL_79												((uint8_t) 0x4F)
    #define CH2_CFG4_PCAL_80												((uint8_t) 0x50)
    #define CH2_CFG4_PCAL_81												((uint8_t) 0x51)
    #define CH2_CFG4_PCAL_82												((uint8_t) 0x52)
    #define CH2_CFG4_PCAL_83												((uint8_t) 0x53)
    #define CH2_CFG4_PCAL_84												((uint8_t) 0x54)
    #define CH2_CFG4_PCAL_85												((uint8_t) 0x55)
    #define CH2_CFG4_PCAL_86												((uint8_t) 0x56)
    #define CH2_CFG4_PCAL_87												((uint8_t) 0x57)
    #define CH2_CFG4_PCAL_88												((uint8_t) 0x58)
    #define CH2_CFG4_PCAL_89												((uint8_t) 0x59)
    #define CH2_CFG4_PCAL_90												((uint8_t) 0x5A)
    #define CH2_CFG4_PCAL_91												((uint8_t) 0x5B)
    #define CH2_CFG4_PCAL_92												((uint8_t) 0x5C)
    #define CH2_CFG4_PCAL_93												((uint8_t) 0x5D)
    #define CH2_CFG4_PCAL_94												((uint8_t) 0x5E)
    #define CH2_CFG4_PCAL_95												((uint8_t) 0x5F)
    #define CH2_CFG4_PCAL_96												((uint8_t) 0x60)
    #define CH2_CFG4_PCAL_97												((uint8_t) 0x61)
    #define CH2_CFG4_PCAL_98												((uint8_t) 0x62)
    #define CH2_CFG4_PCAL_99												((uint8_t) 0x63)
    #define CH2_CFG4_PCAL_100												((uint8_t) 0x64)
    #define CH2_CFG4_PCAL_101												((uint8_t) 0x65)
    #define CH2_CFG4_PCAL_102												((uint8_t) 0x66)
    #define CH2_CFG4_PCAL_103												((uint8_t) 0x67)
    #define CH2_CFG4_PCAL_104												((uint8_t) 0x68)
    #define CH2_CFG4_PCAL_105												((uint8_t) 0x69)
    #define CH2_CFG4_PCAL_106												((uint8_t) 0x6A)
    #define CH2_CFG4_PCAL_107												((uint8_t) 0x6B)
    #define CH2_CFG4_PCAL_108												((uint8_t) 0x6C)
    #define CH2_CFG4_PCAL_109												((uint8_t) 0x6D)
    #define CH2_CFG4_PCAL_110												((uint8_t) 0x6E)
    #define CH2_CFG4_PCAL_111												((uint8_t) 0x6F)
    #define CH2_CFG4_PCAL_112												((uint8_t) 0x70)
    #define CH2_CFG4_PCAL_113												((uint8_t) 0x71)
    #define CH2_CFG4_PCAL_114												((uint8_t) 0x72)
    #define CH2_CFG4_PCAL_115												((uint8_t) 0x73)
    #define CH2_CFG4_PCAL_116												((uint8_t) 0x74)
    #define CH2_CFG4_PCAL_117												((uint8_t) 0x75)
    #define CH2_CFG4_PCAL_118												((uint8_t) 0x76)
    #define CH2_CFG4_PCAL_119												((uint8_t) 0x77)
    #define CH2_CFG4_PCAL_120												((uint8_t) 0x78)
    #define CH2_CFG4_PCAL_121												((uint8_t) 0x79)
    #define CH2_CFG4_PCAL_122												((uint8_t) 0x7A)
    #define CH2_CFG4_PCAL_123												((uint8_t) 0x7B)
    #define CH2_CFG4_PCAL_124												((uint8_t) 0x7C)
    #define CH2_CFG4_PCAL_125												((uint8_t) 0x7D)
    #define CH2_CFG4_PCAL_126												((uint8_t) 0x7E)
    #define CH2_CFG4_PCAL_127												((uint8_t) 0x7F)
    #define CH2_CFG4_PCAL_128												((uint8_t) 0x80)
    #define CH2_CFG4_PCAL_129												((uint8_t) 0x81)
    #define CH2_CFG4_PCAL_130												((uint8_t) 0x82)
    #define CH2_CFG4_PCAL_131												((uint8_t) 0x83)
    #define CH2_CFG4_PCAL_132												((uint8_t) 0x84)
    #define CH2_CFG4_PCAL_133												((uint8_t) 0x85)
    #define CH2_CFG4_PCAL_134												((uint8_t) 0x86)
    #define CH2_CFG4_PCAL_135												((uint8_t) 0x87)
    #define CH2_CFG4_PCAL_136												((uint8_t) 0x88)
    #define CH2_CFG4_PCAL_137												((uint8_t) 0x89)
    #define CH2_CFG4_PCAL_138												((uint8_t) 0x8A)
    #define CH2_CFG4_PCAL_139												((uint8_t) 0x8B)
    #define CH2_CFG4_PCAL_140												((uint8_t) 0x8C)
    #define CH2_CFG4_PCAL_141												((uint8_t) 0x8D)
    #define CH2_CFG4_PCAL_142												((uint8_t) 0x8E)
    #define CH2_CFG4_PCAL_143												((uint8_t) 0x8F)
    #define CH2_CFG4_PCAL_144												((uint8_t) 0x90)
    #define CH2_CFG4_PCAL_145												((uint8_t) 0x91)
    #define CH2_CFG4_PCAL_146												((uint8_t) 0x92)
    #define CH2_CFG4_PCAL_147												((uint8_t) 0x93)
    #define CH2_CFG4_PCAL_148												((uint8_t) 0x94)
    #define CH2_CFG4_PCAL_149												((uint8_t) 0x95)
    #define CH2_CFG4_PCAL_150												((uint8_t) 0x96)
    #define CH2_CFG4_PCAL_151												((uint8_t) 0x97)
    #define CH2_CFG4_PCAL_152												((uint8_t) 0x98)
    #define CH2_CFG4_PCAL_153												((uint8_t) 0x99)
    #define CH2_CFG4_PCAL_154												((uint8_t) 0x9A)
    #define CH2_CFG4_PCAL_155												((uint8_t) 0x9B)
    #define CH2_CFG4_PCAL_156												((uint8_t) 0x9C)
    #define CH2_CFG4_PCAL_157												((uint8_t) 0x9D)
    #define CH2_CFG4_PCAL_158												((uint8_t) 0x9E)
    #define CH2_CFG4_PCAL_159												((uint8_t) 0x9F)
    #define CH2_CFG4_PCAL_160												((uint8_t) 0xA0)
    #define CH2_CFG4_PCAL_161												((uint8_t) 0xA1)
    #define CH2_CFG4_PCAL_162												((uint8_t) 0xA2)
    #define CH2_CFG4_PCAL_163												((uint8_t) 0xA3)
    #define CH2_CFG4_PCAL_164												((uint8_t) 0xA4)
    #define CH2_CFG4_PCAL_165												((uint8_t) 0xA5)
    #define CH2_CFG4_PCAL_166												((uint8_t) 0xA6)
    #define CH2_CFG4_PCAL_167												((uint8_t) 0xA7)
    #define CH2_CFG4_PCAL_168												((uint8_t) 0xA8)
    #define CH2_CFG4_PCAL_169												((uint8_t) 0xA9)
    #define CH2_CFG4_PCAL_170												((uint8_t) 0xAA)
    #define CH2_CFG4_PCAL_171												((uint8_t) 0xAB)
    #define CH2_CFG4_PCAL_172												((uint8_t) 0xAC)
    #define CH2_CFG4_PCAL_173												((uint8_t) 0xAD)
    #define CH2_CFG4_PCAL_174												((uint8_t) 0xAE)
    #define CH2_CFG4_PCAL_175												((uint8_t) 0xAF)
    #define CH2_CFG4_PCAL_176												((uint8_t) 0xB0)
    #define CH2_CFG4_PCAL_177												((uint8_t) 0xB1)
    #define CH2_CFG4_PCAL_178												((uint8_t) 0xB2)
    #define CH2_CFG4_PCAL_179												((uint8_t) 0xB3)
    #define CH2_CFG4_PCAL_180												((uint8_t) 0xB4)
    #define CH2_CFG4_PCAL_181												((uint8_t) 0xB5)
    #define CH2_CFG4_PCAL_182												((uint8_t) 0xB6)
    #define CH2_CFG4_PCAL_183												((uint8_t) 0xB7)
    #define CH2_CFG4_PCAL_184												((uint8_t) 0xB8)
    #define CH2_CFG4_PCAL_185												((uint8_t) 0xB9)
    #define CH2_CFG4_PCAL_186												((uint8_t) 0xBA)
    #define CH2_CFG4_PCAL_187												((uint8_t) 0xBB)
    #define CH2_CFG4_PCAL_188												((uint8_t) 0xBC)
    #define CH2_CFG4_PCAL_189												((uint8_t) 0xBD)
    #define CH2_CFG4_PCAL_190												((uint8_t) 0xBE)
    #define CH2_CFG4_PCAL_191												((uint8_t) 0xBF)
    #define CH2_CFG4_PCAL_192												((uint8_t) 0xC0)
    #define CH2_CFG4_PCAL_193												((uint8_t) 0xC1)
    #define CH2_CFG4_PCAL_194												((uint8_t) 0xC2)
    #define CH2_CFG4_PCAL_195												((uint8_t) 0xC3)
    #define CH2_CFG4_PCAL_196												((uint8_t) 0xC4)
    #define CH2_CFG4_PCAL_197												((uint8_t) 0xC5)
    #define CH2_CFG4_PCAL_198												((uint8_t) 0xC6)
    #define CH2_CFG4_PCAL_199												((uint8_t) 0xC7)
    #define CH2_CFG4_PCAL_200												((uint8_t) 0xC8)
    #define CH2_CFG4_PCAL_201												((uint8_t) 0xC9)
    #define CH2_CFG4_PCAL_202												((uint8_t) 0xCA)
    #define CH2_CFG4_PCAL_203												((uint8_t) 0xCB)
    #define CH2_CFG4_PCAL_204												((uint8_t) 0xCC)
    #define CH2_CFG4_PCAL_205												((uint8_t) 0xCD)
    #define CH2_CFG4_PCAL_206												((uint8_t) 0xCE)
    #define CH2_CFG4_PCAL_207												((uint8_t) 0xCF)
    #define CH2_CFG4_PCAL_208												((uint8_t) 0xD0)
    #define CH2_CFG4_PCAL_209												((uint8_t) 0xD1)
    #define CH2_CFG4_PCAL_210												((uint8_t) 0xD2)
    #define CH2_CFG4_PCAL_211												((uint8_t) 0xD3)
    #define CH2_CFG4_PCAL_212												((uint8_t) 0xD4)
    #define CH2_CFG4_PCAL_213												((uint8_t) 0xD5)
    #define CH2_CFG4_PCAL_214												((uint8_t) 0xD6)
    #define CH2_CFG4_PCAL_215												((uint8_t) 0xD7)
    #define CH2_CFG4_PCAL_216												((uint8_t) 0xD8)
    #define CH2_CFG4_PCAL_217												((uint8_t) 0xD9)
    #define CH2_CFG4_PCAL_218												((uint8_t) 0xDA)
    #define CH2_CFG4_PCAL_219												((uint8_t) 0xDB)
    #define CH2_CFG4_PCAL_220												((uint8_t) 0xDC)
    #define CH2_CFG4_PCAL_221												((uint8_t) 0xDD)
    #define CH2_CFG4_PCAL_222												((uint8_t) 0xDE)
    #define CH2_CFG4_PCAL_223												((uint8_t) 0xDF)
    #define CH2_CFG4_PCAL_224												((uint8_t) 0xE0)
    #define CH2_CFG4_PCAL_225												((uint8_t) 0xE1)
    #define CH2_CFG4_PCAL_226												((uint8_t) 0xE2)
    #define CH2_CFG4_PCAL_227												((uint8_t) 0xE3)
    #define CH2_CFG4_PCAL_228												((uint8_t) 0xE4)
    #define CH2_CFG4_PCAL_229												((uint8_t) 0xE5)
    #define CH2_CFG4_PCAL_230												((uint8_t) 0xE6)
    #define CH2_CFG4_PCAL_231												((uint8_t) 0xE7)
    #define CH2_CFG4_PCAL_232												((uint8_t) 0xE8)
    #define CH2_CFG4_PCAL_233												((uint8_t) 0xE9)
    #define CH2_CFG4_PCAL_234												((uint8_t) 0xEA)
    #define CH2_CFG4_PCAL_235												((uint8_t) 0xEB)
    #define CH2_CFG4_PCAL_236												((uint8_t) 0xEC)
    #define CH2_CFG4_PCAL_237												((uint8_t) 0xED)
    #define CH2_CFG4_PCAL_238												((uint8_t) 0xEE)
    #define CH2_CFG4_PCAL_239												((uint8_t) 0xEF)
    #define CH2_CFG4_PCAL_240												((uint8_t) 0xF0)
    #define CH2_CFG4_PCAL_241												((uint8_t) 0xF1)
    #define CH2_CFG4_PCAL_242												((uint8_t) 0xF2)
    #define CH2_CFG4_PCAL_243												((uint8_t) 0xF3)
    #define CH2_CFG4_PCAL_244												((uint8_t) 0xF4)
    #define CH2_CFG4_PCAL_245												((uint8_t) 0xF5)
    #define CH2_CFG4_PCAL_246												((uint8_t) 0xF6)
    #define CH2_CFG4_PCAL_247												((uint8_t) 0xF7)
    #define CH2_CFG4_PCAL_248												((uint8_t) 0xF8)
    #define CH2_CFG4_PCAL_249												((uint8_t) 0xF9)
    #define CH2_CFG4_PCAL_250												((uint8_t) 0xFA)
    #define CH2_CFG4_PCAL_251												((uint8_t) 0xFB)
    #define CH2_CFG4_PCAL_252												((uint8_t) 0xFC)
    #define CH2_CFG4_PCAL_253												((uint8_t) 0xFD)
    #define CH2_CFG4_PCAL_254												((uint8_t) 0xFE)
    #define CH2_CFG4_PCAL_255												((uint8_t) 0xFF)



/* Register 0x46 (CH3_CFG0) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        INTYP        |                 INSRC[1:0]                |          DC         |                  IMP[1:0]                 |       RESERVED      |        DREEN        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH3_CFG0 register */
    #define CH3_CFG0_ADDRESS												((uint8_t) 0x46)
    #define CH3_CFG0_DEFAULT												((uint8_t) 0x00)

    /* INTYP field */
    #define CH3_CFG0_INTYP_MASK												((uint8_t) 0x80)
    #define CH3_CFG0_INTYP_MIC												((uint8_t) 0x00)    // DEFAULT
    #define CH3_CFG0_INTYP_LINE												((uint8_t) 0x80)

    /* INSRC field */
    #define CH3_CFG0_INSRC_MASK												((uint8_t) 0x60)
    #define CH3_CFG0_INSRC_DIFF												((uint8_t) 0x00)    // DEFAULT
    #define CH3_CFG0_INSRC_SINGLE											((uint8_t) 0x20)
    #define CH3_CFG0_INSRC_PDM												((uint8_t) 0x40)

    /* DC field */
    #define CH3_CFG0_DC_MASK												((uint8_t) 0x10)
    #define CH3_CFG0_DC_AC													((uint8_t) 0x00)    // DEFAULT
    #define CH3_CFG0_DC_DC													((uint8_t) 0x10)

    /* IMP field */
    #define CH3_CFG0_IMP_MASK												((uint8_t) 0x0C)
    #define CH3_CFG0_IMP_2P5k												((uint8_t) 0x00)    // DEFAULT
    #define CH3_CFG0_IMP_10k												((uint8_t) 0x04)
    #define CH3_CFG0_IMP_20k												((uint8_t) 0x08)

    /* DREEN field */
    #define CH3_CFG0_DREEN_MASK												((uint8_t) 0x01)
    #define CH3_CFG0_DREEN_DISABLED											((uint8_t) 0x00)    // DEFAULT
    #define CH3_CFG0_DREEN_ENABLED											((uint8_t) 0x01)



/* Register 0x47 (CH3_CFG1) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                             GAIN[5:0]                                                             |               RESERVED[1:0]               |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH3_CFG1 register */
    #define CH3_CFG1_ADDRESS												((uint8_t) 0x47)
    #define CH3_CFG1_DEFAULT												((uint8_t) 0x00)

    /* GAIN field */
    #define CH3_CFG1_GAIN_MASK												((uint8_t) 0xFC)
    #define CH3_CFG1_GAIN_0dB												((uint8_t) 0x00)    // DEFAULT
    #define CH3_CFG1_GAIN_1dB												((uint8_t) 0x04)
    #define CH3_CFG1_GAIN_2dB												((uint8_t) 0x08)
    #define CH3_CFG1_GAIN_3dB												((uint8_t) 0x0C)
    #define CH3_CFG1_GAIN_4dB												((uint8_t) 0x10)
    #define CH3_CFG1_GAIN_5dB												((uint8_t) 0x14)
    #define CH3_CFG1_GAIN_6dB												((uint8_t) 0x18)
    #define CH3_CFG1_GAIN_7dB												((uint8_t) 0x1C)
    #define CH3_CFG1_GAIN_8dB												((uint8_t) 0x20)
    #define CH3_CFG1_GAIN_9dB												((uint8_t) 0x24)
    #define CH3_CFG1_GAIN_10dB												((uint8_t) 0x28)
    #define CH3_CFG1_GAIN_11dB												((uint8_t) 0x2C)
    #define CH3_CFG1_GAIN_12dB												((uint8_t) 0x30)
    #define CH3_CFG1_GAIN_13dB												((uint8_t) 0x34)
    #define CH3_CFG1_GAIN_14dB												((uint8_t) 0x38)
    #define CH3_CFG1_GAIN_15dB												((uint8_t) 0x3C)
    #define CH3_CFG1_GAIN_16dB												((uint8_t) 0x40)
    #define CH3_CFG1_GAIN_17dB												((uint8_t) 0x44)
    #define CH3_CFG1_GAIN_18dB												((uint8_t) 0x48)
    #define CH3_CFG1_GAIN_19dB												((uint8_t) 0x4C)
    #define CH3_CFG1_GAIN_20dB												((uint8_t) 0x50)
    #define CH3_CFG1_GAIN_21dB												((uint8_t) 0x54)
    #define CH3_CFG1_GAIN_22dB												((uint8_t) 0x58)
    #define CH3_CFG1_GAIN_23dB												((uint8_t) 0x5C)
    #define CH3_CFG1_GAIN_24dB												((uint8_t) 0x60)
    #define CH3_CFG1_GAIN_25dB												((uint8_t) 0x64)
    #define CH3_CFG1_GAIN_26dB												((uint8_t) 0x68)
    #define CH3_CFG1_GAIN_27dB												((uint8_t) 0x6C)
    #define CH3_CFG1_GAIN_28dB												((uint8_t) 0x70)
    #define CH3_CFG1_GAIN_29dB												((uint8_t) 0x74)
    #define CH3_CFG1_GAIN_30dB												((uint8_t) 0x78)
    #define CH3_CFG1_GAIN_31dB												((uint8_t) 0x7C)
    #define CH3_CFG1_GAIN_32dB												((uint8_t) 0x80)
    #define CH3_CFG1_GAIN_33dB												((uint8_t) 0x84)
    #define CH3_CFG1_GAIN_34dB												((uint8_t) 0x88)
    #define CH3_CFG1_GAIN_35dB												((uint8_t) 0x8C)
    #define CH3_CFG1_GAIN_36dB												((uint8_t) 0x90)
    #define CH3_CFG1_GAIN_37dB												((uint8_t) 0x94)
    #define CH3_CFG1_GAIN_38dB												((uint8_t) 0x98)
    #define CH3_CFG1_GAIN_39dB												((uint8_t) 0x9C)
    #define CH3_CFG1_GAIN_40dB												((uint8_t) 0xA0)
    #define CH3_CFG1_GAIN_41dB												((uint8_t) 0xA4)
    #define CH3_CFG1_GAIN_42dB												((uint8_t) 0xA8)



/* Register 0x48 (CH3_CFG2) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                                                   DVOL[7:0]                                                                                   |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH3_CFG2 register */
    #define CH3_CFG2_ADDRESS												((uint8_t) 0x48)
    #define CH3_CFG2_DEFAULT												((uint8_t) 0xC9)

    /* DVOL field */
    #define CH3_CFG2_DVOL_MASK												((uint8_t) 0xFF)
    #define CH3_CFG2_DVOL_MUTE												((uint8_t) 0x00)
    #define CH3_CFG2_DVOL_M100dB											((uint8_t) 0x01)
    #define CH3_CFG2_DVOL_M99P5dB											((uint8_t) 0x02)
    #define CH3_CFG2_DVOL_M99dB												((uint8_t) 0x03)
    #define CH3_CFG2_DVOL_M98P5dB											((uint8_t) 0x04)
    #define CH3_CFG2_DVOL_M98dB												((uint8_t) 0x05)
    #define CH3_CFG2_DVOL_M97P5dB											((uint8_t) 0x06)
    #define CH3_CFG2_DVOL_M97dB												((uint8_t) 0x07)
    #define CH3_CFG2_DVOL_M96P5dB											((uint8_t) 0x08)
    #define CH3_CFG2_DVOL_M96dB												((uint8_t) 0x09)
    #define CH3_CFG2_DVOL_M95P5dB											((uint8_t) 0x0A)
    #define CH3_CFG2_DVOL_M95dB												((uint8_t) 0x0B)
    #define CH3_CFG2_DVOL_M94P5dB											((uint8_t) 0x0C)
    #define CH3_CFG2_DVOL_M94dB												((uint8_t) 0x0D)
    #define CH3_CFG2_DVOL_M93P5dB											((uint8_t) 0x0E)
    #define CH3_CFG2_DVOL_M93dB												((uint8_t) 0x0F)
    #define CH3_CFG2_DVOL_M92P5dB											((uint8_t) 0x10)
    #define CH3_CFG2_DVOL_M92dB												((uint8_t) 0x11)
    #define CH3_CFG2_DVOL_M91P5dB											((uint8_t) 0x12)
    #define CH3_CFG2_DVOL_M91dB												((uint8_t) 0x13)
    #define CH3_CFG2_DVOL_M90P5dB											((uint8_t) 0x14)
    #define CH3_CFG2_DVOL_M90dB												((uint8_t) 0x15)
    #define CH3_CFG2_DVOL_M89P5dB											((uint8_t) 0x16)
    #define CH3_CFG2_DVOL_M89dB												((uint8_t) 0x17)
    #define CH3_CFG2_DVOL_M88P5dB											((uint8_t) 0x18)
    #define CH3_CFG2_DVOL_M88dB												((uint8_t) 0x19)
    #define CH3_CFG2_DVOL_M87P5dB											((uint8_t) 0x1A)
    #define CH3_CFG2_DVOL_M87dB												((uint8_t) 0x1B)
    #define CH3_CFG2_DVOL_M86P5dB											((uint8_t) 0x1C)
    #define CH3_CFG2_DVOL_M86dB												((uint8_t) 0x1D)
    #define CH3_CFG2_DVOL_M85P5dB											((uint8_t) 0x1E)
    #define CH3_CFG2_DVOL_M85dB												((uint8_t) 0x1F)
    #define CH3_CFG2_DVOL_M84P5dB											((uint8_t) 0x20)
    #define CH3_CFG2_DVOL_M84dB												((uint8_t) 0x21)
    #define CH3_CFG2_DVOL_M83P5dB											((uint8_t) 0x22)
    #define CH3_CFG2_DVOL_M83dB												((uint8_t) 0x23)
    #define CH3_CFG2_DVOL_M82P5dB											((uint8_t) 0x24)
    #define CH3_CFG2_DVOL_M82dB												((uint8_t) 0x25)
    #define CH3_CFG2_DVOL_M81P5dB											((uint8_t) 0x26)
    #define CH3_CFG2_DVOL_M81dB												((uint8_t) 0x27)
    #define CH3_CFG2_DVOL_M80P5dB											((uint8_t) 0x28)
    #define CH3_CFG2_DVOL_M80dB												((uint8_t) 0x29)
    #define CH3_CFG2_DVOL_M79P5dB											((uint8_t) 0x2A)
    #define CH3_CFG2_DVOL_M79dB												((uint8_t) 0x2B)
    #define CH3_CFG2_DVOL_M78P5dB											((uint8_t) 0x2C)
    #define CH3_CFG2_DVOL_M78dB												((uint8_t) 0x2D)
    #define CH3_CFG2_DVOL_M77P5dB											((uint8_t) 0x2E)
    #define CH3_CFG2_DVOL_M77dB												((uint8_t) 0x2F)
    #define CH3_CFG2_DVOL_M76P5dB											((uint8_t) 0x30)
    #define CH3_CFG2_DVOL_M76dB												((uint8_t) 0x31)
    #define CH3_CFG2_DVOL_M75P5dB											((uint8_t) 0x32)
    #define CH3_CFG2_DVOL_M75dB												((uint8_t) 0x33)
    #define CH3_CFG2_DVOL_M74P5dB											((uint8_t) 0x34)
    #define CH3_CFG2_DVOL_M74dB												((uint8_t) 0x35)
    #define CH3_CFG2_DVOL_M73P5dB											((uint8_t) 0x36)
    #define CH3_CFG2_DVOL_M73dB												((uint8_t) 0x37)
    #define CH3_CFG2_DVOL_M72P5dB											((uint8_t) 0x38)
    #define CH3_CFG2_DVOL_M72dB												((uint8_t) 0x39)
    #define CH3_CFG2_DVOL_M71P5dB											((uint8_t) 0x3A)
    #define CH3_CFG2_DVOL_M71dB												((uint8_t) 0x3B)
    #define CH3_CFG2_DVOL_M70P5dB											((uint8_t) 0x3C)
    #define CH3_CFG2_DVOL_M70dB												((uint8_t) 0x3D)
    #define CH3_CFG2_DVOL_M69P5dB											((uint8_t) 0x3E)
    #define CH3_CFG2_DVOL_M69dB												((uint8_t) 0x3F)
    #define CH3_CFG2_DVOL_M68P5dB											((uint8_t) 0x40)
    #define CH3_CFG2_DVOL_M68dB												((uint8_t) 0x41)
    #define CH3_CFG2_DVOL_M67P5dB											((uint8_t) 0x42)
    #define CH3_CFG2_DVOL_M67dB												((uint8_t) 0x43)
    #define CH3_CFG2_DVOL_M66P5dB											((uint8_t) 0x44)
    #define CH3_CFG2_DVOL_M66dB												((uint8_t) 0x45)
    #define CH3_CFG2_DVOL_M65P5dB											((uint8_t) 0x46)
    #define CH3_CFG2_DVOL_M65dB												((uint8_t) 0x47)
    #define CH3_CFG2_DVOL_M64P5dB											((uint8_t) 0x48)
    #define CH3_CFG2_DVOL_M64dB												((uint8_t) 0x49)
    #define CH3_CFG2_DVOL_M63P5dB											((uint8_t) 0x4A)
    #define CH3_CFG2_DVOL_M63dB												((uint8_t) 0x4B)
    #define CH3_CFG2_DVOL_M62P5dB											((uint8_t) 0x4C)
    #define CH3_CFG2_DVOL_M62dB												((uint8_t) 0x4D)
    #define CH3_CFG2_DVOL_M61P5dB											((uint8_t) 0x4E)
    #define CH3_CFG2_DVOL_M61dB												((uint8_t) 0x4F)
    #define CH3_CFG2_DVOL_M60P5dB											((uint8_t) 0x50)
    #define CH3_CFG2_DVOL_M60dB												((uint8_t) 0x51)
    #define CH3_CFG2_DVOL_M59P5dB											((uint8_t) 0x52)
    #define CH3_CFG2_DVOL_M59dB												((uint8_t) 0x53)
    #define CH3_CFG2_DVOL_M58P5dB											((uint8_t) 0x54)
    #define CH3_CFG2_DVOL_M58dB												((uint8_t) 0x55)
    #define CH3_CFG2_DVOL_M57P5dB											((uint8_t) 0x56)
    #define CH3_CFG2_DVOL_M57dB												((uint8_t) 0x57)
    #define CH3_CFG2_DVOL_M56P5dB											((uint8_t) 0x58)
    #define CH3_CFG2_DVOL_M56dB												((uint8_t) 0x59)
    #define CH3_CFG2_DVOL_M55P5dB											((uint8_t) 0x5A)
    #define CH3_CFG2_DVOL_M55dB												((uint8_t) 0x5B)
    #define CH3_CFG2_DVOL_M54P5dB											((uint8_t) 0x5C)
    #define CH3_CFG2_DVOL_M54dB												((uint8_t) 0x5D)
    #define CH3_CFG2_DVOL_M53P5dB											((uint8_t) 0x5E)
    #define CH3_CFG2_DVOL_M53dB												((uint8_t) 0x5F)
    #define CH3_CFG2_DVOL_M52P5dB											((uint8_t) 0x60)
    #define CH3_CFG2_DVOL_M52dB												((uint8_t) 0x61)
    #define CH3_CFG2_DVOL_M51P5dB											((uint8_t) 0x62)
    #define CH3_CFG2_DVOL_M51dB												((uint8_t) 0x63)
    #define CH3_CFG2_DVOL_M50P5dB											((uint8_t) 0x64)
    #define CH3_CFG2_DVOL_M50dB												((uint8_t) 0x65)
    #define CH3_CFG2_DVOL_M49P5dB											((uint8_t) 0x66)
    #define CH3_CFG2_DVOL_M49dB												((uint8_t) 0x67)
    #define CH3_CFG2_DVOL_M48P5dB											((uint8_t) 0x68)
    #define CH3_CFG2_DVOL_M48dB												((uint8_t) 0x69)
    #define CH3_CFG2_DVOL_M47P5dB											((uint8_t) 0x6A)
    #define CH3_CFG2_DVOL_M47dB												((uint8_t) 0x6B)
    #define CH3_CFG2_DVOL_M46P5dB											((uint8_t) 0x6C)
    #define CH3_CFG2_DVOL_M46dB												((uint8_t) 0x6D)
    #define CH3_CFG2_DVOL_M45P5dB											((uint8_t) 0x6E)
    #define CH3_CFG2_DVOL_M45dB												((uint8_t) 0x6F)
    #define CH3_CFG2_DVOL_M44P5dB											((uint8_t) 0x70)
    #define CH3_CFG2_DVOL_M44dB												((uint8_t) 0x71)
    #define CH3_CFG2_DVOL_M43P5dB											((uint8_t) 0x72)
    #define CH3_CFG2_DVOL_M43dB												((uint8_t) 0x73)
    #define CH3_CFG2_DVOL_M42P5dB											((uint8_t) 0x74)
    #define CH3_CFG2_DVOL_M42dB												((uint8_t) 0x75)
    #define CH3_CFG2_DVOL_M41P5dB											((uint8_t) 0x76)
    #define CH3_CFG2_DVOL_M41dB												((uint8_t) 0x77)
    #define CH3_CFG2_DVOL_M40P5dB											((uint8_t) 0x78)
    #define CH3_CFG2_DVOL_M40dB												((uint8_t) 0x79)
    #define CH3_CFG2_DVOL_M39P5dB											((uint8_t) 0x7A)
    #define CH3_CFG2_DVOL_M39dB												((uint8_t) 0x7B)
    #define CH3_CFG2_DVOL_M38P5dB											((uint8_t) 0x7C)
    #define CH3_CFG2_DVOL_M38dB												((uint8_t) 0x7D)
    #define CH3_CFG2_DVOL_M37P5dB											((uint8_t) 0x7E)
    #define CH3_CFG2_DVOL_M37dB												((uint8_t) 0x7F)
    #define CH3_CFG2_DVOL_M36P5dB											((uint8_t) 0x80)
    #define CH3_CFG2_DVOL_M36dB												((uint8_t) 0x81)
    #define CH3_CFG2_DVOL_M35P5dB											((uint8_t) 0x82)
    #define CH3_CFG2_DVOL_M35dB												((uint8_t) 0x83)
    #define CH3_CFG2_DVOL_M34P5dB											((uint8_t) 0x84)
    #define CH3_CFG2_DVOL_M34dB												((uint8_t) 0x85)
    #define CH3_CFG2_DVOL_M33P5dB											((uint8_t) 0x86)
    #define CH3_CFG2_DVOL_M33dB												((uint8_t) 0x87)
    #define CH3_CFG2_DVOL_M32P5dB											((uint8_t) 0x88)
    #define CH3_CFG2_DVOL_M32dB												((uint8_t) 0x89)
    #define CH3_CFG2_DVOL_M31P5dB											((uint8_t) 0x8A)
    #define CH3_CFG2_DVOL_M31dB												((uint8_t) 0x8B)
    #define CH3_CFG2_DVOL_M30P5dB											((uint8_t) 0x8C)
    #define CH3_CFG2_DVOL_M30dB												((uint8_t) 0x8D)
    #define CH3_CFG2_DVOL_M29P5dB											((uint8_t) 0x8E)
    #define CH3_CFG2_DVOL_M29dB												((uint8_t) 0x8F)
    #define CH3_CFG2_DVOL_M28P5dB											((uint8_t) 0x90)
    #define CH3_CFG2_DVOL_M28dB												((uint8_t) 0x91)
    #define CH3_CFG2_DVOL_M27P5dB											((uint8_t) 0x92)
    #define CH3_CFG2_DVOL_M27dB												((uint8_t) 0x93)
    #define CH3_CFG2_DVOL_M26P5dB											((uint8_t) 0x94)
    #define CH3_CFG2_DVOL_M26dB												((uint8_t) 0x95)
    #define CH3_CFG2_DVOL_M25P5dB											((uint8_t) 0x96)
    #define CH3_CFG2_DVOL_M25dB												((uint8_t) 0x97)
    #define CH3_CFG2_DVOL_M24P5dB											((uint8_t) 0x98)
    #define CH3_CFG2_DVOL_M24dB												((uint8_t) 0x99)
    #define CH3_CFG2_DVOL_M23P5dB											((uint8_t) 0x9A)
    #define CH3_CFG2_DVOL_M23dB												((uint8_t) 0x9B)
    #define CH3_CFG2_DVOL_M22P5dB											((uint8_t) 0x9C)
    #define CH3_CFG2_DVOL_M22dB												((uint8_t) 0x9D)
    #define CH3_CFG2_DVOL_M21P5dB											((uint8_t) 0x9E)
    #define CH3_CFG2_DVOL_M21dB												((uint8_t) 0x9F)
    #define CH3_CFG2_DVOL_M20P5dB											((uint8_t) 0xA0)
    #define CH3_CFG2_DVOL_M20dB												((uint8_t) 0xA1)
    #define CH3_CFG2_DVOL_M19P5dB											((uint8_t) 0xA2)
    #define CH3_CFG2_DVOL_M19dB												((uint8_t) 0xA3)
    #define CH3_CFG2_DVOL_M18P5dB											((uint8_t) 0xA4)
    #define CH3_CFG2_DVOL_M18dB												((uint8_t) 0xA5)
    #define CH3_CFG2_DVOL_M17P5dB											((uint8_t) 0xA6)
    #define CH3_CFG2_DVOL_M17dB												((uint8_t) 0xA7)
    #define CH3_CFG2_DVOL_M16P5dB											((uint8_t) 0xA8)
    #define CH3_CFG2_DVOL_M16dB												((uint8_t) 0xA9)
    #define CH3_CFG2_DVOL_M15P5dB											((uint8_t) 0xAA)
    #define CH3_CFG2_DVOL_M15dB												((uint8_t) 0xAB)
    #define CH3_CFG2_DVOL_M14P5dB											((uint8_t) 0xAC)
    #define CH3_CFG2_DVOL_M14dB												((uint8_t) 0xAD)
    #define CH3_CFG2_DVOL_M13P5dB											((uint8_t) 0xAE)
    #define CH3_CFG2_DVOL_M13dB												((uint8_t) 0xAF)
    #define CH3_CFG2_DVOL_M12P5dB											((uint8_t) 0xB0)
    #define CH3_CFG2_DVOL_M12dB												((uint8_t) 0xB1)
    #define CH3_CFG2_DVOL_M11P5dB											((uint8_t) 0xB2)
    #define CH3_CFG2_DVOL_M11dB												((uint8_t) 0xB3)
    #define CH3_CFG2_DVOL_M10P5dB											((uint8_t) 0xB4)
    #define CH3_CFG2_DVOL_M10dB												((uint8_t) 0xB5)
    #define CH3_CFG2_DVOL_M9P5dB											((uint8_t) 0xB6)
    #define CH3_CFG2_DVOL_M9dB												((uint8_t) 0xB7)
    #define CH3_CFG2_DVOL_M8P5dB											((uint8_t) 0xB8)
    #define CH3_CFG2_DVOL_M8dB												((uint8_t) 0xB9)
    #define CH3_CFG2_DVOL_M7P5dB											((uint8_t) 0xBA)
    #define CH3_CFG2_DVOL_M7dB												((uint8_t) 0xBB)
    #define CH3_CFG2_DVOL_M6P5dB											((uint8_t) 0xBC)
    #define CH3_CFG2_DVOL_M6dB												((uint8_t) 0xBD)
    #define CH3_CFG2_DVOL_M5P5dB											((uint8_t) 0xBE)
    #define CH3_CFG2_DVOL_M5dB												((uint8_t) 0xBF)
    #define CH3_CFG2_DVOL_M4P5dB											((uint8_t) 0xC0)
    #define CH3_CFG2_DVOL_M4dB												((uint8_t) 0xC1)
    #define CH3_CFG2_DVOL_M3P5dB											((uint8_t) 0xC2)
    #define CH3_CFG2_DVOL_M3dB												((uint8_t) 0xC3)
    #define CH3_CFG2_DVOL_M2P5dB											((uint8_t) 0xC4)
    #define CH3_CFG2_DVOL_M2dB												((uint8_t) 0xC5)
    #define CH3_CFG2_DVOL_M1P5dB											((uint8_t) 0xC6)
    #define CH3_CFG2_DVOL_M1dB												((uint8_t) 0xC7)
    #define CH3_CFG2_DVOL_M0P5dB											((uint8_t) 0xC8)
    #define CH3_CFG2_DVOL_0dB												((uint8_t) 0xC9)    // DEFAULT
    #define CH3_CFG2_DVOL_0P5dB												((uint8_t) 0xCA)
    #define CH3_CFG2_DVOL_1dB												((uint8_t) 0xCB)
    #define CH3_CFG2_DVOL_1P5dB												((uint8_t) 0xCC)
    #define CH3_CFG2_DVOL_2dB												((uint8_t) 0xCD)
    #define CH3_CFG2_DVOL_2P5dB												((uint8_t) 0xCE)
    #define CH3_CFG2_DVOL_3dB												((uint8_t) 0xCF)
    #define CH3_CFG2_DVOL_3P5dB												((uint8_t) 0xD0)
    #define CH3_CFG2_DVOL_4dB												((uint8_t) 0xD1)
    #define CH3_CFG2_DVOL_4P5dB												((uint8_t) 0xD2)
    #define CH3_CFG2_DVOL_5dB												((uint8_t) 0xD3)
    #define CH3_CFG2_DVOL_5P5dB												((uint8_t) 0xD4)
    #define CH3_CFG2_DVOL_6dB												((uint8_t) 0xD5)
    #define CH3_CFG2_DVOL_6P5dB												((uint8_t) 0xD6)
    #define CH3_CFG2_DVOL_7dB												((uint8_t) 0xD7)
    #define CH3_CFG2_DVOL_7P5dB												((uint8_t) 0xD8)
    #define CH3_CFG2_DVOL_8dB												((uint8_t) 0xD9)
    #define CH3_CFG2_DVOL_8P5dB												((uint8_t) 0xDA)
    #define CH3_CFG2_DVOL_9dB												((uint8_t) 0xDB)
    #define CH3_CFG2_DVOL_9P5dB												((uint8_t) 0xDC)
    #define CH3_CFG2_DVOL_10dB												((uint8_t) 0xDD)
    #define CH3_CFG2_DVOL_10P5dB											((uint8_t) 0xDE)
    #define CH3_CFG2_DVOL_11dB												((uint8_t) 0xDF)
    #define CH3_CFG2_DVOL_11P5dB											((uint8_t) 0xE0)
    #define CH3_CFG2_DVOL_12dB												((uint8_t) 0xE1)
    #define CH3_CFG2_DVOL_12P5dB											((uint8_t) 0xE2)
    #define CH3_CFG2_DVOL_13dB												((uint8_t) 0xE3)
    #define CH3_CFG2_DVOL_13P5dB											((uint8_t) 0xE4)
    #define CH3_CFG2_DVOL_14dB												((uint8_t) 0xE5)
    #define CH3_CFG2_DVOL_14P5dB											((uint8_t) 0xE6)
    #define CH3_CFG2_DVOL_15dB												((uint8_t) 0xE7)
    #define CH3_CFG2_DVOL_15P5dB											((uint8_t) 0xE8)
    #define CH3_CFG2_DVOL_16dB												((uint8_t) 0xE9)
    #define CH3_CFG2_DVOL_16P5dB											((uint8_t) 0xEA)
    #define CH3_CFG2_DVOL_17dB												((uint8_t) 0xEB)
    #define CH3_CFG2_DVOL_17P5dB											((uint8_t) 0xEC)
    #define CH3_CFG2_DVOL_18dB												((uint8_t) 0xED)
    #define CH3_CFG2_DVOL_18P5dB											((uint8_t) 0xEE)
    #define CH3_CFG2_DVOL_19dB												((uint8_t) 0xEF)
    #define CH3_CFG2_DVOL_19P5dB											((uint8_t) 0xF0)
    #define CH3_CFG2_DVOL_20dB												((uint8_t) 0xF1)
    #define CH3_CFG2_DVOL_20P5dB											((uint8_t) 0xF2)
    #define CH3_CFG2_DVOL_21dB												((uint8_t) 0xF3)
    #define CH3_CFG2_DVOL_21P5dB											((uint8_t) 0xF4)
    #define CH3_CFG2_DVOL_22dB												((uint8_t) 0xF5)
    #define CH3_CFG2_DVOL_22P5dB											((uint8_t) 0xF6)
    #define CH3_CFG2_DVOL_23dB												((uint8_t) 0xF7)
    #define CH3_CFG2_DVOL_23P5dB											((uint8_t) 0xF8)
    #define CH3_CFG2_DVOL_24dB												((uint8_t) 0xF9)
    #define CH3_CFG2_DVOL_24P5dB											((uint8_t) 0xFA)
    #define CH3_CFG2_DVOL_25dB												((uint8_t) 0xFB)
    #define CH3_CFG2_DVOL_25P5dB											((uint8_t) 0xFC)
    #define CH3_CFG2_DVOL_26dB												((uint8_t) 0xFD)
    #define CH3_CFG2_DVOL_26P5dB											((uint8_t) 0xFE)
    #define CH3_CFG2_DVOL_27dB												((uint8_t) 0xFF)



/* Register 0x49 (CH3_CFG3) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                       GCAL[3:0]                                       |                                     RESERVED[3:0]                                     |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH3_CFG3 register */
    #define CH3_CFG3_ADDRESS												((uint8_t) 0x49)
    #define CH3_CFG3_DEFAULT												((uint8_t) 0x80)

    /* GCAL field */
    #define CH3_CFG3_GCAL_MASK												((uint8_t) 0xF0)
    #define CH3_CFG3_GCAL_M0P8dB											((uint8_t) 0x00)
    #define CH3_CFG3_GCAL_M0P7dB											((uint8_t) 0x10)
    #define CH3_CFG3_GCAL_M0P6dB											((uint8_t) 0x20)
    #define CH3_CFG3_GCAL_M0P5dB											((uint8_t) 0x30)
    #define CH3_CFG3_GCAL_M0P4dB											((uint8_t) 0x40)
    #define CH3_CFG3_GCAL_M0P3dB											((uint8_t) 0x50)
    #define CH3_CFG3_GCAL_M0P2dB											((uint8_t) 0x60)
    #define CH3_CFG3_GCAL_M0P1dB											((uint8_t) 0x70)
    #define CH3_CFG3_GCAL_0dB												((uint8_t) 0x80)    // DEFAULT
    #define CH3_CFG3_GCAL_0P1dB												((uint8_t) 0x90)
    #define CH3_CFG3_GCAL_0P2dB												((uint8_t) 0xA0)
    #define CH3_CFG3_GCAL_0P3dB												((uint8_t) 0xB0)
    #define CH3_CFG3_GCAL_0P4dB												((uint8_t) 0xC0)
    #define CH3_CFG3_GCAL_0P5dB												((uint8_t) 0xD0)
    #define CH3_CFG3_GCAL_0P6dB												((uint8_t) 0xE0)
    #define CH3_CFG3_GCAL_0P7dB												((uint8_t) 0xF0)



/* Register 0x4A (CH3_CFG4) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                                                   PCAL[7:0]                                                                                   |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH3_CFG4 register */
    #define CH3_CFG4_ADDRESS												((uint8_t) 0x4A)
    #define CH3_CFG4_DEFAULT												((uint8_t) 0x00)

    /* PCAL field */
    #define CH3_CFG4_PCAL_MASK												((uint8_t) 0xFF)
    #define CH3_CFG4_PCAL_0													((uint8_t) 0x00)    // DEFAULT
    #define CH3_CFG4_PCAL_1													((uint8_t) 0x01)
    #define CH3_CFG4_PCAL_2													((uint8_t) 0x02)
    #define CH3_CFG4_PCAL_3													((uint8_t) 0x03)
    #define CH3_CFG4_PCAL_4													((uint8_t) 0x04)
    #define CH3_CFG4_PCAL_5													((uint8_t) 0x05)
    #define CH3_CFG4_PCAL_6													((uint8_t) 0x06)
    #define CH3_CFG4_PCAL_7													((uint8_t) 0x07)
    #define CH3_CFG4_PCAL_8													((uint8_t) 0x08)
    #define CH3_CFG4_PCAL_9													((uint8_t) 0x09)
    #define CH3_CFG4_PCAL_10												((uint8_t) 0x0A)
    #define CH3_CFG4_PCAL_11												((uint8_t) 0x0B)
    #define CH3_CFG4_PCAL_12												((uint8_t) 0x0C)
    #define CH3_CFG4_PCAL_13												((uint8_t) 0x0D)
    #define CH3_CFG4_PCAL_14												((uint8_t) 0x0E)
    #define CH3_CFG4_PCAL_15												((uint8_t) 0x0F)
    #define CH3_CFG4_PCAL_16												((uint8_t) 0x10)
    #define CH3_CFG4_PCAL_17												((uint8_t) 0x11)
    #define CH3_CFG4_PCAL_18												((uint8_t) 0x12)
    #define CH3_CFG4_PCAL_19												((uint8_t) 0x13)
    #define CH3_CFG4_PCAL_20												((uint8_t) 0x14)
    #define CH3_CFG4_PCAL_21												((uint8_t) 0x15)
    #define CH3_CFG4_PCAL_22												((uint8_t) 0x16)
    #define CH3_CFG4_PCAL_23												((uint8_t) 0x17)
    #define CH3_CFG4_PCAL_24												((uint8_t) 0x18)
    #define CH3_CFG4_PCAL_25												((uint8_t) 0x19)
    #define CH3_CFG4_PCAL_26												((uint8_t) 0x1A)
    #define CH3_CFG4_PCAL_27												((uint8_t) 0x1B)
    #define CH3_CFG4_PCAL_28												((uint8_t) 0x1C)
    #define CH3_CFG4_PCAL_29												((uint8_t) 0x1D)
    #define CH3_CFG4_PCAL_30												((uint8_t) 0x1E)
    #define CH3_CFG4_PCAL_31												((uint8_t) 0x1F)
    #define CH3_CFG4_PCAL_32												((uint8_t) 0x20)
    #define CH3_CFG4_PCAL_33												((uint8_t) 0x21)
    #define CH3_CFG4_PCAL_34												((uint8_t) 0x22)
    #define CH3_CFG4_PCAL_35												((uint8_t) 0x23)
    #define CH3_CFG4_PCAL_36												((uint8_t) 0x24)
    #define CH3_CFG4_PCAL_37												((uint8_t) 0x25)
    #define CH3_CFG4_PCAL_38												((uint8_t) 0x26)
    #define CH3_CFG4_PCAL_39												((uint8_t) 0x27)
    #define CH3_CFG4_PCAL_40												((uint8_t) 0x28)
    #define CH3_CFG4_PCAL_41												((uint8_t) 0x29)
    #define CH3_CFG4_PCAL_42												((uint8_t) 0x2A)
    #define CH3_CFG4_PCAL_43												((uint8_t) 0x2B)
    #define CH3_CFG4_PCAL_44												((uint8_t) 0x2C)
    #define CH3_CFG4_PCAL_45												((uint8_t) 0x2D)
    #define CH3_CFG4_PCAL_46												((uint8_t) 0x2E)
    #define CH3_CFG4_PCAL_47												((uint8_t) 0x2F)
    #define CH3_CFG4_PCAL_48												((uint8_t) 0x30)
    #define CH3_CFG4_PCAL_49												((uint8_t) 0x31)
    #define CH3_CFG4_PCAL_50												((uint8_t) 0x32)
    #define CH3_CFG4_PCAL_51												((uint8_t) 0x33)
    #define CH3_CFG4_PCAL_52												((uint8_t) 0x34)
    #define CH3_CFG4_PCAL_53												((uint8_t) 0x35)
    #define CH3_CFG4_PCAL_54												((uint8_t) 0x36)
    #define CH3_CFG4_PCAL_55												((uint8_t) 0x37)
    #define CH3_CFG4_PCAL_56												((uint8_t) 0x38)
    #define CH3_CFG4_PCAL_57												((uint8_t) 0x39)
    #define CH3_CFG4_PCAL_58												((uint8_t) 0x3A)
    #define CH3_CFG4_PCAL_59												((uint8_t) 0x3B)
    #define CH3_CFG4_PCAL_60												((uint8_t) 0x3C)
    #define CH3_CFG4_PCAL_61												((uint8_t) 0x3D)
    #define CH3_CFG4_PCAL_62												((uint8_t) 0x3E)
    #define CH3_CFG4_PCAL_63												((uint8_t) 0x3F)
    #define CH3_CFG4_PCAL_64												((uint8_t) 0x40)
    #define CH3_CFG4_PCAL_65												((uint8_t) 0x41)
    #define CH3_CFG4_PCAL_66												((uint8_t) 0x42)
    #define CH3_CFG4_PCAL_67												((uint8_t) 0x43)
    #define CH3_CFG4_PCAL_68												((uint8_t) 0x44)
    #define CH3_CFG4_PCAL_69												((uint8_t) 0x45)
    #define CH3_CFG4_PCAL_70												((uint8_t) 0x46)
    #define CH3_CFG4_PCAL_71												((uint8_t) 0x47)
    #define CH3_CFG4_PCAL_72												((uint8_t) 0x48)
    #define CH3_CFG4_PCAL_73												((uint8_t) 0x49)
    #define CH3_CFG4_PCAL_74												((uint8_t) 0x4A)
    #define CH3_CFG4_PCAL_75												((uint8_t) 0x4B)
    #define CH3_CFG4_PCAL_76												((uint8_t) 0x4C)
    #define CH3_CFG4_PCAL_77												((uint8_t) 0x4D)
    #define CH3_CFG4_PCAL_78												((uint8_t) 0x4E)
    #define CH3_CFG4_PCAL_79												((uint8_t) 0x4F)
    #define CH3_CFG4_PCAL_80												((uint8_t) 0x50)
    #define CH3_CFG4_PCAL_81												((uint8_t) 0x51)
    #define CH3_CFG4_PCAL_82												((uint8_t) 0x52)
    #define CH3_CFG4_PCAL_83												((uint8_t) 0x53)
    #define CH3_CFG4_PCAL_84												((uint8_t) 0x54)
    #define CH3_CFG4_PCAL_85												((uint8_t) 0x55)
    #define CH3_CFG4_PCAL_86												((uint8_t) 0x56)
    #define CH3_CFG4_PCAL_87												((uint8_t) 0x57)
    #define CH3_CFG4_PCAL_88												((uint8_t) 0x58)
    #define CH3_CFG4_PCAL_89												((uint8_t) 0x59)
    #define CH3_CFG4_PCAL_90												((uint8_t) 0x5A)
    #define CH3_CFG4_PCAL_91												((uint8_t) 0x5B)
    #define CH3_CFG4_PCAL_92												((uint8_t) 0x5C)
    #define CH3_CFG4_PCAL_93												((uint8_t) 0x5D)
    #define CH3_CFG4_PCAL_94												((uint8_t) 0x5E)
    #define CH3_CFG4_PCAL_95												((uint8_t) 0x5F)
    #define CH3_CFG4_PCAL_96												((uint8_t) 0x60)
    #define CH3_CFG4_PCAL_97												((uint8_t) 0x61)
    #define CH3_CFG4_PCAL_98												((uint8_t) 0x62)
    #define CH3_CFG4_PCAL_99												((uint8_t) 0x63)
    #define CH3_CFG4_PCAL_100												((uint8_t) 0x64)
    #define CH3_CFG4_PCAL_101												((uint8_t) 0x65)
    #define CH3_CFG4_PCAL_102												((uint8_t) 0x66)
    #define CH3_CFG4_PCAL_103												((uint8_t) 0x67)
    #define CH3_CFG4_PCAL_104												((uint8_t) 0x68)
    #define CH3_CFG4_PCAL_105												((uint8_t) 0x69)
    #define CH3_CFG4_PCAL_106												((uint8_t) 0x6A)
    #define CH3_CFG4_PCAL_107												((uint8_t) 0x6B)
    #define CH3_CFG4_PCAL_108												((uint8_t) 0x6C)
    #define CH3_CFG4_PCAL_109												((uint8_t) 0x6D)
    #define CH3_CFG4_PCAL_110												((uint8_t) 0x6E)
    #define CH3_CFG4_PCAL_111												((uint8_t) 0x6F)
    #define CH3_CFG4_PCAL_112												((uint8_t) 0x70)
    #define CH3_CFG4_PCAL_113												((uint8_t) 0x71)
    #define CH3_CFG4_PCAL_114												((uint8_t) 0x72)
    #define CH3_CFG4_PCAL_115												((uint8_t) 0x73)
    #define CH3_CFG4_PCAL_116												((uint8_t) 0x74)
    #define CH3_CFG4_PCAL_117												((uint8_t) 0x75)
    #define CH3_CFG4_PCAL_118												((uint8_t) 0x76)
    #define CH3_CFG4_PCAL_119												((uint8_t) 0x77)
    #define CH3_CFG4_PCAL_120												((uint8_t) 0x78)
    #define CH3_CFG4_PCAL_121												((uint8_t) 0x79)
    #define CH3_CFG4_PCAL_122												((uint8_t) 0x7A)
    #define CH3_CFG4_PCAL_123												((uint8_t) 0x7B)
    #define CH3_CFG4_PCAL_124												((uint8_t) 0x7C)
    #define CH3_CFG4_PCAL_125												((uint8_t) 0x7D)
    #define CH3_CFG4_PCAL_126												((uint8_t) 0x7E)
    #define CH3_CFG4_PCAL_127												((uint8_t) 0x7F)
    #define CH3_CFG4_PCAL_128												((uint8_t) 0x80)
    #define CH3_CFG4_PCAL_129												((uint8_t) 0x81)
    #define CH3_CFG4_PCAL_130												((uint8_t) 0x82)
    #define CH3_CFG4_PCAL_131												((uint8_t) 0x83)
    #define CH3_CFG4_PCAL_132												((uint8_t) 0x84)
    #define CH3_CFG4_PCAL_133												((uint8_t) 0x85)
    #define CH3_CFG4_PCAL_134												((uint8_t) 0x86)
    #define CH3_CFG4_PCAL_135												((uint8_t) 0x87)
    #define CH3_CFG4_PCAL_136												((uint8_t) 0x88)
    #define CH3_CFG4_PCAL_137												((uint8_t) 0x89)
    #define CH3_CFG4_PCAL_138												((uint8_t) 0x8A)
    #define CH3_CFG4_PCAL_139												((uint8_t) 0x8B)
    #define CH3_CFG4_PCAL_140												((uint8_t) 0x8C)
    #define CH3_CFG4_PCAL_141												((uint8_t) 0x8D)
    #define CH3_CFG4_PCAL_142												((uint8_t) 0x8E)
    #define CH3_CFG4_PCAL_143												((uint8_t) 0x8F)
    #define CH3_CFG4_PCAL_144												((uint8_t) 0x90)
    #define CH3_CFG4_PCAL_145												((uint8_t) 0x91)
    #define CH3_CFG4_PCAL_146												((uint8_t) 0x92)
    #define CH3_CFG4_PCAL_147												((uint8_t) 0x93)
    #define CH3_CFG4_PCAL_148												((uint8_t) 0x94)
    #define CH3_CFG4_PCAL_149												((uint8_t) 0x95)
    #define CH3_CFG4_PCAL_150												((uint8_t) 0x96)
    #define CH3_CFG4_PCAL_151												((uint8_t) 0x97)
    #define CH3_CFG4_PCAL_152												((uint8_t) 0x98)
    #define CH3_CFG4_PCAL_153												((uint8_t) 0x99)
    #define CH3_CFG4_PCAL_154												((uint8_t) 0x9A)
    #define CH3_CFG4_PCAL_155												((uint8_t) 0x9B)
    #define CH3_CFG4_PCAL_156												((uint8_t) 0x9C)
    #define CH3_CFG4_PCAL_157												((uint8_t) 0x9D)
    #define CH3_CFG4_PCAL_158												((uint8_t) 0x9E)
    #define CH3_CFG4_PCAL_159												((uint8_t) 0x9F)
    #define CH3_CFG4_PCAL_160												((uint8_t) 0xA0)
    #define CH3_CFG4_PCAL_161												((uint8_t) 0xA1)
    #define CH3_CFG4_PCAL_162												((uint8_t) 0xA2)
    #define CH3_CFG4_PCAL_163												((uint8_t) 0xA3)
    #define CH3_CFG4_PCAL_164												((uint8_t) 0xA4)
    #define CH3_CFG4_PCAL_165												((uint8_t) 0xA5)
    #define CH3_CFG4_PCAL_166												((uint8_t) 0xA6)
    #define CH3_CFG4_PCAL_167												((uint8_t) 0xA7)
    #define CH3_CFG4_PCAL_168												((uint8_t) 0xA8)
    #define CH3_CFG4_PCAL_169												((uint8_t) 0xA9)
    #define CH3_CFG4_PCAL_170												((uint8_t) 0xAA)
    #define CH3_CFG4_PCAL_171												((uint8_t) 0xAB)
    #define CH3_CFG4_PCAL_172												((uint8_t) 0xAC)
    #define CH3_CFG4_PCAL_173												((uint8_t) 0xAD)
    #define CH3_CFG4_PCAL_174												((uint8_t) 0xAE)
    #define CH3_CFG4_PCAL_175												((uint8_t) 0xAF)
    #define CH3_CFG4_PCAL_176												((uint8_t) 0xB0)
    #define CH3_CFG4_PCAL_177												((uint8_t) 0xB1)
    #define CH3_CFG4_PCAL_178												((uint8_t) 0xB2)
    #define CH3_CFG4_PCAL_179												((uint8_t) 0xB3)
    #define CH3_CFG4_PCAL_180												((uint8_t) 0xB4)
    #define CH3_CFG4_PCAL_181												((uint8_t) 0xB5)
    #define CH3_CFG4_PCAL_182												((uint8_t) 0xB6)
    #define CH3_CFG4_PCAL_183												((uint8_t) 0xB7)
    #define CH3_CFG4_PCAL_184												((uint8_t) 0xB8)
    #define CH3_CFG4_PCAL_185												((uint8_t) 0xB9)
    #define CH3_CFG4_PCAL_186												((uint8_t) 0xBA)
    #define CH3_CFG4_PCAL_187												((uint8_t) 0xBB)
    #define CH3_CFG4_PCAL_188												((uint8_t) 0xBC)
    #define CH3_CFG4_PCAL_189												((uint8_t) 0xBD)
    #define CH3_CFG4_PCAL_190												((uint8_t) 0xBE)
    #define CH3_CFG4_PCAL_191												((uint8_t) 0xBF)
    #define CH3_CFG4_PCAL_192												((uint8_t) 0xC0)
    #define CH3_CFG4_PCAL_193												((uint8_t) 0xC1)
    #define CH3_CFG4_PCAL_194												((uint8_t) 0xC2)
    #define CH3_CFG4_PCAL_195												((uint8_t) 0xC3)
    #define CH3_CFG4_PCAL_196												((uint8_t) 0xC4)
    #define CH3_CFG4_PCAL_197												((uint8_t) 0xC5)
    #define CH3_CFG4_PCAL_198												((uint8_t) 0xC6)
    #define CH3_CFG4_PCAL_199												((uint8_t) 0xC7)
    #define CH3_CFG4_PCAL_200												((uint8_t) 0xC8)
    #define CH3_CFG4_PCAL_201												((uint8_t) 0xC9)
    #define CH3_CFG4_PCAL_202												((uint8_t) 0xCA)
    #define CH3_CFG4_PCAL_203												((uint8_t) 0xCB)
    #define CH3_CFG4_PCAL_204												((uint8_t) 0xCC)
    #define CH3_CFG4_PCAL_205												((uint8_t) 0xCD)
    #define CH3_CFG4_PCAL_206												((uint8_t) 0xCE)
    #define CH3_CFG4_PCAL_207												((uint8_t) 0xCF)
    #define CH3_CFG4_PCAL_208												((uint8_t) 0xD0)
    #define CH3_CFG4_PCAL_209												((uint8_t) 0xD1)
    #define CH3_CFG4_PCAL_210												((uint8_t) 0xD2)
    #define CH3_CFG4_PCAL_211												((uint8_t) 0xD3)
    #define CH3_CFG4_PCAL_212												((uint8_t) 0xD4)
    #define CH3_CFG4_PCAL_213												((uint8_t) 0xD5)
    #define CH3_CFG4_PCAL_214												((uint8_t) 0xD6)
    #define CH3_CFG4_PCAL_215												((uint8_t) 0xD7)
    #define CH3_CFG4_PCAL_216												((uint8_t) 0xD8)
    #define CH3_CFG4_PCAL_217												((uint8_t) 0xD9)
    #define CH3_CFG4_PCAL_218												((uint8_t) 0xDA)
    #define CH3_CFG4_PCAL_219												((uint8_t) 0xDB)
    #define CH3_CFG4_PCAL_220												((uint8_t) 0xDC)
    #define CH3_CFG4_PCAL_221												((uint8_t) 0xDD)
    #define CH3_CFG4_PCAL_222												((uint8_t) 0xDE)
    #define CH3_CFG4_PCAL_223												((uint8_t) 0xDF)
    #define CH3_CFG4_PCAL_224												((uint8_t) 0xE0)
    #define CH3_CFG4_PCAL_225												((uint8_t) 0xE1)
    #define CH3_CFG4_PCAL_226												((uint8_t) 0xE2)
    #define CH3_CFG4_PCAL_227												((uint8_t) 0xE3)
    #define CH3_CFG4_PCAL_228												((uint8_t) 0xE4)
    #define CH3_CFG4_PCAL_229												((uint8_t) 0xE5)
    #define CH3_CFG4_PCAL_230												((uint8_t) 0xE6)
    #define CH3_CFG4_PCAL_231												((uint8_t) 0xE7)
    #define CH3_CFG4_PCAL_232												((uint8_t) 0xE8)
    #define CH3_CFG4_PCAL_233												((uint8_t) 0xE9)
    #define CH3_CFG4_PCAL_234												((uint8_t) 0xEA)
    #define CH3_CFG4_PCAL_235												((uint8_t) 0xEB)
    #define CH3_CFG4_PCAL_236												((uint8_t) 0xEC)
    #define CH3_CFG4_PCAL_237												((uint8_t) 0xED)
    #define CH3_CFG4_PCAL_238												((uint8_t) 0xEE)
    #define CH3_CFG4_PCAL_239												((uint8_t) 0xEF)
    #define CH3_CFG4_PCAL_240												((uint8_t) 0xF0)
    #define CH3_CFG4_PCAL_241												((uint8_t) 0xF1)
    #define CH3_CFG4_PCAL_242												((uint8_t) 0xF2)
    #define CH3_CFG4_PCAL_243												((uint8_t) 0xF3)
    #define CH3_CFG4_PCAL_244												((uint8_t) 0xF4)
    #define CH3_CFG4_PCAL_245												((uint8_t) 0xF5)
    #define CH3_CFG4_PCAL_246												((uint8_t) 0xF6)
    #define CH3_CFG4_PCAL_247												((uint8_t) 0xF7)
    #define CH3_CFG4_PCAL_248												((uint8_t) 0xF8)
    #define CH3_CFG4_PCAL_249												((uint8_t) 0xF9)
    #define CH3_CFG4_PCAL_250												((uint8_t) 0xFA)
    #define CH3_CFG4_PCAL_251												((uint8_t) 0xFB)
    #define CH3_CFG4_PCAL_252												((uint8_t) 0xFC)
    #define CH3_CFG4_PCAL_253												((uint8_t) 0xFD)
    #define CH3_CFG4_PCAL_254												((uint8_t) 0xFE)
    #define CH3_CFG4_PCAL_255												((uint8_t) 0xFF)



/* Register 0x4B (CH4_CFG0) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        INTYP        |                 INSRC[1:0]                |          DC         |                  IMP[1:0]                 |       RESERVED      |        DREEN        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH4_CFG0 register */
    #define CH4_CFG0_ADDRESS												((uint8_t) 0x4B)
    #define CH4_CFG0_DEFAULT												((uint8_t) 0x00)

    /* INTYP field */
    #define CH4_CFG0_INTYP_MASK												((uint8_t) 0x80)
    #define CH4_CFG0_INTYP_MIC												((uint8_t) 0x00)    // DEFAULT
    #define CH4_CFG0_INTYP_LINE												((uint8_t) 0x80)

    /* INSRC field */
    #define CH4_CFG0_INSRC_MASK												((uint8_t) 0x60)
    #define CH4_CFG0_INSRC_DIFF												((uint8_t) 0x00)    // DEFAULT
    #define CH4_CFG0_INSRC_SINGLE											((uint8_t) 0x20)
    #define CH4_CFG0_INSRC_PDM												((uint8_t) 0x40)

    /* DC field */
    #define CH4_CFG0_DC_MASK												((uint8_t) 0x10)
    #define CH4_CFG0_DC_AC													((uint8_t) 0x00)    // DEFAULT
    #define CH4_CFG0_DC_DC													((uint8_t) 0x10)

    /* IMP field */
    #define CH4_CFG0_IMP_MASK												((uint8_t) 0x0C)
    #define CH4_CFG0_IMP_2P5k												((uint8_t) 0x00)    // DEFAULT
    #define CH4_CFG0_IMP_10k												((uint8_t) 0x04)
    #define CH4_CFG0_IMP_20k												((uint8_t) 0x08)

    /* DREEN field */
    #define CH4_CFG0_DREEN_MASK												((uint8_t) 0x01)
    #define CH4_CFG0_DREEN_DISABLED											((uint8_t) 0x00)    // DEFAULT
    #define CH4_CFG0_DREEN_ENABLED											((uint8_t) 0x01)



/* Register 0x4C (CH4_CFG1) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                             GAIN[5:0]                                                             |               RESERVED[1:0]               |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH4_CFG1 register */
    #define CH4_CFG1_ADDRESS												((uint8_t) 0x4C)
    #define CH4_CFG1_DEFAULT												((uint8_t) 0x00)

    /* GAIN field */
    #define CH4_CFG1_GAIN_MASK												((uint8_t) 0xFC)
    #define CH4_CFG1_GAIN_0dB												((uint8_t) 0x00)    // DEFAULT
    #define CH4_CFG1_GAIN_1dB												((uint8_t) 0x04)
    #define CH4_CFG1_GAIN_2dB												((uint8_t) 0x08)
    #define CH4_CFG1_GAIN_3dB												((uint8_t) 0x0C)
    #define CH4_CFG1_GAIN_4dB												((uint8_t) 0x10)
    #define CH4_CFG1_GAIN_5dB												((uint8_t) 0x14)
    #define CH4_CFG1_GAIN_6dB												((uint8_t) 0x18)
    #define CH4_CFG1_GAIN_7dB												((uint8_t) 0x1C)
    #define CH4_CFG1_GAIN_8dB												((uint8_t) 0x20)
    #define CH4_CFG1_GAIN_9dB												((uint8_t) 0x24)
    #define CH4_CFG1_GAIN_10dB												((uint8_t) 0x28)
    #define CH4_CFG1_GAIN_11dB												((uint8_t) 0x2C)
    #define CH4_CFG1_GAIN_12dB												((uint8_t) 0x30)
    #define CH4_CFG1_GAIN_13dB												((uint8_t) 0x34)
    #define CH4_CFG1_GAIN_14dB												((uint8_t) 0x38)
    #define CH4_CFG1_GAIN_15dB												((uint8_t) 0x3C)
    #define CH4_CFG1_GAIN_16dB												((uint8_t) 0x40)
    #define CH4_CFG1_GAIN_17dB												((uint8_t) 0x44)
    #define CH4_CFG1_GAIN_18dB												((uint8_t) 0x48)
    #define CH4_CFG1_GAIN_19dB												((uint8_t) 0x4C)
    #define CH4_CFG1_GAIN_20dB												((uint8_t) 0x50)
    #define CH4_CFG1_GAIN_21dB												((uint8_t) 0x54)
    #define CH4_CFG1_GAIN_22dB												((uint8_t) 0x58)
    #define CH4_CFG1_GAIN_23dB												((uint8_t) 0x5C)
    #define CH4_CFG1_GAIN_24dB												((uint8_t) 0x60)
    #define CH4_CFG1_GAIN_25dB												((uint8_t) 0x64)
    #define CH4_CFG1_GAIN_26dB												((uint8_t) 0x68)
    #define CH4_CFG1_GAIN_27dB												((uint8_t) 0x6C)
    #define CH4_CFG1_GAIN_28dB												((uint8_t) 0x70)
    #define CH4_CFG1_GAIN_29dB												((uint8_t) 0x74)
    #define CH4_CFG1_GAIN_30dB												((uint8_t) 0x78)
    #define CH4_CFG1_GAIN_31dB												((uint8_t) 0x7C)
    #define CH4_CFG1_GAIN_32dB												((uint8_t) 0x80)
    #define CH4_CFG1_GAIN_33dB												((uint8_t) 0x84)
    #define CH4_CFG1_GAIN_34dB												((uint8_t) 0x88)
    #define CH4_CFG1_GAIN_35dB												((uint8_t) 0x8C)
    #define CH4_CFG1_GAIN_36dB												((uint8_t) 0x90)
    #define CH4_CFG1_GAIN_37dB												((uint8_t) 0x94)
    #define CH4_CFG1_GAIN_38dB												((uint8_t) 0x98)
    #define CH4_CFG1_GAIN_39dB												((uint8_t) 0x9C)
    #define CH4_CFG1_GAIN_40dB												((uint8_t) 0xA0)
    #define CH4_CFG1_GAIN_41dB												((uint8_t) 0xA4)
    #define CH4_CFG1_GAIN_42dB												((uint8_t) 0xA8)



/* Register 0x4D (CH4_CFG2) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                                                   DVOL[7:0]                                                                                   |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH4_CFG2 register */
    #define CH4_CFG2_ADDRESS												((uint8_t) 0x4D)
    #define CH4_CFG2_DEFAULT												((uint8_t) 0xC9)

    /* DVOL field */
    #define CH4_CFG2_DVOL_MASK												((uint8_t) 0xFF)
    #define CH4_CFG2_DVOL_MUTE												((uint8_t) 0x00)
    #define CH4_CFG2_DVOL_M100dB											((uint8_t) 0x01)
    #define CH4_CFG2_DVOL_M99P5dB											((uint8_t) 0x02)
    #define CH4_CFG2_DVOL_M99dB												((uint8_t) 0x03)
    #define CH4_CFG2_DVOL_M98P5dB											((uint8_t) 0x04)
    #define CH4_CFG2_DVOL_M98dB												((uint8_t) 0x05)
    #define CH4_CFG2_DVOL_M97P5dB											((uint8_t) 0x06)
    #define CH4_CFG2_DVOL_M97dB												((uint8_t) 0x07)
    #define CH4_CFG2_DVOL_M96P5dB											((uint8_t) 0x08)
    #define CH4_CFG2_DVOL_M96dB												((uint8_t) 0x09)
    #define CH4_CFG2_DVOL_M95P5dB											((uint8_t) 0x0A)
    #define CH4_CFG2_DVOL_M95dB												((uint8_t) 0x0B)
    #define CH4_CFG2_DVOL_M94P5dB											((uint8_t) 0x0C)
    #define CH4_CFG2_DVOL_M94dB												((uint8_t) 0x0D)
    #define CH4_CFG2_DVOL_M93P5dB											((uint8_t) 0x0E)
    #define CH4_CFG2_DVOL_M93dB												((uint8_t) 0x0F)
    #define CH4_CFG2_DVOL_M92P5dB											((uint8_t) 0x10)
    #define CH4_CFG2_DVOL_M92dB												((uint8_t) 0x11)
    #define CH4_CFG2_DVOL_M91P5dB											((uint8_t) 0x12)
    #define CH4_CFG2_DVOL_M91dB												((uint8_t) 0x13)
    #define CH4_CFG2_DVOL_M90P5dB											((uint8_t) 0x14)
    #define CH4_CFG2_DVOL_M90dB												((uint8_t) 0x15)
    #define CH4_CFG2_DVOL_M89P5dB											((uint8_t) 0x16)
    #define CH4_CFG2_DVOL_M89dB												((uint8_t) 0x17)
    #define CH4_CFG2_DVOL_M88P5dB											((uint8_t) 0x18)
    #define CH4_CFG2_DVOL_M88dB												((uint8_t) 0x19)
    #define CH4_CFG2_DVOL_M87P5dB											((uint8_t) 0x1A)
    #define CH4_CFG2_DVOL_M87dB												((uint8_t) 0x1B)
    #define CH4_CFG2_DVOL_M86P5dB											((uint8_t) 0x1C)
    #define CH4_CFG2_DVOL_M86dB												((uint8_t) 0x1D)
    #define CH4_CFG2_DVOL_M85P5dB											((uint8_t) 0x1E)
    #define CH4_CFG2_DVOL_M85dB												((uint8_t) 0x1F)
    #define CH4_CFG2_DVOL_M84P5dB											((uint8_t) 0x20)
    #define CH4_CFG2_DVOL_M84dB												((uint8_t) 0x21)
    #define CH4_CFG2_DVOL_M83P5dB											((uint8_t) 0x22)
    #define CH4_CFG2_DVOL_M83dB												((uint8_t) 0x23)
    #define CH4_CFG2_DVOL_M82P5dB											((uint8_t) 0x24)
    #define CH4_CFG2_DVOL_M82dB												((uint8_t) 0x25)
    #define CH4_CFG2_DVOL_M81P5dB											((uint8_t) 0x26)
    #define CH4_CFG2_DVOL_M81dB												((uint8_t) 0x27)
    #define CH4_CFG2_DVOL_M80P5dB											((uint8_t) 0x28)
    #define CH4_CFG2_DVOL_M80dB												((uint8_t) 0x29)
    #define CH4_CFG2_DVOL_M79P5dB											((uint8_t) 0x2A)
    #define CH4_CFG2_DVOL_M79dB												((uint8_t) 0x2B)
    #define CH4_CFG2_DVOL_M78P5dB											((uint8_t) 0x2C)
    #define CH4_CFG2_DVOL_M78dB												((uint8_t) 0x2D)
    #define CH4_CFG2_DVOL_M77P5dB											((uint8_t) 0x2E)
    #define CH4_CFG2_DVOL_M77dB												((uint8_t) 0x2F)
    #define CH4_CFG2_DVOL_M76P5dB											((uint8_t) 0x30)
    #define CH4_CFG2_DVOL_M76dB												((uint8_t) 0x31)
    #define CH4_CFG2_DVOL_M75P5dB											((uint8_t) 0x32)
    #define CH4_CFG2_DVOL_M75dB												((uint8_t) 0x33)
    #define CH4_CFG2_DVOL_M74P5dB											((uint8_t) 0x34)
    #define CH4_CFG2_DVOL_M74dB												((uint8_t) 0x35)
    #define CH4_CFG2_DVOL_M73P5dB											((uint8_t) 0x36)
    #define CH4_CFG2_DVOL_M73dB												((uint8_t) 0x37)
    #define CH4_CFG2_DVOL_M72P5dB											((uint8_t) 0x38)
    #define CH4_CFG2_DVOL_M72dB												((uint8_t) 0x39)
    #define CH4_CFG2_DVOL_M71P5dB											((uint8_t) 0x3A)
    #define CH4_CFG2_DVOL_M71dB												((uint8_t) 0x3B)
    #define CH4_CFG2_DVOL_M70P5dB											((uint8_t) 0x3C)
    #define CH4_CFG2_DVOL_M70dB												((uint8_t) 0x3D)
    #define CH4_CFG2_DVOL_M69P5dB											((uint8_t) 0x3E)
    #define CH4_CFG2_DVOL_M69dB												((uint8_t) 0x3F)
    #define CH4_CFG2_DVOL_M68P5dB											((uint8_t) 0x40)
    #define CH4_CFG2_DVOL_M68dB												((uint8_t) 0x41)
    #define CH4_CFG2_DVOL_M67P5dB											((uint8_t) 0x42)
    #define CH4_CFG2_DVOL_M67dB												((uint8_t) 0x43)
    #define CH4_CFG2_DVOL_M66P5dB											((uint8_t) 0x44)
    #define CH4_CFG2_DVOL_M66dB												((uint8_t) 0x45)
    #define CH4_CFG2_DVOL_M65P5dB											((uint8_t) 0x46)
    #define CH4_CFG2_DVOL_M65dB												((uint8_t) 0x47)
    #define CH4_CFG2_DVOL_M64P5dB											((uint8_t) 0x48)
    #define CH4_CFG2_DVOL_M64dB												((uint8_t) 0x49)
    #define CH4_CFG2_DVOL_M63P5dB											((uint8_t) 0x4A)
    #define CH4_CFG2_DVOL_M63dB												((uint8_t) 0x4B)
    #define CH4_CFG2_DVOL_M62P5dB											((uint8_t) 0x4C)
    #define CH4_CFG2_DVOL_M62dB												((uint8_t) 0x4D)
    #define CH4_CFG2_DVOL_M61P5dB											((uint8_t) 0x4E)
    #define CH4_CFG2_DVOL_M61dB												((uint8_t) 0x4F)
    #define CH4_CFG2_DVOL_M60P5dB											((uint8_t) 0x50)
    #define CH4_CFG2_DVOL_M60dB												((uint8_t) 0x51)
    #define CH4_CFG2_DVOL_M59P5dB											((uint8_t) 0x52)
    #define CH4_CFG2_DVOL_M59dB												((uint8_t) 0x53)
    #define CH4_CFG2_DVOL_M58P5dB											((uint8_t) 0x54)
    #define CH4_CFG2_DVOL_M58dB												((uint8_t) 0x55)
    #define CH4_CFG2_DVOL_M57P5dB											((uint8_t) 0x56)
    #define CH4_CFG2_DVOL_M57dB												((uint8_t) 0x57)
    #define CH4_CFG2_DVOL_M56P5dB											((uint8_t) 0x58)
    #define CH4_CFG2_DVOL_M56dB												((uint8_t) 0x59)
    #define CH4_CFG2_DVOL_M55P5dB											((uint8_t) 0x5A)
    #define CH4_CFG2_DVOL_M55dB												((uint8_t) 0x5B)
    #define CH4_CFG2_DVOL_M54P5dB											((uint8_t) 0x5C)
    #define CH4_CFG2_DVOL_M54dB												((uint8_t) 0x5D)
    #define CH4_CFG2_DVOL_M53P5dB											((uint8_t) 0x5E)
    #define CH4_CFG2_DVOL_M53dB												((uint8_t) 0x5F)
    #define CH4_CFG2_DVOL_M52P5dB											((uint8_t) 0x60)
    #define CH4_CFG2_DVOL_M52dB												((uint8_t) 0x61)
    #define CH4_CFG2_DVOL_M51P5dB											((uint8_t) 0x62)
    #define CH4_CFG2_DVOL_M51dB												((uint8_t) 0x63)
    #define CH4_CFG2_DVOL_M50P5dB											((uint8_t) 0x64)
    #define CH4_CFG2_DVOL_M50dB												((uint8_t) 0x65)
    #define CH4_CFG2_DVOL_M49P5dB											((uint8_t) 0x66)
    #define CH4_CFG2_DVOL_M49dB												((uint8_t) 0x67)
    #define CH4_CFG2_DVOL_M48P5dB											((uint8_t) 0x68)
    #define CH4_CFG2_DVOL_M48dB												((uint8_t) 0x69)
    #define CH4_CFG2_DVOL_M47P5dB											((uint8_t) 0x6A)
    #define CH4_CFG2_DVOL_M47dB												((uint8_t) 0x6B)
    #define CH4_CFG2_DVOL_M46P5dB											((uint8_t) 0x6C)
    #define CH4_CFG2_DVOL_M46dB												((uint8_t) 0x6D)
    #define CH4_CFG2_DVOL_M45P5dB											((uint8_t) 0x6E)
    #define CH4_CFG2_DVOL_M45dB												((uint8_t) 0x6F)
    #define CH4_CFG2_DVOL_M44P5dB											((uint8_t) 0x70)
    #define CH4_CFG2_DVOL_M44dB												((uint8_t) 0x71)
    #define CH4_CFG2_DVOL_M43P5dB											((uint8_t) 0x72)
    #define CH4_CFG2_DVOL_M43dB												((uint8_t) 0x73)
    #define CH4_CFG2_DVOL_M42P5dB											((uint8_t) 0x74)
    #define CH4_CFG2_DVOL_M42dB												((uint8_t) 0x75)
    #define CH4_CFG2_DVOL_M41P5dB											((uint8_t) 0x76)
    #define CH4_CFG2_DVOL_M41dB												((uint8_t) 0x77)
    #define CH4_CFG2_DVOL_M40P5dB											((uint8_t) 0x78)
    #define CH4_CFG2_DVOL_M40dB												((uint8_t) 0x79)
    #define CH4_CFG2_DVOL_M39P5dB											((uint8_t) 0x7A)
    #define CH4_CFG2_DVOL_M39dB												((uint8_t) 0x7B)
    #define CH4_CFG2_DVOL_M38P5dB											((uint8_t) 0x7C)
    #define CH4_CFG2_DVOL_M38dB												((uint8_t) 0x7D)
    #define CH4_CFG2_DVOL_M37P5dB											((uint8_t) 0x7E)
    #define CH4_CFG2_DVOL_M37dB												((uint8_t) 0x7F)
    #define CH4_CFG2_DVOL_M36P5dB											((uint8_t) 0x80)
    #define CH4_CFG2_DVOL_M36dB												((uint8_t) 0x81)
    #define CH4_CFG2_DVOL_M35P5dB											((uint8_t) 0x82)
    #define CH4_CFG2_DVOL_M35dB												((uint8_t) 0x83)
    #define CH4_CFG2_DVOL_M34P5dB											((uint8_t) 0x84)
    #define CH4_CFG2_DVOL_M34dB												((uint8_t) 0x85)
    #define CH4_CFG2_DVOL_M33P5dB											((uint8_t) 0x86)
    #define CH4_CFG2_DVOL_M33dB												((uint8_t) 0x87)
    #define CH4_CFG2_DVOL_M32P5dB											((uint8_t) 0x88)
    #define CH4_CFG2_DVOL_M32dB												((uint8_t) 0x89)
    #define CH4_CFG2_DVOL_M31P5dB											((uint8_t) 0x8A)
    #define CH4_CFG2_DVOL_M31dB												((uint8_t) 0x8B)
    #define CH4_CFG2_DVOL_M30P5dB											((uint8_t) 0x8C)
    #define CH4_CFG2_DVOL_M30dB												((uint8_t) 0x8D)
    #define CH4_CFG2_DVOL_M29P5dB											((uint8_t) 0x8E)
    #define CH4_CFG2_DVOL_M29dB												((uint8_t) 0x8F)
    #define CH4_CFG2_DVOL_M28P5dB											((uint8_t) 0x90)
    #define CH4_CFG2_DVOL_M28dB												((uint8_t) 0x91)
    #define CH4_CFG2_DVOL_M27P5dB											((uint8_t) 0x92)
    #define CH4_CFG2_DVOL_M27dB												((uint8_t) 0x93)
    #define CH4_CFG2_DVOL_M26P5dB											((uint8_t) 0x94)
    #define CH4_CFG2_DVOL_M26dB												((uint8_t) 0x95)
    #define CH4_CFG2_DVOL_M25P5dB											((uint8_t) 0x96)
    #define CH4_CFG2_DVOL_M25dB												((uint8_t) 0x97)
    #define CH4_CFG2_DVOL_M24P5dB											((uint8_t) 0x98)
    #define CH4_CFG2_DVOL_M24dB												((uint8_t) 0x99)
    #define CH4_CFG2_DVOL_M23P5dB											((uint8_t) 0x9A)
    #define CH4_CFG2_DVOL_M23dB												((uint8_t) 0x9B)
    #define CH4_CFG2_DVOL_M22P5dB											((uint8_t) 0x9C)
    #define CH4_CFG2_DVOL_M22dB												((uint8_t) 0x9D)
    #define CH4_CFG2_DVOL_M21P5dB											((uint8_t) 0x9E)
    #define CH4_CFG2_DVOL_M21dB												((uint8_t) 0x9F)
    #define CH4_CFG2_DVOL_M20P5dB											((uint8_t) 0xA0)
    #define CH4_CFG2_DVOL_M20dB												((uint8_t) 0xA1)
    #define CH4_CFG2_DVOL_M19P5dB											((uint8_t) 0xA2)
    #define CH4_CFG2_DVOL_M19dB												((uint8_t) 0xA3)
    #define CH4_CFG2_DVOL_M18P5dB											((uint8_t) 0xA4)
    #define CH4_CFG2_DVOL_M18dB												((uint8_t) 0xA5)
    #define CH4_CFG2_DVOL_M17P5dB											((uint8_t) 0xA6)
    #define CH4_CFG2_DVOL_M17dB												((uint8_t) 0xA7)
    #define CH4_CFG2_DVOL_M16P5dB											((uint8_t) 0xA8)
    #define CH4_CFG2_DVOL_M16dB												((uint8_t) 0xA9)
    #define CH4_CFG2_DVOL_M15P5dB											((uint8_t) 0xAA)
    #define CH4_CFG2_DVOL_M15dB												((uint8_t) 0xAB)
    #define CH4_CFG2_DVOL_M14P5dB											((uint8_t) 0xAC)
    #define CH4_CFG2_DVOL_M14dB												((uint8_t) 0xAD)
    #define CH4_CFG2_DVOL_M13P5dB											((uint8_t) 0xAE)
    #define CH4_CFG2_DVOL_M13dB												((uint8_t) 0xAF)
    #define CH4_CFG2_DVOL_M12P5dB											((uint8_t) 0xB0)
    #define CH4_CFG2_DVOL_M12dB												((uint8_t) 0xB1)
    #define CH4_CFG2_DVOL_M11P5dB											((uint8_t) 0xB2)
    #define CH4_CFG2_DVOL_M11dB												((uint8_t) 0xB3)
    #define CH4_CFG2_DVOL_M10P5dB											((uint8_t) 0xB4)
    #define CH4_CFG2_DVOL_M10dB												((uint8_t) 0xB5)
    #define CH4_CFG2_DVOL_M9P5dB											((uint8_t) 0xB6)
    #define CH4_CFG2_DVOL_M9dB												((uint8_t) 0xB7)
    #define CH4_CFG2_DVOL_M8P5dB											((uint8_t) 0xB8)
    #define CH4_CFG2_DVOL_M8dB												((uint8_t) 0xB9)
    #define CH4_CFG2_DVOL_M7P5dB											((uint8_t) 0xBA)
    #define CH4_CFG2_DVOL_M7dB												((uint8_t) 0xBB)
    #define CH4_CFG2_DVOL_M6P5dB											((uint8_t) 0xBC)
    #define CH4_CFG2_DVOL_M6dB												((uint8_t) 0xBD)
    #define CH4_CFG2_DVOL_M5P5dB											((uint8_t) 0xBE)
    #define CH4_CFG2_DVOL_M5dB												((uint8_t) 0xBF)
    #define CH4_CFG2_DVOL_M4P5dB											((uint8_t) 0xC0)
    #define CH4_CFG2_DVOL_M4dB												((uint8_t) 0xC1)
    #define CH4_CFG2_DVOL_M3P5dB											((uint8_t) 0xC2)
    #define CH4_CFG2_DVOL_M3dB												((uint8_t) 0xC3)
    #define CH4_CFG2_DVOL_M2P5dB											((uint8_t) 0xC4)
    #define CH4_CFG2_DVOL_M2dB												((uint8_t) 0xC5)
    #define CH4_CFG2_DVOL_M1P5dB											((uint8_t) 0xC6)
    #define CH4_CFG2_DVOL_M1dB												((uint8_t) 0xC7)
    #define CH4_CFG2_DVOL_M0P5dB											((uint8_t) 0xC8)
    #define CH4_CFG2_DVOL_0dB												((uint8_t) 0xC9)    // DEFAULT
    #define CH4_CFG2_DVOL_0P5dB												((uint8_t) 0xCA)
    #define CH4_CFG2_DVOL_1dB												((uint8_t) 0xCB)
    #define CH4_CFG2_DVOL_1P5dB												((uint8_t) 0xCC)
    #define CH4_CFG2_DVOL_2dB												((uint8_t) 0xCD)
    #define CH4_CFG2_DVOL_2P5dB												((uint8_t) 0xCE)
    #define CH4_CFG2_DVOL_3dB												((uint8_t) 0xCF)
    #define CH4_CFG2_DVOL_3P5dB												((uint8_t) 0xD0)
    #define CH4_CFG2_DVOL_4dB												((uint8_t) 0xD1)
    #define CH4_CFG2_DVOL_4P5dB												((uint8_t) 0xD2)
    #define CH4_CFG2_DVOL_5dB												((uint8_t) 0xD3)
    #define CH4_CFG2_DVOL_5P5dB												((uint8_t) 0xD4)
    #define CH4_CFG2_DVOL_6dB												((uint8_t) 0xD5)
    #define CH4_CFG2_DVOL_6P5dB												((uint8_t) 0xD6)
    #define CH4_CFG2_DVOL_7dB												((uint8_t) 0xD7)
    #define CH4_CFG2_DVOL_7P5dB												((uint8_t) 0xD8)
    #define CH4_CFG2_DVOL_8dB												((uint8_t) 0xD9)
    #define CH4_CFG2_DVOL_8P5dB												((uint8_t) 0xDA)
    #define CH4_CFG2_DVOL_9dB												((uint8_t) 0xDB)
    #define CH4_CFG2_DVOL_9P5dB												((uint8_t) 0xDC)
    #define CH4_CFG2_DVOL_10dB												((uint8_t) 0xDD)
    #define CH4_CFG2_DVOL_10P5dB											((uint8_t) 0xDE)
    #define CH4_CFG2_DVOL_11dB												((uint8_t) 0xDF)
    #define CH4_CFG2_DVOL_11P5dB											((uint8_t) 0xE0)
    #define CH4_CFG2_DVOL_12dB												((uint8_t) 0xE1)
    #define CH4_CFG2_DVOL_12P5dB											((uint8_t) 0xE2)
    #define CH4_CFG2_DVOL_13dB												((uint8_t) 0xE3)
    #define CH4_CFG2_DVOL_13P5dB											((uint8_t) 0xE4)
    #define CH4_CFG2_DVOL_14dB												((uint8_t) 0xE5)
    #define CH4_CFG2_DVOL_14P5dB											((uint8_t) 0xE6)
    #define CH4_CFG2_DVOL_15dB												((uint8_t) 0xE7)
    #define CH4_CFG2_DVOL_15P5dB											((uint8_t) 0xE8)
    #define CH4_CFG2_DVOL_16dB												((uint8_t) 0xE9)
    #define CH4_CFG2_DVOL_16P5dB											((uint8_t) 0xEA)
    #define CH4_CFG2_DVOL_17dB												((uint8_t) 0xEB)
    #define CH4_CFG2_DVOL_17P5dB											((uint8_t) 0xEC)
    #define CH4_CFG2_DVOL_18dB												((uint8_t) 0xED)
    #define CH4_CFG2_DVOL_18P5dB											((uint8_t) 0xEE)
    #define CH4_CFG2_DVOL_19dB												((uint8_t) 0xEF)
    #define CH4_CFG2_DVOL_19P5dB											((uint8_t) 0xF0)
    #define CH4_CFG2_DVOL_20dB												((uint8_t) 0xF1)
    #define CH4_CFG2_DVOL_20P5dB											((uint8_t) 0xF2)
    #define CH4_CFG2_DVOL_21dB												((uint8_t) 0xF3)
    #define CH4_CFG2_DVOL_21P5dB											((uint8_t) 0xF4)
    #define CH4_CFG2_DVOL_22dB												((uint8_t) 0xF5)
    #define CH4_CFG2_DVOL_22P5dB											((uint8_t) 0xF6)
    #define CH4_CFG2_DVOL_23dB												((uint8_t) 0xF7)
    #define CH4_CFG2_DVOL_23P5dB											((uint8_t) 0xF8)
    #define CH4_CFG2_DVOL_24dB												((uint8_t) 0xF9)
    #define CH4_CFG2_DVOL_24P5dB											((uint8_t) 0xFA)
    #define CH4_CFG2_DVOL_25dB												((uint8_t) 0xFB)
    #define CH4_CFG2_DVOL_25P5dB											((uint8_t) 0xFC)
    #define CH4_CFG2_DVOL_26dB												((uint8_t) 0xFD)
    #define CH4_CFG2_DVOL_26P5dB											((uint8_t) 0xFE)
    #define CH4_CFG2_DVOL_27dB												((uint8_t) 0xFF)



/* Register 0x4E (CH4_CFG3) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                       GCAL[3:0]                                       |                                     RESERVED[3:0]                                     |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH4_CFG3 register */
    #define CH4_CFG3_ADDRESS												((uint8_t) 0x4E)
    #define CH4_CFG3_DEFAULT												((uint8_t) 0x80)

    /* GCAL field */
    #define CH4_CFG3_GCAL_MASK												((uint8_t) 0xF0)
    #define CH4_CFG3_GCAL_M0P8dB											((uint8_t) 0x00)
    #define CH4_CFG3_GCAL_M0P7dB											((uint8_t) 0x10)
    #define CH4_CFG3_GCAL_M0P6dB											((uint8_t) 0x20)
    #define CH4_CFG3_GCAL_M0P5dB											((uint8_t) 0x30)
    #define CH4_CFG3_GCAL_M0P4dB											((uint8_t) 0x40)
    #define CH4_CFG3_GCAL_M0P3dB											((uint8_t) 0x50)
    #define CH4_CFG3_GCAL_M0P2dB											((uint8_t) 0x60)
    #define CH4_CFG3_GCAL_M0P1dB											((uint8_t) 0x70)
    #define CH4_CFG3_GCAL_0dB												((uint8_t) 0x80)    // DEFAULT
    #define CH4_CFG3_GCAL_0P1dB												((uint8_t) 0x90)
    #define CH4_CFG3_GCAL_0P2dB												((uint8_t) 0xA0)
    #define CH4_CFG3_GCAL_0P3dB												((uint8_t) 0xB0)
    #define CH4_CFG3_GCAL_0P4dB												((uint8_t) 0xC0)
    #define CH4_CFG3_GCAL_0P5dB												((uint8_t) 0xD0)
    #define CH4_CFG3_GCAL_0P6dB												((uint8_t) 0xE0)
    #define CH4_CFG3_GCAL_0P7dB												((uint8_t) 0xF0)



/* Register 0x4F (CH4_CFG4) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                                                   PCAL[7:0]                                                                                   |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH4_CFG4 register */
    #define CH4_CFG4_ADDRESS												((uint8_t) 0x4F)
    #define CH4_CFG4_DEFAULT												((uint8_t) 0x00)

    /* PCAL field */
    #define CH4_CFG4_PCAL_MASK												((uint8_t) 0xFF)
    #define CH4_CFG4_PCAL_0													((uint8_t) 0x00)    // DEFAULT
    #define CH4_CFG4_PCAL_1													((uint8_t) 0x01)
    #define CH4_CFG4_PCAL_2													((uint8_t) 0x02)
    #define CH4_CFG4_PCAL_3													((uint8_t) 0x03)
    #define CH4_CFG4_PCAL_4													((uint8_t) 0x04)
    #define CH4_CFG4_PCAL_5													((uint8_t) 0x05)
    #define CH4_CFG4_PCAL_6													((uint8_t) 0x06)
    #define CH4_CFG4_PCAL_7													((uint8_t) 0x07)
    #define CH4_CFG4_PCAL_8													((uint8_t) 0x08)
    #define CH4_CFG4_PCAL_9													((uint8_t) 0x09)
    #define CH4_CFG4_PCAL_10												((uint8_t) 0x0A)
    #define CH4_CFG4_PCAL_11												((uint8_t) 0x0B)
    #define CH4_CFG4_PCAL_12												((uint8_t) 0x0C)
    #define CH4_CFG4_PCAL_13												((uint8_t) 0x0D)
    #define CH4_CFG4_PCAL_14												((uint8_t) 0x0E)
    #define CH4_CFG4_PCAL_15												((uint8_t) 0x0F)
    #define CH4_CFG4_PCAL_16												((uint8_t) 0x10)
    #define CH4_CFG4_PCAL_17												((uint8_t) 0x11)
    #define CH4_CFG4_PCAL_18												((uint8_t) 0x12)
    #define CH4_CFG4_PCAL_19												((uint8_t) 0x13)
    #define CH4_CFG4_PCAL_20												((uint8_t) 0x14)
    #define CH4_CFG4_PCAL_21												((uint8_t) 0x15)
    #define CH4_CFG4_PCAL_22												((uint8_t) 0x16)
    #define CH4_CFG4_PCAL_23												((uint8_t) 0x17)
    #define CH4_CFG4_PCAL_24												((uint8_t) 0x18)
    #define CH4_CFG4_PCAL_25												((uint8_t) 0x19)
    #define CH4_CFG4_PCAL_26												((uint8_t) 0x1A)
    #define CH4_CFG4_PCAL_27												((uint8_t) 0x1B)
    #define CH4_CFG4_PCAL_28												((uint8_t) 0x1C)
    #define CH4_CFG4_PCAL_29												((uint8_t) 0x1D)
    #define CH4_CFG4_PCAL_30												((uint8_t) 0x1E)
    #define CH4_CFG4_PCAL_31												((uint8_t) 0x1F)
    #define CH4_CFG4_PCAL_32												((uint8_t) 0x20)
    #define CH4_CFG4_PCAL_33												((uint8_t) 0x21)
    #define CH4_CFG4_PCAL_34												((uint8_t) 0x22)
    #define CH4_CFG4_PCAL_35												((uint8_t) 0x23)
    #define CH4_CFG4_PCAL_36												((uint8_t) 0x24)
    #define CH4_CFG4_PCAL_37												((uint8_t) 0x25)
    #define CH4_CFG4_PCAL_38												((uint8_t) 0x26)
    #define CH4_CFG4_PCAL_39												((uint8_t) 0x27)
    #define CH4_CFG4_PCAL_40												((uint8_t) 0x28)
    #define CH4_CFG4_PCAL_41												((uint8_t) 0x29)
    #define CH4_CFG4_PCAL_42												((uint8_t) 0x2A)
    #define CH4_CFG4_PCAL_43												((uint8_t) 0x2B)
    #define CH4_CFG4_PCAL_44												((uint8_t) 0x2C)
    #define CH4_CFG4_PCAL_45												((uint8_t) 0x2D)
    #define CH4_CFG4_PCAL_46												((uint8_t) 0x2E)
    #define CH4_CFG4_PCAL_47												((uint8_t) 0x2F)
    #define CH4_CFG4_PCAL_48												((uint8_t) 0x30)
    #define CH4_CFG4_PCAL_49												((uint8_t) 0x31)
    #define CH4_CFG4_PCAL_50												((uint8_t) 0x32)
    #define CH4_CFG4_PCAL_51												((uint8_t) 0x33)
    #define CH4_CFG4_PCAL_52												((uint8_t) 0x34)
    #define CH4_CFG4_PCAL_53												((uint8_t) 0x35)
    #define CH4_CFG4_PCAL_54												((uint8_t) 0x36)
    #define CH4_CFG4_PCAL_55												((uint8_t) 0x37)
    #define CH4_CFG4_PCAL_56												((uint8_t) 0x38)
    #define CH4_CFG4_PCAL_57												((uint8_t) 0x39)
    #define CH4_CFG4_PCAL_58												((uint8_t) 0x3A)
    #define CH4_CFG4_PCAL_59												((uint8_t) 0x3B)
    #define CH4_CFG4_PCAL_60												((uint8_t) 0x3C)
    #define CH4_CFG4_PCAL_61												((uint8_t) 0x3D)
    #define CH4_CFG4_PCAL_62												((uint8_t) 0x3E)
    #define CH4_CFG4_PCAL_63												((uint8_t) 0x3F)
    #define CH4_CFG4_PCAL_64												((uint8_t) 0x40)
    #define CH4_CFG4_PCAL_65												((uint8_t) 0x41)
    #define CH4_CFG4_PCAL_66												((uint8_t) 0x42)
    #define CH4_CFG4_PCAL_67												((uint8_t) 0x43)
    #define CH4_CFG4_PCAL_68												((uint8_t) 0x44)
    #define CH4_CFG4_PCAL_69												((uint8_t) 0x45)
    #define CH4_CFG4_PCAL_70												((uint8_t) 0x46)
    #define CH4_CFG4_PCAL_71												((uint8_t) 0x47)
    #define CH4_CFG4_PCAL_72												((uint8_t) 0x48)
    #define CH4_CFG4_PCAL_73												((uint8_t) 0x49)
    #define CH4_CFG4_PCAL_74												((uint8_t) 0x4A)
    #define CH4_CFG4_PCAL_75												((uint8_t) 0x4B)
    #define CH4_CFG4_PCAL_76												((uint8_t) 0x4C)
    #define CH4_CFG4_PCAL_77												((uint8_t) 0x4D)
    #define CH4_CFG4_PCAL_78												((uint8_t) 0x4E)
    #define CH4_CFG4_PCAL_79												((uint8_t) 0x4F)
    #define CH4_CFG4_PCAL_80												((uint8_t) 0x50)
    #define CH4_CFG4_PCAL_81												((uint8_t) 0x51)
    #define CH4_CFG4_PCAL_82												((uint8_t) 0x52)
    #define CH4_CFG4_PCAL_83												((uint8_t) 0x53)
    #define CH4_CFG4_PCAL_84												((uint8_t) 0x54)
    #define CH4_CFG4_PCAL_85												((uint8_t) 0x55)
    #define CH4_CFG4_PCAL_86												((uint8_t) 0x56)
    #define CH4_CFG4_PCAL_87												((uint8_t) 0x57)
    #define CH4_CFG4_PCAL_88												((uint8_t) 0x58)
    #define CH4_CFG4_PCAL_89												((uint8_t) 0x59)
    #define CH4_CFG4_PCAL_90												((uint8_t) 0x5A)
    #define CH4_CFG4_PCAL_91												((uint8_t) 0x5B)
    #define CH4_CFG4_PCAL_92												((uint8_t) 0x5C)
    #define CH4_CFG4_PCAL_93												((uint8_t) 0x5D)
    #define CH4_CFG4_PCAL_94												((uint8_t) 0x5E)
    #define CH4_CFG4_PCAL_95												((uint8_t) 0x5F)
    #define CH4_CFG4_PCAL_96												((uint8_t) 0x60)
    #define CH4_CFG4_PCAL_97												((uint8_t) 0x61)
    #define CH4_CFG4_PCAL_98												((uint8_t) 0x62)
    #define CH4_CFG4_PCAL_99												((uint8_t) 0x63)
    #define CH4_CFG4_PCAL_100												((uint8_t) 0x64)
    #define CH4_CFG4_PCAL_101												((uint8_t) 0x65)
    #define CH4_CFG4_PCAL_102												((uint8_t) 0x66)
    #define CH4_CFG4_PCAL_103												((uint8_t) 0x67)
    #define CH4_CFG4_PCAL_104												((uint8_t) 0x68)
    #define CH4_CFG4_PCAL_105												((uint8_t) 0x69)
    #define CH4_CFG4_PCAL_106												((uint8_t) 0x6A)
    #define CH4_CFG4_PCAL_107												((uint8_t) 0x6B)
    #define CH4_CFG4_PCAL_108												((uint8_t) 0x6C)
    #define CH4_CFG4_PCAL_109												((uint8_t) 0x6D)
    #define CH4_CFG4_PCAL_110												((uint8_t) 0x6E)
    #define CH4_CFG4_PCAL_111												((uint8_t) 0x6F)
    #define CH4_CFG4_PCAL_112												((uint8_t) 0x70)
    #define CH4_CFG4_PCAL_113												((uint8_t) 0x71)
    #define CH4_CFG4_PCAL_114												((uint8_t) 0x72)
    #define CH4_CFG4_PCAL_115												((uint8_t) 0x73)
    #define CH4_CFG4_PCAL_116												((uint8_t) 0x74)
    #define CH4_CFG4_PCAL_117												((uint8_t) 0x75)
    #define CH4_CFG4_PCAL_118												((uint8_t) 0x76)
    #define CH4_CFG4_PCAL_119												((uint8_t) 0x77)
    #define CH4_CFG4_PCAL_120												((uint8_t) 0x78)
    #define CH4_CFG4_PCAL_121												((uint8_t) 0x79)
    #define CH4_CFG4_PCAL_122												((uint8_t) 0x7A)
    #define CH4_CFG4_PCAL_123												((uint8_t) 0x7B)
    #define CH4_CFG4_PCAL_124												((uint8_t) 0x7C)
    #define CH4_CFG4_PCAL_125												((uint8_t) 0x7D)
    #define CH4_CFG4_PCAL_126												((uint8_t) 0x7E)
    #define CH4_CFG4_PCAL_127												((uint8_t) 0x7F)
    #define CH4_CFG4_PCAL_128												((uint8_t) 0x80)
    #define CH4_CFG4_PCAL_129												((uint8_t) 0x81)
    #define CH4_CFG4_PCAL_130												((uint8_t) 0x82)
    #define CH4_CFG4_PCAL_131												((uint8_t) 0x83)
    #define CH4_CFG4_PCAL_132												((uint8_t) 0x84)
    #define CH4_CFG4_PCAL_133												((uint8_t) 0x85)
    #define CH4_CFG4_PCAL_134												((uint8_t) 0x86)
    #define CH4_CFG4_PCAL_135												((uint8_t) 0x87)
    #define CH4_CFG4_PCAL_136												((uint8_t) 0x88)
    #define CH4_CFG4_PCAL_137												((uint8_t) 0x89)
    #define CH4_CFG4_PCAL_138												((uint8_t) 0x8A)
    #define CH4_CFG4_PCAL_139												((uint8_t) 0x8B)
    #define CH4_CFG4_PCAL_140												((uint8_t) 0x8C)
    #define CH4_CFG4_PCAL_141												((uint8_t) 0x8D)
    #define CH4_CFG4_PCAL_142												((uint8_t) 0x8E)
    #define CH4_CFG4_PCAL_143												((uint8_t) 0x8F)
    #define CH4_CFG4_PCAL_144												((uint8_t) 0x90)
    #define CH4_CFG4_PCAL_145												((uint8_t) 0x91)
    #define CH4_CFG4_PCAL_146												((uint8_t) 0x92)
    #define CH4_CFG4_PCAL_147												((uint8_t) 0x93)
    #define CH4_CFG4_PCAL_148												((uint8_t) 0x94)
    #define CH4_CFG4_PCAL_149												((uint8_t) 0x95)
    #define CH4_CFG4_PCAL_150												((uint8_t) 0x96)
    #define CH4_CFG4_PCAL_151												((uint8_t) 0x97)
    #define CH4_CFG4_PCAL_152												((uint8_t) 0x98)
    #define CH4_CFG4_PCAL_153												((uint8_t) 0x99)
    #define CH4_CFG4_PCAL_154												((uint8_t) 0x9A)
    #define CH4_CFG4_PCAL_155												((uint8_t) 0x9B)
    #define CH4_CFG4_PCAL_156												((uint8_t) 0x9C)
    #define CH4_CFG4_PCAL_157												((uint8_t) 0x9D)
    #define CH4_CFG4_PCAL_158												((uint8_t) 0x9E)
    #define CH4_CFG4_PCAL_159												((uint8_t) 0x9F)
    #define CH4_CFG4_PCAL_160												((uint8_t) 0xA0)
    #define CH4_CFG4_PCAL_161												((uint8_t) 0xA1)
    #define CH4_CFG4_PCAL_162												((uint8_t) 0xA2)
    #define CH4_CFG4_PCAL_163												((uint8_t) 0xA3)
    #define CH4_CFG4_PCAL_164												((uint8_t) 0xA4)
    #define CH4_CFG4_PCAL_165												((uint8_t) 0xA5)
    #define CH4_CFG4_PCAL_166												((uint8_t) 0xA6)
    #define CH4_CFG4_PCAL_167												((uint8_t) 0xA7)
    #define CH4_CFG4_PCAL_168												((uint8_t) 0xA8)
    #define CH4_CFG4_PCAL_169												((uint8_t) 0xA9)
    #define CH4_CFG4_PCAL_170												((uint8_t) 0xAA)
    #define CH4_CFG4_PCAL_171												((uint8_t) 0xAB)
    #define CH4_CFG4_PCAL_172												((uint8_t) 0xAC)
    #define CH4_CFG4_PCAL_173												((uint8_t) 0xAD)
    #define CH4_CFG4_PCAL_174												((uint8_t) 0xAE)
    #define CH4_CFG4_PCAL_175												((uint8_t) 0xAF)
    #define CH4_CFG4_PCAL_176												((uint8_t) 0xB0)
    #define CH4_CFG4_PCAL_177												((uint8_t) 0xB1)
    #define CH4_CFG4_PCAL_178												((uint8_t) 0xB2)
    #define CH4_CFG4_PCAL_179												((uint8_t) 0xB3)
    #define CH4_CFG4_PCAL_180												((uint8_t) 0xB4)
    #define CH4_CFG4_PCAL_181												((uint8_t) 0xB5)
    #define CH4_CFG4_PCAL_182												((uint8_t) 0xB6)
    #define CH4_CFG4_PCAL_183												((uint8_t) 0xB7)
    #define CH4_CFG4_PCAL_184												((uint8_t) 0xB8)
    #define CH4_CFG4_PCAL_185												((uint8_t) 0xB9)
    #define CH4_CFG4_PCAL_186												((uint8_t) 0xBA)
    #define CH4_CFG4_PCAL_187												((uint8_t) 0xBB)
    #define CH4_CFG4_PCAL_188												((uint8_t) 0xBC)
    #define CH4_CFG4_PCAL_189												((uint8_t) 0xBD)
    #define CH4_CFG4_PCAL_190												((uint8_t) 0xBE)
    #define CH4_CFG4_PCAL_191												((uint8_t) 0xBF)
    #define CH4_CFG4_PCAL_192												((uint8_t) 0xC0)
    #define CH4_CFG4_PCAL_193												((uint8_t) 0xC1)
    #define CH4_CFG4_PCAL_194												((uint8_t) 0xC2)
    #define CH4_CFG4_PCAL_195												((uint8_t) 0xC3)
    #define CH4_CFG4_PCAL_196												((uint8_t) 0xC4)
    #define CH4_CFG4_PCAL_197												((uint8_t) 0xC5)
    #define CH4_CFG4_PCAL_198												((uint8_t) 0xC6)
    #define CH4_CFG4_PCAL_199												((uint8_t) 0xC7)
    #define CH4_CFG4_PCAL_200												((uint8_t) 0xC8)
    #define CH4_CFG4_PCAL_201												((uint8_t) 0xC9)
    #define CH4_CFG4_PCAL_202												((uint8_t) 0xCA)
    #define CH4_CFG4_PCAL_203												((uint8_t) 0xCB)
    #define CH4_CFG4_PCAL_204												((uint8_t) 0xCC)
    #define CH4_CFG4_PCAL_205												((uint8_t) 0xCD)
    #define CH4_CFG4_PCAL_206												((uint8_t) 0xCE)
    #define CH4_CFG4_PCAL_207												((uint8_t) 0xCF)
    #define CH4_CFG4_PCAL_208												((uint8_t) 0xD0)
    #define CH4_CFG4_PCAL_209												((uint8_t) 0xD1)
    #define CH4_CFG4_PCAL_210												((uint8_t) 0xD2)
    #define CH4_CFG4_PCAL_211												((uint8_t) 0xD3)
    #define CH4_CFG4_PCAL_212												((uint8_t) 0xD4)
    #define CH4_CFG4_PCAL_213												((uint8_t) 0xD5)
    #define CH4_CFG4_PCAL_214												((uint8_t) 0xD6)
    #define CH4_CFG4_PCAL_215												((uint8_t) 0xD7)
    #define CH4_CFG4_PCAL_216												((uint8_t) 0xD8)
    #define CH4_CFG4_PCAL_217												((uint8_t) 0xD9)
    #define CH4_CFG4_PCAL_218												((uint8_t) 0xDA)
    #define CH4_CFG4_PCAL_219												((uint8_t) 0xDB)
    #define CH4_CFG4_PCAL_220												((uint8_t) 0xDC)
    #define CH4_CFG4_PCAL_221												((uint8_t) 0xDD)
    #define CH4_CFG4_PCAL_222												((uint8_t) 0xDE)
    #define CH4_CFG4_PCAL_223												((uint8_t) 0xDF)
    #define CH4_CFG4_PCAL_224												((uint8_t) 0xE0)
    #define CH4_CFG4_PCAL_225												((uint8_t) 0xE1)
    #define CH4_CFG4_PCAL_226												((uint8_t) 0xE2)
    #define CH4_CFG4_PCAL_227												((uint8_t) 0xE3)
    #define CH4_CFG4_PCAL_228												((uint8_t) 0xE4)
    #define CH4_CFG4_PCAL_229												((uint8_t) 0xE5)
    #define CH4_CFG4_PCAL_230												((uint8_t) 0xE6)
    #define CH4_CFG4_PCAL_231												((uint8_t) 0xE7)
    #define CH4_CFG4_PCAL_232												((uint8_t) 0xE8)
    #define CH4_CFG4_PCAL_233												((uint8_t) 0xE9)
    #define CH4_CFG4_PCAL_234												((uint8_t) 0xEA)
    #define CH4_CFG4_PCAL_235												((uint8_t) 0xEB)
    #define CH4_CFG4_PCAL_236												((uint8_t) 0xEC)
    #define CH4_CFG4_PCAL_237												((uint8_t) 0xED)
    #define CH4_CFG4_PCAL_238												((uint8_t) 0xEE)
    #define CH4_CFG4_PCAL_239												((uint8_t) 0xEF)
    #define CH4_CFG4_PCAL_240												((uint8_t) 0xF0)
    #define CH4_CFG4_PCAL_241												((uint8_t) 0xF1)
    #define CH4_CFG4_PCAL_242												((uint8_t) 0xF2)
    #define CH4_CFG4_PCAL_243												((uint8_t) 0xF3)
    #define CH4_CFG4_PCAL_244												((uint8_t) 0xF4)
    #define CH4_CFG4_PCAL_245												((uint8_t) 0xF5)
    #define CH4_CFG4_PCAL_246												((uint8_t) 0xF6)
    #define CH4_CFG4_PCAL_247												((uint8_t) 0xF7)
    #define CH4_CFG4_PCAL_248												((uint8_t) 0xF8)
    #define CH4_CFG4_PCAL_249												((uint8_t) 0xF9)
    #define CH4_CFG4_PCAL_250												((uint8_t) 0xFA)
    #define CH4_CFG4_PCAL_251												((uint8_t) 0xFB)
    #define CH4_CFG4_PCAL_252												((uint8_t) 0xFC)
    #define CH4_CFG4_PCAL_253												((uint8_t) 0xFD)
    #define CH4_CFG4_PCAL_254												((uint8_t) 0xFE)
    #define CH4_CFG4_PCAL_255												((uint8_t) 0xFF)



/* Register 0x52 (CH5_CFG2) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                                                   DVOL[7:0]                                                                                   |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH5_CFG2 register */
    #define CH5_CFG2_ADDRESS												((uint8_t) 0x52)
    #define CH5_CFG2_DEFAULT												((uint8_t) 0xC9)

    /* DVOL field */
    #define CH5_CFG2_DVOL_MASK												((uint8_t) 0xFF)
    #define CH5_CFG2_DVOL_MUTE												((uint8_t) 0x00)
    #define CH5_CFG2_DVOL_M100dB											((uint8_t) 0x01)
    #define CH5_CFG2_DVOL_M99P5dB											((uint8_t) 0x02)
    #define CH5_CFG2_DVOL_M99dB												((uint8_t) 0x03)
    #define CH5_CFG2_DVOL_M98P5dB											((uint8_t) 0x04)
    #define CH5_CFG2_DVOL_M98dB												((uint8_t) 0x05)
    #define CH5_CFG2_DVOL_M97P5dB											((uint8_t) 0x06)
    #define CH5_CFG2_DVOL_M97dB												((uint8_t) 0x07)
    #define CH5_CFG2_DVOL_M96P5dB											((uint8_t) 0x08)
    #define CH5_CFG2_DVOL_M96dB												((uint8_t) 0x09)
    #define CH5_CFG2_DVOL_M95P5dB											((uint8_t) 0x0A)
    #define CH5_CFG2_DVOL_M95dB												((uint8_t) 0x0B)
    #define CH5_CFG2_DVOL_M94P5dB											((uint8_t) 0x0C)
    #define CH5_CFG2_DVOL_M94dB												((uint8_t) 0x0D)
    #define CH5_CFG2_DVOL_M93P5dB											((uint8_t) 0x0E)
    #define CH5_CFG2_DVOL_M93dB												((uint8_t) 0x0F)
    #define CH5_CFG2_DVOL_M92P5dB											((uint8_t) 0x10)
    #define CH5_CFG2_DVOL_M92dB												((uint8_t) 0x11)
    #define CH5_CFG2_DVOL_M91P5dB											((uint8_t) 0x12)
    #define CH5_CFG2_DVOL_M91dB												((uint8_t) 0x13)
    #define CH5_CFG2_DVOL_M90P5dB											((uint8_t) 0x14)
    #define CH5_CFG2_DVOL_M90dB												((uint8_t) 0x15)
    #define CH5_CFG2_DVOL_M89P5dB											((uint8_t) 0x16)
    #define CH5_CFG2_DVOL_M89dB												((uint8_t) 0x17)
    #define CH5_CFG2_DVOL_M88P5dB											((uint8_t) 0x18)
    #define CH5_CFG2_DVOL_M88dB												((uint8_t) 0x19)
    #define CH5_CFG2_DVOL_M87P5dB											((uint8_t) 0x1A)
    #define CH5_CFG2_DVOL_M87dB												((uint8_t) 0x1B)
    #define CH5_CFG2_DVOL_M86P5dB											((uint8_t) 0x1C)
    #define CH5_CFG2_DVOL_M86dB												((uint8_t) 0x1D)
    #define CH5_CFG2_DVOL_M85P5dB											((uint8_t) 0x1E)
    #define CH5_CFG2_DVOL_M85dB												((uint8_t) 0x1F)
    #define CH5_CFG2_DVOL_M84P5dB											((uint8_t) 0x20)
    #define CH5_CFG2_DVOL_M84dB												((uint8_t) 0x21)
    #define CH5_CFG2_DVOL_M83P5dB											((uint8_t) 0x22)
    #define CH5_CFG2_DVOL_M83dB												((uint8_t) 0x23)
    #define CH5_CFG2_DVOL_M82P5dB											((uint8_t) 0x24)
    #define CH5_CFG2_DVOL_M82dB												((uint8_t) 0x25)
    #define CH5_CFG2_DVOL_M81P5dB											((uint8_t) 0x26)
    #define CH5_CFG2_DVOL_M81dB												((uint8_t) 0x27)
    #define CH5_CFG2_DVOL_M80P5dB											((uint8_t) 0x28)
    #define CH5_CFG2_DVOL_M80dB												((uint8_t) 0x29)
    #define CH5_CFG2_DVOL_M79P5dB											((uint8_t) 0x2A)
    #define CH5_CFG2_DVOL_M79dB												((uint8_t) 0x2B)
    #define CH5_CFG2_DVOL_M78P5dB											((uint8_t) 0x2C)
    #define CH5_CFG2_DVOL_M78dB												((uint8_t) 0x2D)
    #define CH5_CFG2_DVOL_M77P5dB											((uint8_t) 0x2E)
    #define CH5_CFG2_DVOL_M77dB												((uint8_t) 0x2F)
    #define CH5_CFG2_DVOL_M76P5dB											((uint8_t) 0x30)
    #define CH5_CFG2_DVOL_M76dB												((uint8_t) 0x31)
    #define CH5_CFG2_DVOL_M75P5dB											((uint8_t) 0x32)
    #define CH5_CFG2_DVOL_M75dB												((uint8_t) 0x33)
    #define CH5_CFG2_DVOL_M74P5dB											((uint8_t) 0x34)
    #define CH5_CFG2_DVOL_M74dB												((uint8_t) 0x35)
    #define CH5_CFG2_DVOL_M73P5dB											((uint8_t) 0x36)
    #define CH5_CFG2_DVOL_M73dB												((uint8_t) 0x37)
    #define CH5_CFG2_DVOL_M72P5dB											((uint8_t) 0x38)
    #define CH5_CFG2_DVOL_M72dB												((uint8_t) 0x39)
    #define CH5_CFG2_DVOL_M71P5dB											((uint8_t) 0x3A)
    #define CH5_CFG2_DVOL_M71dB												((uint8_t) 0x3B)
    #define CH5_CFG2_DVOL_M70P5dB											((uint8_t) 0x3C)
    #define CH5_CFG2_DVOL_M70dB												((uint8_t) 0x3D)
    #define CH5_CFG2_DVOL_M69P5dB											((uint8_t) 0x3E)
    #define CH5_CFG2_DVOL_M69dB												((uint8_t) 0x3F)
    #define CH5_CFG2_DVOL_M68P5dB											((uint8_t) 0x40)
    #define CH5_CFG2_DVOL_M68dB												((uint8_t) 0x41)
    #define CH5_CFG2_DVOL_M67P5dB											((uint8_t) 0x42)
    #define CH5_CFG2_DVOL_M67dB												((uint8_t) 0x43)
    #define CH5_CFG2_DVOL_M66P5dB											((uint8_t) 0x44)
    #define CH5_CFG2_DVOL_M66dB												((uint8_t) 0x45)
    #define CH5_CFG2_DVOL_M65P5dB											((uint8_t) 0x46)
    #define CH5_CFG2_DVOL_M65dB												((uint8_t) 0x47)
    #define CH5_CFG2_DVOL_M64P5dB											((uint8_t) 0x48)
    #define CH5_CFG2_DVOL_M64dB												((uint8_t) 0x49)
    #define CH5_CFG2_DVOL_M63P5dB											((uint8_t) 0x4A)
    #define CH5_CFG2_DVOL_M63dB												((uint8_t) 0x4B)
    #define CH5_CFG2_DVOL_M62P5dB											((uint8_t) 0x4C)
    #define CH5_CFG2_DVOL_M62dB												((uint8_t) 0x4D)
    #define CH5_CFG2_DVOL_M61P5dB											((uint8_t) 0x4E)
    #define CH5_CFG2_DVOL_M61dB												((uint8_t) 0x4F)
    #define CH5_CFG2_DVOL_M60P5dB											((uint8_t) 0x50)
    #define CH5_CFG2_DVOL_M60dB												((uint8_t) 0x51)
    #define CH5_CFG2_DVOL_M59P5dB											((uint8_t) 0x52)
    #define CH5_CFG2_DVOL_M59dB												((uint8_t) 0x53)
    #define CH5_CFG2_DVOL_M58P5dB											((uint8_t) 0x54)
    #define CH5_CFG2_DVOL_M58dB												((uint8_t) 0x55)
    #define CH5_CFG2_DVOL_M57P5dB											((uint8_t) 0x56)
    #define CH5_CFG2_DVOL_M57dB												((uint8_t) 0x57)
    #define CH5_CFG2_DVOL_M56P5dB											((uint8_t) 0x58)
    #define CH5_CFG2_DVOL_M56dB												((uint8_t) 0x59)
    #define CH5_CFG2_DVOL_M55P5dB											((uint8_t) 0x5A)
    #define CH5_CFG2_DVOL_M55dB												((uint8_t) 0x5B)
    #define CH5_CFG2_DVOL_M54P5dB											((uint8_t) 0x5C)
    #define CH5_CFG2_DVOL_M54dB												((uint8_t) 0x5D)
    #define CH5_CFG2_DVOL_M53P5dB											((uint8_t) 0x5E)
    #define CH5_CFG2_DVOL_M53dB												((uint8_t) 0x5F)
    #define CH5_CFG2_DVOL_M52P5dB											((uint8_t) 0x60)
    #define CH5_CFG2_DVOL_M52dB												((uint8_t) 0x61)
    #define CH5_CFG2_DVOL_M51P5dB											((uint8_t) 0x62)
    #define CH5_CFG2_DVOL_M51dB												((uint8_t) 0x63)
    #define CH5_CFG2_DVOL_M50P5dB											((uint8_t) 0x64)
    #define CH5_CFG2_DVOL_M50dB												((uint8_t) 0x65)
    #define CH5_CFG2_DVOL_M49P5dB											((uint8_t) 0x66)
    #define CH5_CFG2_DVOL_M49dB												((uint8_t) 0x67)
    #define CH5_CFG2_DVOL_M48P5dB											((uint8_t) 0x68)
    #define CH5_CFG2_DVOL_M48dB												((uint8_t) 0x69)
    #define CH5_CFG2_DVOL_M47P5dB											((uint8_t) 0x6A)
    #define CH5_CFG2_DVOL_M47dB												((uint8_t) 0x6B)
    #define CH5_CFG2_DVOL_M46P5dB											((uint8_t) 0x6C)
    #define CH5_CFG2_DVOL_M46dB												((uint8_t) 0x6D)
    #define CH5_CFG2_DVOL_M45P5dB											((uint8_t) 0x6E)
    #define CH5_CFG2_DVOL_M45dB												((uint8_t) 0x6F)
    #define CH5_CFG2_DVOL_M44P5dB											((uint8_t) 0x70)
    #define CH5_CFG2_DVOL_M44dB												((uint8_t) 0x71)
    #define CH5_CFG2_DVOL_M43P5dB											((uint8_t) 0x72)
    #define CH5_CFG2_DVOL_M43dB												((uint8_t) 0x73)
    #define CH5_CFG2_DVOL_M42P5dB											((uint8_t) 0x74)
    #define CH5_CFG2_DVOL_M42dB												((uint8_t) 0x75)
    #define CH5_CFG2_DVOL_M41P5dB											((uint8_t) 0x76)
    #define CH5_CFG2_DVOL_M41dB												((uint8_t) 0x77)
    #define CH5_CFG2_DVOL_M40P5dB											((uint8_t) 0x78)
    #define CH5_CFG2_DVOL_M40dB												((uint8_t) 0x79)
    #define CH5_CFG2_DVOL_M39P5dB											((uint8_t) 0x7A)
    #define CH5_CFG2_DVOL_M39dB												((uint8_t) 0x7B)
    #define CH5_CFG2_DVOL_M38P5dB											((uint8_t) 0x7C)
    #define CH5_CFG2_DVOL_M38dB												((uint8_t) 0x7D)
    #define CH5_CFG2_DVOL_M37P5dB											((uint8_t) 0x7E)
    #define CH5_CFG2_DVOL_M37dB												((uint8_t) 0x7F)
    #define CH5_CFG2_DVOL_M36P5dB											((uint8_t) 0x80)
    #define CH5_CFG2_DVOL_M36dB												((uint8_t) 0x81)
    #define CH5_CFG2_DVOL_M35P5dB											((uint8_t) 0x82)
    #define CH5_CFG2_DVOL_M35dB												((uint8_t) 0x83)
    #define CH5_CFG2_DVOL_M34P5dB											((uint8_t) 0x84)
    #define CH5_CFG2_DVOL_M34dB												((uint8_t) 0x85)
    #define CH5_CFG2_DVOL_M33P5dB											((uint8_t) 0x86)
    #define CH5_CFG2_DVOL_M33dB												((uint8_t) 0x87)
    #define CH5_CFG2_DVOL_M32P5dB											((uint8_t) 0x88)
    #define CH5_CFG2_DVOL_M32dB												((uint8_t) 0x89)
    #define CH5_CFG2_DVOL_M31P5dB											((uint8_t) 0x8A)
    #define CH5_CFG2_DVOL_M31dB												((uint8_t) 0x8B)
    #define CH5_CFG2_DVOL_M30P5dB											((uint8_t) 0x8C)
    #define CH5_CFG2_DVOL_M30dB												((uint8_t) 0x8D)
    #define CH5_CFG2_DVOL_M29P5dB											((uint8_t) 0x8E)
    #define CH5_CFG2_DVOL_M29dB												((uint8_t) 0x8F)
    #define CH5_CFG2_DVOL_M28P5dB											((uint8_t) 0x90)
    #define CH5_CFG2_DVOL_M28dB												((uint8_t) 0x91)
    #define CH5_CFG2_DVOL_M27P5dB											((uint8_t) 0x92)
    #define CH5_CFG2_DVOL_M27dB												((uint8_t) 0x93)
    #define CH5_CFG2_DVOL_M26P5dB											((uint8_t) 0x94)
    #define CH5_CFG2_DVOL_M26dB												((uint8_t) 0x95)
    #define CH5_CFG2_DVOL_M25P5dB											((uint8_t) 0x96)
    #define CH5_CFG2_DVOL_M25dB												((uint8_t) 0x97)
    #define CH5_CFG2_DVOL_M24P5dB											((uint8_t) 0x98)
    #define CH5_CFG2_DVOL_M24dB												((uint8_t) 0x99)
    #define CH5_CFG2_DVOL_M23P5dB											((uint8_t) 0x9A)
    #define CH5_CFG2_DVOL_M23dB												((uint8_t) 0x9B)
    #define CH5_CFG2_DVOL_M22P5dB											((uint8_t) 0x9C)
    #define CH5_CFG2_DVOL_M22dB												((uint8_t) 0x9D)
    #define CH5_CFG2_DVOL_M21P5dB											((uint8_t) 0x9E)
    #define CH5_CFG2_DVOL_M21dB												((uint8_t) 0x9F)
    #define CH5_CFG2_DVOL_M20P5dB											((uint8_t) 0xA0)
    #define CH5_CFG2_DVOL_M20dB												((uint8_t) 0xA1)
    #define CH5_CFG2_DVOL_M19P5dB											((uint8_t) 0xA2)
    #define CH5_CFG2_DVOL_M19dB												((uint8_t) 0xA3)
    #define CH5_CFG2_DVOL_M18P5dB											((uint8_t) 0xA4)
    #define CH5_CFG2_DVOL_M18dB												((uint8_t) 0xA5)
    #define CH5_CFG2_DVOL_M17P5dB											((uint8_t) 0xA6)
    #define CH5_CFG2_DVOL_M17dB												((uint8_t) 0xA7)
    #define CH5_CFG2_DVOL_M16P5dB											((uint8_t) 0xA8)
    #define CH5_CFG2_DVOL_M16dB												((uint8_t) 0xA9)
    #define CH5_CFG2_DVOL_M15P5dB											((uint8_t) 0xAA)
    #define CH5_CFG2_DVOL_M15dB												((uint8_t) 0xAB)
    #define CH5_CFG2_DVOL_M14P5dB											((uint8_t) 0xAC)
    #define CH5_CFG2_DVOL_M14dB												((uint8_t) 0xAD)
    #define CH5_CFG2_DVOL_M13P5dB											((uint8_t) 0xAE)
    #define CH5_CFG2_DVOL_M13dB												((uint8_t) 0xAF)
    #define CH5_CFG2_DVOL_M12P5dB											((uint8_t) 0xB0)
    #define CH5_CFG2_DVOL_M12dB												((uint8_t) 0xB1)
    #define CH5_CFG2_DVOL_M11P5dB											((uint8_t) 0xB2)
    #define CH5_CFG2_DVOL_M11dB												((uint8_t) 0xB3)
    #define CH5_CFG2_DVOL_M10P5dB											((uint8_t) 0xB4)
    #define CH5_CFG2_DVOL_M10dB												((uint8_t) 0xB5)
    #define CH5_CFG2_DVOL_M9P5dB											((uint8_t) 0xB6)
    #define CH5_CFG2_DVOL_M9dB												((uint8_t) 0xB7)
    #define CH5_CFG2_DVOL_M8P5dB											((uint8_t) 0xB8)
    #define CH5_CFG2_DVOL_M8dB												((uint8_t) 0xB9)
    #define CH5_CFG2_DVOL_M7P5dB											((uint8_t) 0xBA)
    #define CH5_CFG2_DVOL_M7dB												((uint8_t) 0xBB)
    #define CH5_CFG2_DVOL_M6P5dB											((uint8_t) 0xBC)
    #define CH5_CFG2_DVOL_M6dB												((uint8_t) 0xBD)
    #define CH5_CFG2_DVOL_M5P5dB											((uint8_t) 0xBE)
    #define CH5_CFG2_DVOL_M5dB												((uint8_t) 0xBF)
    #define CH5_CFG2_DVOL_M4P5dB											((uint8_t) 0xC0)
    #define CH5_CFG2_DVOL_M4dB												((uint8_t) 0xC1)
    #define CH5_CFG2_DVOL_M3P5dB											((uint8_t) 0xC2)
    #define CH5_CFG2_DVOL_M3dB												((uint8_t) 0xC3)
    #define CH5_CFG2_DVOL_M2P5dB											((uint8_t) 0xC4)
    #define CH5_CFG2_DVOL_M2dB												((uint8_t) 0xC5)
    #define CH5_CFG2_DVOL_M1P5dB											((uint8_t) 0xC6)
    #define CH5_CFG2_DVOL_M1dB												((uint8_t) 0xC7)
    #define CH5_CFG2_DVOL_M0P5dB											((uint8_t) 0xC8)
    #define CH5_CFG2_DVOL_0dB												((uint8_t) 0xC9)    // DEFAULT
    #define CH5_CFG2_DVOL_0P5dB												((uint8_t) 0xCA)
    #define CH5_CFG2_DVOL_1dB												((uint8_t) 0xCB)
    #define CH5_CFG2_DVOL_1P5dB												((uint8_t) 0xCC)
    #define CH5_CFG2_DVOL_2dB												((uint8_t) 0xCD)
    #define CH5_CFG2_DVOL_2P5dB												((uint8_t) 0xCE)
    #define CH5_CFG2_DVOL_3dB												((uint8_t) 0xCF)
    #define CH5_CFG2_DVOL_3P5dB												((uint8_t) 0xD0)
    #define CH5_CFG2_DVOL_4dB												((uint8_t) 0xD1)
    #define CH5_CFG2_DVOL_4P5dB												((uint8_t) 0xD2)
    #define CH5_CFG2_DVOL_5dB												((uint8_t) 0xD3)
    #define CH5_CFG2_DVOL_5P5dB												((uint8_t) 0xD4)
    #define CH5_CFG2_DVOL_6dB												((uint8_t) 0xD5)
    #define CH5_CFG2_DVOL_6P5dB												((uint8_t) 0xD6)
    #define CH5_CFG2_DVOL_7dB												((uint8_t) 0xD7)
    #define CH5_CFG2_DVOL_7P5dB												((uint8_t) 0xD8)
    #define CH5_CFG2_DVOL_8dB												((uint8_t) 0xD9)
    #define CH5_CFG2_DVOL_8P5dB												((uint8_t) 0xDA)
    #define CH5_CFG2_DVOL_9dB												((uint8_t) 0xDB)
    #define CH5_CFG2_DVOL_9P5dB												((uint8_t) 0xDC)
    #define CH5_CFG2_DVOL_10dB												((uint8_t) 0xDD)
    #define CH5_CFG2_DVOL_10P5dB											((uint8_t) 0xDE)
    #define CH5_CFG2_DVOL_11dB												((uint8_t) 0xDF)
    #define CH5_CFG2_DVOL_11P5dB											((uint8_t) 0xE0)
    #define CH5_CFG2_DVOL_12dB												((uint8_t) 0xE1)
    #define CH5_CFG2_DVOL_12P5dB											((uint8_t) 0xE2)
    #define CH5_CFG2_DVOL_13dB												((uint8_t) 0xE3)
    #define CH5_CFG2_DVOL_13P5dB											((uint8_t) 0xE4)
    #define CH5_CFG2_DVOL_14dB												((uint8_t) 0xE5)
    #define CH5_CFG2_DVOL_14P5dB											((uint8_t) 0xE6)
    #define CH5_CFG2_DVOL_15dB												((uint8_t) 0xE7)
    #define CH5_CFG2_DVOL_15P5dB											((uint8_t) 0xE8)
    #define CH5_CFG2_DVOL_16dB												((uint8_t) 0xE9)
    #define CH5_CFG2_DVOL_16P5dB											((uint8_t) 0xEA)
    #define CH5_CFG2_DVOL_17dB												((uint8_t) 0xEB)
    #define CH5_CFG2_DVOL_17P5dB											((uint8_t) 0xEC)
    #define CH5_CFG2_DVOL_18dB												((uint8_t) 0xED)
    #define CH5_CFG2_DVOL_18P5dB											((uint8_t) 0xEE)
    #define CH5_CFG2_DVOL_19dB												((uint8_t) 0xEF)
    #define CH5_CFG2_DVOL_19P5dB											((uint8_t) 0xF0)
    #define CH5_CFG2_DVOL_20dB												((uint8_t) 0xF1)
    #define CH5_CFG2_DVOL_20P5dB											((uint8_t) 0xF2)
    #define CH5_CFG2_DVOL_21dB												((uint8_t) 0xF3)
    #define CH5_CFG2_DVOL_21P5dB											((uint8_t) 0xF4)
    #define CH5_CFG2_DVOL_22dB												((uint8_t) 0xF5)
    #define CH5_CFG2_DVOL_22P5dB											((uint8_t) 0xF6)
    #define CH5_CFG2_DVOL_23dB												((uint8_t) 0xF7)
    #define CH5_CFG2_DVOL_23P5dB											((uint8_t) 0xF8)
    #define CH5_CFG2_DVOL_24dB												((uint8_t) 0xF9)
    #define CH5_CFG2_DVOL_24P5dB											((uint8_t) 0xFA)
    #define CH5_CFG2_DVOL_25dB												((uint8_t) 0xFB)
    #define CH5_CFG2_DVOL_25P5dB											((uint8_t) 0xFC)
    #define CH5_CFG2_DVOL_26dB												((uint8_t) 0xFD)
    #define CH5_CFG2_DVOL_26P5dB											((uint8_t) 0xFE)
    #define CH5_CFG2_DVOL_27dB												((uint8_t) 0xFF)



/* Register 0x53 (CH5_CFG3) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                       GCAL[3:0]                                       |                                     RESERVED[3:0]                                     |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH5_CFG3 register */
    #define CH5_CFG3_ADDRESS												((uint8_t) 0x53)
    #define CH5_CFG3_DEFAULT												((uint8_t) 0x80)

    /* GCAL field */
    #define CH5_CFG3_GCAL_MASK												((uint8_t) 0xF0)
    #define CH5_CFG3_GCAL_M0P8dB											((uint8_t) 0x00)
    #define CH5_CFG3_GCAL_M0P7dB											((uint8_t) 0x10)
    #define CH5_CFG3_GCAL_M0P6dB											((uint8_t) 0x20)
    #define CH5_CFG3_GCAL_M0P5dB											((uint8_t) 0x30)
    #define CH5_CFG3_GCAL_M0P4dB											((uint8_t) 0x40)
    #define CH5_CFG3_GCAL_M0P3dB											((uint8_t) 0x50)
    #define CH5_CFG3_GCAL_M0P2dB											((uint8_t) 0x60)
    #define CH5_CFG3_GCAL_M0P1dB											((uint8_t) 0x70)
    #define CH5_CFG3_GCAL_0dB												((uint8_t) 0x80)    // DEFAULT
    #define CH5_CFG3_GCAL_0P1dB												((uint8_t) 0x90)
    #define CH5_CFG3_GCAL_0P2dB												((uint8_t) 0xA0)
    #define CH5_CFG3_GCAL_0P3dB												((uint8_t) 0xB0)
    #define CH5_CFG3_GCAL_0P4dB												((uint8_t) 0xC0)
    #define CH5_CFG3_GCAL_0P5dB												((uint8_t) 0xD0)
    #define CH5_CFG3_GCAL_0P6dB												((uint8_t) 0xE0)
    #define CH5_CFG3_GCAL_0P7dB												((uint8_t) 0xF0)



/* Register 0x54 (CH5_CFG4) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                                                   PCAL[7:0]                                                                                   |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH5_CFG4 register */
    #define CH5_CFG4_ADDRESS												((uint8_t) 0x54)
    #define CH5_CFG4_DEFAULT												((uint8_t) 0x00)

    /* PCAL field */
    #define CH5_CFG4_PCAL_MASK												((uint8_t) 0xFF)
    #define CH5_CFG4_PCAL_0													((uint8_t) 0x00)    // DEFAULT
    #define CH5_CFG4_PCAL_1													((uint8_t) 0x01)
    #define CH5_CFG4_PCAL_2													((uint8_t) 0x02)
    #define CH5_CFG4_PCAL_3													((uint8_t) 0x03)
    #define CH5_CFG4_PCAL_4													((uint8_t) 0x04)
    #define CH5_CFG4_PCAL_5													((uint8_t) 0x05)
    #define CH5_CFG4_PCAL_6													((uint8_t) 0x06)
    #define CH5_CFG4_PCAL_7													((uint8_t) 0x07)
    #define CH5_CFG4_PCAL_8													((uint8_t) 0x08)
    #define CH5_CFG4_PCAL_9													((uint8_t) 0x09)
    #define CH5_CFG4_PCAL_10												((uint8_t) 0x0A)
    #define CH5_CFG4_PCAL_11												((uint8_t) 0x0B)
    #define CH5_CFG4_PCAL_12												((uint8_t) 0x0C)
    #define CH5_CFG4_PCAL_13												((uint8_t) 0x0D)
    #define CH5_CFG4_PCAL_14												((uint8_t) 0x0E)
    #define CH5_CFG4_PCAL_15												((uint8_t) 0x0F)
    #define CH5_CFG4_PCAL_16												((uint8_t) 0x10)
    #define CH5_CFG4_PCAL_17												((uint8_t) 0x11)
    #define CH5_CFG4_PCAL_18												((uint8_t) 0x12)
    #define CH5_CFG4_PCAL_19												((uint8_t) 0x13)
    #define CH5_CFG4_PCAL_20												((uint8_t) 0x14)
    #define CH5_CFG4_PCAL_21												((uint8_t) 0x15)
    #define CH5_CFG4_PCAL_22												((uint8_t) 0x16)
    #define CH5_CFG4_PCAL_23												((uint8_t) 0x17)
    #define CH5_CFG4_PCAL_24												((uint8_t) 0x18)
    #define CH5_CFG4_PCAL_25												((uint8_t) 0x19)
    #define CH5_CFG4_PCAL_26												((uint8_t) 0x1A)
    #define CH5_CFG4_PCAL_27												((uint8_t) 0x1B)
    #define CH5_CFG4_PCAL_28												((uint8_t) 0x1C)
    #define CH5_CFG4_PCAL_29												((uint8_t) 0x1D)
    #define CH5_CFG4_PCAL_30												((uint8_t) 0x1E)
    #define CH5_CFG4_PCAL_31												((uint8_t) 0x1F)
    #define CH5_CFG4_PCAL_32												((uint8_t) 0x20)
    #define CH5_CFG4_PCAL_33												((uint8_t) 0x21)
    #define CH5_CFG4_PCAL_34												((uint8_t) 0x22)
    #define CH5_CFG4_PCAL_35												((uint8_t) 0x23)
    #define CH5_CFG4_PCAL_36												((uint8_t) 0x24)
    #define CH5_CFG4_PCAL_37												((uint8_t) 0x25)
    #define CH5_CFG4_PCAL_38												((uint8_t) 0x26)
    #define CH5_CFG4_PCAL_39												((uint8_t) 0x27)
    #define CH5_CFG4_PCAL_40												((uint8_t) 0x28)
    #define CH5_CFG4_PCAL_41												((uint8_t) 0x29)
    #define CH5_CFG4_PCAL_42												((uint8_t) 0x2A)
    #define CH5_CFG4_PCAL_43												((uint8_t) 0x2B)
    #define CH5_CFG4_PCAL_44												((uint8_t) 0x2C)
    #define CH5_CFG4_PCAL_45												((uint8_t) 0x2D)
    #define CH5_CFG4_PCAL_46												((uint8_t) 0x2E)
    #define CH5_CFG4_PCAL_47												((uint8_t) 0x2F)
    #define CH5_CFG4_PCAL_48												((uint8_t) 0x30)
    #define CH5_CFG4_PCAL_49												((uint8_t) 0x31)
    #define CH5_CFG4_PCAL_50												((uint8_t) 0x32)
    #define CH5_CFG4_PCAL_51												((uint8_t) 0x33)
    #define CH5_CFG4_PCAL_52												((uint8_t) 0x34)
    #define CH5_CFG4_PCAL_53												((uint8_t) 0x35)
    #define CH5_CFG4_PCAL_54												((uint8_t) 0x36)
    #define CH5_CFG4_PCAL_55												((uint8_t) 0x37)
    #define CH5_CFG4_PCAL_56												((uint8_t) 0x38)
    #define CH5_CFG4_PCAL_57												((uint8_t) 0x39)
    #define CH5_CFG4_PCAL_58												((uint8_t) 0x3A)
    #define CH5_CFG4_PCAL_59												((uint8_t) 0x3B)
    #define CH5_CFG4_PCAL_60												((uint8_t) 0x3C)
    #define CH5_CFG4_PCAL_61												((uint8_t) 0x3D)
    #define CH5_CFG4_PCAL_62												((uint8_t) 0x3E)
    #define CH5_CFG4_PCAL_63												((uint8_t) 0x3F)
    #define CH5_CFG4_PCAL_64												((uint8_t) 0x40)
    #define CH5_CFG4_PCAL_65												((uint8_t) 0x41)
    #define CH5_CFG4_PCAL_66												((uint8_t) 0x42)
    #define CH5_CFG4_PCAL_67												((uint8_t) 0x43)
    #define CH5_CFG4_PCAL_68												((uint8_t) 0x44)
    #define CH5_CFG4_PCAL_69												((uint8_t) 0x45)
    #define CH5_CFG4_PCAL_70												((uint8_t) 0x46)
    #define CH5_CFG4_PCAL_71												((uint8_t) 0x47)
    #define CH5_CFG4_PCAL_72												((uint8_t) 0x48)
    #define CH5_CFG4_PCAL_73												((uint8_t) 0x49)
    #define CH5_CFG4_PCAL_74												((uint8_t) 0x4A)
    #define CH5_CFG4_PCAL_75												((uint8_t) 0x4B)
    #define CH5_CFG4_PCAL_76												((uint8_t) 0x4C)
    #define CH5_CFG4_PCAL_77												((uint8_t) 0x4D)
    #define CH5_CFG4_PCAL_78												((uint8_t) 0x4E)
    #define CH5_CFG4_PCAL_79												((uint8_t) 0x4F)
    #define CH5_CFG4_PCAL_80												((uint8_t) 0x50)
    #define CH5_CFG4_PCAL_81												((uint8_t) 0x51)
    #define CH5_CFG4_PCAL_82												((uint8_t) 0x52)
    #define CH5_CFG4_PCAL_83												((uint8_t) 0x53)
    #define CH5_CFG4_PCAL_84												((uint8_t) 0x54)
    #define CH5_CFG4_PCAL_85												((uint8_t) 0x55)
    #define CH5_CFG4_PCAL_86												((uint8_t) 0x56)
    #define CH5_CFG4_PCAL_87												((uint8_t) 0x57)
    #define CH5_CFG4_PCAL_88												((uint8_t) 0x58)
    #define CH5_CFG4_PCAL_89												((uint8_t) 0x59)
    #define CH5_CFG4_PCAL_90												((uint8_t) 0x5A)
    #define CH5_CFG4_PCAL_91												((uint8_t) 0x5B)
    #define CH5_CFG4_PCAL_92												((uint8_t) 0x5C)
    #define CH5_CFG4_PCAL_93												((uint8_t) 0x5D)
    #define CH5_CFG4_PCAL_94												((uint8_t) 0x5E)
    #define CH5_CFG4_PCAL_95												((uint8_t) 0x5F)
    #define CH5_CFG4_PCAL_96												((uint8_t) 0x60)
    #define CH5_CFG4_PCAL_97												((uint8_t) 0x61)
    #define CH5_CFG4_PCAL_98												((uint8_t) 0x62)
    #define CH5_CFG4_PCAL_99												((uint8_t) 0x63)
    #define CH5_CFG4_PCAL_100												((uint8_t) 0x64)
    #define CH5_CFG4_PCAL_101												((uint8_t) 0x65)
    #define CH5_CFG4_PCAL_102												((uint8_t) 0x66)
    #define CH5_CFG4_PCAL_103												((uint8_t) 0x67)
    #define CH5_CFG4_PCAL_104												((uint8_t) 0x68)
    #define CH5_CFG4_PCAL_105												((uint8_t) 0x69)
    #define CH5_CFG4_PCAL_106												((uint8_t) 0x6A)
    #define CH5_CFG4_PCAL_107												((uint8_t) 0x6B)
    #define CH5_CFG4_PCAL_108												((uint8_t) 0x6C)
    #define CH5_CFG4_PCAL_109												((uint8_t) 0x6D)
    #define CH5_CFG4_PCAL_110												((uint8_t) 0x6E)
    #define CH5_CFG4_PCAL_111												((uint8_t) 0x6F)
    #define CH5_CFG4_PCAL_112												((uint8_t) 0x70)
    #define CH5_CFG4_PCAL_113												((uint8_t) 0x71)
    #define CH5_CFG4_PCAL_114												((uint8_t) 0x72)
    #define CH5_CFG4_PCAL_115												((uint8_t) 0x73)
    #define CH5_CFG4_PCAL_116												((uint8_t) 0x74)
    #define CH5_CFG4_PCAL_117												((uint8_t) 0x75)
    #define CH5_CFG4_PCAL_118												((uint8_t) 0x76)
    #define CH5_CFG4_PCAL_119												((uint8_t) 0x77)
    #define CH5_CFG4_PCAL_120												((uint8_t) 0x78)
    #define CH5_CFG4_PCAL_121												((uint8_t) 0x79)
    #define CH5_CFG4_PCAL_122												((uint8_t) 0x7A)
    #define CH5_CFG4_PCAL_123												((uint8_t) 0x7B)
    #define CH5_CFG4_PCAL_124												((uint8_t) 0x7C)
    #define CH5_CFG4_PCAL_125												((uint8_t) 0x7D)
    #define CH5_CFG4_PCAL_126												((uint8_t) 0x7E)
    #define CH5_CFG4_PCAL_127												((uint8_t) 0x7F)
    #define CH5_CFG4_PCAL_128												((uint8_t) 0x80)
    #define CH5_CFG4_PCAL_129												((uint8_t) 0x81)
    #define CH5_CFG4_PCAL_130												((uint8_t) 0x82)
    #define CH5_CFG4_PCAL_131												((uint8_t) 0x83)
    #define CH5_CFG4_PCAL_132												((uint8_t) 0x84)
    #define CH5_CFG4_PCAL_133												((uint8_t) 0x85)
    #define CH5_CFG4_PCAL_134												((uint8_t) 0x86)
    #define CH5_CFG4_PCAL_135												((uint8_t) 0x87)
    #define CH5_CFG4_PCAL_136												((uint8_t) 0x88)
    #define CH5_CFG4_PCAL_137												((uint8_t) 0x89)
    #define CH5_CFG4_PCAL_138												((uint8_t) 0x8A)
    #define CH5_CFG4_PCAL_139												((uint8_t) 0x8B)
    #define CH5_CFG4_PCAL_140												((uint8_t) 0x8C)
    #define CH5_CFG4_PCAL_141												((uint8_t) 0x8D)
    #define CH5_CFG4_PCAL_142												((uint8_t) 0x8E)
    #define CH5_CFG4_PCAL_143												((uint8_t) 0x8F)
    #define CH5_CFG4_PCAL_144												((uint8_t) 0x90)
    #define CH5_CFG4_PCAL_145												((uint8_t) 0x91)
    #define CH5_CFG4_PCAL_146												((uint8_t) 0x92)
    #define CH5_CFG4_PCAL_147												((uint8_t) 0x93)
    #define CH5_CFG4_PCAL_148												((uint8_t) 0x94)
    #define CH5_CFG4_PCAL_149												((uint8_t) 0x95)
    #define CH5_CFG4_PCAL_150												((uint8_t) 0x96)
    #define CH5_CFG4_PCAL_151												((uint8_t) 0x97)
    #define CH5_CFG4_PCAL_152												((uint8_t) 0x98)
    #define CH5_CFG4_PCAL_153												((uint8_t) 0x99)
    #define CH5_CFG4_PCAL_154												((uint8_t) 0x9A)
    #define CH5_CFG4_PCAL_155												((uint8_t) 0x9B)
    #define CH5_CFG4_PCAL_156												((uint8_t) 0x9C)
    #define CH5_CFG4_PCAL_157												((uint8_t) 0x9D)
    #define CH5_CFG4_PCAL_158												((uint8_t) 0x9E)
    #define CH5_CFG4_PCAL_159												((uint8_t) 0x9F)
    #define CH5_CFG4_PCAL_160												((uint8_t) 0xA0)
    #define CH5_CFG4_PCAL_161												((uint8_t) 0xA1)
    #define CH5_CFG4_PCAL_162												((uint8_t) 0xA2)
    #define CH5_CFG4_PCAL_163												((uint8_t) 0xA3)
    #define CH5_CFG4_PCAL_164												((uint8_t) 0xA4)
    #define CH5_CFG4_PCAL_165												((uint8_t) 0xA5)
    #define CH5_CFG4_PCAL_166												((uint8_t) 0xA6)
    #define CH5_CFG4_PCAL_167												((uint8_t) 0xA7)
    #define CH5_CFG4_PCAL_168												((uint8_t) 0xA8)
    #define CH5_CFG4_PCAL_169												((uint8_t) 0xA9)
    #define CH5_CFG4_PCAL_170												((uint8_t) 0xAA)
    #define CH5_CFG4_PCAL_171												((uint8_t) 0xAB)
    #define CH5_CFG4_PCAL_172												((uint8_t) 0xAC)
    #define CH5_CFG4_PCAL_173												((uint8_t) 0xAD)
    #define CH5_CFG4_PCAL_174												((uint8_t) 0xAE)
    #define CH5_CFG4_PCAL_175												((uint8_t) 0xAF)
    #define CH5_CFG4_PCAL_176												((uint8_t) 0xB0)
    #define CH5_CFG4_PCAL_177												((uint8_t) 0xB1)
    #define CH5_CFG4_PCAL_178												((uint8_t) 0xB2)
    #define CH5_CFG4_PCAL_179												((uint8_t) 0xB3)
    #define CH5_CFG4_PCAL_180												((uint8_t) 0xB4)
    #define CH5_CFG4_PCAL_181												((uint8_t) 0xB5)
    #define CH5_CFG4_PCAL_182												((uint8_t) 0xB6)
    #define CH5_CFG4_PCAL_183												((uint8_t) 0xB7)
    #define CH5_CFG4_PCAL_184												((uint8_t) 0xB8)
    #define CH5_CFG4_PCAL_185												((uint8_t) 0xB9)
    #define CH5_CFG4_PCAL_186												((uint8_t) 0xBA)
    #define CH5_CFG4_PCAL_187												((uint8_t) 0xBB)
    #define CH5_CFG4_PCAL_188												((uint8_t) 0xBC)
    #define CH5_CFG4_PCAL_189												((uint8_t) 0xBD)
    #define CH5_CFG4_PCAL_190												((uint8_t) 0xBE)
    #define CH5_CFG4_PCAL_191												((uint8_t) 0xBF)
    #define CH5_CFG4_PCAL_192												((uint8_t) 0xC0)
    #define CH5_CFG4_PCAL_193												((uint8_t) 0xC1)
    #define CH5_CFG4_PCAL_194												((uint8_t) 0xC2)
    #define CH5_CFG4_PCAL_195												((uint8_t) 0xC3)
    #define CH5_CFG4_PCAL_196												((uint8_t) 0xC4)
    #define CH5_CFG4_PCAL_197												((uint8_t) 0xC5)
    #define CH5_CFG4_PCAL_198												((uint8_t) 0xC6)
    #define CH5_CFG4_PCAL_199												((uint8_t) 0xC7)
    #define CH5_CFG4_PCAL_200												((uint8_t) 0xC8)
    #define CH5_CFG4_PCAL_201												((uint8_t) 0xC9)
    #define CH5_CFG4_PCAL_202												((uint8_t) 0xCA)
    #define CH5_CFG4_PCAL_203												((uint8_t) 0xCB)
    #define CH5_CFG4_PCAL_204												((uint8_t) 0xCC)
    #define CH5_CFG4_PCAL_205												((uint8_t) 0xCD)
    #define CH5_CFG4_PCAL_206												((uint8_t) 0xCE)
    #define CH5_CFG4_PCAL_207												((uint8_t) 0xCF)
    #define CH5_CFG4_PCAL_208												((uint8_t) 0xD0)
    #define CH5_CFG4_PCAL_209												((uint8_t) 0xD1)
    #define CH5_CFG4_PCAL_210												((uint8_t) 0xD2)
    #define CH5_CFG4_PCAL_211												((uint8_t) 0xD3)
    #define CH5_CFG4_PCAL_212												((uint8_t) 0xD4)
    #define CH5_CFG4_PCAL_213												((uint8_t) 0xD5)
    #define CH5_CFG4_PCAL_214												((uint8_t) 0xD6)
    #define CH5_CFG4_PCAL_215												((uint8_t) 0xD7)
    #define CH5_CFG4_PCAL_216												((uint8_t) 0xD8)
    #define CH5_CFG4_PCAL_217												((uint8_t) 0xD9)
    #define CH5_CFG4_PCAL_218												((uint8_t) 0xDA)
    #define CH5_CFG4_PCAL_219												((uint8_t) 0xDB)
    #define CH5_CFG4_PCAL_220												((uint8_t) 0xDC)
    #define CH5_CFG4_PCAL_221												((uint8_t) 0xDD)
    #define CH5_CFG4_PCAL_222												((uint8_t) 0xDE)
    #define CH5_CFG4_PCAL_223												((uint8_t) 0xDF)
    #define CH5_CFG4_PCAL_224												((uint8_t) 0xE0)
    #define CH5_CFG4_PCAL_225												((uint8_t) 0xE1)
    #define CH5_CFG4_PCAL_226												((uint8_t) 0xE2)
    #define CH5_CFG4_PCAL_227												((uint8_t) 0xE3)
    #define CH5_CFG4_PCAL_228												((uint8_t) 0xE4)
    #define CH5_CFG4_PCAL_229												((uint8_t) 0xE5)
    #define CH5_CFG4_PCAL_230												((uint8_t) 0xE6)
    #define CH5_CFG4_PCAL_231												((uint8_t) 0xE7)
    #define CH5_CFG4_PCAL_232												((uint8_t) 0xE8)
    #define CH5_CFG4_PCAL_233												((uint8_t) 0xE9)
    #define CH5_CFG4_PCAL_234												((uint8_t) 0xEA)
    #define CH5_CFG4_PCAL_235												((uint8_t) 0xEB)
    #define CH5_CFG4_PCAL_236												((uint8_t) 0xEC)
    #define CH5_CFG4_PCAL_237												((uint8_t) 0xED)
    #define CH5_CFG4_PCAL_238												((uint8_t) 0xEE)
    #define CH5_CFG4_PCAL_239												((uint8_t) 0xEF)
    #define CH5_CFG4_PCAL_240												((uint8_t) 0xF0)
    #define CH5_CFG4_PCAL_241												((uint8_t) 0xF1)
    #define CH5_CFG4_PCAL_242												((uint8_t) 0xF2)
    #define CH5_CFG4_PCAL_243												((uint8_t) 0xF3)
    #define CH5_CFG4_PCAL_244												((uint8_t) 0xF4)
    #define CH5_CFG4_PCAL_245												((uint8_t) 0xF5)
    #define CH5_CFG4_PCAL_246												((uint8_t) 0xF6)
    #define CH5_CFG4_PCAL_247												((uint8_t) 0xF7)
    #define CH5_CFG4_PCAL_248												((uint8_t) 0xF8)
    #define CH5_CFG4_PCAL_249												((uint8_t) 0xF9)
    #define CH5_CFG4_PCAL_250												((uint8_t) 0xFA)
    #define CH5_CFG4_PCAL_251												((uint8_t) 0xFB)
    #define CH5_CFG4_PCAL_252												((uint8_t) 0xFC)
    #define CH5_CFG4_PCAL_253												((uint8_t) 0xFD)
    #define CH5_CFG4_PCAL_254												((uint8_t) 0xFE)
    #define CH5_CFG4_PCAL_255												((uint8_t) 0xFF)



/* Register 0x57 (CH6_CFG2) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                                                   DVOL[7:0]                                                                                   |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH6_CFG2 register */
    #define CH6_CFG2_ADDRESS												((uint8_t) 0x57)
    #define CH6_CFG2_DEFAULT												((uint8_t) 0xC9)

    /* DVOL field */
    #define CH6_CFG2_DVOL_MASK												((uint8_t) 0xFF)
    #define CH6_CFG2_DVOL_MUTE												((uint8_t) 0x00)
    #define CH6_CFG2_DVOL_M100dB											((uint8_t) 0x01)
    #define CH6_CFG2_DVOL_M99P5dB											((uint8_t) 0x02)
    #define CH6_CFG2_DVOL_M99dB												((uint8_t) 0x03)
    #define CH6_CFG2_DVOL_M98P5dB											((uint8_t) 0x04)
    #define CH6_CFG2_DVOL_M98dB												((uint8_t) 0x05)
    #define CH6_CFG2_DVOL_M97P5dB											((uint8_t) 0x06)
    #define CH6_CFG2_DVOL_M97dB												((uint8_t) 0x07)
    #define CH6_CFG2_DVOL_M96P5dB											((uint8_t) 0x08)
    #define CH6_CFG2_DVOL_M96dB												((uint8_t) 0x09)
    #define CH6_CFG2_DVOL_M95P5dB											((uint8_t) 0x0A)
    #define CH6_CFG2_DVOL_M95dB												((uint8_t) 0x0B)
    #define CH6_CFG2_DVOL_M94P5dB											((uint8_t) 0x0C)
    #define CH6_CFG2_DVOL_M94dB												((uint8_t) 0x0D)
    #define CH6_CFG2_DVOL_M93P5dB											((uint8_t) 0x0E)
    #define CH6_CFG2_DVOL_M93dB												((uint8_t) 0x0F)
    #define CH6_CFG2_DVOL_M92P5dB											((uint8_t) 0x10)
    #define CH6_CFG2_DVOL_M92dB												((uint8_t) 0x11)
    #define CH6_CFG2_DVOL_M91P5dB											((uint8_t) 0x12)
    #define CH6_CFG2_DVOL_M91dB												((uint8_t) 0x13)
    #define CH6_CFG2_DVOL_M90P5dB											((uint8_t) 0x14)
    #define CH6_CFG2_DVOL_M90dB												((uint8_t) 0x15)
    #define CH6_CFG2_DVOL_M89P5dB											((uint8_t) 0x16)
    #define CH6_CFG2_DVOL_M89dB												((uint8_t) 0x17)
    #define CH6_CFG2_DVOL_M88P5dB											((uint8_t) 0x18)
    #define CH6_CFG2_DVOL_M88dB												((uint8_t) 0x19)
    #define CH6_CFG2_DVOL_M87P5dB											((uint8_t) 0x1A)
    #define CH6_CFG2_DVOL_M87dB												((uint8_t) 0x1B)
    #define CH6_CFG2_DVOL_M86P5dB											((uint8_t) 0x1C)
    #define CH6_CFG2_DVOL_M86dB												((uint8_t) 0x1D)
    #define CH6_CFG2_DVOL_M85P5dB											((uint8_t) 0x1E)
    #define CH6_CFG2_DVOL_M85dB												((uint8_t) 0x1F)
    #define CH6_CFG2_DVOL_M84P5dB											((uint8_t) 0x20)
    #define CH6_CFG2_DVOL_M84dB												((uint8_t) 0x21)
    #define CH6_CFG2_DVOL_M83P5dB											((uint8_t) 0x22)
    #define CH6_CFG2_DVOL_M83dB												((uint8_t) 0x23)
    #define CH6_CFG2_DVOL_M82P5dB											((uint8_t) 0x24)
    #define CH6_CFG2_DVOL_M82dB												((uint8_t) 0x25)
    #define CH6_CFG2_DVOL_M81P5dB											((uint8_t) 0x26)
    #define CH6_CFG2_DVOL_M81dB												((uint8_t) 0x27)
    #define CH6_CFG2_DVOL_M80P5dB											((uint8_t) 0x28)
    #define CH6_CFG2_DVOL_M80dB												((uint8_t) 0x29)
    #define CH6_CFG2_DVOL_M79P5dB											((uint8_t) 0x2A)
    #define CH6_CFG2_DVOL_M79dB												((uint8_t) 0x2B)
    #define CH6_CFG2_DVOL_M78P5dB											((uint8_t) 0x2C)
    #define CH6_CFG2_DVOL_M78dB												((uint8_t) 0x2D)
    #define CH6_CFG2_DVOL_M77P5dB											((uint8_t) 0x2E)
    #define CH6_CFG2_DVOL_M77dB												((uint8_t) 0x2F)
    #define CH6_CFG2_DVOL_M76P5dB											((uint8_t) 0x30)
    #define CH6_CFG2_DVOL_M76dB												((uint8_t) 0x31)
    #define CH6_CFG2_DVOL_M75P5dB											((uint8_t) 0x32)
    #define CH6_CFG2_DVOL_M75dB												((uint8_t) 0x33)
    #define CH6_CFG2_DVOL_M74P5dB											((uint8_t) 0x34)
    #define CH6_CFG2_DVOL_M74dB												((uint8_t) 0x35)
    #define CH6_CFG2_DVOL_M73P5dB											((uint8_t) 0x36)
    #define CH6_CFG2_DVOL_M73dB												((uint8_t) 0x37)
    #define CH6_CFG2_DVOL_M72P5dB											((uint8_t) 0x38)
    #define CH6_CFG2_DVOL_M72dB												((uint8_t) 0x39)
    #define CH6_CFG2_DVOL_M71P5dB											((uint8_t) 0x3A)
    #define CH6_CFG2_DVOL_M71dB												((uint8_t) 0x3B)
    #define CH6_CFG2_DVOL_M70P5dB											((uint8_t) 0x3C)
    #define CH6_CFG2_DVOL_M70dB												((uint8_t) 0x3D)
    #define CH6_CFG2_DVOL_M69P5dB											((uint8_t) 0x3E)
    #define CH6_CFG2_DVOL_M69dB												((uint8_t) 0x3F)
    #define CH6_CFG2_DVOL_M68P5dB											((uint8_t) 0x40)
    #define CH6_CFG2_DVOL_M68dB												((uint8_t) 0x41)
    #define CH6_CFG2_DVOL_M67P5dB											((uint8_t) 0x42)
    #define CH6_CFG2_DVOL_M67dB												((uint8_t) 0x43)
    #define CH6_CFG2_DVOL_M66P5dB											((uint8_t) 0x44)
    #define CH6_CFG2_DVOL_M66dB												((uint8_t) 0x45)
    #define CH6_CFG2_DVOL_M65P5dB											((uint8_t) 0x46)
    #define CH6_CFG2_DVOL_M65dB												((uint8_t) 0x47)
    #define CH6_CFG2_DVOL_M64P5dB											((uint8_t) 0x48)
    #define CH6_CFG2_DVOL_M64dB												((uint8_t) 0x49)
    #define CH6_CFG2_DVOL_M63P5dB											((uint8_t) 0x4A)
    #define CH6_CFG2_DVOL_M63dB												((uint8_t) 0x4B)
    #define CH6_CFG2_DVOL_M62P5dB											((uint8_t) 0x4C)
    #define CH6_CFG2_DVOL_M62dB												((uint8_t) 0x4D)
    #define CH6_CFG2_DVOL_M61P5dB											((uint8_t) 0x4E)
    #define CH6_CFG2_DVOL_M61dB												((uint8_t) 0x4F)
    #define CH6_CFG2_DVOL_M60P5dB											((uint8_t) 0x50)
    #define CH6_CFG2_DVOL_M60dB												((uint8_t) 0x51)
    #define CH6_CFG2_DVOL_M59P5dB											((uint8_t) 0x52)
    #define CH6_CFG2_DVOL_M59dB												((uint8_t) 0x53)
    #define CH6_CFG2_DVOL_M58P5dB											((uint8_t) 0x54)
    #define CH6_CFG2_DVOL_M58dB												((uint8_t) 0x55)
    #define CH6_CFG2_DVOL_M57P5dB											((uint8_t) 0x56)
    #define CH6_CFG2_DVOL_M57dB												((uint8_t) 0x57)
    #define CH6_CFG2_DVOL_M56P5dB											((uint8_t) 0x58)
    #define CH6_CFG2_DVOL_M56dB												((uint8_t) 0x59)
    #define CH6_CFG2_DVOL_M55P5dB											((uint8_t) 0x5A)
    #define CH6_CFG2_DVOL_M55dB												((uint8_t) 0x5B)
    #define CH6_CFG2_DVOL_M54P5dB											((uint8_t) 0x5C)
    #define CH6_CFG2_DVOL_M54dB												((uint8_t) 0x5D)
    #define CH6_CFG2_DVOL_M53P5dB											((uint8_t) 0x5E)
    #define CH6_CFG2_DVOL_M53dB												((uint8_t) 0x5F)
    #define CH6_CFG2_DVOL_M52P5dB											((uint8_t) 0x60)
    #define CH6_CFG2_DVOL_M52dB												((uint8_t) 0x61)
    #define CH6_CFG2_DVOL_M51P5dB											((uint8_t) 0x62)
    #define CH6_CFG2_DVOL_M51dB												((uint8_t) 0x63)
    #define CH6_CFG2_DVOL_M50P5dB											((uint8_t) 0x64)
    #define CH6_CFG2_DVOL_M50dB												((uint8_t) 0x65)
    #define CH6_CFG2_DVOL_M49P5dB											((uint8_t) 0x66)
    #define CH6_CFG2_DVOL_M49dB												((uint8_t) 0x67)
    #define CH6_CFG2_DVOL_M48P5dB											((uint8_t) 0x68)
    #define CH6_CFG2_DVOL_M48dB												((uint8_t) 0x69)
    #define CH6_CFG2_DVOL_M47P5dB											((uint8_t) 0x6A)
    #define CH6_CFG2_DVOL_M47dB												((uint8_t) 0x6B)
    #define CH6_CFG2_DVOL_M46P5dB											((uint8_t) 0x6C)
    #define CH6_CFG2_DVOL_M46dB												((uint8_t) 0x6D)
    #define CH6_CFG2_DVOL_M45P5dB											((uint8_t) 0x6E)
    #define CH6_CFG2_DVOL_M45dB												((uint8_t) 0x6F)
    #define CH6_CFG2_DVOL_M44P5dB											((uint8_t) 0x70)
    #define CH6_CFG2_DVOL_M44dB												((uint8_t) 0x71)
    #define CH6_CFG2_DVOL_M43P5dB											((uint8_t) 0x72)
    #define CH6_CFG2_DVOL_M43dB												((uint8_t) 0x73)
    #define CH6_CFG2_DVOL_M42P5dB											((uint8_t) 0x74)
    #define CH6_CFG2_DVOL_M42dB												((uint8_t) 0x75)
    #define CH6_CFG2_DVOL_M41P5dB											((uint8_t) 0x76)
    #define CH6_CFG2_DVOL_M41dB												((uint8_t) 0x77)
    #define CH6_CFG2_DVOL_M40P5dB											((uint8_t) 0x78)
    #define CH6_CFG2_DVOL_M40dB												((uint8_t) 0x79)
    #define CH6_CFG2_DVOL_M39P5dB											((uint8_t) 0x7A)
    #define CH6_CFG2_DVOL_M39dB												((uint8_t) 0x7B)
    #define CH6_CFG2_DVOL_M38P5dB											((uint8_t) 0x7C)
    #define CH6_CFG2_DVOL_M38dB												((uint8_t) 0x7D)
    #define CH6_CFG2_DVOL_M37P5dB											((uint8_t) 0x7E)
    #define CH6_CFG2_DVOL_M37dB												((uint8_t) 0x7F)
    #define CH6_CFG2_DVOL_M36P5dB											((uint8_t) 0x80)
    #define CH6_CFG2_DVOL_M36dB												((uint8_t) 0x81)
    #define CH6_CFG2_DVOL_M35P5dB											((uint8_t) 0x82)
    #define CH6_CFG2_DVOL_M35dB												((uint8_t) 0x83)
    #define CH6_CFG2_DVOL_M34P5dB											((uint8_t) 0x84)
    #define CH6_CFG2_DVOL_M34dB												((uint8_t) 0x85)
    #define CH6_CFG2_DVOL_M33P5dB											((uint8_t) 0x86)
    #define CH6_CFG2_DVOL_M33dB												((uint8_t) 0x87)
    #define CH6_CFG2_DVOL_M32P5dB											((uint8_t) 0x88)
    #define CH6_CFG2_DVOL_M32dB												((uint8_t) 0x89)
    #define CH6_CFG2_DVOL_M31P5dB											((uint8_t) 0x8A)
    #define CH6_CFG2_DVOL_M31dB												((uint8_t) 0x8B)
    #define CH6_CFG2_DVOL_M30P5dB											((uint8_t) 0x8C)
    #define CH6_CFG2_DVOL_M30dB												((uint8_t) 0x8D)
    #define CH6_CFG2_DVOL_M29P5dB											((uint8_t) 0x8E)
    #define CH6_CFG2_DVOL_M29dB												((uint8_t) 0x8F)
    #define CH6_CFG2_DVOL_M28P5dB											((uint8_t) 0x90)
    #define CH6_CFG2_DVOL_M28dB												((uint8_t) 0x91)
    #define CH6_CFG2_DVOL_M27P5dB											((uint8_t) 0x92)
    #define CH6_CFG2_DVOL_M27dB												((uint8_t) 0x93)
    #define CH6_CFG2_DVOL_M26P5dB											((uint8_t) 0x94)
    #define CH6_CFG2_DVOL_M26dB												((uint8_t) 0x95)
    #define CH6_CFG2_DVOL_M25P5dB											((uint8_t) 0x96)
    #define CH6_CFG2_DVOL_M25dB												((uint8_t) 0x97)
    #define CH6_CFG2_DVOL_M24P5dB											((uint8_t) 0x98)
    #define CH6_CFG2_DVOL_M24dB												((uint8_t) 0x99)
    #define CH6_CFG2_DVOL_M23P5dB											((uint8_t) 0x9A)
    #define CH6_CFG2_DVOL_M23dB												((uint8_t) 0x9B)
    #define CH6_CFG2_DVOL_M22P5dB											((uint8_t) 0x9C)
    #define CH6_CFG2_DVOL_M22dB												((uint8_t) 0x9D)
    #define CH6_CFG2_DVOL_M21P5dB											((uint8_t) 0x9E)
    #define CH6_CFG2_DVOL_M21dB												((uint8_t) 0x9F)
    #define CH6_CFG2_DVOL_M20P5dB											((uint8_t) 0xA0)
    #define CH6_CFG2_DVOL_M20dB												((uint8_t) 0xA1)
    #define CH6_CFG2_DVOL_M19P5dB											((uint8_t) 0xA2)
    #define CH6_CFG2_DVOL_M19dB												((uint8_t) 0xA3)
    #define CH6_CFG2_DVOL_M18P5dB											((uint8_t) 0xA4)
    #define CH6_CFG2_DVOL_M18dB												((uint8_t) 0xA5)
    #define CH6_CFG2_DVOL_M17P5dB											((uint8_t) 0xA6)
    #define CH6_CFG2_DVOL_M17dB												((uint8_t) 0xA7)
    #define CH6_CFG2_DVOL_M16P5dB											((uint8_t) 0xA8)
    #define CH6_CFG2_DVOL_M16dB												((uint8_t) 0xA9)
    #define CH6_CFG2_DVOL_M15P5dB											((uint8_t) 0xAA)
    #define CH6_CFG2_DVOL_M15dB												((uint8_t) 0xAB)
    #define CH6_CFG2_DVOL_M14P5dB											((uint8_t) 0xAC)
    #define CH6_CFG2_DVOL_M14dB												((uint8_t) 0xAD)
    #define CH6_CFG2_DVOL_M13P5dB											((uint8_t) 0xAE)
    #define CH6_CFG2_DVOL_M13dB												((uint8_t) 0xAF)
    #define CH6_CFG2_DVOL_M12P5dB											((uint8_t) 0xB0)
    #define CH6_CFG2_DVOL_M12dB												((uint8_t) 0xB1)
    #define CH6_CFG2_DVOL_M11P5dB											((uint8_t) 0xB2)
    #define CH6_CFG2_DVOL_M11dB												((uint8_t) 0xB3)
    #define CH6_CFG2_DVOL_M10P5dB											((uint8_t) 0xB4)
    #define CH6_CFG2_DVOL_M10dB												((uint8_t) 0xB5)
    #define CH6_CFG2_DVOL_M9P5dB											((uint8_t) 0xB6)
    #define CH6_CFG2_DVOL_M9dB												((uint8_t) 0xB7)
    #define CH6_CFG2_DVOL_M8P5dB											((uint8_t) 0xB8)
    #define CH6_CFG2_DVOL_M8dB												((uint8_t) 0xB9)
    #define CH6_CFG2_DVOL_M7P5dB											((uint8_t) 0xBA)
    #define CH6_CFG2_DVOL_M7dB												((uint8_t) 0xBB)
    #define CH6_CFG2_DVOL_M6P5dB											((uint8_t) 0xBC)
    #define CH6_CFG2_DVOL_M6dB												((uint8_t) 0xBD)
    #define CH6_CFG2_DVOL_M5P5dB											((uint8_t) 0xBE)
    #define CH6_CFG2_DVOL_M5dB												((uint8_t) 0xBF)
    #define CH6_CFG2_DVOL_M4P5dB											((uint8_t) 0xC0)
    #define CH6_CFG2_DVOL_M4dB												((uint8_t) 0xC1)
    #define CH6_CFG2_DVOL_M3P5dB											((uint8_t) 0xC2)
    #define CH6_CFG2_DVOL_M3dB												((uint8_t) 0xC3)
    #define CH6_CFG2_DVOL_M2P5dB											((uint8_t) 0xC4)
    #define CH6_CFG2_DVOL_M2dB												((uint8_t) 0xC5)
    #define CH6_CFG2_DVOL_M1P5dB											((uint8_t) 0xC6)
    #define CH6_CFG2_DVOL_M1dB												((uint8_t) 0xC7)
    #define CH6_CFG2_DVOL_M0P5dB											((uint8_t) 0xC8)
    #define CH6_CFG2_DVOL_0dB												((uint8_t) 0xC9)    // DEFAULT
    #define CH6_CFG2_DVOL_0P5dB												((uint8_t) 0xCA)
    #define CH6_CFG2_DVOL_1dB												((uint8_t) 0xCB)
    #define CH6_CFG2_DVOL_1P5dB												((uint8_t) 0xCC)
    #define CH6_CFG2_DVOL_2dB												((uint8_t) 0xCD)
    #define CH6_CFG2_DVOL_2P5dB												((uint8_t) 0xCE)
    #define CH6_CFG2_DVOL_3dB												((uint8_t) 0xCF)
    #define CH6_CFG2_DVOL_3P5dB												((uint8_t) 0xD0)
    #define CH6_CFG2_DVOL_4dB												((uint8_t) 0xD1)
    #define CH6_CFG2_DVOL_4P5dB												((uint8_t) 0xD2)
    #define CH6_CFG2_DVOL_5dB												((uint8_t) 0xD3)
    #define CH6_CFG2_DVOL_5P5dB												((uint8_t) 0xD4)
    #define CH6_CFG2_DVOL_6dB												((uint8_t) 0xD5)
    #define CH6_CFG2_DVOL_6P5dB												((uint8_t) 0xD6)
    #define CH6_CFG2_DVOL_7dB												((uint8_t) 0xD7)
    #define CH6_CFG2_DVOL_7P5dB												((uint8_t) 0xD8)
    #define CH6_CFG2_DVOL_8dB												((uint8_t) 0xD9)
    #define CH6_CFG2_DVOL_8P5dB												((uint8_t) 0xDA)
    #define CH6_CFG2_DVOL_9dB												((uint8_t) 0xDB)
    #define CH6_CFG2_DVOL_9P5dB												((uint8_t) 0xDC)
    #define CH6_CFG2_DVOL_10dB												((uint8_t) 0xDD)
    #define CH6_CFG2_DVOL_10P5dB											((uint8_t) 0xDE)
    #define CH6_CFG2_DVOL_11dB												((uint8_t) 0xDF)
    #define CH6_CFG2_DVOL_11P5dB											((uint8_t) 0xE0)
    #define CH6_CFG2_DVOL_12dB												((uint8_t) 0xE1)
    #define CH6_CFG2_DVOL_12P5dB											((uint8_t) 0xE2)
    #define CH6_CFG2_DVOL_13dB												((uint8_t) 0xE3)
    #define CH6_CFG2_DVOL_13P5dB											((uint8_t) 0xE4)
    #define CH6_CFG2_DVOL_14dB												((uint8_t) 0xE5)
    #define CH6_CFG2_DVOL_14P5dB											((uint8_t) 0xE6)
    #define CH6_CFG2_DVOL_15dB												((uint8_t) 0xE7)
    #define CH6_CFG2_DVOL_15P5dB											((uint8_t) 0xE8)
    #define CH6_CFG2_DVOL_16dB												((uint8_t) 0xE9)
    #define CH6_CFG2_DVOL_16P5dB											((uint8_t) 0xEA)
    #define CH6_CFG2_DVOL_17dB												((uint8_t) 0xEB)
    #define CH6_CFG2_DVOL_17P5dB											((uint8_t) 0xEC)
    #define CH6_CFG2_DVOL_18dB												((uint8_t) 0xED)
    #define CH6_CFG2_DVOL_18P5dB											((uint8_t) 0xEE)
    #define CH6_CFG2_DVOL_19dB												((uint8_t) 0xEF)
    #define CH6_CFG2_DVOL_19P5dB											((uint8_t) 0xF0)
    #define CH6_CFG2_DVOL_20dB												((uint8_t) 0xF1)
    #define CH6_CFG2_DVOL_20P5dB											((uint8_t) 0xF2)
    #define CH6_CFG2_DVOL_21dB												((uint8_t) 0xF3)
    #define CH6_CFG2_DVOL_21P5dB											((uint8_t) 0xF4)
    #define CH6_CFG2_DVOL_22dB												((uint8_t) 0xF5)
    #define CH6_CFG2_DVOL_22P5dB											((uint8_t) 0xF6)
    #define CH6_CFG2_DVOL_23dB												((uint8_t) 0xF7)
    #define CH6_CFG2_DVOL_23P5dB											((uint8_t) 0xF8)
    #define CH6_CFG2_DVOL_24dB												((uint8_t) 0xF9)
    #define CH6_CFG2_DVOL_24P5dB											((uint8_t) 0xFA)
    #define CH6_CFG2_DVOL_25dB												((uint8_t) 0xFB)
    #define CH6_CFG2_DVOL_25P5dB											((uint8_t) 0xFC)
    #define CH6_CFG2_DVOL_26dB												((uint8_t) 0xFD)
    #define CH6_CFG2_DVOL_26P5dB											((uint8_t) 0xFE)
    #define CH6_CFG2_DVOL_27dB												((uint8_t) 0xFF)



/* Register 0x58 (CH6_CFG3) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                       GCAL[3:0]                                       |                                     RESERVED[3:0]                                     |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH6_CFG3 register */
    #define CH6_CFG3_ADDRESS												((uint8_t) 0x58)
    #define CH6_CFG3_DEFAULT												((uint8_t) 0x80)

    /* GCAL field */
    #define CH6_CFG3_GCAL_MASK												((uint8_t) 0xF0)
    #define CH6_CFG3_GCAL_M0P8dB											((uint8_t) 0x00)
    #define CH6_CFG3_GCAL_M0P7dB											((uint8_t) 0x10)
    #define CH6_CFG3_GCAL_M0P6dB											((uint8_t) 0x20)
    #define CH6_CFG3_GCAL_M0P5dB											((uint8_t) 0x30)
    #define CH6_CFG3_GCAL_M0P4dB											((uint8_t) 0x40)
    #define CH6_CFG3_GCAL_M0P3dB											((uint8_t) 0x50)
    #define CH6_CFG3_GCAL_M0P2dB											((uint8_t) 0x60)
    #define CH6_CFG3_GCAL_M0P1dB											((uint8_t) 0x70)
    #define CH6_CFG3_GCAL_0dB												((uint8_t) 0x80)    // DEFAULT
    #define CH6_CFG3_GCAL_0P1dB												((uint8_t) 0x90)
    #define CH6_CFG3_GCAL_0P2dB												((uint8_t) 0xA0)
    #define CH6_CFG3_GCAL_0P3dB												((uint8_t) 0xB0)
    #define CH6_CFG3_GCAL_0P4dB												((uint8_t) 0xC0)
    #define CH6_CFG3_GCAL_0P5dB												((uint8_t) 0xD0)
    #define CH6_CFG3_GCAL_0P6dB												((uint8_t) 0xE0)
    #define CH6_CFG3_GCAL_0P7dB												((uint8_t) 0xF0)



/* Register 0x59 (CH6_CFG4) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                                                   PCAL[7:0]                                                                                   |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH6_CFG4 register */
    #define CH6_CFG4_ADDRESS												((uint8_t) 0x59)
    #define CH6_CFG4_DEFAULT												((uint8_t) 0x00)

    /* PCAL field */
    #define CH6_CFG4_PCAL_MASK												((uint8_t) 0xFF)
    #define CH6_CFG4_PCAL_0													((uint8_t) 0x00)    // DEFAULT
    #define CH6_CFG4_PCAL_1													((uint8_t) 0x01)
    #define CH6_CFG4_PCAL_2													((uint8_t) 0x02)
    #define CH6_CFG4_PCAL_3													((uint8_t) 0x03)
    #define CH6_CFG4_PCAL_4													((uint8_t) 0x04)
    #define CH6_CFG4_PCAL_5													((uint8_t) 0x05)
    #define CH6_CFG4_PCAL_6													((uint8_t) 0x06)
    #define CH6_CFG4_PCAL_7													((uint8_t) 0x07)
    #define CH6_CFG4_PCAL_8													((uint8_t) 0x08)
    #define CH6_CFG4_PCAL_9													((uint8_t) 0x09)
    #define CH6_CFG4_PCAL_10												((uint8_t) 0x0A)
    #define CH6_CFG4_PCAL_11												((uint8_t) 0x0B)
    #define CH6_CFG4_PCAL_12												((uint8_t) 0x0C)
    #define CH6_CFG4_PCAL_13												((uint8_t) 0x0D)
    #define CH6_CFG4_PCAL_14												((uint8_t) 0x0E)
    #define CH6_CFG4_PCAL_15												((uint8_t) 0x0F)
    #define CH6_CFG4_PCAL_16												((uint8_t) 0x10)
    #define CH6_CFG4_PCAL_17												((uint8_t) 0x11)
    #define CH6_CFG4_PCAL_18												((uint8_t) 0x12)
    #define CH6_CFG4_PCAL_19												((uint8_t) 0x13)
    #define CH6_CFG4_PCAL_20												((uint8_t) 0x14)
    #define CH6_CFG4_PCAL_21												((uint8_t) 0x15)
    #define CH6_CFG4_PCAL_22												((uint8_t) 0x16)
    #define CH6_CFG4_PCAL_23												((uint8_t) 0x17)
    #define CH6_CFG4_PCAL_24												((uint8_t) 0x18)
    #define CH6_CFG4_PCAL_25												((uint8_t) 0x19)
    #define CH6_CFG4_PCAL_26												((uint8_t) 0x1A)
    #define CH6_CFG4_PCAL_27												((uint8_t) 0x1B)
    #define CH6_CFG4_PCAL_28												((uint8_t) 0x1C)
    #define CH6_CFG4_PCAL_29												((uint8_t) 0x1D)
    #define CH6_CFG4_PCAL_30												((uint8_t) 0x1E)
    #define CH6_CFG4_PCAL_31												((uint8_t) 0x1F)
    #define CH6_CFG4_PCAL_32												((uint8_t) 0x20)
    #define CH6_CFG4_PCAL_33												((uint8_t) 0x21)
    #define CH6_CFG4_PCAL_34												((uint8_t) 0x22)
    #define CH6_CFG4_PCAL_35												((uint8_t) 0x23)
    #define CH6_CFG4_PCAL_36												((uint8_t) 0x24)
    #define CH6_CFG4_PCAL_37												((uint8_t) 0x25)
    #define CH6_CFG4_PCAL_38												((uint8_t) 0x26)
    #define CH6_CFG4_PCAL_39												((uint8_t) 0x27)
    #define CH6_CFG4_PCAL_40												((uint8_t) 0x28)
    #define CH6_CFG4_PCAL_41												((uint8_t) 0x29)
    #define CH6_CFG4_PCAL_42												((uint8_t) 0x2A)
    #define CH6_CFG4_PCAL_43												((uint8_t) 0x2B)
    #define CH6_CFG4_PCAL_44												((uint8_t) 0x2C)
    #define CH6_CFG4_PCAL_45												((uint8_t) 0x2D)
    #define CH6_CFG4_PCAL_46												((uint8_t) 0x2E)
    #define CH6_CFG4_PCAL_47												((uint8_t) 0x2F)
    #define CH6_CFG4_PCAL_48												((uint8_t) 0x30)
    #define CH6_CFG4_PCAL_49												((uint8_t) 0x31)
    #define CH6_CFG4_PCAL_50												((uint8_t) 0x32)
    #define CH6_CFG4_PCAL_51												((uint8_t) 0x33)
    #define CH6_CFG4_PCAL_52												((uint8_t) 0x34)
    #define CH6_CFG4_PCAL_53												((uint8_t) 0x35)
    #define CH6_CFG4_PCAL_54												((uint8_t) 0x36)
    #define CH6_CFG4_PCAL_55												((uint8_t) 0x37)
    #define CH6_CFG4_PCAL_56												((uint8_t) 0x38)
    #define CH6_CFG4_PCAL_57												((uint8_t) 0x39)
    #define CH6_CFG4_PCAL_58												((uint8_t) 0x3A)
    #define CH6_CFG4_PCAL_59												((uint8_t) 0x3B)
    #define CH6_CFG4_PCAL_60												((uint8_t) 0x3C)
    #define CH6_CFG4_PCAL_61												((uint8_t) 0x3D)
    #define CH6_CFG4_PCAL_62												((uint8_t) 0x3E)
    #define CH6_CFG4_PCAL_63												((uint8_t) 0x3F)
    #define CH6_CFG4_PCAL_64												((uint8_t) 0x40)
    #define CH6_CFG4_PCAL_65												((uint8_t) 0x41)
    #define CH6_CFG4_PCAL_66												((uint8_t) 0x42)
    #define CH6_CFG4_PCAL_67												((uint8_t) 0x43)
    #define CH6_CFG4_PCAL_68												((uint8_t) 0x44)
    #define CH6_CFG4_PCAL_69												((uint8_t) 0x45)
    #define CH6_CFG4_PCAL_70												((uint8_t) 0x46)
    #define CH6_CFG4_PCAL_71												((uint8_t) 0x47)
    #define CH6_CFG4_PCAL_72												((uint8_t) 0x48)
    #define CH6_CFG4_PCAL_73												((uint8_t) 0x49)
    #define CH6_CFG4_PCAL_74												((uint8_t) 0x4A)
    #define CH6_CFG4_PCAL_75												((uint8_t) 0x4B)
    #define CH6_CFG4_PCAL_76												((uint8_t) 0x4C)
    #define CH6_CFG4_PCAL_77												((uint8_t) 0x4D)
    #define CH6_CFG4_PCAL_78												((uint8_t) 0x4E)
    #define CH6_CFG4_PCAL_79												((uint8_t) 0x4F)
    #define CH6_CFG4_PCAL_80												((uint8_t) 0x50)
    #define CH6_CFG4_PCAL_81												((uint8_t) 0x51)
    #define CH6_CFG4_PCAL_82												((uint8_t) 0x52)
    #define CH6_CFG4_PCAL_83												((uint8_t) 0x53)
    #define CH6_CFG4_PCAL_84												((uint8_t) 0x54)
    #define CH6_CFG4_PCAL_85												((uint8_t) 0x55)
    #define CH6_CFG4_PCAL_86												((uint8_t) 0x56)
    #define CH6_CFG4_PCAL_87												((uint8_t) 0x57)
    #define CH6_CFG4_PCAL_88												((uint8_t) 0x58)
    #define CH6_CFG4_PCAL_89												((uint8_t) 0x59)
    #define CH6_CFG4_PCAL_90												((uint8_t) 0x5A)
    #define CH6_CFG4_PCAL_91												((uint8_t) 0x5B)
    #define CH6_CFG4_PCAL_92												((uint8_t) 0x5C)
    #define CH6_CFG4_PCAL_93												((uint8_t) 0x5D)
    #define CH6_CFG4_PCAL_94												((uint8_t) 0x5E)
    #define CH6_CFG4_PCAL_95												((uint8_t) 0x5F)
    #define CH6_CFG4_PCAL_96												((uint8_t) 0x60)
    #define CH6_CFG4_PCAL_97												((uint8_t) 0x61)
    #define CH6_CFG4_PCAL_98												((uint8_t) 0x62)
    #define CH6_CFG4_PCAL_99												((uint8_t) 0x63)
    #define CH6_CFG4_PCAL_100												((uint8_t) 0x64)
    #define CH6_CFG4_PCAL_101												((uint8_t) 0x65)
    #define CH6_CFG4_PCAL_102												((uint8_t) 0x66)
    #define CH6_CFG4_PCAL_103												((uint8_t) 0x67)
    #define CH6_CFG4_PCAL_104												((uint8_t) 0x68)
    #define CH6_CFG4_PCAL_105												((uint8_t) 0x69)
    #define CH6_CFG4_PCAL_106												((uint8_t) 0x6A)
    #define CH6_CFG4_PCAL_107												((uint8_t) 0x6B)
    #define CH6_CFG4_PCAL_108												((uint8_t) 0x6C)
    #define CH6_CFG4_PCAL_109												((uint8_t) 0x6D)
    #define CH6_CFG4_PCAL_110												((uint8_t) 0x6E)
    #define CH6_CFG4_PCAL_111												((uint8_t) 0x6F)
    #define CH6_CFG4_PCAL_112												((uint8_t) 0x70)
    #define CH6_CFG4_PCAL_113												((uint8_t) 0x71)
    #define CH6_CFG4_PCAL_114												((uint8_t) 0x72)
    #define CH6_CFG4_PCAL_115												((uint8_t) 0x73)
    #define CH6_CFG4_PCAL_116												((uint8_t) 0x74)
    #define CH6_CFG4_PCAL_117												((uint8_t) 0x75)
    #define CH6_CFG4_PCAL_118												((uint8_t) 0x76)
    #define CH6_CFG4_PCAL_119												((uint8_t) 0x77)
    #define CH6_CFG4_PCAL_120												((uint8_t) 0x78)
    #define CH6_CFG4_PCAL_121												((uint8_t) 0x79)
    #define CH6_CFG4_PCAL_122												((uint8_t) 0x7A)
    #define CH6_CFG4_PCAL_123												((uint8_t) 0x7B)
    #define CH6_CFG4_PCAL_124												((uint8_t) 0x7C)
    #define CH6_CFG4_PCAL_125												((uint8_t) 0x7D)
    #define CH6_CFG4_PCAL_126												((uint8_t) 0x7E)
    #define CH6_CFG4_PCAL_127												((uint8_t) 0x7F)
    #define CH6_CFG4_PCAL_128												((uint8_t) 0x80)
    #define CH6_CFG4_PCAL_129												((uint8_t) 0x81)
    #define CH6_CFG4_PCAL_130												((uint8_t) 0x82)
    #define CH6_CFG4_PCAL_131												((uint8_t) 0x83)
    #define CH6_CFG4_PCAL_132												((uint8_t) 0x84)
    #define CH6_CFG4_PCAL_133												((uint8_t) 0x85)
    #define CH6_CFG4_PCAL_134												((uint8_t) 0x86)
    #define CH6_CFG4_PCAL_135												((uint8_t) 0x87)
    #define CH6_CFG4_PCAL_136												((uint8_t) 0x88)
    #define CH6_CFG4_PCAL_137												((uint8_t) 0x89)
    #define CH6_CFG4_PCAL_138												((uint8_t) 0x8A)
    #define CH6_CFG4_PCAL_139												((uint8_t) 0x8B)
    #define CH6_CFG4_PCAL_140												((uint8_t) 0x8C)
    #define CH6_CFG4_PCAL_141												((uint8_t) 0x8D)
    #define CH6_CFG4_PCAL_142												((uint8_t) 0x8E)
    #define CH6_CFG4_PCAL_143												((uint8_t) 0x8F)
    #define CH6_CFG4_PCAL_144												((uint8_t) 0x90)
    #define CH6_CFG4_PCAL_145												((uint8_t) 0x91)
    #define CH6_CFG4_PCAL_146												((uint8_t) 0x92)
    #define CH6_CFG4_PCAL_147												((uint8_t) 0x93)
    #define CH6_CFG4_PCAL_148												((uint8_t) 0x94)
    #define CH6_CFG4_PCAL_149												((uint8_t) 0x95)
    #define CH6_CFG4_PCAL_150												((uint8_t) 0x96)
    #define CH6_CFG4_PCAL_151												((uint8_t) 0x97)
    #define CH6_CFG4_PCAL_152												((uint8_t) 0x98)
    #define CH6_CFG4_PCAL_153												((uint8_t) 0x99)
    #define CH6_CFG4_PCAL_154												((uint8_t) 0x9A)
    #define CH6_CFG4_PCAL_155												((uint8_t) 0x9B)
    #define CH6_CFG4_PCAL_156												((uint8_t) 0x9C)
    #define CH6_CFG4_PCAL_157												((uint8_t) 0x9D)
    #define CH6_CFG4_PCAL_158												((uint8_t) 0x9E)
    #define CH6_CFG4_PCAL_159												((uint8_t) 0x9F)
    #define CH6_CFG4_PCAL_160												((uint8_t) 0xA0)
    #define CH6_CFG4_PCAL_161												((uint8_t) 0xA1)
    #define CH6_CFG4_PCAL_162												((uint8_t) 0xA2)
    #define CH6_CFG4_PCAL_163												((uint8_t) 0xA3)
    #define CH6_CFG4_PCAL_164												((uint8_t) 0xA4)
    #define CH6_CFG4_PCAL_165												((uint8_t) 0xA5)
    #define CH6_CFG4_PCAL_166												((uint8_t) 0xA6)
    #define CH6_CFG4_PCAL_167												((uint8_t) 0xA7)
    #define CH6_CFG4_PCAL_168												((uint8_t) 0xA8)
    #define CH6_CFG4_PCAL_169												((uint8_t) 0xA9)
    #define CH6_CFG4_PCAL_170												((uint8_t) 0xAA)
    #define CH6_CFG4_PCAL_171												((uint8_t) 0xAB)
    #define CH6_CFG4_PCAL_172												((uint8_t) 0xAC)
    #define CH6_CFG4_PCAL_173												((uint8_t) 0xAD)
    #define CH6_CFG4_PCAL_174												((uint8_t) 0xAE)
    #define CH6_CFG4_PCAL_175												((uint8_t) 0xAF)
    #define CH6_CFG4_PCAL_176												((uint8_t) 0xB0)
    #define CH6_CFG4_PCAL_177												((uint8_t) 0xB1)
    #define CH6_CFG4_PCAL_178												((uint8_t) 0xB2)
    #define CH6_CFG4_PCAL_179												((uint8_t) 0xB3)
    #define CH6_CFG4_PCAL_180												((uint8_t) 0xB4)
    #define CH6_CFG4_PCAL_181												((uint8_t) 0xB5)
    #define CH6_CFG4_PCAL_182												((uint8_t) 0xB6)
    #define CH6_CFG4_PCAL_183												((uint8_t) 0xB7)
    #define CH6_CFG4_PCAL_184												((uint8_t) 0xB8)
    #define CH6_CFG4_PCAL_185												((uint8_t) 0xB9)
    #define CH6_CFG4_PCAL_186												((uint8_t) 0xBA)
    #define CH6_CFG4_PCAL_187												((uint8_t) 0xBB)
    #define CH6_CFG4_PCAL_188												((uint8_t) 0xBC)
    #define CH6_CFG4_PCAL_189												((uint8_t) 0xBD)
    #define CH6_CFG4_PCAL_190												((uint8_t) 0xBE)
    #define CH6_CFG4_PCAL_191												((uint8_t) 0xBF)
    #define CH6_CFG4_PCAL_192												((uint8_t) 0xC0)
    #define CH6_CFG4_PCAL_193												((uint8_t) 0xC1)
    #define CH6_CFG4_PCAL_194												((uint8_t) 0xC2)
    #define CH6_CFG4_PCAL_195												((uint8_t) 0xC3)
    #define CH6_CFG4_PCAL_196												((uint8_t) 0xC4)
    #define CH6_CFG4_PCAL_197												((uint8_t) 0xC5)
    #define CH6_CFG4_PCAL_198												((uint8_t) 0xC6)
    #define CH6_CFG4_PCAL_199												((uint8_t) 0xC7)
    #define CH6_CFG4_PCAL_200												((uint8_t) 0xC8)
    #define CH6_CFG4_PCAL_201												((uint8_t) 0xC9)
    #define CH6_CFG4_PCAL_202												((uint8_t) 0xCA)
    #define CH6_CFG4_PCAL_203												((uint8_t) 0xCB)
    #define CH6_CFG4_PCAL_204												((uint8_t) 0xCC)
    #define CH6_CFG4_PCAL_205												((uint8_t) 0xCD)
    #define CH6_CFG4_PCAL_206												((uint8_t) 0xCE)
    #define CH6_CFG4_PCAL_207												((uint8_t) 0xCF)
    #define CH6_CFG4_PCAL_208												((uint8_t) 0xD0)
    #define CH6_CFG4_PCAL_209												((uint8_t) 0xD1)
    #define CH6_CFG4_PCAL_210												((uint8_t) 0xD2)
    #define CH6_CFG4_PCAL_211												((uint8_t) 0xD3)
    #define CH6_CFG4_PCAL_212												((uint8_t) 0xD4)
    #define CH6_CFG4_PCAL_213												((uint8_t) 0xD5)
    #define CH6_CFG4_PCAL_214												((uint8_t) 0xD6)
    #define CH6_CFG4_PCAL_215												((uint8_t) 0xD7)
    #define CH6_CFG4_PCAL_216												((uint8_t) 0xD8)
    #define CH6_CFG4_PCAL_217												((uint8_t) 0xD9)
    #define CH6_CFG4_PCAL_218												((uint8_t) 0xDA)
    #define CH6_CFG4_PCAL_219												((uint8_t) 0xDB)
    #define CH6_CFG4_PCAL_220												((uint8_t) 0xDC)
    #define CH6_CFG4_PCAL_221												((uint8_t) 0xDD)
    #define CH6_CFG4_PCAL_222												((uint8_t) 0xDE)
    #define CH6_CFG4_PCAL_223												((uint8_t) 0xDF)
    #define CH6_CFG4_PCAL_224												((uint8_t) 0xE0)
    #define CH6_CFG4_PCAL_225												((uint8_t) 0xE1)
    #define CH6_CFG4_PCAL_226												((uint8_t) 0xE2)
    #define CH6_CFG4_PCAL_227												((uint8_t) 0xE3)
    #define CH6_CFG4_PCAL_228												((uint8_t) 0xE4)
    #define CH6_CFG4_PCAL_229												((uint8_t) 0xE5)
    #define CH6_CFG4_PCAL_230												((uint8_t) 0xE6)
    #define CH6_CFG4_PCAL_231												((uint8_t) 0xE7)
    #define CH6_CFG4_PCAL_232												((uint8_t) 0xE8)
    #define CH6_CFG4_PCAL_233												((uint8_t) 0xE9)
    #define CH6_CFG4_PCAL_234												((uint8_t) 0xEA)
    #define CH6_CFG4_PCAL_235												((uint8_t) 0xEB)
    #define CH6_CFG4_PCAL_236												((uint8_t) 0xEC)
    #define CH6_CFG4_PCAL_237												((uint8_t) 0xED)
    #define CH6_CFG4_PCAL_238												((uint8_t) 0xEE)
    #define CH6_CFG4_PCAL_239												((uint8_t) 0xEF)
    #define CH6_CFG4_PCAL_240												((uint8_t) 0xF0)
    #define CH6_CFG4_PCAL_241												((uint8_t) 0xF1)
    #define CH6_CFG4_PCAL_242												((uint8_t) 0xF2)
    #define CH6_CFG4_PCAL_243												((uint8_t) 0xF3)
    #define CH6_CFG4_PCAL_244												((uint8_t) 0xF4)
    #define CH6_CFG4_PCAL_245												((uint8_t) 0xF5)
    #define CH6_CFG4_PCAL_246												((uint8_t) 0xF6)
    #define CH6_CFG4_PCAL_247												((uint8_t) 0xF7)
    #define CH6_CFG4_PCAL_248												((uint8_t) 0xF8)
    #define CH6_CFG4_PCAL_249												((uint8_t) 0xF9)
    #define CH6_CFG4_PCAL_250												((uint8_t) 0xFA)
    #define CH6_CFG4_PCAL_251												((uint8_t) 0xFB)
    #define CH6_CFG4_PCAL_252												((uint8_t) 0xFC)
    #define CH6_CFG4_PCAL_253												((uint8_t) 0xFD)
    #define CH6_CFG4_PCAL_254												((uint8_t) 0xFE)
    #define CH6_CFG4_PCAL_255												((uint8_t) 0xFF)



/* Register 0x5C (CH7_CFG2) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                                                   DVOL[7:0]                                                                                   |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH7_CFG2 register */
    #define CH7_CFG2_ADDRESS												((uint8_t) 0x5C)
    #define CH7_CFG2_DEFAULT												((uint8_t) 0xC9)

    /* DVOL field */
    #define CH7_CFG2_DVOL_MASK												((uint8_t) 0xFF)
    #define CH7_CFG2_DVOL_MUTE												((uint8_t) 0x00)
    #define CH7_CFG2_DVOL_M100dB											((uint8_t) 0x01)
    #define CH7_CFG2_DVOL_M99P5dB											((uint8_t) 0x02)
    #define CH7_CFG2_DVOL_M99dB												((uint8_t) 0x03)
    #define CH7_CFG2_DVOL_M98P5dB											((uint8_t) 0x04)
    #define CH7_CFG2_DVOL_M98dB												((uint8_t) 0x05)
    #define CH7_CFG2_DVOL_M97P5dB											((uint8_t) 0x06)
    #define CH7_CFG2_DVOL_M97dB												((uint8_t) 0x07)
    #define CH7_CFG2_DVOL_M96P5dB											((uint8_t) 0x08)
    #define CH7_CFG2_DVOL_M96dB												((uint8_t) 0x09)
    #define CH7_CFG2_DVOL_M95P5dB											((uint8_t) 0x0A)
    #define CH7_CFG2_DVOL_M95dB												((uint8_t) 0x0B)
    #define CH7_CFG2_DVOL_M94P5dB											((uint8_t) 0x0C)
    #define CH7_CFG2_DVOL_M94dB												((uint8_t) 0x0D)
    #define CH7_CFG2_DVOL_M93P5dB											((uint8_t) 0x0E)
    #define CH7_CFG2_DVOL_M93dB												((uint8_t) 0x0F)
    #define CH7_CFG2_DVOL_M92P5dB											((uint8_t) 0x10)
    #define CH7_CFG2_DVOL_M92dB												((uint8_t) 0x11)
    #define CH7_CFG2_DVOL_M91P5dB											((uint8_t) 0x12)
    #define CH7_CFG2_DVOL_M91dB												((uint8_t) 0x13)
    #define CH7_CFG2_DVOL_M90P5dB											((uint8_t) 0x14)
    #define CH7_CFG2_DVOL_M90dB												((uint8_t) 0x15)
    #define CH7_CFG2_DVOL_M89P5dB											((uint8_t) 0x16)
    #define CH7_CFG2_DVOL_M89dB												((uint8_t) 0x17)
    #define CH7_CFG2_DVOL_M88P5dB											((uint8_t) 0x18)
    #define CH7_CFG2_DVOL_M88dB												((uint8_t) 0x19)
    #define CH7_CFG2_DVOL_M87P5dB											((uint8_t) 0x1A)
    #define CH7_CFG2_DVOL_M87dB												((uint8_t) 0x1B)
    #define CH7_CFG2_DVOL_M86P5dB											((uint8_t) 0x1C)
    #define CH7_CFG2_DVOL_M86dB												((uint8_t) 0x1D)
    #define CH7_CFG2_DVOL_M85P5dB											((uint8_t) 0x1E)
    #define CH7_CFG2_DVOL_M85dB												((uint8_t) 0x1F)
    #define CH7_CFG2_DVOL_M84P5dB											((uint8_t) 0x20)
    #define CH7_CFG2_DVOL_M84dB												((uint8_t) 0x21)
    #define CH7_CFG2_DVOL_M83P5dB											((uint8_t) 0x22)
    #define CH7_CFG2_DVOL_M83dB												((uint8_t) 0x23)
    #define CH7_CFG2_DVOL_M82P5dB											((uint8_t) 0x24)
    #define CH7_CFG2_DVOL_M82dB												((uint8_t) 0x25)
    #define CH7_CFG2_DVOL_M81P5dB											((uint8_t) 0x26)
    #define CH7_CFG2_DVOL_M81dB												((uint8_t) 0x27)
    #define CH7_CFG2_DVOL_M80P5dB											((uint8_t) 0x28)
    #define CH7_CFG2_DVOL_M80dB												((uint8_t) 0x29)
    #define CH7_CFG2_DVOL_M79P5dB											((uint8_t) 0x2A)
    #define CH7_CFG2_DVOL_M79dB												((uint8_t) 0x2B)
    #define CH7_CFG2_DVOL_M78P5dB											((uint8_t) 0x2C)
    #define CH7_CFG2_DVOL_M78dB												((uint8_t) 0x2D)
    #define CH7_CFG2_DVOL_M77P5dB											((uint8_t) 0x2E)
    #define CH7_CFG2_DVOL_M77dB												((uint8_t) 0x2F)
    #define CH7_CFG2_DVOL_M76P5dB											((uint8_t) 0x30)
    #define CH7_CFG2_DVOL_M76dB												((uint8_t) 0x31)
    #define CH7_CFG2_DVOL_M75P5dB											((uint8_t) 0x32)
    #define CH7_CFG2_DVOL_M75dB												((uint8_t) 0x33)
    #define CH7_CFG2_DVOL_M74P5dB											((uint8_t) 0x34)
    #define CH7_CFG2_DVOL_M74dB												((uint8_t) 0x35)
    #define CH7_CFG2_DVOL_M73P5dB											((uint8_t) 0x36)
    #define CH7_CFG2_DVOL_M73dB												((uint8_t) 0x37)
    #define CH7_CFG2_DVOL_M72P5dB											((uint8_t) 0x38)
    #define CH7_CFG2_DVOL_M72dB												((uint8_t) 0x39)
    #define CH7_CFG2_DVOL_M71P5dB											((uint8_t) 0x3A)
    #define CH7_CFG2_DVOL_M71dB												((uint8_t) 0x3B)
    #define CH7_CFG2_DVOL_M70P5dB											((uint8_t) 0x3C)
    #define CH7_CFG2_DVOL_M70dB												((uint8_t) 0x3D)
    #define CH7_CFG2_DVOL_M69P5dB											((uint8_t) 0x3E)
    #define CH7_CFG2_DVOL_M69dB												((uint8_t) 0x3F)
    #define CH7_CFG2_DVOL_M68P5dB											((uint8_t) 0x40)
    #define CH7_CFG2_DVOL_M68dB												((uint8_t) 0x41)
    #define CH7_CFG2_DVOL_M67P5dB											((uint8_t) 0x42)
    #define CH7_CFG2_DVOL_M67dB												((uint8_t) 0x43)
    #define CH7_CFG2_DVOL_M66P5dB											((uint8_t) 0x44)
    #define CH7_CFG2_DVOL_M66dB												((uint8_t) 0x45)
    #define CH7_CFG2_DVOL_M65P5dB											((uint8_t) 0x46)
    #define CH7_CFG2_DVOL_M65dB												((uint8_t) 0x47)
    #define CH7_CFG2_DVOL_M64P5dB											((uint8_t) 0x48)
    #define CH7_CFG2_DVOL_M64dB												((uint8_t) 0x49)
    #define CH7_CFG2_DVOL_M63P5dB											((uint8_t) 0x4A)
    #define CH7_CFG2_DVOL_M63dB												((uint8_t) 0x4B)
    #define CH7_CFG2_DVOL_M62P5dB											((uint8_t) 0x4C)
    #define CH7_CFG2_DVOL_M62dB												((uint8_t) 0x4D)
    #define CH7_CFG2_DVOL_M61P5dB											((uint8_t) 0x4E)
    #define CH7_CFG2_DVOL_M61dB												((uint8_t) 0x4F)
    #define CH7_CFG2_DVOL_M60P5dB											((uint8_t) 0x50)
    #define CH7_CFG2_DVOL_M60dB												((uint8_t) 0x51)
    #define CH7_CFG2_DVOL_M59P5dB											((uint8_t) 0x52)
    #define CH7_CFG2_DVOL_M59dB												((uint8_t) 0x53)
    #define CH7_CFG2_DVOL_M58P5dB											((uint8_t) 0x54)
    #define CH7_CFG2_DVOL_M58dB												((uint8_t) 0x55)
    #define CH7_CFG2_DVOL_M57P5dB											((uint8_t) 0x56)
    #define CH7_CFG2_DVOL_M57dB												((uint8_t) 0x57)
    #define CH7_CFG2_DVOL_M56P5dB											((uint8_t) 0x58)
    #define CH7_CFG2_DVOL_M56dB												((uint8_t) 0x59)
    #define CH7_CFG2_DVOL_M55P5dB											((uint8_t) 0x5A)
    #define CH7_CFG2_DVOL_M55dB												((uint8_t) 0x5B)
    #define CH7_CFG2_DVOL_M54P5dB											((uint8_t) 0x5C)
    #define CH7_CFG2_DVOL_M54dB												((uint8_t) 0x5D)
    #define CH7_CFG2_DVOL_M53P5dB											((uint8_t) 0x5E)
    #define CH7_CFG2_DVOL_M53dB												((uint8_t) 0x5F)
    #define CH7_CFG2_DVOL_M52P5dB											((uint8_t) 0x60)
    #define CH7_CFG2_DVOL_M52dB												((uint8_t) 0x61)
    #define CH7_CFG2_DVOL_M51P5dB											((uint8_t) 0x62)
    #define CH7_CFG2_DVOL_M51dB												((uint8_t) 0x63)
    #define CH7_CFG2_DVOL_M50P5dB											((uint8_t) 0x64)
    #define CH7_CFG2_DVOL_M50dB												((uint8_t) 0x65)
    #define CH7_CFG2_DVOL_M49P5dB											((uint8_t) 0x66)
    #define CH7_CFG2_DVOL_M49dB												((uint8_t) 0x67)
    #define CH7_CFG2_DVOL_M48P5dB											((uint8_t) 0x68)
    #define CH7_CFG2_DVOL_M48dB												((uint8_t) 0x69)
    #define CH7_CFG2_DVOL_M47P5dB											((uint8_t) 0x6A)
    #define CH7_CFG2_DVOL_M47dB												((uint8_t) 0x6B)
    #define CH7_CFG2_DVOL_M46P5dB											((uint8_t) 0x6C)
    #define CH7_CFG2_DVOL_M46dB												((uint8_t) 0x6D)
    #define CH7_CFG2_DVOL_M45P5dB											((uint8_t) 0x6E)
    #define CH7_CFG2_DVOL_M45dB												((uint8_t) 0x6F)
    #define CH7_CFG2_DVOL_M44P5dB											((uint8_t) 0x70)
    #define CH7_CFG2_DVOL_M44dB												((uint8_t) 0x71)
    #define CH7_CFG2_DVOL_M43P5dB											((uint8_t) 0x72)
    #define CH7_CFG2_DVOL_M43dB												((uint8_t) 0x73)
    #define CH7_CFG2_DVOL_M42P5dB											((uint8_t) 0x74)
    #define CH7_CFG2_DVOL_M42dB												((uint8_t) 0x75)
    #define CH7_CFG2_DVOL_M41P5dB											((uint8_t) 0x76)
    #define CH7_CFG2_DVOL_M41dB												((uint8_t) 0x77)
    #define CH7_CFG2_DVOL_M40P5dB											((uint8_t) 0x78)
    #define CH7_CFG2_DVOL_M40dB												((uint8_t) 0x79)
    #define CH7_CFG2_DVOL_M39P5dB											((uint8_t) 0x7A)
    #define CH7_CFG2_DVOL_M39dB												((uint8_t) 0x7B)
    #define CH7_CFG2_DVOL_M38P5dB											((uint8_t) 0x7C)
    #define CH7_CFG2_DVOL_M38dB												((uint8_t) 0x7D)
    #define CH7_CFG2_DVOL_M37P5dB											((uint8_t) 0x7E)
    #define CH7_CFG2_DVOL_M37dB												((uint8_t) 0x7F)
    #define CH7_CFG2_DVOL_M36P5dB											((uint8_t) 0x80)
    #define CH7_CFG2_DVOL_M36dB												((uint8_t) 0x81)
    #define CH7_CFG2_DVOL_M35P5dB											((uint8_t) 0x82)
    #define CH7_CFG2_DVOL_M35dB												((uint8_t) 0x83)
    #define CH7_CFG2_DVOL_M34P5dB											((uint8_t) 0x84)
    #define CH7_CFG2_DVOL_M34dB												((uint8_t) 0x85)
    #define CH7_CFG2_DVOL_M33P5dB											((uint8_t) 0x86)
    #define CH7_CFG2_DVOL_M33dB												((uint8_t) 0x87)
    #define CH7_CFG2_DVOL_M32P5dB											((uint8_t) 0x88)
    #define CH7_CFG2_DVOL_M32dB												((uint8_t) 0x89)
    #define CH7_CFG2_DVOL_M31P5dB											((uint8_t) 0x8A)
    #define CH7_CFG2_DVOL_M31dB												((uint8_t) 0x8B)
    #define CH7_CFG2_DVOL_M30P5dB											((uint8_t) 0x8C)
    #define CH7_CFG2_DVOL_M30dB												((uint8_t) 0x8D)
    #define CH7_CFG2_DVOL_M29P5dB											((uint8_t) 0x8E)
    #define CH7_CFG2_DVOL_M29dB												((uint8_t) 0x8F)
    #define CH7_CFG2_DVOL_M28P5dB											((uint8_t) 0x90)
    #define CH7_CFG2_DVOL_M28dB												((uint8_t) 0x91)
    #define CH7_CFG2_DVOL_M27P5dB											((uint8_t) 0x92)
    #define CH7_CFG2_DVOL_M27dB												((uint8_t) 0x93)
    #define CH7_CFG2_DVOL_M26P5dB											((uint8_t) 0x94)
    #define CH7_CFG2_DVOL_M26dB												((uint8_t) 0x95)
    #define CH7_CFG2_DVOL_M25P5dB											((uint8_t) 0x96)
    #define CH7_CFG2_DVOL_M25dB												((uint8_t) 0x97)
    #define CH7_CFG2_DVOL_M24P5dB											((uint8_t) 0x98)
    #define CH7_CFG2_DVOL_M24dB												((uint8_t) 0x99)
    #define CH7_CFG2_DVOL_M23P5dB											((uint8_t) 0x9A)
    #define CH7_CFG2_DVOL_M23dB												((uint8_t) 0x9B)
    #define CH7_CFG2_DVOL_M22P5dB											((uint8_t) 0x9C)
    #define CH7_CFG2_DVOL_M22dB												((uint8_t) 0x9D)
    #define CH7_CFG2_DVOL_M21P5dB											((uint8_t) 0x9E)
    #define CH7_CFG2_DVOL_M21dB												((uint8_t) 0x9F)
    #define CH7_CFG2_DVOL_M20P5dB											((uint8_t) 0xA0)
    #define CH7_CFG2_DVOL_M20dB												((uint8_t) 0xA1)
    #define CH7_CFG2_DVOL_M19P5dB											((uint8_t) 0xA2)
    #define CH7_CFG2_DVOL_M19dB												((uint8_t) 0xA3)
    #define CH7_CFG2_DVOL_M18P5dB											((uint8_t) 0xA4)
    #define CH7_CFG2_DVOL_M18dB												((uint8_t) 0xA5)
    #define CH7_CFG2_DVOL_M17P5dB											((uint8_t) 0xA6)
    #define CH7_CFG2_DVOL_M17dB												((uint8_t) 0xA7)
    #define CH7_CFG2_DVOL_M16P5dB											((uint8_t) 0xA8)
    #define CH7_CFG2_DVOL_M16dB												((uint8_t) 0xA9)
    #define CH7_CFG2_DVOL_M15P5dB											((uint8_t) 0xAA)
    #define CH7_CFG2_DVOL_M15dB												((uint8_t) 0xAB)
    #define CH7_CFG2_DVOL_M14P5dB											((uint8_t) 0xAC)
    #define CH7_CFG2_DVOL_M14dB												((uint8_t) 0xAD)
    #define CH7_CFG2_DVOL_M13P5dB											((uint8_t) 0xAE)
    #define CH7_CFG2_DVOL_M13dB												((uint8_t) 0xAF)
    #define CH7_CFG2_DVOL_M12P5dB											((uint8_t) 0xB0)
    #define CH7_CFG2_DVOL_M12dB												((uint8_t) 0xB1)
    #define CH7_CFG2_DVOL_M11P5dB											((uint8_t) 0xB2)
    #define CH7_CFG2_DVOL_M11dB												((uint8_t) 0xB3)
    #define CH7_CFG2_DVOL_M10P5dB											((uint8_t) 0xB4)
    #define CH7_CFG2_DVOL_M10dB												((uint8_t) 0xB5)
    #define CH7_CFG2_DVOL_M9P5dB											((uint8_t) 0xB6)
    #define CH7_CFG2_DVOL_M9dB												((uint8_t) 0xB7)
    #define CH7_CFG2_DVOL_M8P5dB											((uint8_t) 0xB8)
    #define CH7_CFG2_DVOL_M8dB												((uint8_t) 0xB9)
    #define CH7_CFG2_DVOL_M7P5dB											((uint8_t) 0xBA)
    #define CH7_CFG2_DVOL_M7dB												((uint8_t) 0xBB)
    #define CH7_CFG2_DVOL_M6P5dB											((uint8_t) 0xBC)
    #define CH7_CFG2_DVOL_M6dB												((uint8_t) 0xBD)
    #define CH7_CFG2_DVOL_M5P5dB											((uint8_t) 0xBE)
    #define CH7_CFG2_DVOL_M5dB												((uint8_t) 0xBF)
    #define CH7_CFG2_DVOL_M4P5dB											((uint8_t) 0xC0)
    #define CH7_CFG2_DVOL_M4dB												((uint8_t) 0xC1)
    #define CH7_CFG2_DVOL_M3P5dB											((uint8_t) 0xC2)
    #define CH7_CFG2_DVOL_M3dB												((uint8_t) 0xC3)
    #define CH7_CFG2_DVOL_M2P5dB											((uint8_t) 0xC4)
    #define CH7_CFG2_DVOL_M2dB												((uint8_t) 0xC5)
    #define CH7_CFG2_DVOL_M1P5dB											((uint8_t) 0xC6)
    #define CH7_CFG2_DVOL_M1dB												((uint8_t) 0xC7)
    #define CH7_CFG2_DVOL_M0P5dB											((uint8_t) 0xC8)
    #define CH7_CFG2_DVOL_0dB												((uint8_t) 0xC9)    // DEFAULT
    #define CH7_CFG2_DVOL_0P5dB												((uint8_t) 0xCA)
    #define CH7_CFG2_DVOL_1dB												((uint8_t) 0xCB)
    #define CH7_CFG2_DVOL_1P5dB												((uint8_t) 0xCC)
    #define CH7_CFG2_DVOL_2dB												((uint8_t) 0xCD)
    #define CH7_CFG2_DVOL_2P5dB												((uint8_t) 0xCE)
    #define CH7_CFG2_DVOL_3dB												((uint8_t) 0xCF)
    #define CH7_CFG2_DVOL_3P5dB												((uint8_t) 0xD0)
    #define CH7_CFG2_DVOL_4dB												((uint8_t) 0xD1)
    #define CH7_CFG2_DVOL_4P5dB												((uint8_t) 0xD2)
    #define CH7_CFG2_DVOL_5dB												((uint8_t) 0xD3)
    #define CH7_CFG2_DVOL_5P5dB												((uint8_t) 0xD4)
    #define CH7_CFG2_DVOL_6dB												((uint8_t) 0xD5)
    #define CH7_CFG2_DVOL_6P5dB												((uint8_t) 0xD6)
    #define CH7_CFG2_DVOL_7dB												((uint8_t) 0xD7)
    #define CH7_CFG2_DVOL_7P5dB												((uint8_t) 0xD8)
    #define CH7_CFG2_DVOL_8dB												((uint8_t) 0xD9)
    #define CH7_CFG2_DVOL_8P5dB												((uint8_t) 0xDA)
    #define CH7_CFG2_DVOL_9dB												((uint8_t) 0xDB)
    #define CH7_CFG2_DVOL_9P5dB												((uint8_t) 0xDC)
    #define CH7_CFG2_DVOL_10dB												((uint8_t) 0xDD)
    #define CH7_CFG2_DVOL_10P5dB											((uint8_t) 0xDE)
    #define CH7_CFG2_DVOL_11dB												((uint8_t) 0xDF)
    #define CH7_CFG2_DVOL_11P5dB											((uint8_t) 0xE0)
    #define CH7_CFG2_DVOL_12dB												((uint8_t) 0xE1)
    #define CH7_CFG2_DVOL_12P5dB											((uint8_t) 0xE2)
    #define CH7_CFG2_DVOL_13dB												((uint8_t) 0xE3)
    #define CH7_CFG2_DVOL_13P5dB											((uint8_t) 0xE4)
    #define CH7_CFG2_DVOL_14dB												((uint8_t) 0xE5)
    #define CH7_CFG2_DVOL_14P5dB											((uint8_t) 0xE6)
    #define CH7_CFG2_DVOL_15dB												((uint8_t) 0xE7)
    #define CH7_CFG2_DVOL_15P5dB											((uint8_t) 0xE8)
    #define CH7_CFG2_DVOL_16dB												((uint8_t) 0xE9)
    #define CH7_CFG2_DVOL_16P5dB											((uint8_t) 0xEA)
    #define CH7_CFG2_DVOL_17dB												((uint8_t) 0xEB)
    #define CH7_CFG2_DVOL_17P5dB											((uint8_t) 0xEC)
    #define CH7_CFG2_DVOL_18dB												((uint8_t) 0xED)
    #define CH7_CFG2_DVOL_18P5dB											((uint8_t) 0xEE)
    #define CH7_CFG2_DVOL_19dB												((uint8_t) 0xEF)
    #define CH7_CFG2_DVOL_19P5dB											((uint8_t) 0xF0)
    #define CH7_CFG2_DVOL_20dB												((uint8_t) 0xF1)
    #define CH7_CFG2_DVOL_20P5dB											((uint8_t) 0xF2)
    #define CH7_CFG2_DVOL_21dB												((uint8_t) 0xF3)
    #define CH7_CFG2_DVOL_21P5dB											((uint8_t) 0xF4)
    #define CH7_CFG2_DVOL_22dB												((uint8_t) 0xF5)
    #define CH7_CFG2_DVOL_22P5dB											((uint8_t) 0xF6)
    #define CH7_CFG2_DVOL_23dB												((uint8_t) 0xF7)
    #define CH7_CFG2_DVOL_23P5dB											((uint8_t) 0xF8)
    #define CH7_CFG2_DVOL_24dB												((uint8_t) 0xF9)
    #define CH7_CFG2_DVOL_24P5dB											((uint8_t) 0xFA)
    #define CH7_CFG2_DVOL_25dB												((uint8_t) 0xFB)
    #define CH7_CFG2_DVOL_25P5dB											((uint8_t) 0xFC)
    #define CH7_CFG2_DVOL_26dB												((uint8_t) 0xFD)
    #define CH7_CFG2_DVOL_26P5dB											((uint8_t) 0xFE)
    #define CH7_CFG2_DVOL_27dB												((uint8_t) 0xFF)



/* Register 0x5D (CH7_CFG3) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                       GCAL[3:0]                                       |                                     RESERVED[3:0]                                     |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH7_CFG3 register */
    #define CH7_CFG3_ADDRESS												((uint8_t) 0x5D)
    #define CH7_CFG3_DEFAULT												((uint8_t) 0x80)

    /* GCAL field */
    #define CH7_CFG3_GCAL_MASK												((uint8_t) 0xF0)
    #define CH7_CFG3_GCAL_M0P8dB											((uint8_t) 0x00)
    #define CH7_CFG3_GCAL_M0P7dB											((uint8_t) 0x10)
    #define CH7_CFG3_GCAL_M0P6dB											((uint8_t) 0x20)
    #define CH7_CFG3_GCAL_M0P5dB											((uint8_t) 0x30)
    #define CH7_CFG3_GCAL_M0P4dB											((uint8_t) 0x40)
    #define CH7_CFG3_GCAL_M0P3dB											((uint8_t) 0x50)
    #define CH7_CFG3_GCAL_M0P2dB											((uint8_t) 0x60)
    #define CH7_CFG3_GCAL_M0P1dB											((uint8_t) 0x70)
    #define CH7_CFG3_GCAL_0dB												((uint8_t) 0x80)    // DEFAULT
    #define CH7_CFG3_GCAL_0P1dB												((uint8_t) 0x90)
    #define CH7_CFG3_GCAL_0P2dB												((uint8_t) 0xA0)
    #define CH7_CFG3_GCAL_0P3dB												((uint8_t) 0xB0)
    #define CH7_CFG3_GCAL_0P4dB												((uint8_t) 0xC0)
    #define CH7_CFG3_GCAL_0P5dB												((uint8_t) 0xD0)
    #define CH7_CFG3_GCAL_0P6dB												((uint8_t) 0xE0)
    #define CH7_CFG3_GCAL_0P7dB												((uint8_t) 0xF0)



/* Register 0x5E (CH7_CFG4) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                                                   PCAL[7:0]                                                                                   |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH7_CFG4 register */
    #define CH7_CFG4_ADDRESS												((uint8_t) 0x5E)
    #define CH7_CFG4_DEFAULT												((uint8_t) 0x00)

    /* PCAL field */
    #define CH7_CFG4_PCAL_MASK												((uint8_t) 0xFF)
    #define CH7_CFG4_PCAL_0													((uint8_t) 0x00)    // DEFAULT
    #define CH7_CFG4_PCAL_1													((uint8_t) 0x01)
    #define CH7_CFG4_PCAL_2													((uint8_t) 0x02)
    #define CH7_CFG4_PCAL_3													((uint8_t) 0x03)
    #define CH7_CFG4_PCAL_4													((uint8_t) 0x04)
    #define CH7_CFG4_PCAL_5													((uint8_t) 0x05)
    #define CH7_CFG4_PCAL_6													((uint8_t) 0x06)
    #define CH7_CFG4_PCAL_7													((uint8_t) 0x07)
    #define CH7_CFG4_PCAL_8													((uint8_t) 0x08)
    #define CH7_CFG4_PCAL_9													((uint8_t) 0x09)
    #define CH7_CFG4_PCAL_10												((uint8_t) 0x0A)
    #define CH7_CFG4_PCAL_11												((uint8_t) 0x0B)
    #define CH7_CFG4_PCAL_12												((uint8_t) 0x0C)
    #define CH7_CFG4_PCAL_13												((uint8_t) 0x0D)
    #define CH7_CFG4_PCAL_14												((uint8_t) 0x0E)
    #define CH7_CFG4_PCAL_15												((uint8_t) 0x0F)
    #define CH7_CFG4_PCAL_16												((uint8_t) 0x10)
    #define CH7_CFG4_PCAL_17												((uint8_t) 0x11)
    #define CH7_CFG4_PCAL_18												((uint8_t) 0x12)
    #define CH7_CFG4_PCAL_19												((uint8_t) 0x13)
    #define CH7_CFG4_PCAL_20												((uint8_t) 0x14)
    #define CH7_CFG4_PCAL_21												((uint8_t) 0x15)
    #define CH7_CFG4_PCAL_22												((uint8_t) 0x16)
    #define CH7_CFG4_PCAL_23												((uint8_t) 0x17)
    #define CH7_CFG4_PCAL_24												((uint8_t) 0x18)
    #define CH7_CFG4_PCAL_25												((uint8_t) 0x19)
    #define CH7_CFG4_PCAL_26												((uint8_t) 0x1A)
    #define CH7_CFG4_PCAL_27												((uint8_t) 0x1B)
    #define CH7_CFG4_PCAL_28												((uint8_t) 0x1C)
    #define CH7_CFG4_PCAL_29												((uint8_t) 0x1D)
    #define CH7_CFG4_PCAL_30												((uint8_t) 0x1E)
    #define CH7_CFG4_PCAL_31												((uint8_t) 0x1F)
    #define CH7_CFG4_PCAL_32												((uint8_t) 0x20)
    #define CH7_CFG4_PCAL_33												((uint8_t) 0x21)
    #define CH7_CFG4_PCAL_34												((uint8_t) 0x22)
    #define CH7_CFG4_PCAL_35												((uint8_t) 0x23)
    #define CH7_CFG4_PCAL_36												((uint8_t) 0x24)
    #define CH7_CFG4_PCAL_37												((uint8_t) 0x25)
    #define CH7_CFG4_PCAL_38												((uint8_t) 0x26)
    #define CH7_CFG4_PCAL_39												((uint8_t) 0x27)
    #define CH7_CFG4_PCAL_40												((uint8_t) 0x28)
    #define CH7_CFG4_PCAL_41												((uint8_t) 0x29)
    #define CH7_CFG4_PCAL_42												((uint8_t) 0x2A)
    #define CH7_CFG4_PCAL_43												((uint8_t) 0x2B)
    #define CH7_CFG4_PCAL_44												((uint8_t) 0x2C)
    #define CH7_CFG4_PCAL_45												((uint8_t) 0x2D)
    #define CH7_CFG4_PCAL_46												((uint8_t) 0x2E)
    #define CH7_CFG4_PCAL_47												((uint8_t) 0x2F)
    #define CH7_CFG4_PCAL_48												((uint8_t) 0x30)
    #define CH7_CFG4_PCAL_49												((uint8_t) 0x31)
    #define CH7_CFG4_PCAL_50												((uint8_t) 0x32)
    #define CH7_CFG4_PCAL_51												((uint8_t) 0x33)
    #define CH7_CFG4_PCAL_52												((uint8_t) 0x34)
    #define CH7_CFG4_PCAL_53												((uint8_t) 0x35)
    #define CH7_CFG4_PCAL_54												((uint8_t) 0x36)
    #define CH7_CFG4_PCAL_55												((uint8_t) 0x37)
    #define CH7_CFG4_PCAL_56												((uint8_t) 0x38)
    #define CH7_CFG4_PCAL_57												((uint8_t) 0x39)
    #define CH7_CFG4_PCAL_58												((uint8_t) 0x3A)
    #define CH7_CFG4_PCAL_59												((uint8_t) 0x3B)
    #define CH7_CFG4_PCAL_60												((uint8_t) 0x3C)
    #define CH7_CFG4_PCAL_61												((uint8_t) 0x3D)
    #define CH7_CFG4_PCAL_62												((uint8_t) 0x3E)
    #define CH7_CFG4_PCAL_63												((uint8_t) 0x3F)
    #define CH7_CFG4_PCAL_64												((uint8_t) 0x40)
    #define CH7_CFG4_PCAL_65												((uint8_t) 0x41)
    #define CH7_CFG4_PCAL_66												((uint8_t) 0x42)
    #define CH7_CFG4_PCAL_67												((uint8_t) 0x43)
    #define CH7_CFG4_PCAL_68												((uint8_t) 0x44)
    #define CH7_CFG4_PCAL_69												((uint8_t) 0x45)
    #define CH7_CFG4_PCAL_70												((uint8_t) 0x46)
    #define CH7_CFG4_PCAL_71												((uint8_t) 0x47)
    #define CH7_CFG4_PCAL_72												((uint8_t) 0x48)
    #define CH7_CFG4_PCAL_73												((uint8_t) 0x49)
    #define CH7_CFG4_PCAL_74												((uint8_t) 0x4A)
    #define CH7_CFG4_PCAL_75												((uint8_t) 0x4B)
    #define CH7_CFG4_PCAL_76												((uint8_t) 0x4C)
    #define CH7_CFG4_PCAL_77												((uint8_t) 0x4D)
    #define CH7_CFG4_PCAL_78												((uint8_t) 0x4E)
    #define CH7_CFG4_PCAL_79												((uint8_t) 0x4F)
    #define CH7_CFG4_PCAL_80												((uint8_t) 0x50)
    #define CH7_CFG4_PCAL_81												((uint8_t) 0x51)
    #define CH7_CFG4_PCAL_82												((uint8_t) 0x52)
    #define CH7_CFG4_PCAL_83												((uint8_t) 0x53)
    #define CH7_CFG4_PCAL_84												((uint8_t) 0x54)
    #define CH7_CFG4_PCAL_85												((uint8_t) 0x55)
    #define CH7_CFG4_PCAL_86												((uint8_t) 0x56)
    #define CH7_CFG4_PCAL_87												((uint8_t) 0x57)
    #define CH7_CFG4_PCAL_88												((uint8_t) 0x58)
    #define CH7_CFG4_PCAL_89												((uint8_t) 0x59)
    #define CH7_CFG4_PCAL_90												((uint8_t) 0x5A)
    #define CH7_CFG4_PCAL_91												((uint8_t) 0x5B)
    #define CH7_CFG4_PCAL_92												((uint8_t) 0x5C)
    #define CH7_CFG4_PCAL_93												((uint8_t) 0x5D)
    #define CH7_CFG4_PCAL_94												((uint8_t) 0x5E)
    #define CH7_CFG4_PCAL_95												((uint8_t) 0x5F)
    #define CH7_CFG4_PCAL_96												((uint8_t) 0x60)
    #define CH7_CFG4_PCAL_97												((uint8_t) 0x61)
    #define CH7_CFG4_PCAL_98												((uint8_t) 0x62)
    #define CH7_CFG4_PCAL_99												((uint8_t) 0x63)
    #define CH7_CFG4_PCAL_100												((uint8_t) 0x64)
    #define CH7_CFG4_PCAL_101												((uint8_t) 0x65)
    #define CH7_CFG4_PCAL_102												((uint8_t) 0x66)
    #define CH7_CFG4_PCAL_103												((uint8_t) 0x67)
    #define CH7_CFG4_PCAL_104												((uint8_t) 0x68)
    #define CH7_CFG4_PCAL_105												((uint8_t) 0x69)
    #define CH7_CFG4_PCAL_106												((uint8_t) 0x6A)
    #define CH7_CFG4_PCAL_107												((uint8_t) 0x6B)
    #define CH7_CFG4_PCAL_108												((uint8_t) 0x6C)
    #define CH7_CFG4_PCAL_109												((uint8_t) 0x6D)
    #define CH7_CFG4_PCAL_110												((uint8_t) 0x6E)
    #define CH7_CFG4_PCAL_111												((uint8_t) 0x6F)
    #define CH7_CFG4_PCAL_112												((uint8_t) 0x70)
    #define CH7_CFG4_PCAL_113												((uint8_t) 0x71)
    #define CH7_CFG4_PCAL_114												((uint8_t) 0x72)
    #define CH7_CFG4_PCAL_115												((uint8_t) 0x73)
    #define CH7_CFG4_PCAL_116												((uint8_t) 0x74)
    #define CH7_CFG4_PCAL_117												((uint8_t) 0x75)
    #define CH7_CFG4_PCAL_118												((uint8_t) 0x76)
    #define CH7_CFG4_PCAL_119												((uint8_t) 0x77)
    #define CH7_CFG4_PCAL_120												((uint8_t) 0x78)
    #define CH7_CFG4_PCAL_121												((uint8_t) 0x79)
    #define CH7_CFG4_PCAL_122												((uint8_t) 0x7A)
    #define CH7_CFG4_PCAL_123												((uint8_t) 0x7B)
    #define CH7_CFG4_PCAL_124												((uint8_t) 0x7C)
    #define CH7_CFG4_PCAL_125												((uint8_t) 0x7D)
    #define CH7_CFG4_PCAL_126												((uint8_t) 0x7E)
    #define CH7_CFG4_PCAL_127												((uint8_t) 0x7F)
    #define CH7_CFG4_PCAL_128												((uint8_t) 0x80)
    #define CH7_CFG4_PCAL_129												((uint8_t) 0x81)
    #define CH7_CFG4_PCAL_130												((uint8_t) 0x82)
    #define CH7_CFG4_PCAL_131												((uint8_t) 0x83)
    #define CH7_CFG4_PCAL_132												((uint8_t) 0x84)
    #define CH7_CFG4_PCAL_133												((uint8_t) 0x85)
    #define CH7_CFG4_PCAL_134												((uint8_t) 0x86)
    #define CH7_CFG4_PCAL_135												((uint8_t) 0x87)
    #define CH7_CFG4_PCAL_136												((uint8_t) 0x88)
    #define CH7_CFG4_PCAL_137												((uint8_t) 0x89)
    #define CH7_CFG4_PCAL_138												((uint8_t) 0x8A)
    #define CH7_CFG4_PCAL_139												((uint8_t) 0x8B)
    #define CH7_CFG4_PCAL_140												((uint8_t) 0x8C)
    #define CH7_CFG4_PCAL_141												((uint8_t) 0x8D)
    #define CH7_CFG4_PCAL_142												((uint8_t) 0x8E)
    #define CH7_CFG4_PCAL_143												((uint8_t) 0x8F)
    #define CH7_CFG4_PCAL_144												((uint8_t) 0x90)
    #define CH7_CFG4_PCAL_145												((uint8_t) 0x91)
    #define CH7_CFG4_PCAL_146												((uint8_t) 0x92)
    #define CH7_CFG4_PCAL_147												((uint8_t) 0x93)
    #define CH7_CFG4_PCAL_148												((uint8_t) 0x94)
    #define CH7_CFG4_PCAL_149												((uint8_t) 0x95)
    #define CH7_CFG4_PCAL_150												((uint8_t) 0x96)
    #define CH7_CFG4_PCAL_151												((uint8_t) 0x97)
    #define CH7_CFG4_PCAL_152												((uint8_t) 0x98)
    #define CH7_CFG4_PCAL_153												((uint8_t) 0x99)
    #define CH7_CFG4_PCAL_154												((uint8_t) 0x9A)
    #define CH7_CFG4_PCAL_155												((uint8_t) 0x9B)
    #define CH7_CFG4_PCAL_156												((uint8_t) 0x9C)
    #define CH7_CFG4_PCAL_157												((uint8_t) 0x9D)
    #define CH7_CFG4_PCAL_158												((uint8_t) 0x9E)
    #define CH7_CFG4_PCAL_159												((uint8_t) 0x9F)
    #define CH7_CFG4_PCAL_160												((uint8_t) 0xA0)
    #define CH7_CFG4_PCAL_161												((uint8_t) 0xA1)
    #define CH7_CFG4_PCAL_162												((uint8_t) 0xA2)
    #define CH7_CFG4_PCAL_163												((uint8_t) 0xA3)
    #define CH7_CFG4_PCAL_164												((uint8_t) 0xA4)
    #define CH7_CFG4_PCAL_165												((uint8_t) 0xA5)
    #define CH7_CFG4_PCAL_166												((uint8_t) 0xA6)
    #define CH7_CFG4_PCAL_167												((uint8_t) 0xA7)
    #define CH7_CFG4_PCAL_168												((uint8_t) 0xA8)
    #define CH7_CFG4_PCAL_169												((uint8_t) 0xA9)
    #define CH7_CFG4_PCAL_170												((uint8_t) 0xAA)
    #define CH7_CFG4_PCAL_171												((uint8_t) 0xAB)
    #define CH7_CFG4_PCAL_172												((uint8_t) 0xAC)
    #define CH7_CFG4_PCAL_173												((uint8_t) 0xAD)
    #define CH7_CFG4_PCAL_174												((uint8_t) 0xAE)
    #define CH7_CFG4_PCAL_175												((uint8_t) 0xAF)
    #define CH7_CFG4_PCAL_176												((uint8_t) 0xB0)
    #define CH7_CFG4_PCAL_177												((uint8_t) 0xB1)
    #define CH7_CFG4_PCAL_178												((uint8_t) 0xB2)
    #define CH7_CFG4_PCAL_179												((uint8_t) 0xB3)
    #define CH7_CFG4_PCAL_180												((uint8_t) 0xB4)
    #define CH7_CFG4_PCAL_181												((uint8_t) 0xB5)
    #define CH7_CFG4_PCAL_182												((uint8_t) 0xB6)
    #define CH7_CFG4_PCAL_183												((uint8_t) 0xB7)
    #define CH7_CFG4_PCAL_184												((uint8_t) 0xB8)
    #define CH7_CFG4_PCAL_185												((uint8_t) 0xB9)
    #define CH7_CFG4_PCAL_186												((uint8_t) 0xBA)
    #define CH7_CFG4_PCAL_187												((uint8_t) 0xBB)
    #define CH7_CFG4_PCAL_188												((uint8_t) 0xBC)
    #define CH7_CFG4_PCAL_189												((uint8_t) 0xBD)
    #define CH7_CFG4_PCAL_190												((uint8_t) 0xBE)
    #define CH7_CFG4_PCAL_191												((uint8_t) 0xBF)
    #define CH7_CFG4_PCAL_192												((uint8_t) 0xC0)
    #define CH7_CFG4_PCAL_193												((uint8_t) 0xC1)
    #define CH7_CFG4_PCAL_194												((uint8_t) 0xC2)
    #define CH7_CFG4_PCAL_195												((uint8_t) 0xC3)
    #define CH7_CFG4_PCAL_196												((uint8_t) 0xC4)
    #define CH7_CFG4_PCAL_197												((uint8_t) 0xC5)
    #define CH7_CFG4_PCAL_198												((uint8_t) 0xC6)
    #define CH7_CFG4_PCAL_199												((uint8_t) 0xC7)
    #define CH7_CFG4_PCAL_200												((uint8_t) 0xC8)
    #define CH7_CFG4_PCAL_201												((uint8_t) 0xC9)
    #define CH7_CFG4_PCAL_202												((uint8_t) 0xCA)
    #define CH7_CFG4_PCAL_203												((uint8_t) 0xCB)
    #define CH7_CFG4_PCAL_204												((uint8_t) 0xCC)
    #define CH7_CFG4_PCAL_205												((uint8_t) 0xCD)
    #define CH7_CFG4_PCAL_206												((uint8_t) 0xCE)
    #define CH7_CFG4_PCAL_207												((uint8_t) 0xCF)
    #define CH7_CFG4_PCAL_208												((uint8_t) 0xD0)
    #define CH7_CFG4_PCAL_209												((uint8_t) 0xD1)
    #define CH7_CFG4_PCAL_210												((uint8_t) 0xD2)
    #define CH7_CFG4_PCAL_211												((uint8_t) 0xD3)
    #define CH7_CFG4_PCAL_212												((uint8_t) 0xD4)
    #define CH7_CFG4_PCAL_213												((uint8_t) 0xD5)
    #define CH7_CFG4_PCAL_214												((uint8_t) 0xD6)
    #define CH7_CFG4_PCAL_215												((uint8_t) 0xD7)
    #define CH7_CFG4_PCAL_216												((uint8_t) 0xD8)
    #define CH7_CFG4_PCAL_217												((uint8_t) 0xD9)
    #define CH7_CFG4_PCAL_218												((uint8_t) 0xDA)
    #define CH7_CFG4_PCAL_219												((uint8_t) 0xDB)
    #define CH7_CFG4_PCAL_220												((uint8_t) 0xDC)
    #define CH7_CFG4_PCAL_221												((uint8_t) 0xDD)
    #define CH7_CFG4_PCAL_222												((uint8_t) 0xDE)
    #define CH7_CFG4_PCAL_223												((uint8_t) 0xDF)
    #define CH7_CFG4_PCAL_224												((uint8_t) 0xE0)
    #define CH7_CFG4_PCAL_225												((uint8_t) 0xE1)
    #define CH7_CFG4_PCAL_226												((uint8_t) 0xE2)
    #define CH7_CFG4_PCAL_227												((uint8_t) 0xE3)
    #define CH7_CFG4_PCAL_228												((uint8_t) 0xE4)
    #define CH7_CFG4_PCAL_229												((uint8_t) 0xE5)
    #define CH7_CFG4_PCAL_230												((uint8_t) 0xE6)
    #define CH7_CFG4_PCAL_231												((uint8_t) 0xE7)
    #define CH7_CFG4_PCAL_232												((uint8_t) 0xE8)
    #define CH7_CFG4_PCAL_233												((uint8_t) 0xE9)
    #define CH7_CFG4_PCAL_234												((uint8_t) 0xEA)
    #define CH7_CFG4_PCAL_235												((uint8_t) 0xEB)
    #define CH7_CFG4_PCAL_236												((uint8_t) 0xEC)
    #define CH7_CFG4_PCAL_237												((uint8_t) 0xED)
    #define CH7_CFG4_PCAL_238												((uint8_t) 0xEE)
    #define CH7_CFG4_PCAL_239												((uint8_t) 0xEF)
    #define CH7_CFG4_PCAL_240												((uint8_t) 0xF0)
    #define CH7_CFG4_PCAL_241												((uint8_t) 0xF1)
    #define CH7_CFG4_PCAL_242												((uint8_t) 0xF2)
    #define CH7_CFG4_PCAL_243												((uint8_t) 0xF3)
    #define CH7_CFG4_PCAL_244												((uint8_t) 0xF4)
    #define CH7_CFG4_PCAL_245												((uint8_t) 0xF5)
    #define CH7_CFG4_PCAL_246												((uint8_t) 0xF6)
    #define CH7_CFG4_PCAL_247												((uint8_t) 0xF7)
    #define CH7_CFG4_PCAL_248												((uint8_t) 0xF8)
    #define CH7_CFG4_PCAL_249												((uint8_t) 0xF9)
    #define CH7_CFG4_PCAL_250												((uint8_t) 0xFA)
    #define CH7_CFG4_PCAL_251												((uint8_t) 0xFB)
    #define CH7_CFG4_PCAL_252												((uint8_t) 0xFC)
    #define CH7_CFG4_PCAL_253												((uint8_t) 0xFD)
    #define CH7_CFG4_PCAL_254												((uint8_t) 0xFE)
    #define CH7_CFG4_PCAL_255												((uint8_t) 0xFF)



/* Register 0x61 (CH8_CFG2) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                                                   DVOL[7:0]                                                                                   |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH8_CFG2 register */
    #define CH8_CFG2_ADDRESS												((uint8_t) 0x61)
    #define CH8_CFG2_DEFAULT												((uint8_t) 0xC9)

    /* DVOL field */
    #define CH8_CFG2_DVOL_MASK												((uint8_t) 0xFF)
    #define CH8_CFG2_DVOL_MUTE												((uint8_t) 0x00)
    #define CH8_CFG2_DVOL_M100dB											((uint8_t) 0x01)
    #define CH8_CFG2_DVOL_M99P5dB											((uint8_t) 0x02)
    #define CH8_CFG2_DVOL_M99dB												((uint8_t) 0x03)
    #define CH8_CFG2_DVOL_M98P5dB											((uint8_t) 0x04)
    #define CH8_CFG2_DVOL_M98dB												((uint8_t) 0x05)
    #define CH8_CFG2_DVOL_M97P5dB											((uint8_t) 0x06)
    #define CH8_CFG2_DVOL_M97dB												((uint8_t) 0x07)
    #define CH8_CFG2_DVOL_M96P5dB											((uint8_t) 0x08)
    #define CH8_CFG2_DVOL_M96dB												((uint8_t) 0x09)
    #define CH8_CFG2_DVOL_M95P5dB											((uint8_t) 0x0A)
    #define CH8_CFG2_DVOL_M95dB												((uint8_t) 0x0B)
    #define CH8_CFG2_DVOL_M94P5dB											((uint8_t) 0x0C)
    #define CH8_CFG2_DVOL_M94dB												((uint8_t) 0x0D)
    #define CH8_CFG2_DVOL_M93P5dB											((uint8_t) 0x0E)
    #define CH8_CFG2_DVOL_M93dB												((uint8_t) 0x0F)
    #define CH8_CFG2_DVOL_M92P5dB											((uint8_t) 0x10)
    #define CH8_CFG2_DVOL_M92dB												((uint8_t) 0x11)
    #define CH8_CFG2_DVOL_M91P5dB											((uint8_t) 0x12)
    #define CH8_CFG2_DVOL_M91dB												((uint8_t) 0x13)
    #define CH8_CFG2_DVOL_M90P5dB											((uint8_t) 0x14)
    #define CH8_CFG2_DVOL_M90dB												((uint8_t) 0x15)
    #define CH8_CFG2_DVOL_M89P5dB											((uint8_t) 0x16)
    #define CH8_CFG2_DVOL_M89dB												((uint8_t) 0x17)
    #define CH8_CFG2_DVOL_M88P5dB											((uint8_t) 0x18)
    #define CH8_CFG2_DVOL_M88dB												((uint8_t) 0x19)
    #define CH8_CFG2_DVOL_M87P5dB											((uint8_t) 0x1A)
    #define CH8_CFG2_DVOL_M87dB												((uint8_t) 0x1B)
    #define CH8_CFG2_DVOL_M86P5dB											((uint8_t) 0x1C)
    #define CH8_CFG2_DVOL_M86dB												((uint8_t) 0x1D)
    #define CH8_CFG2_DVOL_M85P5dB											((uint8_t) 0x1E)
    #define CH8_CFG2_DVOL_M85dB												((uint8_t) 0x1F)
    #define CH8_CFG2_DVOL_M84P5dB											((uint8_t) 0x20)
    #define CH8_CFG2_DVOL_M84dB												((uint8_t) 0x21)
    #define CH8_CFG2_DVOL_M83P5dB											((uint8_t) 0x22)
    #define CH8_CFG2_DVOL_M83dB												((uint8_t) 0x23)
    #define CH8_CFG2_DVOL_M82P5dB											((uint8_t) 0x24)
    #define CH8_CFG2_DVOL_M82dB												((uint8_t) 0x25)
    #define CH8_CFG2_DVOL_M81P5dB											((uint8_t) 0x26)
    #define CH8_CFG2_DVOL_M81dB												((uint8_t) 0x27)
    #define CH8_CFG2_DVOL_M80P5dB											((uint8_t) 0x28)
    #define CH8_CFG2_DVOL_M80dB												((uint8_t) 0x29)
    #define CH8_CFG2_DVOL_M79P5dB											((uint8_t) 0x2A)
    #define CH8_CFG2_DVOL_M79dB												((uint8_t) 0x2B)
    #define CH8_CFG2_DVOL_M78P5dB											((uint8_t) 0x2C)
    #define CH8_CFG2_DVOL_M78dB												((uint8_t) 0x2D)
    #define CH8_CFG2_DVOL_M77P5dB											((uint8_t) 0x2E)
    #define CH8_CFG2_DVOL_M77dB												((uint8_t) 0x2F)
    #define CH8_CFG2_DVOL_M76P5dB											((uint8_t) 0x30)
    #define CH8_CFG2_DVOL_M76dB												((uint8_t) 0x31)
    #define CH8_CFG2_DVOL_M75P5dB											((uint8_t) 0x32)
    #define CH8_CFG2_DVOL_M75dB												((uint8_t) 0x33)
    #define CH8_CFG2_DVOL_M74P5dB											((uint8_t) 0x34)
    #define CH8_CFG2_DVOL_M74dB												((uint8_t) 0x35)
    #define CH8_CFG2_DVOL_M73P5dB											((uint8_t) 0x36)
    #define CH8_CFG2_DVOL_M73dB												((uint8_t) 0x37)
    #define CH8_CFG2_DVOL_M72P5dB											((uint8_t) 0x38)
    #define CH8_CFG2_DVOL_M72dB												((uint8_t) 0x39)
    #define CH8_CFG2_DVOL_M71P5dB											((uint8_t) 0x3A)
    #define CH8_CFG2_DVOL_M71dB												((uint8_t) 0x3B)
    #define CH8_CFG2_DVOL_M70P5dB											((uint8_t) 0x3C)
    #define CH8_CFG2_DVOL_M70dB												((uint8_t) 0x3D)
    #define CH8_CFG2_DVOL_M69P5dB											((uint8_t) 0x3E)
    #define CH8_CFG2_DVOL_M69dB												((uint8_t) 0x3F)
    #define CH8_CFG2_DVOL_M68P5dB											((uint8_t) 0x40)
    #define CH8_CFG2_DVOL_M68dB												((uint8_t) 0x41)
    #define CH8_CFG2_DVOL_M67P5dB											((uint8_t) 0x42)
    #define CH8_CFG2_DVOL_M67dB												((uint8_t) 0x43)
    #define CH8_CFG2_DVOL_M66P5dB											((uint8_t) 0x44)
    #define CH8_CFG2_DVOL_M66dB												((uint8_t) 0x45)
    #define CH8_CFG2_DVOL_M65P5dB											((uint8_t) 0x46)
    #define CH8_CFG2_DVOL_M65dB												((uint8_t) 0x47)
    #define CH8_CFG2_DVOL_M64P5dB											((uint8_t) 0x48)
    #define CH8_CFG2_DVOL_M64dB												((uint8_t) 0x49)
    #define CH8_CFG2_DVOL_M63P5dB											((uint8_t) 0x4A)
    #define CH8_CFG2_DVOL_M63dB												((uint8_t) 0x4B)
    #define CH8_CFG2_DVOL_M62P5dB											((uint8_t) 0x4C)
    #define CH8_CFG2_DVOL_M62dB												((uint8_t) 0x4D)
    #define CH8_CFG2_DVOL_M61P5dB											((uint8_t) 0x4E)
    #define CH8_CFG2_DVOL_M61dB												((uint8_t) 0x4F)
    #define CH8_CFG2_DVOL_M60P5dB											((uint8_t) 0x50)
    #define CH8_CFG2_DVOL_M60dB												((uint8_t) 0x51)
    #define CH8_CFG2_DVOL_M59P5dB											((uint8_t) 0x52)
    #define CH8_CFG2_DVOL_M59dB												((uint8_t) 0x53)
    #define CH8_CFG2_DVOL_M58P5dB											((uint8_t) 0x54)
    #define CH8_CFG2_DVOL_M58dB												((uint8_t) 0x55)
    #define CH8_CFG2_DVOL_M57P5dB											((uint8_t) 0x56)
    #define CH8_CFG2_DVOL_M57dB												((uint8_t) 0x57)
    #define CH8_CFG2_DVOL_M56P5dB											((uint8_t) 0x58)
    #define CH8_CFG2_DVOL_M56dB												((uint8_t) 0x59)
    #define CH8_CFG2_DVOL_M55P5dB											((uint8_t) 0x5A)
    #define CH8_CFG2_DVOL_M55dB												((uint8_t) 0x5B)
    #define CH8_CFG2_DVOL_M54P5dB											((uint8_t) 0x5C)
    #define CH8_CFG2_DVOL_M54dB												((uint8_t) 0x5D)
    #define CH8_CFG2_DVOL_M53P5dB											((uint8_t) 0x5E)
    #define CH8_CFG2_DVOL_M53dB												((uint8_t) 0x5F)
    #define CH8_CFG2_DVOL_M52P5dB											((uint8_t) 0x60)
    #define CH8_CFG2_DVOL_M52dB												((uint8_t) 0x61)
    #define CH8_CFG2_DVOL_M51P5dB											((uint8_t) 0x62)
    #define CH8_CFG2_DVOL_M51dB												((uint8_t) 0x63)
    #define CH8_CFG2_DVOL_M50P5dB											((uint8_t) 0x64)
    #define CH8_CFG2_DVOL_M50dB												((uint8_t) 0x65)
    #define CH8_CFG2_DVOL_M49P5dB											((uint8_t) 0x66)
    #define CH8_CFG2_DVOL_M49dB												((uint8_t) 0x67)
    #define CH8_CFG2_DVOL_M48P5dB											((uint8_t) 0x68)
    #define CH8_CFG2_DVOL_M48dB												((uint8_t) 0x69)
    #define CH8_CFG2_DVOL_M47P5dB											((uint8_t) 0x6A)
    #define CH8_CFG2_DVOL_M47dB												((uint8_t) 0x6B)
    #define CH8_CFG2_DVOL_M46P5dB											((uint8_t) 0x6C)
    #define CH8_CFG2_DVOL_M46dB												((uint8_t) 0x6D)
    #define CH8_CFG2_DVOL_M45P5dB											((uint8_t) 0x6E)
    #define CH8_CFG2_DVOL_M45dB												((uint8_t) 0x6F)
    #define CH8_CFG2_DVOL_M44P5dB											((uint8_t) 0x70)
    #define CH8_CFG2_DVOL_M44dB												((uint8_t) 0x71)
    #define CH8_CFG2_DVOL_M43P5dB											((uint8_t) 0x72)
    #define CH8_CFG2_DVOL_M43dB												((uint8_t) 0x73)
    #define CH8_CFG2_DVOL_M42P5dB											((uint8_t) 0x74)
    #define CH8_CFG2_DVOL_M42dB												((uint8_t) 0x75)
    #define CH8_CFG2_DVOL_M41P5dB											((uint8_t) 0x76)
    #define CH8_CFG2_DVOL_M41dB												((uint8_t) 0x77)
    #define CH8_CFG2_DVOL_M40P5dB											((uint8_t) 0x78)
    #define CH8_CFG2_DVOL_M40dB												((uint8_t) 0x79)
    #define CH8_CFG2_DVOL_M39P5dB											((uint8_t) 0x7A)
    #define CH8_CFG2_DVOL_M39dB												((uint8_t) 0x7B)
    #define CH8_CFG2_DVOL_M38P5dB											((uint8_t) 0x7C)
    #define CH8_CFG2_DVOL_M38dB												((uint8_t) 0x7D)
    #define CH8_CFG2_DVOL_M37P5dB											((uint8_t) 0x7E)
    #define CH8_CFG2_DVOL_M37dB												((uint8_t) 0x7F)
    #define CH8_CFG2_DVOL_M36P5dB											((uint8_t) 0x80)
    #define CH8_CFG2_DVOL_M36dB												((uint8_t) 0x81)
    #define CH8_CFG2_DVOL_M35P5dB											((uint8_t) 0x82)
    #define CH8_CFG2_DVOL_M35dB												((uint8_t) 0x83)
    #define CH8_CFG2_DVOL_M34P5dB											((uint8_t) 0x84)
    #define CH8_CFG2_DVOL_M34dB												((uint8_t) 0x85)
    #define CH8_CFG2_DVOL_M33P5dB											((uint8_t) 0x86)
    #define CH8_CFG2_DVOL_M33dB												((uint8_t) 0x87)
    #define CH8_CFG2_DVOL_M32P5dB											((uint8_t) 0x88)
    #define CH8_CFG2_DVOL_M32dB												((uint8_t) 0x89)
    #define CH8_CFG2_DVOL_M31P5dB											((uint8_t) 0x8A)
    #define CH8_CFG2_DVOL_M31dB												((uint8_t) 0x8B)
    #define CH8_CFG2_DVOL_M30P5dB											((uint8_t) 0x8C)
    #define CH8_CFG2_DVOL_M30dB												((uint8_t) 0x8D)
    #define CH8_CFG2_DVOL_M29P5dB											((uint8_t) 0x8E)
    #define CH8_CFG2_DVOL_M29dB												((uint8_t) 0x8F)
    #define CH8_CFG2_DVOL_M28P5dB											((uint8_t) 0x90)
    #define CH8_CFG2_DVOL_M28dB												((uint8_t) 0x91)
    #define CH8_CFG2_DVOL_M27P5dB											((uint8_t) 0x92)
    #define CH8_CFG2_DVOL_M27dB												((uint8_t) 0x93)
    #define CH8_CFG2_DVOL_M26P5dB											((uint8_t) 0x94)
    #define CH8_CFG2_DVOL_M26dB												((uint8_t) 0x95)
    #define CH8_CFG2_DVOL_M25P5dB											((uint8_t) 0x96)
    #define CH8_CFG2_DVOL_M25dB												((uint8_t) 0x97)
    #define CH8_CFG2_DVOL_M24P5dB											((uint8_t) 0x98)
    #define CH8_CFG2_DVOL_M24dB												((uint8_t) 0x99)
    #define CH8_CFG2_DVOL_M23P5dB											((uint8_t) 0x9A)
    #define CH8_CFG2_DVOL_M23dB												((uint8_t) 0x9B)
    #define CH8_CFG2_DVOL_M22P5dB											((uint8_t) 0x9C)
    #define CH8_CFG2_DVOL_M22dB												((uint8_t) 0x9D)
    #define CH8_CFG2_DVOL_M21P5dB											((uint8_t) 0x9E)
    #define CH8_CFG2_DVOL_M21dB												((uint8_t) 0x9F)
    #define CH8_CFG2_DVOL_M20P5dB											((uint8_t) 0xA0)
    #define CH8_CFG2_DVOL_M20dB												((uint8_t) 0xA1)
    #define CH8_CFG2_DVOL_M19P5dB											((uint8_t) 0xA2)
    #define CH8_CFG2_DVOL_M19dB												((uint8_t) 0xA3)
    #define CH8_CFG2_DVOL_M18P5dB											((uint8_t) 0xA4)
    #define CH8_CFG2_DVOL_M18dB												((uint8_t) 0xA5)
    #define CH8_CFG2_DVOL_M17P5dB											((uint8_t) 0xA6)
    #define CH8_CFG2_DVOL_M17dB												((uint8_t) 0xA7)
    #define CH8_CFG2_DVOL_M16P5dB											((uint8_t) 0xA8)
    #define CH8_CFG2_DVOL_M16dB												((uint8_t) 0xA9)
    #define CH8_CFG2_DVOL_M15P5dB											((uint8_t) 0xAA)
    #define CH8_CFG2_DVOL_M15dB												((uint8_t) 0xAB)
    #define CH8_CFG2_DVOL_M14P5dB											((uint8_t) 0xAC)
    #define CH8_CFG2_DVOL_M14dB												((uint8_t) 0xAD)
    #define CH8_CFG2_DVOL_M13P5dB											((uint8_t) 0xAE)
    #define CH8_CFG2_DVOL_M13dB												((uint8_t) 0xAF)
    #define CH8_CFG2_DVOL_M12P5dB											((uint8_t) 0xB0)
    #define CH8_CFG2_DVOL_M12dB												((uint8_t) 0xB1)
    #define CH8_CFG2_DVOL_M11P5dB											((uint8_t) 0xB2)
    #define CH8_CFG2_DVOL_M11dB												((uint8_t) 0xB3)
    #define CH8_CFG2_DVOL_M10P5dB											((uint8_t) 0xB4)
    #define CH8_CFG2_DVOL_M10dB												((uint8_t) 0xB5)
    #define CH8_CFG2_DVOL_M9P5dB											((uint8_t) 0xB6)
    #define CH8_CFG2_DVOL_M9dB												((uint8_t) 0xB7)
    #define CH8_CFG2_DVOL_M8P5dB											((uint8_t) 0xB8)
    #define CH8_CFG2_DVOL_M8dB												((uint8_t) 0xB9)
    #define CH8_CFG2_DVOL_M7P5dB											((uint8_t) 0xBA)
    #define CH8_CFG2_DVOL_M7dB												((uint8_t) 0xBB)
    #define CH8_CFG2_DVOL_M6P5dB											((uint8_t) 0xBC)
    #define CH8_CFG2_DVOL_M6dB												((uint8_t) 0xBD)
    #define CH8_CFG2_DVOL_M5P5dB											((uint8_t) 0xBE)
    #define CH8_CFG2_DVOL_M5dB												((uint8_t) 0xBF)
    #define CH8_CFG2_DVOL_M4P5dB											((uint8_t) 0xC0)
    #define CH8_CFG2_DVOL_M4dB												((uint8_t) 0xC1)
    #define CH8_CFG2_DVOL_M3P5dB											((uint8_t) 0xC2)
    #define CH8_CFG2_DVOL_M3dB												((uint8_t) 0xC3)
    #define CH8_CFG2_DVOL_M2P5dB											((uint8_t) 0xC4)
    #define CH8_CFG2_DVOL_M2dB												((uint8_t) 0xC5)
    #define CH8_CFG2_DVOL_M1P5dB											((uint8_t) 0xC6)
    #define CH8_CFG2_DVOL_M1dB												((uint8_t) 0xC7)
    #define CH8_CFG2_DVOL_M0P5dB											((uint8_t) 0xC8)
    #define CH8_CFG2_DVOL_0dB												((uint8_t) 0xC9)    // DEFAULT
    #define CH8_CFG2_DVOL_0P5dB												((uint8_t) 0xCA)
    #define CH8_CFG2_DVOL_1dB												((uint8_t) 0xCB)
    #define CH8_CFG2_DVOL_1P5dB												((uint8_t) 0xCC)
    #define CH8_CFG2_DVOL_2dB												((uint8_t) 0xCD)
    #define CH8_CFG2_DVOL_2P5dB												((uint8_t) 0xCE)
    #define CH8_CFG2_DVOL_3dB												((uint8_t) 0xCF)
    #define CH8_CFG2_DVOL_3P5dB												((uint8_t) 0xD0)
    #define CH8_CFG2_DVOL_4dB												((uint8_t) 0xD1)
    #define CH8_CFG2_DVOL_4P5dB												((uint8_t) 0xD2)
    #define CH8_CFG2_DVOL_5dB												((uint8_t) 0xD3)
    #define CH8_CFG2_DVOL_5P5dB												((uint8_t) 0xD4)
    #define CH8_CFG2_DVOL_6dB												((uint8_t) 0xD5)
    #define CH8_CFG2_DVOL_6P5dB												((uint8_t) 0xD6)
    #define CH8_CFG2_DVOL_7dB												((uint8_t) 0xD7)
    #define CH8_CFG2_DVOL_7P5dB												((uint8_t) 0xD8)
    #define CH8_CFG2_DVOL_8dB												((uint8_t) 0xD9)
    #define CH8_CFG2_DVOL_8P5dB												((uint8_t) 0xDA)
    #define CH8_CFG2_DVOL_9dB												((uint8_t) 0xDB)
    #define CH8_CFG2_DVOL_9P5dB												((uint8_t) 0xDC)
    #define CH8_CFG2_DVOL_10dB												((uint8_t) 0xDD)
    #define CH8_CFG2_DVOL_10P5dB											((uint8_t) 0xDE)
    #define CH8_CFG2_DVOL_11dB												((uint8_t) 0xDF)
    #define CH8_CFG2_DVOL_11P5dB											((uint8_t) 0xE0)
    #define CH8_CFG2_DVOL_12dB												((uint8_t) 0xE1)
    #define CH8_CFG2_DVOL_12P5dB											((uint8_t) 0xE2)
    #define CH8_CFG2_DVOL_13dB												((uint8_t) 0xE3)
    #define CH8_CFG2_DVOL_13P5dB											((uint8_t) 0xE4)
    #define CH8_CFG2_DVOL_14dB												((uint8_t) 0xE5)
    #define CH8_CFG2_DVOL_14P5dB											((uint8_t) 0xE6)
    #define CH8_CFG2_DVOL_15dB												((uint8_t) 0xE7)
    #define CH8_CFG2_DVOL_15P5dB											((uint8_t) 0xE8)
    #define CH8_CFG2_DVOL_16dB												((uint8_t) 0xE9)
    #define CH8_CFG2_DVOL_16P5dB											((uint8_t) 0xEA)
    #define CH8_CFG2_DVOL_17dB												((uint8_t) 0xEB)
    #define CH8_CFG2_DVOL_17P5dB											((uint8_t) 0xEC)
    #define CH8_CFG2_DVOL_18dB												((uint8_t) 0xED)
    #define CH8_CFG2_DVOL_18P5dB											((uint8_t) 0xEE)
    #define CH8_CFG2_DVOL_19dB												((uint8_t) 0xEF)
    #define CH8_CFG2_DVOL_19P5dB											((uint8_t) 0xF0)
    #define CH8_CFG2_DVOL_20dB												((uint8_t) 0xF1)
    #define CH8_CFG2_DVOL_20P5dB											((uint8_t) 0xF2)
    #define CH8_CFG2_DVOL_21dB												((uint8_t) 0xF3)
    #define CH8_CFG2_DVOL_21P5dB											((uint8_t) 0xF4)
    #define CH8_CFG2_DVOL_22dB												((uint8_t) 0xF5)
    #define CH8_CFG2_DVOL_22P5dB											((uint8_t) 0xF6)
    #define CH8_CFG2_DVOL_23dB												((uint8_t) 0xF7)
    #define CH8_CFG2_DVOL_23P5dB											((uint8_t) 0xF8)
    #define CH8_CFG2_DVOL_24dB												((uint8_t) 0xF9)
    #define CH8_CFG2_DVOL_24P5dB											((uint8_t) 0xFA)
    #define CH8_CFG2_DVOL_25dB												((uint8_t) 0xFB)
    #define CH8_CFG2_DVOL_25P5dB											((uint8_t) 0xFC)
    #define CH8_CFG2_DVOL_26dB												((uint8_t) 0xFD)
    #define CH8_CFG2_DVOL_26P5dB											((uint8_t) 0xFE)
    #define CH8_CFG2_DVOL_27dB												((uint8_t) 0xFF)



/* Register 0x62 (CH8_CFG3) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                       GCAL[3:0]                                       |                                     RESERVED[3:0]                                     |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH8_CFG3 register */
    #define CH8_CFG3_ADDRESS												((uint8_t) 0x62)
    #define CH8_CFG3_DEFAULT												((uint8_t) 0x80)

    /* GCAL field */
    #define CH8_CFG3_GCAL_MASK												((uint8_t) 0xF0)
    #define CH8_CFG3_GCAL_M0P8dB											((uint8_t) 0x00)
    #define CH8_CFG3_GCAL_M0P7dB											((uint8_t) 0x10)
    #define CH8_CFG3_GCAL_M0P6dB											((uint8_t) 0x20)
    #define CH8_CFG3_GCAL_M0P5dB											((uint8_t) 0x30)
    #define CH8_CFG3_GCAL_M0P4dB											((uint8_t) 0x40)
    #define CH8_CFG3_GCAL_M0P3dB											((uint8_t) 0x50)
    #define CH8_CFG3_GCAL_M0P2dB											((uint8_t) 0x60)
    #define CH8_CFG3_GCAL_M0P1dB											((uint8_t) 0x70)
    #define CH8_CFG3_GCAL_0dB												((uint8_t) 0x80)    // DEFAULT
    #define CH8_CFG3_GCAL_0P1dB												((uint8_t) 0x90)
    #define CH8_CFG3_GCAL_0P2dB												((uint8_t) 0xA0)
    #define CH8_CFG3_GCAL_0P3dB												((uint8_t) 0xB0)
    #define CH8_CFG3_GCAL_0P4dB												((uint8_t) 0xC0)
    #define CH8_CFG3_GCAL_0P5dB												((uint8_t) 0xD0)
    #define CH8_CFG3_GCAL_0P6dB												((uint8_t) 0xE0)
    #define CH8_CFG3_GCAL_0P7dB												((uint8_t) 0xF0)



/* Register 0x63 (CH8_CFG4) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                                                   PCAL[7:0]                                                                                   |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH8_CFG4 register */
    #define CH8_CFG4_ADDRESS												((uint8_t) 0x63)
    #define CH8_CFG4_DEFAULT												((uint8_t) 0x00)

    /* PCAL field */
    #define CH8_CFG4_PCAL_MASK												((uint8_t) 0xFF)
    #define CH8_CFG4_PCAL_0													((uint8_t) 0x00)    // DEFAULT
    #define CH8_CFG4_PCAL_1													((uint8_t) 0x01)
    #define CH8_CFG4_PCAL_2													((uint8_t) 0x02)
    #define CH8_CFG4_PCAL_3													((uint8_t) 0x03)
    #define CH8_CFG4_PCAL_4													((uint8_t) 0x04)
    #define CH8_CFG4_PCAL_5													((uint8_t) 0x05)
    #define CH8_CFG4_PCAL_6													((uint8_t) 0x06)
    #define CH8_CFG4_PCAL_7													((uint8_t) 0x07)
    #define CH8_CFG4_PCAL_8													((uint8_t) 0x08)
    #define CH8_CFG4_PCAL_9													((uint8_t) 0x09)
    #define CH8_CFG4_PCAL_10												((uint8_t) 0x0A)
    #define CH8_CFG4_PCAL_11												((uint8_t) 0x0B)
    #define CH8_CFG4_PCAL_12												((uint8_t) 0x0C)
    #define CH8_CFG4_PCAL_13												((uint8_t) 0x0D)
    #define CH8_CFG4_PCAL_14												((uint8_t) 0x0E)
    #define CH8_CFG4_PCAL_15												((uint8_t) 0x0F)
    #define CH8_CFG4_PCAL_16												((uint8_t) 0x10)
    #define CH8_CFG4_PCAL_17												((uint8_t) 0x11)
    #define CH8_CFG4_PCAL_18												((uint8_t) 0x12)
    #define CH8_CFG4_PCAL_19												((uint8_t) 0x13)
    #define CH8_CFG4_PCAL_20												((uint8_t) 0x14)
    #define CH8_CFG4_PCAL_21												((uint8_t) 0x15)
    #define CH8_CFG4_PCAL_22												((uint8_t) 0x16)
    #define CH8_CFG4_PCAL_23												((uint8_t) 0x17)
    #define CH8_CFG4_PCAL_24												((uint8_t) 0x18)
    #define CH8_CFG4_PCAL_25												((uint8_t) 0x19)
    #define CH8_CFG4_PCAL_26												((uint8_t) 0x1A)
    #define CH8_CFG4_PCAL_27												((uint8_t) 0x1B)
    #define CH8_CFG4_PCAL_28												((uint8_t) 0x1C)
    #define CH8_CFG4_PCAL_29												((uint8_t) 0x1D)
    #define CH8_CFG4_PCAL_30												((uint8_t) 0x1E)
    #define CH8_CFG4_PCAL_31												((uint8_t) 0x1F)
    #define CH8_CFG4_PCAL_32												((uint8_t) 0x20)
    #define CH8_CFG4_PCAL_33												((uint8_t) 0x21)
    #define CH8_CFG4_PCAL_34												((uint8_t) 0x22)
    #define CH8_CFG4_PCAL_35												((uint8_t) 0x23)
    #define CH8_CFG4_PCAL_36												((uint8_t) 0x24)
    #define CH8_CFG4_PCAL_37												((uint8_t) 0x25)
    #define CH8_CFG4_PCAL_38												((uint8_t) 0x26)
    #define CH8_CFG4_PCAL_39												((uint8_t) 0x27)
    #define CH8_CFG4_PCAL_40												((uint8_t) 0x28)
    #define CH8_CFG4_PCAL_41												((uint8_t) 0x29)
    #define CH8_CFG4_PCAL_42												((uint8_t) 0x2A)
    #define CH8_CFG4_PCAL_43												((uint8_t) 0x2B)
    #define CH8_CFG4_PCAL_44												((uint8_t) 0x2C)
    #define CH8_CFG4_PCAL_45												((uint8_t) 0x2D)
    #define CH8_CFG4_PCAL_46												((uint8_t) 0x2E)
    #define CH8_CFG4_PCAL_47												((uint8_t) 0x2F)
    #define CH8_CFG4_PCAL_48												((uint8_t) 0x30)
    #define CH8_CFG4_PCAL_49												((uint8_t) 0x31)
    #define CH8_CFG4_PCAL_50												((uint8_t) 0x32)
    #define CH8_CFG4_PCAL_51												((uint8_t) 0x33)
    #define CH8_CFG4_PCAL_52												((uint8_t) 0x34)
    #define CH8_CFG4_PCAL_53												((uint8_t) 0x35)
    #define CH8_CFG4_PCAL_54												((uint8_t) 0x36)
    #define CH8_CFG4_PCAL_55												((uint8_t) 0x37)
    #define CH8_CFG4_PCAL_56												((uint8_t) 0x38)
    #define CH8_CFG4_PCAL_57												((uint8_t) 0x39)
    #define CH8_CFG4_PCAL_58												((uint8_t) 0x3A)
    #define CH8_CFG4_PCAL_59												((uint8_t) 0x3B)
    #define CH8_CFG4_PCAL_60												((uint8_t) 0x3C)
    #define CH8_CFG4_PCAL_61												((uint8_t) 0x3D)
    #define CH8_CFG4_PCAL_62												((uint8_t) 0x3E)
    #define CH8_CFG4_PCAL_63												((uint8_t) 0x3F)
    #define CH8_CFG4_PCAL_64												((uint8_t) 0x40)
    #define CH8_CFG4_PCAL_65												((uint8_t) 0x41)
    #define CH8_CFG4_PCAL_66												((uint8_t) 0x42)
    #define CH8_CFG4_PCAL_67												((uint8_t) 0x43)
    #define CH8_CFG4_PCAL_68												((uint8_t) 0x44)
    #define CH8_CFG4_PCAL_69												((uint8_t) 0x45)
    #define CH8_CFG4_PCAL_70												((uint8_t) 0x46)
    #define CH8_CFG4_PCAL_71												((uint8_t) 0x47)
    #define CH8_CFG4_PCAL_72												((uint8_t) 0x48)
    #define CH8_CFG4_PCAL_73												((uint8_t) 0x49)
    #define CH8_CFG4_PCAL_74												((uint8_t) 0x4A)
    #define CH8_CFG4_PCAL_75												((uint8_t) 0x4B)
    #define CH8_CFG4_PCAL_76												((uint8_t) 0x4C)
    #define CH8_CFG4_PCAL_77												((uint8_t) 0x4D)
    #define CH8_CFG4_PCAL_78												((uint8_t) 0x4E)
    #define CH8_CFG4_PCAL_79												((uint8_t) 0x4F)
    #define CH8_CFG4_PCAL_80												((uint8_t) 0x50)
    #define CH8_CFG4_PCAL_81												((uint8_t) 0x51)
    #define CH8_CFG4_PCAL_82												((uint8_t) 0x52)
    #define CH8_CFG4_PCAL_83												((uint8_t) 0x53)
    #define CH8_CFG4_PCAL_84												((uint8_t) 0x54)
    #define CH8_CFG4_PCAL_85												((uint8_t) 0x55)
    #define CH8_CFG4_PCAL_86												((uint8_t) 0x56)
    #define CH8_CFG4_PCAL_87												((uint8_t) 0x57)
    #define CH8_CFG4_PCAL_88												((uint8_t) 0x58)
    #define CH8_CFG4_PCAL_89												((uint8_t) 0x59)
    #define CH8_CFG4_PCAL_90												((uint8_t) 0x5A)
    #define CH8_CFG4_PCAL_91												((uint8_t) 0x5B)
    #define CH8_CFG4_PCAL_92												((uint8_t) 0x5C)
    #define CH8_CFG4_PCAL_93												((uint8_t) 0x5D)
    #define CH8_CFG4_PCAL_94												((uint8_t) 0x5E)
    #define CH8_CFG4_PCAL_95												((uint8_t) 0x5F)
    #define CH8_CFG4_PCAL_96												((uint8_t) 0x60)
    #define CH8_CFG4_PCAL_97												((uint8_t) 0x61)
    #define CH8_CFG4_PCAL_98												((uint8_t) 0x62)
    #define CH8_CFG4_PCAL_99												((uint8_t) 0x63)
    #define CH8_CFG4_PCAL_100												((uint8_t) 0x64)
    #define CH8_CFG4_PCAL_101												((uint8_t) 0x65)
    #define CH8_CFG4_PCAL_102												((uint8_t) 0x66)
    #define CH8_CFG4_PCAL_103												((uint8_t) 0x67)
    #define CH8_CFG4_PCAL_104												((uint8_t) 0x68)
    #define CH8_CFG4_PCAL_105												((uint8_t) 0x69)
    #define CH8_CFG4_PCAL_106												((uint8_t) 0x6A)
    #define CH8_CFG4_PCAL_107												((uint8_t) 0x6B)
    #define CH8_CFG4_PCAL_108												((uint8_t) 0x6C)
    #define CH8_CFG4_PCAL_109												((uint8_t) 0x6D)
    #define CH8_CFG4_PCAL_110												((uint8_t) 0x6E)
    #define CH8_CFG4_PCAL_111												((uint8_t) 0x6F)
    #define CH8_CFG4_PCAL_112												((uint8_t) 0x70)
    #define CH8_CFG4_PCAL_113												((uint8_t) 0x71)
    #define CH8_CFG4_PCAL_114												((uint8_t) 0x72)
    #define CH8_CFG4_PCAL_115												((uint8_t) 0x73)
    #define CH8_CFG4_PCAL_116												((uint8_t) 0x74)
    #define CH8_CFG4_PCAL_117												((uint8_t) 0x75)
    #define CH8_CFG4_PCAL_118												((uint8_t) 0x76)
    #define CH8_CFG4_PCAL_119												((uint8_t) 0x77)
    #define CH8_CFG4_PCAL_120												((uint8_t) 0x78)
    #define CH8_CFG4_PCAL_121												((uint8_t) 0x79)
    #define CH8_CFG4_PCAL_122												((uint8_t) 0x7A)
    #define CH8_CFG4_PCAL_123												((uint8_t) 0x7B)
    #define CH8_CFG4_PCAL_124												((uint8_t) 0x7C)
    #define CH8_CFG4_PCAL_125												((uint8_t) 0x7D)
    #define CH8_CFG4_PCAL_126												((uint8_t) 0x7E)
    #define CH8_CFG4_PCAL_127												((uint8_t) 0x7F)
    #define CH8_CFG4_PCAL_128												((uint8_t) 0x80)
    #define CH8_CFG4_PCAL_129												((uint8_t) 0x81)
    #define CH8_CFG4_PCAL_130												((uint8_t) 0x82)
    #define CH8_CFG4_PCAL_131												((uint8_t) 0x83)
    #define CH8_CFG4_PCAL_132												((uint8_t) 0x84)
    #define CH8_CFG4_PCAL_133												((uint8_t) 0x85)
    #define CH8_CFG4_PCAL_134												((uint8_t) 0x86)
    #define CH8_CFG4_PCAL_135												((uint8_t) 0x87)
    #define CH8_CFG4_PCAL_136												((uint8_t) 0x88)
    #define CH8_CFG4_PCAL_137												((uint8_t) 0x89)
    #define CH8_CFG4_PCAL_138												((uint8_t) 0x8A)
    #define CH8_CFG4_PCAL_139												((uint8_t) 0x8B)
    #define CH8_CFG4_PCAL_140												((uint8_t) 0x8C)
    #define CH8_CFG4_PCAL_141												((uint8_t) 0x8D)
    #define CH8_CFG4_PCAL_142												((uint8_t) 0x8E)
    #define CH8_CFG4_PCAL_143												((uint8_t) 0x8F)
    #define CH8_CFG4_PCAL_144												((uint8_t) 0x90)
    #define CH8_CFG4_PCAL_145												((uint8_t) 0x91)
    #define CH8_CFG4_PCAL_146												((uint8_t) 0x92)
    #define CH8_CFG4_PCAL_147												((uint8_t) 0x93)
    #define CH8_CFG4_PCAL_148												((uint8_t) 0x94)
    #define CH8_CFG4_PCAL_149												((uint8_t) 0x95)
    #define CH8_CFG4_PCAL_150												((uint8_t) 0x96)
    #define CH8_CFG4_PCAL_151												((uint8_t) 0x97)
    #define CH8_CFG4_PCAL_152												((uint8_t) 0x98)
    #define CH8_CFG4_PCAL_153												((uint8_t) 0x99)
    #define CH8_CFG4_PCAL_154												((uint8_t) 0x9A)
    #define CH8_CFG4_PCAL_155												((uint8_t) 0x9B)
    #define CH8_CFG4_PCAL_156												((uint8_t) 0x9C)
    #define CH8_CFG4_PCAL_157												((uint8_t) 0x9D)
    #define CH8_CFG4_PCAL_158												((uint8_t) 0x9E)
    #define CH8_CFG4_PCAL_159												((uint8_t) 0x9F)
    #define CH8_CFG4_PCAL_160												((uint8_t) 0xA0)
    #define CH8_CFG4_PCAL_161												((uint8_t) 0xA1)
    #define CH8_CFG4_PCAL_162												((uint8_t) 0xA2)
    #define CH8_CFG4_PCAL_163												((uint8_t) 0xA3)
    #define CH8_CFG4_PCAL_164												((uint8_t) 0xA4)
    #define CH8_CFG4_PCAL_165												((uint8_t) 0xA5)
    #define CH8_CFG4_PCAL_166												((uint8_t) 0xA6)
    #define CH8_CFG4_PCAL_167												((uint8_t) 0xA7)
    #define CH8_CFG4_PCAL_168												((uint8_t) 0xA8)
    #define CH8_CFG4_PCAL_169												((uint8_t) 0xA9)
    #define CH8_CFG4_PCAL_170												((uint8_t) 0xAA)
    #define CH8_CFG4_PCAL_171												((uint8_t) 0xAB)
    #define CH8_CFG4_PCAL_172												((uint8_t) 0xAC)
    #define CH8_CFG4_PCAL_173												((uint8_t) 0xAD)
    #define CH8_CFG4_PCAL_174												((uint8_t) 0xAE)
    #define CH8_CFG4_PCAL_175												((uint8_t) 0xAF)
    #define CH8_CFG4_PCAL_176												((uint8_t) 0xB0)
    #define CH8_CFG4_PCAL_177												((uint8_t) 0xB1)
    #define CH8_CFG4_PCAL_178												((uint8_t) 0xB2)
    #define CH8_CFG4_PCAL_179												((uint8_t) 0xB3)
    #define CH8_CFG4_PCAL_180												((uint8_t) 0xB4)
    #define CH8_CFG4_PCAL_181												((uint8_t) 0xB5)
    #define CH8_CFG4_PCAL_182												((uint8_t) 0xB6)
    #define CH8_CFG4_PCAL_183												((uint8_t) 0xB7)
    #define CH8_CFG4_PCAL_184												((uint8_t) 0xB8)
    #define CH8_CFG4_PCAL_185												((uint8_t) 0xB9)
    #define CH8_CFG4_PCAL_186												((uint8_t) 0xBA)
    #define CH8_CFG4_PCAL_187												((uint8_t) 0xBB)
    #define CH8_CFG4_PCAL_188												((uint8_t) 0xBC)
    #define CH8_CFG4_PCAL_189												((uint8_t) 0xBD)
    #define CH8_CFG4_PCAL_190												((uint8_t) 0xBE)
    #define CH8_CFG4_PCAL_191												((uint8_t) 0xBF)
    #define CH8_CFG4_PCAL_192												((uint8_t) 0xC0)
    #define CH8_CFG4_PCAL_193												((uint8_t) 0xC1)
    #define CH8_CFG4_PCAL_194												((uint8_t) 0xC2)
    #define CH8_CFG4_PCAL_195												((uint8_t) 0xC3)
    #define CH8_CFG4_PCAL_196												((uint8_t) 0xC4)
    #define CH8_CFG4_PCAL_197												((uint8_t) 0xC5)
    #define CH8_CFG4_PCAL_198												((uint8_t) 0xC6)
    #define CH8_CFG4_PCAL_199												((uint8_t) 0xC7)
    #define CH8_CFG4_PCAL_200												((uint8_t) 0xC8)
    #define CH8_CFG4_PCAL_201												((uint8_t) 0xC9)
    #define CH8_CFG4_PCAL_202												((uint8_t) 0xCA)
    #define CH8_CFG4_PCAL_203												((uint8_t) 0xCB)
    #define CH8_CFG4_PCAL_204												((uint8_t) 0xCC)
    #define CH8_CFG4_PCAL_205												((uint8_t) 0xCD)
    #define CH8_CFG4_PCAL_206												((uint8_t) 0xCE)
    #define CH8_CFG4_PCAL_207												((uint8_t) 0xCF)
    #define CH8_CFG4_PCAL_208												((uint8_t) 0xD0)
    #define CH8_CFG4_PCAL_209												((uint8_t) 0xD1)
    #define CH8_CFG4_PCAL_210												((uint8_t) 0xD2)
    #define CH8_CFG4_PCAL_211												((uint8_t) 0xD3)
    #define CH8_CFG4_PCAL_212												((uint8_t) 0xD4)
    #define CH8_CFG4_PCAL_213												((uint8_t) 0xD5)
    #define CH8_CFG4_PCAL_214												((uint8_t) 0xD6)
    #define CH8_CFG4_PCAL_215												((uint8_t) 0xD7)
    #define CH8_CFG4_PCAL_216												((uint8_t) 0xD8)
    #define CH8_CFG4_PCAL_217												((uint8_t) 0xD9)
    #define CH8_CFG4_PCAL_218												((uint8_t) 0xDA)
    #define CH8_CFG4_PCAL_219												((uint8_t) 0xDB)
    #define CH8_CFG4_PCAL_220												((uint8_t) 0xDC)
    #define CH8_CFG4_PCAL_221												((uint8_t) 0xDD)
    #define CH8_CFG4_PCAL_222												((uint8_t) 0xDE)
    #define CH8_CFG4_PCAL_223												((uint8_t) 0xDF)
    #define CH8_CFG4_PCAL_224												((uint8_t) 0xE0)
    #define CH8_CFG4_PCAL_225												((uint8_t) 0xE1)
    #define CH8_CFG4_PCAL_226												((uint8_t) 0xE2)
    #define CH8_CFG4_PCAL_227												((uint8_t) 0xE3)
    #define CH8_CFG4_PCAL_228												((uint8_t) 0xE4)
    #define CH8_CFG4_PCAL_229												((uint8_t) 0xE5)
    #define CH8_CFG4_PCAL_230												((uint8_t) 0xE6)
    #define CH8_CFG4_PCAL_231												((uint8_t) 0xE7)
    #define CH8_CFG4_PCAL_232												((uint8_t) 0xE8)
    #define CH8_CFG4_PCAL_233												((uint8_t) 0xE9)
    #define CH8_CFG4_PCAL_234												((uint8_t) 0xEA)
    #define CH8_CFG4_PCAL_235												((uint8_t) 0xEB)
    #define CH8_CFG4_PCAL_236												((uint8_t) 0xEC)
    #define CH8_CFG4_PCAL_237												((uint8_t) 0xED)
    #define CH8_CFG4_PCAL_238												((uint8_t) 0xEE)
    #define CH8_CFG4_PCAL_239												((uint8_t) 0xEF)
    #define CH8_CFG4_PCAL_240												((uint8_t) 0xF0)
    #define CH8_CFG4_PCAL_241												((uint8_t) 0xF1)
    #define CH8_CFG4_PCAL_242												((uint8_t) 0xF2)
    #define CH8_CFG4_PCAL_243												((uint8_t) 0xF3)
    #define CH8_CFG4_PCAL_244												((uint8_t) 0xF4)
    #define CH8_CFG4_PCAL_245												((uint8_t) 0xF5)
    #define CH8_CFG4_PCAL_246												((uint8_t) 0xF6)
    #define CH8_CFG4_PCAL_247												((uint8_t) 0xF7)
    #define CH8_CFG4_PCAL_248												((uint8_t) 0xF8)
    #define CH8_CFG4_PCAL_249												((uint8_t) 0xF9)
    #define CH8_CFG4_PCAL_250												((uint8_t) 0xFA)
    #define CH8_CFG4_PCAL_251												((uint8_t) 0xFB)
    #define CH8_CFG4_PCAL_252												((uint8_t) 0xFC)
    #define CH8_CFG4_PCAL_253												((uint8_t) 0xFD)
    #define CH8_CFG4_PCAL_254												((uint8_t) 0xFE)
    #define CH8_CFG4_PCAL_255												((uint8_t) 0xFF)



/* Register 0x6B (DSP_CFG0) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |               RESERVED[1:0]               |               DECI_FILT[1:0]              |                CH_SUM[1:0]                |                HPF_SEL[1:0]               |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* DSP_CFG0 register */
    #define DSP_CFG0_ADDRESS												((uint8_t) 0x6B)
    #define DSP_CFG0_DEFAULT												((uint8_t) 0x01)

    /* DECI_FILT field */
    #define DSP_CFG0_DECI_FILT_MASK											((uint8_t) 0x30)
    #define DSP_CFG0_DECI_FILT_LINEAR										((uint8_t) 0x00)    // DEFAULT
    #define DSP_CFG0_DECI_FILT_LOWLAT										((uint8_t) 0x10)
    #define DSP_CFG0_DECI_FILT_ULTRALOWLAT									((uint8_t) 0x20)

    /* CH_SUM field */
    #define DSP_CFG0_CH_SUM_MASK											((uint8_t) 0x0C)
    #define DSP_CFG0_CH_SUM_DISABLED										((uint8_t) 0x00)    // DEFAULT
    #define DSP_CFG0_CH_SUM_2CH												((uint8_t) 0x04)
    #define DSP_CFG0_CH_SUM_4CH												((uint8_t) 0x08)

    /* HPF_SEL field */
    #define DSP_CFG0_HPF_SEL_MASK											((uint8_t) 0x03)
    #define DSP_CFG0_HPF_SEL_PROG											((uint8_t) 0x00)
    #define DSP_CFG0_HPF_SEL_0P00025FS										((uint8_t) 0x01)    // DEFAULT
    #define DSP_CFG0_HPF_SEL_0P002FS										((uint8_t) 0x02)
    #define DSP_CFG0_HPF_SEL_0P008FS										((uint8_t) 0x03)



/* Register 0x6C (DSP_CFG1) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |      DVOL_GANG      |              BIQUAD_CFG[1:0]              |  DISABLE_SOFT_STEP  |     DRE_AGC_SEL     |                          RESERVED[2:0]                          |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* DSP_CFG1 register */
    #define DSP_CFG1_ADDRESS												((uint8_t) 0x6C)
    #define DSP_CFG1_DEFAULT												((uint8_t) 0x40)

    /* DVOL_GANG field */
    #define DSP_CFG1_DVOL_GANG_MASK											((uint8_t) 0x80)
    #define DSP_CFG1_DVOL_GANG_INDIVIDUAL									((uint8_t) 0x00)    // DEFAULT
    #define DSP_CFG1_DVOL_GANG_GLOBAL										((uint8_t) 0x80)

    /* BIQUAD_CFG field */
    #define DSP_CFG1_BIQUAD_CFG_MASK										((uint8_t) 0x60)
    #define DSP_CFG1_BIQUAD_CFG_NONE										((uint8_t) 0x00)
    #define DSP_CFG1_BIQUAD_CFG_1											((uint8_t) 0x20)
    #define DSP_CFG1_BIQUAD_CFG_2											((uint8_t) 0x40)    // DEFAULT
    #define DSP_CFG1_BIQUAD_CFG_3											((uint8_t) 0x60)

    /* DISABLE_SOFT_STEP field */
    #define DSP_CFG1_DISABLE_SOFT_STEP_MASK									((uint8_t) 0x10)
    #define DSP_CFG1_DISABLE_SOFT_STEP_ENABLED								((uint8_t) 0x00)    // DEFAULT
    #define DSP_CFG1_DISABLE_SOFT_STEP_DISABLED								((uint8_t) 0x10)

    /* DRE_AGC_SEL field */
    #define DSP_CFG1_DRE_AGC_SEL_MASK										((uint8_t) 0x08)
    #define DSP_CFG1_DRE_AGC_SEL_DRE										((uint8_t) 0x00)    // DEFAULT
    #define DSP_CFG1_DRE_AGC_SEL_AGC										((uint8_t) 0x08)



/* Register 0x6D (DRE_CFG0) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                      DRE_LVL[3:0]                                     |                                    DRE_MAXGAIN[3:0]                                   |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* DRE_CFG0 register */
    #define DRE_CFG0_ADDRESS												((uint8_t) 0x6D)
    #define DRE_CFG0_DEFAULT												((uint8_t) 0x7B)

    /* DRE_LVL field */
    #define DRE_CFG0_DRE_LVL_MASK											((uint8_t) 0xF0)
    #define DRE_CFG0_DRE_LVL_M12dB											((uint8_t) 0x00)
    #define DRE_CFG0_DRE_LVL_M18dB											((uint8_t) 0x10)
    #define DRE_CFG0_DRE_LVL_M24dB											((uint8_t) 0x20)
    #define DRE_CFG0_DRE_LVL_M30dB											((uint8_t) 0x30)
    #define DRE_CFG0_DRE_LVL_M36dB											((uint8_t) 0x40)
    #define DRE_CFG0_DRE_LVL_M42dB											((uint8_t) 0x50)
    #define DRE_CFG0_DRE_LVL_M48dB											((uint8_t) 0x60)
    #define DRE_CFG0_DRE_LVL_M54dB											((uint8_t) 0x70)    // DEFAULT
    #define DRE_CFG0_DRE_LVL_M60dB											((uint8_t) 0x80)
    #define DRE_CFG0_DRE_LVL_M66dB											((uint8_t) 0x90)

    /* DRE_MAXGAIN field */
    #define DRE_CFG0_DRE_MAXGAIN_MASK										((uint8_t) 0x0F)
    #define DRE_CFG0_DRE_MAXGAIN_2dB										((uint8_t) 0x00)
    #define DRE_CFG0_DRE_MAXGAIN_4dB										((uint8_t) 0x01)
    #define DRE_CFG0_DRE_MAXGAIN_6dB										((uint8_t) 0x02)
    #define DRE_CFG0_DRE_MAXGAIN_8dB										((uint8_t) 0x03)
    #define DRE_CFG0_DRE_MAXGAIN_10dB										((uint8_t) 0x04)
    #define DRE_CFG0_DRE_MAXGAIN_12dB										((uint8_t) 0x05)
    #define DRE_CFG0_DRE_MAXGAIN_14dB										((uint8_t) 0x06)
    #define DRE_CFG0_DRE_MAXGAIN_16dB										((uint8_t) 0x07)
    #define DRE_CFG0_DRE_MAXGAIN_18dB										((uint8_t) 0x08)
    #define DRE_CFG0_DRE_MAXGAIN_20dB										((uint8_t) 0x09)
    #define DRE_CFG0_DRE_MAXGAIN_22dB										((uint8_t) 0x0A)
    #define DRE_CFG0_DRE_MAXGAIN_24dB										((uint8_t) 0x0B)    // DEFAULT
    #define DRE_CFG0_DRE_MAXGAIN_26dB										((uint8_t) 0x0C)



/* Register 0x70 (AGC_CFG0) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                      AGC_LVL[3:0]                                     |                                    AGC_MAXGAIN[3:0]                                   |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* AGC_CFG0 register */
    #define AGC_CFG0_ADDRESS												((uint8_t) 0x70)
    #define AGC_CFG0_DEFAULT												((uint8_t) 0xE7)

    /* AGC_LVL field */
    #define AGC_CFG0_AGC_LVL_MASK											((uint8_t) 0xF0)
    #define AGC_CFG0_AGC_LVL_M6dB											((uint8_t) 0x00)
    #define AGC_CFG0_AGC_LVL_M8dB											((uint8_t) 0x10)
    #define AGC_CFG0_AGC_LVL_M10dB											((uint8_t) 0x20)
    #define AGC_CFG0_AGC_LVL_M12dB											((uint8_t) 0x30)
    #define AGC_CFG0_AGC_LVL_M14dB											((uint8_t) 0x40)
    #define AGC_CFG0_AGC_LVL_M16dB											((uint8_t) 0x50)
    #define AGC_CFG0_AGC_LVL_M18dB											((uint8_t) 0x60)
    #define AGC_CFG0_AGC_LVL_M20dB											((uint8_t) 0x70)
    #define AGC_CFG0_AGC_LVL_M22dB											((uint8_t) 0x80)
    #define AGC_CFG0_AGC_LVL_M24dB											((uint8_t) 0x90)
    #define AGC_CFG0_AGC_LVL_M26dB											((uint8_t) 0xA0)
    #define AGC_CFG0_AGC_LVL_M28dB											((uint8_t) 0xB0)
    #define AGC_CFG0_AGC_LVL_M30dB											((uint8_t) 0xC0)
    #define AGC_CFG0_AGC_LVL_M32dB											((uint8_t) 0xD0)
    #define AGC_CFG0_AGC_LVL_M34dB											((uint8_t) 0xE0)    // DEFAULT
    #define AGC_CFG0_AGC_LVL_M36dB											((uint8_t) 0xF0)

    /* AGC_MAXGAIN field */
    #define AGC_CFG0_AGC_MAXGAIN_MASK										((uint8_t) 0x0F)
    #define AGC_CFG0_AGC_MAXGAIN_3dB										((uint8_t) 0x00)
    #define AGC_CFG0_AGC_MAXGAIN_6dB										((uint8_t) 0x01)
    #define AGC_CFG0_AGC_MAXGAIN_9dB										((uint8_t) 0x02)
    #define AGC_CFG0_AGC_MAXGAIN_12dB										((uint8_t) 0x03)
    #define AGC_CFG0_AGC_MAXGAIN_15dB										((uint8_t) 0x04)
    #define AGC_CFG0_AGC_MAXGAIN_18dB										((uint8_t) 0x05)
    #define AGC_CFG0_AGC_MAXGAIN_21dB										((uint8_t) 0x06)
    #define AGC_CFG0_AGC_MAXGAIN_24dB										((uint8_t) 0x07)    // DEFAULT
    #define AGC_CFG0_AGC_MAXGAIN_27dB										((uint8_t) 0x08)
    #define AGC_CFG0_AGC_MAXGAIN_30dB										((uint8_t) 0x09)
    #define AGC_CFG0_AGC_MAXGAIN_33dB										((uint8_t) 0x0A)
    #define AGC_CFG0_AGC_MAXGAIN_36dB										((uint8_t) 0x0B)
    #define AGC_CFG0_AGC_MAXGAIN_39dB										((uint8_t) 0x0C)
    #define AGC_CFG0_AGC_MAXGAIN_42dB										((uint8_t) 0x0D)



/* Register 0x73 (IN_CH_EN) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |         CH1         |         CH2         |         CH3         |         CH4         |         CH5         |         CH6         |         CH7         |         CH8         |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* IN_CH_EN register */
    #define IN_CH_EN_ADDRESS												((uint8_t) 0x73)
    #define IN_CH_EN_DEFAULT												((uint8_t) 0xF0)

    /* CH1 field */
    #define IN_CH_EN_CH1_MASK												((uint8_t) 0x80)
    #define IN_CH_EN_CH1_DISABLED											((uint8_t) 0x00)
    #define IN_CH_EN_CH1_ENABLED											((uint8_t) 0x80)    // DEFAULT

    /* CH2 field */
    #define IN_CH_EN_CH2_MASK												((uint8_t) 0x40)
    #define IN_CH_EN_CH2_DISABLED											((uint8_t) 0x00)
    #define IN_CH_EN_CH2_ENABLED											((uint8_t) 0x40)    // DEFAULT

    /* CH3 field */
    #define IN_CH_EN_CH3_MASK												((uint8_t) 0x20)
    #define IN_CH_EN_CH3_DISABLED											((uint8_t) 0x00)
    #define IN_CH_EN_CH3_ENABLED											((uint8_t) 0x20)    // DEFAULT

    /* CH4 field */
    #define IN_CH_EN_CH4_MASK												((uint8_t) 0x10)
    #define IN_CH_EN_CH4_DISABLED											((uint8_t) 0x00)
    #define IN_CH_EN_CH4_ENABLED											((uint8_t) 0x10)    // DEFAULT

    /* CH5 field */
    #define IN_CH_EN_CH5_MASK												((uint8_t) 0x08)
    #define IN_CH_EN_CH5_DISABLED											((uint8_t) 0x00)    // DEFAULT
    #define IN_CH_EN_CH5_ENABLED											((uint8_t) 0x08)

    /* CH6 field */
    #define IN_CH_EN_CH6_MASK												((uint8_t) 0x04)
    #define IN_CH_EN_CH6_DISABLED											((uint8_t) 0x00)    // DEFAULT
    #define IN_CH_EN_CH6_ENABLED											((uint8_t) 0x04)

    /* CH7 field */
    #define IN_CH_EN_CH7_MASK												((uint8_t) 0x02)
    #define IN_CH_EN_CH7_DISABLED											((uint8_t) 0x00)    // DEFAULT
    #define IN_CH_EN_CH7_ENABLED											((uint8_t) 0x02)

    /* CH8 field */
    #define IN_CH_EN_CH8_MASK												((uint8_t) 0x01)
    #define IN_CH_EN_CH8_DISABLED											((uint8_t) 0x00)    // DEFAULT
    #define IN_CH_EN_CH8_ENABLED											((uint8_t) 0x01)



/* Register 0x74 (ASI_OUT_CH_EN) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |         CH1         |         CH2         |         CH3         |         CH4         |         CH5         |         CH6         |         CH7         |         CH8         |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* ASI_OUT_CH_EN register */
    #define ASI_OUT_CH_EN_ADDRESS											((uint8_t) 0x74)
    #define ASI_OUT_CH_EN_DEFAULT											((uint8_t) 0x00)

    /* CH1 field */
    #define ASI_OUT_CH_EN_CH1_MASK											((uint8_t) 0x80)
    #define ASI_OUT_CH_EN_CH1_TRI_STATE										((uint8_t) 0x00)    // DEFAULT
    #define ASI_OUT_CH_EN_CH1_ENABLED										((uint8_t) 0x80)

    /* CH2 field */
    #define ASI_OUT_CH_EN_CH2_MASK											((uint8_t) 0x40)
    #define ASI_OUT_CH_EN_CH2_TRI_STATE										((uint8_t) 0x00)    // DEFAULT
    #define ASI_OUT_CH_EN_CH2_ENABLED										((uint8_t) 0x40)

    /* CH3 field */
    #define ASI_OUT_CH_EN_CH3_MASK											((uint8_t) 0x20)
    #define ASI_OUT_CH_EN_CH3_TRI_STATE										((uint8_t) 0x00)    // DEFAULT
    #define ASI_OUT_CH_EN_CH3_ENABLED										((uint8_t) 0x20)

    /* CH4 field */
    #define ASI_OUT_CH_EN_CH4_MASK											((uint8_t) 0x10)
    #define ASI_OUT_CH_EN_CH4_TRI_STATE										((uint8_t) 0x00)    // DEFAULT
    #define ASI_OUT_CH_EN_CH4_ENABLED										((uint8_t) 0x10)

    /* CH5 field */
    #define ASI_OUT_CH_EN_CH5_MASK											((uint8_t) 0x08)
    #define ASI_OUT_CH_EN_CH5_TRI_STATE										((uint8_t) 0x00)    // DEFAULT
    #define ASI_OUT_CH_EN_CH5_ENABLED										((uint8_t) 0x08)

    /* CH6 field */
    #define ASI_OUT_CH_EN_CH6_MASK											((uint8_t) 0x04)
    #define ASI_OUT_CH_EN_CH6_TRI_STATE										((uint8_t) 0x00)    // DEFAULT
    #define ASI_OUT_CH_EN_CH6_ENABLED										((uint8_t) 0x04)

    /* CH7 field */
    #define ASI_OUT_CH_EN_CH7_MASK											((uint8_t) 0x02)
    #define ASI_OUT_CH_EN_CH7_TRI_STATE										((uint8_t) 0x00)    // DEFAULT
    #define ASI_OUT_CH_EN_CH7_ENABLED										((uint8_t) 0x02)

    /* CH8 field */
    #define ASI_OUT_CH_EN_CH8_MASK											((uint8_t) 0x01)
    #define ASI_OUT_CH_EN_CH8_TRI_STATE										((uint8_t) 0x00)    // DEFAULT
    #define ASI_OUT_CH_EN_CH8_ENABLED										((uint8_t) 0x01)



/* Register 0x75 (PWR_CFG) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |     MICBIAS_PDZ     |       ADC_PDZ       |       PLL_PDZ       |    DYN_CH_PUPD_EN   |             DYN_MAXCH_SEL[1:0]            |               RESERVED[1:0]               |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* PWR_CFG register */
    #define PWR_CFG_ADDRESS													((uint8_t) 0x75)
    #define PWR_CFG_DEFAULT													((uint8_t) 0x00)

    /* MICBIAS_PDZ field */
    #define PWR_CFG_MICBIAS_PDZ_MASK										((uint8_t) 0x80)
    #define PWR_CFG_MICBIAS_PDZ_OFF											((uint8_t) 0x00)    // DEFAULT
    #define PWR_CFG_MICBIAS_PDZ_ON											((uint8_t) 0x80)

    /* ADC_PDZ field */
    #define PWR_CFG_ADC_PDZ_MASK											((uint8_t) 0x40)
    #define PWR_CFG_ADC_PDZ_OFF												((uint8_t) 0x00)    // DEFAULT
    #define PWR_CFG_ADC_PDZ_ON												((uint8_t) 0x40)

    /* PLL_PDZ field */
    #define PWR_CFG_PLL_PDZ_MASK											((uint8_t) 0x20)
    #define PWR_CFG_PLL_PDZ_OFF												((uint8_t) 0x00)    // DEFAULT
    #define PWR_CFG_PLL_PDZ_ON												((uint8_t) 0x20)

    /* DYN_CH_PUPD_EN field */
    #define PWR_CFG_DYN_CH_PUPD_EN_MASK										((uint8_t) 0x10)
    #define PWR_CFG_DYN_CH_PUPD_EN_OFF										((uint8_t) 0x00)    // DEFAULT
    #define PWR_CFG_DYN_CH_PUPD_EN_ON										((uint8_t) 0x10)

    /* DYN_MAXCH_SEL field */
    #define PWR_CFG_DYN_MAXCH_SEL_MASK										((uint8_t) 0x0C)
    #define PWR_CFG_DYN_MAXCH_SEL_12										((uint8_t) 0x00)    // DEFAULT
    #define PWR_CFG_DYN_MAXCH_SEL_1234										((uint8_t) 0x04)
    #define PWR_CFG_DYN_MAXCH_SEL_123456									((uint8_t) 0x08)
    #define PWR_CFG_DYN_MAXCH_SEL_12345678									((uint8_t) 0x0C)



/* Register 0x76 (DEV_STS0) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |      CH1_STATUS     |      CH2_STATUS     |      CH3_STATUS     |      CH4_STATUS     |      CH5_STATUS     |      CH6_STATUS     |      CH7_STATUS     |      CH8_STATUS     |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* DEV_STS0 register */
    #define DEV_STS0_ADDRESS												((uint8_t) 0x76)
    #define DEV_STS0_DEFAULT												((uint8_t) 0x00)

    /* CH1_STATUS field */
    #define DEV_STS0_CH1_STATUS_MASK										((uint8_t) 0x80)
    #define DEV_STS0_CH1_STATUS_UNPOWERED									((uint8_t) 0x00)    // DEFAULT
    #define DEV_STS0_CH1_STATUS_POWERED										((uint8_t) 0x80)

    /* CH2_STATUS field */
    #define DEV_STS0_CH2_STATUS_MASK										((uint8_t) 0x40)
    #define DEV_STS0_CH2_STATUS_UNPOWERED									((uint8_t) 0x00)    // DEFAULT
    #define DEV_STS0_CH2_STATUS_POWERED										((uint8_t) 0x40)

    /* CH3_STATUS field */
    #define DEV_STS0_CH3_STATUS_MASK										((uint8_t) 0x20)
    #define DEV_STS0_CH3_STATUS_UNPOWERED									((uint8_t) 0x00)    // DEFAULT
    #define DEV_STS0_CH3_STATUS_POWERED										((uint8_t) 0x20)

    /* CH4_STATUS field */
    #define DEV_STS0_CH4_STATUS_MASK										((uint8_t) 0x10)
    #define DEV_STS0_CH4_STATUS_UNPOWERED									((uint8_t) 0x00)    // DEFAULT
    #define DEV_STS0_CH4_STATUS_POWERED										((uint8_t) 0x10)

    /* CH5_STATUS field */
    #define DEV_STS0_CH5_STATUS_MASK										((uint8_t) 0x08)
    #define DEV_STS0_CH5_STATUS_UNPOWERED									((uint8_t) 0x00)    // DEFAULT
    #define DEV_STS0_CH5_STATUS_POWERED										((uint8_t) 0x08)

    /* CH6_STATUS field */
    #define DEV_STS0_CH6_STATUS_MASK										((uint8_t) 0x04)
    #define DEV_STS0_CH6_STATUS_UNPOWERED									((uint8_t) 0x00)    // DEFAULT
    #define DEV_STS0_CH6_STATUS_POWERED										((uint8_t) 0x04)

    /* CH7_STATUS field */
    #define DEV_STS0_CH7_STATUS_MASK										((uint8_t) 0x02)
    #define DEV_STS0_CH7_STATUS_UNPOWERED									((uint8_t) 0x00)    // DEFAULT
    #define DEV_STS0_CH7_STATUS_POWERED										((uint8_t) 0x02)

    /* CH8_STATUS field */
    #define DEV_STS0_CH8_STATUS_MASK										((uint8_t) 0x01)
    #define DEV_STS0_CH8_STATUS_UNPOWERED									((uint8_t) 0x00)    // DEFAULT
    #define DEV_STS0_CH8_STATUS_POWERED										((uint8_t) 0x01)



/* Register 0x77 (DEV_STS1) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                          MODE_STS[2:0]                          |                                                RESERVED[4:0]                                                |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* DEV_STS1 register */
    #define DEV_STS1_ADDRESS												((uint8_t) 0x77)
    #define DEV_STS1_DEFAULT												((uint8_t) 0x80)

    /* MODE_STS field */
    #define DEV_STS1_MODE_STS_MASK											((uint8_t) 0xE0)
    #define DEV_STS1_MODE_STS_SLEEP											((uint8_t) 0x00)
    #define DEV_STS1_MODE_STS_ACTIVE_CH_OFF									((uint8_t) 0x20)
    #define DEV_STS1_MODE_STS_ACTIVE_CH_ON									((uint8_t) 0x40)



/* Register 0x7E (I2C_CKSUM) definition
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        Bit 7        |        Bit 6        |        Bit 5        |        Bit 4        |        Bit 3        |        Bit 2        |        Bit 1        |        Bit 0        |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                                                 I2C_CKSUM[7:0]                                                                                |
 * |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* I2C_CKSUM register */
    #define I2C_CKSUM_ADDRESS												((uint8_t) 0x7E)
    #define I2C_CKSUM_DEFAULT												((uint8_t) 0x00)



#endif /* TLV320ADCX140_PAGE0_H_ */
