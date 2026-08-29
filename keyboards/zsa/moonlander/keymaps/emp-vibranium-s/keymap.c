#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE,

  ST_FORCE_EQUAL,
  ST_FORCE_SLASH,
  ST_FORCE_BSLS,
  ST_FORCE_MINUS,
  ST_FORCE_GRAVE,
  ST_FORCE_LBRC,
  ST_FORCE_RBRC,
  ST_FORCE_ZERO,
  ST_FORCE_ONE,
  ST_FORCE_X,

  ST_MACRO_QU, KC_ALNUM_MACRO_FIRST = ST_MACRO_QU,

  AD_MACRO_MC,

  AD_MACRO_SX, KC_ALNUM_MACRO_LAST = AD_MACRO_SX,
};

enum Layers {
  _BASE,
  _LMOD,
  _RMOD,
  _NUM,
  _NUMPAD,
  _FN,
  _LEFT,
  _LFN,
  _FIRMWARE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_moonlander(
    XXXXXXX,        KC_7,           KC_3,           KC_1,           KC_5,           KC_9,           XXXXXXX,                                        XXXXXXX,        KC_6,           KC_2,           KC_0,           KC_4,           KC_8,           XXXXXXX,
    KC_GRAVE,       LT(0,KC_Z),     KC_W,           KC_H,           KC_M,           KC_K,           KC_BACKSPACE,                                   KC_INSERT,      KC_MINUS,       KC_QUOT,        KC_COMMA,       KC_DOT,         KC_SLASH,       KC_BSLS,
    KC_TAB,         KC_V,           KC_C,           KC_N,           KC_T,           KC_B,           KC_DELETE,                                      KC_UNDS,        KC_PLUS,        KC_A,           KC_E,           KC_I,           KC_QUES,        KC_ASTR,
    MO(_LEFT),      KC_S,           KC_P,           KC_L,           KC_D,           KC_G,                                                                           KC_EQUAL,       KC_U,           KC_O,           KC_Y,           KC_J,           CW_TOGG,
    TO(_LEFT),      KC_X,           KC_F,           MO(_NUM),       LM(_LMOD,MOD_LSFT),             KC_ESCAPE,                                      RCTL(KC_BSPC),             LM(_RMOD,MOD_RSFT),  MO(_FN),        KC_SCLN,        KC_AT,          XXXXXXX,
    KC_SPACE,       KC_ENTER,       XXXXXXX,                        XXXXXXX,        KC_ENTER,       KC_R
  ),

  [_LMOD] = LAYOUT_moonlander(
    _______,        _______,        _______,        ST_FORCE_ONE,   _______,        _______,        _______,                                        _______,        _______,        _______,        ST_FORCE_ZERO,  _______,        _______,        _______,
    ST_FORCE_GRAVE, ST_FORCE_LBRC,  ST_FORCE_RBRC,  KC_LCBR,        KC_RCBR,        KC_PERC,        _______,                                        _______,        ST_FORCE_MINUS, _______,        _______,        _______,        ST_FORCE_SLASH, ST_FORCE_BSLS,
    _______,        KC_AMPR,        KC_LGUI,        KC_LALT,        KC_LCTL,        XXXXXXX,        _______,                                        KC_SPACE,       _______,        _______,        _______,        _______,        KC_EXLM,        _______,
    _______,        KC_PIPE,        KC_LPRN,        KC_RPRN,        KC_DLR,         KC_CIRC,                                                                        ST_FORCE_EQUAL, _______,        _______,        _______,        _______,        _______,
    XXXXXXX,        ST_FORCE_X,     _______,        _______,        _______,                        _______,                                        RCTL(KC_BSPC),                  _______,        _______,        _______,        _______,          _______,
    _______,        XXXXXXX,        _______,                        _______,        _______,        _______
  ),

  [_RMOD] = LAYOUT_moonlander(
    _______,        _______,        _______,        ST_FORCE_ONE,   _______,        _______,        _______,                                        _______,        _______,        _______,        ST_FORCE_ZERO,  _______,        _______,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        ST_FORCE_MINUS, _______,        _______,        _______,        ST_FORCE_SLASH, ST_FORCE_BSLS,
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        KC_RCTL,        KC_RALT,        KC_RGUI,        KC_EXLM,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,                                                                        ST_FORCE_EQUAL, KC_AMPR,        KC_PIPE,        KC_HASH,        _______,        _______,
    XXXXXXX,        _______,        _______,        _______,        _______,                        _______,                                        RCTL(KC_BSPC),                  _______,        _______,        _______,        _______,          _______,
    _______,        _______,        _______,                        _______,        XXXXXXX,        _______
  ),

