// #include "iris.h"
#include QMK_KEYBOARD_H
/* #include "action_layer.h" */
/* #include "eeconfig.h" */

/* extern keymap_config_t keymap_config; */

#define _QWERTY 0
// #define _ASHIFT 1
// #define _RAISE 2
#define _SYM 1
#define _NUM 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  // ASHIFT,
  // RAISE,
  SYM,
  NUM
};

/* #define KC_ KC_TRNS */
/* #define _______ KC_TRNS */

#define KC_ASFT ASHIFT
#define KC_RASE RAISE
#define KC_BL_T BL_TOGG
#define KC_BL_I BL_UP
#define KC_BL_D BL_DOWN

// Control when held, Escape when tapped
#define KC_CESC CTL_T(KC_ESC)
// Control when held, Semicolon when tapped
#define KC_CSCL CTL_T(KC_SCLN)
// Alt when held, Escape when tapped
#define KC_ATAB ALT_T(KC_TAB)
// Alt when held, Semicolon when tapped
#define KC_ABSL ALT_T(KC_BSLS)
// GUI when held, Tilde when tapped
#define KC_GTIL RGUI_T(KC_TILD)
// GUI when held, Media Play when tapped
#define KC_GMPL LGUI_T(KC_MPLY)
// Control+P for ctrlp shortcut in vim
/* #define KC_CTLP LCTL(KC_P) */
// German characters - assuming 'setxkbmap de us' is set in linux
#define KC_EURO RALT(KC_E)
#define KC_AE RALT(KC_A)
#define KC_OE RALT(KC_O)
#define KC_UE RALT(KC_U)
#define KC_SZ RALT(KC_S)

