# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
<<<<<<< HEAD
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
RGB_MATRIX_ENABLE = no
RGB_MATRIX_DRIVER = WS2812
LTO_ENABLE = yes

# if firmware size over limit, try this option
# LTO_ENABLE = yes
=======
<<<<<<< Updated upstream
>>>>>>> 82ba9c28a0 (Added uli)

DEFAULT_FOLDER = crkbd/rev1

RGBLIGHT_SUPPORTED = yes
RGB_MATRIX_SUPPORTED = yes
<<<<<<< HEAD

LAYOUTS = split_3x5_3 split_3x6_3
=======
=======
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
RGB_MATRIX_ENABLE = no
RGB_MATRIX_DRIVER = WS2812
LTO_ENABLE = yes

# if firmware size over limit, try this option
# LTO_ENABLE = yes

DEFAULT_FOLDER = crkbd/rev1

RGBLIGHT_SUPPORTED = no
RGB_MATRIX_SUPPORTED = no

LAYOUTS = split_3x5_3 split_3x6_3
>>>>>>> Stashed changes
>>>>>>> 82ba9c28a0 (Added uli)
