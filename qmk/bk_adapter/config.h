#pragma once

#include "config_common.h"

/* USB DEVICE DESCRIPTOR */
#define PRODUCT The Bastard Keyboards Blackpill
#define MANUFACTURER Bastard Keyboards x KarlK90
#define VENDOR_ID 0xA8F8
#define PRODUCT_ID 0x1828
#define DEVICE_VER 0x0001

/* MATRIX CONFIG */
#define MATRIX_COLS 6
#define MATRIX_ROWS 10
#define MATRIX_COL_PINS \
    { B0, B1, B10, B3, B4, B5 }
#define MATRIX_COL_PINS_RIGHT \
    { B0, B1, B10, B3, B4, B5 }

#define MATRIX_ROW_PINS \
    { B15, A2, B8, A8, B9 }
#define MATRIX_ROW_PINS_RIGHT \
    { B15, A2, B8, A8, B9 }

#define DIODE_DIRECTION ROW2COL
#define DEBUG_MATRIX_SCAN_RATE

/* RGB CONFIG - WS2812 DRIVER */
#define RGB_DI_PIN A1
#define WS2812_EXTERNAL_PULLUP
#define WS2812_PWM_DRIVER PWMD2
#define WS2812_PWM_CHANNEL 2
#define WS2812_PWM_PAL_MODE 1
#define WS2812_DMA_CHANNEL 3
#define WS2812_DMA_STREAM STM32_DMA1_STREAM1
// Without the following configurations the WS2812 would not light up
#define WS2812_PWM_TARGET_PERIOD 800000

/* CRC DRIVER */
#define CRC8_USE_TABLE
#define CRC8_OPTIMIZE_SPEED

/* SPLIT CONFIG */
#define SPLIT_HAND_PIN A3

/* SERIAL SPLIT DRIVER */
#define SERIAL_USART_TX_PIN A9
// To use the highest possible baudrate (3.75Mbit/s) uncomment the following
// line, this can result in dropped communications so lower the speed if there
// are many timeouts. #define SERIAL_USART_SPEED (STM32_PCLK2 >> 4)

/* SPI DRIVER */
#define SPI_DRIVER SPID1
#define SPI_SCK_PIN A5
#define SPI_MOSI_PIN B7
#define SPI_MISO_PIN A6

/* EEPROM DRIVER */
#define EXTERNAL_EEPROM_SPI_SLAVE_SELECT_PIN A4

/* PMW3360 DRIVER */
#define PMW3360_CS_PIN B14