  [_NUM] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______,
    _______,        KC_LBRC,        KC_RBRC,        KC_LCBR,        KC_RCBR,        KC_PERC,        _______,                                        TO(_NUMPAD),    KC_MINUS,       KC_7,           KC_8,           KC_9,           KC_SLASH,       _______,
    _______, KC_DLR,  MT(MOD_LGUI,KC_LEFT), MT(MOD_LALT,KC_UP), MT(MOD_LCTL,KC_DOWN), KC_RIGHT,     _______,                                        _______,        KC_PLUS,        KC_4,           KC_5,           KC_6,           KC_COMMA,       _______,
    _______,        KC_LABK,        KC_LPRN,        KC_RPRN,        KC_EQUAL,       KC_RABK,                                                                        KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_KP_EQUAL,    _______,
    TO(0),          _______,        TO(_FN),        TO(0),          _______,                        _______,                                        KC_BSPC,                        KC_0,           KC_DOT,         KC_COLN,        KC_HASH,        TO(0),
    TO(_NUMPAD),    _______,        _______,                        _______,        KC_ENTER,       _______
  ),

  [_NUMPAD] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        KC_NUM,         KC_KP_MINUS,    KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_SLASH,    _______,
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        KC_KP_PLUS,     KC_KP_4,        KC_KP_5,        KC_KP_6,        _______,        _______,
    _______,        KC_LPRN,        KC_EQUAL,       KC_LBRC,        KC_RBRC,        KC_RPRN,                                                                        KC_KP_EQUAL,    KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_EQUAL,    _______,
    TO(0),          _______,        TO(_FN),        TO(0),          _______,                        _______,                                        KC_BSPC,                        KC_KP_0,        KC_KP_DOT,      _______,        KC_KP_ASTERISK, TO(0),
    TO(_NUM),       KC_KP_COMMA,    _______,                        _______,        KC_KP_ENTER,    _______
  ),

  [_FN] = LAYOUT_moonlander(
    _______,        KC_F14,         KC_F12,         KC_F11,         KC_F10,         KC_F15,         _______,                                        _______,        KC_F16,         KC_F17,         KC_F18,         KC_F19,         KC_F20,         _______,
    _______,        KC_F13,         KC_F9,          KC_F8,          KC_F7,          KC_F23,         KC_F24,                                         KC_INSERT,      KC_ESCAPE,      KC_MPRV,        KC_MNXT,        KC_MPLY,        KC_MUTE,        KC_VOLU,
    _______,      KC_BRIU, MT(MOD_LGUI,KC_F6), MT(MOD_LALT,KC_F5), MT(MOD_LCTL,KC_F4), KC_F22,      _______,                                        KC_DELETE,      KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TAB,         KC_VOLD,
    _______,        KC_BRID,        KC_F3,       KC_F2,          KC_F1,          KC_F21,                                                                            KC_HOME,        KC_PGDN,        KC_PAGE_UP,     KC_END,         LCTL(KC_G),     KC_WWW_SEARCH,
    TO(0),          _______,        TO(0),          TO(_NUM),       _______,                        _______,                                        KC_BSPC,                        KC_RIGHT_SHIFT, TO(0),          _______,        _______,        TO(0),
    _______,        _______,        _______,                        _______,        _______,        _______
  ),

  [_LEFT] = LAYOUT_moonlander(
    _______,        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           _______,                                        _______,        KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           _______,
    KC_GRAVE,       KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,                                           KC_LBRC,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_MINUS,
    KC_TAB,         KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,                                           KC_EQUAL,       KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,
    MO(_LFN),       KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RIGHT_CTRL,
    KC_LEFT_ALT,    _______,        KC_LEFT_GUI,    KC_LEFT_CTRL,   KC_LEFT_SHIFT,                  KC_ESCAPE,                                      KC_BSPC,                        KC_RIGHT_SHIFT, KC_RIGHT_ALT,   KC_CAPS,        _______,        TO(0),
    KC_SPACE,       KC_ENTER,       _______,                        _______,        _______,        _______
  ),

  [_LFN] = LAYOUT_moonlander(
    _______,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______,
    KC_DELETE,      KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_U,                                           KC_RBRC,        UG_VALU,        UG_VALU,        UG_VALU,        DT_UP,          DT_PRNT,        KC_SCRL,
    KC_BSPC,        KC_F11,         KC_LEFT,        KC_UP,          KC_DOWN,        KC_RIGHT,       KC_L,                                           XXXXXXX,        UG_VALD,        UG_VALD,        UG_VALD,        DT_DOWN,        KC_PAUSE,       KC_PSCR,
    KC_RIGHT_ALT,   KC_F12,         KC_HOME,        KC_PAGE_UP,     KC_PGDN,        KC_END,                                                                         CM_OFF,         CM_ON,          LED_LEVEL,      AU_TOGG,        KC_BSLS,        KC_RIGHT_CTRL,
    _______,        _______,        KC_RIGHT_GUI,   KC_RIGHT_CTRL,  KC_LEFT_SHIFT,                  KC_ESCAPE,                                      KC_BSPC,                        MO(_FIRMWARE),  _______,        _______,        _______,        TO(0),
    KC_SPACE,       KC_ENTER,       _______,                        _______,        TO(0),          _______
  ),

  [_FIRMWARE] = LAYOUT_moonlander(
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        EE_CLR,         XXXXXXX,                                        XXXXXXX,        QK_BOOT,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                                                                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
    TO(0),          XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                        XXXXXXX,                                        XXXXXXX,                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        TO(0),
    XXXXXXX,        XXXXXXX,        XXXXXXX,                        XXXXXXX,        XXXXXXX,        XXXXXXX
  ),
};

