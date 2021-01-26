/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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
#define VENDOR_ID       0xDEEC
#define PRODUCT_ID      0x0124
#define DEVICE_VER      0x0001
#define MANUFACTURER    DChun
#define PRODUCT         Apollo
#define DESCRIPTION     Split columnar stagger keyboard


#define TAPPING_TERM 150

/* Select hand configuration */
#define USE_I2C
// #define SOFT_SERIAL_PIN D0
// #define EE_HANDS

// #define SPLIT_USB_DETECT
// #define SPLIT_USB_TIMEOUT 1000
// #define NO_USB_STARTUP_CHECK

// Turn off on slave
// #define WAIT_FOR_USB

#define SPLIT_HAND_PIN D5

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 10
#define MATRIX_ROW_PINS { F7, F6, F5, F4, D3 }
#define MATRIX_ROW_PINS_RIGHT { B6, B5, B4, D7, E6 }

// wiring of each half
#define MATRIX_COLS 7
#define MATRIX_COL_PINS { C7, B4, D7, D6, D4, F1, F0 }
#define MATRIX_COL_PINS_RIGHT { B0, D6, F1, F0, F4, F5, C6 }

#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 2

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION
