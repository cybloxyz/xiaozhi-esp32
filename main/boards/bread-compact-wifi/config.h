#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_

#include <driver/gpio.h>

#define AUDIO_INPUT_SAMPLE_RATE  16000
#define AUDIO_OUTPUT_SAMPLE_RATE 24000

// Mic (INMP441) dan speaker (MAX98357A) berbagi BCLK dan WS -> mode DUPLEX.
// AUDIO_I2S_METHOD_SIMPLEX sengaja tidak di-define.

#define AUDIO_I2S_GPIO_WS   GPIO_NUM_12   // LRC / WS (mic + amp)
#define AUDIO_I2S_GPIO_BCLK GPIO_NUM_11   // CLK / BCLK (mic + amp)
#define AUDIO_I2S_GPIO_DIN  GPIO_NUM_1    // INMP441 SD (data mic -> ESP32)
#define AUDIO_I2S_GPIO_DOUT GPIO_NUM_10   // MAX98357A DIN (ESP32 -> amp)

#define BUILTIN_LED_GPIO        GPIO_NUM_48
#define BOOT_BUTTON_GPIO        GPIO_NUM_0
#define TOUCH_BUTTON_GPIO       GPIO_NUM_5    // TTP223
#define VOLUME_UP_BUTTON_GPIO   GPIO_NUM_NC   // tidak dipakai
#define VOLUME_DOWN_BUTTON_GPIO GPIO_NUM_NC   // tidak dipakai

#define DISPLAY_SDA_PIN GPIO_NUM_8
#define DISPLAY_SCL_PIN GPIO_NUM_9
#define DISPLAY_WIDTH   128

#if CONFIG_OLED_SSD1306_128X32
#define DISPLAY_HEIGHT  32
#elif CONFIG_OLED_SSD1306_128X64
#define DISPLAY_HEIGHT  64
#elif CONFIG_OLED_SH1106_128X64
#define DISPLAY_HEIGHT  64
#define SH1106
#else
#error "OLED display type is not selected"
#endif

#define DISPLAY_MIRROR_X false
#define DISPLAY_MIRROR_Y false

// Modul SD card (belum dipakai oleh firmware Xiaozhi bawaan)
#define SD_CARD_MISO_GPIO GPIO_NUM_43   // pin RX UART0
#define SD_CARD_MOSI_GPIO GPIO_NUM_44   // pin TX UART0
#define SD_CARD_SCK_GPIO  GPIO_NUM_2
#define SD_CARD_CS_GPIO   GPIO_NUM_4

// MCP test: kontrol lampu (pin bebas, boleh diganti atau dihapus)
#define LAMP_GPIO GPIO_NUM_18

#endif // _BOARD_CONFIG_H_