enum combo_index {
  AD_MC_MC, ADAPTIVE_FIRST = AD_MC_MC,

  // Left pinky adaptives
  AD_XS_SX, ADAPTIVE_LAST = AD_XS_SX,

  ST_COMBO_KG,
};

// Bigram combo
const uint16_t PROGMEM comboKG[] = { KC_K, KC_G, COMBO_END };

// Miscellaneous letters
const uint16_t PROGMEM adaptiveMC[] = { KC_M, KC_C, COMBO_END };

// Left pinky adaptives
const uint16_t PROGMEM adaptiveXS[] = { KC_X, KC_S, COMBO_END };

combo_t key_combos[] = {
  [AD_MC_MC] = COMBO(adaptiveMC, AD_MACRO_MC), // Mc names are common, mc never starts a word.

  [AD_XS_SX] = COMBO(adaptiveXS, AD_MACRO_SX), // jsx

  [ST_COMBO_KG] = COMBO(comboKG, ST_MACRO_QU),
};

inline bool is_adaptive(uint16_t index) {
  switch (index) {
  case ADAPTIVE_FIRST ... ADAPTIVE_LAST: return true;
  default: return false;
  }
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
    case ST_COMBO_KG:
        return COMBO_TERM + 50;
    default:
        return is_adaptive(index) ? ADAPTIVE_TERM : COMBO_TERM;
    }
}

bool get_combo_must_press_in_order(uint16_t index, combo_t *combo) {
    return is_adaptive(index);
}

// Disabled
bool get_combo_must_tap(uint16_t index, combo_t *combo) {
  return false;
}

// Disabled
bool get_combo_must_hold(uint16_t index, combo_t *combo) {
  return false;
}

bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
  // Keycodes that continue Caps Word, with shift applied.
  case KC_A ... KC_Z:
  case KC_SCLN:
  case KC_MINS:
    add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to this key.
    return true;

  // Keycodes that continue Caps Word, without shifting.
  case KC_1 ... KC_0:
  case KC_BSPC:
  case RCTL(KC_BSPC):
  case KC_LEFT:
  case KC_DOWN:
  case KC_UP:
  case KC_RIGHT:
  case KC_HOME:
  case KC_END:
  case KC_PGUP:
  case KC_PGDN:
  case KC_DEL:
  case KC_UNDS:
  case KC_QUOTE:
  case KC_SLASH:
  case KC_PLUS:
  case KC_ASTR:
  case KC_BSLS:
  case ST_FORCE_MINUS:
  case ST_FORCE_GRAVE:
  case ST_FORCE_SLASH:
  case KC_ALNUM_MACRO_FIRST ... KC_ALNUM_MACRO_LAST:
    return true;

  default:
    return false;  // Deactivate Caps Word.
  }
}

