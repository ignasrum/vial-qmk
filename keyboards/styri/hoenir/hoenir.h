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
#pragma once

#include "quantum.h"
#include "ws2812.h"

/*  ---------- LEFT HAND -----------   ---------- RIGHT HAND ----------
#define LAYOUT(                                                          \
    L11,L12,L13,L14,L15,L16,L17,           R17,R16,R15,R14,R13,R12,R11,  \
    L21,L22,L23,L24,L25,L26,L27,           R27,R26,R25,R24,R23,R22,R21,  \
    L31,L32,L33,L34,L35,L36,L37,           R37,R36,R35,R34,R33,R32,R31,  \
    L41,L42,L43,L44,L45,L46,                   R46,R45,R44,R43,R42,R41,  \
    L51,L52,L53,L54,L55,                           R55,R54,R53,R52,R51,  \
                            L56,L57,   R57,R56,                          \
                                L61,   R61,                              \
                        L71,L72,L73,   R73,R72,R71 )                     \
                                                         \
    {                                                    \
    { L11,   L12,   L13,   L14,   L15,   L16,   L17 },   \
    { L21,   L22,   L23,   L24,   L25,   L26,   L27 },   \
    { L31,   L32,   L33,   L34,   L35,   L36,   L37 },   \
    { L41,   L42,   L43,   L44,   L45,   L46,   KC_NO }, \
    { L51,   L52,   L53,   L54,   L55,   L56,   L57 },   \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, L61 },   \
    { KC_NO, KC_NO, KC_NO, KC_NO, L71,   L72,   L73 },   \
                                                         \
    { R17,   R16,   R15,   R14,   R13,   R12,   R11 },   \
    { R27,   R26,   R25,   R24,   R23,   R22,   R21 },   \
    { R37,   R36,   R35,   R34,   R33,   R32,   R31 },   \
    { KC_NO, R46,   R45,   R44,   R43,   R42,   R41 },   \
    { R57,   R56,   R55,   R54,   R53,   R52,   R51 },   \
    { R61,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { R73,   R72,   R71,   KC_NO, KC_NO, KC_NO, KC_NO }  \
    }
*/
