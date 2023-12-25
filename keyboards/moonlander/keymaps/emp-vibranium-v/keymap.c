#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_MACRO_8,
  ST_MACRO_9,
  ST_MACRO_10,
  ST_MACRO_11,
};


typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;
tap_dance_action_t *action;

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_NO,          KC_7,           KC_3,           KC_1,           KC_5,           KC_9,           KC_NO,                                          KC_NO,          KC_6,           KC_2,           KC_0,           KC_4,           KC_8,           KC_NO,          
    KC_TRANSPARENT, KC_X,           KC_W,           KC_M,           KC_G,           KC_DQUO,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_AT,          KC_DOT,         KC_QUOTE,       KC_J,           KC_B,           KC_TRANSPARENT, 
    KC_TAB,         KC_S,           KC_C,           KC_N,           KC_T,           KC_K,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_LPRN,        KC_A,           KC_E,           KC_I,           KC_H,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_V,           KC_F,           KC_L,           KC_D,           KC_SLASH,                                       KC_MINUS,       KC_U,           KC_O,           KC_Y,           KC_P,           KC_TRANSPARENT, 
    TO(5),          KC_NO,          TT(3),          TT(4),          MO(1),          KC_ESCAPE,                                                                                                      RCTL(KC_BSPC),  MO(2),          MO(4),          CW_TOGG,        KC_NO,          KC_TRANSPARENT, 
    KC_R,           TD(DANCE_0),    KC_NO,                          KC_NO,          KC_ENTER,       KC_SPACE
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_CIRC,        KC_AT,          KC_RPRN,        KC_DLR,         KC_ASTR,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          RSFT(KC_J),     LSFT(KC_B),     KC_TRANSPARENT, 
    LSFT(KC_TAB),   KC_NO,          KC_LEFT_GUI,    KC_LEFT_ALT,    KC_LEFT_CTRL,   KC_NO,          KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_NO,          LSFT(KC_A),     LSFT(KC_E),     LSFT(KC_I),     LSFT(KC_H),     KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          LSFT(KC_U),     LSFT(KC_O),     LSFT(KC_Y),     LSFT(KC_P),     KC_TRANSPARENT, 
    KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, KC_NO,                                                                                                          KC_BSPC,        OSM(MOD_LSFT),  KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_NO,          KC_NO,          KC_TRANSPARENT,                 KC_TRANSPARENT, LSFT(KC_ENTER), ST_MACRO_11
  ),
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_AMPR,        KC_HASH,        KC_EXLM,        KC_PERC,        KC_LPRN,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, RSFT(KC_X),     RSFT(KC_W),     RSFT(KC_M),     RSFT(KC_G),     KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, 
    RSFT(KC_TAB),   RSFT(KC_S),     RSFT(KC_C),     RSFT(KC_N),     RSFT(KC_T),     RSFT(KC_K),     KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_NO,          KC_RIGHT_CTRL,  KC_LEFT_ALT,    KC_RIGHT_GUI,   KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, RSFT(KC_V),     RSFT(KC_F),     RSFT(KC_L),     RSFT(KC_D),     KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, 
    KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          OSM(MOD_RSFT),  RSFT(KC_ESCAPE),                                                                                                KC_NO,          KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    RSFT(KC_R),     KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_NO,          KC_NO
  ),
  [3] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LABK,        KC_D,           KC_E,           KC_F,           KC_RABK,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_ASTR,        KC_7,           KC_8,           KC_9,           TD(DANCE_1),    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_X,           MT(MOD_LGUI, KC_LEFT),MT(MOD_LALT, KC_UP),MT(MOD_LCTL, KC_DOWN),KC_RIGHT,       KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_PLUS,        KC_4,           KC_5,           KC_6,           KC_HASH,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LPRN,        KC_A,           KC_B,           KC_C,           KC_RPRN,                                        KC_MINUS,       KC_1,           KC_2,           KC_3,           TD(DANCE_2),    KC_TRANSPARENT, 
    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT_SHIFT,  KC_TRANSPARENT,                                                                                                 KC_BSPC,        KC_0,           TD(DANCE_3),    KC_EQUAL,       KC_TRANSPARENT, TO(0),          
    KC_TRANSPARENT, KC_COMMA,       KC_TRANSPARENT,                 KC_TRANSPARENT, KC_KP_ENTER,    KC_TRANSPARENT
  ),
  [4] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_F14,         KC_F10,         KC_F11,         KC_F12,         KC_F15,         KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F16,         KC_F17,         KC_F18,         KC_F19,         KC_F20,         KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F13,         KC_F9,          KC_F8,          KC_F7,          KC_F23,         KC_F24,                                         KC_INSERT,      KC_ESCAPE,      KC_MEDIA_NEXT_TRACK,KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,
    KC_TRANSPARENT, KC_BRIGHTNESS_UP,MT(MOD_LGUI, KC_F6),MT(MOD_LALT, KC_F5),MT(MOD_LCTL, KC_F4),KC_F22,         KC_TRANSPARENT,                                                                 KC_DELETE,      KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TAB,         KC_AUDIO_VOL_DOWN,
    KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_F3,          KC_F2,          KC_F1,          KC_F21,                                         KC_HOME,        KC_PGDN,        KC_PAGE_UP,     KC_END,         LCTL(KC_G),     KC_WWW_SEARCH,  
    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT_SHIFT,  KC_TRANSPARENT,                                                                                                 KC_BSPC,        KC_RIGHT_SHIFT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(0),          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT, 
    KC_LEFT_SHIFT,  KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,                                           KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_MINUS,       
    KC_TAB,         KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,                                                                           KC_EQUAL,       KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,       
    KC_LEFT_ALT,    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RIGHT_CTRL,  
    MO(6),          KC_TRANSPARENT, KC_LEFT_GUI,    KC_LEFT_CTRL,   KC_RIGHT_SHIFT, KC_ESCAPE,                                                                                                      KC_TRANSPARENT, KC_RIGHT_SHIFT, KC_RIGHT_ALT,   KC_RIGHT_GUI,   KC_TRANSPARENT, TO(0),          
    KC_SPACE,       KC_ENTER,       KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [6] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_DELETE,      KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_U,                                           QK_DYNAMIC_TAPPING_TERM_UP,RGB_MODE_FORWARD,RGB_HUD,        RGB_HUI,        RGB_TOG,        QK_DYNAMIC_TAPPING_TERM_PRINT,KC_GRAVE,       
    KC_BSPC,        KC_F11,         KC_LEFT,        KC_UP,          KC_DOWN,        KC_RIGHT,       KC_L,                                                                           QK_DYNAMIC_TAPPING_TERM_DOWN,RGB_SLD,        RGB_VAD,        RGB_VAI,        TOGGLE_LAYER_COLOR,KC_PAUSE,       KC_PSCR,        
    KC_RIGHT_ALT,   KC_F12,         KC_HOME,        KC_PAGE_UP,     KC_PGDN,        KC_END,                                         CM_OFF,         CM_ON,          MOON_LED_LEVEL, AU_TOGG,        KC_BSLS,        KC_RIGHT_CTRL,  
    KC_TRANSPARENT, KC_TRANSPARENT, KC_RIGHT_GUI,   KC_RIGHT_CTRL,  KC_LEFT_SHIFT,  KC_ESCAPE,                                                                                                      KC_BSPC,        MO(7),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_CAPS,        
    KC_SPACE,       KC_ENTER,       KC_TRANSPARENT,                 KC_TRANSPARENT, TO(0),          KC_TRANSPARENT
  ),
  [7] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, EE_CLR,         KC_TRANSPARENT,                                 KC_TRANSPARENT, QK_BOOT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(0),          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};
