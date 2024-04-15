//#include "ladis.h"
#include QMK_KEYBOARD_H
#include "qp.h"

painter_device_t display;
painter_font_handle_t gameover;

enum layers { BASE, EXTRA, TAP, BUTTON };


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT(
		QK_BOOT, KC_UP, KC_WWW_FORWARD,
		KC_LEFT, KC_DOWN, KC_RIGHT,
		MO(1), KC_WWW_REFRESH, KC_F16,
		LCTL(KC_LGUI), KC_MUTE),

[1] = LAYOUT(
		KC_F17, KC_F18, KC_F19,
		KC_F20, KC_F21, KC_F22,
		KC_NO, KC_F23, KC_F24,
		KC_SYSTEM_SLEEP, KC_MUTE),

[2] = LAYOUT(
		KC_TRNS , KC_TRNS , KC_TRNS ,
		KC_TRNS , KC_TRNS , KC_TRNS ,
		KC_TRNS , KC_TRNS , KC_TRNS ,
		KC_TRNS , KC_TRNS ),

[3] = LAYOUT(
		KC_TRNS , KC_TRNS , KC_TRNS ,
		KC_TRNS , KC_TRNS , KC_TRNS ,
		KC_TRNS , KC_TRNS , KC_TRNS ,
		KC_TRNS , KC_TRNS ),

};

 #ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =   { ENCODER_CCW_CW(KC_BSPC, KC_DEL),  ENCODER_CCW_CW(KC_PGDN, KC_PGUP)  },
    [1] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  },
    [2] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  },
    [3] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  }
};
#endif

void keyboard_post_init_kb(void) {
    display = qp_sh1106_make_i2c_device(128, 32, 0x3C);
    qp_init(display,QP_ROTATION_0);
    qp_power(display, true);
    qp_rect(display, 0, 0, 7, 7, 0, 255, 255, true);

    qp_flush(display);
    }

//qmk compile -kb ladis -km via_QP_prim -e CONVERT_TO=elite_pi
