// Copyright 2022 HorrorTroll <https://github.com/HorrorTroll>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-3.0-or-later

RGB_MATRIX_EFFECT(CUSTOM_GRADIENT)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
extern HSV  gradient_0;
extern HSV  gradient_100;
extern bool reflected_gradient;

static HSV INTERPOLATE_HSV(float step, HSV gradient_0, HSV gradient_100) {
    uint8_t cw, ccw;
    HSV     color;

    cw  = (gradient_0.h >= gradient_100.h) ? 255 + gradient_100.h - gradient_0.h
                                           : gradient_100.h - gradient_0.h; // Hue range is 0 to 255.
    ccw = (gradient_0.h >= gradient_100.h) ? gradient_0.h - gradient_100.h : 255 + gradient_0.h - gradient_100.h;

    if (cw < ccw) { // going clockwise
        color.h = gradient_0.h + (uint8_t)(step * cw);
    } else { // Going counter clockwise
        color.h = gradient_0.h - (uint8_t)(step * ccw);
    }

    color.s = gradient_0.s + step * (gradient_100.s - gradient_0.s);

    // Scale V with global RGB Matrix's V, so users can still control overall brightness with RGB_VAI & RGB_VAD0
    color.v = round((gradient_0.v + step * (gradient_100.v - gradient_0.v)) * ((float)rgb_matrix_config.hsv.v / 255));

    return color;
}

static HSV CUSTOM_GRADIENT_math(uint8_t led_x, uint8_t min_x, uint8_t max_x) {
    float step             = (float)led_x / (max_x - min_x);
    float mid_gradient_pos = 0.5;

    if (reflected_gradient) {
        if (step <= mid_gradient_pos) {
            return INTERPOLATE_HSV(step * (1 / mid_gradient_pos), gradient_0, gradient_100);
        } else {
            return INTERPOLATE_HSV((step - mid_gradient_pos) * (1 / (1 - mid_gradient_pos)), gradient_100, gradient_0);
        }

    } else {
        return INTERPOLATE_HSV(step, gradient_0, gradient_100);
    }
}

static bool CUSTOM_GRADIENT(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint8_t min_x = 0;   // X coordinate of the left-most LED
    uint8_t max_x = 224; // X coordinate of the right-most LED

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();

        HSV hsv_orig = CUSTOM_GRADIENT_math(g_led_config.point[i].x, min_x, max_x);
        RGB rgb      = hsv_to_rgb(hsv_orig);

        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }

    return led_max < RGB_MATRIX_LED_COUNT;
}
#endif
