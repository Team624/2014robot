uint32_t gradientColor(uint32_t colorFrom, uint32_t colorTo, byte fadeAmount) {
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
void fillStrip(uint32_t c, uint8_t brightness) {
  uint8_t r = (uint8_t)(c >> 16);
  uint8_t g = (uint8_t)(c >>  8);
  uint8_t b = (uint8_t)c;
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, (r * brightness / 255), (g * brightness / 255), (b * brightness / 255));
  } 
  //
 // strip.show();
}

void fillStrip(uint32_t c) {
  fillStrip(c, 255); 
}