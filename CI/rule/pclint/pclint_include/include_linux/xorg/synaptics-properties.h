/*
 * Copyright © 2008 Red Hat, Inc.
 *
 * Permission to use, copy, modify, distribute, and sell this software
 * and its documentation for any purpose is hereby granted without
 * fee, provided that the above copyright notice appear in all copies
 * and that both that copyright notice and this permission notice
 * appear in supporting documentation, and that the name of Red Hat
 * not be used in advertising or publicity pertaining to distribution
 * of the software without specific, written prior permission.  Red
 * Hat makes no representations about the suitability of this software
 * for any purpose.  It is provided "as is" without express or implied
 * warranty.
 *
 * THE AUTHORS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN
 * NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
 * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
 * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * Authors: Peter Hutterer
 */

#ifndef _SYNAPTICS_PROPERTIES_H_
#define _SYNAPTICS_PROPERTIES_H_

/**
 * Properties exported by the synaptics driver. These properties are
 * recognized by the driver and will change its behavior when modified.
 * For a description of what each property does, see synaptics.h.
 */

/* 32 bit, 4 values, left, right, top, bottom */
#define SYNAPTICS_PROP_EDGES "Synaptics Edges"

/* 32 bit, 3 values, low, high, press */
#define SYNAPTICS_PROP_FINGER "Synaptics Finger"

/* 32 bit */
#define SYNAPTICS_PROP_TAP_TIME "Synaptics Tap Time"

/* 32 bit */
#define SYNAPTICS_PROP_TAP_MOVE "Synaptics Tap Move"

/* 32 bit, 3 values, single touch timeout, max tapping time for double
 * taps, duration of a single click  */
#define SYNAPTICS_PROP_TAP_DURATIONS "Synaptics Tap Durations"

/* 8 bit (BOOL) */
#define SYNAPTICS_PROP_TAP_FAST "Synaptics Tap FastTap"

/* 32 bit */
#define SYNAPTICS_PROP_MIDDLE_TIMEOUT "Synaptics Middle Button Timeout"

/* 32 bit */
#define SYNAPTICS_PROP_TWOFINGER_PRESSURE "Synaptics Two-Finger Pressure"

/* 32 bit */
#define SYNAPTICS_PROP_TWOFINGER_WIDTH "Synaptics Two-Finger Width"

/* 32 bit, 2 values, vert, horiz */
#define SYNAPTICS_PROP_SCROLL_DISTANCE "Synaptics Scrolling Distance"

/* 8 bit (BOOL), 3 values, vertical, horizontal, corner */
#define SYNAPTICS_PROP_SCROLL_EDGE "Synaptics Edge Scrolling"

/* 8 bit (BOOL), 2 values, vertical, horizontal */
#define SYNAPTICS_PROP_SCROLL_TWOFINGER "Synaptics Two-Finger Scrolling"

/* FLOAT, 4 values, min, max, accel, trackstick */
#define SYNAPTICS_PROP_SPEED "Synaptics Move Speed"

/* 32 bit, 2 values, min, max */
#define SYNAPTICS_PROP_EDGEMOTION_PRESSURE "Synaptics Edge Motion Pressure"

/* 32 bit, 2 values, min, max */
#define SYNAPTICS_PROP_EDGEMOTION_SPEED "Synaptics Edge Motion Speed"

/* 8 bit (BOOL) */
#define SYNAPTICS_PROP_EDGEMOTION "Synaptics Edge Motion Always"

/* 8 bit (BOOL), 2 values, updown, leftright */
#define SYNAPTICS_PROP_BUTTONSCROLLING "Synaptics Button Scrolling"

/* 8 bit (BOOL), 2 values, updown, leftright */
#define SYNAPTICS_PROP_BUTTONSCROLLING_REPEAT "Synaptics Button Scrolling Repeat"

/* 32 bit */
#define SYNAPTICS_PROP_BUTTONSCROLLING_TIME "Synaptics Button Scrolling Time"

/* 8 bit, valid values (0, 1, 2) */
#define SYNAPTICS_PROP_OFF "Synaptics Off"

/* 8 bit (BOOL) */
#define SYNAPTICS_PROP_GUESTMOUSE "Synaptics Guestmouse Off"

/* 8 bit (BOOL) */
#define SYNAPTICS_PROP_LOCKED_DRAGS "Synaptics Locked Drags"

/* 32 bit */
#define SYNAPTICS_PROP_LOCKED_DRAGS_TIMEOUT "Synaptics Locked Drags Timeout"

/* 8 bit, up to MAX_TAP values (see synaptics.h), 0 disables an
 * element. order: RT, RB, LT, LB, F1, F2, F3 */
#define SYNAPTICS_PROP_TAP_ACTION "Synaptics Tap Action"

/* 8 bit, up to MAX_CLICK values (see synaptics.h), 0 disables an
 * element. order: Finger 1, 2, 3 */
#define SYNAPTICS_PROP_CLICK_ACTION "Synaptics Click Action"

/* 8 bit (BOOL) */
#define SYNAPTICS_PROP_CIRCULAR_SCROLLING "Synaptics Circular Scrolling"

/* FLOAT */
#define SYNAPTICS_PROP_CIRCULAR_SCROLLING_DIST "Synaptics Circular Scrolling Distance"

/* 8 bit, valid values 0..8 (inclusive)
 * order: any edge, top, top + right, right, right + bottom, bottom, bottom +
 * left, left, left  + top */
#define SYNAPTICS_PROP_CIRCULAR_SCROLLING_TRIGGER "Synaptics Circular Scrolling Trigger"

/* 8 bit (BOOL) */
#define SYNAPTICS_PROP_CIRCULAR_PAD "Synaptics Circular Pad"

/* 8 bit (BOOL) */
#define SYNAPTICS_PROP_PALM_DETECT "Synaptics Palm Detection"

/* 32 bit, 2 values, width, z */
#define SYNAPTICS_PROP_PALM_DIMENSIONS "Synaptics Palm Dimensions"

/* FLOAT */
#define SYNAPTICS_PROP_COASTING_SPEED "Synaptics Coasting Speed"

/* 32 bit, 2 values, min, max */
#define SYNAPTICS_PROP_PRESSURE_MOTION "Synaptics Pressure Motion"

/* FLOAT, 2 values, min, max */
#define SYNAPTICS_PROP_PRESSURE_MOTION_FACTOR "Synaptics Pressure Motion Factor"

/* 8 bit (BOOL) */
#define SYNAPTICS_PROP_GRAB "Synaptics Grab Event Device"

/* 32 bit */
#define SYNAPTICS_PROP_LED_DOUBLE_TAP "Synaptics LED Double Tap"

/* 8 bit (0-100) */
#define SYNAPTICS_PROP_TOUCH_BUTTON_AREA "Synaptics Touch Button Area"

/* 8 bit (BOOL) */
#define SYNAPTICS_PROP_TOUCH_BUTTON_SENSE "Synaptics Touch Button Sense"

#endif /* _SYNAPTICS_PROPERTIES_H_ */
