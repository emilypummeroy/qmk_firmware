#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,

  ST_MACRO_CODE_BLOCK,
  ST_MACRO_FORCE_EQUAL,

  ST_MACRO_ZZ, KC_ALNUM_MACRO_FIRST = ST_MACRO_ZZ,
  ST_MACRO_QU,
  ST_MACRO_WH,
  ST_MACRO_GH,
  ST_MACRO_SH,
  ST_MACRO_CH,
  ST_MACRO_TH,
  ST_MACRO_PH,
  ST_MACRO_SPH, // Sphere

  AD_MACRO_LG,
  AD_MACRO_ML,
  AD_MACRO_LM,
  AD_MACRO_LN,
  AD_MACRO_NL,
  AD_MACRO_MN,
  AD_MACRO_NM,
  AD_MACRO_GL,
  AD_MACRO_DG,
  AD_MACRO_GD,
  AD_MACRO_SP,
  // Maybe Mc would be convenient

  // F adaptives
  // L@T S@C W@M
  AD_MACRO_LF,
  AD_MACRO_FL,
  AD_MACRO_SF,
  AD_MACRO_FS,
  AD_MACRO_WF,
  AD_MACRO_FW,
  AD_MACRO_LFS,
  AD_MACRO_NFS,

  // K adaptives
  // S@C C@N N@T L@G P@L
  AD_MACRO_LK,
  AD_MACRO_KL,
  AD_MACRO_CK,
  AD_MACRO_KC,
  AD_MACRO_SK,
  AD_MACRO_KS,
  AD_MACRO_NK,
  AD_MACRO_KN,
  AD_MACRO_PK,
  AD_MACRO_KP,
  AD_MACRO_LKS,
  AD_MACRO_CKS,
  AD_MACRO_NKS,
  AD_MACRO_CKL, // cackle
  // nothing for backpack because C and P same finger

  // B adaptives
  // L@D S@C C@N M@G P@L V@P
  AD_MACRO_MB,
  AD_MACRO_SB,
  AD_MACRO_BS,
  AD_MACRO_LB,
  AD_MACRO_BL,
  AD_MACRO_PB,
  AD_MACRO_BP,
  AD_MACRO_VB,
  AD_MACRO_BV,
  AD_MACRO_CB,
  AD_MACRO_BC, // ribcage
  AD_MACRO_LBS,
  AD_MACRO_MBS,
  AD_MACRO_BTS, // doubts

  // Vowel SFB adaptives
  AD_MACRO_AU,
  AD_MACRO_EO,
  AD_MACRO_UA,
  AD_MACRO_OE,
  AD_MACRO_YI,
  AD_MACRO_JI,

  // J adaptives
  AD_MACRO_JO,
  AD_MACRO_OJ, KC_ALNUM_MACRO_LAST = AD_MACRO_OJ,
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
    KC_NO,          KC_7,           KC_3,           KC_1,           KC_5,           KC_9,           KC_NO,                                          KC_NO,          KC_6,           KC_2,           KC_0,           KC_4,           KC_8,           KC_NO,
    KC_NO,          LT(0, KC_X),    KC_W,           KC_M,           KC_G,           KC_F,           KC_DELETE,                                      KC_INSERT,      LT(0, KC_SCLN), LT(0, KC_DOT), LT(0, KC_QUOTE), KC_J,           KC_AT,          KC_NO,
    KC_TAB,         KC_S,           KC_C,           KC_N,           KC_T,           KC_K,           KC_BACKSPACE,                                   KC_DELETE,      LT(0, KC_COMMA), KC_A,           KC_E,           KC_I,           KC_H,          KC_NO,
    KC_NO,          KC_V,           KC_P,           KC_L,           KC_D,           KC_B,                                                                          LT(0, KC_MINUS), KC_U,           KC_O,           KC_Y,          LT(0, KC_SLASH), KC_NO,
    TO(_LEFT),      KC_NO,          MO(_FN),        MO(_NUM),       LM(_LMOD, MOD_LSFT),            KC_ESCAPE,                                      RCTL(KC_BSPC),             LM(_RMOD, MOD_LSFT), MO(_FN),        CW_TOGG,        KC_NO,          KC_NO,
    KC_R,           KC_ENTER,         KC_NO,                          KC_NO,          KC_ENTER,       KC_SPACE
  ),

  [_LMOD] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_CIRC,        KC_AT,          KC_RPRN,        KC_DLR,         KC_ASTR,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                KC_TRANSPARENT, LT(0, KC_COLON), KC_RABK,        LT(0, KC_DQUO), KC_J,           KC_HASH,        KC_TRANSPARENT,
    KC_TAB,         KC_NO,          KC_LEFT_GUI,    KC_LEFT_ALT,    KC_LEFT_CTRL,   KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, LT(0, KC_LABK), KC_A,           KC_E,           KC_I,           KC_H,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,   ST_MACRO_FORCE_EQUAL,  KC_LCBR,        KC_RCBR,        KC_NO,                                                                          KC_UNDS,        KC_U,           KC_O,           KC_Y,           KC_QUES,        KC_TRANSPARENT,
    KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT,                 KC_TRANSPARENT,                                 KC_BSPC,                        OSM(MOD_RSFT),  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_NO,          KC_NO,          KC_TRANSPARENT,                 KC_TRANSPARENT, KC_ENTER,       KC_TRANSPARENT
  ),

  [_RMOD] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_AMPR,        KC_HASH,        KC_EXLM,        KC_PERC,        KC_LPRN,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, LT(0, KC_X),    KC_W,           KC_M,           KC_G,           KC_F,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_AMPR,        KC_RPRN,        LT(0, KC_DQUO), KC_NO,          KC_HASH,        KC_TRANSPARENT,
    KC_TAB,         KC_S,           KC_C,           KC_N,           KC_T,           KC_K,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_LPRN,        KC_RIGHT_CTRL,  KC_LEFT_ALT,    KC_RIGHT_GUI,   KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_V,           KC_P,           KC_L,           KC_D,           KC_B,                                                                           KC_PIPE,        KC_NO,          KC_NO,          KC_NO,          KC_PERC,        KC_TRANSPARENT,
    KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_SPACE,                       KC_TRANSPARENT,                                 KC_BSPC,                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_R,           KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_NO,          KC_NO
  ),

  [_NUM] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LABK,        KC_D,           KC_E,           KC_F,           KC_RABK,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_ASTR,        KC_7,           KC_8,           KC_9,           KC_DLR,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_COMMA, MT(MOD_LGUI,KC_LEFT), MT(MOD_LALT,KC_UP), MT(MOD_LCTL, KC_DOWN), KC_RIGHT, KC_TRANSPARENT,                            KC_TRANSPARENT, KC_PLUS,        KC_4,           KC_5,           KC_6,           KC_HASH,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LPRN,        KC_EQUAL,       KC_LBRC,        KC_RBRC,        KC_RPRN,                                                                        KC_MINUS,       KC_1,           KC_2,           KC_3,          LT(0, KC_SLASH), KC_TRANSPARENT,
    TO(0),          KC_TRANSPARENT, TO(_FN),        TO(0),          KC_LEFT_SHIFT,                  KC_TRANSPARENT,                                 KC_BSPC,                        KC_0,           LT(0, KC_DOT),  KC_EQUAL,       KC_TRANSPARENT, TO(0),
    TO(_NUMPAD),    KC_TRANSPARENT,           KC_TRANSPARENT,                 KC_TRANSPARENT, KC_ENTER,       KC_TRANSPARENT
  ),

  [_NUMPAD] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LABK,        KC_D,           KC_E,           KC_F,           KC_RABK,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_KP_ASTERISK, KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_NUM,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_X,           MT(MOD_LGUI, KC_LEFT),MT(MOD_LALT, KC_UP),MT(MOD_LCTL, KC_DOWN),KC_RIGHT,       KC_TRANSPARENT,                 KC_TRANSPARENT, KC_KP_PLUS,     KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_HASH,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LPRN,        KC_A,           KC_B,           KC_C,           KC_RPRN,                                                                        KC_KP_MINUS,    KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_SLASH,    KC_TRANSPARENT,
    TO(0),          KC_TRANSPARENT, TO(_FN),        TO(0),          KC_LEFT_SHIFT,                  KC_TRANSPARENT,                                 KC_BSPC,                        KC_KP_0,        KC_KP_DOT,      KC_KP_EQUAL,    KC_TRANSPARENT, TO(0),
    TO(_NUM),       KC_KP_COMMA,    KC_TRANSPARENT,                 KC_TRANSPARENT, KC_KP_ENTER,    KC_TRANSPARENT
  ),

  [_FN] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_F14,         KC_F12,         KC_F11,         KC_F10,         KC_F15,         KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F16,         KC_F17,         KC_F18,         KC_F19,         KC_F20,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_F13,         KC_F9,          KC_F8,          KC_F7,          KC_F23,         KC_F24,                                         KC_INSERT,      KC_ESCAPE,      KC_MEDIA_NEXT_TRACK,KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,
    KC_TRANSPARENT, KC_BRIGHTNESS_UP,MT(MOD_LGUI, KC_F6),MT(MOD_LALT, KC_F5),MT(MOD_LCTL, KC_F4),KC_F22, KC_TRANSPARENT,                            KC_DELETE,      KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TAB,         KC_AUDIO_VOL_DOWN,
    KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_F3,       KC_F2,          KC_F1,          KC_F21,                                                                         KC_HOME,        KC_PGDN,        KC_PAGE_UP,     KC_END,         LCTL(KC_G),     KC_WWW_SEARCH,
    TO(0),          KC_TRANSPARENT, TO(0),          TO(_NUM),       KC_LEFT_SHIFT,                  KC_TRANSPARENT,                                 KC_BSPC,                        KC_RIGHT_SHIFT, TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, TO(0),
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_LEFT] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT,
    KC_GRAVE,       KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_LBRC,                                        KC_RBRC,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_MINUS,
    KC_TAB,         KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,                                           KC_EQUAL,       KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,
    MO(_LFN),       KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RIGHT_CTRL,
    KC_LEFT_ALT,    KC_TRANSPARENT, KC_LEFT_GUI,    KC_LEFT_CTRL,   KC_LEFT_SHIFT,                  KC_ESCAPE,                                      KC_BSPC,                        KC_RIGHT_SHIFT, KC_RIGHT_ALT,   KC_RIGHT_GUI,   KC_TRANSPARENT, TO(0),
    KC_SPACE,       KC_ENTER,       KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_LFN] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_DELETE,      KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_U,                                           QK_DYNAMIC_TAPPING_TERM_UP,RGB_MODE_FORWARD,RGB_HUD,        RGB_HUI,        RGB_TOG,        QK_DYNAMIC_TAPPING_TERM_PRINT,KC_SCRL,
    KC_BSPC,        KC_F11,         KC_LEFT,        KC_UP,          KC_DOWN,        KC_RIGHT,       KC_L,                                           QK_DYNAMIC_TAPPING_TERM_DOWN,RGB_SLD,        RGB_VAD,        RGB_VAI,        TOGGLE_LAYER_COLOR,KC_PAUSE,       KC_PSCR,
    KC_RIGHT_ALT,   KC_F12,         KC_HOME,        KC_PAGE_UP,     KC_PGDN,        KC_END,                                                                         CM_OFF,         CM_ON,          MOON_LED_LEVEL, AU_TOGG,        KC_BSLS,        KC_RIGHT_CTRL,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_RIGHT_GUI,   KC_RIGHT_CTRL,  KC_LEFT_SHIFT,                  KC_ESCAPE,                                      KC_BSPC,                        MO(_FIRMWARE),  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_CAPS,
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

