#include "encoder_utils.h"

void encoder_utils_init(void) {
    encoder_left_mode  = ENC_MODE_LEFT_RIGHT;
    // encoder_right_mode = ENC_MODE_VOLUME;
}

void set_encoder_mode(bool left, encoder_mode_t mode) {
    if (left) {
        encoder_left_mode = mode;
    } else {
        // encoder_right_mode = mode;
    }
}

encoder_mode_t get_encoder_mode(bool left) {
    if (left) {
        return encoder_left_mode;
    } else {
        return encoder_right_mode;
    }
}

void cycle_encoder_mode(bool left, bool reverse) {
    encoder_mode_t mode = get_encoder_mode(left);
    if (reverse) {
        mode = (mode == 0) ? (_ENC_MODE_LAST - 1) : (mode - 1);
    } else {
        mode = (mode == (_ENC_MODE_LAST - 1)) ? 0 : (mode + 1);
    }
    set_encoder_mode(left, mode);
}

void encoder_action_volume(uint8_t clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
}

void encoder_action_word_nav(uint8_t clockwise) {
    if (clockwise) {
        tap_code16(C(KC_RIGHT));
    } else {
        tap_code16(C(KC_LEFT));
    }
}

void encoder_action_left_right(uint8_t clockwise) {
    if (clockwise) {
        tap_code(KC_WH_R);
    } else {
        tap_code(KC_WH_L);
    }
}

void encoder_action_up_down(uint8_t clockwise) {
    if (clockwise) {
        tap_code(KC_WH_U);
    } else {
        tap_code(KC_WH_D);
    }
}

void encoder_action_tab(uint8_t clockwise){
    if (clockwise) {
        tap_code16(KC_TAB);
    } else {
        tap_code16(S(KC_TAB));
    }
}

void encoder_action(encoder_mode_t mode, uint8_t clockwise) {
    switch (mode) {
        // case ENC_MODE_VOLUME:
        //     encoder_action_volume(clockwise);
        //     break;
        // case ENC_MODE_WORD_NAV:
        //     encoder_action_word_nav(clockwise);
        //     break;
        case ENC_MODE_LEFT_RIGHT:
            encoder_action_left_right(clockwise);
            break;
        // case ENC_MODE_TAB:
        //     encoder_action_tab(clockwise);
            break;
        case ENC_MODE_UP_DOWN:
            encoder_action_up_down(clockwise);
            break;
        default:
            encoder_action_volume(clockwise);
    }
}
