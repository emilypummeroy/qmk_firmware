#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE,

  ST_FORCE_EQUAL,
  ST_FORCE_MINUS,

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
  AD_MACRO_WS,
  AD_MACRO_MC,
  AD_MACRO_VS,
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
  AD_MACRO_XP,
  AD_MACRO_XB,
  AD_MACRO_BZ,
  AD_MACRO_XC,
  AD_MACRO_GZ,
  AD_MACRO_XT,
  AD_MACRO_TZ,
  AD_MACRO_LZ,
  AD_MACRO_XF,
  AD_MACRO_GZW,
  AD_MACRO_ZSH,
  AD_MACRO_XCL,
  AD_MACRO_XQU,

  // ZZ, VV, SS adaptives
  AD_MACRO_ZZ,
  AD_MACRO_VV,
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
  AD_MACRO_NKS,
  AD_MACRO_NKL,
  AD_MACRO_LKN,
  AD_MACRO_MPK, // Pumpkin
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
  AD_MACRO_BC,
  AD_MACRO_BD,
  AD_MACRO_DB,
  AD_MACRO_LBS,
  AD_MACRO_PBS,
  AD_MACRO_BTS,
  AD_MACRO_MPB,
  AD_MACRO_NGB,
  AD_MACRO_MBS,

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
  AD_MACRO_NTH,
  AD_MACRO_THN,
  AD_MACRO_WTH,
  AD_MACRO_THW,
  AD_MACRO_DTH,
  AD_MACRO_THD,
  AD_MACRO_LTH,
  AD_MACRO_THL,
  AD_MACRO_FTH,
  AD_MACRO_THF,
  AD_MACRO_THS,
  AD_MACRO_THR,
  AD_MACRO_WTHS,
  AD_MACRO_DTHS,
  AD_MACRO_NTHS,
  AD_MACRO_FTHS,

  AD_MACRO_SHN,
  AD_MACRO_NSH,
  AD_MACRO_MSH,
  AD_MACRO_SHM,
  AD_MACRO_WSH,
  AD_MACRO_SHW,
  AD_MACRO_LSH,
  AD_MACRO_SHL,

  AD_MACRO_GWH,
  AD_MACRO_NWH,
  AD_MACRO_TWH,
  AD_MACRO_LWH,
  AD_MACRO_RWH,

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
  AD_MACRO_AU,
  AD_MACRO_EO,
  AD_MACRO_UA,
  AD_MACRO_OE,
  AD_MACRO_Eq,
  AD_MACRO_Iq,
  AD_MACRO_YI,
  AD_MACRO_Oq,
  AD_MACRO_HEq,
  AD_MACRO_IEq,
  AD_MACRO_YEq,
  AD_MACRO_YIq,

  // J adaptives
  AD_MACRO_JI,
  AD_MACRO_JO,
  AD_MACRO_JOE,
  AD_MACRO_JOq,
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
    KC_GRAVE,       LT(0,KC_X),     KC_W,           KC_M,           KC_G,           KC_F,           KC_DELETE,                                      KC_INSERT,      KC_SCLN,        KC_DOT,         KC_QUOTE,       KC_J,           KC_BSLS,        XXXXXXX,
    KC_TAB,         KC_V,           KC_C,           KC_N,           KC_T,           KC_K,           KC_BACKSPACE,                                   KC_DELETE,      KC_COMMA,       KC_A,           KC_E,           KC_I,           KC_SLASH,       XXXXXXX,
    MO(_LEFT),      KC_S,           KC_P,           KC_L,           KC_D,           KC_B,                                                                           KC_MINUS,       KC_U,           KC_O,           KC_Y,           KC_H,           XXXXXXX,
    TO(_LEFT),      XXXXXXX,        MO(_FN),        MO(_NUM),       LM(_LMOD,MOD_LSFT),             KC_ESCAPE,                                      RCTL(KC_BSPC),             LM(_RMOD,MOD_RSFT),  MO(_FN),        CW_TOGG,        XXXXXXX,        XXXXXXX,
    KC_R,           KC_ENTER,         XXXXXXX,                        XXXXXXX,        KC_ENTER,       KC_SPACE
  ),

  [_LMOD] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______,
    XXXXXXX,        ST_FORCE_Q,     KC_QUES,        KC_EXLM,        KC_PERC,        KC_AT,          _______,                                        _______,        _______,        _______,        _______,        _______,        KC_DLR,         _______,
    _______,        ST_FORCE_S,     KC_LGUI,        KC_LALT,        KC_LCTL,        KC_CIRC,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______,
    _______,        XXXXXXX,        ST_FORCE_EQUAL, KC_LCBR,        KC_RCBR,        XXXXXXX,                                                                        _______,        _______,        _______,        _______,        _______,        _______,
    XXXXXXX,        _______,        XXXXXXX,        XXXXXXX,        _______,                        _______,                                        KC_BSPC,                        OSM(MOD_RSFT),  _______,        _______,        _______,        _______,
    XXXXXXX,        XXXXXXX,        _______,                        _______,        _______,        _______
  ),

  [_RMOD] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        KC_ASTR,        KC_HASH,        KC_AMPR,        KC_PIPE,        KC_DLR,         _______,
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        KC_PLUS,        KC_RCTL,        KC_RALT,        KC_RGUI,        _______,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,                                                                        ST_FORCE_MINUS, KC_LPRN,        KC_RPRN,        ST_FORCE_EQUAL, ST_FORCE_EQUAL, _______,
    XXXXXXX,        _______,        XXXXXXX,        XXXXXXX,        KC_SPACE,                       _______,                                        KC_BSPC,                        _______,        _______,        _______,        _______,        _______,
    KC_R,           _______,        _______,                        _______,        XXXXXXX,        XXXXXXX
  ),

  [_NUM] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______,
    _______,        KC_CIRC,        KC_QUES,        KC_EXLM,        KC_PERC,        KC_AT,          _______,                                        TO(_NUMPAD),    KC_ASTR,        KC_7,           KC_8,           KC_9,           KC_DLR,         _______,
    _______, KC_COMMA, MT(MOD_LGUI,KC_LEFT), MT(MOD_LALT,KC_UP), MT(MOD_LCTL,KC_DOWN), KC_RIGHT,    _______,                                        _______,        KC_PLUS,        KC_4,           KC_5,           KC_6,           _______,        _______,
    _______,        KC_LPRN,        KC_EQUAL,       KC_LBRC,        KC_RBRC,        KC_RPRN,                                                                        KC_MINUS,       KC_1,           KC_2,           KC_3,           KC_EQUAL,       _______,
    TO(0),          _______,        TO(_FN),        TO(0),          KC_LEFT_SHIFT,                  _______,                                        KC_BSPC,                        KC_0,           KC_DOT,         KC_EQUAL,       _______,        TO(0),
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
    _______,        KC_F13,         KC_F9,          KC_F8,          KC_F7,          KC_F23,         KC_F24,                                         KC_INSERT,      KC_ESCAPE,      KC_MNXT,        KC_MPRV,        KC_MPLY,        KC_MUTE,        KC_VOLU,
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
  AD_qQ_WQ,
  AD_WV_WS,
  AD_MC_MC,
  AD_VW_VS,
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
  AD_VP_XP,
  AD_WB_XB,
  AD_BW_BZ,
  AD_XC_XC,
  AD_GX_GZ,
  AD_XT_XT,
  AD_XN_XT,
  AD_TX_TZ,
  AD_LX_LZ,
  AD_WF_XF,
  AD_GXW_GZW,
  AD_gXW_ZSH,
  AD_XCL_XCL,
  AD_WKM_XQU,

  // ZZ, VV, SS adaptives
  AD_XF_ZZ,
  AD_VK_VV,
  AD_SB_SS,
  AD_XGF_ZZL,
  AD_XFG_ZZL,
  AD_XWF_ZZW,
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
  AD_NTK_CKN,
  AD_NKT_CKN,
  AD_TKP_NKS,
  AD_TKL_NKL,
  AD_LKT_LKN,
  AD_GLK_MPK,
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
  AD_BN_BC,
  AD_BK_BD,
  AD_KB_DB,
  AD_DBP_LBS,
  AD_LBP_PBS,
  AD_BTP_BTS, // doubts
  AD_GLB_MPB,
  AD_NGB_NGB,
  AD_GBP_MBS,

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

  AD_CMG_NTH,
  AD_GMC_THN,
  AD_WMG_WTH,
  AD_GMW_THW,
  AD_PMG_LTH,
  AD_GMP_THL,
  AD_MGK_THF,
  AD_FGM_FTH,
  AD_GMS_THS,
  AD_MGS_THS,
  AD_MGR_THR,
  AD_WMGS_WTHS,
  AD_GMWS_WTHS,
  AD_CMGS_NTHS,
  AD_CGMS_NTHS,
  AD_FGMP_FTHS,

  AD_BDN_SHN,
  AD_NDB_NSH,
  AD_MTK_MSH, // Gumshoe
  AD_KTM_SHM, // Establishment
  AD_MTB_WSH, // Fellowship
  AD_BTM_SHW, // Bushwalk
  AD_LDB_LSH,
  AD_BDL_SHL,

  AD_GWX_GWH,
  AD_NWX_NWH,
  AD_TWX_TWH,
  AD_LWX_LWH,
  AD_RWX_RWH,

  AD_XWM_GHN,
  AD_MWX_NGH,
  AD_WMT_GHT,
  AD_MWV_GHS,
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
  AD_Am_AU,
  AD_Ac_EO,
  AD_Uc_UA,
  AD_Um_OE,
  AD_Ed_Eq,
  AD_Iq_Iq,
  AD_Is_YI,
  AD_sI_YI,
  AD_Od_Oq,
  AD_HEd_HEq,
  AD_IEd_IEq,
  AD_YEd_YEq,
  AD_sIq_YIq,

  // J adaptives
  AD_qI_JI,
  AD_Jq_JO,
  AD_qds_JOE,
  AD_Jqd_JOq,
  AD_qJ_OJ,

  // Miscellaneous letters
  AD_WXg_WQ, ADAPTIVE_LAST = AD_WXg_WQ,
  ST_COMBO_gX_Q,

  // H Bigram combos
  ST_COMBO_XW,
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
const uint16_t PROGMEM comboXW[] = { LT(0,KC_X), KC_W, COMBO_END };
const uint16_t PROGMEM comboGM[] = { KC_G, KC_M, COMBO_END};
const uint16_t PROGMEM comboMG[] = { KC_M, KC_G, COMBO_END};
const uint16_t PROGMEM comboWM[] = { KC_W, KC_M, COMBO_END};
const uint16_t PROGMEM comboDB[] = { KC_D, KC_B, COMBO_END};
const uint16_t PROGMEM comboCV[] = { KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM comboGF[] = { KC_G, KC_F, COMBO_END};
const uint16_t PROGMEM comboYH[] = { KC_Y, KC_H, COMBO_END };
const uint16_t PROGMEM comboIH[] = { KC_I, KC_H, COMBO_END };

// Miscellaneous letters
const uint16_t PROGMEM combogX[] = { KC_GRAVE, LT(0,KC_X), COMBO_END };
const uint16_t PROGMEM adaptiveWXg[] = { KC_W, LT(0,KC_X), KC_GRAVE, COMBO_END };

const uint16_t PROGMEM adaptiveKM[] = { KC_K, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveqQ[] = { KC_QUES, ST_FORCE_Q, COMBO_END };
const uint16_t PROGMEM adaptiveWV[] = { KC_W, KC_V, COMBO_END };
const uint16_t PROGMEM adaptiveMC[] = { KC_M, KC_C, COMBO_END };
const uint16_t PROGMEM adaptiveVW[] = { KC_V, KC_W, COMBO_END };
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
const uint16_t PROGMEM adaptiveVP[] = { KC_V, KC_P, COMBO_END };
const uint16_t PROGMEM adaptiveWB[] = { KC_W, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveBW[] = { KC_B, KC_W, COMBO_END };
const uint16_t PROGMEM adaptiveXC[] = { LT(0,KC_X), KC_C, COMBO_END };
const uint16_t PROGMEM adaptiveGX[] = { KC_G, LT(0,KC_X), COMBO_END };
const uint16_t PROGMEM adaptiveXT[] = { LT(0,KC_X), KC_T, COMBO_END };
const uint16_t PROGMEM adaptiveXN[] = { LT(0,KC_X), KC_N, COMBO_END };
const uint16_t PROGMEM adaptiveTX[] = { KC_T, LT(0,KC_X), COMBO_END };
const uint16_t PROGMEM adaptiveLX[] = { KC_L, LT(0,KC_X), COMBO_END };
const uint16_t PROGMEM adaptiveWF[] = { KC_W, KC_F, COMBO_END };
const uint16_t PROGMEM adaptiveGXW[] = { KC_G, LT(0,KC_X), KC_W, COMBO_END };
const uint16_t PROGMEM adaptivegXW[] = { KC_GRV, LT(0,KC_X), KC_W, COMBO_END };
const uint16_t PROGMEM adaptiveXCL[] = { LT(0,KC_X), KC_C, KC_L, COMBO_END };
const uint16_t PROGMEM adaptiveWKM[] = { KC_W, KC_K, KC_M, COMBO_END };

// ZZ, VV, SS adaptives
const uint16_t PROGMEM adaptiveXF[] = { LT(0,KC_X), KC_F, COMBO_END };
const uint16_t PROGMEM adaptiveVK[] = { KC_V, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveSB[] = { KC_S, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveXGF[] = { LT(0,KC_X), KC_G, KC_F, COMBO_END };
const uint16_t PROGMEM adaptiveXFG[] = { LT(0,KC_X), KC_F, KC_G, COMBO_END };
const uint16_t PROGMEM adaptiveXWF[] = { LT(0,KC_X), KC_W, KC_F, COMBO_END };
const uint16_t PROGMEM adaptiveXFW[] = { LT(0,KC_X), KC_F, KC_W, COMBO_END };
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
const uint16_t PROGMEM adaptiveNTK[] = { KC_N, KC_T, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveNKT[] = { KC_N, KC_K, KC_T, COMBO_END };
const uint16_t PROGMEM adaptiveTKP[] = { KC_T, KC_K, KC_P, COMBO_END };
const uint16_t PROGMEM adaptiveTKL[] = { KC_T, KC_K, KC_L, COMBO_END };
const uint16_t PROGMEM adaptiveLKT[] = { KC_L, KC_K, KC_T, COMBO_END };
const uint16_t PROGMEM adaptiveGLK[] = { KC_G, KC_L, KC_K, COMBO_END };
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
const uint16_t PROGMEM adaptiveBN[] = { KC_B, KC_N, COMBO_END };
const uint16_t PROGMEM adaptiveBK[] = { KC_B, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveKB[] = { KC_K, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveDBP[] = { KC_D, KC_B, KC_P, COMBO_END };
const uint16_t PROGMEM adaptiveLBP[] = { KC_L, KC_B, KC_P, COMBO_END };
const uint16_t PROGMEM adaptiveBTP[] = { KC_B, KC_T, KC_P, COMBO_END };
const uint16_t PROGMEM adaptiveGLB[] = { KC_G, KC_L, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveNGB[] = { KC_N, KC_G, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveGBP[] = { KC_G, KC_B, KC_P, COMBO_END };

// H digraph adaptives
const uint16_t PROGMEM adaptiveLCV[] = { KC_L, KC_C, KC_V, COMBO_END };
const uint16_t PROGMEM adaptiveVCL[] = { KC_V, KC_C, KC_L, COMBO_END };
const uint16_t PROGMEM adaptiveXCN[] = { LT(0,KC_X), KC_C, KC_N, COMBO_END };
const uint16_t PROGMEM adaptiveNCV[] = { KC_N, KC_C, KC_V, COMBO_END };
const uint16_t PROGMEM adaptiveVCN[] = { KC_V, KC_C, KC_N, COMBO_END };
const uint16_t PROGMEM adaptiveTCV[] = { KC_T, KC_C, KC_V, COMBO_END };
const uint16_t PROGMEM adaptiveSCN[] = { KC_S, KC_C, KC_N, COMBO_END };
const uint16_t PROGMEM adaptiveNCS[] = { KC_N, KC_C, KC_S, COMBO_END };
const uint16_t PROGMEM adaptiveMCV[] = { KC_M, KC_C, KC_V, COMBO_END };
const uint16_t PROGMEM adaptiveVCM[] = { KC_V, KC_C, KC_M, COMBO_END };

const uint16_t PROGMEM adaptiveCMG[] = { KC_C, KC_M, KC_G, COMBO_END };
const uint16_t PROGMEM adaptiveGMC[] = { KC_G, KC_M, KC_C, COMBO_END };
const uint16_t PROGMEM adaptiveWMG[] = { KC_W, KC_M, KC_G, COMBO_END };
const uint16_t PROGMEM adaptiveGMW[] = { KC_G, KC_M, KC_W, COMBO_END };
const uint16_t PROGMEM adaptivePMG[] = { KC_P, KC_M, KC_G, COMBO_END };
const uint16_t PROGMEM adaptiveGMP[] = { KC_G, KC_M, KC_P, COMBO_END };
const uint16_t PROGMEM adaptiveMGK[] = { KC_M, KC_G, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveFGM[] = { KC_F, KC_G, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveGMS[] = { KC_G, KC_M, KC_S, COMBO_END };
const uint16_t PROGMEM adaptiveMGS[] = { KC_M, KC_G, KC_S, COMBO_END };
const uint16_t PROGMEM adaptiveMGR[] = { KC_M, KC_G, KC_R, COMBO_END };
const uint16_t PROGMEM adaptiveWMGS[] = { KC_W, KC_M, KC_G, KC_S, COMBO_END };
const uint16_t PROGMEM adaptiveGMWS[] = { KC_G, KC_M, KC_W, KC_S, COMBO_END };
const uint16_t PROGMEM adaptiveCMGS[] = { KC_C, KC_M, KC_G, KC_S, COMBO_END };
const uint16_t PROGMEM adaptiveCGMS[] = { KC_C, KC_G, KC_M, KC_S, COMBO_END };
const uint16_t PROGMEM adaptiveFGMP[] = { KC_F, KC_G, KC_M, KC_P, COMBO_END };

const uint16_t PROGMEM adaptiveBDN[] = { KC_B, KC_D, KC_N, COMBO_END };
const uint16_t PROGMEM adaptiveNDB[] = { KC_N, KC_D, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveMTK[] = { KC_M, KC_T, KC_K, COMBO_END };
const uint16_t PROGMEM adaptiveKTM[] = { KC_K, KC_T, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveMTB[] = { KC_M, KC_T, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveBTM[] = { KC_B, KC_T, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveLDB[] = { KC_L, KC_D, KC_B, COMBO_END };
const uint16_t PROGMEM adaptiveBDL[] = { KC_B, KC_D, KC_L, COMBO_END };

const uint16_t PROGMEM adaptiveGWX[] = { KC_W, KC_W, LT(0,KC_X), COMBO_END };
const uint16_t PROGMEM adaptiveNWX[] = { KC_N, KC_W, LT(0,KC_X), COMBO_END };
const uint16_t PROGMEM adaptiveTWX[] = { KC_T, KC_W, LT(0,KC_X), COMBO_END };
const uint16_t PROGMEM adaptiveLWX[] = { KC_L, KC_W, LT(0,KC_X), COMBO_END };
const uint16_t PROGMEM adaptiveRWX[] = { KC_R, KC_W, LT(0,KC_X), COMBO_END };

const uint16_t PROGMEM adaptiveXWM[] = { LT(0,KC_X), KC_W, KC_M, COMBO_END };
const uint16_t PROGMEM adaptiveMWX[] = { KC_M, KC_W, LT(0,KC_X), COMBO_END };
const uint16_t PROGMEM adaptiveWMT[] = { KC_W, KC_M, KC_T, COMBO_END };
const uint16_t PROGMEM adaptiveMWV[] = { KC_M, KC_W, KC_V, COMBO_END };
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
const uint16_t PROGMEM adaptiveAm[] = { KC_A, KC_MINUS, COMBO_END };
const uint16_t PROGMEM adaptiveAc[] = { KC_A, KC_COMMA, COMBO_END };
const uint16_t PROGMEM adaptiveUc[] = { KC_U, KC_COMMA, COMBO_END };
const uint16_t PROGMEM adaptiveUm[] = { KC_U, KC_MINUS, COMBO_END };
const uint16_t PROGMEM adaptiveEd[] = { KC_E, KC_DOT, COMBO_END };
const uint16_t PROGMEM adaptiveIq[] = { KC_I, KC_QUOTE, COMBO_END };
const uint16_t PROGMEM adaptiveIs[] = { KC_I, KC_SLASH, COMBO_END };
const uint16_t PROGMEM adaptivesI[] = { KC_SLASH, KC_I, COMBO_END };
const uint16_t PROGMEM adaptiveOd[] = { KC_O, KC_DOT, COMBO_END };
const uint16_t PROGMEM adaptiveHEd[] = { KC_H, KC_E, KC_DOT, COMBO_END };
const uint16_t PROGMEM adaptiveIEd[] = { KC_I, KC_E, KC_DOT, COMBO_END };
const uint16_t PROGMEM adaptiveYEd[] = { KC_Y, KC_E, KC_DOT, COMBO_END };
const uint16_t PROGMEM adaptivesIq[] = { KC_SLASH, KC_I, KC_QUOTE, COMBO_END };

// J adaptives
const uint16_t PROGMEM adaptiveqI[] = { KC_QUOTE, KC_I, COMBO_END };
const uint16_t PROGMEM adaptiveJq[] = { KC_J, KC_QUOTE, COMBO_END };
const uint16_t PROGMEM adaptiveqds[] = { KC_QUOTE, KC_DOT, KC_SCLN, COMBO_END };
const uint16_t PROGMEM adaptiveJqd[] = { KC_J, KC_QUOTE, KC_DOT, COMBO_END };
const uint16_t PROGMEM adaptiveqJ[] = { KC_QUOTE, KC_J, COMBO_END };

combo_t key_combos[] = {
  [AD_KM_QU] = COMBO(adaptiveKM, AD_MACRO_QU),
  [AD_qQ_WQ] = COMBO(adaptiveqQ, AD_MACRO_WQ),
  [AD_WV_WS] = COMBO(adaptiveWV, AD_MACRO_WS),
  [AD_MC_MC] = COMBO(adaptiveMC, AD_MACRO_MC),
  [AD_VW_VS] = COMBO(adaptiveVW, AD_MACRO_VS),
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

  // X/Z adaptives
  [AD_VP_XP] = COMBO(adaptiveVP, AD_MACRO_XP),
  [AD_WB_XB] = COMBO(adaptiveWB, AD_MACRO_XB), // Xbox
  [AD_BW_BZ] = COMBO(adaptiveBW, AD_MACRO_BZ), // Subzero
  [AD_XC_XC] = COMBO(adaptiveXC, AD_MACRO_XC),
  [AD_GX_GZ] = COMBO(adaptiveGX, AD_MACRO_GZ), // Zigzag
  [AD_XT_XT] = COMBO(adaptiveXT, AD_MACRO_XT),
  [AD_XN_XT] = COMBO(adaptiveXN, AD_MACRO_XT),
  [AD_TX_TZ] = COMBO(adaptiveTX, AD_MACRO_TZ),
  [AD_LX_LZ] = COMBO(adaptiveLX, AD_MACRO_LZ), // Calzone
  [AD_WF_XF] = COMBO(adaptiveWF, AD_MACRO_XF), // Oxford
  [AD_GXW_GZW] = COMBO(adaptiveGXW, AD_MACRO_GZW), // Zugzwang
  [AD_gXW_ZSH] = COMBO(adaptivegXW, AD_MACRO_ZSH), // Oh my zsh!
  [AD_XCL_XCL] = COMBO(adaptiveXCL, AD_MACRO_XCL), // Exclude
  [AD_WKM_XQU] = COMBO(adaptiveWKM, AD_MACRO_XQU),

  // ZZ, VV, SS adaptives
  [AD_XF_ZZ] = COMBO(adaptiveXF, AD_MACRO_ZZ), // Fizz
  [AD_VK_VV] = COMBO(adaptiveVK, AD_MACRO_VV), // Savvy
  [AD_SB_SS] = COMBO(adaptiveSB, AD_MACRO_SS), // Miss
  [AD_XGF_ZZL] = COMBO(adaptiveXGF, AD_MACRO_ZZL), // Rizzler
  [AD_XFG_ZZL] = COMBO(adaptiveXFG, AD_MACRO_ZZL), // Rizzler
  [AD_XWF_ZZW] = COMBO(adaptiveXWF, AD_MACRO_ZZW), // Buzzword
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
  [AD_NTK_CKN] = COMBO(adaptiveNTK, AD_MACRO_CKN), // Acknowledge
  [AD_NKT_CKN] = COMBO(adaptiveNKT, AD_MACRO_CKN), // Acknowledge
  [AD_TKP_NKS] = COMBO(adaptiveTKP, AD_MACRO_NKS),
  [AD_TKL_NKL] = COMBO(adaptiveTKL, AD_MACRO_NKL), // Ankle
  [AD_LKT_LKN] = COMBO(adaptiveLKT, AD_MACRO_LKN), // Falkner
  [AD_GLK_MPK] = COMBO(adaptiveGLK, AD_MACRO_MPK), // Pumpkin
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
  [AD_BN_BC] = COMBO(adaptiveBN, AD_MACRO_BC), // Webcam
  [AD_BK_BD] = COMBO(adaptiveBK, AD_MACRO_BD), // Abdicate
  [AD_KB_DB] = COMBO(adaptiveKB, AD_MACRO_DB), // Goodbye
  [AD_DBP_LBS] = COMBO(adaptiveDBP, AD_MACRO_LBS),
  [AD_LBP_PBS] = COMBO(adaptiveLBP, AD_MACRO_PBS), // Acronym
  [AD_BTP_BTS] = COMBO(adaptiveBTP, AD_MACRO_BTS),
  [AD_GLB_MPB] = COMBO(adaptiveGLB, AD_MACRO_MPB), // Humpback
  [AD_NGB_NGB] = COMBO(adaptiveNGB, AD_MACRO_NGB), // Springboard
  [AD_GBP_MBS] = COMBO(adaptiveGBP, AD_MACRO_MBS), // Thumbs
  // No MBL because it would be more twisty than typing with M+BL

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

  [AD_CMG_NTH] = COMBO(adaptiveCMG, AD_MACRO_NTH), // Tenth
  [AD_GMC_THN] = COMBO(adaptiveGMC, AD_MACRO_THN), // Ethnic
  [AD_WMG_WTH] = COMBO(adaptiveWMG, AD_MACRO_WTH), // Growth
  [AD_GMW_THW] = COMBO(adaptiveGMW, AD_MACRO_THW), // Southwest
  [AD_PMG_LTH] = COMBO(adaptivePMG, AD_MACRO_LTH), // Health
  [AD_GMP_THL] = COMBO(adaptiveGMP, AD_MACRO_THL), // Athlete
  [AD_MGK_THF] = COMBO(adaptiveMGK, AD_MACRO_THF), // Faithful
  [AD_FGM_FTH] = COMBO(adaptiveFGM, AD_MACRO_FTH), // Fifth
  [AD_GMS_THS] = COMBO(adaptiveGMS, AD_MACRO_THS), // Maths
  [AD_MGS_THS] = COMBO(adaptiveMGS, AD_MACRO_THS), // Maths
  [AD_MGR_THR] = COMBO(adaptiveMGR, AD_MACRO_THR), // Threat
  [AD_WMGS_WTHS] = COMBO(adaptiveWMGS, AD_MACRO_WTHS), // Growths
  [AD_GMWS_WTHS] = COMBO(adaptiveGMWS, AD_MACRO_WTHS), // Growths
  [AD_CMGS_NTHS] = COMBO(adaptiveCMGS, AD_MACRO_NTHS), // Tenths
  [AD_CGMS_NTHS] = COMBO(adaptiveCGMS, AD_MACRO_NTHS), // Tenths
  [AD_FGMP_FTHS] = COMBO(adaptiveFGMP, AD_MACRO_FTHS), // Fifths

  [AD_BDN_SHN] = COMBO(adaptiveBDN, AD_MACRO_SHN),
  [AD_NDB_NSH] = COMBO(adaptiveNDB, AD_MACRO_NSH),
  [AD_MTK_MSH] = COMBO(adaptiveMTK, AD_MACRO_MSH), // Gumshoe
  [AD_KTM_SHM] = COMBO(adaptiveKTM, AD_MACRO_SHM), // Establishment
  [AD_MTB_WSH] = COMBO(adaptiveMTB, AD_MACRO_WSH), // Fellowship
  [AD_BTM_SHW] = COMBO(adaptiveBTM, AD_MACRO_SHW), // Bushwalk
  [AD_LDB_LSH] = COMBO(adaptiveLDB, AD_MACRO_LSH),
  [AD_BDL_SHL] = COMBO(adaptiveBDL, AD_MACRO_SHL),

  [AD_GWX_GWH] = COMBO(adaptiveGWX, AD_MACRO_GWH), // Cogwheel
  [AD_NWX_NWH] = COMBO(adaptiveNWX, AD_MACRO_NWH), // Meanwhile
  [AD_TWX_TWH] = COMBO(adaptiveTWX, AD_MACRO_TWH), // Erstwhile
  [AD_LWX_LWH] = COMBO(adaptiveLWX, AD_MACRO_LWH), // Coolwhip
  [AD_RWX_RWH] = COMBO(adaptiveRWX, AD_MACRO_RWH), // Overwhelm

  [AD_XWM_GHN] = COMBO(adaptiveXWM, AD_MACRO_GHN), // Toughness
  [AD_MWX_NGH] = COMBO(adaptiveMWX, AD_MACRO_NGH), // Shanghai
  [AD_WMT_GHT] = COMBO(adaptiveWMT, AD_MACRO_GHT), // Thought
  [AD_MWV_GHS] = COMBO(adaptiveMWV, AD_MACRO_GHS), // Breakthroughs
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
  [AD_Am_AU] = COMBO(adaptiveAm, AD_MACRO_AU),
  [AD_Ac_EO] = COMBO(adaptiveAc, AD_MACRO_EO),
  [AD_Uc_UA] = COMBO(adaptiveUc, AD_MACRO_UA),
  [AD_Um_OE] = COMBO(adaptiveUm, AD_MACRO_OE),
  [AD_Ed_Eq] = COMBO(adaptiveEd, AD_MACRO_Eq),
  [AD_Iq_Iq] = COMBO(adaptiveIq, AD_MACRO_Iq),
  [AD_Is_YI] = COMBO(adaptiveIs, AD_MACRO_YI),
  [AD_sI_YI] = COMBO(adaptivesI, AD_MACRO_YI),
  [AD_Od_Oq] = COMBO(adaptiveOd, AD_MACRO_Oq),
  [AD_HEd_HEq] = COMBO(adaptiveHEd, AD_MACRO_HEq),
  [AD_IEd_IEq] = COMBO(adaptiveIEd, AD_MACRO_IEq),
  [AD_YEd_YEq] = COMBO(adaptiveYEd, AD_MACRO_YEq),
  [AD_sIq_YIq] = COMBO(adaptivesIq, AD_MACRO_YIq),

  // J adaptives
  [AD_qI_JI] = COMBO(adaptiveqI, AD_MACRO_JI),
  [AD_Jq_JO] = COMBO(adaptiveJq, AD_MACRO_JO),
  [AD_qds_JOE] = COMBO(adaptiveqds, AD_MACRO_JOE),
  [AD_Jqd_JOq] = COMBO(adaptiveJqd, AD_MACRO_JOq),
  [AD_qJ_OJ] = COMBO(adaptiveqJ, AD_MACRO_OJ),

  // Miscellaneous combos
  [AD_WXg_WQ] = COMBO(adaptiveWXg, AD_MACRO_WQ), // :wq for vim
  [ST_COMBO_gX_Q] = COMBO(combogX, KC_Q),

  // H Bigram combos
  [ST_COMBO_XW] = COMBO(comboXW, ST_MACRO_WH),
  [ST_COMBO_GM] = COMBO(comboGM, ST_MACRO_TH),
  [ST_COMBO_MG] = COMBO(comboMG, ST_MACRO_TH),
  [ST_COMBO_WM] = COMBO(comboWM, ST_MACRO_GH),
  [ST_COMBO_DB] = COMBO(comboDB, ST_MACRO_SH), // Maybe this should be ordered?
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
    case ST_COMBO_XW:
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
    SEND_CASED_STRINGS(AD_MACRO_WS, "ws", "Ws", "WS");
    SEND_CASED_STRINGS(AD_MACRO_MC, "mc", "Mc", "MC");
    SEND_CASED_STRINGS(AD_MACRO_VS, "vs", "Vs", "VS");
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
    SEND_CASED_STRINGS(AD_MACRO_XP, "xp", "Xp", "XP");
    SEND_CASED_STRINGS(AD_MACRO_XB, "xb", "Xb", "XB");
    SEND_CASED_STRINGS(AD_MACRO_BZ, "bz", "Bz", "BZ");
    SEND_CASED_STRINGS(AD_MACRO_XC, "xc", "Xc", "XC");
    SEND_CASED_STRINGS(AD_MACRO_GZ, "gz", "Gz", "GZ");
    SEND_CASED_STRINGS(AD_MACRO_XT, "xt", "Xt", "XT");
    SEND_CASED_STRINGS(AD_MACRO_TZ, "tz", "Tz", "TZ");
    SEND_CASED_STRINGS(AD_MACRO_LZ, "lz", "Lz", "LZ");
    SEND_CASED_STRINGS(AD_MACRO_XF, "xf", "Xf", "XF");
    SEND_CASED_STRINGS(AD_MACRO_GZW, "gzw", "Gzw", "GZW");
    SEND_CASED_STRINGS(AD_MACRO_ZSH, "zsh", "Zsh", "ZSH");
    SEND_CASED_STRINGS(AD_MACRO_XCL, "xcl", "Xcl", "XCL");
    SEND_CASED_STRINGS(AD_MACRO_XQU, "xqu", "Xqu", "XQU");

  // ZZ, VV, SS adaptives
    SEND_CASED_STRINGS(AD_MACRO_ZZ, "zz", "Zz", "ZZ");
    SEND_CASED_STRINGS(AD_MACRO_VV, "vv", "Vv", "VV");
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
    SEND_CASED_STRINGS(AD_MACRO_NKS, "nks", "Nks", "NKS");
    SEND_CASED_STRINGS(AD_MACRO_NKL, "nkl", "Nkl", "NKL");
    SEND_CASED_STRINGS(AD_MACRO_LKN, "lkn", "Lkn", "LKN");
    SEND_CASED_STRINGS(AD_MACRO_MPK, "mpk", "Mpk", "MPK"); // Pumpkin
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
    SEND_CASED_STRINGS(AD_MACRO_BC, "bc", "Bc", "BC");
    SEND_CASED_STRINGS(AD_MACRO_BD, "bd", "Bd", "BD");
    SEND_CASED_STRINGS(AD_MACRO_DB, "db", "dB", "DB");
    SEND_CASED_STRINGS(AD_MACRO_LBS, "lbs", "Lbs", "LBS");
    SEND_CASED_STRINGS(AD_MACRO_PBS, "pbs", "Pbs", "PBS");
    SEND_CASED_STRINGS(AD_MACRO_BTS, "bts", "Bts", "BTS");
    SEND_CASED_STRINGS(AD_MACRO_MPB, "mpb", "Mpb", "MPB");
    SEND_CASED_STRINGS(AD_MACRO_NGB, "ngb", "Ngb", "NGB");
    SEND_CASED_STRINGS(AD_MACRO_MBS, "mbs", "Mbs", "MBS");

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

    SEND_CASED_STRINGS(AD_MACRO_NTH, "nth", "Nth", "NTH");
    SEND_CASED_STRINGS(AD_MACRO_THN, "thn", "Thn", "THN");
    SEND_CASED_STRINGS(AD_MACRO_WTH, "wth", "Wth", "WTH");
    SEND_CASED_STRINGS(AD_MACRO_THW, "thw", "Thw", "THW");
    SEND_CASED_STRINGS(AD_MACRO_DTH, "dth", "Dth", "DTH");
    SEND_CASED_STRINGS(AD_MACRO_THD, "thd", "Thd", "THD");
    SEND_CASED_STRINGS(AD_MACRO_LTH, "lth", "Lth", "LTH");
    SEND_CASED_STRINGS(AD_MACRO_FTH, "fth", "Fth", "FTH");
    SEND_CASED_STRINGS(AD_MACRO_THF, "thf", "Thf", "THF");
    SEND_CASED_STRINGS(AD_MACRO_THL, "thl", "Thl", "THL");
    SEND_CASED_STRINGS(AD_MACRO_THS, "ths", "Ths", "THS");
    SEND_CASED_STRINGS(AD_MACRO_THR, "thr", "Thr", "THR");
    SEND_CASED_STRINGS(AD_MACRO_WTHS, "wths", "Wths", "WTHS");
    SEND_CASED_STRINGS(AD_MACRO_DTHS, "dths", "Dths", "DTHS");
    SEND_CASED_STRINGS(AD_MACRO_NTHS, "nths", "Nths", "NTHS");
    SEND_CASED_STRINGS(AD_MACRO_FTHS, "fths", "Fths", "FTHS");

    SEND_CASED_STRINGS(AD_MACRO_SHN, "shn", "Shn", "SHN");
    SEND_CASED_STRINGS(AD_MACRO_NSH, "nsh", "Nsh", "NSH");
    SEND_CASED_STRINGS(AD_MACRO_MSH, "msh", "Msh", "MSH");
    SEND_CASED_STRINGS(AD_MACRO_SHM, "shm", "Shm", "SHM");
    SEND_CASED_STRINGS(AD_MACRO_WSH, "wsh", "Wsh", "WSH");
    SEND_CASED_STRINGS(AD_MACRO_SHW, "shw", "Shw", "SHW");
    SEND_CASED_STRINGS(AD_MACRO_LSH, "lsh", "Lsh", "LSH");
    SEND_CASED_STRINGS(AD_MACRO_SHL, "shl", "Shl", "SHL");

    SEND_CASED_STRINGS(AD_MACRO_GWH, "gwh", "Gwh", "GWH");
    SEND_CASED_STRINGS(AD_MACRO_NWH, "nwh", "Nwh", "NWH");
    SEND_CASED_STRINGS(AD_MACRO_TWH, "twh", "Twh", "TWH");
    SEND_CASED_STRINGS(AD_MACRO_LWH, "lwh", "Lwh", "LWH");
    SEND_CASED_STRINGS(AD_MACRO_RWH, "rwh", "Rwh", "RWH");

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
    SEND_CASED_STRINGS(AD_MACRO_AU, "au", "Au", "AU");
    SEND_CASED_STRINGS(AD_MACRO_EO, "eo", "Eo", "EO");
    SEND_CASED_STRINGS(AD_MACRO_UA, "ua", "Ua", "UA");
    SEND_CASED_STRINGS(AD_MACRO_OE, "oe", "Oe", "OE");
    SEND_CASED_STRINGS(AD_MACRO_Eq, "e'", "E'", "E'");
    SEND_CASED_STRINGS(AD_MACRO_Iq, "i'", "I'", "I'");
    SEND_CASED_STRINGS(AD_MACRO_YI, "yi", "Yi", "YI");
    SEND_CASED_STRINGS(AD_MACRO_Oq, "o'", "O'", "O'");
    SEND_CASED_STRINGS(AD_MACRO_HEq, "he'", "He'", "HE'");
    SEND_CASED_STRINGS(AD_MACRO_IEq, "ie'", "Ie'", "IE'");
    SEND_CASED_STRINGS(AD_MACRO_YEq, "ye'", "Ye'", "YE'");
    SEND_CASED_STRINGS(AD_MACRO_YIq, "yi'", "Yi'", "YI'");

  // J adaptives
    SEND_CASED_STRINGS(AD_MACRO_JI, "ji", "Ji", "JI");
    SEND_CASED_STRINGS(AD_MACRO_JO, "jo", "Jo", "JO");
    SEND_CASED_STRINGS(AD_MACRO_JOE, "joe", "Joe", "JOE");
    SEND_CASED_STRINGS(AD_MACRO_JOq, "jo'", "Jo'", "JO'");
    SEND_CASED_STRINGS(AD_MACRO_OJ, "oj", "Oj", "OJ");

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
    SEND_FORCED_STRING(ST_FORCE_MINUS, "-");
    SEND_FORCED_STRING(ST_FORCE_S, "s");
    SEND_CASED_STRINGS(ST_FORCE_Q, "q", "q", "Q");

  // Tap-hold keys
    TAPHOLD_CASED(LT(0, KC_X), "z", "Z", "Z");

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
