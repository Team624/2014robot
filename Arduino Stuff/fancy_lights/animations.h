class Animation {
	public:
		virtual void setup() = 0;
		virtual bool update() = 0;
		int sleepTime;
};

class ColorRay : public Animation
{
	  uint32_t color;
  uint8_t pulseHead;
  uint8_t pulseWidth;

public:
  ColorRay(uint32_t c, int del) {
    sleepTime = del;
    pulseHead = 0;
    pulseWidth = 10;
    color = c;
  }

  void setup() {
    fillStrip(strip.Color(0,0,0));
    strip.show();
  }

  bool update() {
    strip.setPixelColor(pulseHead, color);
    strip.setPixelColor(pulseHead - pulseWidth, 0);
    pulseHead++;
    strip.show();
    if(pulseHead - pulseWidth >= strip.numPixels())
    { 
      return true;
    }
    else 
    {
      return false;
    }
  }
};

class Bounce : public Animation
{
	 uint32_t color;
  int x;
  int width;
  int wt; 
  bool reverse;

public:
  Bounce(uint32_t c, int del) : 
  x(0), width(15), wt(30) {
    sleepTime = del;
    color = c;
    reverse = false;
  }

  void setup() {
    fillStrip(strip.Color(0,0,0));
    strip.show();
  }

  bool update() {
    if(!reverse) {
      strip.setPixelColor(x, color);
      strip.setPixelColor(x-width, 0);
      x++;
      strip.show();
      if(x>= (strip.numPixels()-wt)) reverse = true;
      //  Serial.print("FORWAD");
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

class Strobes : public Animation
{
	 uint32_t c;
  uint32_t cc;
  int it;
  int flashes;
  bool on;

public:
  Strobes(uint32_t color1, uint32_t color2, int del, int f) {
    sleepTime = del;
    c = color1;
    cc = color2;
    on = false;
    flashes=f;
  }
  void setup() {
    fillStrip(strip.Color(0,0,0));
    strip.show();
  }

  bool update() {
    if(on) {
      fillStrip(c);
      on=false;
    } 
    else {
      fillStrip(cc);
      on=true;

    }
    strip.show();
    it++;
    if(it > flashes) return true;
    else return false;
  }
};

class Pixelate : public Animation
{
	 uint32_t c;

public:
  Pixelate(uint32_t color, int del)
  {
    c=color;
    sleepTime=del;
  }

  void setup() {
    fillStrip(strip.Color(0,0,0));
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
          isPicked=false;
        }
        if(pnum[px]!=1)
        {
          picks++;
          pnum[px]=1;
          isPicked=true;
          break;
        }
      }

      strip.setPixelColor(px,c);

      strip.show();
      delay(sleepTime);
    }
    return true;
  }
};

class Collision : public Animation
{
	uint32_t c;
	uint32_t cc;

	int left;
	int right;
	int width;
	int ends;
	
public:
	Collision(uint32_t color1,uint32_t color2, int wait){
    c=color1;
    cc=color2;
    sleepTime=wait;
    right = 0;
    width = 10;
    ends = right - width;
    left = strip.numPixels();
  }

  void setup() {
    fillStrip(strip.Color(0,0,0));
    strip.show();
  }

  bool update()
  {
    if((left+width)<=right)
    {
      strip.setPixelColor(left+width, c);
      strip.setPixelColor(right-width, c);
    }
    else
    {
      strip.setPixelColor(left+width, cc);
      strip.setPixelColor(right-width, cc);
    }
    left--;
    right++;
    strip.show();

    return !(right<=(strip.numPixels()+10));

  }
};

class FadePulse : public Animation
{
  uint32_t c;
  int curBright;
  static const int amountStep = 2;
  bool forward;
public: 
  FadePulse(uint32_t color, uint8_t wait) {
    c = color;
    sleepTime = wait;
    forward = true;
    curBright = 250;
  }
  void setup() {
    fillStrip(strip.Color(0,0,0));
    strip.show();
  }
  bool update() {
    fillStrip(c, curBright);
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
      }
    }
    strip.show();
    return false;
  }
};

class ThrottleBars : public Animation
{
	 uint32_t c;
  uint8_t pulseHead;
public:  
  ThrottleReactPulse(uint32_t co, uint8_t wait) { 
    c=co;
    sleepTime=wait;
    pulseHead = 0;
    
  }
  void setup() {

  }
  bool update()
  {
    uint32_t newColor = gradientColor(c, strip.Color(0, 255, 0), throttle);
    byte r = (byte)(newColor >> 16);
    byte g = (byte)(newColor >>  8);
    byte b = (byte) newColor;
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
      pulseHead += map(throttle, 0, 255, 1, 8);
      strip.show();
    return pulseHead > strip.numPixels();
  }
};

