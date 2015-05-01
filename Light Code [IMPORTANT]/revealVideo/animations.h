class Animation {
	public:
		virtual void setup() = 0;
		virtual bool update() = 0;
		int sleepTime;
		
};

class Bounce : public Animation
{
	 uint32_t color;
  int x;
  int width;
  int wt; 
  bool reverse;
  Adafruit_NeoPixel& strip;
  int t;
  //Adafruit_NeoPixel stp;

public:
  Bounce(uint32_t c, int del, Adafruit_NeoPixel& stp): strip(stp), x(0), width(15), wt(12) {
    sleepTime = del;
    color = c;
    reverse = false;
	
  }

  void setup() {
    fillStrip(strip.Color(0,0,0),strip);
    strip.show();
  }

  bool update() {
    if(!reverse) {
      strip.setPixelColor(x, color);
      strip.setPixelColor(x-width, 0);
      x++;
      strip.show();
      if(x>= strip.numPixels()+15) reverse = true;
      //  Serial.print("FORWAD"); (strip.numPixels()+wt)
    } 
    else { //second half of bounce
      strip.setPixelColor(x, color);
      strip.setPixelColor(x+width, 0);
      x--;
      //Serial.print(x);
      strip.show();
      if(x < -15) { 
        return true; 
      }
    }
    return false;
  }
};

class Pixelate : public Animation
{
	uint32_t c;
	uint32_t cc;
	Adafruit_NeoPixel& strip;
	int t;
public:
  Pixelate(uint32_t color, uint32_t colors, int del, Adafruit_NeoPixel& stp): strip(stp)
  {
    c=color;
	cc=colors;
    sleepTime=del;
	
  }

  void setup() {
    fillStrip(strip.Color(0,0,0),strip);
    strip.show();
  }

  bool update(){
    int picks=0;
    int pnum[strip.numPixels()];
    int px;
	
    while(picks<strip.numPixels())
    {

      bool isPicked = false;
      while(!isPicked)
      {
        px=random(0,strip.numPixels()+1);
        if(pnum[px]==1)
        {
          isPicked=true;
		  picks++;
          pnum[px]=0;
		  strip.setPixelColor(px,cc);
		  break;
        }
        if(pnum[px]!=1)
        {
          picks++;
          pnum[px]=1;
          isPicked=true;
		  strip.setPixelColor(px,c);
          break;
        }
      }

      strip.show();
      delay(sleepTime);
    }
    return true;
  }
};

class FadePulse : public Animation
{
  uint32_t c;
  int curBright;
  static const int amountStep = 4;
  bool forward;
  Adafruit_NeoPixel& strip;
  int t;
 
public: 
  FadePulse(uint32_t color, uint8_t wait, Adafruit_NeoPixel& stp): strip(stp) {
    c = color;
    sleepTime = wait;
    forward = true;
    curBright = 250;
	
  }
  void setup() {
    fillStrip(strip.Color(0,0,0),strip);
    strip.show();
  }
  bool update() {
  
    fillStrip(c, curBright,strip);
    if(forward) {
      curBright += amountStep;
      if(curBright >= 255) {
        curBright = 255;
        forward = false;
      }
    }
    else {
      curBright -= amountStep;
      if(curBright <= 0) {
        forward = true; 
        curBright = 0;
		return true;
      }
    }
	//i++;
    strip.show();
    return false;
  
  }
};

class Scanner : public Animation {
  uint32_t c;
  byte r;
  byte g;
  byte b;
   Adafruit_NeoPixel& strip;
  uint8_t pulseHead;
  int t;
public:  
  Scanner(uint32_t co, uint8_t wait, Adafruit_NeoPixel& stp): strip(stp) { 
    c=co;
    sleepTime=wait;
    pulseHead = 0;
    r= (byte)(c >> 16);
    g = (byte)(c >>  8);
    b = (byte) c;
	
	
	
  }
  void setup() {

  }
  bool update()
  {
      for(uint8_t i=0; i<strip.numPixels(); ++i) {
        uint8_t divisor = 0;
        uint8_t distance = abs(i - pulseHead);
        if      (distance <= 2) divisor = 1;
        else if (distance <= 4) divisor = 2;
        else if (distance <= 6) divisor = 4;
        else if (distance <= 8) divisor = 8;
        else divisor = 16; 
        strip.setPixelColor(i, r/divisor, g/divisor, b/divisor);
      }
      pulseHead++;
      strip.show();
	  if(pulseHead>=strip.numPixels()+16)
	  {
		pulseHead=0;
	  }
    return pulseHead > strip.numPixels();
  }

}; 
class Rainbow : public Animation {
  
   uint16_t i, j;
   Adafruit_NeoPixel& strip;
   int t;

public:
  Rainbow(uint8_t wait, Adafruit_NeoPixel& stp): strip(stp)
  {
    sleepTime=wait;
  }

  void setup() {
    fillStrip(strip.Color(0,0,0),strip);
    strip.show();
  }

	bool update()
	{
	for(j=0; j<256; j++) {
		for(i=0; i<strip.numPixels(); i++) {
			strip.setPixelColor(i, Flag((i+j) & 255,strip));
		}
    strip.show();
    delay(sleepTime);
	}
	return true;
    }
    
};
class PixThree : public Animation {
  uint32_t r, w, b;
  Adafruit_NeoPixel& strip;
  int t;

public:
  PixThree(uint32_t red, uint32_t white, uint32_t blue,uint8_t wait, Adafruit_NeoPixel& stp): strip(stp)
  {
    sleepTime=wait;
	r=red;
	w=white;
	b=blue;
	
	
	
  }

  void setup() {
    fillStrip(strip.Color(0,0,0),strip);
    strip.show();
  }

	bool update()
	{
	int picks=0;
    int pnum[strip.numPixels()];
    int px;
    while(picks<strip.numPixels())
    {

      bool isPicked = false;
      while(!isPicked)
      {
        px=random(0,strip.numPixels()+1);
        if(pnum[px]==1)
        {
          isPicked=true;
		  
          pnum[px]=0;
		  if(picks%3==0)strip.setPixelColor(px,r);
		  else if((picks-1)%3==0)strip.setPixelColor(px,w);
		  else strip.setPixelColor(px,b);
		  picks++;
		  break;
        }
        if(pnum[px]!=1)
        {
		if(picks%3==0)strip.setPixelColor(px,r);
		  else if((picks-1)%3==0)strip.setPixelColor(px,w);
		  else strip.setPixelColor(px,b);
          picks++;
          pnum[px]=1;
          isPicked=true;
          break;
        }
      }

      strip.show();
      delay(sleepTime);
    }
    return true;
    }
};	
class Steady : public Animation {
  uint32_t c;
  Adafruit_NeoPixel& strip;
  int t;

public:
  Steady(uint32_t col, uint8_t wait, Adafruit_NeoPixel& stp): strip(stp)
  {
    c=col;
    sleepTime=wait;
	
	
	
  }

  void setup() {
    fillStrip(strip.Color(0,0,0),strip);
    strip.show();
  }

	bool update()
	{
	for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
	  strip.show();
    }
	return true;
    }
    
};
