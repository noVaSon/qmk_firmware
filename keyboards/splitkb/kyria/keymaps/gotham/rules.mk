CONSOLE_ENABLE     = yes # Console for debug
ENCODER_ENABLE     = yes # ENables the use of one or more encoders
RGBLIGHT_ENABLE    = no  # Enable keyboard RGB underglow
MOUSEKEY_ENABLE    = yes # Mouse keys
OLED_ENABLE = no
OLED_DRIVER = SSD1306    # Enables the use of OLED displays
THUMBSTICK_ENABLE  = no  # Enables analog thumbstick code

ifeq ($(strip $(ENCODER_ENABLE)), yes)
	SRC += encoder_utils.c
endif

ifeq ($(strip $(OLED_ENABLE)), yes)
	SRC += oled_utils.c
endif

ifeq ($(strip $(THUMBSTICK_ENABLE)), yes)
    POINTING_DEVICE_ENABLE = yes
    POINTING_DEVICE_DRIVER = custom
    OPT_DEFS += -DTHUMBSTICK_ENABLE
	SRC += analog.c
	SRC += thumbstick.c
endif
