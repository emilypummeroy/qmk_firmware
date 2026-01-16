#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE,

  ST_FORCE_EQUAL,
  ST_FORCE_S,

  ST_MACRO_WH, KC_ALNUM_MACRO_FIRST = ST_MACRO_WH,
  ST_MACRO_GH,
  ST_MACRO_SH,
  ST_MACRO_CH,
  ST_MACRO_TH,
  ST_MACRO_PH,

  AD_MACRO_XP,
  AD_MACRO_ZZ,
  AD_MACRO_QU,
  AD_MACRO_WQ,
  AD_MACRO_SS,
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
  AD_MACRO_VS,
  AD_MACRO_ZZL,
  // Maybe Mc would be convenient

  // F adaptives
  // L@G S@C W@M
  AD_MACRO_LF,
  AD_MACRO_FL,
  AD_MACRO_SF,
  AD_MACRO_FS,
  AD_MACRO_WF,
  AD_MACRO_FW,
  AD_MACRO_LFS,
  AD_MACRO_NFS,

  // K adaptives
  // S@P C@N N@T L@G P@L
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
  // L@D S@P C@N M@G P@L V@C
  AD_MACRO_MB,
  AD_MACRO_VB,
  AD_MACRO_BV,
  AD_MACRO_LB,
  AD_MACRO_BL,
  AD_MACRO_PB,
  AD_MACRO_BP,
  AD_MACRO_SB,
  AD_MACRO_BS,
  AD_MACRO_CB,
  AD_MACRO_BC, // ribcage
  AD_MACRO_LBS,
  AD_MACRO_MBS,
  AD_MACRO_BTS, // doubts

  // H digraph adaptives
  AD_MACRO_LCH,
  AD_MACRO_CHL,
  AD_MACRO_NCH, // Winch
  AD_MACRO_TCH, // Witch
  AD_MACRO_NTH, // Tenth
  AD_MACRO_LTH,
  AD_MACRO_THL,
  AD_MACRO_SHN,
  AD_MACRO_NSH,
  AD_MACRO_LSH,
  AD_MACRO_SHL,
  AD_MACRO_GHN, // Toughness
  AD_MACRO_GHT, // Thought
  AD_MACRO_SPH, // Sphere
  AD_MACRO_MPH, // Emphasis

  // Vowel SFB adaptives
  AD_MACRO_AU,
  AD_MACRO_EO,
  AD_MACRO_UA,
  AD_MACRO_OE,
  AD_MACRO_YI,
  AD_MACRO_Eq,
  AD_MACRO_HEq,
  AD_MACRO_IEq,
  AD_MACRO_YEq,

  // J adaptives
  AD_MACRO_JI,
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
    XXXXXXX,        KC_7,           KC_3,           KC_1,           KC_5,           KC_9,           XXXXXXX,                                        XXXXXXX,        KC_6,           KC_2,           KC_0,           KC_4,           KC_8,           XXXXXXX,
    KC_GRAVE,       LT(0, KC_X),    KC_W,           KC_M,           KC_G,           KC_F,           KC_DELETE,                                      KC_INSERT,      KC_SCLN,        KC_DOT,         KC_QUOTE,       KC_J,           KC_BSLS,        XXXXXXX,
    KC_TAB,         KC_V,           KC_C,           KC_N,           KC_T,           KC_K,           KC_BACKSPACE,                                   KC_DELETE,      KC_COMMA,       KC_A,           KC_E,           KC_I,           KC_SLASH,       XXXXXXX,
    XXXXXXX,        KC_S,           KC_P,           KC_L,           KC_D,           KC_B,                                                                           KC_MINUS,       KC_U,           KC_O,           KC_Y,           KC_H,           XXXXXXX,
    TO(_LEFT),      XXXXXXX,        MO(_FN),        MO(_NUM),       LM(_LMOD,MOD_LSFT),             KC_ESCAPE,                                      RCTL(KC_BSPC),             LM(_RMOD,MOD_RSFT),  MO(_FN),        CW_TOGG,        XXXXXXX,        XXXXXXX,
    KC_R,           KC_ENTER,         XXXXXXX,                        XXXXXXX,        KC_ENTER,       KC_SPACE
  ),

  [_LMOD] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______,
    XXXXXXX,        KC_CIRC,        KC_QUES,        KC_EXLM,        KC_PERC,        KC_AT,          _______,                                        _______,        _______,        _______,        _______,        _______,        KC_DLR,         _______,
    _______,        XXXXXXX,        KC_LGUI,        KC_LALT,        KC_LCTL,        XXXXXXX,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______,
    _______,        ST_FORCE_S,     ST_FORCE_EQUAL, KC_LCBR,        KC_RCBR,        XXXXXXX,                                                                        _______,        _______,        _______,        _______,        _______,        _______,
    XXXXXXX,        _______,        XXXXXXX,        XXXXXXX,        _______,                        _______,                                        KC_BSPC,                        OSM(MOD_RSFT),  _______,        _______,        _______,        _______,
    XXXXXXX,        XXXXXXX,        _______,                        _______,        _______,        _______
  ),

  [_RMOD] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        KC_HASH,        KC_RPRN,        KC_AMPR,        KC_PIPE,        KC_DLR,         _______,
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        KC_LPRN,        KC_RCTL,        KC_RALT,        KC_RGUI,        _______,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,                                                                        _______,        XXXXXXX,        XXXXXXX,        XXXXXXX,        ST_FORCE_EQUAL, _______,
    XXXXXXX,        _______,        XXXXXXX,        XXXXXXX,        KC_SPACE,                       _______,                                        KC_BSPC,                        _______,        _______,        _______,        _______,        _______,
    KC_R,           _______,        _______,                        _______,        XXXXXXX,        XXXXXXX
  ),

  [_NUM] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______,
    _______,        KC_CIRC,        KC_QUES,        KC_EXLM,        KC_PERC,        KC_AT,          _______,                                        TO(_NUMPAD),    KC_ASTR,        KC_7,           KC_8,           KC_9,           KC_DLR,         _______,
    _______, KC_COMMA, MT(MOD_LGUI,KC_LEFT), MT(MOD_LALT,KC_UP), MT(MOD_LCTL,KC_DOWN), KC_RIGHT,    _______,                                        _______,        KC_PLUS,        KC_4,           KC_5,           KC_6,           _______,        _______,
    _______,        KC_LPRN,        KC_EQUAL,       KC_LBRC,        KC_RBRC,        KC_RPRN,                                                                        KC_MINUS,       KC_1,           KC_2,           KC_3,           KC_EQUAL,       _______,
    TO(0),          _______,        TO(_FN),        TO(0),          KC_LEFT_SHIFT,                  _______,                                        KC_BSPC,                        KC_DOT,         KC_0,           KC_EQUAL,       _______,        TO(0),
    TO(_NUMPAD),    _______,        _______,                        _______,        KC_ENTER,       _______
  ),

  [_NUMPAD] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        KC_NUM,         KC_KP_ASTERISK, KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_DLR,         _______,
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        KC_KP_PLUS,     KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_SLASH,    _______,
    _______,        KC_LPRN,        KC_EQUAL,       KC_LBRC,        KC_RBRC,        KC_RPRN,                                                                        KC_KP_MINUS,    KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_EQUAL,    _______,
    TO(0),          _______,        TO(_FN),        TO(0),          KC_LEFT_SHIFT,                  _______,                                        KC_BSPC,                        KC_KP_DOT,      KC_KP_0,        KC_KP_EQUAL,    _______,        TO(0),
    TO(_NUM),       KC_KP_COMMA,    _______,                        _______,        KC_KP_ENTER,    _______
  ),

  [_FN] = LAYOUT_moonlander(
    _______,        KC_F14,         KC_F12,         KC_F11,         KC_F10,         KC_F15,         _______,                                        _______,        KC_F16,         KC_F17,         KC_F18,         KC_F19,         KC_F20,         _______,
    _______,        KC_F13,         KC_F9,          KC_F8,          KC_F7,          KC_F23,         KC_F24,                                         KC_INSERT,      KC_ESCAPE,      KC_MNXT,        KC_MPRV,        KC_MPLY,        KC_MUTE,        KC_VOLU,
    _______,        KC_BRIU,    MT(MOD_LGUI, KC_F6),MT(MOD_LALT, KC_F5),MT(MOD_LCTL, KC_F4),KC_F22, _______,                                        KC_DELETE,      KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TAB,         KC_VOLD,
    _______,        KC_BRID,        KC_F3,       KC_F2,          KC_F1,          KC_F21,                                                                         KC_HOME,        KC_PGDN,        KC_PAGE_UP,     KC_END,         LCTL(KC_G),     KC_WWW_SEARCH,
    TO(0),          _______,        TO(0),          TO(_NUM),       KC_LEFT_SHIFT,                  _______,                                        KC_BSPC,                        KC_RIGHT_SHIFT, TO(0),          _______,        _______,        TO(0),
    _______,        _______,        _______,                        _______,        _______,        _______
  ),

  [_LEFT] = LAYOUT_moonlander(
    _______,        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           _______,                                        _______,        KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           _______,
    KC_GRAVE,       KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_LBRC,                                        KC_RBRC,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_MINUS,
    KC_TAB,         KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,                                           KC_EQUAL,       KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,
    MO(_LFN),       KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RIGHT_CTRL,
    KC_LEFT_ALT,    _______,        KC_LEFT_GUI,    KC_LEFT_CTRL,   KC_LEFT_SHIFT,                  KC_ESCAPE,                                      KC_BSPC,                        KC_RIGHT_SHIFT, KC_RIGHT_ALT,   KC_RIGHT_GUI,   _______,        TO(0),
    KC_SPACE,       KC_ENTER,       _______,                        _______,        _______,        _______
  ),

  [_LFN] = LAYOUT_moonlander(
    _______,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______,
    KC_DELETE,      KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_U,                                           DT_UP,          UG_VALU,        UG_VALU,        UG_VALU,        UG_VALU,        DT_PRNT,        KC_SCRL,
    KC_BSPC,        KC_F11,         KC_LEFT,        KC_UP,          KC_DOWN,        KC_RIGHT,       KC_L,                                           DT_DOWN,        UG_VALD,        UG_VALD,        UG_VALD,        UG_VALD,        KC_PAUSE,       KC_PSCR,
    KC_RIGHT_ALT,   KC_F12,         KC_HOME,        KC_PAGE_UP,     KC_PGDN,        KC_END,                                                                         CM_OFF,         CM_ON,          LED_LEVEL,      AU_TOGG,        KC_BSLS,        KC_RIGHT_CTRL,
    _______,        _______,        KC_RIGHT_GUI,   KC_RIGHT_CTRL,  KC_LEFT_SHIFT,                  KC_ESCAPE,                                      KC_BSPC,                        MO(_FIRMWARE),  _______,        _______,        _______,        KC_CAPS,
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
  AD_XW_XP, ADAPTIVE_FIRST = AD_XW_XP,
  AD_XG_ZZ,
  AD_KM_QU,
  AD_MTK_WQ,
  AD_SD_SS,
  AD_MG_LG,
  AD_MC_ML,
  AD_CM_LM,
  AD_PN_LN,
  AD_NP_NL,
  AD_MT_MN,
  AD_TM_NM,
  AD_GM_GL,
  AD_DM_DG,
  AD_MD_GD,
  AD_VC_VS,
  AD_XMG_ZZL, // Rizzler

  // F adaptives
  // L@G S@C W@M
  AD_GF_LF,
  AD_FG_FL,
  AD_CF_SF,
  AD_FC_FS,
  AD_MF_WF,
  AD_FM_FW,
  AD_TFC_LFS,
  AD_NFC_NFS,

  // K adaptives
  // S@C C@N N@T L@G P@L
  AD_GK_LK,
  AD_KG_KL,
  AD_NK_CK,
  AD_KN_KC,
  AD_PK_SK,
  AD_KP_KS,
  AD_TK_NK,
  AD_KT_KN,
  AD_LK_PK,
  AD_KL_KP,
  AD_GKC_LKS,
  AD_NKP_CKS,
  AD_TKP_NKS,
  AD_NKG_CKL, // cackle

  // B adaptives
  // L@D S@C C@N M@T P@L V@P
  AD_GB_MB,
  AD_CB_VB,
  AD_BC_BV,
  AD_DB_LB,
  AD_BD_BL,
  AD_LB_PB,
  AD_BL_BP,
  AD_PB_SB,
  AD_BP_BS,
  AD_NB_CB,
  AD_BN_BC, // ribcage
  AD_DBP_LBS,
  AD_GBP_MBS,
  AD_BTP_BTS, // doubts

  // H digraph adaptives
  AD_DCN_LCH,
  AD_CND_CHL,
  AD_VCN_NCH, // Winch
  AD_TNC_TCH, // Witch
  AD_CNT_NTH, // Tenth
  AD_PTN_LTH,
  AD_TNP_THL,
  AD_BDN_SHN,
  AD_NDB_NSH,
  AD_LDB_LSH,
  AD_BDL_SHL,
  AD_WMG_GHN,
  AD_WMT_GHT,
  AD_CGF_SPH,
  AD_MGF_MPH,

  // Vowel SFB adaptives
  AD_Am_AU,
  AD_Ac_EO,
  AD_Oc_YI,
  AD_Uc_UA,
  AD_Um_OE,
  AD_Ed_Eq,
  AD_HEd_HEq,
  AD_IEd_IEq,
  AD_YEd_YEq,

  // J adaptives
  AD_qI_JI,
  AD_Jq_JO,
  AD_qJ_OJ, ADAPTIVE_LAST = AD_qJ_OJ,

  // Miscellaneous consonants
  ST_COMBO_NTK_Q,

  // H Bigram combos
  ST_COMBO_WM,
  ST_COMBO_GM,
  ST_COMBO_DB,
  ST_COMBO_CN,
  ST_COMBO_TN,
  ST_COMBO_GF,
};

