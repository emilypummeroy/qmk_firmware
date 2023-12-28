#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,

  ST_MACRO_DIAMOND,
  ST_MACRO_PARENS,
  ST_MACRO_SQUARE,
  ST_MACRO_CURLS,
  ST_MACRO_ARROW_BRACE,
  ST_MACRO_FULL_STOP,

  ST_MACRO_QU, KC_ALNUM_MACRO_FIRST = ST_MACRO_QU,
  ST_MACRO_WH,
  ST_MACRO_GH,
  ST_MACRO_SH,
  ST_MACRO_CH,
  ST_MACRO_TH,
  ST_MACRO_PH,

  AD_MACRO_LG,
  AD_MACRO_ML,
  AD_MACRO_GL,
  AD_MACRO_LK,
  AD_MACRO_SK,
  AD_MACRO_LM,
  AD_MACRO_CK,
  AD_MACRO_NK,
  AD_MACRO_KN,
  AD_MACRO_KC,
  AD_MACRO_KS,
  AD_MACRO_VS,

  // Vowel SFB adaptives
  AD_MACRO_AU,
  AD_MACRO_EO,
  AD_MACRO_IJ,
  AD_MACRO_UA,
  AD_MACRO_OE,
  AD_MACRO_YI,
  AD_MACRO_JI,

  // JB adaptives
  AD_MACRO_JO,
  AD_MACRO_OJ,
  AD_MACRO_BO,
  AD_MACRO_OB,
  AD_MACRO_BY,
  AD_MACRO_BI,
  AD_MACRO_IB, KC_ALNUM_MACRO_LAST = AD_MACRO_IB,
};

