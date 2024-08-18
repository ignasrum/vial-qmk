/* Copyright 2023 Ignas Rumbavicius (@ignasrum)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layers {
    ST, // default layer / FIRST, used for Windows/Linux
    ND, // SECOND, used for Windows/Linux
    RD, // THIRD, used for Mac
    TH, // FOURTH, used for Mac
};

void keyboard_pre_init_user(void) {
    setPinOutput(GP28);  // initialize GP28 for LED_1
    setPinOutput(GP27);  // initialize GP27 for LED_2

    writePinLow(GP28);
    writePinLow(GP27);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        // Second layer
        case ND:
            writePinHigh(GP27);
            writePinLow(GP28);
            break;
        // Third layer
        case RD:
            writePinLow(GP27);
            writePinHigh(GP28);
            break;
        // Fourth layer
        case TH:
            writePinHigh(GP27);
            writePinHigh(GP28);
            break;
        // Default / First layer
        default:
            writePinLow(GP27);
            writePinLow(GP28);
            break;
    }
    return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap ST: Default layer (Windows/Linux base layer)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  |RGBTOG|           |RGBVAI|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |RGBMOD|           |RGBVAD|   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Caps   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|RGBSAI|           |RGBHUI|------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * |--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------|
 * | Ctrl   |      | Del  | Left | Right|                                       |  Up  | Down |   [  |   ]  | Ctrl   |
 * `------------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | LGui | Home |       | PgUp | Alt  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | End  |       | PgDn |      |      |
 *                                 | Space| Alt  |------|       |------| Enter| Back-|
 *                                 |      |      | Ctrl |       | L2   |      | space|
 *                                 `--------------------'       `--------------------'
 */
[ST] = LAYOUT(
    KC_ESC,   KC_1,   KC_2,    KC_3,     KC_4,      KC_5,      RGB_TOG,        RGB_VAI,  KC_6,     KC_7,   KC_8,     KC_9,     KC_0,     KC_MINS,
    KC_TAB,   KC_Q,   KC_W,    KC_E,     KC_R,      KC_T,      RGB_MOD,        RGB_VAD,  KC_Y,     KC_U,   KC_I,     KC_O,     KC_P,     KC_BSLS,
    KC_CAPS,  KC_A,   KC_S,    KC_D,     KC_F,      KC_G,      RGB_SAI,        RGB_HUI,  KC_H,     KC_J,   KC_K,     KC_L,     KC_SCLN,  KC_QUOTE,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,     KC_V,      KC_B,                                KC_N,     KC_M,   KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
    KC_LCTL,  KC_NO,  KC_DEL,  KC_LEFT,  KC_RGHT,                                                  KC_UP,  KC_DOWN,  KC_LBRC,  KC_RBRC,  KC_RCTL,
                                                    KC_LGUI,   KC_HOME,        KC_PGUP,  KC_RALT,
                                                               KC_END,         KC_PGDN,
                                         KC_SPACE,  KC_LALT,   KC_LCTL,        MO(ND),   KC_ENT,   KC_BSPC
    ),
/* Keymap ND: Second layer (Windows/Linux second layer)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        | F1   | F2   | F3   | F4   | F5   |      |           | L3   | F6   | F7   | F8   | F9   | F10  | F11    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      | F12    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | <    | >    |      |        |
 * |--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------|
 * |        |      |      |      |      |                                       |      |      |      |      |        |
 * `------------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[ND] = LAYOUT(
    KC_NO,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_NO,      TG(RD), KC_F6,  KC_F7,  KC_F8,   KC_F9,      KC_F10,  KC_F11,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,      KC_NO,   KC_F12,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,      KC_NO,   KC_NO,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                      KC_NO,  KC_NO,  KC_NUBS, S(KC_NUBS), KC_NO,   KC_NO,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                                      KC_NO,  KC_NO,   KC_NO,      KC_NO,   KC_NO,
                                            KC_NO,  KC_NO,      KC_NO,  KC_NO,
                                                    KC_NO,      KC_NO,
                                    KC_NO,  KC_NO,  KC_NO,      KC_NO,  KC_NO, KC_NO
    ),
/* Keymap RD: Third layer (Mac base layer)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  |RGBTOG|           |RGBVAI|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |RGBMOD|           |RGBVAD|   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Caps   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|RGBSAI|           |RGBHUI|------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * |--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------|
 * | Ctrl   |      | Del  | Left | Right|                                       |  Up  | Down |   [  |   ]  | Ctrl   |
 * `------------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Alt  | Ctrl |       | PgUp | Alt  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Home |       | PgDn |      |      |
 *                                 | Space| LGui |------|       |------| Enter| Back-|
 *                                 |      |      | End  |       | L4   |      | space|
 *                                 `--------------------'       `--------------------'
 */
[RD] = LAYOUT(
    KC_ESC,   KC_1,   KC_2,    KC_3,     KC_4,      KC_5,      RGB_TOG,        RGB_VAI,  KC_6,     KC_7,   KC_8,     KC_9,     KC_0,     KC_MINS,
    KC_TAB,   KC_Q,   KC_W,    KC_E,     KC_R,      KC_T,      RGB_MOD,        RGB_VAD,  KC_Y,     KC_U,   KC_I,     KC_O,     KC_P,     KC_BSLS,
    KC_CAPS,  KC_A,   KC_S,    KC_D,     KC_F,      KC_G,      RGB_SAI,        RGB_HUI,  KC_H,     KC_J,   KC_K,     KC_L,     KC_SCLN,  KC_QUOTE,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,     KC_V,      KC_B,                                KC_N,     KC_M,   KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
    KC_LCTL,  KC_NO,  KC_DEL,  KC_LEFT,  KC_RGHT,                                                  KC_UP,  KC_DOWN,  KC_BSLS,  KC_RBRC,  KC_RCTL,
                                                    KC_LALT,   KC_LCTL,        KC_PGUP,  KC_RALT,
                                                               KC_HOME,        KC_PGDN,
                                         KC_SPACE,  KC_LGUI,   KC_END,         MO(TH),   KC_ENT,   KC_BSPC
    ),
/* Keymap TH: Fourth layer (Mac second layer)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        | F1   | F2   | F3   | F4   | F5   |      |           | L1   | F6   | F7   | F8   | F9   | F10  | F11    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      | F12    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | <    | >    |      |        |
 * |--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------|
 * |        |      |      |      |      |                                       |      |      |      |      |        |
 * `------------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[TH] = LAYOUT(
    KC_NO,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_NO,      TG(RD), KC_F6,  KC_F7,  KC_F8,   KC_F9,      KC_F10,  KC_F11,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,      KC_NO,   KC_F12,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,      KC_NO,   KC_NO,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                      KC_NO,  KC_NO,  KC_NUBS, S(KC_NUBS), KC_NO,   KC_NO,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                                      KC_NO,  KC_NO,   KC_NO,      KC_NO,   KC_NO,
                                            KC_NO,  KC_NO,      KC_NO,  KC_NO,
                                                    KC_NO,      KC_NO,
                                    KC_NO,  KC_NO,  KC_NO,      KC_NO,  KC_NO, KC_NO
    ),
};
