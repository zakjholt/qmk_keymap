#include QMK_KEYBOARD_H

enum custom_keycodes { SWAP = SAFE_RANGE };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  default:
    return true;
  }
}
