#include QMK_KEYBOARD_H

#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3
#define _LAYER4 4

enum custom_keycodes {
  LAYER0 = SAFE_RANGE,
  LAYER1,
  LAYER2,
  LAYER3,
  LAYER4,
};


// Tap Dance declarations
enum {
  TD_1,
  TD_2,
  TD_3,
  TD_4,
  TD_5,
  TD_6,
  TD_7,
  TD_8,
  TD_9,
  TD_10,
  TD_11,
  TD_12,
  TD_CCP,
  TD_LBKT,
  TD_RBKT,
};

enum {
  COMBO_ESC,
  COMBO_TAB,
  COMBO_DEL,
  COMBO_BACKSPACE,
  COMBO_ENTER
};

void dance_ccp (tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
      register_code(KC_LCTL);
      tap_code(KC_V);
      unregister_code(KC_LCTL);
    } else if (state->count == 2) {
      register_code(KC_LCTL);
      tap_code(KC_C);
      unregister_code(KC_LCTL);
    } else if (state->count == 3) {
      register_code(KC_LCTL);
      tap_code(KC_X);
      unregister_code(KC_LCTL);
    } else {
      reset_tap_dance (state);
    }
}

void dance_lbkt (tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
      register_code(KC_LSFT);
      tap_code(KC_9);
      unregister_code(KC_LSFT);
    } else if (state->count == 2) {
      register_code(KC_LSFT);
      tap_code(KC_LEFT_BRACKET);
      unregister_code(KC_LSFT);
    } else if (state->count == 3) {
      tap_code(KC_LEFT_BRACKET);
    } else {
      reset_tap_dance (state);
    }
}

void dance_rbkt (tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
      register_code(KC_LSFT);
      tap_code(KC_0);
      unregister_code(KC_LSFT);
    } else if (state->count == 2) {
      register_code(KC_RSFT);
      tap_code(KC_RIGHT_BRACKET);
      unregister_code(KC_RSFT);
    } else if (state->count == 3) {
      tap_code(KC_RIGHT_BRACKET);
    } else {
      reset_tap_dance (state);
    }
}

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
  // Tap once for Escape, twice for Caps Lock
  [TD_1] = ACTION_TAP_DANCE_DOUBLE(KC_KP_1, KC_F1),
  [TD_2] = ACTION_TAP_DANCE_DOUBLE(KC_KP_2, KC_F2),
  [TD_3] = ACTION_TAP_DANCE_DOUBLE(KC_KP_3, KC_F3),
  [TD_4] = ACTION_TAP_DANCE_DOUBLE(KC_KP_4, KC_F4),
  [TD_5] = ACTION_TAP_DANCE_DOUBLE(KC_KP_5, KC_F5),
  [TD_6] = ACTION_TAP_DANCE_DOUBLE(KC_KP_6, KC_F6),
  [TD_7] = ACTION_TAP_DANCE_DOUBLE(KC_KP_7, KC_F7),
  [TD_8] = ACTION_TAP_DANCE_DOUBLE(KC_KP_8, KC_F8),
  [TD_9] = ACTION_TAP_DANCE_DOUBLE(KC_KP_9, KC_F9),
  [TD_10] = ACTION_TAP_DANCE_DOUBLE(KC_KP_0, KC_F10),
  [TD_11] = ACTION_TAP_DANCE_DOUBLE(KC_PSLS, KC_F11),
  [TD_12] = ACTION_TAP_DANCE_DOUBLE(KC_PAST, KC_F12),
  [TD_CCP] = ACTION_TAP_DANCE_FN(dance_ccp),
  [TD_LBKT] = ACTION_TAP_DANCE_FN(dance_lbkt),
  [TD_RBKT] = ACTION_TAP_DANCE_FN(dance_rbkt),
};

