USER_NAME := pcheng

# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

SPLIT_KEYBOARD = yes
LAYOUTS = ortho_4x12

BOOTMAGIC_ENABLE     = no  # Enable Bootmagic Lite
MOUSEKEY_ENABLE      = yes # Mouse keys
EXTRAKEY_ENABLE      = yes # Audio control and System control
CONSOLE_ENABLE       = no  # Console for debug
COMMAND_ENABLE       = yes # Commands for debug and configuration
NKRO_ENABLE          = yes # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
AUDIO_SUPPORTED      = no
AUDIO_ENABLE         = no
RGBLIGHT_ENABLE      = no
BACKLIGHT_ENABLE     = no
DYNAMIC_MACRO_ENABLE = yes
TAP_DANCE_ENABLE     = no
