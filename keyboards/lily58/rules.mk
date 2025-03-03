# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = no       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
RGBLIGHT_ENABLE = no       # Enable WS2812 RGB underlight.
<<<<<<< HEAD
OLED_ENABLE = yes
OLED_DRIVER = SSD1306    # OLED display
SPLIT_KEYBOARD = yes

OLED_ENABLE = no
OLED_DRIVER = SSD1306    # OLED display
SPLIT_KEYBOARD = yes
COMBO_ENABLE = yes

DEFAULT_FOLDER = lily58/rev1