enum Layers {
  _BASE,
  _LMOD,
  _RMOD,
  _NUM,
  _FN,
  _LEFT,
  _LFN,
  _FIRMWARE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_moonlander(
    KC_NO,          KC_7,           KC_3,           KC_1,           KC_5,           KC_9,           KC_NO,                                          KC_NO,          KC_6,           KC_2,           KC_0,           KC_4,           KC_8,           KC_NO,
    KC_NO,          KC_X,           KC_W,           KC_M,           KC_G,           KC_DQUO,        KC_NO,                                          KC_NO,          KC_AT,          KC_DOT,         KC_QUOTE,       KC_J,           KC_B,           KC_NO,
    KC_TAB,         KC_S,           KC_C,           KC_N,           KC_T,           KC_K,           KC_NO,                                          KC_NO,          KC_LPRN,        KC_A,           KC_E,           KC_I,           KC_H,           KC_NO,
    KC_NO,          KC_V,           KC_F,           KC_L,           KC_D,           KC_SLASH,                                                                       KC_MINUS,       KC_U,           KC_O,           KC_Y,           KC_P,           KC_NO,
    TO(5),          KC_NO,          OSL(_NUM),      OSL(_FN),       LM(_LMOD, MOD_LSFT),            KC_ESCAPE,                                      RCTL(KC_BSPC),             LM(_RMOD, MOD_LSFT), MO(_FN),        CW_TOGG,        KC_NO,          KC_NO,
    KC_R,          LT(0, KC_COMMA), KC_NO,                          KC_NO,          KC_ENTER,       KC_SPACE
  ),
  [_LMOD] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_CIRC,        KC_AT,          KC_RPRN,        KC_DLR,         KC_ASTR,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_J,           KC_B,           KC_TRANSPARENT,
    KC_TAB,         KC_NO,          KC_LEFT_GUI,    KC_LEFT_ALT,    KC_LEFT_CTRL,   KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_A,           KC_E,           KC_I,           KC_H,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                          KC_NO,          KC_U,           KC_O,           KC_Y,           KC_P,           KC_TRANSPARENT,
    KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT,                 KC_TRANSPARENT,                                 KC_BSPC,                        OSM(MOD_RSFT),  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_NO,          KC_NO,          KC_TRANSPARENT,                 KC_TRANSPARENT, KC_ENTER,       ST_MACRO_FULL_STOP
  ),
  [_RMOD] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_AMPR,        KC_HASH,        KC_EXLM,        KC_PERC,        KC_LPRN,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_X,           KC_W,           KC_M,           KC_G,           KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,
    KC_TAB,         KC_S,           KC_C,           KC_N,           KC_T,           KC_K,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_RIGHT_CTRL,  KC_LEFT_ALT,    KC_RIGHT_GUI,   KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_V,           KC_F,           KC_L,           KC_D,           KC_NO,                                                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,
    KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          OSM(MOD_RSFT),                  KC_TRANSPARENT,                                 KC_BSPC,                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_R,           KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_NO,          KC_NO
  ),
  [_NUM] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LABK,        KC_D,           KC_E,           KC_F,           KC_RABK,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_ASTR,        KC_7,           KC_8,           KC_9,           LT(0, KC_DLR),  KC_TRANSPARENT,
    KC_TRANSPARENT, KC_X,           MT(MOD_LGUI, KC_LEFT),MT(MOD_LALT, KC_UP),MT(MOD_LCTL, KC_DOWN),KC_RIGHT,       KC_TRANSPARENT,                 KC_TRANSPARENT, KC_PLUS,        KC_4,           KC_5,           KC_6,           KC_HASH,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LPRN,        KC_A,           KC_B,           KC_C,           KC_RPRN,                                                                        KC_MINUS,       KC_1,           KC_2,           KC_3,          LT(0, KC_SLASH), KC_TRANSPARENT,
    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT_SHIFT,                  KC_TRANSPARENT,                                 KC_BSPC,                        KC_0,           LT(0, KC_DOT),  KC_EQUAL,       KC_TRANSPARENT, TO(0),
    KC_TRANSPARENT, KC_COMMA,       KC_TRANSPARENT,                 KC_TRANSPARENT, KC_KP_ENTER,    KC_TRANSPARENT
  ),
  [_FN] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_F14,         KC_F10,         KC_F11,         KC_F12,         KC_F15,         KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F16,         KC_F17,         KC_F18,         KC_F19,         KC_F20,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_F13,         KC_F9,          KC_F8,          KC_F7,          KC_F23,         KC_F24,                                         KC_INSERT,      KC_ESCAPE,      KC_MEDIA_NEXT_TRACK,KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,
    KC_TRANSPARENT, KC_BRIGHTNESS_UP,MT(MOD_LGUI, KC_F6),MT(MOD_LALT, KC_F5),MT(MOD_LCTL, KC_F4),KC_F22,         KC_TRANSPARENT,                    KC_DELETE,      KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TAB,         KC_AUDIO_VOL_DOWN,
    KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_F3,          KC_F2,          KC_F1,          KC_F21,                                                                      KC_HOME,        KC_PGDN,        KC_PAGE_UP,     KC_END,         LCTL(KC_G),     KC_WWW_SEARCH,
    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT_SHIFT,                  KC_TRANSPARENT,                                 KC_BSPC,                        KC_RIGHT_SHIFT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(0),
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [_LEFT] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT,
    KC_LEFT_SHIFT,  KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,                                           KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_MINUS,
    KC_TAB,         KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,                                           KC_EQUAL,       KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,
    KC_LEFT_ALT,    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RIGHT_CTRL,
    MO(6),          KC_TRANSPARENT, KC_LEFT_GUI,    KC_LEFT_CTRL,   KC_RIGHT_SHIFT,                 KC_ESCAPE,                                      KC_TRANSPARENT,                 KC_RIGHT_SHIFT, KC_RIGHT_ALT,   KC_RIGHT_GUI,   KC_TRANSPARENT, TO(0),
    KC_SPACE,       KC_ENTER,       KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [_LFN] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_DELETE,      KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_U,                                           QK_DYNAMIC_TAPPING_TERM_UP,RGB_MODE_FORWARD,RGB_HUD,        RGB_HUI,        RGB_TOG,        QK_DYNAMIC_TAPPING_TERM_PRINT,KC_GRAVE,
    KC_BSPC,        KC_F11,         KC_LEFT,        KC_UP,          KC_DOWN,        KC_RIGHT,       KC_L,                                           QK_DYNAMIC_TAPPING_TERM_DOWN,RGB_SLD,        RGB_VAD,        RGB_VAI,        TOGGLE_LAYER_COLOR,KC_PAUSE,       KC_PSCR,
    KC_RIGHT_ALT,   KC_F12,         KC_HOME,        KC_PAGE_UP,     KC_PGDN,        KC_END,                                                                         CM_OFF,         CM_ON,          MOON_LED_LEVEL, AU_TOGG,        KC_BSLS,        KC_RIGHT_CTRL,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_RIGHT_GUI,   KC_RIGHT_CTRL,  KC_LEFT_SHIFT,                  KC_ESCAPE,                                                                      KC_BSPC,                        MO(7),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_CAPS,
    KC_SPACE,       KC_ENTER,       KC_TRANSPARENT,                 KC_TRANSPARENT, TO(0),          KC_TRANSPARENT
  ),
  [_FIRMWARE] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, EE_CLR,         KC_TRANSPARENT,                                 KC_TRANSPARENT, QK_BOOT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT,                                 KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(0),
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};


