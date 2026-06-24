#pragma once

#define PLOOPY_DPI_OPTIONS { 800 }
#define PLOOPY_DPI_DEFAULT 0

/* 'Drag Scroll' Ploopy custom scrolling using mouse sensor */
#define PLOOPY_DRAGSCROLL_INVERT /* Invert vertical scroll direction to match a standard mouse wheel (rather than 'natural' direction */
#define PLOOPY_DRAGSCROLL_DIVISOR_H 256.0 /* Horizontal movement divisor; the higher the value the slower the scroll */
#define PLOOPY_DRAGSCROLL_DIVISOR_V 128.0 /* Vertical movement divisor; the higher the value the slower the scroll */
//#define PLOOPY_DRAGSCROLL_MOMENTARY /* Set the 'Drag Scroll' button to be active only on button held */

/* High resolution scrolling */
//#define POINTING_DEVICE_HIRES_SCROLL_ENABLE
//#define POINTING_DEVICE_HIRES_SCROLL_MULTIPLIER 1

#ifdef COMBO_ENABLE
    #define COMBO_TERM 40
#endif
