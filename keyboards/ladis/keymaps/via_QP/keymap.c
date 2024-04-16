//#include "ladis.h"
#include QMK_KEYBOARD_H
#include "qp.h"
#include "digi.qff.h"

painter_device_t display;
painter_font_handle_t digi;

enum { _BASE, _EXTRA, _TAP, _BUTTON };


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT(
		QK_BOOT, KC_UP, KC_WWW_FORWARD,
		KC_LEFT, KC_DOWN, KC_RIGHT,
		MO(1), KC_WWW_REFRESH, KC_F16,
		LCTL(KC_LGUI), KC_MUTE),

[_EXTRA] = LAYOUT(
		KC_F17, KC_F18, KC_F19,
		KC_F20, KC_F21, KC_F22,
		KC_NO, KC_F23, KC_F24,
		KC_SYSTEM_SLEEP, KC_MUTE),

[_TAP] = LAYOUT(
		KC_TRNS , KC_TRNS , KC_TRNS ,
		KC_TRNS , KC_TRNS , KC_TRNS ,
		KC_TRNS , KC_TRNS , KC_TRNS ,
		KC_TRNS , KC_TRNS ),

[_BUTTON] = LAYOUT(
		KC_TRNS , KC_TRNS , KC_TRNS ,
		KC_TRNS , KC_TRNS , KC_TRNS ,
		KC_TRNS , KC_TRNS , KC_TRNS ,
		KC_TRNS , KC_TRNS )

};

 #ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] =   { ENCODER_CCW_CW(KC_BSPC, KC_DEL),  ENCODER_CCW_CW(KC_PGDN, KC_PGUP)  },
    [_EXTRA] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  },
    [_TAP] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  },
    [_BUTTON] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  }
};
#endif

const char *current_layer_name(void) {
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            return "BASE   ";
        case _EXTRA:
            return "EXTRA  ";
        case _TAP:
            return "TAP    ";
        case _BUTTON:
            return "BUTTON ";
    }
            return "UKN    ";

}

void keyboard_post_init_user(void) {
    display = qp_sh1106_make_i2c_device(128, 32, 0x3C);
    qp_init(display,QP_ROTATION_0);
    qp_power(display, true);
    digi = qp_load_font_mem(font_digi);
}


void housekeeping_task_user(void) {

        static const char *last_layer_name = NULL;
        const char *layer_name = current_layer_name();
        if (last_layer_name != layer_name) {
            last_layer_name = layer_name;
        qp_drawtext(display, 1, 2, digi, layer_name);
        }

    qp_flush(display);
    }

//qmk compile -kb ladis -km via_QP -e CONVERT_TO=elite_pi
