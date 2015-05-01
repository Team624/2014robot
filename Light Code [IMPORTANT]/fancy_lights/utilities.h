uint32_t gradientColor(uint32_t colorFrom, uint32_t colorTo, byte fadeAmount, Adafruit_NeoPixel& strip) {

  uint8_t fromR = (uint8_t)(colorFrom >> 16);
  uint8_t fromG = (uint8_t)(colorFrom >>  8);
  uint8_t fromB = (uint8_t)colorFrom;
  uint8_t toR = (uint8_t)(colorTo >> 16);
  uint8_t toG = (uint8_t)(colorTo >>  8);
  uint8_t toB = (uint8_t)colorTo;
  return strip.Color(
    map(fadeAmount, 0, 255, fromR, toR),
    map(fadeAmount, 0, 255, fromG, toG),
    map(fadeAmount, 0, 255, fromB, toB)
  );
  
}

/* fill the strip with a certain brightness at a certain color */
void fillStrip(uint32_t c, uint8_t brightness, Adafruit_NeoPixel& strip) {

  uint8_t r = (uint8_t)(c >> 16);
  uint8_t g = (uint8_t)(c >>  8);
  uint8_t b = (uint8_t)c;
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, (r * brightness / 255), (g * brightness / 255), (b * brightness / 255));
  } 
  //
 // strip.show();
}

void fillStrip(uint32_t c, Adafruit_NeoPixel& strip) {

  fillStrip(c, 255, strip); 
}

uint32_t Wheel(byte WheelPos, Adafruit_NeoPixel& strip) {

  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

uint32_t Flag(byte WheelPos, Adafruit_NeoPixel& strip) {

  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 0, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 255 - WheelPos * 3, 255 - WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, 0, 255 - WheelPos * 3);
  }
}