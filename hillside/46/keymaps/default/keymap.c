#include QMK_KEYBOARD_H

#define L_DEF 0
#define L_SYM 1
#define L_NAV 2
#define L_FNC 3
#define L_CFG 4

// Tap Dance declarations
enum {
  TD_CCP,
  TD_LBKT,
  TD_RBKT,
  TD_LANG,
};

enum {
  COMBO_ESC,
  COMBO_TAB,
  COMBO_DEL,
  COMBO_BACKSPACE,
  COMBO_ENTER,
  COMBO_LANG
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

void dance_lang(tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    tap_code(KP_SPC);
  } else if (state->count == 2) {
    tap_code(KC_RALT);
  } else {
    reset_tap_dance (state);
  }
}

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
  [TD_CCP] = ACTION_TAP_DANCE_FN(dance_ccp),
  [TD_LBKT] = ACTION_TAP_DANCE_FN(dance_lbkt),
  [TD_RBKT] = ACTION_TAP_DANCE_FN(dance_rbkt),
  [TD_LANG] = ACTION_TAP_DANCE_FN(dance_lang),
};

const uint16_t PROGMEM combo1[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo2[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo3[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo4[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo5[] = {KC_L, KC_SEMICOLON, COMBO_END};
const uint16_t PROGMEM combo6[] = {KC_X, KC_C, COMBO_END};

combo_t key_combos[] = {
  [COMBO_ESC] = COMBO(combo1, KC_ESC),
  [COMBO_BACKSPACE] = COMBO(combo3, KC_BSPC),
  [COMBO_ENTER] = COMBO(combo5, KC_ENT),
  [COMBO_TAB] = COMBO(combo2, KC_TAB),
  [COMBO_DEL] = COMBO(combo4, KC_DELETE),
  [COMBO_LANG] = COMBO(combo6, KC_RALT),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[L_DEF] = LAYOUT(
  __XX__,  KP_Q__,  KP_W__,  KP_E__,  KP_R__,  KP_T__,                      KP_Y__,  KP_U__,  KP_I__,  KP_O__,  KP_P__,  __XX__,
  __XX__,  MT_A__,  KP_S__,  KP_D__,  KP_F__,  KP_G__,                      KP_H__,  KP_J__,  KP_K__,  KP_L__,  MT_SMC,  __XX__,
  __XX__,  MT_Z__,  MT_X__,  MT_C__,  KP_V__,  KP_B__,  TD_COP,    TD_COP,  KP_N__,  KP_M__,  MT_CMA,  MT_DOT,  MT_SLS,  __XX__,
                             KP_AU_,  KP_AD_,  TD_LAN,  MO_NUM,    MO_SYM,  LT_ENT,  KP_AL_,  KP_AR_
  ),

[L_SYM] = LAYOUT(
  __XX__,  KP_EXC,  KP_AT_,  KP_HSH,  KP_DLR,  KP_PCT,                      KP_CRT,  KP_AMP,  KP_AST,  KP_UND,  KP_EQL,  __XX__,
  __XX__,  KP_SFT,  KP_GRV,  KP_TID,  TD_LPR,  KP_LBK,                      KP_RBK,  TD_RPR,  KP_PIP,  KP_BSL,  KP_SFT,  __XX__,
  __XX__,  KP_CTL,  KP_GUI,  KP_ALT,  KP_APS,  KP_KMI,  __XX__,    CP_WRD,  KP_PLS,  KP_DQT,  KP_ALT,  KP_GUI,  KP_CTL,  __XX__,
                             _TRNS_,  _TRNS_,  _TRNS_,  MO_CFG,    _TRNS_,  _TRNS_,  _TRNS_,  _TRNS_
  ),

[L_NAV] = LAYOUT(
  __XX__,  __XX__,  KP_PSC,  KP_SLK,  KP_BRK,  KP_NLK,                      KP_7__,  KP_8__,  KP_9__,  KP_AST,  KP_MIN,  __XX__,
  __XX__,  KP_SFT,  __XX__,  __XX__,  KP_INS,  KP_HOM,                      KP_4__,  KP_5__,  KP_6__,  KP_SLS,  KP_PLS,  __XX__,
  __XX__,  KP_CTL,  KP_GUI,  KP_ALT,  KP_DEL,  KP_END,  __XX__,    OS_SCP,  KP_1__,  KP_2__,  KP_3__,  KP_DT_,  KP_0__,  __XX__,
                             _TRNS_,  _TRNS_,  _TRNS_,  _TRNS_,    MO_CFG,  _TRNS_,  _TRNS_,  _TRNS_
  ),

[L_FNC] = LAYOUT(
  __XX__,  __XX__,  __XX__,  __XX__,  KP_END,  __XX__,                      KP_HOM,  KP_PUP,  __XX__,  __XX__,  __XX__,  __XX__,
  __XX__,  KP_SFT,  __XX__,  KP_PDN,  __XX__,  __XX__,                      KP_AL_,  KP_AD_,  KP_AU_,  KP_AR_,  __XX__,  __XX__,
  __XX__,  KP_CTL,  KP_GUI,  KP_ALT,  __XX__,  __XX__,  __XX__,    __XX__,  __XX__,  __XX__,  __XX__,  __XX__,  __XX__,  __XX__,
                             _TRNS_,  _TRNS_,  _TRNS_,  _TRNS_,    _TRNS_,  _TRNS_,  _TRNS_,  _TRNS_
  ),

[L_CFG] = LAYOUT(
  __XX__,  __XX__,  __XX__,  __XX__,  __XX__,  __XX__,                      KP_F7_,  KP_F8_,  KP_F9_,  KP_F12,  __XX__,  __XX__,
  __XX__,  KP_SFT,  __XX__,  __XX__,  __XX__,  __XX__,                      KP_F4_,  KP_F5_,  KP_F6_,  KP_F11,  __XX__,  __XX__,
  __XX__,  KP_CTL,  KP_GUI,  KP_ALT,  __XX__,  __XX__,  AG_NOR,    AG_TOG,  KP_F1_,  KP_F2_,  KP_F3_,  KP_F10,  __XX__,  __XX__,
                             __XX__,  __XX__,  __XX__,  _TRNS_,    _TRNS_,  __XX__,  __XX__,  __XX__
  )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
  [L_DEF] = { ENCODER_CCW_CW(LCTL(LGUI(KC_LEFT)), LCTL(LGUI(KC_RIGHT))), ENCODER_CCW_CW(KC_NO, KC_NO) },
  [L_SYM] = { ENCODER_CCW_CW(LCTL(KC_Z), LCTL(LSFT(KC_Z))),  ENCODER_CCW_CW(KC_NO, KC_NO)  },
  [L_NAV] = { ENCODER_CCW_CW(LCTL(LSFT(KC_TAB)), LCTL(KC_TAB)),  ENCODER_CCW_CW(KC_NO, KC_NO)  },
  [L_FNC] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN),  ENCODER_CCW_CW(KC_NO, KC_NO)  },
  [L_CFG] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_NO, KC_NO) },
};
#endif