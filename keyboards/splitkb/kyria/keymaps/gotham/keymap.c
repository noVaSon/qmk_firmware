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
*  TODO 3l layout, split layout
* TODO extra layout 3L Colemak qglm*
* TODO macro
* TODO comment?
*/

    // [_QWERTY] = LAYOUT(
    //   KC_ESC,             KC_Q,           KC_W,             KC_E,               KC_R,                KC_T,                                                                                                   KC_Y,               KC_U,            KC_I,            KC_O,            KC_P,            KC_EQL,
    //   KC_TAB ,      LGUI_T(KC_A),   LALT_T(KC_S),     LCTL_T(KC_D),       LSFT_T(KC_F),   MT(KC_HYPR, KC_G),                                                                                    MT(KC_HYPR, KC_H),       RSFT_T(KC_J),    RCTL_T(KC_K),    LALT_T(KC_L),    RGUI_T(KC_SCLN),        KC_QUOT,
    //   KC_LSFT,             KC_Z,           KC_X,             KC_C,               KC_V,                KC_B,              MO(_FUN),      MO(_FUN),              TEAMS_MUTE_MIC,              MO(_FUN),             KC_N,               KC_M,            KC_COMM,         KC_DOT,          KC_SLSH,         KC_MINS,
                                                    // ENC_MODE_L,         KC_RALT,        LT(_NUM, KC_TAB ),      LT(_NAV,  KC_SPC),    LT(_SYM, KC_ENT),      LT(_SYM, KC_ENT),     LT(_NAV, KC_BSPC), LT(_NUM, KC_DEL ),      KC_APP,         KC_MUTE
    // ),

    // shifting slowly

    // [_BASE] = LAYOUT(
    //   KC_ESC,             KC_Q,           KC_W,             KC_E,               KC_R,                KC_T,                                                                                                   KC_Y,               KC_U,            KC_I,            KC_O,            KC_SCLN,            KC_EQL,
    //   KC_TAB ,      LGUI_T(KC_A),   LALT_T(KC_S),     LCTL_T(KC_D),       LSFT_T(KC_F),   MT(KC_HYPR, KC_G),                                                                                    MT(KC_HYPR, KC_H),       RSFT_T(KC_J),    RCTL_T(KC_K),    LALT_T(KC_L),    RGUI_T(KC_P),        KC_QUOT,
    //   KC_LSFT,             KC_Z,           KC_X,             KC_C,               KC_V,                KC_B,              MO(_FUN),      MO(_FUN),              TEAMS_MUTE_MIC,              MO(_FUN),             KC_N,               KC_M,            KC_COMM,         KC_DOT,          KC_SLSH,         KC_MINS,
                                                    // ENC_MODE_L,         KC_RALT,        LT(_NUM, KC_TAB ),      LT(_NAV,  KC_SPC),    LT(_SYM, KC_ENT),      LT(_SYM, KC_ENT),     LT(_NAV, KC_BSPC), LT(_NUM, KC_DEL ),      KC_APP,         KC_MUTE
    // ),

// 5 swap qwkrfy

    // [_BASE  ] = LAYOUT(
    //   KC_ESC,             KC_Q,           KC_W,             KC_K,               KC_R,                KC_F,                                                                                                   KC_Y,               KC_U,            KC_I,            KC_J,            KC_SCLN,            KC_EQL,
    //   KC_TAB ,      LGUI_T(KC_D),   LALT_T(KC_S),     LCTL_T(KC_A),       LSFT_T(KC_T),   MT(KC_HYPR, KC_N),                                                                                    MT(KC_HYPR, KC_H),       RSFT_T(KC_O),    RCTL_T(KC_E),    LALT_T(KC_L),    RGUI_T(KC_P),        KC_QUOT,
    //   KC_LSFT,             KC_Z,           KC_X,             KC_C,               KC_V,                KC_B,              MO(_FUN),      MO(_FUN),              TEAMS_MUTE_MIC,              MO(_FUN),             KC_G,               KC_M,            KC_COMM,         KC_DOT,          KC_SLSH,         KC_MINS,
                                                    // ENC_MODE_L,         KC_RALT,        LT(_NUM, KC_TAB ),      LT(_NAV,  KC_SPC),    LT(_SYM, KC_ENT),      LT(_SYM, KC_ENT),     LT(_NAV, KC_BSPC), LT(_NUM, KC_DEL ),      KC_APP,         KC_MUTE
    // ),