uint8_t current_mods;
#define SEND_STRING_CLEAR(KEYS) \
  current_mods = get_mods(); \
  clear_mods(); \
  SEND_STRING(KEYS); \
  register_mods(current_mods);

#define SEND_STRINGS(BASE, SHIFTED, CAPS) \
  if (is_caps_word_on()) SEND_STRING(CAPS); \
  else if ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) { \
    SEND_STRING_CLEAR(SHIFTED); \
  } \
  else SEND_STRING(BASE);

#define SEND_CASED_STRINGS(NAME, BASE, SHIFTED, CAPS) \
   case (NAME): \
    if (record->event.pressed) { \
      SEND_STRINGS(BASE, SHIFTED, CAPS); \
    } \
    return true;

#define SEND_FORCED_STRING(NAME, RESULT) \
   case (NAME): \
    if (record->event.pressed) { \
      SEND_STRING_CLEAR(RESULT); \
    } \
    return true;

#define TAPHOLD_CODE16(NAME, RESULT) \
    case (NAME): \
    if (!record->tap.count && record->event.pressed) { \
      tap_code16(RESULT); \
      return false; \
    } \
    return true;

#define TAPHOLD_CASED(NAME, BASE, SHIFTED, CAPS) \
    case (NAME): \
    if (!record->tap.count && record->event.pressed) { \
      SEND_STRINGS(BASE, SHIFTED, CAPS); \
      return true; \
    } \
    return true;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    SEND_CASED_STRINGS(AD_MACRO_MC, "mc", "Mc", "MC");

    SEND_CASED_STRINGS(AD_MACRO_SX, "sx", "Sx", "SX");

    SEND_CASED_STRINGS(ST_MACRO_QU, "qu", "Qu", "QU");

  // Forced characters
    SEND_FORCED_STRING(ST_FORCE_EQUAL, "=");
    SEND_FORCED_STRING(ST_FORCE_SLASH, "/");
    SEND_FORCED_STRING(ST_FORCE_BSLS, "\\");
    SEND_FORCED_STRING(ST_FORCE_MINUS, "-");
    SEND_FORCED_STRING(ST_FORCE_GRAVE, "`");
    SEND_FORCED_STRING(ST_FORCE_LBRC, "[");
    SEND_FORCED_STRING(ST_FORCE_RBRC, "]");
    SEND_FORCED_STRING(ST_FORCE_ZERO, "0");
    SEND_FORCED_STRING(ST_FORCE_ONE, "1");
    SEND_FORCED_STRING(ST_FORCE_X, "x");

  // Tap-hold keys
    TAPHOLD_CASED(LT(0,KC_Z), "q", "Q", "Q");

  default:
    return true;
  }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case MT(MOD_LGUI, KC_LEFT):
  case MT(MOD_LALT, KC_UP):
  case MT(MOD_LCTL, KC_DOWN):
    return g_tapping_term + 50;
  case LT(0,KC_Z):
    return g_tapping_term + 150;
  default:
    return g_tapping_term;
  }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

#define CL_BASE {93,255,191}
#define CL_NUM {36,255,193}
#define CL_NUMPAD {52,255,193}
#define CL_FN {203,196,165}
#define CL_FIRMWARE {8,235,250}
#define CL_LEFT {101,206,157}
#define CL_MOD {86,255,204}
#define CL_OFF {0,0,0}
#define CL_CLEAR {67,180,255}
#define CL_MEDIA {102,255,143}
#define CL_LFN {237,234,175}

