#pragma once

#include "quantum.h"

#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
    #include <avr/io.h>
    #include <avr/interrupt.h>
#endif
#endif

#define LAYOUT( \
  L00, L01, L02, L03, L04, L05, R01, R02, R03, R04, R05, R06, \
	L10, L11, L12, L13, L14, L15, R11, R12, R13, R14, R15, R16, \
	L20, L21, L22, L23, L24, L25, R21, R22, R23, R24, R25, R26, \
	L30, L31, L32, L33, L34, L35, R31, R32, R33, R34, R35, R36, \
  L40, L41, L42, L43, L44, L45, R41, R42, R43, R44, R45, R46, \
                           L46, R40 \
) \
{ \
	{ L00,   L01,   L02,   L03,   L04,   L05,   KC_NO }, \
	{ L10,   L11,   L12,   L13,   L14,   L15,   KC_NO }, \
	{ L20,   L21,   L22,   L23,   L24,   L25,   KC_NO }, \
	{ L30,   L31,   L32,   L33,   L34,   L35,   KC_NO }, \
	{ L40,   L41,   L42,   L43,   L44,   L45,   L46 }, \
	{ KC_NO, R01,   R02,   R03,   R04,   R05,   R06 }, \
	{ KC_NO, R11,   R12,   R13,   R14,   R15,   R16 }, \
	{ KC_NO, R21,   R22,   R23,   R24,   R25,   R26 }, \
	{ KC_NO, R31,   R32,   R33,   R34,   R35,   R36 }, \
	{ R40,   R41,   R42,   R43,   R44,   R45,   R46 }  \
}


#define KC________ KC_TRNS
#define KC_RGB_MOD RGB_MOD
#define KC_FN FN
#define KC_ADJ ADJ