// QGMLWY
    // [_BASE  ] = LAYOUT(
    // KC_ESC,             KC_Q,           KC_G,             KC_M,               KC_L,                KC_W,                                                                                                   KC_Y,               KC_F,            KC_U,            KC_B,            KC_SCLN,            KC_EQL,
    // KC_TAB ,      LGUI_T(KC_D),   LALT_T(KC_S),     LCTL_T(KC_T),       LSFT_T(KC_N),   MT(KC_HYPR, KC_R),                                                                                    MT(KC_HYPR, KC_I),       RSFT_T(KC_A),    RCTL_T(KC_E),    LALT_T(KC_O),    RGUI_T(KC_H),        KC_QUOT,
    // KC_LSFT,             KC_Z,           KC_X,             KC_C,               KC_V,                KC_J,              MO(_FUN),      MO(_FUN),              TEAMS_MUTE_MIC,              MO(_FUN),             KC_K,               KC_P,            KC_COMM,         KC_DOT,          KC_SLSH,         KC_MINS,
                                                    // ENC_MODE_L,         KC_RALT,        LT(_NUM, KC_TAB ),      LT(_NAV,  KC_SPC),    LT(_SYM, KC_ENT),      LT(_SYM, KC_ENT),     LT(_NAV, KC_BSPC), LT(_NUM, KC_DEL ),      KC_APP,         KC_MUTE
    // ),

// Colemak
    // [_BASE  ] = LAYOUT(
    // KC_ESC,             KC_Q,           KC_W,             KC_F,               KC_P,                KC_G,                                                                                                   KC_J,               KC_L,            KC_U,            KC_Y,            KC_SCLN,            KC_EQL,
    // KC_BSPC ,      LGUI_T(KC_A),   LALT_T(KC_R),     LCTL_T(KC_S),       LSFT_T(KC_T),   MT(KC_HYPR, KC_D),                                                                                    MT(KC_HYPR, KC_H),       RSFT_T(KC_N),    RCTL_T(KC_E),    LALT_T(KC_I),    RGUI_T(KC_O),        KC_QUOT,
    // KC_LSFT,             KC_Z,           KC_X,             KC_C,               KC_V,                KC_B,              MO(_FUN),      MO(_FUN),              TEAMS_MUTE_MIC,              MO(_FUN),             KC_K,               KC_M,            KC_COMM,         KC_DOT,          KC_SLSH,         KC_MINS,
                                                    // ENC_MODE_L,         KC_RALT,        LT(_NUM, KC_TAB ),      LT(_NAV,  KC_SPC),    LT(_SYM, KC_ENT),      LT(_SYM, KC_ENT),     LT(_NAV, KC_BSPC), LT(_NUM, KC_DEL ),      KC_APP,         KC_MUTE
    // ),

// qwpr https://sourceforge.net/p/qwpr/wiki/Home/
    // [_BASE  ] = LAYOUT(
    // KC_ESC,             KC_Q,           KC_W,             KC_P,               KC_R,                KC_F,                                                                                                   KC_Y,               KC_U,            KC_K,            KC_L,            KC_SCLN,            KC_EQL,
    // KC_BSPC ,      LGUI_T(KC_A),   LALT_T(KC_S),     LCTL_T(KC_D),       LSFT_T(KC_T),   MT(KC_HYPR, KC_G),                                                                                    MT(KC_HYPR, KC_H),       RSFT_T(KC_N),    RCTL_T(KC_I),    LALT_T(KC_O),    RGUI_T(KC_E),        KC_QUOT,
    // KC_LSFT,             KC_Z,           KC_X,             KC_C,               KC_V,                KC_B,              MO(_FUN),      MO(_FUN),              TEAMS_MUTE_MIC,              MO(_FUN),             KC_J,               KC_M,            KC_COMM,         KC_DOT,          KC_SLSH,         KC_MINS,
                                                    // ENC_MODE_L,         KC_RALT,        LT(_NUM, KC_TAB ),      LT(_NAV,  KC_SPC),    LT(_SYM, KC_ENT),      LT(_SYM, KC_ENT),     LT(_NAV, KC_BSPC), LT(_NUM, KC_DEL ),      KC_APP,         KC_MUTE
    // ),