#define CL_TAP_HOLD {128,242,161}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [_BASE] = {
        CL_BASE, CL_BASE, CL_BASE, CL_LEFT, CL_LEFT,
        CL_BASE, CL_BASE, CL_BASE, CL_BASE, CL_BASE,
        CL_BASE, CL_BASE, CL_BASE, CL_BASE, CL_BASE,
        CL_BASE, CL_BASE, CL_BASE, CL_BASE, CL_NUM,
        CL_BASE, CL_BASE, CL_BASE, CL_BASE, CL_MOD,
        CL_BASE, CL_BASE, CL_BASE, CL_BASE,
        CL_BASE, CL_BASE, CL_BASE,
        CL_BASE, CL_BASE, CL_BASE, CL_BASE,

        CL_BASE, CL_OFF, CL_OFF, CL_OFF, CL_OFF,
        CL_BASE, CL_BASE, CL_BASE, CL_BASE, CL_BASE,
        CL_BASE, CL_BASE, CL_BASE, CL_BASE, CL_MOD,
        CL_BASE, CL_BASE, CL_BASE, CL_BASE, CL_FN,
        CL_BASE, CL_BASE, CL_BASE, CL_BASE, CL_MOD,
        CL_BASE, CL_BASE, CL_BASE, CL_BASE,
        CL_BASE, CL_BASE, CL_BASE,
        CL_BASE, CL_BASE, CL_BASE, CL_BASE
    },

    [_LMOD] = {
        CL_MOD, CL_OFF, CL_BASE, CL_LEFT, CL_OFF,
        CL_OFF, CL_NUM, CL_BASE, CL_OFF, CL_MOD,
        CL_OFF, CL_NUM, CL_MOD, CL_NUM, CL_OFF,
        CL_OFF, CL_NUM, CL_MOD, CL_NUM, CL_OFF,
        CL_OFF, CL_NUM, CL_MOD, CL_NUM, CL_CLEAR,
        CL_OFF, CL_NUM, CL_BASE, CL_OFF,
        CL_MOD, CL_OFF, CL_OFF,
        CL_OFF, CL_OFF, CL_BASE, CL_OFF,

        CL_BASE, CL_OFF, CL_OFF, CL_OFF, CL_OFF,
        CL_OFF, CL_BASE, CL_BASE, CL_BASE, CL_BASE,
        CL_OFF, CL_BASE, CL_BASE, CL_BASE, CL_MOD,
        CL_OFF, CL_BASE, CL_BASE, CL_BASE, CL_FN,
        CL_OFF, CL_BASE, CL_BASE, CL_BASE, CL_MOD,
        CL_OFF, CL_BASE, CL_BASE, CL_BASE,
        CL_BASE, CL_OFF, CL_OFF,
        CL_BASE, CL_BASE, CL_BASE, CL_BASE
    },

    [_RMOD] = {
        CL_BASE, CL_BASE, CL_BASE, CL_LEFT, CL_OFF,
        CL_OFF, CL_BASE, CL_BASE, CL_BASE, CL_BASE,
        CL_OFF, CL_BASE, CL_BASE, CL_BASE, CL_OFF,
        CL_OFF, CL_BASE, CL_BASE, CL_BASE, CL_OFF,
        CL_OFF, CL_BASE, CL_BASE, CL_BASE, CL_BASE,
        CL_OFF, CL_BASE, CL_BASE, CL_BASE,
        CL_BASE, CL_OFF, CL_OFF,
        CL_BASE, CL_TAP_HOLD, CL_BASE, CL_BASE,

        CL_MOD, CL_OFF, CL_OFF, CL_OFF, CL_OFF,
        CL_OFF, CL_NUM, CL_BASE, CL_NUM, CL_MOD,
        CL_OFF, CL_NUM, CL_MOD, CL_NUM, CL_MOD,
        CL_OFF, CL_NUM, CL_MOD, CL_NUM, CL_FN,
        CL_OFF, CL_NUM, CL_MOD, CL_NUM, CL_CLEAR,
        CL_OFF, CL_NUM, CL_NUM, CL_BASE,
        CL_MOD, CL_OFF, CL_OFF,
        CL_OFF, CL_OFF, CL_MOD, CL_OFF
    },

    [_NUM] = {
        CL_NUM, CL_OFF, CL_OFF, CL_OFF, CL_BASE,
        CL_OFF, CL_NUM, CL_NUM, CL_NUM, CL_NUM,
        CL_OFF, CL_NUM, CL_TAP_HOLD, CL_NUM, CL_FN,
        CL_OFF, CL_NUM, CL_TAP_HOLD, CL_NUM, CL_BASE,
        CL_OFF, CL_NUM, CL_TAP_HOLD, CL_NUM, CL_MOD,
        CL_OFF, CL_NUM, CL_NUM, CL_NUM,
        CL_NUM, CL_OFF, CL_OFF,
        CL_NUMPAD, CL_NUM, CL_NUM, CL_OFF,

        CL_NUM, CL_OFF, CL_OFF, CL_OFF, CL_BASE,
        CL_OFF, CL_NUM, CL_NUM, CL_NUM, CL_NUM,
        CL_OFF, CL_NUM, CL_NUM, CL_NUM, CL_NUM,
        CL_OFF, CL_NUM, CL_NUM, CL_NUM, CL_TAP_HOLD,
        CL_OFF, CL_NUM, CL_NUM, CL_NUM, CL_NUM,
        CL_OFF, CL_NUM, CL_NUM, CL_NUM,
        CL_NUM, CL_OFF, CL_OFF,
        CL_NUM, CL_NUM, CL_NUM, CL_NUM
    },

    [_NUMPAD] = {
        CL_NUMPAD, CL_OFF, CL_OFF, CL_OFF, CL_BASE,
        CL_OFF, CL_NUMPAD, CL_NUMPAD, CL_NUMPAD, CL_NUMPAD,
        CL_OFF, CL_NUMPAD, CL_TAP_HOLD, CL_NUMPAD, CL_FN,
        CL_OFF, CL_NUMPAD, CL_TAP_HOLD, CL_NUMPAD, CL_BASE,
        CL_OFF, CL_NUMPAD, CL_TAP_HOLD, CL_NUMPAD, CL_MOD,
        CL_OFF, CL_NUMPAD, CL_NUMPAD, CL_NUMPAD,
        CL_NUMPAD, CL_OFF, CL_OFF,
        CL_NUM, CL_NUMPAD, CL_NUMPAD, CL_OFF,

        CL_NUMPAD, CL_OFF, CL_OFF, CL_OFF, CL_BASE,
        CL_OFF, CL_NUMPAD, CL_NUMPAD, CL_NUMPAD, CL_NUMPAD,
        CL_OFF, CL_NUMPAD, CL_NUMPAD, CL_NUMPAD, CL_NUMPAD,
        CL_OFF, CL_NUMPAD, CL_NUMPAD, CL_NUMPAD, CL_NUMPAD,
        CL_OFF, CL_NUMPAD, CL_NUMPAD, CL_NUMPAD, CL_NUMPAD,
        CL_OFF, CL_NUMPAD, CL_NUMPAD, CL_NUMPAD,
        CL_NUMPAD, CL_OFF, CL_OFF,
        CL_NUMPAD, CL_NUMPAD, CL_NUMPAD, CL_NUMPAD
    },

    [_FN] = {
        CL_FN, CL_OFF, CL_OFF, CL_OFF, CL_BASE,
        CL_FN, CL_FN, CL_MEDIA, CL_MEDIA, CL_FN,
        CL_FN, CL_FN, CL_TAP_HOLD, CL_FN, CL_BASE,
        CL_FN, CL_FN, CL_TAP_HOLD, CL_FN, CL_NUM,
        CL_FN, CL_FN, CL_TAP_HOLD, CL_FN, CL_MOD,
        CL_FN, CL_FN, CL_FN, CL_FN,
        CL_FN, CL_FN, CL_OFF,
        CL_OFF, CL_OFF, CL_FN, CL_OFF,

        CL_FN, CL_MEDIA, CL_MEDIA, CL_FN, CL_BASE,
        CL_FN, CL_MEDIA, CL_FN, CL_FN, CL_FN,
        CL_FN, CL_MEDIA, CL_FN, CL_FN, CL_MOD,
        CL_FN, CL_MEDIA, CL_FN, CL_FN, CL_CLEAR,
        CL_FN, CL_MEDIA, CL_FN, CL_FN, CL_MOD,
        CL_FN, CL_FN, CL_FN, CL_FN,
        CL_FN, CL_FN, CL_FN,
        CL_FN, CL_FN, CL_FN, CL_FN
    },

    [_LEFT] = {
        CL_LEFT, CL_LEFT, CL_LEFT, CL_LFN, CL_MOD,
        CL_LEFT, CL_LEFT, CL_LEFT, CL_LEFT, CL_LEFT,
        CL_LEFT, CL_LEFT, CL_LEFT, CL_LEFT, CL_MOD,
        CL_LEFT, CL_LEFT, CL_LEFT, CL_LEFT, CL_MOD,
        CL_LEFT, CL_LEFT, CL_LEFT, CL_LEFT, CL_MOD,
        CL_LEFT, CL_LEFT, CL_LEFT, CL_LEFT,
        CL_LEFT, CL_LEFT, CL_LEFT,
        CL_LEFT, CL_LEFT, CL_LEFT, CL_LEFT,

        CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_BASE,
        CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF,
        CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF,
        CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF,
        CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF,
        CL_OFF, CL_OFF, CL_OFF, CL_OFF,
        CL_OFF, CL_OFF, CL_OFF,
        CL_OFF, CL_OFF, CL_OFF, CL_OFF
    },

    [_LFN] = {
        CL_LFN, CL_LFN, CL_LFN, CL_MOD, CL_CLEAR,
        CL_LFN, CL_LFN, CL_LFN, CL_LFN, CL_LFN,
        CL_LFN, CL_LFN, CL_LFN, CL_LFN, CL_MOD,
        CL_LFN, CL_LFN, CL_LFN, CL_LFN, CL_MOD,
        CL_LFN, CL_LFN, CL_LFN, CL_LFN, CL_MOD,
        CL_LFN, CL_LFN, CL_LFN, CL_LFN,
        CL_LFN, CL_LFN, CL_LFN,
        CL_LFN, CL_LFN, CL_LFN, CL_LFN,

        CL_LFN, CL_LFN, CL_LFN, CL_MOD, CL_LFN,
        CL_OFF, CL_FIRMWARE, CL_LFN, CL_LFN, CL_LFN,
        CL_OFF, {253,174,200}, {253,174,200}, {253,174,200}, CL_MOD,
        CL_OFF, {253,174,200}, {253,174,200}, {253,174,200}, CL_MOD,
        CL_OFF, {253,174,200}, {253,174,200}, {188,255,180}, CL_FIRMWARE,
        CL_OFF, {253,174,200}, {253,174,200}, {12,255,186},
        CL_LFN, CL_FIRMWARE, CL_FIRMWARE,
        CL_OFF, CL_BASE, CL_LFN, CL_LFN
    },

    [_FIRMWARE] = {
        CL_FIRMWARE, CL_FIRMWARE, CL_FIRMWARE, CL_FIRMWARE, CL_BASE,
        CL_FIRMWARE, CL_FIRMWARE, CL_FIRMWARE, CL_FIRMWARE, CL_FIRMWARE,
        CL_FIRMWARE, CL_FIRMWARE, CL_FIRMWARE, CL_FIRMWARE, CL_FIRMWARE,
        CL_FIRMWARE, CL_FIRMWARE, CL_FIRMWARE, CL_FIRMWARE, CL_FIRMWARE,
        CL_OFF, CL_OFF, CL_OFF, CL_FIRMWARE, CL_FIRMWARE,
        CL_OFF, {0,255,255}, CL_OFF, CL_FIRMWARE,
        {0,255,255}, CL_OFF, CL_OFF,
        CL_FIRMWARE, CL_FIRMWARE, CL_FIRMWARE, CL_FIRMWARE,

        CL_FIRMWARE, CL_FIRMWARE, CL_FIRMWARE, CL_FIRMWARE, CL_BASE,
        CL_FIRMWARE, CL_FIRMWARE, CL_FIRMWARE, CL_FIRMWARE, CL_FIRMWARE,
        CL_FIRMWARE, CL_FIRMWARE, CL_FIRMWARE, CL_FIRMWARE, CL_FIRMWARE,
        CL_FIRMWARE, CL_FIRMWARE, CL_FIRMWARE, CL_FIRMWARE, CL_FIRMWARE,
        CL_OFF, CL_OFF, CL_OFF, CL_FIRMWARE, CL_CLEAR,
        CL_OFF, {172,255,255}, CL_OFF, CL_FIRMWARE,
        {172,255,255}, CL_OFF, CL_OFF,
        CL_FIRMWARE, CL_FIRMWARE, CL_FIRMWARE, CL_FIRMWARE
    }
};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
    case 7:
      set_layer_color(7);
      break;
    case 8:
      set_layer_color(8);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}
