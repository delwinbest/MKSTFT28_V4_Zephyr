How to build PlatformIO based project
=====================================

1. [Install PlatformIO Core](https://docs.platformio.org/page/core.html)
2. Download [development platform with examples](https://github.com/platformio/platform-ststm32/archive/develop.zip)
3. Extract ZIP archive
4. Run these commands:

```shell
# Build project
$ pio run

# Upload firmware
$ pio run --target upload
```

## Connecting ST-LINK v2 to the MKS TFT: 

    ST-LINK    MKS-TFT32: 
    5v         AUX-1 5v 
    GND        AUX-1 GND 
    SWDIO      JTAG pin 4 
    SWCLK      JTAG pin 5 

## Board JTAG connector (left-to-right):

    3.3v   GND   GND 
    SWDIO  SWCLK RESET

Disconnect MKS TFT from printer before connecting ST-LINK. Do not connect ST-LINK 3.3v pin.


## Board Configuration

    BOOT Mode: Boot0 = 0, Boot 1 = 0

    SPI1 (default): SPIFlash: Winbond 8MB (64Mb) Serial Flash Memory W25Q CS: PB9,MOSI=PA7,PIN_SPI_MISO=PA6,PIN_SPI_SCK=PA5
    SPI1 (default): SDCard CS: PD11, MOSI=PA7,PIN_SPI_MISO=PA6,PIN_SPI_SCK=PA5
    SPI3 (remapped): URTouch CS: PC5
    I2C: Two-wire Serial EEPROM AT24C16B 
    UART1: Wifi connector
    UART2: Octopi
    UART4: Touch controller
    PX11/12, UART1_CTS/RTS: USB
    PA2: Buzzer

