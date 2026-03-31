#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE,

  ST_FORCE_EQUAL,
  ST_FORCE_SLASH,
  ST_FORCE_BSLS,
  ST_FORCE_MINUS,
  ST_FORCE_LBRC,
  ST_FORCE_RBRC,

  ST_FORCE_S,
  ST_FORCE_Q,

  ST_MACRO_WH, KC_ALNUM_MACRO_FIRST = ST_MACRO_WH,
  ST_MACRO_GH,
  ST_MACRO_SH,
  ST_MACRO_CH,
  ST_MACRO_TH,
  ST_MACRO_PH,
  ST_MACRO_HY,
  ST_MACRO_HI,

  AD_MACRO_QU,
  AD_MACRO_WQ,
  AD_MACRO_cWQ,
  AD_MACRO_cW,
  AD_MACRO_cQ,
  AD_MACRO_MC,
  AD_MACRO_MPG,
  AD_MACRO_MPT,
  AD_MACRO_MPD,
  AD_MACRO_SQU,
  AD_MACRO_LQU,
  AD_MACRO_DQU,
  AD_MACRO_NQU,
  AD_MACRO_MQU,
  AD_MACRO_CQU,
  AD_MACRO_WNL,

  // X/Z adaptives
  AD_MACRO_SV,
  AD_MACRO_VS,
  AD_MACRO_SX,
  AD_MACRO_ZB,
  AD_MACRO_BZ,
  AD_MACRO_XF,
  AD_MACRO_GZW,
  AD_MACRO_XQU,

  // ZZ, SS adaptives
  AD_MACRO_ZZ,
  AD_MACRO_SS,
  AD_MACRO_ZZL,
  AD_MACRO_ZZW,
  AD_MACRO_SSW,
  AD_MACRO_SMS,
  AD_MACRO_SSM,
  AD_MACRO_SCS,
  AD_MACRO_SSC,
  AD_MACRO_STS,
  AD_MACRO_SSN,
  AD_MACRO_SPS,
  AD_MACRO_SSP,
  AD_MACRO_SSL,

  // F adaptives
  // L@G S@C W@M S@P P@L L@D D@B
  AD_MACRO_SF,
  AD_MACRO_FS,
  AD_MACRO_WF,
  AD_MACRO_FW,
  AD_MACRO_MF,
  AD_MACRO_FM,
  AD_MACRO_PF,
  AD_MACRO_FP,
  AD_MACRO_LF,
  AD_MACRO_FL,
  AD_MACRO_DF,
  AD_MACRO_FG,
  AD_MACRO_GF,
  AD_MACRO_LFW,
  AD_MACRO_FTS,
  AD_MACRO_FTW,
  AD_MACRO_MPF,

  // K adaptives
  // S@P C@N N@T L@G P@L M@G W@M
  AD_MACRO_WK,
  AD_MACRO_MK,
  AD_MACRO_KM,
  AD_MACRO_LK,
  AD_MACRO_KL,
  AD_MACRO_VK,
  AD_MACRO_KV,
  AD_MACRO_CK,
  AD_MACRO_KC,
  AD_MACRO_SK,
  AD_MACRO_KS,
  AD_MACRO_NK,
  AD_MACRO_KN,
  AD_MACRO_PK,
  AD_MACRO_KP,
  AD_MACRO_WKW,
  AD_MACRO_WKS,
  AD_MACRO_PKG,
  AD_MACRO_LKS,
  AD_MACRO_SKL,
  AD_MACRO_CKS,
  AD_MACRO_CKN,
  AD_MACRO_NKN,
  AD_MACRO_NKS,
  AD_MACRO_NKL,
  AD_MACRO_LKN,
  AD_MACRO_MPK, // Pumpkin
  AD_MACRO_MKV,
  AD_MACRO_CKL, // cackle
  AD_MACRO_CKP, // Backpack
  AD_MACRO_CKB, // Blackerry
  // nothing for backpack because C and P same finger

  // B adaptives
  // L@D S@P C@N P@L V@P W@M M@G G@F
  AD_MACRO_GB,
  AD_MACRO_MB,
  AD_MACRO_BM,
  AD_MACRO_WB,
  AD_MACRO_BW,
  AD_MACRO_BV,
  AD_MACRO_LB,
  AD_MACRO_BL,
  AD_MACRO_PB,
  AD_MACRO_BP,
  AD_MACRO_SB,
  AD_MACRO_BS,
  AD_MACRO_BD,
  AD_MACRO_DB,
  AD_MACRO_LBS,
  AD_MACRO_PBS,
  AD_MACRO_BTS,
  AD_MACRO_MPB,
  AD_MACRO_NGB,
  AD_MACRO_MBS,
  AD_MACRO_MBL,

  // H digraph adaptives
  AD_MACRO_LCH,
  AD_MACRO_CHL,
  AD_MACRO_XCH,
  AD_MACRO_NCH,
  AD_MACRO_CHN,
  AD_MACRO_TCH,
  AD_MACRO_SCH,
  AD_MACRO_CHS,
  AD_MACRO_MCH,
  AD_MACRO_CHM,
  AD_MACRO_CHTH,

  AD_MACRO_THM,
  AD_MACRO_NTH,
  AD_MACRO_THN,
  AD_MACRO_LTH,
  AD_MACRO_THL,
  AD_MACRO_WTH,
  AD_MACRO_THW,
  AD_MACRO_CTH,
  AD_MACRO_THC,
  AD_MACRO_PTH,
  AD_MACRO_THP,
  AD_MACRO_DTH,
  AD_MACRO_THD,
  AD_MACRO_FTH,
  AD_MACRO_THF,
  AD_MACRO_THB,
  AD_MACRO_BTH,
  AD_MACRO_THS,
  AD_MACRO_THR,
  AD_MACRO_WTHS,
  AD_MACRO_DTHS,
  AD_MACRO_NTHS,
  AD_MACRO_FTHS,
  AD_MACRO_THBR,

  AD_MACRO_NSH,
  AD_MACRO_SHN,
  AD_MACRO_TSH,
  AD_MACRO_SHT,
  AD_MACRO_MSH,
  AD_MACRO_SHM,
  AD_MACRO_GSH,
  AD_MACRO_SHG,
  AD_MACRO_WSH,
  AD_MACRO_LSH,
  AD_MACRO_SHL,

  AD_MACRO_NWH,
  AD_MACRO_LWH,

  AD_MACRO_GHN,
  AD_MACRO_NGH,
  AD_MACRO_GHT,
  AD_MACRO_GHS,
  AD_MACRO_GHL,
  AD_MACRO_GHB,

  AD_MACRO_SPH,
  AD_MACRO_PHS,
  AD_MACRO_MPH,
  AD_MACRO_LPH,
  AD_MACRO_PHL,
  AD_MACRO_MPHS,

  // Vowel SFB adaptives
  AD_MACRO_JOY,
  AD_MACRO_AU,
  AD_MACRO_EO,
  AD_MACRO_UA,
  AD_MACRO_OE, KC_ALNUM_MACRO_LAST = AD_MACRO_OE,
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
    KC_GRAVE,       LT(0,KC_Z),     KC_W,           KC_M,           KC_G,           KC_F,           KC_BACKSPACE,                                   KC_INSERT,      KC_SCLN,        KC_QUOT,        KC_COMMA,       KC_DOT,         KC_SLASH,       KC_BSLS,
    KC_TAB,         KC_V,           KC_C,           KC_N,           KC_T,           KC_K,           KC_SPACE,                                       KC_DELETE,      KC_EQUAL,       KC_A,           KC_E,           KC_I,           KC_QUES,        XXXXXXX,
    MO(_LEFT),      KC_S,           KC_P,           KC_L,           KC_D,           KC_B,                                                                           KC_MINUS,       KC_U,           KC_O,           KC_Y,           KC_H,           XXXXXXX,
    TO(_LEFT),      KC_X,           KC_RPRN,        MO(_NUM),       LM(_LMOD,MOD_LSFT),             KC_ESCAPE,                                      RCTL(KC_BSPC),             LM(_RMOD,MOD_RSFT),  MO(_FN),        KC_LPRN,        KC_J,           XXXXXXX,
    KC_R,           KC_ENTER,       XXXXXXX,                        XXXXXXX,        KC_ENTER,       KC_SPACE
  ),

  [_LMOD] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______,
    _______,        KC_EXLM,        KC_PIPE,        KC_AMPR,        KC_PERC,        KC_HASH,        _______,                                        _______,        _______,        _______,        _______,        _______,        ST_FORCE_SLASH, ST_FORCE_BSLS,
    _______,        XXXXXXX,        KC_LGUI,        KC_LALT,        KC_LCTL,        CW_TOGG,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______,
    _______,        ST_FORCE_S,     ST_FORCE_LBRC, ST_FORCE_RBRC,   ST_FORCE_EQUAL, KC_AT,                                                                          _______,        _______,        _______,        _______,        _______,        _______,
    XXXXXXX,        KC_LPRN,        KC_RPRN,        _______,        _______,                        _______,                                        RCTL(KC_BSPC),                  _______,        _______,        _______,        _______,        _______,
    XXXXXXX,        XXXXXXX,        _______,                        _______,        _______,        _______
  ),

  [_RMOD] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        KC_CIRC,        _______,        _______,        _______,        ST_FORCE_SLASH, ST_FORCE_BSLS,
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        KC_PLUS,        KC_RCTL,        KC_RALT,        KC_RGUI,        KC_ASTR,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,                                                                        ST_FORCE_MINUS, ST_FORCE_EQUAL, KC_LCBR,        KC_RCBR,        KC_DLR,         _______,
    XXXXXXX,        _______,        _______,        _______,        _______,                       _______,                                        RCTL(KC_BSPC),                   _______,        _______,        KC_LPRN,        KC_RPRN,         _______,
    KC_R,           _______,        _______,                        _______,        XXXXXXX,        XXXXXXX
  ),

  [_NUM] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______,
    _______,        KC_EXLM,        KC_PIPE,        KC_AMPR,        KC_PERC,        KC_HASH,        _______,                                        TO(_NUMPAD),    KC_COMMA,       KC_7,           KC_8,           KC_9,           KC_SLASH,       _______,
    _______, KC_COMMA, MT(MOD_LGUI,KC_LEFT), MT(MOD_LALT,KC_UP), MT(MOD_LCTL,KC_DOWN), KC_RIGHT,    _______,                                        _______,        KC_PLUS,        KC_4,           KC_5,           KC_6,           KC_ASTR,        _______,
    _______,        KC_LPRN,        ST_FORCE_LBRC, ST_FORCE_RBRC,   KC_EQUAL,       KC_RPRN,                                                                        KC_MINUS,       KC_1,           KC_2,           KC_3,           KC_DLR,         _______,
    TO(0),          _______,        TO(_FN),        TO(0),          KC_LEFT_SHIFT,                  _______,                                        KC_BSPC,                        KC_0,           KC_DOT,         KC_EQUAL,       KC_UNDS,         TO(0),
    TO(_NUMPAD),    _______,        _______,                        _______,        KC_ENTER,       _______
  ),

  [_NUMPAD] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        KC_NUM,         KC_KP_ASTERISK, KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_DLR,         _______,
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        KC_KP_PLUS,     KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_SLASH,    _______,
    _______,        KC_LPRN,        KC_EQUAL,       KC_LBRC,        KC_RBRC,        KC_RPRN,                                                                        KC_KP_MINUS,    KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_EQUAL,    _______,
    TO(0),          _______,        TO(_FN),        TO(0),          KC_LEFT_SHIFT,                  _______,                                        KC_BSPC,                        KC_KP_0,        KC_KP_DOT,      KC_KP_EQUAL,    _______,        TO(0),
    TO(_NUM),       KC_KP_COMMA,    _______,                        _______,        KC_KP_ENTER,    _______
  ),

  [_FN] = LAYOUT_moonlander(
    _______,        KC_F14,         KC_F12,         KC_F11,         KC_F10,         KC_F15,         _______,                                        _______,        KC_F16,         KC_F17,         KC_F18,         KC_F19,         KC_F20,         _______,
    _______,        KC_F13,         KC_F9,          KC_F8,          KC_F7,          KC_F23,         KC_F24,                                         KC_INSERT,      KC_ESCAPE,      KC_MPRV,        KC_MNXT,        KC_MPLY,        KC_MUTE,        KC_VOLU,
    _______,      KC_BRIU, MT(MOD_LGUI,KC_F6), MT(MOD_LALT,KC_F5), MT(MOD_LCTL,KC_F4), KC_F22,      _______,                                        KC_DELETE,      KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TAB,         KC_VOLD,
    _______,        KC_BRID,        KC_F3,       KC_F2,          KC_F1,          KC_F21,                                                                         KC_HOME,        KC_PGDN,        KC_PAGE_UP,     KC_END,         LCTL(KC_G),     KC_WWW_SEARCH,
    TO(0),          _______,        TO(0),          TO(_NUM),       KC_LEFT_SHIFT,                  _______,                                        KC_BSPC,                        KC_RIGHT_SHIFT, TO(0),          _______,        _______,        TO(0),
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
  AD_KM_QU, ADAPTIVE_FIRST = AD_KM_QU,
  AD_pe_WQ,
  AD_cpe_cWQ,
  AD_cp_cW,
  AD_ce_cQ,
  AD_MC_MC,
  AD_MPG_MPG,
  AD_MPT_MPT,
  AD_MPD_MPD,
  AD_PKM_SQU,
  AD_DKM_LQU,
  AD_BKM_DQU,
  AD_TKM_NQU,
  AD_GKM_MQU,

  AD_CKM_CQU,
  AD_WND_WNL,

  // X/Z adaptives
  AD_WV_SV,
  AD_VW_VS,
  AD_XS_SX,
  AD_WB_ZB,
  AD_BW_BZ,
  AD_WF_XF,
  AD_GZW_GZW,
  AD_XDC_XQU,

  // ZZ, SS adaptives
  AD_XF_ZZ,
  AD_SB_SS,
  AD_XGF_ZZL,
  AD_XFG_ZZL,
  AD_ZWF_ZZW,
  AD_XFW_ZZW,
  AD_SWB_SSW,
  AD_SBW_SSW,
  AD_SGB_SSM,
  AD_SBG_SSM,
  AD_SCB_SSC,
  AD_SBC_SSC,
  AD_STB_SSN,
  AD_SBT_SSN,
  AD_SPB_SSP,
  AD_SBP_SSP,
  AD_SDB_SSL,
  AD_SBD_SSL,

  // F adaptives
  // L@G W@M M@G S@P P@L L@D D@B
  AD_MF_WF,
  AD_FM_FW,
  AD_GF_MF,
  AD_FG_FM,
  AD_PF_SF,
  AD_FP_FS,
  AD_LF_PF,
  AD_FL_FP,
  AD_DF_LF,
  AD_FD_FL,
  AD_BF_DF,
  AD_FK_FG,
  AD_KF_GF,
  AD_DFM_LFW,
  AD_FTP_FTS,
  AD_FTM_FTW,
  AD_GLF_MPF,

  // K adaptives
  // S@P C@N N@T L@D P@L
  AD_MK_WK,
  AD_GK_MK,
  AD_KG_KM,
  AD_DK_LK,
  AD_KD_KL,
  AD_CK_VK,
  AD_KC_KV,
  AD_NK_CK,
  AD_KN_KC,
  AD_PK_SK,
  AD_KP_KS,
  AD_TK_NK,
  AD_KT_KN,
  AD_LK_PK,
  AD_KL_KP,
  AD_MKG_WKW,
  AD_MKP_WKS,
  AD_LKG_PKG,
  AD_DKP_LKS,
  AD_PKD_SKL,
  AD_NKP_CKS,
  AD_NKT_CKN,
  AD_TKN_NKN,
  AD_TKP_NKS,
  AD_TKL_NKL,
  AD_LKT_LKN,
  AD_GLK_MPK,
  AD_GKC_MKV,
  AD_NKG_CKL,
  AD_NKD_CKL,
  AD_NDK_CKL,
  AD_KTL_CKP,
  AD_NKB_CKB,
  AD_NBK_CKB,

  // B adaptives
  // L@D S@P C@N P@L V@P
  AD_FB_GB,
  AD_GB_MB,
  AD_BG_BM,
  AD_MB_WB,
  AD_BM_BW,
  AD_BC_BV, // Obvious -- but no words with VB
  AD_DB_LB,
  AD_BD_BL,
  AD_LB_PB,
  AD_BL_BP,
  AD_PB_SB,
  AD_BP_BS,
  AD_BK_BD,
  AD_KB_DB,
  AD_DBP_LBS,
  AD_LBP_PBS,
  AD_BTP_BTS, // doubts
  AD_GLB_MPB,
  AD_NGB_NGB,
  AD_GBP_MBS,
  AD_GBL_MBL,

  // H digraph adaptives
  AD_DCN_LCH,
  AD_LCV_LCH,
  AD_CND_CHL,
  AD_VCL_CHL,
  AD_XCN_XCH, // Exchange
  AD_NCV_NCH, // Winch
  AD_VCN_CHN, // Techno
  AD_TNC_TCH, // Witch
  AD_TCV_TCH,
  AD_SCN_SCH, // Schedule
  AD_NCS_CHS,
  AD_GNC_MCH, // Armchair
  AD_MCV_MCH,
  AD_CNG_CHM, // Attachment
  AD_VCM_CHM,
  AD_VCMG_CHTH,

  AD_TNW_THM,
  AD_CNT_NTH,
  AD_TNC_THN,
  AD_PNT_LTH,
  AD_TNP_THL,
  AD_WMG_WTH,
  AD_GMW_THW,
  AD_CMG_CTH,
  AD_GMC_THC,
  AD_PMG_PTH,
  AD_GMP_THP,
  AD_DNC_DTH,
  AD_CND_THD,
  AD_NTK_THF,
  AD_KTN_FTH,
  AD_MGK_THB,
  AD_KGM_BTH,
  AD_GMS_THS,
  AD_MGS_THS,
  AD_MGR_THR,
  AD_WMGS_WTHS,
  AD_GMWS_WTHS,
  AD_CNTS_NTHS,
  AD_CTNS_NTHS,
  AD_KTNP_FTHS,
  AD_MGBR_THBR,

  AD_NWZ_NSH,
  AD_ZWN_SHN,
  AD_TWZ_TSH,
  AD_ZWT_SHT,
  AD_MWZ_MSH,
  AD_ZWM_SHM,
  AD_GWZ_GSH,
  AD_ZWG_SHG,
  AD_WZg_WSH,
  AD_LWZ_LSH,
  AD_ZWL_SHL,

  AD_NDB_NWH,
  AD_LDB_LWH,

  AD_MWV_GHN,
  AD_VWM_NGH,
  AD_WMT_GHT,
  AD_MWS_GHS,
  AD_WML_GHL,
  AD_MWL_GHL,
  AD_WMD_GHL,
  AD_MGB_GHB,

  AD_PGF_SPH,
  AD_FGP_PHS,
  AD_GFP_PHS,
  AD_MGF_MPH,
  AD_LGF_LPH,
  AD_FGL_PHL,
  AD_GFL_PHL,
  AD_MGFP_MPHS,
  AD_MGPF_MPHS,

  // Vowel SFB adaptives
  AD_JYO_JOY,
  AD_Am_AU,
  AD_Ae_EO,
  AD_Ue_UA,
  AD_Um_OE, ADAPTIVE_LAST = AD_Um_OE,

  // H Bigram combos
  ST_COMBO_ZW,
  ST_COMBO_GM,
  ST_COMBO_MG,
  ST_COMBO_WM,
  ST_COMBO_DB,
  ST_COMBO_CV,
  ST_COMBO_GF,
  ST_COMBO_YH,
  ST_COMBO_IH,
};

