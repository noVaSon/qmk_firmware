/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#include "keycodes.h"

#ifdef ENCODER_ENABLE
#    include "encoder_utils.h"
#endif

#ifdef OLED_ENABLE
#    include "oled_utils.h"
#endif

#ifdef THUMBSTICK_ENABLE
#    include "thumbstick.h"
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,--------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |         |
 *                        |      |      |      |      |      |  |      |      |      |      | mute mic|
 *                        `----------------------------------'  `----------------------------------'
*/

    [_QWERTY] = LAYOUT(
      _______,           KC_Q,           KC_W,             KC_E,               KC_R,                KC_T,                                                                                                 KC_Y,               KC_U,            KC_I,            KC_O,            KC_P,            KC_EQL,
      KC_ESC ,      LGUI_T(KC_A),   LALT_T(KC_S),     LCTL_T(KC_D),       LSFT_T(KC_F),   MT(KC_HYPR, KC_G),                                                                                    MT(KC_HYPR, KC_H),       RSFT_T(KC_J),    RCTL_T(KC_K),    LALT_T(KC_L),    RGUI_T(KC_SCLN),        KC_QUOT,
      KC_LCTL,             KC_Z,           KC_X,             KC_C,               KC_V,                KC_B,              _______,      MO(_FUN),            MO(_FUN),             _______,             KC_N,               KC_M,            KC_COMM,         KC_DOT,          KC_SLSH,         CTL_MINS,
                                                      ENC_MODE_L,         KC_RALT,        LT(_NUM,    KC_TAB), LT(_SYM,  KC_SPC),      MO(_MSE),            MO(_NAV),     LT(_SYM, KC_ENT), LT(_NAV,  KC_BSPC),           KC_DEL,          MUTE_MIC
    ),

// TODO: Layer Switching, HRM, NUMPAD

/*
 * Symbol Layer: Symbols only
 */
    [_SYM] = LAYOUT(
      _______, KC_HASH, KC_DLR,  KC_LCBR, KC_RCBR, KC_PIPE,                                       _______, _______, _______, _______, _______, _______,
      _______, KC_EXLM, KC_AT,   KC_LPRN, KC_RPRN, KC_GRV,                                        KC_MINS, KC_PLUS, KC_ASTR, KC_SLSH, KC_PERC, _______,
      _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______, _______,   _______, _______, KC_AMPR, KC_PIPE, KC_COMM, KC_DOT,  KC_SLSH, _______,
                                 _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
    ),

/*
* Nav Layer: movement and history
*/
    [_NAV] = LAYOUT(
      _______, _______,    C(KC_LEFT), KC_UP,   C(KC_RGHT),   _______,                                       _______, _______, _______, _______, _______, _______,
      _______,   KC_HOME,  KC_LEFT,    KC_DOWN,   KC_RGHT,    KC_END,                                        _______, _______, _______, _______, _______, _______,
      _______, C(KC_Z),    KC_CUT,     KC_COPY,   KC_PSTE,  C(KC_Y),   _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______,
                                        _______, _______,     _______, _______, _______,   _______, _______, _______, _______, _______
  ),

/*
* Mouse Layer: mouse control
*/
    [_MSE] = LAYOUT(
      _______, _______,  _______, _______, _______, _______,                                       _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_ACL0,
      _______, _______,  _______, _______, _______, _______,                                       _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_ACL1,
      _______, C(KC_Z),  KC_CUT,  KC_COPY, KC_PSTE, C(KC_Y), _______, _______,   _______, _______, KC_PGDN, _______, KC_BTN3, _______, _______, KC_ACL2,
                                  _______, _______, _______, _______, _______,   _______, _______, KC_BTN1, KC_BTN2, _______
  ),

/*
 * Numblock layer
 */
    [_NUM] = LAYOUT(
      _______, _______, _______,  _______, _______, _______,                                      KC_COMM,  KC_7,    KC_8,    KC_9,  KC_ASTR, KC_PSLS,
      _______, _______, _______,  _______, _______, _______,                                      KC_DOT,   KC_4,    KC_5,    KC_6,  KC_PEQL, KC_AMPR,
      _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, KC_0,     KC_1,    KC_2,    KC_3,  KC_PLUS, KC_PMNS,
                                 _______, _______, _______, _______, _______,   _______, _______, _______,  _______, _______
    ),


/*
 * Function Layer: Function keys, RGB
  */
    [_FUN] = LAYOUT(
      DB_TOGG, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,                                       KC_F12,   KC_F7,   KC_F8,    _______, _______,  _______,
      _______, _______, _______, _______, _______, _______,                                       KC_F11, KC_F4, KC_F5, KC_F6, _______, _______,
      _______, _______, _______, _______, KC_MUTE, KC_VOLD, _______, _______,   _______, _______, KC_F10, KC_F1, KC_F2, KC_F3, _______, _______,
                                 _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
    ),
};
// clang-format on

void matrix_init_user(void) {
#ifdef ENCODER_ENABLE
    encoder_utils_init();
#endif
}

// TODO: what is this for? rename layers / propably a third layer only on top of the other two activated
// layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#ifdef ENCODER_ENABLE
        case ENC_MODE_L:
            if (record->event.pressed) {
                cycle_encoder_mode(true, false);
            }
            break;
        case ENC_MODE_R:
            if (record->event.pressed) {
                cycle_encoder_mode(false, false);
            }
            break;
#endif
#ifdef THUMBSTICK_ENABLE
        case TMB_MODE:
            if (record->event.pressed) {
                thumbstick_mode_cycle(false);
            }
#endif
    }
    return true;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    render_status();
    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        encoder_action(get_encoder_mode(true), clockwise);
#    ifdef OLED_ENABLE
        oled_on();
#    endif
    } else if (index == 1) {
        encoder_action(get_encoder_mode(false), clockwise);
#    ifdef OLED_ENABLE
        oled_on();
#    endif
    }
    return true;
}
#endif