#define HRMA LGUI_T(KC_A)
#define HRMS LALT_T(KC_S)
#define HRMD LCTL_T(KC_D)
#define HRMF LSFT_T(KC_F)
#define HRMJ RSFT_T(KC_J)
#define HRMK LCTL_T(KC_K)
#define HRML LALT_T(KC_L)
#define HRMC LSFT_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // [_QWERTY] = LAYOUT(
  // //,-------+-------+-------+-------+-------+-------.                  ,-------+-------+-------+-------+-------+-------.
  //    KC_GTIL, KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                    KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_GMPL,
  // //|-------+-------+-------+-------+-------+-------.                  ,-------+-------+-------+-------+-------+-------|
  //    KC_ATAB, KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                    KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_ABSL,
  // //|-------+-------+-------+-------+-------+-------.                  ,-------+-------+-------+-------+-------+-------|
  //    KC_CESC, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                    KC_H  , KC_J  , KC_K  , KC_L  ,KC_COLN,KC_CSCL,
  // //|-------+-------+-------+-------+-------+-------.                  ,-------+-------+-------+-------+-------+-------|
  //    KC_EQL , KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,KC_LGUI,   KC_RGUI, KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_MINS,
  // //`-------+-------+-------+-------+-------+-------+-------/   \------+-------+-------+-------+-------+-------+-------'
  //                                  KC_RASE,KC_ASFT, KC_ENT,         KC_SPC, KC_ASFT,KC_RASE
  // //                              `-------+-------+-------'        `-------+-------+-------'
  // ),
  //
  // [_ASHIFT] = LAYOUT(
  // //,-------+-------+-------+-------+-------+-------.                  ,-------+-------+-------+-------+-------+-------.
  //    KC_GRV ,_______,_______,_______,_______,_______,                   KC_AMPR,KC_QUOT,KC_DQUO,_______,_______,_______,
  // //|-------+-------+-------+-------+-------+-------.                  ,-------+-------+-------+-------+-------+-------|
  //    KC_CIRC,_______,_______,_______,_______,_______,                   _______,_______,_______,_______,_______,_______,
  // //|-------+-------+-------+-------+-------+-------.                  ,-------+-------+-------+-------+-------+-------|
  //    KC_ASTR,_______,_______,_______,_______,_______,                   _______,_______,_______,_______,KC_LPRN,KC_RPRN,
  // //|-------+-------+-------+-------+-------+-------.                  ,-------+-------+-------+-------+-------+-------|
  //    _______,_______,_______,_______,_______,_______,_______,   _______,_______,_______,_______,_______,_______,KC_UNDS,
  // //`-------+-------+-------+-------+-------+-------+-------/   \------+-------+-------+-------+-------+-------+-------'
  //                                  _______,_______,_______,         KC_BSPC,_______,_______
  // //                              `-------+-------+-------'        `-------+-------+-------'
  // ),
  //
  // [_RAISE] = LAYOUT(
  // //,-------+-------+-------+-------+-------+-------.                  ,-------+-------+-------+-------+-------+-------.
  //    KC_F11 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                    KC_F6 , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F12 ,
  // //|-------+-------+-------+-------+-------+-------.                  ,-------+-------+-------+-------+-------+-------|
  //    QK_RBT ,_______,_______,KC_EURO,_______,_______,                   _______, KC_UE ,_______, KC_OE ,KC_LCBR,KC_RCBR,
  // //|-------+-------+-------+-------+-------+-------.                  ,-------+-------+-------+-------+-------+-------|
  //    DB_TOGG, KC_AE , KC_SZ ,_______,_______,_______,                   KC_LEFT,KC_DOWN, KC_UP ,KC_RGHT,KC_LBRC,KC_RBRC,
  // //|-------+-------+-------+-------+-------+-------.                  ,-------+-------+-------+-------+-------+-------|
  //    QK_BOOT,_______,_______,_______,_______,_______,_______,   BL_TOGG,BL_DOWN, BL_UP ,KC_VOLD,KC_VOLU,KC_MUTE,KC_PSCR,
  // //`-------+-------+-------+-------+-------+-------+-------/   \------+-------+-------+-------+-------+-------+-------'
  //                                  _______,_______,_______,         KC_DEL ,_______,KC_MUTE
  // //                              `-------+-------+-------'        `-------+-------+-------'
  // )

  [_QWERTY] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------.                  ,-------+-------+-------+-------+-------+-------.
     _______,_______,_______,_______,_______,_______,                   _______,_______,_______,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------.                  ,-------+-------+-------+-------+-------+-------|
     _______, KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                    KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,_______,
  //|-------+-------+-------+-------+-------+-------.                  ,-------+-------+-------+-------+-------+-------|
     _______, HRMA  , HRMS  , HRMD  , HRMF  , KC_G  ,                    KC_H  , HRMJ  , HRMK  , HRML  , HRMC  ,_______,
  //|-------+-------+-------+-------+-------+-------.                  ,-------+-------+-------+-------+-------+-------|
     _______, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,_______,   _______, KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,_______,
  //`-------+-------+-------+-------+-------+-------+-------/   \------+-------+-------+-------+-------+-------+-------'
                                   KC_RASE,KC_ASFT, KC_ENT,         KC_SPC, KC_ASFT,KC_RASE
  //                              `-------+-------+-------'        `-------+-------+-------'
  ),

  [_SYM] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------.                  ,-------+-------+-------+-------+-------+-------.
     _______,_______,_______,_______,_______,_______,                   _______,_______,_______,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------.                  ,-------+-------+-------+-------+-------+-------|
     _______,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                   _______,_______,_______,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------.                  ,-------+-------+-------+-------+-------+-------|
     _______,_______,_______,_______,_______,_______,                   _______,_______,_______,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------.                  ,-------+-------+-------+-------+-------+-------|
     _______,_______,_______,_______,_______,_______,_______,   _______,_______,_______,_______,_______,_______,_______,
  //`-------+-------+-------+-------+-------+-------+-------/   \------+-------+-------+-------+-------+-------+-------'
                                   _______,_______,_______,         KC_BSPC,_______,_______
  //                              `-------+-------+-------'        `-------+-------+-------'
  ),

  [_NUM] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------.                  ,-------+-------+-------+-------+-------+-------.
     _______,_______,_______,_______,_______,_______,                   _______,_______,_______,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------.                  ,-------+-------+-------+-------+-------+-------|
     _______,_______,_______,_______,_______,_______,                   _______, KC_1  , KC_2  , KC_3  ,_______,_______,
  //|-------+-------+-------+-------+-------+-------.                  ,-------+-------+-------+-------+-------+-------|
     _______,_______,_______,_______,_______,_______,                   _______, KC_4  , KC_5  , KC_6  ,_______,_______,
  //|-------+-------+-------+-------+-------+-------.                  ,-------+-------+-------+-------+-------+-------|
     _______,_______,_______,_______,_______,_______,_______,   _______,_______, KC_7  , KC_8  , KC_9  ,_______,_______,
  //`-------+-------+-------+-------+-------+-------+-------/   \------+-------+-------+-------+-------+-------+-------'
                                   _______,_______,_______,         _______,_______,_______
  //                              `-------+-------+-------'        `-------+-------+-------'
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool is_shift_except;
  uint8_t is_mod;

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
	case ASHIFT:
      if (record->event.pressed) {
		register_code(KC_LSFT);
        layer_on(_ASHIFT);
      } else {
        layer_off(_ASHIFT);
		unregister_code16(KC_LSFT);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;

    case KC_GTIL:
      if (record->tap.count && record->event.pressed) {
        tap_code16(KC_TILD); // Send KC_TILD on tap
        return false;        // Return false to ignore further processing of key
      }
      break;

    case KC_GMPL:
      if (record->tap.count && record->event.pressed) {
        tap_code16(KC_MPLY); // Send KC_MPLY on tap
        return false;        // Return false to ignore further processing of key
      }
      break;

	case KC_EQL:
	  is_mod = get_mods() & (MOD_BIT(KC_LGUI) | MOD_BIT(KC_RGUI));
	  if (record->event.pressed && is_mod) {
		  register_code16(KC_LSFT);
		  return false;
	  } else if (!(record->event.pressed)) {
		  unregister_code16(KC_LSFT);
		  return true;
	  } else {
		  return true;
	  }
	  break;
	case KC_MINS:
	  is_mod = get_mods() & (MOD_BIT(KC_LGUI) | MOD_BIT(KC_RGUI));
	  if (record->event.pressed && is_mod) {
		  register_code16(KC_LSFT);
		  return false;
	  } else if (!(record->event.pressed)) {
		  unregister_code16(KC_LSFT);
		  return true;
	  } else {
		  return true;
	  }
	  break;
	case KC_GRV:
	  is_shift_except = true;
	  break;
	case KC_LBRC:
	  is_shift_except = true;
	  break;
	case KC_RBRC:
	  is_shift_except = true;
	  break;
	case KC_DEL:
	  is_shift_except = true;
	  break;
	case KC_QUOT:
	  is_shift_except = true;
	  break;
	default:
	  return true;
  }

  /* Shift exception for alternative shift layer to keep functionality */
  if (record->event.pressed & is_shift_except) {
	  unregister_code16(KC_LSFT);
	  return true;
  }
  return true;
}
