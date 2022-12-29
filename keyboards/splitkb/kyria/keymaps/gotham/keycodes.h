#pragma once

#include "quantum.h"

enum layers { _QWERTY = 0, _SYM, _NUM, _NAV, _MSE, _FUN };

enum custom_keycodes {
    ENC_MODE_L = SAFE_RANGE,
    ENC_MODE_R,
    TMB_MODE,
};

#define SFT_QUOT   MT(MOD_RSFT, KC_QUOT)
#define CTL_MINS   MT(MOD_RCTL, KC_MINS)
#define MUTE_MIC   C(S(KC_M))
