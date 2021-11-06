/*  
 * File:          incbin-print-self.ino
 * Description:   incbin Aduino example. Prints out the content of this file to Serial.
 * URL:           https://github.com/AlexIII/incbin-arduino
 * 
 */ 
//                                    !!! IMPORTANT !!!
//          !!! This example WON'T COMPILE unless you follow these instructions !!! 
/* -----------------------------------------------------------------------------------------------
 *      1. SAVE this example (CTRL+S) to any folder on your disk
 *      2. CLOSE ALL Arduino windows
 *      3. Re-open the *.ino file you've just saved via DOUBLE-CLICK (DO NOT do File -> Open...)
 * -----------------------------------------------------------------------------------------------
 * 
 * 
 *    - You can use this library in your *.ino project as usual,
 *      it will compile fine, but you will have to open it via double-click every time.
 *    - See the github page for detailed explanation of these shenanigans.
 *    - If you have troubles using this library feel free to open an issue on the github.
 *    
 */

#include "incbin.h"

// Include TEXT file "incbin-print-self.ino" with name `Sketch`
INCTEXT(SketchText, "incbin-print-self.ino");
// This will create global variables:
//  const __FlashStringHelper gSketchTextData[];        // NULL-terminated Flash string, pointer to the data
//  const __FlashStringHelper *const gSketchTextEnd;    // Pointer to the end of the data
//  const unsigned int gSketchTextSize;                 // Size of the data in bytes


// Alternatively you can include the file as BINARY data
// --
// INCBIN(SketchText, "incbin-print-self.ino");
// --
// This will create global variables:
//  const unsigned char gSketchTextData[];              // Pointer to the data
//  const unsigned char *const gSketchTextEnd;          // Pointer to the end of the data
//  const unsigned int gSketchTextSize;                 // Size of the data in bytes

void setup() {
  Serial.begin(115200);

  // Print data content
  Serial.println(F("----------------------------------"));
  Serial.println(gSketchTextData);
  Serial.println(F("----------------------------------"));

  // Print data size
  Serial.print(F("Sketch file size: "));
  Serial.println(gSketchTextSize);


/* Alternatively, read the data byte-by-byte (for AVR-based Arduino) */
//  PGM_P p = reinterpret_cast<PGM_P>(gSketchTextData);
//  for(int i = 0; i < gSketchTextSize; ++i) {
//    unsigned char c = pgm_read_byte(p++);
//    Serial.write(c);
//  }
//  Serial.println();

}

void loop() {}
