#include QMK_KEYBOARD_H

#define _BASE 0

uint8_t left_encoder_layer = 0; // A variable used to alter encoder behaviour.
uint8_t right_encoder_layer = 0; // A variable used to alter encoder behaviour.
uint8_t encoder_layer_count = 2; // The amount of encoder layers

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LENC,
  RENC,
 };


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT( \
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,             KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_PSCR, KC_SLCK, KC_PAUS, RENC, \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,              KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,              KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_P7,   KC_P8,   KC_P9,           \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,              KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_P4,   KC_P5,   KC_P6,   KC_PPLS, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,           KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_P1,   KC_P2,   KC_P3,            \
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,           LENC,             KC_SPC,  KC_RALT,           KC_RGUI, KC_MENU, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_P0,   KC_PDOT, KC_PENT  \
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) 
  {
    case LENC:
      if (record->event.pressed)
      {
        // Increment encoder layer with wrap-to-zero
        if(++left_encoder_layer >= encoder_layer_count)
        {
          left_encoder_layer = 0;
        }
      }
      else
      {
      }
      break;

    case RENC:
      if (record->event.pressed)
      {
        // Increment encoder layer with wrap-to-zero
        if(++right_encoder_layer >= encoder_layer_count)
        {
          right_encoder_layer = 0;
        }
      }
      else
      {
      }
      break;
  }
  return true;
};

//Encoder
void encoder_update_user(uint8_t index, bool clockwise)
{
  switch(index)
  {
    case 0: // Left encoder
      switch(left_encoder_layer) // Use the current encoder layer
      {
        case 1: // Layer 1
          if (clockwise)
          {
              tap_code16(C(KC_RGHT));
          } 
          else 
          {
              tap_code16(C(KC_LEFT));
          }
          break;
        
        case 0: // Layer 0
          if (clockwise)
          {
            tap_code16(KC_RGHT);
          }
          else
          {
            tap_code16(KC_LEFT);
          }
          break;
      }
      break;
      
    case 1: // Right encoder
      switch(right_encoder_layer) // Use the current encoder layer
      {
        case 0: // Layer 1
          if (clockwise)
          {
            tap_code16(KC_WH_D);
          } 
          else
          {
            tap_code16(KC_WH_U);
          }
          break;

        case 1: // Layer 0
          if (clockwise) 
          {
            tap_code(KC_VOLU);
          } 
          else 
          {
            tap_code(KC_VOLD);
          }
          break;
      }
      break;
  }
}