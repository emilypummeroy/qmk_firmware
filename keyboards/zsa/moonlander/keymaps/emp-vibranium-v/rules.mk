# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file

###
# See also ../emp-vibranium-s
###

CONSOLE_ENABLE = no
COMMAND_ENABLE = no
AUDIO_ENABLE = no
MOUSEKEY_ENABLE = no
ORYX_ENABLE = yes
TAP_DANCE_ENABLE = no
SPACE_CADET_ENABLE = no
CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes
DYNAMIC_TAPPING_TERM_ENABLE = yes
LTO_ENABLE = yes

CUSTOM_MATRIX = lite

VPATH += drivers/gpio
SRC += matrix.c mcp23018.c
I2C_DRIVER_REQUIRED = yes

MCU_LDSCRIPT = STM32F303xB