// norman https://sourceforge.net/p/qwpr/wiki/Home/   qwdfkjurl;
    [_BASE  ] = LAYOUT(
    KC_ESC,             KC_Q,           KC_W,             KC_D,               KC_F,                KC_K,                                                                                                   KC_J,               KC_U,            KC_R,            KC_L,            KC_SCLN,           LT(_IDEA, KC_EQL),
    KC_BSPC ,      LGUI_T(KC_A),   LALT_T(KC_S),     LCTL_T(KC_E),       LSFT_T(KC_T),   MEH_T(KC_G),                                                                                    MEH_T(KC_Y),       RSFT_T(KC_N),    RCTL_T(KC_I),    LALT_T(KC_O),    RGUI_T(KC_H),        KC_QUOT,
    KC_LSFT,             KC_Z,           KC_X,             KC_C,               KC_V,                KC_B,              MO(_FUN),      MO(_FUN),              TEAMS_MUTE_MIC,              MO(_FUN),             KC_P,               KC_M,            KC_COMM,         KC_DOT,          KC_SLSH,         KC_MINS,
                                                    ENC_MODE_L,         KC_RALT,        LT(_NUM, KC_TAB ),      LT(_NAV,  KC_SPC),    LT(_SYM, KC_ENT),      LT(_SYM, KC_ENT),     LT(_NAV, KC_BSPC), LT(_NUM, KC_DEL ),      KC_APP,         KC_MUTE
    ),


// /*
//  * Symbol Layer: Symbols only
//  TODO: 3l layout
//  */
//     [_SYM] = LAYOUT(
//       _______, KC_HASH, KC_DLR,  KC_LCBR, KC_RCBR, KC_PIPE,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
//       _______, KC_EXLM, KC_AT,   KC_LPRN, KC_RPRN, KC_GRV,                                        KC_MINS, KC_PLUS, KC_ASTR, KC_SLSH, KC_PERC, _______,
//       _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______, _______,   _______, _______, KC_AMPR, KC_PIPE, KC_COMM, KC_DOT,  KC_SLSH, _______,
//                                  _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
//     ),

/*
 * Symbol Layer: Symbols only
 * Layout follows suggestion of 3L Layout: https://jack.rosenth.al/3l/)
 */
    [_SYM] = LAYOUT(
      _______, KC_DQT,  KC_UNDS, KC_LBRC, KC_RBRC, KC_CIRC,                                        KC_EXLM, KC_LT,   KC_GT,   KC_EQL,  KC_AMPR, _______,
      _______, KC_SLSH, KC_MINS, KC_LCBR, KC_RCBR, KC_ASTR,                                        KC_QUES, KC_LPRN, KC_RPRN, KC_QUOT, KC_COLN, _______,
      _______, KC_HASH, KC_DLR,  KC_PIPE, KC_TILD, KC_GRV, _______, _______,     _______, _______, KC_PLUS, KC_PERC, KC_BSLS, KC_AT,   _______, _______,
                                _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    ),



/*
* Nav Layer: movement and history
*/
    [_NAV] = LAYOUT(
      _______, KC_WH_L,    C(KC_LEFT), KC_UP,   C(KC_RGHT),   KC_WH_R,                                        KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, KC_BTN4, KC_ACL0,
      _______, KC_HOME,    KC_LEFT,    KC_DOWN,   KC_RGHT,    KC_END,                                         KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5, KC_ACL1,
      _______, C(KC_Z),    C(KC_X),     C(KC_C),   C(KC_V),  C(KC_Y),   _______, _______,   _______, _______,  XXXXXXX, XXXXXXX, KC_BTN3, XXXXXXX, KC_BTN6, KC_ACL2,
                                        _______, _______,     _______, _______, _______,   _______, _______, KC_BTN1, KC_BTN2, _______
  ),