enum combo_index {
  AD_MG_LG, ADAPTIVE_FIRST = AD_MG_LG,
  AD_MC_ML,
  AD_CM_LM,
  AD_PN_LN,
  AD_NP_NL,
  AD_MT_MN,
  AD_TM_NM,
  AD_GM_GL,
  AD_DM_DG,
  AD_MD_GD,
  AD_VC_SP,

  // F adaptives
  // L@T S@C W@M
  AD_TF_LF,
  AD_FT_FL,
  AD_CF_SF,
  AD_FC_FS,
  AD_MF_WF,
  AD_FM_FW,
  AD_GFC_LFS,
  AD_DFC_NFS,

  // K adaptives
  // S@C C@N N@T L@G P@L
  AD_GK_LK,
  AD_KG_KL,
  AD_NK_CK,
  AD_KN_KC,
  AD_CK_SK,
  AD_KC_KS,
  AD_TK_NK,
  AD_KT_KN,
  AD_LK_PK,
  AD_KL_KP,
  AD_GKC_LKS,
  AD_NKC_CKS,
  AD_TKC_NKS,
  AD_NKG_CKL, // cackle

  // B adaptives
  // L@D S@C C@N M@T P@L V@P
  AD_TB_MB,
  AD_CB_SB,
  AD_BC_BS,
  AD_DB_LB,
  AD_BD_BL,
  AD_LB_PB,
  AD_BL_BP,
  AD_PB_VB,
  AD_BP_BV,
  AD_NB_CB,
  AD_BN_BC, // ribcage
  AD_DBC_LBS,
  AD_TBC_MBS,
  AD_BTC_BTS, // doubts

