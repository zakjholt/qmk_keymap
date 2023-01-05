#include QMK_KEYBOARD_H

enum custom_keycodes { SWAP = SAFE_RANGE };

bool sw_win_active = false;

void update_swapper(
    bool *active,
    uint16_t cmdish,
    uint16_t tabish,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record
) {
    if (keycode == trigger) {
        if (record->event.pressed) {
            if (!*active) {
                *active = true;
                register_code(cmdish);
            }
            register_code(tabish);
        } else {
            unregister_code(tabish);
            // Don't unregister cmdish until some other key is hit or released.
        }
    } else if (*active) {
        unregister_code(cmdish);
        *active = false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  update_swapper(&sw_win_active, KC_LGUI, KC_TAB, SWAP, keycode, record);

  switch (keycode) {
  default:
    return true;
  }
}
