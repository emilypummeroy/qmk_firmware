#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,

  // TODO rework brackets
  MB_MACRO_DIAMOND,
  MB_MACRO_PARENS,
  MB_MACRO_SQUARE,
  MB_MACRO_CURLS,
  MB_MACRO_ARROW_BRACE,

  ST_MACRO_FULL_STOP, // Maybe this should shift the next letter

  ST_MACRO_ZZ, KC_ALNUM_MACRO_FIRST = ST_MACRO_ZZ,
  ST_MACRO_QU,
  ST_MACRO_WH,
  ST_MACRO_GH,
  ST_MACRO_SH,
  ST_MACRO_CH,
  ST_MACRO_TH,
  ST_MACRO_PH,

  AD_MACRO_WL,
  AD_MACRO_MP,
  AD_MACRO_LG,
  AD_MACRO_ML,
  AD_MACRO_LM,
  AD_MACRO_MN,
  AD_MACRO_NM,
  AD_MACRO_GL,
  AD_MACRO_DG,
  AD_MACRO_VS,
  // Maybe Mc would be convenient

  // F adaptives
  // L@G N@T S@C W@M
  // Need FT for after, ooft, etc.
  AD_MACRO_LF,
  AD_MACRO_FL,
  AD_MACRO_NF,
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
  AD_MACRO_BM,
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
  AD_MACRO_BT, // SFB, TB is easier, BT is more common
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
    KC_NO,          LT(0, KC_X),    KC_W,           KC_M,           KC_G,           KC_F,           KC_NO,                                          KC_NO,          KC_SCLN,        KC_DOT,         KC_QUOTE,       KC_J,           KC_AT,          KC_NO,
    KC_TAB,         KC_S,           KC_C,           KC_N,           KC_T,           KC_K,           KC_NO,                                          KC_NO,          KC_COMMA,       KC_A,           KC_E,           KC_I,           KC_H,           KC_NO,
    KC_NO,          KC_V,           KC_P,           KC_L,           KC_D,           KC_B,                                                                           KC_MINUS,       KC_U,           KC_O,           KC_Y,           KC_SLASH,       KC_NO,
    TO(_LEFT),      KC_NO,          MO(_FN),        MO(_NUM),       LM(_LMOD, MOD_LSFT),            KC_ESCAPE,                                      RCTL(KC_BSPC),             LM(_RMOD, MOD_LSFT), MO(_FN),        CW_TOGG,        KC_NO,          KC_NO,
    KC_R,           KC_LPRN,        KC_NO,                          KC_NO,          KC_ENTER,       KC_SPACE
  ),
  [_LMOD] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_CIRC,        KC_AT,          KC_RPRN,        KC_DLR,         KC_ASTR,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_DQUO,        KC_J,           KC_NO,          KC_TRANSPARENT,
    KC_TAB,         KC_NO,          KC_LEFT_GUI,    KC_LEFT_ALT,    KC_LEFT_CTRL,   KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_A,           KC_E,           KC_I,           KC_H,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                          KC_NO,          KC_U,           KC_O,           KC_Y,           KC_QUES,        KC_TRANSPARENT,
    KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT,                 KC_TRANSPARENT,                                 KC_BSPC,                        OSM(MOD_RSFT),  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_NO,          KC_NO,          KC_TRANSPARENT,                 KC_TRANSPARENT, KC_ENTER,       ST_MACRO_FULL_STOP
  ),
  [_RMOD] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_AMPR,        KC_HASH,        KC_EXLM,        KC_PERC,        KC_LPRN,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, LT(0, KC_X),    KC_W,           KC_M,           KC_G,           KC_F,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,
    KC_TAB,         KC_S,           KC_C,           KC_N,           KC_T,           KC_K,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_RIGHT_CTRL,  KC_LEFT_ALT,    KC_RIGHT_GUI,   KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_V,           KC_P,           KC_L,           KC_D,           KC_B,                                                                           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,
    KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          OSM(MOD_RSFT),                  KC_TRANSPARENT,                                 KC_BSPC,                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_R,           KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_NO,          KC_NO
  ),
  [_NUM] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LABK,        KC_D,           KC_E,           KC_F,           KC_RABK,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_ASTR,        KC_7,           KC_8,           KC_9,           KC_DLR,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_X,           MT(MOD_LGUI, KC_LEFT),MT(MOD_LALT, KC_UP),MT(MOD_LCTL, KC_DOWN),KC_RIGHT,       KC_TRANSPARENT,                 KC_TRANSPARENT, KC_PLUS,        KC_4,           KC_5,           KC_6,           KC_HASH,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LPRN,        KC_A,           KC_B,           KC_C,           KC_RPRN,                                                                        KC_MINUS,       KC_1,           KC_2,           KC_3,           KC_SLASH,       KC_TRANSPARENT,
    TO(0),          KC_TRANSPARENT, TO(_FN),        TO(0),          KC_LEFT_SHIFT,                  KC_TRANSPARENT,                                 KC_BSPC,                        KC_0,           LT(0, KC_DOT),  KC_EQUAL,       KC_TRANSPARENT, TO(0),
    TO(_NUMPAD),    KC_COMMA,       KC_TRANSPARENT,                 KC_TRANSPARENT, KC_ENTER,       KC_TRANSPARENT
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
    KC_TRANSPARENT, KC_F14,         KC_F10,         KC_F11,         KC_F12,         KC_F15,         KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F16,         KC_F17,         KC_F18,         KC_F19,         KC_F20,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_F13,         KC_F9,          KC_F8,          KC_F7,          KC_F23,         KC_F24,                                         KC_INSERT,      KC_ESCAPE,      KC_MEDIA_NEXT_TRACK,KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,
    KC_TRANSPARENT, KC_BRIGHTNESS_UP,MT(MOD_LGUI, KC_F6),MT(MOD_LALT, KC_F5),MT(MOD_LCTL, KC_F4),KC_F22,         KC_TRANSPARENT,                    KC_DELETE,      KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TAB,         KC_AUDIO_VOL_DOWN,
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
  AD_WM_WL, ADAPTIVE_FIRST = AD_WM_WL,
  AD_MW_MP,
  AD_MG_LG,
  AD_MC_ML,
  AD_CM_LM,
  AD_MT_MN,
  AD_TM_NM,
  AD_GM_GL,
  AD_DM_DG,
  AD_VC_VS,

  // F adaptives
  // L@G N@T S@C W@M
  AD_GF_LF,
  AD_FG_FL,
  AD_TF_NF,
  // Need FT for after, ooft, etc.
  AD_CF_SF,
  AD_FC_FS,
  AD_MF_WF,
  AD_FM_FW,
  AD_GFC_LFS,
  AD_TFC_NFS,

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
  // L@D S@C C@N M@G P@L V@P
  AD_GB_MB,
  AD_BG_BM,
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
  AD_TB_BT, // SFB
  AD_DBC_LBS,
  AD_GBC_MBS,
  AD_TBC_BTS, // doubts, SFB
  AD_BTC_BTS, // doubts

  // Vowel SFB adaptives
  AD_AH_AU,
  AD_EH_EO,
  AD_IH_YI,
  AD_UH_UA,
  AU_OH_OE,
  AD_JH_JI,

  // J adaptives
  AD_Jq_JO,
  AD_qJ_OJ, ADAPTIVE_LAST = AD_qJ_OJ,

  MB_LABK, MODBO_FIRST = MB_LABK,
  MB_RABK,
  MB_DIAMOND,
  MB_RPRN,
  MB_PARENS,
  MB_LBRC,
  MB_RBRC,
  MB_SQUARE,
  MB_LCBR,
  MB_RCBR,
  MB_CURLS,
  MB_ARROW_BRACE, MODBO_LAST = MB_ARROW_BRACE,

  ST_COMBO_XW_ZZ,
  ST_COMBO_WG_QU,
  ST_COMBO_WMG_Q,
  ST_COMBO_BSLS,
  ST_COMBO_DOT_QUOTE_COLN,
  ST_COMBO_COMMA_DOT_SCLN,
  ST_COMBO_ASTR,

  ST_COMBO_UNDO,
  ST_COMBO_SELECT,
  ST_COMBO_COPY,
  ST_COMBO_CUT,
  ST_COMBO_PASTE,
};


