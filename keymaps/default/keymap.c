/* */

#include QMK_KEYBOARD_H

enum layer_names {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    [_QWERTY] = LAYOUT( \
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
    QK_GESC,   KC_Q,   KC_D,    KC_R,    KC_W,    KC_B,                     KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN,    KC_MINS, \
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_LCTL, KC_A,   KC_S,    KC_H,    KC_T,    KC_G,                     KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_QUOT, \
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_LSFT,  KC_Z,   KC_X,    KC_M,    KC_C,    KC_V,                      KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, \
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
                        KC_LALT, KC_LGUI, LT(_RAISE, KC_ENT),               LT(_LOWER, KC_SPACE),   KC_BSPC,   KC_RALT \
    ),


    [_LOWER] = LAYOUT( \
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
    QK_GESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_UP,    KC_9,    KC_0,    KC_EQUAL, \
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_CIRC, KC_LEFT, KC_DOWN, KC_RIGHT, KC_RPRN, _______, \
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
    _______, _______, _______, _______, _______, _______,                    XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                _______, _______, _______,                   _______,  KC_DEL, _______ \
    ),

    [_RAISE] = LAYOUT( \
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
    QK_GESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_6,    KC_9,    KC_0,    KC_EQUAL, \
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
    _______,  KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,                   XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX, \
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
    _______,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                _______, _______,  _______,                  LT(_ADJUST, KC_SPACE),  KC_DEL, _______ \
    ),

    [_ADJUST] = LAYOUT( \
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                                KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, \
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                _______, _______, _______,                   _______, _______, _______ \
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
            break;
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(_RAISE, KC_ENT):
      return 200;
    case LT(_LOWER, KC_SPACE):
      return 200;
    case LT(_ADJUST, KC_SPACE):
      return 200;
    default:
      return TAPPING_TERM;
  }
}