const uint16_t PROGMEM combo1[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo2[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo3[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo4[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo5[] = {KC_L, KC_SEMICOLON, COMBO_END};

combo_t key_combos[] = {
  [COMBO_ESC] = COMBO(combo1, KC_ESC),
  [COMBO_BACKSPACE] = COMBO(combo3, KC_BSPC),
  [COMBO_ENTER] = COMBO(combo5, KC_ENT),
  [COMBO_TAB] = COMBO(combo2, KC_TAB),
  [COMBO_DEL] = COMBO(combo4, KC_DELETE),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_LAYER0] = LAYOUT(
  __XX__,  KP_Q__,  KP_W__,  KP_E__,  KP_R__,  KP_T__,                      KP_Y__,  KP_U__,  KP_I__,  KP_O__,  KP_P__,  __XX__,
  __XX__,  MT_A__,  KP_S__,  KP_D__,  KP_F__,  KP_G__,                      KP_H__,  KP_J__,  KP_K__,  KP_L__,  MT_SMC,  __XX__,
  __XX__,  MT_Z__,  MT_X__,  MT_C__,  KP_V__,  KP_B__,  __XX__,    TD_COP,  KP_N__,  KP_M__,  MT_CMA,  MT_DOT,  MT_SLS,  __XX__,
                             KP_AU_,  KP_AD_,  KP_SPC,  MO_NUM,    MO_SYM,  LT_ENT,  KP_AL_,  KP_AR_
  ),

[_LAYER1] = LAYOUT(
  __XX__,  KP_EXC,  KP_AT_,  KP_HSH,  KP_DLR,  KP_PCT,                      KP_CRT,  KP_AMP,  KP_AST,  KP_UND,  KP_EQL,  __XX__,
  __XX__,  KP_SFT,  KP_GRV,  KP_TID,  TD_LPR,  KP_LBK,                      KP_RBK,  TD_RPR,  KP_PIP,  KP_BSL,  KP_SFT,  __XX__,
  __XX__,  KP_CTL,  KP_GUI,  KP_ALT,  KP_APS,  KP_KMI,  __XX__,    CP_WRD,  KP_PLS,  KP_DQT,  KP_ALT,  KP_GUI,  KP_CTL,  __XX__,
                             _TRNS_,  _TRNS_,  _TRNS_,  MO_CFG,    _TRNS_,  _TRNS_,  _TRNS_,  _TRNS_
  ),

[_LAYER2] = LAYOUT(
  __XX__,  __XX__,  KP_PSC,  KP_SLK,  KP_BRK,  KP_NLK,                      TD_AST,  TD_7__,  TD_8__,  TD_9__,  KP_MIN,  __XX__,
  __XX__,  KP_SFT,  __XX__,  __XX__,  KP_INS,  KP_HOM,                      TD_SLS,  TD_4__,  TD_5__,  TD_6__,  KP_PLS,  __XX__,
  __XX__,  KP_CTL,  KP_GUI,  KP_ALT,  KP_DEL,  KP_END,  __XX__,    OS_SCP,  TD_0__,  TD_1__,  TD_2__,  TD_3__,  KP_DT_,  __XX__,
                             _TRNS_,  _TRNS_,  _TRNS_,  _TRNS_,    MO_CFG,  _TRNS_,  _TRNS_,  _TRNS_
  ),

[_LAYER3] = LAYOUT(
  __XX__,  __XX__,  __XX__,  __XX__,  KP_END,  __XX__,                      KP_HOM,  KP_PUP,  __XX__,  __XX__,  __XX__,  __XX__,
  __XX__,  KP_SFT,  __XX__,  KP_PDN,  __XX__,  __XX__,                      KP_AL_,  KP_AD_,  KP_AU_,  KP_AR_,  __XX__,  __XX__,
  __XX__,  KP_CTL,  KP_GUI,  KP_ALT,  __XX__,  __XX__,  __XX__,    __XX__,  __XX__,  __XX__,  __XX__,  __XX__,  __XX__,  __XX__,
                             _TRNS_,  _TRNS_,  _TRNS_,  _TRNS_,    _TRNS_,  _TRNS_,  _TRNS_,  _TRNS_
  ),

[_LAYER4] = LAYOUT(
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, AG_NORM,    AG_SWAP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                       KC_NO, KC_NO, KC_NO, KC_TRNS,    KC_TRNS, KC_NO, KC_NO, KC_NO
  )

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(LCTL(LGUI(KC_LEFT)), LCTL(LGUI(KC_RIGHT))), ENCODER_CCW_CW(KC_NO, KC_NO) },
    [1] = { ENCODER_CCW_CW(LCTL(KC_Z), LCTL(LSFT(KC_Z))),  ENCODER_CCW_CW(KC_NO, KC_NO)  },
    [2] = { ENCODER_CCW_CW(LCTL(LSFT(KC_TAB)), LCTL(KC_TAB)),  ENCODER_CCW_CW(KC_NO, KC_NO)  },
    [3] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN),  ENCODER_CCW_CW(KC_NO, KC_NO)  },
    [4] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_NO, KC_NO) },
};
#endif