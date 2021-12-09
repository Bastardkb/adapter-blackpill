# At the time of writing (10th of Dezember 2021) this is still work in progress. There is a likelyhood of errors that have not been found yet. If you like to live on the bleeding edge go ahead if you like security wait until offical confirmation that the adapter works as intended!

Blackpill holder pcb with breakouts for rgb, trackball etc.

Licensed under CERN-OHL-W v2.

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

## BOM

| Qty. |                      Part                      |                                                                Link                                                                |
| ---- | ---------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------- |
| 2    | WeAct STM32F411 Blackpill                      | [AliExpress](https://www.aliexpress.com/item/1005001456186625.html)                                                                |
| 2    | 64Kbit STM M95 SPI EEPROM (SOP-8 package size) | [LCSC Electronics](https://lcsc.com/product-detail/EEPROM_STMicroelectronics-M95640-WMN6TP_C140882.html)                           |
| 4    | 5.1k 1206 Resistors                            | [LCSC Electronics](https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_UNI-ROYAL-Uniroyal-Elec-1206W4F5101T5E_C26033.html) |
| 2    | TRRS Jack 3.5mm                                | [LCSC Electronics](https://lcsc.com/product-detail/Pre-ordered-Connectors_XKB-Connectivity-PJ-320E_C2884941.html)                  |
| 2    | Push button 5.1mm x 1.5mm                      | [LCSC Electronics](https://lcsc.com/product-detail/Tactile-Switches_XKB-Connectivity-TS-1187A-B-A-B_C318884.html)                  |

 **Note About EEPROM:** QMK can only address 64kbit of memory. So buying anything larger is possible but wasted.

## JLCPCB Order Form (non default values)

* Different Design: 2
* PCB Height: 1mm

## Recommended way to attach MCU to adapter

![Header pins long side on bottom](https://cdn.discordapp.com/attachments/747849854276993114/915438746885816401/STM32F411CEU6_WeAct_Black_Pill_V2.png "bottom view of WeAct_Black_Pill")
![Elite-C adapter looks similar](https://cdn.discordapp.com/attachments/747850923023532073/917082370203607101/76-SWtxD5yNuvbsMLcKAxJII_M5w2juIZuDnQQMsW-VUXTQv-tv4Ju1rIXA-a9Hn6rxcuW34BAAYXKeUi5G3fKMoSbNl2HES9LPlbMYZioP_Ol1HNKip8EF_1Kr8nm6-cMjKs5wC0aen-TuDZjqQE7MhqrMNe8MxqrA0NiTr81869KeJeFpGrAei19xqCjLpO5jcsRDU_FKAc_FC2mRzOteIls9-IShEQoJYTQ0m23tz3L_zWAfeI2bfcWaygDQLRW-s93hR9hg672LtWWHCtBtLXzsoNRuSYkzwj_VyGVLmJC63U21AO5uTM5iUqJ64LGLX700Dk0VgG7dvhEr211VDhxo_Sq6-Cdhb3ZxKNR5VYqu1e4izE0SBZ-jwiAfvB3FijTOnnAJ3jfrkK19S5Lc-pBLlCTArL5Lwt-DhQTADWKQQyoxQ6U-9wcLiQrjq1vwKFxQMuHioHG1Q6iHDdeF6LiTqd4fDLzMYSgdJAEU6itGaK5oYqufAGMyd..png "view of elite-c adapter plate. same idea")