class PumpFake : public Animation
{
	uint32_t c;
	uint32_t cc;
	public:
	void setup() 
	{

	}
	bool update()
	{
	
	}
};

class RagingColors : public Animation
{
	uint32_t c;
	public:
	void setup() 
	{
		
	}
	bool update()
	{
		for (int i=0;i<strip.numPixels();i++)
		{
		
		}
	}
};

class Omni : public Animation
{
	uint32_t c;
	uint32_t corn = strip.numPixels()/3;
	uint32_t corns = strip.numPixels()-corn;
	bool state;
	public:
	Omni(uint32_t co, uint8_t wait)
	{
		sleepTime=wait;
		c=co;
		state = true;
	}
	void setup() 
	{
		fillStrip(strip.Color(0,0,0));
		strip.show();
	}
	bool update()
	{
		if(state)
		{
		for (int i=0;i<strip.numPixels();i++)
		{
			if(strip.numPixels()-i>=corns)
			{
				strip.setPixelColor(strip.numPixels()-i, c);
			}
			if(i<=corn)
			{
				strip.setPixelColor(i, c);
			}
			else
			{
				strip.setPixelColor(i, strip.Color(0,0,0));
			}
		}
		}
		
		else
		{
		for (int i=0;i<strip.numPixels();i++)
		{
			if(strip.numPixels()-i>=corns)
			{
				strip.setPixelColor(strip.numPixels()-i, strip.Color(0,0,0));
			}
			if(i<=corn)
			{
				strip.setPixelColor(i, strip.Color(0,0,0));
			}
			else
			{
				strip.setPixelColor(i, c);
			}
		}
		}
		strip.show();
		
	}
};

class FieldPOS : public Animation
{
	uint32_t r = strip.Color(255,0,0);
	uint32_t w = strip.Color(255,255,255);
	uint32_t b = strip.Color(0,0,255);
	uint32_t y = strip.Color(255,255,0);
	uint8_t sspot;
	uint8_t pos;
	uint8_t posScale;
	
	uint8_t red;
	uint8_t blue;
	uint8_t white;
	
	public:
	FieldPOS(uint8_t position, uint8_t spot, uint8_t wait)
	{
		sleepTime=wait;
		pos=position;
		sspot=spot;
	}
	void setup() 
	{
		fillStrip(strip.Color(0,0,0));
		strip.show();
		
		if(alliance=0)
		{
		red = ((strip.numPixels())/3)*2;
		blue = 0;
		}
		else
		{
		red = 0;
		blue = ((strip.numPixels()))*2;
		}
		white = ((strip.numPixels())/3);
	}
	bool update()
	{
		posScale = ((strip.numPixels())/54)*pos;
		
		for (int i=0;i<posScale;i++)
		{
			if(i>=red)
			{
				strip.setPixelColor(i,r);
			}
			if(i>=blue)
			{
				strip.setPixelColor(i,b);
			}
			if(i>=white)
			{
				strip.setPixelColor(i,w);
			}
			if(posScale=sspot)
			{
				strip.setPixelColor(strip.numPixels()-1,y);
			}
		}
	}
};

class Stripes : 
public Animation {
  uint32_t c;
  uint32_t cc;
public:
  Stripes(uint32_t col,uint32_t coll, uint8_t wait)
  {
    c=col;
    cc=coll;
    sleepTime=wait;
  }

  void setup() {
    fillStrip(strip.Color(0,0,0));
    strip.show();
  }

  bool update()
  {
    for(uint16_t i=0; i<strip.numPixels(); i++) {
      if(i%2==0)
      {
        strip.setPixelColor(i, c);
      }
      else
      {
        strip.setPixelColor(i, cc);
      }
      strip.show();

    }
    return true;
  }

};

class Steady : public Animation {
  uint32_t c;

public:
  Steady(uint32_t col, uint8_t wait)
  {
    c=col;
    sleepTime=wait;
  }

  void setup() {
    fillStrip(strip.Color(0,0,0));
    strip.show();
  }

	bool update()
	{
	for(uint16_t i=0; i<strip.numPixels(); i++) {
      if(i%2==0)
      {
        strip.setPixelColor(i, c);
      }
	  strip.show();
    }
	return true;
    }
    
};