// Bigram combo
const uint16_t PROGMEM comboZW[] = { LT(0,KC_Z), KC_W, COMBO_END };
const uint16_t PROGMEM comboGM[] = { KC_G, KC_M, COMBO_END};
const uint16_t PROGMEM comboMG[] = { KC_M, KC_G, COMBO_END};
const uint16_t PROGMEM comboWM[] = { KC_W, KC_M, COMBO_END};
const uint16_t PROGMEM comboDB[] = { KC_D, KC_B, COMBO_END};
const uint16_t PROGMEM comboCV[] = { KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM comboGF[] = { KC_G, KC_F, COMBO_END};
const uint16_t PROGMEM comboYH[] = { KC_Y, KC_H, COMBO_END };
const uint16_t PROGMEM comboIH[] = { KC_I, KC_H, COMBO_END };

// Miscellaneous letters
const uint16_t PROGMEM adaptiveKM[] = { KC_K, KC_M, COMBO_END };
const uint16_t PROGMEM adaptivePipeExlm[] = { KC_PIPE, KC_EXLM, COMBO_END };
const uint16_t PROGMEM adaptiveColPipeExlm[] = { KC_SCLN, KC_PIPE, KC_EXLM, COMBO_END };
const uint16_t PROGMEM adaptiveColPipe[] = { KC_SCLN, KC_PIPE, COMBO_END };
const uint16_t PROGMEM adaptiveColExlm[] = { KC_SCLN, KC_EXLM, COMBO_END };
const uint16_t PROGMEM adaptiveMC[] = { KC_M, KC_C, COMBO_END };
const uint16_t PROGMEM adaptiveMPG[] = { KC_M, KC_P, KC_G, COMBO_END };
const uint16_t PROGMEM adaptiveMPT[] = { KC_M, KC_P, KC_T, COMBO_END };
const uint16_t PROGMEM adaptiveMPD[] = { KC_M, KC_P, KC_D, COMBO_END };
const uint16_t PROGMEM adaptivePKM[] = { KC_P, KC_K, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveDKM[] = { KC_D, KC_K, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveBKM[] = { KC_B, KC_K, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveTKM[] = { KC_T, KC_K, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveGKM[] = { KC_G, KC_K, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveCKM[] = { KC_C, KC_K, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveWND[] = { KC_W, KC_N, KC_D, COMBO_END };

// X/Z adaptives
const uint16_t PROGMEM adaptiveWV[] = { KC_W, KC_V, COMBO_END };
const uint16_t PROGMEM adaptiveVW[] = { KC_V, KC_W, COMBO_END };
const uint16_t PROGMEM adaptiveXS[] = { KC_X, KC_S, COMBO_END };
const uint16_t PROGMEM adaptiveWB[] = { KC_W, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveBW[] = { KC_B, KC_W, COMBO_END };
const uint16_t PROGMEM adaptiveWF[] = { KC_W, KC_F, COMBO_END };
const uint16_t PROGMEM adaptiveGZW[] = { KC_G, LT(0,KC_Z), KC_W, COMBO_END };
const uint16_t PROGMEM adaptiveXDC[] = { KC_X, KC_D, KC_C, COMBO_END };

// ZZ, SS adaptives
const uint16_t PROGMEM adaptiveXF[] = { LT(0,KC_Z), KC_F, COMBO_END };
const uint16_t PROGMEM adaptiveSB[] = { KC_S, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveXGF[] = { LT(0,KC_Z), KC_G, KC_F, COMBO_END };
const uint16_t PROGMEM adaptiveXFG[] = { LT(0,KC_Z), KC_F, KC_G, COMBO_END };
const uint16_t PROGMEM adaptiveZWF[] = { LT(0,KC_Z), KC_W, KC_F, COMBO_END };
const uint16_t PROGMEM adaptiveXFW[] = { LT(0,KC_Z), KC_F, KC_W, COMBO_END };
const uint16_t PROGMEM adaptiveSWB[] = { KC_S, KC_W, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveSBW[] = { KC_S, KC_B, KC_W, COMBO_END };
const uint16_t PROGMEM adaptiveSGB[] = { KC_S, KC_G, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveSBG[] = { KC_S, KC_B, KC_G, COMBO_END };
const uint16_t PROGMEM adaptiveSCB[] = { KC_S, KC_C, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveSBC[] = { KC_S, KC_B, KC_C, COMBO_END };
const uint16_t PROGMEM adaptiveSTB[] = { KC_S, KC_T, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveSBT[] = { KC_S, KC_B, KC_T, COMBO_END };
const uint16_t PROGMEM adaptiveSPB[] = { KC_S, KC_P, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveSBP[] = { KC_S, KC_B, KC_P, COMBO_END };
const uint16_t PROGMEM adaptiveSDB[] = { KC_S, KC_D, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveSBD[] = { KC_S, KC_B, KC_D, COMBO_END };

// F adaptives
// L@G S@C W@M S@P P@L L@D D@B
const uint16_t PROGMEM adaptiveMF[] = { KC_M, KC_F, COMBO_END };
const uint16_t PROGMEM adaptiveFM[] = { KC_F, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveGF[] = { KC_G, KC_F, COMBO_END };
const uint16_t PROGMEM adaptiveFG[] = { KC_F, KC_G, COMBO_END };
const uint16_t PROGMEM adaptivePF[] = { KC_P, KC_F, COMBO_END };
const uint16_t PROGMEM adaptiveFP[] = { KC_F, KC_P, COMBO_END };
const uint16_t PROGMEM adaptiveLF[] = { KC_L, KC_F, COMBO_END };
const uint16_t PROGMEM adaptiveFL[] = { KC_F, KC_L, COMBO_END };
const uint16_t PROGMEM adaptiveDF[] = { KC_D, KC_F, COMBO_END };
const uint16_t PROGMEM adaptiveFD[] = { KC_F, KC_D, COMBO_END };
const uint16_t PROGMEM adaptiveBF[] = { KC_B, KC_F, COMBO_END };
const uint16_t PROGMEM adaptiveFK[] = { KC_F, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveKF[] = { KC_K, KC_F, COMBO_END };
const uint16_t PROGMEM adaptiveDFM[] = { KC_D, KC_F, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveFTP[] = { KC_F, KC_T, KC_P, COMBO_END };
const uint16_t PROGMEM adaptiveFTM[] = { KC_F, KC_T, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveGLF[] = { KC_G, KC_L, KC_F, COMBO_END };

// K adaptives
// S@C/P C@N N@T L@D P@L W@M
const uint16_t PROGMEM adaptiveMK[] = { KC_M, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveGK[] = { KC_G, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveKG[] = { KC_K, KC_G, COMBO_END };
const uint16_t PROGMEM adaptiveDK[] = { KC_D, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveKD[] = { KC_K, KC_D, COMBO_END };
const uint16_t PROGMEM adaptiveCK[] = { KC_C, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveKC[] = { KC_K, KC_C, COMBO_END };
const uint16_t PROGMEM adaptiveNK[] = { KC_N, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveKN[] = { KC_K, KC_N, COMBO_END };
const uint16_t PROGMEM adaptivePK[] = { KC_P, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveKP[] = { KC_K, KC_P, COMBO_END };
const uint16_t PROGMEM adaptiveTK[] = { KC_T, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveKT[] = { KC_K, KC_T, COMBO_END };
const uint16_t PROGMEM adaptiveLK[] = { KC_L, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveKL[] = { KC_K, KC_L, COMBO_END };
const uint16_t PROGMEM adaptiveMKG[] = { KC_M, KC_K, KC_G, COMBO_END };
const uint16_t PROGMEM adaptiveMKP[] = { KC_M, KC_K, KC_P, COMBO_END };
const uint16_t PROGMEM adaptiveLKG[] = { KC_L, KC_K, KC_G, COMBO_END };
const uint16_t PROGMEM adaptiveDKP[] = { KC_D, KC_K, KC_P, COMBO_END };
const uint16_t PROGMEM adaptivePKD[] = { KC_P, KC_K, KC_D, COMBO_END };
const uint16_t PROGMEM adaptiveNKP[] = { KC_N, KC_K, KC_P, COMBO_END };
const uint16_t PROGMEM adaptiveNKT[] = { KC_N, KC_K, KC_T, COMBO_END };
const uint16_t PROGMEM adaptiveTKN[] = { KC_T, KC_K, KC_N, COMBO_END };
const uint16_t PROGMEM adaptiveTKP[] = { KC_T, KC_K, KC_P, COMBO_END };
const uint16_t PROGMEM adaptiveTKL[] = { KC_T, KC_K, KC_L, COMBO_END };
const uint16_t PROGMEM adaptiveLKT[] = { KC_L, KC_K, KC_T, COMBO_END };
const uint16_t PROGMEM adaptiveGLK[] = { KC_G, KC_L, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveGKC[] = { KC_G, KC_K, KC_C, COMBO_END };
const uint16_t PROGMEM adaptiveNKG[] = { KC_N, KC_K, KC_G, COMBO_END };
const uint16_t PROGMEM adaptiveNKD[] = { KC_N, KC_K, KC_D, COMBO_END };
const uint16_t PROGMEM adaptiveNDK[] = { KC_N, KC_D, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveKTL[] = { KC_K, KC_T, KC_L, COMBO_END };
const uint16_t PROGMEM adaptiveNKB[] = { KC_N, KC_K, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveNBK[] = { KC_N, KC_B, KC_K, COMBO_END };

// B adaptives
// L@D S@P C@N P@L V@C
const uint16_t PROGMEM adaptiveFB[] = { KC_F, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveGB[] = { KC_G, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveBG[] = { KC_B, KC_G, COMBO_END };
const uint16_t PROGMEM adaptiveMB[] = { KC_M, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveBM[] = { KC_B, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveBC[] = { KC_B, KC_C, COMBO_END };
const uint16_t PROGMEM adaptiveDB[] = { KC_D, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveBD[] = { KC_B, KC_D, COMBO_END };
const uint16_t PROGMEM adaptiveLB[] = { KC_L, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveBL[] = { KC_B, KC_L, COMBO_END };
const uint16_t PROGMEM adaptivePB[] = { KC_P, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveBP[] = { KC_B, KC_P, COMBO_END };
const uint16_t PROGMEM adaptiveBK[] = { KC_B, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveKB[] = { KC_K, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveDBP[] = { KC_D, KC_B, KC_P, COMBO_END };
const uint16_t PROGMEM adaptiveLBP[] = { KC_L, KC_B, KC_P, COMBO_END };
const uint16_t PROGMEM adaptiveBTP[] = { KC_B, KC_T, KC_P, COMBO_END };
const uint16_t PROGMEM adaptiveGLB[] = { KC_G, KC_L, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveNGB[] = { KC_N, KC_G, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveGBP[] = { KC_G, KC_B, KC_P, COMBO_END };
const uint16_t PROGMEM adaptiveGBL[] = { KC_G, KC_B, KC_L, COMBO_END };

// H digraph adaptives
const uint16_t PROGMEM adaptiveLCV[] = { KC_L, KC_C, KC_V, COMBO_END };
const uint16_t PROGMEM adaptiveVCL[] = { KC_V, KC_C, KC_L, COMBO_END };
const uint16_t PROGMEM adaptiveXCN[] = { KC_X, KC_C, KC_N, COMBO_END };
const uint16_t PROGMEM adaptiveNCV[] = { KC_N, KC_C, KC_V, COMBO_END };
const uint16_t PROGMEM adaptiveVCN[] = { KC_V, KC_C, KC_N, COMBO_END };
const uint16_t PROGMEM adaptiveTCV[] = { KC_T, KC_C, KC_V, COMBO_END };
const uint16_t PROGMEM adaptiveSCN[] = { KC_S, KC_C, KC_N, COMBO_END };
const uint16_t PROGMEM adaptiveNCS[] = { KC_N, KC_C, KC_S, COMBO_END };
const uint16_t PROGMEM adaptiveMCV[] = { KC_M, KC_C, KC_V, COMBO_END };
const uint16_t PROGMEM adaptiveVCM[] = { KC_V, KC_C, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveVCMG[] = { KC_V, KC_C, KC_M, KC_G, COMBO_END };

const uint16_t PROGMEM adaptiveTNW[] = { KC_T, KC_N, KC_W, COMBO_END };
const uint16_t PROGMEM adaptiveCNT[] = { KC_C, KC_N, KC_T, COMBO_END };
const uint16_t PROGMEM adaptiveTNC[] = { KC_T, KC_N, KC_C, COMBO_END };
const uint16_t PROGMEM adaptivePNT[] = { KC_P, KC_N, KC_T, COMBO_END };
const uint16_t PROGMEM adaptiveTNP[] = { KC_T, KC_N, KC_P, COMBO_END };
const uint16_t PROGMEM adaptiveWMG[] = { KC_W, KC_M, KC_G, COMBO_END };
const uint16_t PROGMEM adaptiveGMW[] = { KC_G, KC_M, KC_W, COMBO_END };
const uint16_t PROGMEM adaptiveCMG[] = { KC_C, KC_M, KC_G, COMBO_END };
const uint16_t PROGMEM adaptiveGMC[] = { KC_G, KC_M, KC_C, COMBO_END };
const uint16_t PROGMEM adaptivePMG[] = { KC_P, KC_M, KC_G, COMBO_END };
const uint16_t PROGMEM adaptiveGMP[] = { KC_G, KC_M, KC_P, COMBO_END };
const uint16_t PROGMEM adaptiveDNC[] = { KC_D, KC_N, KC_C, COMBO_END };
const uint16_t PROGMEM adaptiveCND[] = { KC_C, KC_N, KC_D, COMBO_END };
const uint16_t PROGMEM adaptiveNTK[] = { KC_N, KC_T, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveKTN[] = { KC_K, KC_T, KC_N, COMBO_END };
const uint16_t PROGMEM adaptiveMGK[] = { KC_M, KC_G, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveKGM[] = { KC_K, KC_G, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveGMS[] = { KC_G, KC_M, KC_S, COMBO_END };
const uint16_t PROGMEM adaptiveMGS[] = { KC_M, KC_G, KC_S, COMBO_END };
const uint16_t PROGMEM adaptiveMGR[] = { KC_M, KC_G, KC_R, COMBO_END };
const uint16_t PROGMEM adaptiveWMGS[] = { KC_W, KC_M, KC_G, KC_S, COMBO_END };
const uint16_t PROGMEM adaptiveGMWS[] = { KC_G, KC_M, KC_W, KC_S, COMBO_END };
const uint16_t PROGMEM adaptiveCNTS[] = { KC_C, KC_N, KC_T, KC_S, COMBO_END };
const uint16_t PROGMEM adaptiveCTNS[] = { KC_C, KC_T, KC_N, KC_S, COMBO_END };
const uint16_t PROGMEM adaptiveKTNP[] = { KC_K, KC_T, KC_N, KC_P, COMBO_END };
const uint16_t PROGMEM adaptiveMGBR[] = { KC_M, KC_G, KC_B, KC_R, COMBO_END };

const uint16_t PROGMEM adaptiveNWZ[] = { KC_N, KC_W, LT(0,KC_Z), COMBO_END };
const uint16_t PROGMEM adaptiveZWN[] = { LT(0,KC_Z), KC_W, KC_N, COMBO_END };
const uint16_t PROGMEM adaptiveTWZ[] = { KC_T, KC_W, LT(0,KC_Z), COMBO_END };
const uint16_t PROGMEM adaptiveZWT[] = { LT(0,KC_Z), KC_W, KC_T, COMBO_END };
const uint16_t PROGMEM adaptiveMWZ[] = { KC_M, KC_W, LT(0,KC_Z), COMBO_END };
const uint16_t PROGMEM adaptiveZWM[] = { LT(0,KC_Z), KC_W, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveGWZ[] = { KC_G, KC_W, LT(0,KC_Z), COMBO_END };
const uint16_t PROGMEM adaptiveZWG[] = { LT(0,KC_Z), KC_W, KC_G, COMBO_END };
const uint16_t PROGMEM adaptiveWZg[] = { KC_W, LT(0,KC_Z), KC_GRV, COMBO_END };
const uint16_t PROGMEM adaptiveLWZ[] = { KC_L, KC_W, LT(0,KC_Z), COMBO_END };
const uint16_t PROGMEM adaptiveZWL[] = { LT(0,KC_Z), KC_W, KC_W, COMBO_END };

const uint16_t PROGMEM adaptiveNDB[] = { KC_N, KC_D, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveLDB[] = { KC_L, KC_D, KC_B, COMBO_END };

const uint16_t PROGMEM adaptiveMWV[] = { KC_M, KC_W, KC_V, COMBO_END };
const uint16_t PROGMEM adaptiveVWM[] = { KC_V, KC_W, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveWMT[] = { KC_W, KC_M, KC_T, COMBO_END };
const uint16_t PROGMEM adaptiveMWS[] = { KC_M, KC_W, KC_S, COMBO_END };
const uint16_t PROGMEM adaptiveWML[] = { KC_W, KC_M, KC_L, COMBO_END };
const uint16_t PROGMEM adaptiveMWL[] = { KC_M, KC_W, KC_L, COMBO_END };
const uint16_t PROGMEM adaptiveWMD[] = { KC_W, KC_M, KC_D, COMBO_END };
const uint16_t PROGMEM adaptiveMGB[] = { KC_M, KC_G, KC_B, COMBO_END };

const uint16_t PROGMEM adaptivePGF[] = { KC_P, KC_G, KC_F, COMBO_END };
const uint16_t PROGMEM adaptiveFGP[] = { KC_F, KC_G, KC_P, COMBO_END };
const uint16_t PROGMEM adaptiveGFP[] = { KC_G, KC_F, KC_P, COMBO_END };
const uint16_t PROGMEM adaptiveMGF[] = { KC_M, KC_G, KC_F, COMBO_END };
const uint16_t PROGMEM adaptiveLGF[] = { KC_L, KC_G, KC_F, COMBO_END };
const uint16_t PROGMEM adaptiveFGL[] = { KC_F, KC_G, KC_L, COMBO_END };
const uint16_t PROGMEM adaptiveGFL[] = { KC_G, KC_F, KC_L, COMBO_END };
const uint16_t PROGMEM adaptiveMGFP[] = { KC_M, KC_G, KC_F, KC_P, COMBO_END };
const uint16_t PROGMEM adaptiveMGPF[] = { KC_M, KC_G, KC_G, KC_F, COMBO_END };

// Vowel SFB adaptives
const uint16_t PROGMEM adaptiveJYO[] = { KC_J, KC_Y, KC_O, COMBO_END };
const uint16_t PROGMEM adaptiveAm[] = { KC_A, KC_MINUS, COMBO_END };
const uint16_t PROGMEM adaptiveAe[] = { KC_A, KC_EQUAL, COMBO_END };
const uint16_t PROGMEM adaptiveUe[] = { KC_U, KC_EQUAL, COMBO_END };
const uint16_t PROGMEM adaptiveUm[] = { KC_U, KC_MINUS, COMBO_END };

combo_t key_combos[] = {
  [AD_KM_QU] = COMBO(adaptiveKM, AD_MACRO_QU),
  [AD_pe_WQ] =   COMBO(adaptivePipeExlm, AD_MACRO_WQ),
  [AD_cpe_cWQ] = COMBO(adaptiveColPipeExlm, AD_MACRO_cWQ),
  [AD_cp_cW] =   COMBO(adaptiveColPipe, AD_MACRO_cW),
  [AD_ce_cQ] =   COMBO(adaptiveColExlm, AD_MACRO_cQ),
  [AD_MC_MC] = COMBO(adaptiveMC, AD_MACRO_MC),
  [AD_MPG_MPG] = COMBO(adaptiveMPG, AD_MACRO_MPG), // Campground
  [AD_MPT_MPT] = COMBO(adaptiveMPT, AD_MACRO_MPT), // Empty
  [AD_MPD_MPD] = COMBO(adaptiveMPD, AD_MACRO_MPD), // Clampdown
  [AD_PKM_SQU] = COMBO(adaptivePKM, AD_MACRO_SQU), // Squire
  [AD_DKM_LQU] = COMBO(adaptiveDKM, AD_MACRO_LQU), // Calque
  [AD_BKM_DQU] = COMBO(adaptiveBKM, AD_MACRO_DQU), // Headquarter
  [AD_TKM_NQU] = COMBO(adaptiveTKM, AD_MACRO_NQU), // Enquire
  [AD_GKM_MQU] = COMBO(adaptiveGKM, AD_MACRO_MQU), // Cumquat
  [AD_CKM_CQU] = COMBO(adaptiveCKM, AD_MACRO_CQU), // Acquire
  [AD_WND_WNL] = COMBO(adaptiveWND, AD_MACRO_WNL), // Download

  // V/X/Z adaptives
  [AD_WV_SV] = COMBO(adaptiveWV, AD_MACRO_SV), // Transverse
  [AD_VW_VS] = COMBO(adaptiveVW, AD_MACRO_VS), // vs
  [AD_XS_SX] = COMBO(adaptiveXS, AD_MACRO_SX), // jsx
  [AD_WB_ZB] = COMBO(adaptiveWB, AD_MACRO_ZB), // Whizbang
  [AD_BW_BZ] = COMBO(adaptiveBW, AD_MACRO_BZ), // Subzero
  [AD_WF_XF] = COMBO(adaptiveWF, AD_MACRO_XF), // Oxford
  [AD_GZW_GZW] = COMBO(adaptiveGZW, AD_MACRO_GZW), // Zugzwang
  [AD_XDC_XQU] = COMBO(adaptiveXDC, AD_MACRO_XQU),

  // ZZ, SS adaptives
  // No VV, prefer easier "vsk"
  [AD_XF_ZZ] = COMBO(adaptiveXF, AD_MACRO_ZZ), // Fizz
  [AD_SB_SS] = COMBO(adaptiveSB, AD_MACRO_SS), // Miss
  [AD_XGF_ZZL] = COMBO(adaptiveXGF, AD_MACRO_ZZL), // Rizzler
  [AD_XFG_ZZL] = COMBO(adaptiveXFG, AD_MACRO_ZZL), // Rizzler
  [AD_ZWF_ZZW] = COMBO(adaptiveZWF, AD_MACRO_ZZW), // Buzzword
  [AD_XFW_ZZW] = COMBO(adaptiveXFW, AD_MACRO_ZZW), // Buzzword
  [AD_SWB_SSW] = COMBO(adaptiveSWB, AD_MACRO_SSW), // Congresswoman
  [AD_SBW_SSW] = COMBO(adaptiveSBW, AD_MACRO_SSW), // Congresswoman
  [AD_SGB_SSM] = COMBO(adaptiveSGB, AD_MACRO_SSM), // Congressman
  [AD_SBG_SSM] = COMBO(adaptiveSBG, AD_MACRO_SMS), // Truisms
  [AD_SCB_SSC] = COMBO(adaptiveSCB, AD_MACRO_SCS), // Discs
  [AD_SBC_SSC] = COMBO(adaptiveSBC, AD_MACRO_SSC), // Crosscut
  [AD_STB_SSN] = COMBO(adaptiveSTB, AD_MACRO_STS), // Mists
  [AD_SBT_SSN] = COMBO(adaptiveSBT, AD_MACRO_SSN), // Hopelessness
  [AD_SPB_SSP] = COMBO(adaptiveSPB, AD_MACRO_SPS), // Wasps
  [AD_SBP_SSP] = COMBO(adaptiveSBP, AD_MACRO_SSP), // Misspell
  [AD_SDB_SSL] = COMBO(adaptiveSDB, AD_MACRO_SSL), // Lossless
  [AD_SBD_SSL] = COMBO(adaptiveSBD, AD_MACRO_SSL), // Lossless

  // F adaptives
  // L@G W@M M@G S@P P@L L@D D@B
  [AD_MF_WF] = COMBO(adaptiveMF, AD_MACRO_WF), // Awful
  [AD_FM_FW] = COMBO(adaptiveFM, AD_MACRO_FW), // Halfway
  [AD_GF_MF] = COMBO(adaptiveGF, AD_MACRO_MF), // Comfort
  [AD_FG_FM] = COMBO(adaptiveFG, AD_MACRO_FM), // Engulfment
  [AD_PF_SF] = COMBO(adaptivePF, AD_MACRO_SF), // Satisfy
  [AD_FP_FS] = COMBO(adaptiveFP, AD_MACRO_FS), // Hoofs
  [AD_LF_PF] = COMBO(adaptiveLF, AD_MACRO_PF), // Cupful
  [AD_FL_FP] = COMBO(adaptiveFL, AD_MACRO_FP), // Halfpipe
  [AD_DF_LF] = COMBO(adaptiveDF, AD_MACRO_LF), // Half
  [AD_FD_FL] = COMBO(adaptiveFD, AD_MACRO_FL), // Fly
  [AD_BF_DF] = COMBO(adaptiveBF, AD_MACRO_DF), // Mindful
  [AD_FK_FG] = COMBO(adaptiveFK, AD_MACRO_FG),
  [AD_KF_GF] = COMBO(adaptiveKF, AD_MACRO_GF), // Bagful
  [AD_DFM_LFW] = COMBO(adaptiveDFM, AD_MACRO_LFW), // Halfway
  [AD_FTP_FTS] = COMBO(adaptiveFTP, AD_MACRO_FTS), // Crafts
  [AD_FTM_FTW] = COMBO(adaptiveFTM, AD_MACRO_FTW), // Software
  [AD_GLF_MPF] = COMBO(adaptiveGLF, AD_MACRO_MPF), // Campfire

  // K adaptives
  // S@P C@N N@T L@D P@L W@M
  [AD_MK_WK] = COMBO(adaptiveMK, AD_MACRO_WK),
  [AD_GK_MK] = COMBO(adaptiveGK, AD_MACRO_MK),
  [AD_KG_KM] = COMBO(adaptiveKG, AD_MACRO_KM),
  [AD_DK_LK] = COMBO(adaptiveDK, AD_MACRO_LK),
  [AD_KD_KL] = COMBO(adaptiveKD, AD_MACRO_KL),
  [AD_CK_VK] = COMBO(adaptiveCK, AD_MACRO_VK),
  [AD_KC_KV] = COMBO(adaptiveKC, AD_MACRO_KV),
  [AD_NK_CK] = COMBO(adaptiveNK, AD_MACRO_CK),
  [AD_KN_KC] = COMBO(adaptiveKN, AD_MACRO_KC),
  [AD_PK_SK] = COMBO(adaptivePK, AD_MACRO_SK),
  [AD_KP_KS] = COMBO(adaptiveKP, AD_MACRO_KS),
  [AD_TK_NK] = COMBO(adaptiveTK, AD_MACRO_NK),
  [AD_KT_KN] = COMBO(adaptiveKT, AD_MACRO_KN),
  [AD_LK_PK] = COMBO(adaptiveLK, AD_MACRO_PK),
  [AD_KL_KP] = COMBO(adaptiveKL, AD_MACRO_KP),
  [AD_MKG_WKW] = COMBO(adaptiveMKG, AD_MACRO_WKW), // Awkward
  [AD_MKP_WKS] = COMBO(adaptiveMKP, AD_MACRO_WKS),
  [AD_LKG_PKG] = COMBO(adaptiveLKG, AD_MACRO_PKG), // Short for package
  [AD_DKP_LKS] = COMBO(adaptiveDKP, AD_MACRO_LKS), // Talks
  [AD_PKD_SKL] = COMBO(adaptivePKD, AD_MACRO_SKL), // Maskless
  [AD_NKP_CKS] = COMBO(adaptiveNKP, AD_MACRO_CKS),
  [AD_NKT_CKN] = COMBO(adaptiveNKT, AD_MACRO_CKN), // Acknowledge
  [AD_TKN_NKN] = COMBO(adaptiveTKN, AD_MACRO_NKN), // Unknown
  [AD_TKP_NKS] = COMBO(adaptiveTKP, AD_MACRO_NKS),
  [AD_TKL_NKL] = COMBO(adaptiveTKL, AD_MACRO_NKL), // Ankle
  [AD_LKT_LKN] = COMBO(adaptiveLKT, AD_MACRO_LKN), // Falkner
  [AD_GLK_MPK] = COMBO(adaptiveGLK, AD_MACRO_MPK), // Pumpkin
  [AD_GKC_MKV] = COMBO(adaptiveGKC, AD_MACRO_MKV), // mkv the file format
  [AD_NKG_CKL] = COMBO(adaptiveNKG, AD_MACRO_CKL), // cackle
  [AD_NKD_CKL] = COMBO(adaptiveNKD, AD_MACRO_CKL), // cackle
  [AD_NDK_CKL] = COMBO(adaptiveNDK, AD_MACRO_CKL), // cackle
  [AD_KTL_CKP] = COMBO(adaptiveKTL, AD_MACRO_CKP), // Backpack
  [AD_NKB_CKB] = COMBO(adaptiveNKB, AD_MACRO_CKB), // Blackberry
  [AD_NBK_CKB] = COMBO(adaptiveNBK, AD_MACRO_CKB), // Blackberry

  // B adaptives
  // L@D S@P C@N P@L V@P W@M M@G G@F
  [AD_FB_GB] = COMBO(adaptiveFB, AD_MACRO_GB), // Bugbear
  [AD_GB_MB] = COMBO(adaptiveGB, AD_MACRO_MB), // Thumb
  [AD_BG_BM] = COMBO(adaptiveBG, AD_MACRO_BM), // Submit
  [AD_MB_WB] = COMBO(adaptiveMB, AD_MACRO_WB), // Cowbell
  [AD_BM_BW] = COMBO(adaptiveBM, AD_MACRO_BW), // Cobweb
  [AD_BC_BV] = COMBO(adaptiveBC, AD_MACRO_BV), // Obvious
  [AD_DB_LB] = COMBO(adaptiveDB, AD_MACRO_LB), // Shelby
  [AD_BD_BL] = COMBO(adaptiveBD, AD_MACRO_BL), // Able
  [AD_LB_PB] = COMBO(adaptiveLB, AD_MACRO_PB), // Upbeat
  [AD_BL_BP] = COMBO(adaptiveBL, AD_MACRO_BP), // Webpage
  [AD_PB_SB] = COMBO(adaptivePB, AD_MACRO_SB), // Husband
  [AD_BP_BS] = COMBO(adaptiveBP, AD_MACRO_BS), // Tubs
  [AD_BK_BD] = COMBO(adaptiveBK, AD_MACRO_BD), // Abdicate
  [AD_KB_DB] = COMBO(adaptiveKB, AD_MACRO_DB), // Goodbye
  [AD_DBP_LBS] = COMBO(adaptiveDBP, AD_MACRO_LBS),
  [AD_LBP_PBS] = COMBO(adaptiveLBP, AD_MACRO_PBS), // Acronym
  [AD_BTP_BTS] = COMBO(adaptiveBTP, AD_MACRO_BTS),
  [AD_GLB_MPB] = COMBO(adaptiveGLB, AD_MACRO_MPB), // Humpback
  [AD_NGB_NGB] = COMBO(adaptiveNGB, AD_MACRO_NGB), // Springboard
  [AD_GBP_MBS] = COMBO(adaptiveGBP, AD_MACRO_MBS), // Thumbs
  [AD_GBL_MBL] = COMBO(adaptiveGBL, AD_MACRO_MBL), // Tumble

  // H digraph adaptives
  [AD_LCV_LCH] = COMBO(adaptiveLCV, AD_MACRO_LCH), // Gulch
  [AD_VCL_CHL] = COMBO(adaptiveVCL, AD_MACRO_CHL), // Chlorine
  [AD_XCN_XCH] = COMBO(adaptiveXCN, AD_MACRO_XCH), // Exchange
  [AD_NCV_NCH] = COMBO(adaptiveNCV, AD_MACRO_NCH), // Winch
  [AD_VCN_CHN] = COMBO(adaptiveVCN, AD_MACRO_CHN), // Techno
  [AD_TCV_TCH] = COMBO(adaptiveTCV, AD_MACRO_TCH), // Witch
  [AD_SCN_SCH] = COMBO(adaptiveSCN, AD_MACRO_SCH), // Schedule
  [AD_NCS_CHS] = COMBO(adaptiveNCS, AD_MACRO_CHS), // Epochs
  [AD_MCV_MCH] = COMBO(adaptiveMCV, AD_MACRO_MCH), // Armchair
  [AD_VCM_CHM] = COMBO(adaptiveVCM, AD_MACRO_CHM), // Attachment
  [AD_VCMG_CHTH] = COMBO(adaptiveVCMG, AD_MACRO_CHTH), // Chthonic

  [AD_TNW_THM] = COMBO(adaptiveTNW, AD_MACRO_THM), // Rhythm
  [AD_CNT_NTH] = COMBO(adaptiveCNT, AD_MACRO_NTH), // Tenth
  [AD_TNC_THN] = COMBO(adaptiveTNC, AD_MACRO_THN), // Ethnic
  [AD_PNT_LTH] = COMBO(adaptivePNT, AD_MACRO_LTH), // Health
  [AD_TNP_THL] = COMBO(adaptiveTNP, AD_MACRO_THL), // Athlete
  [AD_WMG_WTH] = COMBO(adaptiveWMG, AD_MACRO_WTH), // Growth
  [AD_GMW_THW] = COMBO(adaptiveGMW, AD_MACRO_THW), // Southwest
  [AD_CMG_CTH] = COMBO(adaptiveCMG, AD_MACRO_CTH), // Ecthyma
  [AD_GMC_THC] = COMBO(adaptiveGMC, AD_MACRO_THC), // Forthcoming
  [AD_PMG_PTH] = COMBO(adaptivePMG, AD_MACRO_PTH), // Depth
  [AD_GMP_THP] = COMBO(adaptiveGMP, AD_MACRO_THP), // Southpaw
  [AD_DNC_DTH] = COMBO(adaptiveDNC, AD_MACRO_DTH), // Width
  [AD_CND_THD] = COMBO(adaptiveCND, AD_MACRO_THD), // Birthday
  [AD_NTK_THF] = COMBO(adaptiveNTK, AD_MACRO_THF), // Faithful
  [AD_KTN_FTH] = COMBO(adaptiveKTN, AD_MACRO_FTH), // Fifth -- Avoid high index finger
  [AD_MGK_THB] = COMBO(adaptiveMGK, AD_MACRO_THB), // Smoothbore
  [AD_KGM_BTH] = COMBO(adaptiveKGM, AD_MACRO_BTH), // Subtheme
  [AD_GMS_THS] = COMBO(adaptiveGMS, AD_MACRO_THS), // Maths
  [AD_MGS_THS] = COMBO(adaptiveMGS, AD_MACRO_THS), // Maths
  [AD_MGR_THR] = COMBO(adaptiveMGR, AD_MACRO_THR), // Threat
  [AD_WMGS_WTHS] = COMBO(adaptiveWMGS, AD_MACRO_WTHS), // Growths
  [AD_GMWS_WTHS] = COMBO(adaptiveGMWS, AD_MACRO_WTHS), // Growths
  [AD_CNTS_NTHS] = COMBO(adaptiveCNTS, AD_MACRO_NTHS), // Tenths
  [AD_CTNS_NTHS] = COMBO(adaptiveCTNS, AD_MACRO_NTHS), // Tenths
  [AD_KTNP_FTHS] = COMBO(adaptiveKTNP, AD_MACRO_FTHS), // Fifths -- None for fifthly
  [AD_MGBR_THBR] = COMBO(adaptiveMGBR, AD_MACRO_THBR), // Toothbrush

  [AD_NWZ_NSH] = COMBO(adaptiveNWZ, AD_MACRO_NSH), // Kinship
  [AD_ZWN_SHN] = COMBO(adaptiveZWN, AD_MACRO_SHN), // Lushness
  [AD_TWZ_TSH] = COMBO(adaptiveTWZ, AD_MACRO_TSH), // Tshi
  [AD_ZWT_SHT] = COMBO(adaptiveZWT, AD_MACRO_SHT), // Shtick
  [AD_MWZ_MSH] = COMBO(adaptiveMWZ, AD_MACRO_MSH), // Gumshoe
  [AD_ZWM_SHM] = COMBO(adaptiveZWM, AD_MACRO_SHM), // Establishment
  [AD_GWZ_GSH] = COMBO(adaptiveGWZ, AD_MACRO_GSH), // Flagship
  [AD_ZWG_SHG] = COMBO(adaptiveZWG, AD_MACRO_SHG), // Bushgoat
  [AD_WZg_WSH] = COMBO(adaptiveWZg, AD_MACRO_WSH), // Fellowship
  [AD_LWZ_LSH] = COMBO(adaptiveLWZ, AD_MACRO_LSH), // Welsh
  [AD_ZWL_SHL] = COMBO(adaptiveZWL, AD_MACRO_SHL), // Bullshit

  [AD_NDB_NWH] = COMBO(adaptiveNDB, AD_MACRO_NWH), // Meanwhile
  [AD_LDB_LWH] = COMBO(adaptiveLDB, AD_MACRO_LWH), // Coolwhip

  [AD_MWV_GHN] = COMBO(adaptiveMWV, AD_MACRO_GHN), // Toughness
  [AD_VWM_NGH] = COMBO(adaptiveVWM, AD_MACRO_NGH), // Shanghai
  [AD_WMT_GHT] = COMBO(adaptiveWMT, AD_MACRO_GHT), // Thought
  [AD_MWS_GHS] = COMBO(adaptiveMWS, AD_MACRO_GHS), // Breakthroughs
  [AD_WML_GHL] = COMBO(adaptiveWML, AD_MACRO_GHL), // Highlight
  [AD_MWL_GHL] = COMBO(adaptiveMWL, AD_MACRO_GHL), // Highlight
  [AD_WMD_GHL] = COMBO(adaptiveWMD, AD_MACRO_GHL), // Highlight
  [AD_MGB_GHB] = COMBO(adaptiveMGB, AD_MACRO_GHB), // Neighbour

  [AD_PGF_SPH] = COMBO(adaptivePGF, AD_MACRO_SPH), // Sphere
  [AD_FGP_PHS] = COMBO(adaptiveFGP, AD_MACRO_PHS), // Graphs
  [AD_GFP_PHS] = COMBO(adaptiveGFP, AD_MACRO_PHS), // Graphs
  [AD_MGF_MPH] = COMBO(adaptiveMGF, AD_MACRO_MPH), // Emphasis
  [AD_LGF_LPH] = COMBO(adaptiveLGF, AD_MACRO_LPH), // Alpha
  [AD_FGL_PHL] = COMBO(adaptiveFGL, AD_MACRO_PHL), // Phlebotomy
  [AD_GFL_PHL] = COMBO(adaptiveGFL, AD_MACRO_PHL), // Phlebotomy
  [AD_MGFP_MPHS] = COMBO(adaptiveMGFP, AD_MACRO_MPHS), // Triumphs
  [AD_MGPF_MPHS] = COMBO(adaptiveMGPF, AD_MACRO_MPHS), // Triumphs

  // Vowel SFB adaptives
  [AD_JYO_JOY] = COMBO(adaptiveJYO, AD_MACRO_JOY),
  [AD_Am_AU] = COMBO(adaptiveAm, AD_MACRO_AU),
  [AD_Ae_EO] = COMBO(adaptiveAe, AD_MACRO_EO),
  [AD_Ue_UA] = COMBO(adaptiveUe, AD_MACRO_UA),
  [AD_Um_OE] = COMBO(adaptiveUm, AD_MACRO_OE),

  // H Bigram combos
  [ST_COMBO_ZW] = COMBO(comboZW, ST_MACRO_SH),
  [ST_COMBO_GM] = COMBO(comboGM, ST_MACRO_TH),
  [ST_COMBO_MG] = COMBO(comboMG, ST_MACRO_TH),
  [ST_COMBO_WM] = COMBO(comboWM, ST_MACRO_GH),
  [ST_COMBO_DB] = COMBO(comboDB, ST_MACRO_WH),
  [ST_COMBO_CV] = COMBO(comboCV, ST_MACRO_CH),
  [ST_COMBO_GF] = COMBO(comboGF, ST_MACRO_PH),
  [ST_COMBO_YH] = COMBO(comboYH, ST_MACRO_HY),
  [ST_COMBO_IH] = COMBO(comboIH, ST_MACRO_HI),
};

inline bool is_adaptive(uint16_t index) {
  switch (index) {
  case ADAPTIVE_FIRST ... ADAPTIVE_LAST: return true;
  default: return false;
  }
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
    case ST_COMBO_GM:
    case ST_COMBO_DB:
        return COMBO_TERM - 20;
    case ST_COMBO_CV:
    case ST_COMBO_ZW:
    case ST_COMBO_YH:
    case ST_COMBO_MG:
        return COMBO_TERM + 10;
    default:
        return is_adaptive(index) ? ADAPTIVE_TERM : COMBO_TERM;
    }
}

bool get_combo_must_press_in_order(uint16_t index, combo_t *combo) {
  switch (index) {
      case ST_COMBO_MG:
      case ST_COMBO_GM:
      case ST_COMBO_DB:
          return true;
      // case AD_MGFW_MPHS:
          // return false;
      default: return is_adaptive(index);
  }
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
  case ST_FORCE_S:
  case ST_FORCE_Q:
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
  case KC_BSLS:
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
    SEND_CASED_STRINGS(AD_MACRO_QU, "qu", "Qu", "QU");
    SEND_CASED_STRINGS(AD_MACRO_WQ, "wq", "wq", "WQ"); // vim :wq
    SEND_CASED_STRINGS(AD_MACRO_cWQ, ":wq", ":wq", ":WQ"); // vim :wq
    SEND_CASED_STRINGS(AD_MACRO_cW, ":w", ":w", ":W"); // vim :w
    SEND_CASED_STRINGS(AD_MACRO_cQ, ":q", ":q", ":Q"); // vim :q
    SEND_CASED_STRINGS(AD_MACRO_MC, "mc", "Mc", "MC");
    SEND_CASED_STRINGS(AD_MACRO_MPG, "mpg", "Mpg", "MPG");
    SEND_CASED_STRINGS(AD_MACRO_MPT, "mpt", "Mpt", "MPT");
    SEND_CASED_STRINGS(AD_MACRO_MPD, "mpd", "Mpd", "MPD");
    SEND_CASED_STRINGS(AD_MACRO_SQU, "squ", "Squ", "SQU");
    SEND_CASED_STRINGS(AD_MACRO_LQU, "lqu", "Lqu", "LQU");
    SEND_CASED_STRINGS(AD_MACRO_DQU, "dqu", "Dqu", "DQU");
    SEND_CASED_STRINGS(AD_MACRO_NQU, "nqu", "Nqu", "NQU");
    SEND_CASED_STRINGS(AD_MACRO_MQU, "mqu", "Mqu", "MQU");
    SEND_CASED_STRINGS(AD_MACRO_CQU, "cqu", "Cqu", "CQU");
    SEND_CASED_STRINGS(AD_MACRO_WNL, "wnl", "Wnl", "WNL");

  // X/Z adaptives
    SEND_CASED_STRINGS(AD_MACRO_SV, "sv", "Sv", "SV");
    SEND_CASED_STRINGS(AD_MACRO_VS, "vs", "Vs", "VS");
    SEND_CASED_STRINGS(AD_MACRO_SX, "sx", "Sx", "SX");
    SEND_CASED_STRINGS(AD_MACRO_ZB, "zb", "Zb", "ZB");
    SEND_CASED_STRINGS(AD_MACRO_BZ, "bz", "Bz", "BZ");
    SEND_CASED_STRINGS(AD_MACRO_XF, "xf", "Xf", "XF");
    SEND_CASED_STRINGS(AD_MACRO_GZW, "gzw", "Gzw", "GZW");
    SEND_CASED_STRINGS(AD_MACRO_XQU, "xqu", "Xqu", "XQU");

  // ZZ, SS adaptives
    SEND_CASED_STRINGS(AD_MACRO_ZZ, "zz", "Zz", "ZZ");
    SEND_CASED_STRINGS(AD_MACRO_SS, "ss", "Ss", "SS");
    SEND_CASED_STRINGS(AD_MACRO_ZZL, "zzl", "Zzl", "ZZL");
    SEND_CASED_STRINGS(AD_MACRO_ZZW, "zzw", "Zzw", "ZZW");
    SEND_CASED_STRINGS(AD_MACRO_SSW, "ssw", "Ssw", "SSW");
    SEND_CASED_STRINGS(AD_MACRO_SMS, "sms", "Sms", "SMS");
    SEND_CASED_STRINGS(AD_MACRO_SSM, "ssm", "Ssm", "SSM");
    SEND_CASED_STRINGS(AD_MACRO_SCS, "scs", "Scs", "SCS");
    SEND_CASED_STRINGS(AD_MACRO_SSC, "ssc", "Ssc", "SSC");
    SEND_CASED_STRINGS(AD_MACRO_STS, "sts", "Sts", "STS");
    SEND_CASED_STRINGS(AD_MACRO_SSN, "ssn", "Ssn", "SSN");
    SEND_CASED_STRINGS(AD_MACRO_SPS, "sps", "Sps", "SPS");
    SEND_CASED_STRINGS(AD_MACRO_SSP, "ssp", "Ssp", "SSP");
    SEND_CASED_STRINGS(AD_MACRO_SSL, "ssl", "Ssl", "SSL");

  // F adaptives
  // L@G S@C W@M S@P P@L L@D D@B
    SEND_CASED_STRINGS(AD_MACRO_SF, "sf", "Sf", "SF");
    SEND_CASED_STRINGS(AD_MACRO_FS, "fs", "Fs", "FS");
    SEND_CASED_STRINGS(AD_MACRO_WF, "wf", "Wf", "WF");
    SEND_CASED_STRINGS(AD_MACRO_FW, "fw", "Fw", "FW");
    SEND_CASED_STRINGS(AD_MACRO_MF, "mf", "Mf", "MF");
    SEND_CASED_STRINGS(AD_MACRO_FM, "fm", "Fm", "FM");
    SEND_CASED_STRINGS(AD_MACRO_PF, "pf", "Pf", "PF");
    SEND_CASED_STRINGS(AD_MACRO_FP, "fp", "Fp", "FP");
    SEND_CASED_STRINGS(AD_MACRO_LF, "lf", "Lf", "LF");
    SEND_CASED_STRINGS(AD_MACRO_FL, "fl", "Fl", "FL");
    SEND_CASED_STRINGS(AD_MACRO_DF, "df", "Df", "DF");
    SEND_CASED_STRINGS(AD_MACRO_FG, "fg", "Fg", "FG");
    SEND_CASED_STRINGS(AD_MACRO_GF, "gf", "Gf", "GF");
    SEND_CASED_STRINGS(AD_MACRO_LFW, "lfw", "Lfw", "LFW");
    SEND_CASED_STRINGS(AD_MACRO_FTS, "fts", "Fts", "FTS");
    SEND_CASED_STRINGS(AD_MACRO_FTW, "ftw", "Ftw", "FTW");
    SEND_CASED_STRINGS(AD_MACRO_MPF, "mpf", "Mpf", "MPF");

  // K adaptives
  // S@C C@N N@T L@G P@L W@M
    SEND_CASED_STRINGS(AD_MACRO_WK, "wk", "Wk", "WK");
    SEND_CASED_STRINGS(AD_MACRO_MK, "mk", "Mk", "MK");
    SEND_CASED_STRINGS(AD_MACRO_KM, "km", "Km", "KM");
    SEND_CASED_STRINGS(AD_MACRO_LK, "lk", "Lk", "LK");
    SEND_CASED_STRINGS(AD_MACRO_KL, "kl", "Kl", "KL");
    SEND_CASED_STRINGS(AD_MACRO_VK, "vk", "Vk", "VK");
    SEND_CASED_STRINGS(AD_MACRO_KV, "kv", "Kv", "KV");
    SEND_CASED_STRINGS(AD_MACRO_CK, "ck", "Ck", "CK");
    SEND_CASED_STRINGS(AD_MACRO_KC, "kc", "Kc", "KC");
    SEND_CASED_STRINGS(AD_MACRO_SK, "sk", "Sk", "SK");
    SEND_CASED_STRINGS(AD_MACRO_KS, "ks", "Ks", "KS");
    SEND_CASED_STRINGS(AD_MACRO_NK, "nk", "Nk", "NK");
    SEND_CASED_STRINGS(AD_MACRO_KN, "kn", "Kn", "KN");
    SEND_CASED_STRINGS(AD_MACRO_PK, "pk", "Pk", "PK");
    SEND_CASED_STRINGS(AD_MACRO_KP, "kp", "Kp", "KP");
    SEND_CASED_STRINGS(AD_MACRO_WKW, "wkw", "Wkw", "WKW");
    SEND_CASED_STRINGS(AD_MACRO_WKS, "wks", "Wks", "WKS");
    SEND_CASED_STRINGS(AD_MACRO_PKG, "pkg", "Lkg", "PKG");
    SEND_CASED_STRINGS(AD_MACRO_LKS, "lks", "Lks", "LKS");
    SEND_CASED_STRINGS(AD_MACRO_SKL, "kls", "Skl", "SKL");
    SEND_CASED_STRINGS(AD_MACRO_CKS, "cks", "Cks", "CKS");
    SEND_CASED_STRINGS(AD_MACRO_CKN, "ckn", "Ckn", "CKN");
    SEND_CASED_STRINGS(AD_MACRO_NKN, "nkn", "Nkn", "NKN");
    SEND_CASED_STRINGS(AD_MACRO_NKS, "nks", "Nks", "NKS");
    SEND_CASED_STRINGS(AD_MACRO_NKL, "nkl", "Nkl", "NKL");
    SEND_CASED_STRINGS(AD_MACRO_LKN, "lkn", "Lkn", "LKN");
    SEND_CASED_STRINGS(AD_MACRO_MPK, "mpk", "Mpk", "MPK"); // Pumpkin
    SEND_CASED_STRINGS(AD_MACRO_MKV, "mkv", "Mkv", "MKV");
    SEND_CASED_STRINGS(AD_MACRO_CKL, "ckl", "Ckl", "CKL"); // cackle
    SEND_CASED_STRINGS(AD_MACRO_CKP, "ckp", "Ckp", "CKP"); // Backpack
    SEND_CASED_STRINGS(AD_MACRO_CKB, "ckb", "Ckb", "CKB"); // Blackberry

  // B adaptives
  // L@D S@P C@N P@L V@P W@M M@G G@F
    SEND_CASED_STRINGS(AD_MACRO_GB, "gb", "Gb", "GB");
    SEND_CASED_STRINGS(AD_MACRO_MB, "mb", "Mb", "MB");
    SEND_CASED_STRINGS(AD_MACRO_BM, "bm", "Bm", "BM");
    SEND_CASED_STRINGS(AD_MACRO_WB, "wb", "Wb", "WB");
    SEND_CASED_STRINGS(AD_MACRO_BW, "bw", "Bw", "BW");
    SEND_CASED_STRINGS(AD_MACRO_BV, "bv", "Bv", "BV");
    SEND_CASED_STRINGS(AD_MACRO_LB, "lb", "Lb", "LB");
    SEND_CASED_STRINGS(AD_MACRO_BL, "bl", "Bl", "BL");
    SEND_CASED_STRINGS(AD_MACRO_PB, "pb", "Pb", "PB");
    SEND_CASED_STRINGS(AD_MACRO_BP, "bp", "Bp", "BP");
    SEND_CASED_STRINGS(AD_MACRO_SB, "sb", "Sb", "SB");
    SEND_CASED_STRINGS(AD_MACRO_BS, "bs", "Bs", "BS");
    SEND_CASED_STRINGS(AD_MACRO_BD, "bd", "Bd", "BD");
    SEND_CASED_STRINGS(AD_MACRO_DB, "db", "dB", "DB");
    SEND_CASED_STRINGS(AD_MACRO_LBS, "lbs", "Lbs", "LBS");
    SEND_CASED_STRINGS(AD_MACRO_PBS, "pbs", "Pbs", "PBS");
    SEND_CASED_STRINGS(AD_MACRO_BTS, "bts", "Bts", "BTS");
    SEND_CASED_STRINGS(AD_MACRO_MPB, "mpb", "Mpb", "MPB");
    SEND_CASED_STRINGS(AD_MACRO_NGB, "ngb", "Ngb", "NGB");
    SEND_CASED_STRINGS(AD_MACRO_MBS, "mbs", "Mbs", "MBS");
    SEND_CASED_STRINGS(AD_MACRO_MBL, "mbl", "Mbl", "MBL");

  // H digraph adaptives
    SEND_CASED_STRINGS(AD_MACRO_LCH, "lch", "Lch", "LCH");
    SEND_CASED_STRINGS(AD_MACRO_CHL, "chl", "Chl", "CHL");
    SEND_CASED_STRINGS(AD_MACRO_XCH, "xch", "Xch", "XCH");
    SEND_CASED_STRINGS(AD_MACRO_NCH, "nch", "Nch", "NCH");
    SEND_CASED_STRINGS(AD_MACRO_CHN, "chn", "Chn", "CHN");
    SEND_CASED_STRINGS(AD_MACRO_TCH, "tch", "Tch", "TCH");
    SEND_CASED_STRINGS(AD_MACRO_SCH, "sch", "Sch", "SCH");
    SEND_CASED_STRINGS(AD_MACRO_CHS, "chs", "Chs", "CHS");
    SEND_CASED_STRINGS(AD_MACRO_MCH, "mch", "Mch", "MCH");
    SEND_CASED_STRINGS(AD_MACRO_CHM, "chm", "Chm", "CHM");
    SEND_CASED_STRINGS(AD_MACRO_CHTH, "chth", "Chth", "CHTH");

    SEND_CASED_STRINGS(AD_MACRO_THM, "thm", "Thm", "THM");
    SEND_CASED_STRINGS(AD_MACRO_NTH, "nth", "Nth", "NTH");
    SEND_CASED_STRINGS(AD_MACRO_THN, "thn", "Thn", "THN");
    SEND_CASED_STRINGS(AD_MACRO_LTH, "lth", "Lth", "LTH");
    SEND_CASED_STRINGS(AD_MACRO_THL, "thl", "Thl", "THL");
    SEND_CASED_STRINGS(AD_MACRO_WTH, "wth", "Wth", "WTH");
    SEND_CASED_STRINGS(AD_MACRO_THW, "thw", "Thw", "THW");
    SEND_CASED_STRINGS(AD_MACRO_CTH, "cth", "Cth", "CTH");
    SEND_CASED_STRINGS(AD_MACRO_THC, "thc", "Thc", "THC");
    SEND_CASED_STRINGS(AD_MACRO_PTH, "pth", "Pth", "PTH");
    SEND_CASED_STRINGS(AD_MACRO_THP, "thp", "Thp", "THP");
    SEND_CASED_STRINGS(AD_MACRO_DTH, "dth", "Dth", "DTH");
    SEND_CASED_STRINGS(AD_MACRO_THD, "thd", "Thd", "THD");
    SEND_CASED_STRINGS(AD_MACRO_FTH, "fth", "Fth", "FTH");
    SEND_CASED_STRINGS(AD_MACRO_THF, "thf", "Thf", "THF");
    SEND_CASED_STRINGS(AD_MACRO_THB, "thb", "Thb", "THB");
    SEND_CASED_STRINGS(AD_MACRO_BTH, "bth", "Bth", "BTH");
    SEND_CASED_STRINGS(AD_MACRO_THS, "ths", "Ths", "THS");
    SEND_CASED_STRINGS(AD_MACRO_THR, "thr", "Thr", "THR");
    SEND_CASED_STRINGS(AD_MACRO_WTHS, "wths", "Wths", "WTHS");
    SEND_CASED_STRINGS(AD_MACRO_DTHS, "dths", "Dths", "DTHS");
    SEND_CASED_STRINGS(AD_MACRO_NTHS, "nths", "Nths", "NTHS");
    SEND_CASED_STRINGS(AD_MACRO_FTHS, "fths", "Fths", "FTHS");
    SEND_CASED_STRINGS(AD_MACRO_THBR, "thbr", "Thbr", "THBR");

    SEND_CASED_STRINGS(AD_MACRO_NSH, "nsh", "Nsh", "NSH");
    SEND_CASED_STRINGS(AD_MACRO_SHN, "shn", "Shn", "SHN");
    SEND_CASED_STRINGS(AD_MACRO_TSH, "tsh", "Tsh", "TSH");
    SEND_CASED_STRINGS(AD_MACRO_SHT, "sht", "Sht", "SHT");
    SEND_CASED_STRINGS(AD_MACRO_MSH, "msh", "Msh", "MSH");
    SEND_CASED_STRINGS(AD_MACRO_SHM, "shm", "Shm", "SHM");
    SEND_CASED_STRINGS(AD_MACRO_GSH, "gsh", "Gsh", "GSH");
    SEND_CASED_STRINGS(AD_MACRO_SHG, "shg", "Shg", "SHG");
    SEND_CASED_STRINGS(AD_MACRO_WSH, "wsh", "Wsh", "WSH");
    SEND_CASED_STRINGS(AD_MACRO_LSH, "lsh", "Lsh", "LSH");
    SEND_CASED_STRINGS(AD_MACRO_SHL, "shl", "Shl", "SHL");

    SEND_CASED_STRINGS(AD_MACRO_NWH, "nwh", "Nwh", "NWH");
    SEND_CASED_STRINGS(AD_MACRO_LWH, "lwh", "Lwh", "LWH");

    SEND_CASED_STRINGS(AD_MACRO_GHN, "ghn", "Ghn", "GHN");
    SEND_CASED_STRINGS(AD_MACRO_NGH, "ngh", "Ngh", "NGH");
    SEND_CASED_STRINGS(AD_MACRO_GHT, "ght", "Ght", "GHT");
    SEND_CASED_STRINGS(AD_MACRO_GHS, "ghs", "Ghs", "GHS");
    SEND_CASED_STRINGS(AD_MACRO_GHL, "ghl", "Ghl", "GHL");
    SEND_CASED_STRINGS(AD_MACRO_GHB, "ghb", "Ghb", "GHB");

    SEND_CASED_STRINGS(AD_MACRO_SPH, "sph", "Sph", "SPH");
    SEND_CASED_STRINGS(AD_MACRO_PHS, "phs", "Phs", "PHS");
    SEND_CASED_STRINGS(AD_MACRO_MPH, "mph", "Mph", "MPH");
    SEND_CASED_STRINGS(AD_MACRO_LPH, "lph", "Lph", "LPH");
    SEND_CASED_STRINGS(AD_MACRO_PHL, "phl", "Phl", "PHL");
    SEND_CASED_STRINGS(AD_MACRO_MPHS, "mphs", "Mphs", "MPHS");

  // Vowel SFB adaptives
    SEND_CASED_STRINGS(AD_MACRO_JOY, "joy", "Joy", "JOY");
    SEND_CASED_STRINGS(AD_MACRO_AU, "au", "Au", "AU");
    SEND_CASED_STRINGS(AD_MACRO_EO, "eo", "Eo", "EO");
    SEND_CASED_STRINGS(AD_MACRO_UA, "ua", "Ua", "UA");
    SEND_CASED_STRINGS(AD_MACRO_OE, "oe", "Oe", "OE");

  // H digraphs
    SEND_CASED_STRINGS(ST_MACRO_WH, "wh", "Wh", "WH");
    SEND_CASED_STRINGS(ST_MACRO_GH, "gh", "Gh", "GH");
    SEND_CASED_STRINGS(ST_MACRO_SH, "sh", "Sh", "SH");
    SEND_CASED_STRINGS(ST_MACRO_CH, "ch", "Ch", "CH");
    SEND_CASED_STRINGS(ST_MACRO_TH, "th", "Th", "TH");
    SEND_CASED_STRINGS(ST_MACRO_PH, "ph", "Ph", "PH");
    SEND_CASED_STRINGS(ST_MACRO_HY, "hy", "Hy", "HY");
    SEND_CASED_STRINGS(ST_MACRO_HI, "hi", "Hi", "HI");

  // Forced characters
    SEND_FORCED_STRING(ST_FORCE_EQUAL, "=");
    SEND_FORCED_STRING(ST_FORCE_SLASH, "/");
    SEND_FORCED_STRING(ST_FORCE_BSLS, "\\");
    SEND_FORCED_STRING(ST_FORCE_MINUS, "-");
    SEND_FORCED_STRING(ST_FORCE_LBRC, "[");
    SEND_FORCED_STRING(ST_FORCE_RBRC, "]");
    SEND_FORCED_STRING(ST_FORCE_S, "s");
    SEND_CASED_STRINGS(ST_FORCE_Q, "q", "q", "Q");

  // Tap-hold keys
    TAPHOLD_CASED(LT(0, KC_Z), "q", "Q", "q");

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
        CL_BASE, CL_BASE, CL_BASE, CL_BASE, CL_FN,
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