// Parentheses modifier combos
const uint16_t PROGMEM modboLabk[] = { KC_LPRN, KC_DOT, COMBO_END};
const uint16_t PROGMEM modboRabk[] = { KC_LPRN, KC_QUOTE, COMBO_END};
const uint16_t PROGMEM modboDiamond[] = { KC_LPRN, KC_QUOTE, KC_DOT, COMBO_END};
const uint16_t PROGMEM modboRprn[] = { KC_LPRN, KC_A, COMBO_END};
const uint16_t PROGMEM modboParens[] = { KC_LPRN, KC_E, KC_A, COMBO_END};
const uint16_t PROGMEM modboLbrc[] = { KC_LPRN, KC_U, COMBO_END};
const uint16_t PROGMEM modboRbrc[] = { KC_LPRN, KC_O, COMBO_END};
const uint16_t PROGMEM modboSquare[] = { KC_LPRN, KC_O, KC_U, COMBO_END};
const uint16_t PROGMEM modboLcbr[] = { KC_LPRN, KC_E, COMBO_END};
const uint16_t PROGMEM modboRcbr[] = { KC_LPRN, KC_I, COMBO_END};
const uint16_t PROGMEM modboCurls[] = { KC_LPRN, KC_I, KC_E, COMBO_END};
const uint16_t PROGMEM modboArrowBrace[] = { KC_LPRN, KC_QUOTE, KC_A, COMBO_END};

