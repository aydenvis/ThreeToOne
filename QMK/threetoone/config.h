/*
Copyright 2021 Ayden Visser </u/aydenvis>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       5
#define PRODUCT_ID      5
#define DEVICE_VER      1
#define MANUFACTURER    Aydenvis
#define PRODUCT         ThreeToOne
#define DESCRIPTION     100% Ortho Board

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 12
#define MATRIX_COLS 9

// wiring of each half
#define MATRIX_ROW_PINS { F6, F7, B1, B3, B2, B6 }
#define MATRIX_COL_PINS { F5, F4, B5, B4, E6, D7, D1, D2, D3  }

#define MATRIX_ROW_PINS_RIGHT { F4, F5, B3, B1, F7, F6 }
#define MATRIX_COL_PINS_RIGHT { D3, D2, D1, D4, C6, D7, E6, B4, B5}

// Encoder things
#define ENCODERS_PAD_A { C6 }
#define ENCODERS_PAD_B { D4 }

#define ENCODERS_PAD_A_RIGHT { B7 }
#define ENCODERS_PAD_B_RIGHT { D5 }

//Two leds
#define LED_NUM_LOCK_PIN B6
#define CAPS_NUM_LOCK_PIN B2

#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* serial.c configuration for split keyboard */
#define SOFT_SERIAL_PIN D0