const uint16_t PROGMEM comboWG[] = { KC_W, KC_G, COMBO_END };
const uint16_t PROGMEM comboWMG[] = { KC_W, KC_M, KC_G, COMBO_END };
const uint16_t PROGMEM combo0[] = { KC_X, KC_W, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_W, KC_M, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_M, KC_G, COMBO_END};
const uint16_t PROGMEM combo4[] = { KC_G, KC_DQUO, COMBO_END};
const uint16_t PROGMEM combo5[] = { KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM combo6[] = { KC_C, KC_N, COMBO_END};
const uint16_t PROGMEM combo7[] = { KC_N, KC_T, COMBO_END};
const uint16_t PROGMEM combo8[] = { KC_P, KC_Y, COMBO_END};
const uint16_t PROGMEM combo9[] = { KC_V, KC_F, COMBO_END};
const uint16_t PROGMEM combo10[] = { KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM combo11[] = { KC_L, KC_SLASH, COMBO_END};
const uint16_t PROGMEM combo12[] = { KC_V, KC_F, KC_L, COMBO_END};
const uint16_t PROGMEM combo13[] = { KC_V, KC_L, COMBO_END};
const uint16_t PROGMEM combo14[] = { KC_F, KC_L, KC_D, COMBO_END};
const uint16_t PROGMEM combo15[] = { KC_D, KC_SLASH, COMBO_END};
const uint16_t PROGMEM combo16[] = { KC_L, KC_D, KC_SLASH, COMBO_END};
const uint16_t PROGMEM combo17[] = { KC_AT, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo18[] = { KC_DOT, KC_QUOTE, COMBO_END};
const uint16_t PROGMEM combo19[] = { KC_QUOTE, KC_J, COMBO_END};
const uint16_t PROGMEM combo20[] = { KC_AT, KC_DOT, KC_QUOTE, COMBO_END};
const uint16_t PROGMEM combo21[] = { KC_DOT, KC_QUOTE, KC_J, COMBO_END};
const uint16_t PROGMEM combo22[] = { KC_QUOTE, KC_J, KC_B, COMBO_END};
const uint16_t PROGMEM combo23[] = { KC_LPRN, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo24[] = { KC_LPRN, KC_QUOTE, COMBO_END};
const uint16_t PROGMEM combo25[] = { KC_LPRN, KC_DOT, KC_QUOTE, COMBO_END};
const uint16_t PROGMEM combo26[] = { KC_LPRN, KC_A, COMBO_END};
const uint16_t PROGMEM combo27[] = { KC_LPRN, KC_A, KC_E, COMBO_END};
const uint16_t PROGMEM combo28[] = { KC_LPRN, KC_U, COMBO_END};
const uint16_t PROGMEM combo29[] = { KC_LPRN, KC_O, COMBO_END};
const uint16_t PROGMEM combo30[] = { KC_LPRN, KC_U, KC_O, COMBO_END};
const uint16_t PROGMEM combo31[] = { KC_LPRN, KC_E, COMBO_END};
const uint16_t PROGMEM combo32[] = { KC_LPRN, KC_I, COMBO_END};
const uint16_t PROGMEM combo33[] = { KC_LPRN, KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM combo34[] = { KC_LPRN, KC_DOT, KC_E, COMBO_END};
const uint16_t PROGMEM combo35[] = { KC_MINUS, KC_U, COMBO_END};
const uint16_t PROGMEM combo36[] = { KC_MINUS, KC_O, COMBO_END};
const uint16_t PROGMEM combo37[] = { KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM combo38[] = { KC_MINUS, KC_U, KC_O, COMBO_END};
const uint16_t PROGMEM combo39[] = { KC_MINUS, KC_A, KC_E, COMBO_END};
const uint16_t PROGMEM combo40[] = { KC_MINUS, KC_E, KC_Y, COMBO_END};
const uint16_t PROGMEM combo41[] = { KC_U, KC_O, KC_Y, COMBO_END};
const uint16_t PROGMEM combo42[] = { KC_S, KC_C, KC_N, COMBO_END};
const uint16_t PROGMEM combo43[] = { KC_C, KC_N, KC_T, COMBO_END};
const uint16_t PROGMEM combo44[] = { KC_N, KC_T, KC_K, COMBO_END};


enum combo_index {
  AD_MG_LG, ADAPTIVE_FIRST = AD_MG_LG,
  AD_MT_ML,
  AD_GM_GL,
  AD_GK_LK,
  AD_CK_SK,
  AD_CM_LM,
  AD_NK_CK,
  AD_TK_NK,
  AD_KT_KN,
  AD_KN_KC,
  AD_KC_KS,
  AD_VC_VS,

  // Vowel SFB adaptives
  AD_AH_AU,
  AD_EH_EO,
  AD_IH_IJ,
  AD_UH_UA,
  AU_OH_OE,
  AD_YH_YI,
  AD_JH_JI,

  // JB adaptives
  AD_Jd_JO,
  AD_dJ_OJ,
  AD_Bd_BO,
  AD_dB_OB,
  AD_Bq_BY,
  AD_BJ_BI,
  AD_JB_IB, ADAPTIVE_LAST = AD_JB_IB,

  ST_COMBO_WG_QU,
  ST_COMBO_WMG_Q,
};

const uint16_t PROGMEM adaptiveMG[] = { KC_M, KC_G, COMBO_END };
const uint16_t PROGMEM adaptiveMT[] = { KC_M, KC_T, COMBO_END };
const uint16_t PROGMEM adaptiveGM[] = { KC_G, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveGK[] = { KC_G, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveCK[] = { KC_C, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveCM[] = { KC_C, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveNK[] = { KC_N, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveTK[] = { KC_T, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveKT[] = { KC_K, KC_T, COMBO_END };
const uint16_t PROGMEM adaptiveKN[] = { KC_K, KC_N, COMBO_END };
const uint16_t PROGMEM adaptiveKC[] = { KC_K, KC_C, COMBO_END };
const uint16_t PROGMEM adaptiveVC[] = { KC_V, KC_C, COMBO_END };

// Vowel SFB adaptives
const uint16_t PROGMEM adaptiveAH[] = { KC_A, KC_H, COMBO_END };
const uint16_t PROGMEM adaptiveEH[] = { KC_E, KC_H, COMBO_END };
const uint16_t PROGMEM adaptiveIH[] = { KC_I, KC_H, COMBO_END };
const uint16_t PROGMEM adaptiveUH[] = { KC_U, KC_H, COMBO_END };
const uint16_t PROGMEM adaptiveOH[] = { KC_O, KC_H, COMBO_END };
const uint16_t PROGMEM adaptiveYH[] = { KC_Y, KC_H, COMBO_END };
const uint16_t PROGMEM adaptiveJH[] = { KC_J, KC_H, COMBO_END };

// JB adaptives
const uint16_t PROGMEM adaptiveJd[] = { KC_J, KC_DOT, COMBO_END };
const uint16_t PROGMEM adaptivedJ[] = { KC_DOT, KC_J, COMBO_END };
const uint16_t PROGMEM adaptiveBd[] = { KC_B, KC_DOT, COMBO_END };
const uint16_t PROGMEM adaptivedB[] = { KC_DOT, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveBq[] = { KC_B, KC_QUOTE, COMBO_END };
const uint16_t PROGMEM adaptiveBJ[] = { KC_B, KC_J, COMBO_END };
const uint16_t PROGMEM adaptiveJB[] = { KC_J, KC_B, COMBO_END };

combo_t key_combos[] = {
  [AD_MG_LG] = COMBO(adaptiveMG, AD_MACRO_LG),
  [AD_MT_ML] = COMBO(adaptiveMT, AD_MACRO_ML),
  [AD_GM_GL] = COMBO(adaptiveGM, AD_MACRO_GL),
  [AD_GK_LK] = COMBO(adaptiveGK, AD_MACRO_LK),
  [AD_CK_SK] = COMBO(adaptiveCK, AD_MACRO_SK),
  [AD_CM_LM] = COMBO(adaptiveCM, AD_MACRO_LM),
  [AD_NK_CK] = COMBO(adaptiveNK, AD_MACRO_CK),
  [AD_TK_NK] = COMBO(adaptiveTK, AD_MACRO_NK),
  [AD_KT_KN] = COMBO(adaptiveKT, AD_MACRO_KN),
  [AD_KN_KC] = COMBO(adaptiveKN, AD_MACRO_KC),
  [AD_KC_KS] = COMBO(adaptiveKC, AD_MACRO_KS),
  [AD_VC_VS] = COMBO(adaptiveVC, AD_MACRO_VS),

  // Vowel SFB adaptives
  [AD_AH_AU] = COMBO(adaptiveAH, AD_MACRO_AU),
  [AD_EH_EO] = COMBO(adaptiveEH, AD_MACRO_EO),
  [AD_IH_IJ] = COMBO(adaptiveIH, AD_MACRO_IJ),
  [AD_UH_UA] = COMBO(adaptiveUH, AD_MACRO_UA),
  [AU_OH_OE] = COMBO(adaptiveOH, AD_MACRO_OE),
  [AD_YH_YI] = COMBO(adaptiveYH, AD_MACRO_YI),
  [AD_JH_JI] = COMBO(adaptiveJH, AD_MACRO_JI),

  // JB adaptives
  [AD_Jd_JO] = COMBO(adaptiveJd, AD_MACRO_JO),
  [AD_dJ_OJ] = COMBO(adaptivedJ, AD_MACRO_OJ),
  [AD_Bd_BO] = COMBO(adaptiveBd, AD_MACRO_BO),
  [AD_dB_OB] = COMBO(adaptivedB, AD_MACRO_OB),
  [AD_Bq_BY] = COMBO(adaptiveBq, AD_MACRO_BY),
  [AD_BJ_BI] = COMBO(adaptiveBJ, AD_MACRO_BI),
  [AD_JB_IB] = COMBO(adaptiveJB, AD_MACRO_IB),

  [ST_COMBO_WG_QU] = COMBO(comboWG, ST_MACRO_QU),
  [ST_COMBO_WMG_Q] = COMBO(comboWMG, KC_Q),

  COMBO(combo0, KC_Z),
  COMBO(combo1, ST_MACRO_WH),
  COMBO(combo2, ST_MACRO_GH),
  COMBO(combo4, KC_EXLM),
  COMBO(combo5, ST_MACRO_SH),
  COMBO(combo6, ST_MACRO_CH),
  COMBO(combo7, ST_MACRO_TH),
  COMBO(combo8, ST_MACRO_PH),
  COMBO(combo9, LCTL(KC_Z)),
  COMBO(combo10, LCTL(KC_C)),
  COMBO(combo11, LCTL(KC_V)),
  COMBO(combo12, LCTL(KC_X)),
  COMBO(combo13, LCTL(KC_A)),
  COMBO(combo14, LCTL(KC_V)),
  COMBO(combo15, KC_ASTR),
  COMBO(combo16, KC_BSLS),
  COMBO(combo17, KC_HASH),
  COMBO(combo18, KC_COLN),
  COMBO(combo19, KC_QUES),
  COMBO(combo20, KC_AMPR),
  COMBO(combo21, KC_PIPE),
  COMBO(combo22, KC_PERC),
  COMBO(combo23, KC_LABK),
  COMBO(combo24, KC_RABK),
  COMBO(combo25, ST_MACRO_DIAMOND),
  COMBO(combo26, KC_RPRN),
  COMBO(combo27, ST_MACRO_PARENS),
  COMBO(combo28, KC_LBRC),
  COMBO(combo29, KC_RBRC),
  COMBO(combo30, ST_MACRO_SQUARE),
  COMBO(combo31, KC_LCBR),
  COMBO(combo32, KC_RCBR),
  COMBO(combo33, ST_MACRO_CURLS),
  COMBO(combo34, ST_MACRO_ARROW_BRACE),
  COMBO(combo35, KC_PLUS),
  COMBO(combo36, KC_EQUAL),
  COMBO(combo37, KC_UNDS),
  COMBO(combo38, KC_TILD),
  COMBO(combo39, KC_CIRC),
  COMBO(combo40, KC_DLR),
  COMBO(combo41, KC_GRAVE),
  COMBO(combo42, KC_ESCAPE),
  COMBO(combo43, KC_TAB),
  COMBO(combo44, KC_BSPC),
};

inline bool is_adaptive(uint16_t index) {
  switch (index) {
  case ADAPTIVE_FIRST ... ADAPTIVE_LAST: return true;
  default: return false;
  }
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
  return is_adaptive(index) ? ADAPTIVE_TERM : COMBO_TERM;
}

bool get_combo_must_press_in_order(uint16_t index, combo_t *combo) {
  return is_adaptive(index);

}

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
  return is_adaptive(index);
}

bool get_combo_must_hold(uint16_t index, combo_t *combo) {
  return false;
}

bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
  // Keycodes that continue Caps Word, with shift applied.
  case KC_A ... KC_Z:
  case KC_MINS:
    add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
    return true;

  // Keycodes that continue Caps Word, without shifting.
  case KC_1 ... KC_0:
  case KC_BSPC:
  case KC_DEL:
  case KC_UNDS:
  case KC_ALNUM_MACRO_FIRST ... KC_ALNUM_MACRO_LAST:
    return true;

  default:
    return false;  // Deactivate Caps Word.
  }
}

#define SEND_STRINGS(BASE, SHIFTED, CAPS) \
  if (is_caps_word_on()) SEND_STRING(CAPS); \
  else if ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) SEND_STRING(SHIFTED); \
  else SEND_STRING(BASE);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case ST_MACRO_QU:
    if (record->event.pressed) {
      SEND_STRINGS("qu", "Qu", "QU");
    }
    return true;
  case AD_MACRO_LG:
    if (record->event.pressed) {
      SEND_STRINGS("lg", "Lg", "LG");
    }
    return true;
  case AD_MACRO_ML:
    if (record->event.pressed) {
      SEND_STRINGS("ml", "Ml", "ML");
    }
    return true;
  case AD_MACRO_GL:
    if (record->event.pressed) {
      SEND_STRINGS("gl", "Gl", "GL");
    }
    return true;
  case AD_MACRO_LK:
    if (record->event.pressed) {
      SEND_STRINGS("lk", "Lk", "LK");
    }
    return true;
  case AD_MACRO_SK:
    if (record->event.pressed) {
      SEND_STRINGS("sk", "Sk", "SK");
    }
    return true;
  case AD_MACRO_LM:
    if (record->event.pressed) {
      SEND_STRINGS("lm", "Lm", "LM");
    }
    return true;
  case AD_MACRO_CK:
    if (record->event.pressed) {
      SEND_STRINGS("ck", "Ck", "CK");
    }
    return true;
  case AD_MACRO_NK:
    if (record->event.pressed) {
      SEND_STRINGS("nk", "Nk", "NK");
    }
    return true;
  case AD_MACRO_KN:
    if (record->event.pressed) {
      SEND_STRINGS("kn", "Kn", "KN");
    }
    return true;
  case AD_MACRO_KC:
    if (record->event.pressed) {
      SEND_STRINGS("kc", "Kc", "KC");
    }
    return true;
  case AD_MACRO_KS:
    if (record->event.pressed) {
      SEND_STRINGS("ks", "Ks", "KS");
    }
    return true;
  case AD_MACRO_VS:
    if (record->event.pressed) {
      SEND_STRINGS("vs", "Vs", "VS");
    }
    return true;

  // Vowel SFB adaptives
  case AD_MACRO_AU:
    if (record->event.pressed) {
      SEND_STRINGS("au", "Au", "AU");
    }
    return true;
  case AD_MACRO_EO:
    if (record->event.pressed) {
      SEND_STRINGS("eo", "Eo", "EO");
    }
    return true;
  case AD_MACRO_IJ:
    if (record->event.pressed) {
      SEND_STRINGS("ij", "Ij", "IJ");
    }
    return true;
  case AD_MACRO_UA:
    if (record->event.pressed) {
      SEND_STRINGS("ua", "Ua", "UA");
    }
    return true;
  case AD_MACRO_OE:
    if (record->event.pressed) {
      SEND_STRINGS("oe", "Oe", "OE");
    }
    return true;
  case AD_MACRO_YI:
    if (record->event.pressed) {
      SEND_STRINGS("yi", "Yi", "YI");
    }
    return true;
  case AD_MACRO_JI:
    if (record->event.pressed) {
      SEND_STRINGS("ji", "Ji", "JI");
    }
    return true;

  // JB adaptives
  case AD_MACRO_JO:
    if (record->event.pressed) {
      SEND_STRINGS("jo", "Jo", "JO");
    }
    return true;
  case AD_MACRO_OJ:
    if (record->event.pressed) {
      SEND_STRINGS("oj", "oJ", "OJ");
    }
    return true;
  case AD_MACRO_BO:
    if (record->event.pressed) {
      SEND_STRINGS("bo", "Bo", "BO");
    }
    return true;
  case AD_MACRO_OB:
    if (record->event.pressed) {
      SEND_STRINGS("ob", "oB", "OB");
    }
    return true;
  case AD_MACRO_BY:
    if (record->event.pressed) {
      SEND_STRINGS("by", "By", "BY");
    }
    return true;
  case AD_MACRO_BI:
    if (record->event.pressed) {
      SEND_STRINGS("bi", "Bi", "BI");
    }
    return true;
  case AD_MACRO_IB:
    if (record->event.pressed) {
      SEND_STRINGS("ib", "Ib", "IB");
    }
    return true;

  // H digraphs
  case ST_MACRO_WH:
    if (record->event.pressed) {
      SEND_STRINGS("wh", "Wh", "WH");
    }
    return true;
  case ST_MACRO_GH:
    if (record->event.pressed) {
      SEND_STRINGS("gh", "Gh", "GH");
    }
    return true;
  case ST_MACRO_SH:
    if (record->event.pressed) {
      SEND_STRINGS("sh", "Sh", "SH");
    }
    return true;
  case ST_MACRO_CH:
    if (record->event.pressed) {
      SEND_STRINGS("ch", "Ch", "CH");
    }
    return true;
  case ST_MACRO_TH:
    if (record->event.pressed) {
      SEND_STRINGS("th", "Th", "TH");
    }
    return true;
  case ST_MACRO_PH:
    if (record->event.pressed) {
      SEND_STRINGS("ph", "Ph", "PH");
    }
    return true;

  // Symbol macros
  case ST_MACRO_DIAMOND:
    if (record->event.pressed) {
      SEND_STRING("<>");
    }
    return true;
  case ST_MACRO_PARENS:
    if (record->event.pressed) {
      SEND_STRING("()");
    }
    return true;
  case ST_MACRO_SQUARE:
    if (record->event.pressed) {
      SEND_STRING("[]");
    }
    return true;
  case ST_MACRO_CURLS:
    if (record->event.pressed) {
      SEND_STRING("{}");
    }
    return true;
  case ST_MACRO_ARROW_BRACE:
    if (record->event.pressed) {
      SEND_STRING("=> {");
    }
    return true;
  case ST_MACRO_FULL_STOP:
    if (record->event.pressed) {
      SEND_STRING(". ");
    }
    return true;

  case LT(0, KC_COMMA):
    if (!record->tap.count && record->event.pressed) {
      tap_code16(KC_SCLN);
      return false;
    }
    return true;
  case LT(0, KC_DOT):
    if (!record->tap.count && record->event.pressed) {
      tap_code16(KC_COLN);
      return false;
    }
    return true;
  case LT(0, KC_DLR):
    if (!record->tap.count && record->event.pressed) {
      tap_code16(KC_CIRC);
      return false;
    }
    return true;
  case LT(0, KC_SLASH):
    if (!record->tap.count && record->event.pressed) {
      tap_code16(KC_PERC);
      return false;
    }
    return true;
  case RGB_SLD:
    if (rawhid_state.rgb_control) {
      return false;
    }
    if (record->event.pressed) {
      rgblight_mode(1);
    }
    return false;

  default:
    return true;
  }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case LT(0, KC_COMMA):
    return g_tapping_term + 75;
  case MT(MOD_LGUI, KC_LEFT):
    return g_tapping_term + 25;
  case MT(MOD_LALT, KC_UP):
    return g_tapping_term + 25;
  case MT(MOD_LCTL, KC_DOWN):
    return g_tapping_term + 25;
  case LT(0, KC_DLR):
    return g_tapping_term + 25;
  case LT(0, KC_DOT):
    return g_tapping_term + 25;
  default:
    return g_tapping_term;
  }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [_BASE] = { {93,255,191}, {0,0,0}, {0,0,0}, {0,0,0}, {101,206,157}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {36,255,193}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {203,196,165}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {86,255,204}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {0,0,0}, {0,0,0}, {93,255,191}, {128,242,161}, {93,255,191}, {93,255,191}, {93,255,191}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {86,255,204}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {203,196,165}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {86,255,204}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {0,0,0}, {0,0,0}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191} },

    [_LMOD] = { {86,255,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,204}, {0,0,0}, {0,0,0}, {86,255,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,204}, {0,0,0}, {67,180,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {93,255,191}, {0,0,0}, {93,255,191}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {0,0,0}, {93,255,191}, {93,255,191}, {93,255,191}, {0,0,0}, {0,0,0}, {0,0,0}, {93,255,191}, {93,255,191}, {0,0,0}, {0,0,0}, {0,0,0}, {93,255,191}, {93,255,191}, {86,255,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {93,255,191}, {0,0,0}, {0,0,0}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191} },

    [_RMOD] = { {93,255,191}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {0,0,0}, {93,255,191}, {93,255,191}, {93,255,191}, {0,0,0}, {0,0,0}, {93,255,191}, {93,255,191}, {93,255,191}, {0,0,0}, {0,0,0}, {93,255,191}, {93,255,191}, {93,255,191}, {86,255,204}, {0,0,0}, {0,0,0}, {93,255,191}, {0,0,0}, {93,255,191}, {0,0,0}, {0,0,0}, {93,255,191}, {128,242,161}, {93,255,191}, {93,255,191}, {86,255,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,204}, {0,0,0}, {0,0,0}, {86,255,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,204}, {0,0,0}, {67,180,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,204}, {0,0,0} },

    [_NUM] = { {36,255,193}, {0,0,0}, {0,0,0}, {0,0,0}, {93,255,191}, {0,0,0}, {36,255,193}, {36,255,193}, {36,255,193}, {36,255,193}, {0,0,0}, {36,255,193}, {128,242,161}, {36,255,193}, {67,180,255}, {0,0,0}, {36,255,193}, {128,242,161}, {36,255,193}, {203,196,165}, {0,0,0}, {36,255,193}, {128,242,161}, {36,255,193}, {86,255,204}, {0,0,0}, {36,255,193}, {36,255,193}, {36,255,193}, {36,255,193}, {0,0,0}, {0,0,0}, {0,0,0}, {36,255,193}, {36,255,193}, {0,0,0}, {36,255,193}, {0,0,0}, {0,0,0}, {0,0,0}, {93,255,191}, {0,0,0}, {128,242,161}, {36,255,193}, {128,242,161}, {36,255,193}, {0,0,0}, {36,255,193}, {36,255,193}, {36,255,193}, {36,255,193}, {0,0,0}, {36,255,193}, {36,255,193}, {36,255,193}, {128,242,161}, {0,0,0}, {36,255,193}, {36,255,193}, {36,255,193}, {36,255,193}, {0,0,0}, {36,255,193}, {36,255,193}, {36,255,193}, {36,255,193}, {0,0,0}, {0,0,0}, {36,255,193}, {36,255,193}, {36,255,193}, {36,255,193} },

    [_FN] = { {203,196,165}, {0,0,0}, {0,0,0}, {0,0,0}, {93,255,191}, {203,196,165}, {203,196,165}, {102,255,143}, {102,255,143}, {203,196,165}, {203,196,165}, {203,196,165}, {128,242,161}, {203,196,165}, {86,255,204}, {203,196,165}, {203,196,165}, {128,242,161}, {203,196,165}, {67,180,255}, {203,196,165}, {203,196,165}, {128,242,161}, {203,196,165}, {86,255,204}, {203,196,165}, {203,196,165}, {203,196,165}, {203,196,165}, {203,196,165}, {203,196,165}, {0,0,0}, {0,0,0}, {0,0,0}, {203,196,165}, {0,0,0}, {203,196,165}, {102,255,143}, {102,255,143}, {203,196,165}, {93,255,191}, {203,196,165}, {102,255,143}, {203,196,165}, {203,196,165}, {203,196,165}, {203,196,165}, {102,255,143}, {203,196,165}, {203,196,165}, {86,255,204}, {203,196,165}, {102,255,143}, {203,196,165}, {203,196,165}, {67,180,255}, {203,196,165}, {102,255,143}, {203,196,165}, {203,196,165}, {86,255,204}, {203,196,165}, {203,196,165}, {203,196,165}, {203,196,165}, {203,196,165}, {203,196,165}, {203,196,165}, {203,196,165}, {203,196,165}, {203,196,165}, {203,196,165} },

    [_LEFT] = { {101,206,157}, {86,255,204}, {101,206,157}, {86,255,204}, {237,234,175}, {101,206,157}, {101,206,157}, {101,206,157}, {101,206,157}, {101,206,157}, {101,206,157}, {101,206,157}, {101,206,157}, {101,206,157}, {86,255,204}, {101,206,157}, {101,206,157}, {101,206,157}, {101,206,157}, {86,255,204}, {101,206,157}, {101,206,157}, {101,206,157}, {101,206,157}, {86,255,204}, {101,206,157}, {101,206,157}, {101,206,157}, {101,206,157}, {101,206,157}, {101,206,157}, {101,206,157}, {101,206,157}, {101,206,157}, {101,206,157}, {101,206,157}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {93,255,191}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [_LFN] = { {237,234,175}, {237,234,175}, {237,234,175}, {86,255,204}, {67,180,255}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {86,255,204}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {86,255,204}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {86,255,204}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {86,255,204}, {237,234,175}, {0,0,0}, {8,235,250}, {237,234,175}, {237,234,175}, {237,234,175}, {0,0,0}, {253,174,200}, {253,174,200}, {253,174,200}, {86,255,204}, {0,0,0}, {253,174,200}, {253,174,200}, {253,174,200}, {86,255,204}, {0,0,0}, {253,174,200}, {253,174,200}, {188,255,180}, {8,235,250}, {0,0,0}, {253,174,200}, {253,174,200}, {12,255,186}, {237,234,175}, {8,235,250}, {8,235,250}, {0,0,0}, {93,255,191}, {237,234,175}, {237,234,175} },

    [_FIRMWARE] = { {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {93,255,191}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {0,0,0}, {0,0,0}, {0,0,0}, {8,235,250}, {8,235,250}, {0,0,0}, {0,255,255}, {0,0,0}, {8,235,250}, {0,255,255}, {0,0,0}, {0,0,0}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {93,255,191}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {0,0,0}, {0,0,0}, {0,0,0}, {8,235,250}, {67,180,255}, {0,0,0}, {172,255,255}, {0,0,0}, {8,235,250}, {172,255,255}, {0,0,0}, {0,0,0}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250} },

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
  if (rawhid_state.rgb_control) {
      return false;
  }
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
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}