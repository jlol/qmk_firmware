BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes        # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
RGBLIGHT_ENABLE = no       # Enable WS2812 RGB underlight.
SWAP_HANDS_ENABLE = no      # Enable one-hand typing
ENCODER_ENABLE = no
TAP_DANCE_ENABLE = no
LTO_ENABLE = yes

OLED_ENABLE= no     # OLED display
DEBOUNCE_TYPE = asym_eager_defer_pk 

#OLED_ENABLE= yes     # OLED display
#OLED_DRIVER = SSD1306
#WPM_ENABLE = yes
#SPLIT_KEYBOARD = yes
#LUNA_ENABLE = yes 
#OCEAN_DREAM_ENABLE = yes 

# If you want to change the display of OLED, you need to change here
SRC +=   ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c \
        #./lib/rgb_state_reader.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c \

ifeq ($(strip $(OLED_ENABLE)), yes)
    SRC += oled_setup.c
	OPT_DEFS += -DOLED_ENABLE

	ifdef OCEAN_DREAM_ENABLE
		ifeq ($(strip $(OCEAN_DREAM_ENABLE)), yes)
			SRC += ocean_dream.c
			OPT_DEFS += -DOCEAN_DREAM_ENABLE
		endif
	endif
	ifndef OCEAN_DREAM_ENABLE
		SRC += ocean_dream.c
		OPT_DEFS += -DOCEAN_DREAM_ENABLE
	endif

	ifdef LUNA_ENABLE
		ifeq ($(strip $(LUNA_ENABLE)), yes)
			SRC += luna.c
			OPT_DEFS += -DLUNA_ENABLE
		endif
	endif
	ifndef LUNA_ENABLE
		SRC += luna.c
		OPT_DEFS += -DLUNA_ENABLE
	endif
endif