  // Vowel SFB adaptives
  AD_As_AU,
  AD_Es_EO,
  AD_Is_YI,
  AD_Us_UA,
  AD_Os_OE,
  AD_JH_JI,

  // J adaptives
  AD_Jq_JO,
  AD_qJ_OJ, ADAPTIVE_LAST = AD_qJ_OJ,

  // Weird letters
  ST_COMBO_XW_ZZ,
  ST_COMBO_WG_QU,
  ST_COMBO_WMG_Q,

  // Symbol combos
  ST_COMBO_CODE_BLOCK,
  ST_COMBO_ASTERISK,
  ST_COMBO_PLUS,

  // H Bigram combos
  ST_COMBO_WM,
  ST_COMBO_GM,
  ST_COMBO_DL,
  ST_COMBO_CN,
  ST_COMBO_TN,
  ST_COMBO_GF,
  ST_COMBO_NGF,
};

// Bigram combo
const uint16_t PROGMEM comboWM[] = { KC_W, KC_M, COMBO_END};
const uint16_t PROGMEM comboGM[] = { KC_M, KC_G, COMBO_END};
const uint16_t PROGMEM comboDL[] = { KC_D, KC_L, COMBO_END};
const uint16_t PROGMEM comboCN[] = { KC_C, KC_N, COMBO_END};
const uint16_t PROGMEM comboTN[] = { KC_N, KC_T, COMBO_END};
const uint16_t PROGMEM comboGF[] = { KC_G, KC_F, COMBO_END};
const uint16_t PROGMEM comboNGF[] = { KC_N, KC_G, KC_F, COMBO_END};

// Weird letters
const uint16_t PROGMEM comboXW[] = { LT(0, KC_X), KC_W, COMBO_END};
const uint16_t PROGMEM comboWG[] = { KC_W, KC_G, COMBO_END };
const uint16_t PROGMEM comboWMG[] = { KC_W, KC_M, KC_G, COMBO_END };

// Symbol combos
const uint16_t PROGMEM comboAstr[] = { LT(0, KC_COMMA), KC_A, COMBO_END};
const uint16_t PROGMEM comboCodeBlock[] = { LT(0, KC_SCLN), LT(0, KC_DOT), LT(0, KC_QUOT), COMBO_END };
const uint16_t PROGMEM comboPlus[] = { LT(0, KC_MINUS), KC_U, COMBO_END};

