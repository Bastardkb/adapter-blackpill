## Work in progress.

Blackpill holder pcb with breakouts for rgb, trackball etc.

Licensed under CERN-OHL-W v2.
w

Copyright Quentin Lebastard and Stefan Kerkmann 2021.
## Pin assignments

| Pin No. | Pin  |      Function      |
| ------- | ---- | ------------------ |
| 11      | PA1  | TIM2_CH2 (RGB)     |
| 3       | PA14 | SPI1 CS TRACKBALL  |
| 10      | PA15 | SPI1 CS USER       |
| 14      | PA4  | SPI1 CS EEPROM     |
| 15      | PA5  | SPI1 SCK           |
| 16      | PA6  | SPI1 MISO          |
| 17      | PA7  | SPI1 MOSI          |
| 30      | PA9  | USART1 TX (SERIAL) |
| 32      | PA11 | USB_OTG_FS_DM      |
| 33      | PA12 | USB_OTG_FS_DP      |
| 42      | PB6  | I2C1 SCL           |
| 43      | PB7  | I2C1 SDA           |


# DMA channels

|   event   |    channel / stream     |       usage        |
| --------- | ----------------------- | ------------------ |
| I2C1_RX   | DMA1 Stream 0 Channel 1 | not used           |
| I2C1_TX   | DMA1 Stream 6 Channel 1 | not used           |
| SPI1_RX   | DMA2 Stream 0 Channel 3 | EEPROM and PMW3360 |
| SPI1_TX   | DMA2 Stream 3 Channel 3 | EEPROM and PMW3360 |
| TIM2_UP   | DMA1 Stream 1 Channel 3 | WS2812 PWM         |
| USART1_RX | DMA2 Stream 2 Channel 4 | not used           |
| USART1_TX | DMA2 Stream 7 Channel 4 | not used           |


## Test report

* PWM Driver - ok with external pullup and adjusted timings see `config.h`
* Serial Half-duplex - ok at default speed and up to 3.75MBit/s see `config.h`
* SPI EEPROM - ok, PWM3360 - ok from scope, should work with real hardware
* Splithand detection - ok
* Bootloader bodge - ok, can enter reliably everytime
* Matrix - ok
