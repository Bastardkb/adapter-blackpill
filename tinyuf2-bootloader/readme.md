# BastardKB branded TinyUF2 bootloaders

For usage with STM32F411 mcus.

1. Put blackpill into the STM32 DFU bootloader by holding BOOT0 button and pressing NRST button afterwards
2. Flash TinyUF2 bootloader via `dfu-util -d 0483:df11 -a 0 -s 0x08000000:leave -D tinyuf2-stm32f411ce_blackpill.bin -w`

**The flash sectors of TinyUF2 bootloader is automatically locked, so they can not be overwritten**

In case you want to update or overwrite TinyUF2 again:

1. Put TinyUF2 into flashing / DFU mode by double tapping the NRST fast
2. Copy `tinyuf2-unlocker-stm32f411.uf2` into the Charybdis folder
3. The STM32F411 will automatically reboot into STM32 DFU bootloader
4. Update or overwrite the TinyUF2 bootloader with `dfu-util`
