#ifndef config_h
#define config_h
#include <Adafruit_GFX.h>
#include <FastLED_NeoMatrix.h>
#include <FastLED.h>

#define mw 24
#define mh 32
#define NUMMATRIX (mw*mh)

// Compat for some other demos
#define NUM_LEDS NUMMATRIX 
#define MATRIX_HEIGHT mh
#define MATRIX_WIDTH mw


// Fonts + Gifs
// Sketch uses 676884 bytes (64%) of program storage space. Maximum is 1044464 bytes.
// Global variables use 33124 bytes (40%) of dynamic memory, leaving 48796 bytes for local variables. Maximum is 81920 bytes.
// Uploading 681024 bytes from /tmp/arduino_build_498793/NeoMatrix-FastLED-IR.ino.bin to flash at 0x00000000


// disable animated gifs for faster builds/uploads
// Sketch uses 332208 bytes (31%) of program storage space. Maximum is 1044464 bytes.
// Global variables use 33112 bytes (40%) of dynamic memory, leaving 48808 bytes for local variables. Maximum is 81920 bytes.
// Uploading 336352 bytes from /tmp/arduino_build_498793/NeoMatrix-FastLED-IR.ino.bin to flash at 0x00000000
//#define NOANIMGIF 1


// Disable fonts in many sizes
// Sketch uses 283784 bytes (27%) of program storage space. Maximum is 1044464 bytes.
// Global variables use 32880 bytes (40%) of dynamic memory, leaving 49040 bytes for local variables. Maximum is 81920 bytes.
// Uploading 287936 bytes from /tmp/arduino_build_498793/NeoMatrix-FastLED-IR.ino.bin to flash at 0x00000000
//#define NOFONTS 1



//---------------------------------------------------------------------------- 

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

extern FastLED_NeoMatrix *matrix;

int XY( int x, int y) 
{
	// For some reason, Y is reversed on my matrix, so fix this here.
	return matrix->XY(x,MATRIX_HEIGHT-1-y);

}

// Yeah, with default arguments, this should not be necessary, but I'm hitting
// a compiler bug that prevents , bool wrap=false in the signature.
int XY( int x, int y, bool wrap) { 
	return matrix->XY(x,MATRIX_HEIGHT-1-y);
}

#ifdef ESP8266
#define NEOPIXEL_PIN D1 // GPIO5


// D4 is also the system LED, causing it to blink on IR receive, which is great.
#define RECV_PIN D4     // GPIO2

// Turn off Wifi in setup()
// https://www.hackster.io/rayburne/esp8266-turn-off-wifi-reduce-current-big-time-1df8ae
//
#include "ESP8266WiFi.h"
extern "C" {
#include "user_interface.h"
}
// min/max are broken by the ESP8266 include
#define min(a,b) (a<b)?(a):(b)
#define max(a,b) (a>b)?(a):(b)
#endif

uint8_t gHue = 0; // rotating "base color" used by many of the patterns
uint16_t speed = 255;
#endif
