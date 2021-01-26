#include QMK_KEYBOARD_H
#include "matrix.h"

#define _KEYS 0
#define _MEDIA 1
#define _PROD 2

#define M_AT M(0)
#define M_AST M(1)
#define M_NT M(2)
#define M_CT M(3)

uint16_t layer_timer;
uint8_t layer = 0;
uint8_t num_pressed = 0;

enum {
    TD_LAYERS = 0
};

int cur_dance (qk_tap_dance_state_t *state);
void x_finished (qk_tap_dance_state_t *state, void *user_data);
void x_reset (qk_tap_dance_state_t *state, void *user_data);

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LAYERS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_KEYS] = LAYOUT(
        KC_ENT, KC_UP, KC_DEL,
        KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [_MEDIA] = LAYOUT(
        KC_VOLD, KC_F, KC_VOLU,
        KC_LEFT, KC_SPACE, KC_RIGHT
    ),
    [_PROD] = LAYOUT(
        M_CT, KC_UP, M_NT,
        M_AST, KC_DOWN, M_AT
    )
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if(record->event.pressed) {
        switch(id) {
            case 0: return MACRO(D(LCTL), T(TAB), U(LCTL), END);
            case 1: {
                // num_pressed++;
                return MACRO(D(LCTL), D(LSFT), T(TAB), U(LSFT), U(LCTL), END);
            }
            case 2: return MACRO(D(LCTL), T(T), U(LCTL), END);
            case 3: return MACRO(D(LCTL), T(W), U(LCTL), END);
        }
    } else if(id == 1) {
        // num_pressed--;
    }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if(record->event.pressed) {
        num_pressed++;
    } else num_pressed--;

    if(num_pressed == 1) {
        layer_timer = timer_read();
    }
    return false;
}

void matrix_scan_user(void) {
  // jump to bootloaer when all keys are pressed
  if (matrix_get_row(0) == 0b111 && matrix_get_row(1) == 0b111) {
    clear_keyboard();
    bootloader_jump();
  }
}

void man_layer(void) {
    layer_off(layer);
    layer = (layer+1)%3;

    switch(layer) {
        case _KEYS: {
            DDRF |= (1<<7);
            DDRB |= (1<<6);
            DDRF &= ~(1<<6);
        } break;
        case _MEDIA: {
            DDRF |= (1<<6);
            DDRB |= (1<<6);
            DDRF &= ~(1<<7);
        } break;
        case _PROD: {
            DDRF |= (1<<7);
            DDRB &= ~(1<<6);
            DDRF |= (1<<6);
        }
    }

    layer_on(layer);
}

void x_finished (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2 && state->pressed) {
            man_layer();
    } else {
        if(layer == 0 || layer == 1) {
            register_code(KC_LEFT);
        } else {
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(KC_TAB);
            unregister_code(KC_TAB);
            unregister_code(KC_LSFT);
            unregister_code(KC_LCTL);
        }
    } 
}

void x_reset (qk_tap_dance_state_t *state, void *user_data) {
    if(layer == 0 || layer == 1) {
        // unregister_code(KC_LEFT);
    } else {
        // unregister_code(KC_SPACE);
    }
}