const uint16_t PROGMEM combo0[] = { KC_X, KC_W, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_W, KC_M, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_M, KC_G, COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_W, KC_G, KC_M, COMBO_END};
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
const uint16_t PROGMEM combo37[] = { KC_MINUS, KC_Y, COMBO_END};
const uint16_t PROGMEM combo38[] = { KC_MINUS, KC_U, KC_O, COMBO_END};
const uint16_t PROGMEM combo39[] = { KC_MINUS, KC_A, KC_E, COMBO_END};
const uint16_t PROGMEM combo40[] = { KC_MINUS, KC_E, KC_Y, COMBO_END};
const uint16_t PROGMEM combo41[] = { KC_U, KC_O, KC_Y, COMBO_END};
const uint16_t PROGMEM combo42[] = { KC_S, KC_C, KC_N, COMBO_END};
const uint16_t PROGMEM combo43[] = { KC_C, KC_N, KC_T, COMBO_END};
const uint16_t PROGMEM combo44[] = { KC_N, KC_T, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_Z),
    COMBO(combo1, ST_MACRO_0),
    COMBO(combo2, ST_MACRO_1),
    COMBO(combo3, KC_Q),
    COMBO(combo4, KC_EXLM),
    COMBO(combo5, ST_MACRO_2),
    COMBO(combo6, ST_MACRO_3),
    COMBO(combo7, ST_MACRO_4),
    COMBO(combo8, ST_MACRO_5),
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
    COMBO(combo25, ST_MACRO_6),
    COMBO(combo26, KC_RPRN),
    COMBO(combo27, ST_MACRO_7),
    COMBO(combo28, KC_LBRC),
    COMBO(combo29, KC_RBRC),
    COMBO(combo30, ST_MACRO_8),
    COMBO(combo31, KC_LCBR),
    COMBO(combo32, KC_RCBR),
    COMBO(combo33, ST_MACRO_9),
    COMBO(combo34, ST_MACRO_10),
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
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_W:
            return g_tapping_term -155;
        case KC_M:
            return g_tapping_term -155;
        case KC_G:
            return g_tapping_term -155;
        case KC_S:
            return g_tapping_term -155;
        case KC_C:
            return g_tapping_term -155;
        case KC_N:
            return g_tapping_term -155;
        case KC_T:
            return g_tapping_term -155;
        case KC_K:
            return g_tapping_term -155;
        case KC_V:
            return g_tapping_term -155;
        case KC_F:
            return g_tapping_term -155;
        case KC_L:
            return g_tapping_term -155;
        case KC_D:
            return g_tapping_term -155;
        case TD(DANCE_0):
            return g_tapping_term + 75;
        case MT(MOD_LGUI, KC_LEFT):
            return g_tapping_term + 25;
        case MT(MOD_LALT, KC_UP):
            return g_tapping_term + 25;
        case MT(MOD_LCTL, KC_DOWN):
            return g_tapping_term + 25;
        case TD(DANCE_1):
            return g_tapping_term + 25;
        case TD(DANCE_3):
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
    [0] = { {93,255,191}, {0,0,0}, {0,0,0}, {0,0,0}, {101,206,157}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {36,255,193}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {203,196,165}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {86,255,204}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {0,0,0}, {0,0,0}, {93,255,191}, {128,242,161}, {93,255,191}, {93,255,191}, {93,255,191}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {86,255,204}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {203,196,165}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {86,255,204}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {0,0,0}, {0,0,0}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191} },

    [1] = { {86,255,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,204}, {0,0,0}, {0,0,0}, {86,255,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,204}, {0,0,0}, {67,180,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {93,255,191}, {0,0,0}, {93,255,191}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {0,0,0}, {93,255,191}, {93,255,191}, {93,255,191}, {0,0,0}, {0,0,0}, {0,0,0}, {93,255,191}, {93,255,191}, {0,0,0}, {0,0,0}, {0,0,0}, {93,255,191}, {93,255,191}, {86,255,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {93,255,191}, {0,0,0}, {0,0,0}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191} },

    [2] = { {93,255,191}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {93,255,191}, {93,255,191}, {93,255,191}, {93,255,191}, {0,0,0}, {93,255,191}, {93,255,191}, {93,255,191}, {0,0,0}, {0,0,0}, {93,255,191}, {93,255,191}, {93,255,191}, {0,0,0}, {0,0,0}, {93,255,191}, {93,255,191}, {93,255,191}, {86,255,204}, {0,0,0}, {0,0,0}, {93,255,191}, {0,0,0}, {93,255,191}, {0,0,0}, {0,0,0}, {93,255,191}, {128,242,161}, {93,255,191}, {93,255,191}, {86,255,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,204}, {0,0,0}, {0,0,0}, {86,255,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,204}, {0,0,0}, {67,180,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,204}, {0,0,0} },

    [3] = { {36,255,193}, {0,0,0}, {0,0,0}, {0,0,0}, {93,255,191}, {0,0,0}, {36,255,193}, {36,255,193}, {36,255,193}, {36,255,193}, {0,0,0}, {36,255,193}, {128,242,161}, {36,255,193}, {67,180,255}, {0,0,0}, {36,255,193}, {128,242,161}, {36,255,193}, {203,196,165}, {0,0,0}, {36,255,193}, {128,242,161}, {36,255,193}, {86,255,204}, {0,0,0}, {36,255,193}, {36,255,193}, {36,255,193}, {36,255,193}, {0,0,0}, {0,0,0}, {0,0,0}, {36,255,193}, {36,255,193}, {0,0,0}, {36,255,193}, {0,0,0}, {0,0,0}, {0,0,0}, {93,255,191}, {0,0,0}, {128,242,161}, {36,255,193}, {128,242,161}, {36,255,193}, {0,0,0}, {36,255,193}, {36,255,193}, {36,255,193}, {36,255,193}, {0,0,0}, {36,255,193}, {36,255,193}, {36,255,193}, {128,242,161}, {0,0,0}, {36,255,193}, {36,255,193}, {36,255,193}, {36,255,193}, {0,0,0}, {36,255,193}, {36,255,193}, {36,255,193}, {36,255,193}, {0,0,0}, {0,0,0}, {36,255,193}, {36,255,193}, {36,255,193}, {36,255,193} },

    [4] = { {203,196,165}, {0,0,0}, {0,0,0}, {0,0,0}, {93,255,191}, {203,196,165}, {203,196,165}, {102,255,143}, {102,255,143}, {203,196,165}, {203,196,165}, {203,196,165}, {128,242,161}, {203,196,165}, {86,255,204}, {203,196,165}, {203,196,165}, {128,242,161}, {203,196,165}, {67,180,255}, {203,196,165}, {203,196,165}, {128,242,161}, {203,196,165}, {86,255,204}, {203,196,165}, {203,196,165}, {203,196,165}, {203,196,165}, {203,196,165}, {203,196,165}, {0,0,0}, {0,0,0}, {0,0,0}, {203,196,165}, {0,0,0}, {203,196,165}, {102,255,143}, {102,255,143}, {203,196,165}, {93,255,191}, {203,196,165}, {102,255,143}, {203,196,165}, {203,196,165}, {203,196,165}, {203,196,165}, {102,255,143}, {203,196,165}, {203,196,165}, {86,255,204}, {203,196,165}, {102,255,143}, {203,196,165}, {203,196,165}, {67,180,255}, {203,196,165}, {102,255,143}, {203,196,165}, {203,196,165}, {86,255,204}, {203,196,165}, {203,196,165}, {203,196,165}, {203,196,165}, {203,196,165}, {203,196,165}, {203,196,165}, {203,196,165}, {203,196,165}, {203,196,165}, {203,196,165} },

    [5] = { {101,206,157}, {86,255,204}, {101,206,157}, {86,255,204}, {237,234,175}, {101,206,157}, {101,206,157}, {101,206,157}, {101,206,157}, {101,206,157}, {101,206,157}, {101,206,157}, {101,206,157}, {101,206,157}, {86,255,204}, {101,206,157}, {101,206,157}, {101,206,157}, {101,206,157}, {86,255,204}, {101,206,157}, {101,206,157}, {101,206,157}, {101,206,157}, {86,255,204}, {101,206,157}, {101,206,157}, {101,206,157}, {101,206,157}, {101,206,157}, {101,206,157}, {101,206,157}, {101,206,157}, {101,206,157}, {101,206,157}, {101,206,157}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {93,255,191}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [6] = { {237,234,175}, {237,234,175}, {237,234,175}, {86,255,204}, {67,180,255}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {86,255,204}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {86,255,204}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {86,255,204}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {237,234,175}, {86,255,204}, {237,234,175}, {0,0,0}, {8,235,250}, {237,234,175}, {237,234,175}, {237,234,175}, {0,0,0}, {253,174,200}, {253,174,200}, {253,174,200}, {86,255,204}, {0,0,0}, {253,174,200}, {253,174,200}, {253,174,200}, {86,255,204}, {0,0,0}, {253,174,200}, {253,174,200}, {188,255,180}, {8,235,250}, {0,0,0}, {253,174,200}, {253,174,200}, {12,255,186}, {237,234,175}, {8,235,250}, {8,235,250}, {0,0,0}, {93,255,191}, {237,234,175}, {237,234,175} },

    [7] = { {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {93,255,191}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {0,0,0}, {0,0,0}, {0,0,0}, {8,235,250}, {8,235,250}, {0,0,0}, {0,255,255}, {0,0,0}, {8,235,250}, {0,255,255}, {0,0,0}, {0,0,0}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {93,255,191}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250}, {0,0,0}, {0,0,0}, {0,0,0}, {8,235,250}, {67,180,255}, {0,0,0}, {172,255,255}, {0,0,0}, {8,235,250}, {172,255,255}, {0,0,0}, {0,0,0}, {8,235,250}, {8,235,250}, {8,235,250}, {8,235,250} },

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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_W) SS_DELAY(100) SS_TAP(X_H));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_G) SS_DELAY(100) SS_TAP(X_H));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_S) SS_DELAY(100) SS_TAP(X_H));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_C) SS_DELAY(100) SS_TAP(X_H));
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_T) SS_DELAY(100) SS_TAP(X_H));
    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_P) SS_DELAY(100) SS_TAP(X_H));
    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_COMMA)) SS_DELAY(100) SS_RSFT(SS_TAP(X_DOT)));
    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_9)) SS_DELAY(100) SS_RSFT(SS_TAP(X_0)));
    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LBRC) SS_DELAY(100) SS_TAP(X_RBRC));
    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_LBRC)) SS_DELAY(100) SS_RSFT(SS_TAP(X_RBRC)));
    }
    break;
    case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_EQUAL) SS_DELAY(100) SS_RSFT(SS_TAP(X_DOT)) SS_DELAY(100) SS_TAP(X_SPACE) SS_DELAY(100) SS_RSFT(SS_TAP(X_LBRC)));
    }
    break;
    case ST_MACRO_11:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_DOT) SS_DELAY(100) SS_TAP(X_SPACE));
    }
    break;

    case TD(DANCE_0):
    case TD(DANCE_1):
    case TD(DANCE_2):
    case TD(DANCE_3):
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
        }
        break;
    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
  }
  return true;
}


void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }


tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_TAP_HOLD(KC_COMMA, KC_SCLN),
        [DANCE_1] = ACTION_TAP_DANCE_TAP_HOLD(KC_DLR, KC_CIRC),
        [DANCE_2] = ACTION_TAP_DANCE_TAP_HOLD(KC_SLASH, KC_PERC),
        [DANCE_3] = ACTION_TAP_DANCE_TAP_HOLD(KC_DOT, KC_COLN),
};