// /*
// * Mouse Layer: mouse control
// TODO> SWAP sides with eddssf
// */
//     [_MSE] = LAYOUT(
//       _______, _______,  _______, _______, _______, _______,                                       _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_ACL0,
//       _______, _______,  _______, _______, _______, _______,                                       _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_ACL1,
//       _______, C(KC_Z),  KC_CUT,  KC_COPY, KC_PSTE, C(KC_Y), _______, _______,   _______, _______, KC_PGDN, _______, KC_BTN3, _______, _______, KC_ACL2,
//                                   _______, _______, _______, _______, _______,   _______, _______, KC_BTN1, KC_BTN2, _______
//   ),

// /*
// * Mouse Layer: mouse control
// TODO> SWAP sides with eddssf
// */
//     [_MSE] = LAYOUT(
//       _______, _______,  _______, _______, _______, _______,                                       KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, KC_BTN4, KC_ACL0,
//       _______, _______,  _______, _______, _______, _______,                                       KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5, KC_ACL1,
//       _______, C(KC_Z),  KC_CUT,  KC_COPY, KC_PSTE, C(KC_Y), _______, _______,   _______, _______, XXXXXXX, XXXXXXX, KC_BTN3, XXXXXXX, KC_BTN6, KC_ACL2,
//                                   _______, _______, _______, _______, _______,   _______, _______, KC_BTN1, KC_BTN2, _______
//   ),

/*
 * Numblock layer
 */
    [_NUM] = LAYOUT(
      _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                          KC_COMM,  KC_7,    KC_8,    KC_9,  KC_ASTR, KC_PSLS,
      _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                                          KC_DOT,   KC_4,    KC_5,    KC_6,  KC_PEQL, KC_AMPR,
      _______, KC_PLUS, KC_PMNS, KC_PEQL, KC_DOT,  KC_COMM, _______, _______,   _______, _______, KC_0,     KC_1,    KC_2,    KC_3,  KC_PLUS, KC_PMNS,
                                 _______, _______, _______, _______, _______,   _______, _______, _______,  _______, KC_0
    ),


/*
 * Function Layer: Function keys, RGB
 * TODO add mic mute
*/
    [_FUN] =LAYOUT(
      DB_TOGG, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,                                       KC_F12,   KC_F7,   KC_F8,  KC_F9,  KC_F15, TEAMS_CAM,
      _______, _______, _______, _______, _______, KC_VOLD,                                       KC_F11,   KC_F4,   KC_F5,  KC_F6,  KC_F14, TEAMS_HAND,
      _______, _______, _______, _______, _______, KC_MUTE, _______, _______,   _______, _______, KC_F10,   KC_F1,   KC_F2,  KC_F3,  KC_F13, TEAMS_HANGUP,
                                 _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
    ),

/*
 * IDEA layer
 */
    [_IDEA] = LAYOUT(
      _______,  A(KC_0),  LSA(KC_0),  _______,  _______,  _______,                                      RCS(KC_F14),  S(KC_F10),  S(KC_F9),  C(KC_F2),  A(KC_V), _______,
      _______,  A(KC_1),  _______,  _______,  _______,  _______,                                       RCS(KC_F8),  MEH(KC_F9),  _______,  _______,  _______, _______,
      _______,  A(KC_9),  A(KC_4),  A(KC_5),  _______,  A(KC_F12), _______, _______,   _______, _______, _______,  _______,  _______,  _______,  RCS(KC_GRV), _______,
                                    C(KC_MINS),  C(KC_PLUS),  _______, _______, _______,   _______, _______, _______,  _______,  _______
    ),

//     /*
//  * IDEA layer
//  */
//     [_IDEA] = LAYOUT(
//       _______,  _______,  _______,  _______,  _______,  _______,                                       _______,  _______,  _______,  _______,  _______, _______,
//       _______,  _______,  _______,  _______,  _______,  _______,                                       _______,  _______,  _______,  _______,  _______, _______,
//       _______,  _______,  _______,  _______,  _______,  _______, _______, _______,   _______, _______, _______,  _______,  _______,  _______,  _______, _______,
//                                     _______,  _______,  _______, _______, _______,   _______, _______, _______,  _______,  _______
//     ),
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
        encoder_action_volume(clockwise); //get_encoder_mode(false), clockwise);
#    ifdef OLED_ENABLE
        oled_on();
#    endif
    }
    return true;
}
#endif
