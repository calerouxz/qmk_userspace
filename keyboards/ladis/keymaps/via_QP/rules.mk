VIA_ENABLE = yes
ENCODER_MAP_ENABLE = yes
QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS += sh1106_i2c
OLED_ENABLE = no

VPATH += keyboards/ladis/via_QP
SRC += \
	digi.qff.c \
	roboto.qff.c \
