// Copyright 2023 andrzej.skowron (@andrzej.skowron)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0xFEED
#define PRODUCT_ID   0x0000
#define DEVICE_VER   0x0001
#define MANUFACTURER "andrzej.skowron"
#define PRODUCT      "askcorne"


#define MASTER_LEFT
#define EE_HANDS


/* key matrix size */
#define MATRIX_COLS 6
#define MATRIX_ROWS 8

#define MATRIX_COL_PINS { F1, F0, B6, B2, B3, B1 }
// #define MATRIX_ROW_PINS { B1, B3, B2, B6, F0, F1 }
#define MATRIX_ROW_PINS { F4, F5, F6, F7 }
#define UNUSED_PINS
#define DIODE_DIRECTION COL2ROW


#define DEBOUNCE 5

#ifndef SOFT_SERIAL_PIN
#define SOFT_SERIAL_PIN D0
// #define SOFT_SERIAL_PIN D5
#define SERIAL_USE_MULTI_TRANSACTION
#endif


#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 100


#define TAPPING_TERM_PER_KEY