const uint16_t PROGMEM adaptiveMG[] = { KC_M, KC_G, COMBO_END };
const uint16_t PROGMEM adaptiveMC[] = { KC_M, KC_C, COMBO_END };
const uint16_t PROGMEM adaptiveCM[] = { KC_C, KC_M, COMBO_END };
const uint16_t PROGMEM adaptivePN[] = { KC_P, KC_N, COMBO_END };
const uint16_t PROGMEM adaptiveNP[] = { KC_N, KC_P, COMBO_END };
const uint16_t PROGMEM adaptiveMT[] = { KC_M, KC_T, COMBO_END };
const uint16_t PROGMEM adaptiveTM[] = { KC_T, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveGM[] = { KC_G, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveDM[] = { KC_D, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveMD[] = { KC_M, KC_D, COMBO_END };
const uint16_t PROGMEM adaptiveVC[] = { KC_V, KC_C, COMBO_END };

// F adaptives
// L@G S@C W@M
const uint16_t PROGMEM adaptiveTF[] = { KC_T, KC_F, COMBO_END };
const uint16_t PROGMEM adaptiveFT[] = { KC_F, KC_T, COMBO_END };
const uint16_t PROGMEM adaptiveCF[] = { KC_C, KC_F, COMBO_END };
const uint16_t PROGMEM adaptiveFC[] = { KC_F, KC_C, COMBO_END };
const uint16_t PROGMEM adaptiveMF[] = { KC_M, KC_F, COMBO_END };
const uint16_t PROGMEM adaptiveFM[] = { KC_F, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveGFC[] = { KC_G, KC_F, KC_C, COMBO_END };
const uint16_t PROGMEM adaptiveDFC[] = { KC_D, KC_F, KC_C, COMBO_END };

// K adaptives
// S@C C@N N@T L@G P@L
const uint16_t PROGMEM adaptiveGK[] = { KC_G, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveKG[] = { KC_K, KC_G, COMBO_END };
const uint16_t PROGMEM adaptiveNK[] = { KC_N, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveKN[] = { KC_K, KC_N, COMBO_END };
const uint16_t PROGMEM adaptiveCK[] = { KC_C, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveKC[] = { KC_K, KC_C, COMBO_END };
const uint16_t PROGMEM adaptiveTK[] = { KC_T, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveKT[] = { KC_K, KC_T, COMBO_END };
const uint16_t PROGMEM adaptiveLK[] = { KC_L, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveKL[] = { KC_K, KC_L, COMBO_END };
const uint16_t PROGMEM adaptiveGKC[] = { KC_G, KC_K, KC_C, COMBO_END };
const uint16_t PROGMEM adaptiveNKC[] = { KC_N, KC_K, KC_C, COMBO_END };
const uint16_t PROGMEM adaptiveTKC[] = { KC_T, KC_K, KC_C, COMBO_END };
const uint16_t PROGMEM adaptiveNKG[] = { KC_N, KC_K, KC_G, COMBO_END };

// B adaptives
// L@D S@C C@N M@G P@L V@P
const uint16_t PROGMEM adaptiveTB[] = { KC_T, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveCB[] = { KC_C, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveBC[] = { KC_B, KC_C, COMBO_END };
const uint16_t PROGMEM adaptiveDB[] = { KC_D, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveBD[] = { KC_B, KC_D, COMBO_END };
const uint16_t PROGMEM adaptiveLB[] = { KC_L, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveBL[] = { KC_B, KC_L, COMBO_END };
const uint16_t PROGMEM adaptivePB[] = { KC_P, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveBP[] = { KC_B, KC_P, COMBO_END };
const uint16_t PROGMEM adaptiveNB[] = { KC_N, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveBN[] = { KC_B, KC_N, COMBO_END };
const uint16_t PROGMEM adaptiveDBC[] = { KC_D, KC_B, KC_C, COMBO_END };
const uint16_t PROGMEM adaptiveTBC[] = { KC_T, KC_B, KC_C, COMBO_END };
const uint16_t PROGMEM adaptiveBTC[] = { KC_B, KC_T, KC_C, COMBO_END };

// Vowel SFB adaptives
const uint16_t PROGMEM adaptiveAs[] = { KC_A, LT(0, KC_SLASH), COMBO_END };
const uint16_t PROGMEM adaptiveEs[] = { KC_E, LT(0, KC_SLASH), COMBO_END };
const uint16_t PROGMEM adaptiveIs[] = { KC_I, LT(0, KC_SLASH), COMBO_END };
const uint16_t PROGMEM adaptiveUs[] = { KC_U, LT(0, KC_SLASH), COMBO_END };
const uint16_t PROGMEM adaptiveOs[] = { KC_O, LT(0, KC_SLASH), COMBO_END };
const uint16_t PROGMEM adaptiveJH[] = { KC_J, KC_H, COMBO_END };

// J adaptives
const uint16_t PROGMEM adaptiveJq[] = { KC_J, LT(0, KC_QUOTE), COMBO_END };
const uint16_t PROGMEM adaptiveqJ[] = { LT(0, KC_QUOTE), KC_J, COMBO_END };

combo_t key_combos[] = {
  [AD_MG_LG] = COMBO(adaptiveMG, AD_MACRO_LG),
  [AD_MC_ML] = COMBO(adaptiveMC, AD_MACRO_ML),
  [AD_CM_LM] = COMBO(adaptiveCM, AD_MACRO_LM),
  [AD_NP_NL] = COMBO(adaptiveNP, AD_MACRO_NL),
  [AD_PN_LN] = COMBO(adaptivePN, AD_MACRO_LN),
  [AD_MT_MN] = COMBO(adaptiveMT, AD_MACRO_MN),
  [AD_TM_NM] = COMBO(adaptiveTM, AD_MACRO_NM),
  [AD_GM_GL] = COMBO(adaptiveGM, AD_MACRO_GL),
  [AD_DM_DG] = COMBO(adaptiveDM, AD_MACRO_DG),
  [AD_MD_GD] = COMBO(adaptiveMD, AD_MACRO_GD),
  [AD_VC_SP] = COMBO(adaptiveVC, AD_MACRO_SP),

  // F adaptives
  // L@T S@C W@M
  [AD_TF_LF] = COMBO(adaptiveTF, AD_MACRO_LF),
  [AD_FT_FL] = COMBO(adaptiveFT, AD_MACRO_FL),
  [AD_CF_SF] = COMBO(adaptiveCF, AD_MACRO_SF),
  [AD_FC_FS] = COMBO(adaptiveFC, AD_MACRO_FS),
  [AD_MF_WF] = COMBO(adaptiveMF, AD_MACRO_WF),
  [AD_FM_FW] = COMBO(adaptiveFM, AD_MACRO_FW),
  [AD_GFC_LFS] = COMBO(adaptiveGFC, AD_MACRO_LFS),
  [AD_DFC_NFS] = COMBO(adaptiveDFC, AD_MACRO_NFS),

  // K adaptives
  // S@C C@N N@T L@G P@L
  [AD_GK_LK] = COMBO(adaptiveGK, AD_MACRO_LK),
  [AD_KG_KL] = COMBO(adaptiveKG, AD_MACRO_KL),
  [AD_NK_CK] = COMBO(adaptiveNK, AD_MACRO_CK),
  [AD_KN_KC] = COMBO(adaptiveKN, AD_MACRO_KC),
  [AD_CK_SK] = COMBO(adaptiveCK, AD_MACRO_SK),
  [AD_KC_KS] = COMBO(adaptiveKC, AD_MACRO_KS),
  [AD_TK_NK] = COMBO(adaptiveTK, AD_MACRO_NK),
  [AD_KT_KN] = COMBO(adaptiveKT, AD_MACRO_KN),
  [AD_LK_PK] = COMBO(adaptiveLK, AD_MACRO_PK),
  [AD_KL_KP] = COMBO(adaptiveKL, AD_MACRO_KP),
  [AD_GKC_LKS] = COMBO(adaptiveGKC, AD_MACRO_LKS),
  [AD_NKC_CKS] = COMBO(adaptiveNKC, AD_MACRO_CKS),
  [AD_TKC_NKS] = COMBO(adaptiveTKC, AD_MACRO_NKS),
  [AD_NKG_CKL] = COMBO(adaptiveNKG, AD_MACRO_CKL),

  // B adaptives
  // L@D S@C C@N M@T P@L V@P
  [AD_TB_MB] = COMBO(adaptiveTB, AD_MACRO_MB),
  [AD_CB_SB] = COMBO(adaptiveCB, AD_MACRO_SB),
  [AD_BC_BS] = COMBO(adaptiveBC, AD_MACRO_BS),
  [AD_DB_LB] = COMBO(adaptiveDB, AD_MACRO_LB),
  [AD_BD_BL] = COMBO(adaptiveBD, AD_MACRO_BL),
  [AD_LB_PB] = COMBO(adaptiveLB, AD_MACRO_PB),
  [AD_BL_BP] = COMBO(adaptiveBL, AD_MACRO_BP),
  [AD_PB_VB] = COMBO(adaptivePB, AD_MACRO_VB),
  [AD_BP_BV] = COMBO(adaptiveBP, AD_MACRO_BV),
  [AD_NB_CB] = COMBO(adaptiveNB, AD_MACRO_CB),
  [AD_BN_BC] = COMBO(adaptiveBN, AD_MACRO_BC),
  [AD_DBC_LBS] = COMBO(adaptiveDBC, AD_MACRO_LBS),
  [AD_TBC_MBS] = COMBO(adaptiveTBC, AD_MACRO_MBS),
  [AD_BTC_BTS] = COMBO(adaptiveBTC, AD_MACRO_BTS),

  // Vowel SFB adaptives
  [AD_As_AU] = COMBO(adaptiveAs, AD_MACRO_AU),
  [AD_Es_EO] = COMBO(adaptiveEs, AD_MACRO_EO),
  [AD_Is_YI] = COMBO(adaptiveIs, AD_MACRO_YI),
  [AD_Us_UA] = COMBO(adaptiveUs, AD_MACRO_UA),
  [AD_Os_OE] = COMBO(adaptiveOs, AD_MACRO_OE),
  [AD_JH_JI] = COMBO(adaptiveJH, AD_MACRO_JI),

  // J adaptives
  [AD_Jq_JO] = COMBO(adaptiveJq, AD_MACRO_JO),
  [AD_qJ_OJ] = COMBO(adaptiveqJ, AD_MACRO_OJ),

  // Weird letters
  [ST_COMBO_XW_ZZ] = COMBO(comboXW, ST_MACRO_ZZ),
  [ST_COMBO_WG_QU] = COMBO(comboWG, ST_MACRO_QU),
  [ST_COMBO_WMG_Q] = COMBO(comboWMG, KC_Q),

  // Symbol combos
  [ST_COMBO_CODE_BLOCK] = COMBO(comboCodeBlock, ST_MACRO_CODE_BLOCK),
  [ST_COMBO_ASTERISK] = COMBO(comboAstr, KC_ASTR),
  [ST_COMBO_PLUS] = COMBO(comboPlus, KC_PLUS),

  // H Bigram combos
  [ST_COMBO_WM] = COMBO(comboWM, ST_MACRO_WH),
  [ST_COMBO_GM] = COMBO(comboGM, ST_MACRO_GH),
  [ST_COMBO_DL] = COMBO(comboDL, ST_MACRO_SH), // Maybe this should be ordered?
  [ST_COMBO_CN] = COMBO(comboCN, ST_MACRO_CH),
  [ST_COMBO_TN] = COMBO(comboTN, ST_MACRO_TH),
  [ST_COMBO_GF] = COMBO(comboGF, ST_MACRO_PH),
  [ST_COMBO_NGF] = COMBO(comboNGF, ST_MACRO_SPH), // Sphere
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
  case KC_MINS:
    add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to this key.
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
    SEND_CASED_STRINGS(ST_MACRO_ZZ, "zz", "Zz", "ZZ");
    SEND_CASED_STRINGS(ST_MACRO_QU, "qu", "Qu", "QU");
    SEND_CASED_STRINGS(AD_MACRO_LG, "lg", "Lg", "LG");
    SEND_CASED_STRINGS(AD_MACRO_ML, "ml", "Ml", "ML");
    SEND_CASED_STRINGS(AD_MACRO_LM, "lm", "Lm", "LM");
    SEND_CASED_STRINGS(AD_MACRO_LN, "ln", "Ln", "LN");
    SEND_CASED_STRINGS(AD_MACRO_NL, "nl", "Nl", "NL");
    SEND_CASED_STRINGS(AD_MACRO_MN, "mn", "Mn", "MN");
    SEND_CASED_STRINGS(AD_MACRO_NM, "nm", "Nm", "NM");
    SEND_CASED_STRINGS(AD_MACRO_GL, "gl", "Gl", "GL");
    SEND_CASED_STRINGS(AD_MACRO_DG, "dg", "Dg", "DG");
    SEND_CASED_STRINGS(AD_MACRO_GD, "gd", "Gd", "GD");
    SEND_CASED_STRINGS(AD_MACRO_SP, "sp", "Sp", "SP");

  // F adaptives
  // L@T S@C W@M
    SEND_CASED_STRINGS(AD_MACRO_LF, "lf", "Lf", "LF");
    SEND_CASED_STRINGS(AD_MACRO_FL, "fl", "Fl", "FL");
    SEND_CASED_STRINGS(AD_MACRO_SF, "sf", "Sf", "SF");
    SEND_CASED_STRINGS(AD_MACRO_FS, "fs", "Fs", "FS");
    SEND_CASED_STRINGS(AD_MACRO_WF, "wf", "Wf", "WF");
    SEND_CASED_STRINGS(AD_MACRO_FW, "fw", "Fw", "FW");
    SEND_CASED_STRINGS(AD_MACRO_LFS, "lfs", "Lfs", "LFS");
    SEND_CASED_STRINGS(AD_MACRO_NFS, "nfs", "Nfs", "NFS");

  // K adaptives
  // S@C C@N N@T L@G P@L
    SEND_CASED_STRINGS(AD_MACRO_LK, "lk", "Lk", "LK");
    SEND_CASED_STRINGS(AD_MACRO_KL, "kl", "Kl", "KL");
    SEND_CASED_STRINGS(AD_MACRO_CK, "ck", "Ck", "CK");
    SEND_CASED_STRINGS(AD_MACRO_KC, "kc", "Kc", "KC");
    SEND_CASED_STRINGS(AD_MACRO_SK, "sk", "Sk", "SK");
    SEND_CASED_STRINGS(AD_MACRO_KS, "ks", "Ks", "KS");
    SEND_CASED_STRINGS(AD_MACRO_NK, "nk", "Nk", "NK");
    SEND_CASED_STRINGS(AD_MACRO_KN, "kn", "Kn", "KN");
    SEND_CASED_STRINGS(AD_MACRO_PK, "pk", "Pk", "PK");
    SEND_CASED_STRINGS(AD_MACRO_KP, "kp", "Kp", "KP");
    SEND_CASED_STRINGS(AD_MACRO_LKS, "lks", "Lks", "LKS");
    SEND_CASED_STRINGS(AD_MACRO_CKS, "cks", "Cks", "CKS");
    SEND_CASED_STRINGS(AD_MACRO_NKS, "nks", "Nks", "NKS");
    SEND_CASED_STRINGS(AD_MACRO_CKL, "ckl", "Ckl", "CKL"); // cackle

  // B adaptives
  // L@D S@C C@N M@T
    SEND_CASED_STRINGS(AD_MACRO_MB, "mb", "Mb", "MB");
    SEND_CASED_STRINGS(AD_MACRO_SB, "sb", "Sb", "SB");
    SEND_CASED_STRINGS(AD_MACRO_BS, "bs", "Bs", "BS");
    SEND_CASED_STRINGS(AD_MACRO_LB, "lb", "Lb", "LB");
    SEND_CASED_STRINGS(AD_MACRO_BL, "bl", "Bl", "BL");
    SEND_CASED_STRINGS(AD_MACRO_PB, "pb", "Pb", "PB");
    SEND_CASED_STRINGS(AD_MACRO_BP, "bp", "Bp", "BP");
    SEND_CASED_STRINGS(AD_MACRO_VB, "vb", "Vb", "VB");
    SEND_CASED_STRINGS(AD_MACRO_BV, "bv", "Bv", "BV");
    SEND_CASED_STRINGS(AD_MACRO_CB, "cb", "Cb", "CB");
    SEND_CASED_STRINGS(AD_MACRO_BC, "bc", "Bc", "BC");
    SEND_CASED_STRINGS(AD_MACRO_LBS, "lbs", "Lbs", "LBS");
    SEND_CASED_STRINGS(AD_MACRO_MBS, "mbs", "Mbs", "MBS");
    SEND_CASED_STRINGS(AD_MACRO_BTS, "bts", "Bts", "BTS");

  // Vowel SFB adaptives
    SEND_CASED_STRINGS(AD_MACRO_AU, "au", "Au", "AU");
    SEND_CASED_STRINGS(AD_MACRO_EO, "eo", "Eo", "EO");
    SEND_CASED_STRINGS(AD_MACRO_UA, "ua", "Ua", "UA");
    SEND_CASED_STRINGS(AD_MACRO_OE, "oe", "Oe", "OE");
    SEND_CASED_STRINGS(AD_MACRO_YI, "yi", "Yi", "YI");
    SEND_CASED_STRINGS(AD_MACRO_JI, "ji", "Ji", "JI");

  // J adaptives
    SEND_CASED_STRINGS(AD_MACRO_JO, "jo", "Jo", "JO");
    SEND_CASED_STRINGS(AD_MACRO_OJ, "oj", "oJ", "OJ");

  // H digraphs
    SEND_CASED_STRINGS(ST_MACRO_WH, "wh", "Wh", "WH");
    SEND_CASED_STRINGS(ST_MACRO_GH, "gh", "Gh", "GH");
    SEND_CASED_STRINGS(ST_MACRO_SH, "sh", "Sh", "SH");
    SEND_CASED_STRINGS(ST_MACRO_CH, "ch", "Ch", "CH");
    SEND_CASED_STRINGS(ST_MACRO_TH, "th", "Th", "TH");
    SEND_CASED_STRINGS(ST_MACRO_PH, "ph", "Ph", "PH");
    SEND_CASED_STRINGS(ST_MACRO_SPH, "sph", "Sph", "SPH"); // Sphere

  // Symbol macros
  case ST_MACRO_CODE_BLOCK:
    if (record->event.pressed) {
      SEND_STRINGS("```", "~~~", "```");
    }
    return true;

  case ST_MACRO_FORCE_EQUAL:
    if (record->event.pressed) {
      SEND_STRING_CLEAR("=");
    }
    return true;

  // Tap-hold keys
  TAPHOLD_CASED(LT(0, KC_X), "z", "Z", "Z");
  TAPHOLD_CODE16(LT(0, KC_QUOT), KC_EXLM);
  TAPHOLD_CODE16(LT(0, KC_DOT), KC_CIRC);
  TAPHOLD_CODE16(LT(0, KC_COMMA), KC_DLR);
  TAPHOLD_CODE16(LT(0, KC_SCLN), KC_GRAVE);
  TAPHOLD_CODE16(LT(0, KC_MINUS), KC_QUES);
  TAPHOLD_CODE16(LT(0, KC_SLASH), KC_BSLS);

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
  case MT(MOD_LGUI, KC_LEFT):
    return g_tapping_term + 25;
  case MT(MOD_LALT, KC_UP):
    return g_tapping_term + 25;
  case MT(MOD_LCTL, KC_DOWN):
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

#define BASE_COLOUR {93,255,191}
#define NUM_COLOUR {36,255,193}
#define NUMPAD_COLOUR {52,255,193}
#define FN_COLOUR {203,196,165}
#define FIRMWARE_COLOUR {8,235,250}
#define LEFT_COLOUR {101,206,157}
#define MOD_COLOUR {86,255,204}
#define OFF_COLOUR {0,0,0}
#define CLEAR_COLOUR {67,180,255}
#define MEDIA_COLOUR {102,255,143}
#define LFN_COLOUR {237,234,175}

#define TAP_HOLD_COLOUR {128,242,161}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [_BASE] = {
        BASE_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, LEFT_COLOUR,
        BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR,
        BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, FN_COLOUR,
        BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, NUM_COLOUR,
        BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, MOD_COLOUR,
        BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR,
        BASE_COLOUR, OFF_COLOUR, OFF_COLOUR,
        BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR,

        BASE_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR,
        BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR,
        BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, MOD_COLOUR,
        BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, FN_COLOUR,
        BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, MOD_COLOUR,
        BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR,
        BASE_COLOUR, OFF_COLOUR, OFF_COLOUR,
        BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR
    },

    [_LMOD] = {
        MOD_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR,
        OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, MOD_COLOUR,
        OFF_COLOUR, OFF_COLOUR, MOD_COLOUR, OFF_COLOUR, OFF_COLOUR,
        OFF_COLOUR, OFF_COLOUR, MOD_COLOUR, OFF_COLOUR, OFF_COLOUR,
        OFF_COLOUR, OFF_COLOUR, MOD_COLOUR, OFF_COLOUR, CLEAR_COLOUR,
        OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR,
        MOD_COLOUR, OFF_COLOUR, OFF_COLOUR,
        OFF_COLOUR, OFF_COLOUR, BASE_COLOUR, OFF_COLOUR,

        BASE_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR,
        OFF_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR,
        OFF_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, OFF_COLOUR,
        OFF_COLOUR, OFF_COLOUR, BASE_COLOUR, BASE_COLOUR, OFF_COLOUR,
        OFF_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, MOD_COLOUR,
        OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR,
        BASE_COLOUR, OFF_COLOUR, OFF_COLOUR,
        BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR
    },

    [_RMOD] = {
        BASE_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR,
        OFF_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR,
        OFF_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, OFF_COLOUR,
        OFF_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, OFF_COLOUR,
        OFF_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, MOD_COLOUR,
        OFF_COLOUR, OFF_COLOUR, BASE_COLOUR, OFF_COLOUR,
        BASE_COLOUR, OFF_COLOUR, OFF_COLOUR,
        BASE_COLOUR, TAP_HOLD_COLOUR, BASE_COLOUR, BASE_COLOUR,

        MOD_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR,
        OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, MOD_COLOUR,
        OFF_COLOUR, OFF_COLOUR, MOD_COLOUR, OFF_COLOUR, OFF_COLOUR,
        OFF_COLOUR, OFF_COLOUR, MOD_COLOUR, OFF_COLOUR, OFF_COLOUR,
        OFF_COLOUR, OFF_COLOUR, MOD_COLOUR, OFF_COLOUR, CLEAR_COLOUR,
        OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR,
        MOD_COLOUR, OFF_COLOUR, OFF_COLOUR,
        OFF_COLOUR, OFF_COLOUR, MOD_COLOUR, OFF_COLOUR
    },

    [_NUM] = {
        NUM_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, BASE_COLOUR,
        OFF_COLOUR, NUM_COLOUR, NUM_COLOUR, NUM_COLOUR, NUM_COLOUR,
        OFF_COLOUR, NUM_COLOUR, TAP_HOLD_COLOUR, NUM_COLOUR, FN_COLOUR,
        OFF_COLOUR, NUM_COLOUR, TAP_HOLD_COLOUR, NUM_COLOUR, BASE_COLOUR,
        OFF_COLOUR, NUM_COLOUR, TAP_HOLD_COLOUR, NUM_COLOUR, MOD_COLOUR,
        OFF_COLOUR, NUM_COLOUR, NUM_COLOUR, NUM_COLOUR,
        NUM_COLOUR, OFF_COLOUR, OFF_COLOUR,
        NUMPAD_COLOUR, NUM_COLOUR, NUM_COLOUR, OFF_COLOUR,

        NUM_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, BASE_COLOUR,
        OFF_COLOUR, NUM_COLOUR, NUM_COLOUR, NUM_COLOUR, NUM_COLOUR,
        OFF_COLOUR, NUM_COLOUR, NUM_COLOUR, NUM_COLOUR, NUM_COLOUR,
        OFF_COLOUR, NUM_COLOUR, NUM_COLOUR, NUM_COLOUR, TAP_HOLD_COLOUR,
        OFF_COLOUR, NUM_COLOUR, NUM_COLOUR, NUM_COLOUR, NUM_COLOUR,
        OFF_COLOUR, NUM_COLOUR, NUM_COLOUR, NUM_COLOUR,
        NUM_COLOUR, OFF_COLOUR, OFF_COLOUR,
        NUM_COLOUR, NUM_COLOUR, NUM_COLOUR, NUM_COLOUR
    },

    [_NUMPAD] = {
        NUMPAD_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, BASE_COLOUR,
        OFF_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR,
        OFF_COLOUR, NUMPAD_COLOUR, TAP_HOLD_COLOUR, NUMPAD_COLOUR, FN_COLOUR,
        OFF_COLOUR, NUMPAD_COLOUR, TAP_HOLD_COLOUR, NUMPAD_COLOUR, BASE_COLOUR,
        OFF_COLOUR, NUMPAD_COLOUR, TAP_HOLD_COLOUR, NUMPAD_COLOUR, MOD_COLOUR,
        OFF_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR,
        NUMPAD_COLOUR, OFF_COLOUR, OFF_COLOUR,
        NUM_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, OFF_COLOUR,

        NUMPAD_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, BASE_COLOUR,
        OFF_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR,
        OFF_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR,
        OFF_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR,
        OFF_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR,
        OFF_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR,
        NUMPAD_COLOUR, OFF_COLOUR, OFF_COLOUR,
        NUMPAD_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR
    },

    [_FN] = {
        FN_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, BASE_COLOUR,
        FN_COLOUR, FN_COLOUR, MEDIA_COLOUR, MEDIA_COLOUR, FN_COLOUR,
        FN_COLOUR, FN_COLOUR, TAP_HOLD_COLOUR, FN_COLOUR, BASE_COLOUR,
        FN_COLOUR, FN_COLOUR, TAP_HOLD_COLOUR, FN_COLOUR, NUM_COLOUR,
        FN_COLOUR, FN_COLOUR, TAP_HOLD_COLOUR, FN_COLOUR, MOD_COLOUR,
        FN_COLOUR, FN_COLOUR, FN_COLOUR, FN_COLOUR,
        FN_COLOUR, FN_COLOUR, OFF_COLOUR,
        OFF_COLOUR, OFF_COLOUR, FN_COLOUR, OFF_COLOUR,

        FN_COLOUR, MEDIA_COLOUR, MEDIA_COLOUR, FN_COLOUR, BASE_COLOUR,
        FN_COLOUR, MEDIA_COLOUR, FN_COLOUR, FN_COLOUR, FN_COLOUR,
        FN_COLOUR, MEDIA_COLOUR, FN_COLOUR, FN_COLOUR, MOD_COLOUR,
        FN_COLOUR, MEDIA_COLOUR, FN_COLOUR, FN_COLOUR, CLEAR_COLOUR,
        FN_COLOUR, MEDIA_COLOUR, FN_COLOUR, FN_COLOUR, MOD_COLOUR,
        FN_COLOUR, FN_COLOUR, FN_COLOUR, FN_COLOUR,
        FN_COLOUR, FN_COLOUR, FN_COLOUR,
        FN_COLOUR, FN_COLOUR, FN_COLOUR, FN_COLOUR
    },

    [_LEFT] = {
        LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR, LFN_COLOUR, MOD_COLOUR,
        LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR,
        LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR, MOD_COLOUR,
        LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR, MOD_COLOUR,
        LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR, MOD_COLOUR,
        LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR,
        LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR,
        LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR,

        OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, BASE_COLOUR,
        OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR,
        OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR,
        OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR,
        OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR,
        OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR,
        OFF_COLOUR, OFF_COLOUR, OFF_COLOUR,
        OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR
    },

    [_LFN] = { LFN_COLOUR, LFN_COLOUR, LFN_COLOUR, MOD_COLOUR, CLEAR_COLOUR, LFN_COLOUR, LFN_COLOUR, LFN_COLOUR, LFN_COLOUR, LFN_COLOUR, LFN_COLOUR, LFN_COLOUR, LFN_COLOUR, LFN_COLOUR, MOD_COLOUR, LFN_COLOUR, LFN_COLOUR, LFN_COLOUR, LFN_COLOUR, MOD_COLOUR, LFN_COLOUR, LFN_COLOUR, LFN_COLOUR, LFN_COLOUR, MOD_COLOUR, LFN_COLOUR, LFN_COLOUR, LFN_COLOUR, LFN_COLOUR, LFN_COLOUR, LFN_COLOUR, LFN_COLOUR, LFN_COLOUR, LFN_COLOUR, LFN_COLOUR, LFN_COLOUR, LFN_COLOUR, LFN_COLOUR, LFN_COLOUR, MOD_COLOUR, LFN_COLOUR, OFF_COLOUR, FIRMWARE_COLOUR, LFN_COLOUR, LFN_COLOUR, LFN_COLOUR, OFF_COLOUR, {253,174,200}, {253,174,200}, {253,174,200}, MOD_COLOUR, OFF_COLOUR, {253,174,200}, {253,174,200}, {253,174,200}, MOD_COLOUR, OFF_COLOUR, {253,174,200}, {253,174,200}, {188,255,180}, FIRMWARE_COLOUR, OFF_COLOUR, {253,174,200}, {253,174,200}, {12,255,186}, LFN_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, OFF_COLOUR, BASE_COLOUR, LFN_COLOUR, LFN_COLOUR },

    [_FIRMWARE] = { FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, BASE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, OFF_COLOUR, {0,255,255}, OFF_COLOUR, FIRMWARE_COLOUR, {0,255,255}, OFF_COLOUR, OFF_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, BASE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, FIRMWARE_COLOUR, CLEAR_COLOUR, OFF_COLOUR, {172,255,255}, OFF_COLOUR, FIRMWARE_COLOUR, {172,255,255}, OFF_COLOUR, OFF_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR }
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