// Text editing combos
const uint16_t PROGMEM comboUndo[] = { KC_V, KC_P, COMBO_END};
const uint16_t PROGMEM comboSelect[] = { KC_V, KC_L, COMBO_END};
const uint16_t PROGMEM comboCopy[] = { KC_P, KC_D, COMBO_END};
const uint16_t PROGMEM comboCut[] = { KC_V, KC_P, KC_L, COMBO_END};
const uint16_t PROGMEM comboPaste[] = { KC_P, KC_L, KC_D, COMBO_END};

// Top row Symbol combos
const uint16_t PROGMEM comboBsls[] = { KC_J, KC_SLASH, COMBO_END};
const uint16_t PROGMEM comboDotQuote[] = { KC_DOT, KC_QUOTE, COMBO_END};
const uint16_t PROGMEM comboCommaDot[] = { KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM comboAstr[] = { KC_COMMA, KC_A, COMBO_END};
const uint16_t PROGMEM comboExclam[] = { KC_G, KC_DQUO, COMBO_END};
const uint16_t PROGMEM comboHash[] = { KC_AT, KC_DOT, COMBO_END};
const uint16_t PROGMEM comboQuestion[] = { KC_QUOTE, KC_J, COMBO_END};
const uint16_t PROGMEM comboAmpersand[] = { KC_AT, KC_DOT, KC_QUOTE, COMBO_END};
const uint16_t PROGMEM comboPipe[] = { KC_DOT, KC_QUOTE, KC_J, COMBO_END};
const uint16_t PROGMEM comboPercent[] = { KC_QUOTE, KC_J, KC_SLASH, COMBO_END};

// Bigram combo
const uint16_t PROGMEM comboWM[] = { KC_W, KC_M, COMBO_END};
const uint16_t PROGMEM comboGM[] = { KC_M, KC_G, COMBO_END};
const uint16_t PROGMEM comboST[] = { KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM comboCN[] = { KC_C, KC_N, COMBO_END};
const uint16_t PROGMEM comboTN[] = { KC_N, KC_T, COMBO_END};
const uint16_t PROGMEM comboPN[] = { KC_P, KC_N, COMBO_END};

const uint16_t PROGMEM comboXW[] = { LT(0, KC_X), KC_W, COMBO_END};
const uint16_t PROGMEM comboWG[] = { KC_W, KC_G, COMBO_END };
const uint16_t PROGMEM comboWMG[] = { KC_W, KC_M, KC_G, COMBO_END };

// Line combos
const uint16_t PROGMEM combo35[] = { KC_MINUS, KC_U, COMBO_END};
const uint16_t PROGMEM combo36[] = { KC_MINUS, KC_O, COMBO_END};
const uint16_t PROGMEM combo37[] = { KC_A, KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM combo38[] = { KC_MINUS, KC_U, KC_O, COMBO_END};
const uint16_t PROGMEM combo39[] = { KC_MINUS, KC_A, KC_O, COMBO_END};
const uint16_t PROGMEM combo40[] = { KC_MINUS, KC_E, KC_Y, COMBO_END};
const uint16_t PROGMEM combo41[] = { KC_U, KC_O, KC_Y, COMBO_END};

// Control combos
const uint16_t PROGMEM combo42[] = { KC_S, KC_C, KC_N, COMBO_END};
const uint16_t PROGMEM combo43[] = { KC_C, KC_N, KC_T, COMBO_END};
const uint16_t PROGMEM combo44[] = { KC_N, KC_T, KC_K, COMBO_END};

const uint16_t PROGMEM adaptiveWM[] = { KC_W, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveMW[] = { KC_M, KC_W, COMBO_END };
const uint16_t PROGMEM adaptiveMG[] = { KC_M, KC_G, COMBO_END };
const uint16_t PROGMEM adaptiveMC[] = { KC_M, KC_C, COMBO_END };
const uint16_t PROGMEM adaptiveCM[] = { KC_C, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveMT[] = { KC_M, KC_T, COMBO_END };
const uint16_t PROGMEM adaptiveTM[] = { KC_T, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveGM[] = { KC_G, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveDM[] = { KC_D, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveVC[] = { KC_V, KC_C, COMBO_END };

// F adaptives
// L@G N@T S@C W@M
const uint16_t PROGMEM adaptiveGF[] = { KC_G, KC_F, COMBO_END };
const uint16_t PROGMEM adaptiveFG[] = { KC_F, KC_G, COMBO_END };
const uint16_t PROGMEM adaptiveTF[] = { KC_T, KC_F, COMBO_END };
// Need FT for after, ooft, etc.
const uint16_t PROGMEM adaptiveCF[] = { KC_C, KC_F, COMBO_END };
const uint16_t PROGMEM adaptiveFC[] = { KC_F, KC_C, COMBO_END };
const uint16_t PROGMEM adaptiveMF[] = { KC_M, KC_F, COMBO_END };
const uint16_t PROGMEM adaptiveFM[] = { KC_F, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveGFC[] = { KC_G, KC_F, KC_C, COMBO_END };
const uint16_t PROGMEM adaptiveTFC[] = { KC_T, KC_F, KC_C, COMBO_END };

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
const uint16_t PROGMEM adaptiveGB[] = { KC_G, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveBG[] = { KC_B, KC_G, COMBO_END };
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
const uint16_t PROGMEM adaptiveTB[] = { KC_T, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveDBC[] = { KC_D, KC_B, KC_C, COMBO_END };
const uint16_t PROGMEM adaptiveGBC[] = { KC_G, KC_B, KC_C, COMBO_END };
const uint16_t PROGMEM adaptiveBTC[] = { KC_B, KC_T, KC_C, COMBO_END };
const uint16_t PROGMEM adaptiveTBC[] = { KC_T, KC_B, KC_C, COMBO_END };

// Vowel SFB adaptives
const uint16_t PROGMEM adaptiveAH[] = { KC_A, KC_H, COMBO_END };
const uint16_t PROGMEM adaptiveEH[] = { KC_E, KC_H, COMBO_END };
const uint16_t PROGMEM adaptiveIH[] = { KC_I, KC_H, COMBO_END };
const uint16_t PROGMEM adaptiveUH[] = { KC_U, KC_H, COMBO_END };
const uint16_t PROGMEM adaptiveOH[] = { KC_O, KC_H, COMBO_END };
const uint16_t PROGMEM adaptiveJH[] = { KC_J, KC_H, COMBO_END };

// J adaptives
const uint16_t PROGMEM adaptiveJq[] = { KC_J, KC_QUOTE, COMBO_END };
const uint16_t PROGMEM adaptiveqJ[] = { KC_QUOTE, KC_J, COMBO_END };

combo_t key_combos[] = {
  [AD_WM_WL] = COMBO(adaptiveWM, AD_MACRO_WL),
  [AD_MW_MP] = COMBO(adaptiveMW, AD_MACRO_MP),
  [AD_MG_LG] = COMBO(adaptiveMG, AD_MACRO_LG),
  [AD_MC_ML] = COMBO(adaptiveMC, AD_MACRO_ML),
  [AD_CM_LM] = COMBO(adaptiveCM, AD_MACRO_LM),
  [AD_MT_MN] = COMBO(adaptiveMT, AD_MACRO_MN),
  [AD_TM_NM] = COMBO(adaptiveTM, AD_MACRO_NM),
  [AD_GM_GL] = COMBO(adaptiveGM, AD_MACRO_GL),
  [AD_DM_DG] = COMBO(adaptiveDM, AD_MACRO_DG),
  [AD_VC_VS] = COMBO(adaptiveVC, AD_MACRO_VS),

  // F adaptives
  // L@G N@T S@C W@M
  [AD_GF_LF] = COMBO(adaptiveGF, AD_MACRO_LF),
  [AD_FG_FL] = COMBO(adaptiveFG, AD_MACRO_FL),
  [AD_TF_NF] = COMBO(adaptiveTF, AD_MACRO_NF),
  // Need FT for after, ooft, etc.
  [AD_CF_SF] = COMBO(adaptiveCF, AD_MACRO_SF),
  [AD_FC_FS] = COMBO(adaptiveFC, AD_MACRO_FS),
  [AD_MF_WF] = COMBO(adaptiveMF, AD_MACRO_WF),
  [AD_FM_FW] = COMBO(adaptiveFM, AD_MACRO_FW),
  [AD_GFC_LFS] = COMBO(adaptiveGFC, AD_MACRO_LFS),
  [AD_TFC_NFS] = COMBO(adaptiveTFC, AD_MACRO_NFS),

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
  // L@D S@C C@N M@G P@L V@P
  [AD_GB_MB] = COMBO(adaptiveGB, AD_MACRO_MB),
  [AD_BG_BM] = COMBO(adaptiveBG, AD_MACRO_BM),
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
  [AD_TB_BT] = COMBO(adaptiveTB, AD_MACRO_BT),
  [AD_DBC_LBS] = COMBO(adaptiveDBC, AD_MACRO_LBS),
  [AD_GBC_MBS] = COMBO(adaptiveGBC, AD_MACRO_MBS),
  [AD_BTC_BTS] = COMBO(adaptiveBTC, AD_MACRO_BTS),
  [AD_TBC_BTS] = COMBO(adaptiveTBC, AD_MACRO_BTS),

  // Vowel SFB adaptives
  [AD_AH_AU] = COMBO(adaptiveAH, AD_MACRO_AU),
  [AD_EH_EO] = COMBO(adaptiveEH, AD_MACRO_EO),
  [AD_IH_YI] = COMBO(adaptiveIH, AD_MACRO_YI),
  [AD_UH_UA] = COMBO(adaptiveUH, AD_MACRO_UA),
  [AU_OH_OE] = COMBO(adaptiveOH, AD_MACRO_OE),
  [AD_JH_JI] = COMBO(adaptiveJH, AD_MACRO_JI),

  // J adaptives
  [AD_Jq_JO] = COMBO(adaptiveJq, AD_MACRO_JO),
  [AD_qJ_OJ] = COMBO(adaptiveqJ, AD_MACRO_OJ),

  // Parentheses modifier combos
  // TODO rework brackets
  [MB_LABK] = COMBO(modboLabk, KC_LABK),
  [MB_RABK] = COMBO(modboRabk, KC_RABK),
  [MB_DIAMOND] = COMBO(modboDiamond, MB_MACRO_DIAMOND),
  [MB_RPRN] = COMBO(modboRprn, KC_RPRN),
  [MB_PARENS] = COMBO(modboParens, MB_MACRO_PARENS),
  [MB_LBRC] = COMBO(modboLbrc, KC_LBRC),
  [MB_RBRC] = COMBO(modboRbrc, KC_RBRC),
  [MB_SQUARE] = COMBO(modboSquare, MB_MACRO_SQUARE),
  [MB_LCBR] = COMBO(modboLcbr, KC_LCBR),
  [MB_RCBR] = COMBO(modboRcbr, KC_RCBR),
  [MB_CURLS] = COMBO(modboCurls, MB_MACRO_CURLS),
  [MB_ARROW_BRACE] = COMBO(modboArrowBrace, MB_MACRO_ARROW_BRACE),

  // !!! UNSORTED !!!
  [ST_COMBO_WG_QU] = COMBO(comboWG, ST_MACRO_QU),
  [ST_COMBO_XW_ZZ] = COMBO(comboXW, ST_MACRO_ZZ),
  [ST_COMBO_WMG_Q] = COMBO(comboWMG, KC_Q),
  [ST_COMBO_BSLS] = COMBO(comboBsls, KC_BSLS),
  [ST_COMBO_DOT_QUOTE_COLN] = COMBO(comboDotQuote, KC_COLN),
  [ST_COMBO_COMMA_DOT_SCLN] = COMBO(comboCommaDot, KC_SCLN),
  [ST_COMBO_ASTR] = COMBO(comboAstr, KC_ASTR),

  // Text editing combos
  [ST_COMBO_UNDO] = COMBO(comboUndo, LCTL(KC_Z)),
  [ST_COMBO_SELECT] = COMBO(comboSelect, LCTL(KC_A)),
  [ST_COMBO_COPY] = COMBO(comboCopy, LCTL(KC_C)),
  [ST_COMBO_CUT] = COMBO(comboCut, LCTL(KC_X)),
  [ST_COMBO_PASTE] = COMBO(comboPaste, LCTL(KC_V)),

  // Top row symbol combos
  // TODO redefine top row combos
  COMBO(comboExclam, KC_EXLM),
  COMBO(comboHash, KC_HASH),
  COMBO(comboQuestion, KC_QUES),
  COMBO(comboAmpersand, KC_AMPR),
  COMBO(comboPipe, KC_PIPE),
  COMBO(comboPercent, KC_PERC),

  // Bigram combos
  COMBO(comboWM, ST_MACRO_WH),
  COMBO(comboGM, ST_MACRO_GH),
  COMBO(comboST, ST_MACRO_SH),
  COMBO(comboCN, ST_MACRO_CH),
  COMBO(comboTN, ST_MACRO_TH),
  COMBO(comboPN, ST_MACRO_PH),

  // Line combos
  COMBO(combo35, KC_PLUS),
  COMBO(combo36, KC_EQUAL),
  COMBO(combo37, KC_UNDS),
  COMBO(combo38, KC_TILD),
  COMBO(combo39, KC_CIRC),
  COMBO(combo40, KC_DLR),
  COMBO(combo41, KC_GRAVE),

  // Control combos
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

inline bool is_modbo(uint16_t index) {
  switch (index) {
  case MODBO_FIRST ... MODBO_LAST: return true;
  default: return false;
  }
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
  return is_adaptive(index) ? ADAPTIVE_TERM
  : is_modbo(index) ? MODBO_TERM
  : COMBO_TERM;
}

bool get_combo_must_press_in_order(uint16_t index, combo_t *combo) {
  return is_adaptive(index) || is_modbo(index);
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
    return true; \

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    SEND_CASED_STRINGS(ST_MACRO_ZZ, "zz", "Zz", "ZZ");
    SEND_CASED_STRINGS(ST_MACRO_QU, "qu", "Qu", "QU");
    SEND_CASED_STRINGS(AD_MACRO_WL, "wl", "Wl", "WL");
    SEND_CASED_STRINGS(AD_MACRO_MP, "mp", "Mp", "MP");
    SEND_CASED_STRINGS(AD_MACRO_LG, "lg", "Lg", "LG");
    SEND_CASED_STRINGS(AD_MACRO_ML, "ml", "Ml", "ML");
    SEND_CASED_STRINGS(AD_MACRO_LM, "lm", "Lm", "LM");
    SEND_CASED_STRINGS(AD_MACRO_MN, "mn", "Mn", "MN");
    SEND_CASED_STRINGS(AD_MACRO_NM, "nm", "Nm", "NM");
    SEND_CASED_STRINGS(AD_MACRO_GL, "gl", "Gl", "GL");
    SEND_CASED_STRINGS(AD_MACRO_DG, "dg", "Dg", "DG");
    SEND_CASED_STRINGS(AD_MACRO_VS, "vs", "Vs", "VS");

  // F adaptives
  // L@G N@T S@C W@M
  // Need FT for after, ooft, etc.
    SEND_CASED_STRINGS(AD_MACRO_LF, "lf", "Lf", "LF");
    SEND_CASED_STRINGS(AD_MACRO_FL, "fl", "Fl", "FL");
    SEND_CASED_STRINGS(AD_MACRO_NF, "nf", "Nf", "NF");
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
  // L@D S@C C@N M@G
    SEND_CASED_STRINGS(AD_MACRO_MB, "mb", "Mb", "MB");
    SEND_CASED_STRINGS(AD_MACRO_BM, "bm", "Bm", "BM");
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
    SEND_CASED_STRINGS(AD_MACRO_BT, "bt", "Bt", "BT");
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

  // Symbol macros
  case MB_MACRO_DIAMOND:
    if (record->event.pressed) {
      SEND_STRING("<>");
    }
    return true;
  case MB_MACRO_PARENS:
    if (record->event.pressed) {
      SEND_STRING("()");
    }
    return true;
  case MB_MACRO_SQUARE:
    if (record->event.pressed) {
      SEND_STRING("[]");
    }
    return true;
  case MB_MACRO_CURLS:
    if (record->event.pressed) {
      SEND_STRING("{}");
    }
    return true;
  case MB_MACRO_ARROW_BRACE:
    if (record->event.pressed) {
      SEND_STRING("=> {");
    }
    return true;
  case ST_MACRO_FULL_STOP:
    if (record->event.pressed) {
      SEND_STRING_CLEAR(". ");
    }
    return true;

  case LT(0, KC_X):
    if (!record->tap.count && record->event.pressed) {
      SEND_STRINGS("z", "Z", "Z");
      return true;
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

#define BASE_COLOUR {93,255,191}
#define NUM_COLOUR {36,255,193}
#define NUMPAD_COLOUR {52,255,193}
#define FN_COLOUR {203,196,165}
#define FIRMWARE_COLOUR {8,235,250}
#define LEFT_COLOUR {101,206,157}
#define MOD_COLOUR {86,255,204}
#define OFF_COLOUR {0,0,0}

#define TAP_HOLD_COLOUR {128,242,161}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [_BASE] = { BASE_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, LEFT_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, FN_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, NUM_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, MOD_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, OFF_COLOUR, OFF_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, MOD_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, FN_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, MOD_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, OFF_COLOUR, OFF_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR },

    [_LMOD] = { MOD_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, MOD_COLOUR, OFF_COLOUR, OFF_COLOUR, MOD_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, MOD_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, MOD_COLOUR, OFF_COLOUR, {67,180,255}, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, MOD_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, BASE_COLOUR, OFF_COLOUR, BASE_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, OFF_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, BASE_COLOUR, BASE_COLOUR, OFF_COLOUR, OFF_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, MOD_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, BASE_COLOUR, OFF_COLOUR, OFF_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR },

    [_RMOD] = { BASE_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, OFF_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, OFF_COLOUR, OFF_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, OFF_COLOUR, OFF_COLOUR, BASE_COLOUR, BASE_COLOUR, BASE_COLOUR, MOD_COLOUR, OFF_COLOUR, OFF_COLOUR, BASE_COLOUR, OFF_COLOUR, BASE_COLOUR, OFF_COLOUR, OFF_COLOUR, BASE_COLOUR, TAP_HOLD_COLOUR, BASE_COLOUR, BASE_COLOUR, MOD_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, MOD_COLOUR, OFF_COLOUR, OFF_COLOUR, MOD_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, MOD_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, MOD_COLOUR, OFF_COLOUR, {67,180,255}, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, MOD_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, MOD_COLOUR, OFF_COLOUR },

    [_NUM] = { NUM_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, BASE_COLOUR, OFF_COLOUR, NUM_COLOUR, NUM_COLOUR, NUM_COLOUR, NUM_COLOUR, OFF_COLOUR, NUM_COLOUR, TAP_HOLD_COLOUR, NUM_COLOUR, FN_COLOUR, OFF_COLOUR, NUM_COLOUR, TAP_HOLD_COLOUR, NUM_COLOUR, BASE_COLOUR, OFF_COLOUR, NUM_COLOUR, TAP_HOLD_COLOUR, NUM_COLOUR, MOD_COLOUR, OFF_COLOUR, NUM_COLOUR, NUM_COLOUR, NUM_COLOUR, NUM_COLOUR, OFF_COLOUR, OFF_COLOUR, NUMPAD_COLOUR, NUM_COLOUR, NUM_COLOUR, OFF_COLOUR, NUM_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, BASE_COLOUR, OFF_COLOUR, NUM_COLOUR, NUM_COLOUR, NUM_COLOUR, NUM_COLOUR, OFF_COLOUR, NUM_COLOUR, NUM_COLOUR, NUM_COLOUR, NUM_COLOUR, OFF_COLOUR, NUM_COLOUR, NUM_COLOUR, NUM_COLOUR, TAP_HOLD_COLOUR, OFF_COLOUR, NUM_COLOUR, NUM_COLOUR, NUM_COLOUR, NUM_COLOUR, OFF_COLOUR, NUM_COLOUR, NUM_COLOUR, NUM_COLOUR, NUM_COLOUR, OFF_COLOUR, OFF_COLOUR, NUM_COLOUR, NUM_COLOUR, NUM_COLOUR, NUM_COLOUR },

    [_NUMPAD] = { NUMPAD_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, BASE_COLOUR, OFF_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, OFF_COLOUR, NUMPAD_COLOUR, TAP_HOLD_COLOUR, NUMPAD_COLOUR, FN_COLOUR, OFF_COLOUR, NUMPAD_COLOUR, TAP_HOLD_COLOUR, NUMPAD_COLOUR, BASE_COLOUR, OFF_COLOUR, NUMPAD_COLOUR, TAP_HOLD_COLOUR, NUMPAD_COLOUR, MOD_COLOUR, OFF_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, OFF_COLOUR, OFF_COLOUR, NUM_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, OFF_COLOUR, NUMPAD_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, BASE_COLOUR, OFF_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, OFF_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, OFF_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, OFF_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, OFF_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, OFF_COLOUR, OFF_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR, NUMPAD_COLOUR },

    [_FN] = { FN_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, BASE_COLOUR, FN_COLOUR, FN_COLOUR, {102,255,143}, {102,255,143}, FN_COLOUR, FN_COLOUR, FN_COLOUR, TAP_HOLD_COLOUR, FN_COLOUR, BASE_COLOUR, FN_COLOUR, FN_COLOUR, TAP_HOLD_COLOUR, FN_COLOUR, NUM_COLOUR, FN_COLOUR, FN_COLOUR, TAP_HOLD_COLOUR, FN_COLOUR, MOD_COLOUR, FN_COLOUR, FN_COLOUR, FN_COLOUR, FN_COLOUR, FN_COLOUR, FN_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, FN_COLOUR, OFF_COLOUR, FN_COLOUR, {102,255,143}, {102,255,143}, FN_COLOUR, BASE_COLOUR, FN_COLOUR, {102,255,143}, FN_COLOUR, FN_COLOUR, FN_COLOUR, FN_COLOUR, {102,255,143}, FN_COLOUR, FN_COLOUR, MOD_COLOUR, FN_COLOUR, {102,255,143}, FN_COLOUR, FN_COLOUR, {67,180,255}, FN_COLOUR, {102,255,143}, FN_COLOUR, FN_COLOUR, MOD_COLOUR, FN_COLOUR, FN_COLOUR, FN_COLOUR, FN_COLOUR, FN_COLOUR, FN_COLOUR, FN_COLOUR, FN_COLOUR, FN_COLOUR, FN_COLOUR, FN_COLOUR },

    [_LEFT] = { LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR, {237,234,175}, MOD_COLOUR, LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR, MOD_COLOUR, LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR, MOD_COLOUR, LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR, MOD_COLOUR, LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR, LEFT_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, BASE_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR },

    [_LFN] = { {237,234,175}, {237,234,175}, {237,234,175}, MOD_COLOUR, {67,180,255}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, MOD_COLOUR, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, MOD_COLOUR, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, MOD_COLOUR, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, MOD_COLOUR, {237,234,175}, OFF_COLOUR, FIRMWARE_COLOUR, {237,234,175}, {237,234,175}, {237,234,175}, OFF_COLOUR, {253,174,200}, {253,174,200}, {253,174,200}, MOD_COLOUR, OFF_COLOUR, {253,174,200}, {253,174,200}, {253,174,200}, MOD_COLOUR, OFF_COLOUR, {253,174,200}, {253,174,200}, {188,255,180}, FIRMWARE_COLOUR, OFF_COLOUR, {253,174,200}, {253,174,200}, {12,255,186}, {237,234,175}, FIRMWARE_COLOUR, FIRMWARE_COLOUR, OFF_COLOUR, BASE_COLOUR, {237,234,175}, {237,234,175} },

    [_FIRMWARE] = { FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, BASE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, OFF_COLOUR, {0,255,255}, OFF_COLOUR, FIRMWARE_COLOUR, {0,255,255}, OFF_COLOUR, OFF_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, BASE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, OFF_COLOUR, OFF_COLOUR, OFF_COLOUR, FIRMWARE_COLOUR, {67,180,255}, OFF_COLOUR, {172,255,255}, OFF_COLOUR, FIRMWARE_COLOUR, {172,255,255}, OFF_COLOUR, OFF_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR, FIRMWARE_COLOUR }
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
