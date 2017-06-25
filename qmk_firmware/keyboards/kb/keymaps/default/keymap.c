#include "kb.h"

#define MODS_CTRL_MASK  (MOD_BIT(KC_LCTRL)|MOD_BIT(KC_RCTRL))
#define MODS_SHIFT_MASK (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define MODS_ALT_MASK   (MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))
#define MODS_GUI_MASK   (MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI))
#define MODS_ALL_MASK   (MODS_CTRL_MASK|MODS_SHIFT_MASK|MODS_ALT_MASK|MODS_GUI_MASK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* 0: Default layer
     *
     * ,-----------------------------------------------------------------------------------.
     * |Esc^Fn1| F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10| F11| F12|PrtS|ScrL| Ins |
     * |-----------------------------------------------------------------------------------|
     * |Esc^~|  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = |   \ |   ` | Home|
     * |-----------------------------------------------------------------------------------|
     * | Tab  |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] | Back^Del | PgUp|
     * |-----------------------------------------------------------------------------------|
     * |  Ctrl   |  A |  S |  D |  F |  G |  H |  J |  K |  L |  ; |  ' |    Return  | PgDn|
     * |-----------------------------------------------------------------------------------|
     * |  Shift    |  Z |  X |  C |  V |  B |  N |  M |  , |  . |  / |   Shift  |    | End |
     * |-----------------------------------------------------------------------------------|
     * |  Fn1 |  Sup |  Alt |            Space            |   Alt |  Ctrl |     |    |     |
     * `-----------------------------------------------------------------------------------'
     */
   KEYMAP(
      LT(1, KC_ESC), KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_SLCK, KC_INS,
      F(0), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV, KC_HOME,
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, F(1), KC_PGUP,
      KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGDN,
      KC_LSFT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_END,
      MO(1), KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_RALT, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

    /* 1: Function layer
     *
     * ,-----------------------------------------------------------------------------------.
     * |       |GUI1|GUI2|GUI3|GUI4|GUI5|GUI6|GUI7|GUI8|GUI9|    |    |    |    |    | Mute|
     * |-----------------------------------------------------------------------------------|
     * |  `  |    |    |    |    |    |    |    |    |    |    |    |    |     |     | Mute|
     * |-----------------------------------------------------------------------------------|
     * |      |    |    |    |    |    |    |    |    |    |    |    |    | Delete   | Vol+|
     * |-----------------------------------------------------------------------------------|
     * |         |    |    |    |    |    |Left| Dn | Up |Righ|    |    |            | Vol-|
     * |-----------------------------------------------------------------------------------|
     * |           |    |    |    |    |    |    |    |    |    |    |          |PgUp|     |
     * |-----------------------------------------------------------------------------------|
     * |  Fn1 |  Fn2 |      |                             |       |       | Home|PgDn| End |
     * `-----------------------------------------------------------------------------------'
     */
   KEYMAP(
      KC_TRNS, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE,
      KC_GRV, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, KC_MUTE,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_VOLU,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_TRNS,
      MO(1), MO(2), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_END),

    /* 2: Control layer
     *
     * ,-----------------------------------------------------------------------------------.
     * |       |    |    |    |    |    |    |    |    |    |    |    |    |    |    | Mode|
     * |-----------------------------------------------------------------------------------|
     * |     |    |    |    |    |    |    |    |    |    |    |    |    |     |     | Mode|
     * |-----------------------------------------------------------------------------------|
     * |      |    |    |    |    |    |    |    |    |    |    |    |    |          | VA+ |
     * |-----------------------------------------------------------------------------------|
     * |         |    |    |    |    |    |    |    |    |    |    |    |            | VA- |
     * |-----------------------------------------------------------------------------------|
     * |           |    |    |    |    |    |    |    |    |    |    |          |Sat+|     |
     * |-----------------------------------------------------------------------------------|
     * |      |  Fn2 |      |          RGB Toggle         |       |       | Hue+|Sat-| Hue-|
     * `-----------------------------------------------------------------------------------'
     */
   KEYMAP(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_MOD,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_MOD,
      KC_TRNS, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_VAI,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_VAD,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BL_DEC, BL_TOGG, BL_INC, BL_STEP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_SAI, KC_TRNS,
      KC_TRNS, MO(2), KC_TRNS, RGB_TOG, RGB_TOG, RGB_TOG, KC_TRNS, KC_TRNS, KC_TRNS, RGB_HUD, RGB_SAD, RGB_HUI),

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
   switch (id) {
   }
   return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   return true;
}

void led_set_user(uint8_t usb_led) {
   if (usb_led & (1 << USB_LED_NUM_LOCK)) {
   } else {
   }

   if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
      DDRB |= (1 << 2); PORTB &= ~(1 << 2);
   } else {
      DDRB &= ~(1 << 2); PORTB &= ~(1 << 2);
   }

   if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
   } else {
   }

   if (usb_led & (1 << USB_LED_COMPOSE)) {
   } else {
   }

   if (usb_led & (1 << USB_LED_KANA)) {
   } else {
   }
}

enum function_id {
   MOD_ESC,
   MOD_BACKSPACE,
};

const uint16_t PROGMEM fn_actions[] = {
   [0]  = ACTION_FUNCTION(MOD_ESC),
   [1]  = ACTION_FUNCTION(MOD_BACKSPACE),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {

   switch (id) {
      case MOD_ESC: {
         static uint8_t esc_mod_masked;

         /* Any MOD flips ESC to GRV. */
         esc_mod_masked = get_mods() & MODS_ALL_MASK;
         if (record->event.pressed) {
            if (esc_mod_masked) {
               add_key(KC_GRV);
               send_keyboard_report();
            } else {
               add_key(KC_ESC);
               send_keyboard_report();
            }
         } else {
            if (esc_mod_masked) {
               del_key(KC_GRV);
               send_keyboard_report();
            } else {
               del_key(KC_ESC);
               send_keyboard_report();
            }
         }
         break;
      }

      case MOD_BACKSPACE: {
         static uint8_t backspace_mod_masked;

         /*
          * SHIFT flips backspace to delete.
          *
          * TODO This may not work when the WM interprets SHIFT+DEL as
          * something other than just DEL. For example, Gnome uses
          * SHIFT+DEL for deleting files.
          */
         backspace_mod_masked = get_mods() & MODS_SHIFT_MASK;
         if (record->event.pressed) {
            if (backspace_mod_masked) {
               add_key(KC_DEL);
               send_keyboard_report();
            } else {
               add_key(KC_BSPC);
               send_keyboard_report();
            }
         } else {
            if (backspace_mod_masked) {
               del_key(KC_DEL);
               send_keyboard_report();
            } else {
               del_key(KC_BSPC);
               send_keyboard_report();
            }
         }
         break;
      }
   }
}