// Bigram combo
const uint16_t PROGMEM comboWM[] = { KC_W, KC_M, COMBO_END};
const uint16_t PROGMEM comboGM[] = { KC_M, KC_G, COMBO_END};
const uint16_t PROGMEM comboDB[] = { KC_D, KC_B, COMBO_END};
const uint16_t PROGMEM comboCN[] = { KC_C, KC_N, COMBO_END};
const uint16_t PROGMEM comboTN[] = { KC_N, KC_T, COMBO_END};
const uint16_t PROGMEM comboGF[] = { KC_G, KC_F, COMBO_END};

// Miscellaneous consonants
const uint16_t PROGMEM comboNTK[] = { KC_N, KC_T, KC_K, COMBO_END };

const uint16_t PROGMEM adaptiveXW[] = { LT(0, KC_X), KC_W, COMBO_END };
const uint16_t PROGMEM adaptiveXG[] = { LT(0, KC_X), KC_G, COMBO_END };
const uint16_t PROGMEM adaptiveKM[] = { KC_K, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveMTK[] = { KC_M, KC_T, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveSD[] = { KC_S, KC_D, COMBO_END };
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
const uint16_t PROGMEM adaptiveXMG[] = { LT(0, KC_X), KC_M, KC_G, COMBO_END };

// F adaptives
// L@G S@C W@M
const uint16_t PROGMEM adaptiveGF[] = { KC_G, KC_F, COMBO_END };
const uint16_t PROGMEM adaptiveFG[] = { KC_F, KC_G, COMBO_END };
const uint16_t PROGMEM adaptiveCF[] = { KC_C, KC_F, COMBO_END };
const uint16_t PROGMEM adaptiveFC[] = { KC_F, KC_C, COMBO_END };
const uint16_t PROGMEM adaptiveMF[] = { KC_M, KC_F, COMBO_END };
const uint16_t PROGMEM adaptiveFM[] = { KC_F, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveTFC[] = { KC_T, KC_F, KC_C, COMBO_END };
const uint16_t PROGMEM adaptiveNFC[] = { KC_N, KC_F, KC_C, COMBO_END };

// K adaptives
// S@C/P C@N N@T L@G P@L
const uint16_t PROGMEM adaptiveGK[] = { KC_G, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveKG[] = { KC_K, KC_G, COMBO_END };
const uint16_t PROGMEM adaptiveNK[] = { KC_N, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveKN[] = { KC_K, KC_N, COMBO_END };
const uint16_t PROGMEM adaptivePK[] = { KC_P, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveKP[] = { KC_K, KC_P, COMBO_END };
const uint16_t PROGMEM adaptiveTK[] = { KC_T, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveKT[] = { KC_K, KC_T, COMBO_END };
const uint16_t PROGMEM adaptiveLK[] = { KC_L, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveKL[] = { KC_K, KC_L, COMBO_END };
const uint16_t PROGMEM adaptiveGKC[] = { KC_G, KC_K, KC_C, COMBO_END };
const uint16_t PROGMEM adaptiveNKP[] = { KC_N, KC_K, KC_P, COMBO_END };
const uint16_t PROGMEM adaptiveTKP[] = { KC_T, KC_K, KC_P, COMBO_END };
const uint16_t PROGMEM adaptiveNKG[] = { KC_N, KC_K, KC_G, COMBO_END };

// B adaptives
// L@D S@P C@N M@G P@L V@C
const uint16_t PROGMEM adaptiveGB[] = { KC_G, KC_B, COMBO_END };
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
const uint16_t PROGMEM adaptiveDBP[] = { KC_D, KC_B, KC_P, COMBO_END };
const uint16_t PROGMEM adaptiveGBP[] = { KC_G, KC_B, KC_P, COMBO_END };
const uint16_t PROGMEM adaptiveBTP[] = { KC_B, KC_T, KC_P, COMBO_END };

// H digraph adaptives
const uint16_t PROGMEM adaptiveDNC[] = { KC_D, KC_N, KC_C, COMBO_END };
const uint16_t PROGMEM adaptiveCND[] = { KC_C, KC_N, KC_D, COMBO_END };
const uint16_t PROGMEM adaptiveVCN[] = { KC_V, KC_C, KC_N, COMBO_END };
const uint16_t PROGMEM adaptiveTNC[] = { KC_T, KC_N, KC_C, COMBO_END };
const uint16_t PROGMEM adaptiveCNT[] = { KC_C, KC_N, KC_T, COMBO_END };
const uint16_t PROGMEM adaptivePNT[] = { KC_P, KC_N, KC_T, COMBO_END };
const uint16_t PROGMEM adaptiveTNP[] = { KC_T, KC_N, KC_P, COMBO_END };
const uint16_t PROGMEM adaptiveBDN[] = { KC_B, KC_D, KC_N, COMBO_END };
const uint16_t PROGMEM adaptiveNDB[] = { KC_N, KC_D, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveLDB[] = { KC_L, KC_D, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveBDL[] = { KC_B, KC_D, KC_L, COMBO_END };
const uint16_t PROGMEM adaptiveWMG[] = { KC_W, KC_M, KC_G, COMBO_END};
const uint16_t PROGMEM adaptiveWMT[] = { KC_W, KC_M, KC_T, COMBO_END};
const uint16_t PROGMEM adaptiveCGF[] = { KC_C, KC_G, KC_F, COMBO_END};
const uint16_t PROGMEM adaptiveMGF[] = { KC_M, KC_G, KC_F, COMBO_END};

// Vowel SFB adaptives
const uint16_t PROGMEM adaptiveAm[] = { KC_A, KC_MINUS, COMBO_END };
const uint16_t PROGMEM adaptiveAc[] = { KC_A, KC_COMMA, COMBO_END };
const uint16_t PROGMEM adaptiveOc[] = { KC_O, KC_COMMA, COMBO_END };
const uint16_t PROGMEM adaptiveUc[] = { KC_U, KC_COMMA, COMBO_END };
const uint16_t PROGMEM adaptiveUm[] = { KC_U, KC_MINUS, COMBO_END };
const uint16_t PROGMEM adaptiveEd[] = { KC_E, KC_DOT, COMBO_END };
const uint16_t PROGMEM adaptiveHEd[] = { KC_H, KC_E, KC_DOT, COMBO_END };
const uint16_t PROGMEM adaptiveIEd[] = { KC_I, KC_E, KC_DOT, COMBO_END };
const uint16_t PROGMEM adaptiveYEd[] = { KC_Y, KC_E, KC_DOT, COMBO_END };

// J adaptives
const uint16_t PROGMEM adaptiveqI[] = { KC_QUOTE, KC_I, COMBO_END };
const uint16_t PROGMEM adaptiveJq[] = { KC_J, KC_QUOTE, COMBO_END };
const uint16_t PROGMEM adaptiveqJ[] = { KC_QUOTE, KC_J, COMBO_END };

combo_t key_combos[] = {
  [AD_XW_XP] = COMBO(adaptiveXW, AD_MACRO_XP),
  [AD_XG_ZZ] = COMBO(adaptiveXG, AD_MACRO_ZZ),
  [AD_KM_QU] = COMBO(adaptiveKM, AD_MACRO_QU),
  [AD_MTK_WQ] = COMBO(adaptiveMTK, AD_MACRO_WQ),
  [AD_SD_SS] = COMBO(adaptiveSD, AD_MACRO_SS),
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
  [AD_VC_VS] = COMBO(adaptiveVC, AD_MACRO_VS),
  [AD_XMG_ZZL] = COMBO(adaptiveXMG, AD_MACRO_ZZL),

  // F adaptives
  // L@G S@C W@M
  [AD_GF_LF] = COMBO(adaptiveGF, AD_MACRO_LF),
  [AD_FG_FL] = COMBO(adaptiveFG, AD_MACRO_FL),
  [AD_CF_SF] = COMBO(adaptiveCF, AD_MACRO_SF),
  [AD_FC_FS] = COMBO(adaptiveFC, AD_MACRO_FS),
  [AD_MF_WF] = COMBO(adaptiveMF, AD_MACRO_WF),
  [AD_FM_FW] = COMBO(adaptiveFM, AD_MACRO_FW),
  [AD_TFC_LFS] = COMBO(adaptiveTFC, AD_MACRO_LFS),
  [AD_NFC_NFS] = COMBO(adaptiveNFC, AD_MACRO_NFS),

  // K adaptives
  // S@P/C C@N N@T L@G P@L
  [AD_GK_LK] = COMBO(adaptiveGK, AD_MACRO_LK),
  [AD_KG_KL] = COMBO(adaptiveKG, AD_MACRO_KL),
  [AD_NK_CK] = COMBO(adaptiveNK, AD_MACRO_CK),
  [AD_KN_KC] = COMBO(adaptiveKN, AD_MACRO_KC),
  [AD_PK_SK] = COMBO(adaptivePK, AD_MACRO_SK),
  [AD_KP_KS] = COMBO(adaptiveKP, AD_MACRO_KS),
  [AD_TK_NK] = COMBO(adaptiveTK, AD_MACRO_NK),
  [AD_KT_KN] = COMBO(adaptiveKT, AD_MACRO_KN),
  [AD_LK_PK] = COMBO(adaptiveLK, AD_MACRO_PK),
  [AD_KL_KP] = COMBO(adaptiveKL, AD_MACRO_KP),
  [AD_GKC_LKS] = COMBO(adaptiveGKC, AD_MACRO_LKS),
  [AD_NKP_CKS] = COMBO(adaptiveNKP, AD_MACRO_CKS),
  [AD_TKP_NKS] = COMBO(adaptiveTKP, AD_MACRO_NKS),
  [AD_NKG_CKL] = COMBO(adaptiveNKG, AD_MACRO_CKL),

  // B adaptives
  // L@D S@C C@N M@T P@L V@P
  [AD_GB_MB] = COMBO(adaptiveGB, AD_MACRO_MB),
  [AD_CB_VB] = COMBO(adaptiveCB, AD_MACRO_VB),
  [AD_BC_BV] = COMBO(adaptiveBC, AD_MACRO_BV),
  [AD_DB_LB] = COMBO(adaptiveDB, AD_MACRO_LB),
  [AD_BD_BL] = COMBO(adaptiveBD, AD_MACRO_BL),
  [AD_LB_PB] = COMBO(adaptiveLB, AD_MACRO_PB),
  [AD_BL_BP] = COMBO(adaptiveBL, AD_MACRO_BP),
  [AD_PB_SB] = COMBO(adaptivePB, AD_MACRO_SB),
  [AD_BP_BS] = COMBO(adaptiveBP, AD_MACRO_BS),
  [AD_NB_CB] = COMBO(adaptiveNB, AD_MACRO_CB),
  [AD_BN_BC] = COMBO(adaptiveBN, AD_MACRO_BC),
  [AD_DBP_LBS] = COMBO(adaptiveDBP, AD_MACRO_LBS),
  [AD_GBP_MBS] = COMBO(adaptiveGBP, AD_MACRO_MBS),
  [AD_BTP_BTS] = COMBO(adaptiveBTP, AD_MACRO_BTS),

  // H digraph adaptives
  [AD_DCN_LCH] = COMBO(adaptiveDNC, AD_MACRO_LCH),
  [AD_CND_CHL] = COMBO(adaptiveCND, AD_MACRO_CHL),
  [AD_VCN_NCH] = COMBO(adaptiveVCN, AD_MACRO_NCH), // Winch
  [AD_TNC_TCH] = COMBO(adaptiveTNC, AD_MACRO_TCH), // Witch
  [AD_CNT_NTH] = COMBO(adaptiveCNT, AD_MACRO_NTH), // Tenth
  [AD_PTN_LTH] = COMBO(adaptivePNT, AD_MACRO_LTH),
  [AD_TNP_THL] = COMBO(adaptiveTNP, AD_MACRO_THL),
  [AD_BDN_SHN] = COMBO(adaptiveBDN, AD_MACRO_SHN),
  [AD_NDB_NSH] = COMBO(adaptiveNDB, AD_MACRO_NSH),
  [AD_LDB_LSH] = COMBO(adaptiveLDB, AD_MACRO_LSH),
  [AD_BDL_SHL] = COMBO(adaptiveBDL, AD_MACRO_SHL),
  [AD_WMG_GHN] = COMBO(adaptiveWMG, AD_MACRO_GHN), // Toughness
  [AD_WMT_GHT] = COMBO(adaptiveWMT, AD_MACRO_GHT), // Thought
  [AD_CGF_SPH] = COMBO(adaptiveCGF, AD_MACRO_SPH), // Sphere
  [AD_MGF_MPH] = COMBO(adaptiveMGF, AD_MACRO_MPH), // Emphasis

  // Vowel SFB adaptives
  [AD_Am_AU] = COMBO(adaptiveAm, AD_MACRO_AU),
  [AD_Ac_EO] = COMBO(adaptiveAc, AD_MACRO_EO),
  [AD_Oc_YI] = COMBO(adaptiveOc, AD_MACRO_YI),
  [AD_Uc_UA] = COMBO(adaptiveUc, AD_MACRO_UA),
  [AD_Um_OE] = COMBO(adaptiveUm, AD_MACRO_OE),
  [AD_Ed_Eq] = COMBO(adaptiveEd, AD_MACRO_Eq),
  [AD_HEd_HEq] = COMBO(adaptiveHEd, AD_MACRO_HEq),
  [AD_IEd_IEq] = COMBO(adaptiveIEd, AD_MACRO_IEq),
  [AD_YEd_YEq] = COMBO(adaptiveYEd, AD_MACRO_YEq),

  // J adaptives
  [AD_qI_JI] = COMBO(adaptiveqI, AD_MACRO_JI),
  [AD_Jq_JO] = COMBO(adaptiveJq, AD_MACRO_JO),
  [AD_qJ_OJ] = COMBO(adaptiveqJ, AD_MACRO_OJ),

  // Miscellaneous consonants
  [ST_COMBO_NTK_Q] = COMBO(comboNTK, KC_Q),

  // H Bigram combos
  [ST_COMBO_WM] = COMBO(comboGM, ST_MACRO_WH),
  [ST_COMBO_GM] = COMBO(comboWM, ST_MACRO_GH),
  [ST_COMBO_DB] = COMBO(comboDB, ST_MACRO_SH), // Maybe this should be ordered?
  [ST_COMBO_CN] = COMBO(comboCN, ST_MACRO_CH),
  [ST_COMBO_TN] = COMBO(comboTN, ST_MACRO_TH),
  [ST_COMBO_GF] = COMBO(comboGF, ST_MACRO_PH),
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
  case RCTL(KC_BSPC):
  case LM(_LMOD,MOD_LSFT):
  case LM(_RMOD,MOD_RSFT):
  case KC_LSFT:
  case KC_RSFT:
  case KC_DEL:
  case KC_UNDS:
  case KC_QUOTE:
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
    SEND_CASED_STRINGS(AD_MACRO_XP, "xp", "Xp", "XP");
    SEND_CASED_STRINGS(AD_MACRO_ZZ, "zz", "Zz", "ZZ");
    SEND_CASED_STRINGS(AD_MACRO_QU, "qu", "Qu", "QU");
    SEND_CASED_STRINGS(AD_MACRO_WQ, "wq", "Wq", "WQ");
    SEND_CASED_STRINGS(AD_MACRO_SS, "ss", "Su", "SS");
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
    SEND_CASED_STRINGS(AD_MACRO_VS, "vs", "Vs", "VS");
    SEND_CASED_STRINGS(AD_MACRO_ZZL, "zzl", "Zzl", "ZZL");

  // F adaptives
  // L@G S@C W@M
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
    SEND_CASED_STRINGS(AD_MACRO_VB, "vb", "Vb", "VB");
    SEND_CASED_STRINGS(AD_MACRO_BV, "bv", "Bv", "BV");
    SEND_CASED_STRINGS(AD_MACRO_LB, "lb", "Lb", "LB");
    SEND_CASED_STRINGS(AD_MACRO_BL, "bl", "Bl", "BL");
    SEND_CASED_STRINGS(AD_MACRO_PB, "pb", "Pb", "PB");
    SEND_CASED_STRINGS(AD_MACRO_BP, "bp", "Bp", "BP");
    SEND_CASED_STRINGS(AD_MACRO_SB, "sb", "Sb", "SB");
    SEND_CASED_STRINGS(AD_MACRO_BS, "bs", "Bs", "BS");
    SEND_CASED_STRINGS(AD_MACRO_CB, "cb", "Cb", "CB");
    SEND_CASED_STRINGS(AD_MACRO_BC, "bc", "Bc", "BC");
    SEND_CASED_STRINGS(AD_MACRO_LBS, "lbs", "Lbs", "LBS");
    SEND_CASED_STRINGS(AD_MACRO_MBS, "mbs", "Mbs", "MBS");
    SEND_CASED_STRINGS(AD_MACRO_BTS, "bts", "Bts", "BTS");

  // H digraph adaptives
    SEND_CASED_STRINGS(AD_MACRO_LCH, "lch", "Lch", "LCH");
    SEND_CASED_STRINGS(AD_MACRO_CHL, "chl", "Chl", "CHL");
    SEND_CASED_STRINGS(AD_MACRO_NCH, "nch", "Nch", "NCH"); // Winch
    SEND_CASED_STRINGS(AD_MACRO_TCH, "tch", "Tch", "TCH"); // Witch
    SEND_CASED_STRINGS(AD_MACRO_NTH, "nth", "Nth", "NTH"); // Tenth
    SEND_CASED_STRINGS(AD_MACRO_LTH, "lth", "Lth", "LTH");
    SEND_CASED_STRINGS(AD_MACRO_THL, "thl", "Thl", "THL");
    SEND_CASED_STRINGS(AD_MACRO_SHN, "shn", "Shn", "SHN");
    SEND_CASED_STRINGS(AD_MACRO_NSH, "nsh", "Nsh", "NSH");
    SEND_CASED_STRINGS(AD_MACRO_LSH, "lsh", "Lsh", "LSH");
    SEND_CASED_STRINGS(AD_MACRO_SHL, "shl", "Shl", "SHL");
    SEND_CASED_STRINGS(AD_MACRO_GHN, "ghn", "Ghn", "GHN"); // Toughness
    SEND_CASED_STRINGS(AD_MACRO_GHT, "ght", "Ght", "GHT"); // Thought
    SEND_CASED_STRINGS(AD_MACRO_SPH, "sph", "Sph", "SPH"); // Sphere
    SEND_CASED_STRINGS(AD_MACRO_MPH, "mph", "Mph", "MPH"); // Emphasis

  // Vowel SFB adaptives
    SEND_CASED_STRINGS(AD_MACRO_AU, "au", "Au", "AU");
    SEND_CASED_STRINGS(AD_MACRO_EO, "eo", "Eo", "EO");
    SEND_CASED_STRINGS(AD_MACRO_UA, "ua", "Ua", "UA");
    SEND_CASED_STRINGS(AD_MACRO_OE, "oe", "Oe", "OE");
    SEND_CASED_STRINGS(AD_MACRO_YI, "yi", "Yi", "YI");
    SEND_CASED_STRINGS(AD_MACRO_Eq, "e'", "E'", "E'");
    SEND_CASED_STRINGS(AD_MACRO_HEq, "he'", "He'", "HE'");
    SEND_CASED_STRINGS(AD_MACRO_IEq, "ie'", "Ie'", "IE'");
    SEND_CASED_STRINGS(AD_MACRO_YEq, "ye'", "Ye'", "YE'");

  // J adaptives
    SEND_CASED_STRINGS(AD_MACRO_JI, "ji", "Ji", "JI");
    SEND_CASED_STRINGS(AD_MACRO_JO, "jo", "Jo", "JO");
    SEND_CASED_STRINGS(AD_MACRO_OJ, "oj", "Oj", "OJ");

  // H digraphs
    SEND_CASED_STRINGS(ST_MACRO_WH, "wh", "Wh", "WH");
    SEND_CASED_STRINGS(ST_MACRO_GH, "gh", "Gh", "GH");
    SEND_CASED_STRINGS(ST_MACRO_SH, "sh", "Sh", "SH");
    SEND_CASED_STRINGS(ST_MACRO_CH, "ch", "Ch", "CH");
    SEND_CASED_STRINGS(ST_MACRO_TH, "th", "Th", "TH");
    SEND_CASED_STRINGS(ST_MACRO_PH, "ph", "Ph", "PH");

  // Symbol macros
  case ST_FORCE_EQUAL:
    if (record->event.pressed) {
      SEND_STRING_CLEAR("=");
    }
    return true;
  case ST_FORCE_S:
    if (record->event.pressed) {
      SEND_STRING_CLEAR("s");
    }
    return true;

  // Tap-hold keys
    TAPHOLD_CASED(LT(0, KC_X), "z", "Z", "Z");

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
        CL_BASE, CL_OFF, CL_OFF, CL_OFF, CL_LEFT,
        CL_BASE, CL_BASE, CL_BASE, CL_BASE, CL_BASE,
        CL_BASE, CL_BASE, CL_BASE, CL_BASE, CL_FN,
        CL_BASE, CL_BASE, CL_BASE, CL_BASE, CL_NUM,
        CL_BASE, CL_BASE, CL_BASE, CL_BASE, CL_MOD,
        CL_BASE, CL_BASE, CL_BASE, CL_BASE,
        CL_BASE, CL_OFF, CL_OFF,
        CL_BASE, CL_BASE, CL_BASE, CL_BASE,

        CL_BASE, CL_OFF, CL_OFF, CL_OFF, CL_OFF,
        CL_BASE, CL_BASE, CL_BASE, CL_BASE, CL_BASE,
        CL_BASE, CL_BASE, CL_BASE, CL_BASE, CL_MOD,
        CL_BASE, CL_BASE, CL_BASE, CL_BASE, CL_FN,
        CL_BASE, CL_BASE, CL_BASE, CL_BASE, CL_MOD,
        CL_BASE, CL_BASE, CL_BASE, CL_BASE,
        CL_BASE, CL_OFF, CL_OFF,
        CL_BASE, CL_BASE, CL_BASE, CL_BASE
    },

    [_LMOD] = {
        CL_MOD, CL_OFF, CL_OFF, CL_OFF, CL_OFF,
        CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_MOD,
        CL_OFF, CL_OFF, CL_MOD, CL_OFF, CL_OFF,
        CL_OFF, CL_OFF, CL_MOD, CL_OFF, CL_OFF,
        CL_OFF, CL_OFF, CL_MOD, CL_OFF, CL_CLEAR,
        CL_OFF, CL_OFF, CL_OFF, CL_OFF,
        CL_MOD, CL_OFF, CL_OFF,
        CL_OFF, CL_OFF, CL_BASE, CL_OFF,

        CL_BASE, CL_OFF, CL_OFF, CL_OFF, CL_OFF,
        CL_OFF, CL_BASE, CL_BASE, CL_BASE, CL_BASE,
        CL_OFF, CL_BASE, CL_BASE, CL_BASE, CL_OFF,
        CL_OFF, CL_OFF, CL_BASE, CL_BASE, CL_OFF,
        CL_OFF, CL_BASE, CL_BASE, CL_BASE, CL_MOD,
        CL_OFF, CL_OFF, CL_OFF, CL_OFF,
        CL_BASE, CL_OFF, CL_OFF,
        CL_BASE, CL_BASE, CL_BASE, CL_BASE
    },

    [_RMOD] = {
        CL_BASE, CL_OFF, CL_OFF, CL_OFF, CL_OFF,
        CL_OFF, CL_BASE, CL_BASE, CL_BASE, CL_BASE,
        CL_OFF, CL_BASE, CL_BASE, CL_BASE, CL_OFF,
        CL_OFF, CL_BASE, CL_BASE, CL_BASE, CL_OFF,
        CL_OFF, CL_BASE, CL_BASE, CL_BASE, CL_MOD,
        CL_OFF, CL_OFF, CL_BASE, CL_OFF,
        CL_BASE, CL_OFF, CL_OFF,
        CL_BASE, CL_TAP_HOLD, CL_BASE, CL_BASE,

        CL_MOD, CL_OFF, CL_OFF, CL_OFF, CL_OFF,
        CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_MOD,
        CL_OFF, CL_OFF, CL_MOD, CL_OFF, CL_OFF,
        CL_OFF, CL_OFF, CL_MOD, CL_OFF, CL_OFF,
        CL_OFF, CL_OFF, CL_MOD, CL_OFF, CL_CLEAR,
        CL_OFF, CL_OFF, CL_OFF, CL_OFF,
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
