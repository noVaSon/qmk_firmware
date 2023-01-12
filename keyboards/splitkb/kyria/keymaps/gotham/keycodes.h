#pragma once

#include "quantum.h"

enum layers { _NORMAN = 0, _QWERTY ,_SYM, _NUM, _NAV, _FUN, _IDEA };

enum custom_keycodes {
    ENC_MODE_L = SAFE_RANGE,
    ENC_MODE_R,
    TMB_MODE,
    DEFAULT_QWERTY,
    DEFAULT_NORMAN
};

#define TEAMS_MUTE_MIC   C(S(KC_M))
#define TEAMS_CAM    S(C(KC_O))
#define TEAMS_HAND   S(C(KC_K))
#define TEAMS_HANGUP S(C(KC_H))
