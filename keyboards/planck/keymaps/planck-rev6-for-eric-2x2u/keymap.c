#include QMK_KEYBOARD_H


/* planck rev6 RGB layout:
 * ----------------------------------
 * |   6       5       4        3   |
 * |               0                |
 * |   7       8       1        2   |
 * ----------------------------------
 */

// Layer aliases
enum layer_names {
    _LINUX_BASE,    // Layer 0 - Linux base layer
    _WINDOWS_BASE,  // Layer 1 - Windows base layer
    _MACOS_BASE,    // Layer 2 - macOS base layer
    _SYMBOLS,       // Layer 3 - Symbols and navigation
    _NUMBERS,       // Layer 4 - Numbers and function keys
    _FUNCTION,      // Layer 5 - Function keys and RGB controls
    _MOUSE          // Layer 6 - Mouse layer
};

const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 1, HSV_GREEN},
    {8, 1, HSV_GREEN}
);

const rgblight_segment_t PROGMEM mouse_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 1, HSV_CYAN},
    {8, 1, HSV_CYAN},
    {7, 1, HSV_CYAN},
    {3, 1, HSV_CYAN},
    {6, 1, HSV_CYAN},
    {2, 1, HSV_CYAN}
);

enum rgb_layer_index {
    L_CAPSLOCK,
    L_MOUSE


};

const rgblight_segment_t * const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    [L_CAPSLOCK] = capslock_layer,
    [L_MOUSE] = mouse_layer
);


bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(L_CAPSLOCK, led_state.caps_lock);
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(L_MOUSE, layer_state_cmp(state, _MOUSE));
    return state;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_LINUX_BASE] = LAYOUT_planck_2x2u(KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_BSPC,
                             KC_ESC,  KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
                             KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, SC_SENT,
                             KC_LCTL, KC_LGUI, LALT_T(KC_CAPS), KC_LALT,         LT(_NUMBERS, KC_BSPC),     LT(_SYMBOLS, KC_SPC),          KC_RALT, KC_APP, KC_RGUI, KC_RCTL),

    [_WINDOWS_BASE] = LAYOUT_planck_2x2u(KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_BSPC,
                             KC_ESC,  KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
                             KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, SC_SENT,
                             KC_LCTL, KC_LGUI, LALT(KC_LSFT), KC_LALT,         LT(_NUMBERS, KC_BSPC),     LT(_SYMBOLS, KC_SPC),          KC_RALT, KC_APP, KC_RGUI, KC_RCTL),

    // macOS: Opt/Cmd swapped vs Linux so Cmd sits next to thumbs; Cmd-tap Caps on the inner left mod
    [_MACOS_BASE] = LAYOUT_planck_2x2u(KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_BSPC,
                             KC_ESC,  KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
                             KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, SC_SENT,
                             KC_LCTL, KC_LALT, LGUI_T(KC_CAPS), KC_LGUI,         LT(_NUMBERS, KC_BSPC),     LT(_SYMBOLS, KC_SPC),          KC_RGUI, KC_APP, KC_RALT, KC_RCTL),

    [_SYMBOLS] = LAYOUT_planck_2x2u(KC_GRV,  KC_NO,   KC_NO,   KC_LCBR, KC_RCBR, KC_NO, KC_NO, KC_PGUP, KC_UP,   KC_PGDN, KC_NO, KC_DEL,
                             KC_TRNS, KC_NO,   KC_NO,   KC_LPRN, KC_RPRN, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_TRNS,
                             KC_TRNS, KC_NO,   KC_NO,   KC_LBRC, KC_RBRC, KC_NO, KC_NO, KC_HOME, KC_NO,   KC_END,  KC_NO, KC_TRNS,
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,              LT(_FUNCTION,KC_BSPC),   KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	[_NUMBERS] = LAYOUT_planck_2x2u(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
                             KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
                             KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS,   LT(_FUNCTION, KC_SPC),            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	[_FUNCTION] = LAYOUT_planck_2x2u(AS_TOGG, KC_NO,   UG_VALU, UG_VALD,  KC_NO, KC_NO, KC_NO, KC_MPRV, KC_VOLU, KC_MNXT, KC_PSCR, KC_NO,
                             KC_TRNS, UG_TOGG, UG_NEXT, UG_PREV, KC_NO, KC_NO, KC_NO, KC_MPLY, KC_VOLD, KC_MUTE, KC_NO,  KC_TRNS,
                             KC_TRNS, NK_TOGG, UG_HUEU, UG_HUED,  PDF(_MACOS_BASE), PDF(_WINDOWS_BASE), PDF(_LINUX_BASE), TG(_MOUSE),   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS,
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [_MOUSE] = LAYOUT_planck_2x2u(KC_TRNS, MS_ACL0, MS_ACL1, MS_ACL2,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MS_UP, KC_TRNS, KC_TRNS, KC_TRNS,
                             TG(_MOUSE),   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, MS_LEFT, MS_DOWN, MS_RGHT, KC_TRNS, KC_TRNS,
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                MS_BTN2, MS_BTN1,          MS_BTN3, KC_TRNS, KC_TRNS, KC_TRNS)
};

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}
