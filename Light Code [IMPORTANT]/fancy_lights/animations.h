//4/17/14
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

class Strobes : public Animation
{
	 uint32_t c;
  uint32_t cc;
  int it;
  int flashes;
  bool on;
  bool other;
  Adafruit_NeoPixel& strip;
  int t;

public:
  Strobes(uint32_t color1, uint32_t color2, int del, int f, Adafruit_NeoPixel& stp): strip(stp) {
    sleepTime = del;
    c = color1;
    cc = color2;
    on = false;
    flashes=f;
	it=0;
	
	
	
  }

  void setup() {
    fillStrip(strip.Color(0,0,0),strip);
    strip.show();
  }
  
  bool update() {
  while(it<=flashes)
  {
    if(on) {
      fillStrip(c,strip);
    } 
    else{
      fillStrip(cc,strip);
    }
	on = !on;
    strip.show();
	//delay(sleepTime);
    it++;
  }
  return true;
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
        px=random(0,strip.numPixels());
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
      return false;
      //delay(sleepTime);
    }
    return true;
  }
};

class Collision : public Animation
{
	uint32_t c;
	uint32_t cc;
int t;
	int left;
	int right;
	int width;
	int ends;
	Adafruit_NeoPixel& strip;
	
public:
	Collision(uint32_t color1,uint32_t color2, int wait, Adafruit_NeoPixel& stp): strip(stp){
    c=color1;
    cc=color2;
    sleepTime=wait;
    right = 0;
    width = 10;
    ends = right - width;
    left = strip.numPixels();
	
	
	
  }

  void setup() {
    fillStrip(strip.Color(0,0,0),strip);
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
  uint32_t cc;
  int curBright;
  static const int amountStep = 2;
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
/*
class ThrottleBars : public Animation
{
	 uint32_t c;
	 int t;
	 Adafruit_NeoPixel& strip;
  uint8_t pulseHead;
public:  
  ThrottleBars(uint32_t co, uint8_t wait, Adafruit_NeoPixel& stp): strip(stp) { 
    c=co;
    sleepTime=wait;
    pulseHead = 0;
    
	
	
  }
  void setup() {

  }
  bool update()
  {
    uint32_t newColor = gradientColor(c, strip.Color(0, 255, 0), throttle,strip);
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
*/
class Omni : public Animation
{
	uint32_t c;
	int t;
	uint32_t corn;
	uint32_t corns;
	bool state;
	Adafruit_NeoPixel& strip;
	int it;
	
	public:
	Omni(uint32_t co, uint8_t wait, Adafruit_NeoPixel& stp): strip(stp)
	{
		sleepTime=wait;
		c=co;
		corn = strip.numPixels()/3;
		corns = strip.numPixels()-corn;
		state = true;
		it=0;
		
	
	
	}
	void setup() 
	{
		fillStrip(strip.Color(0,0,0),strip);
		strip.show();
	}
	bool update()
	{
	
	while(it<=10)
	{
		if(state)
		{
		for (int i=0;i<strip.numPixels();i++)
		{
			if(i>=corns)
			{
				strip.setPixelColor(i, c);
			}
			else if(i<=corn)
			{
				strip.setPixelColor(i, c);
			}
			else
			{
				strip.setPixelColor(i, strip.Color(0,0,0));
			}
		}
		state=false;
		}
		
		else
		{
		for (int i=0;i<strip.numPixels();i++)
		{
			if(i>=corns || i<=corn)
			{
				strip.setPixelColor(i, strip.Color(0,0,0));
			}
		
			else
			{
				strip.setPixelColor(i, c);
			}
		}
		state = true;
		}
		strip.show();
		//delay(sleepTime);
	}
	}
};

class FieldPOS : public Animation
{

	Adafruit_NeoPixel& strip;
	uint8_t red;
	uint8_t blue;
	uint8_t white;
	int t;
  int pressureIndex;
	bool gg, omom, read;
  bool on;
	
	public:
	FieldPOS(bool g, bool ready, bool om, uint8_t wait, Adafruit_NeoPixel& stp): strip(stp)
	{
		sleepTime=wait;
		gg=g;
		omom=om;
		read=ready;
		red = 0;
		blue = (strip.numPixels()/3)*2;
		white = strip.numPixels()/3;
    pressureIndex=0;
    on=true;
		
	}
	void setup() 
	{
		fillStrip(strip.Color(0,0,0),strip);
		strip.show();
	}
	bool update()
	{
		
		//high/low gear
		{
			uint32_t color;
			if(gg) //high gear
				color = strip.Color(0,255,0);
			else //low gear
				color = strip.Color(0,0,255);
				
			for(int i=0;i<white;i++)
			{
				strip.setPixelColor(i, color);
			}
		}
		
		//omni?
		{
			uint32_t color;
			if(omom) //omni
				color = strip.Color(0,0,0);
			else //traction
				color = strip.Color(255,0,0);
			
			for(int ii=white;ii<blue;ii++)
			{
				strip.setPixelColor(ii, color);
			}
		}
		
		//shoot ready?
		{
			uint32_t color;
			if(read)
				color = strip.Color(255,255,255);
			else
				color = strip.Color(0,0,0);
			
			for(int iii=blue;iii<strip.numPixels();iii++)
			{
				strip.setPixelColor(iii, color);
			}
		}
    /*
		if(pressure==PRESSURE_LOW)
		{
			if(pressureIndex%4==0)
			{
				if(on)
				{
					fillStrip(strip.Color(255,150,0),strip);
				} 
			
				else
				{
					fillStrip(strip.Color(0,0,0),strip);
					//i++;
				}
				on = !on; 
			}
		}
		else if(pressure==PRESSURE_EMPTY)
		{
			if(pressureIndex%2==0)
			{
				if(on)
				{
					fillStrip(strip.Color(255,0,0),strip);
				} 
				
				else
				{
					fillStrip(strip.Color(0,0,0),strip);
					//i++;
				}
				on = !on;
			}
		}
		pressureIndex = (pressureIndex+1) % 4;
		*/
		strip.show();
		//delay(sleepTime);
	}
	
};

class Stripes : 
public Animation {
  uint32_t c;
  uint32_t cc;
  Adafruit_NeoPixel& strip;
  int t;
public:
  Stripes(uint32_t col,uint32_t coll, uint8_t wait, Adafruit_NeoPixel& stp): strip(stp)
  {
    c=col;
    cc=coll;
    sleepTime=wait;
	
	
	
  }

  void setup() {
    fillStrip(strip.Color(0,0,0),strip);
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
			strip.setPixelColor(i, Wheel((i+j) & 255,strip));
		}
    strip.show();
    //delay(sleepTime);
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
      //delay(sleepTime);
    }
    return true;
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
    r = (byte)(c >> 16);
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
    return pulseHead > strip.numPixels();
  }

}; 

class America : public Animation {
  
   uint16_t i, j;
   Adafruit_NeoPixel& strip;
   int t;

public:
  America(uint8_t wait, Adafruit_NeoPixel& stp): strip(stp)
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
			strip.setPixelColor(i, Flag((i+j) & 255, strip));
		}
    strip.show();
    //delay(sleepTime);
	}
	return true;
    }
    
};

class Orbit : public Animation
{
	 uint32_t color;
	 int t;
  int x;
  int width;
  int wt; 
  bool reverse;
  Adafruit_NeoPixel& strip;

public:
  Orbit(uint32_t c, int del, Adafruit_NeoPixel& stp): strip(stp), x(0), width(15), wt(12) {
    sleepTime = del;
    color = c;
    reverse = false;
	x=0;
	
	
	
  }

  void setup() {
    fillStrip(strip.Color(0,0,0),strip);
    strip.show();
  }

  bool update() {
    strip.setPixelColor(x, color);
	if(x>=strip.numPixels())
	{
		x=0;
	}
	if(x-width>=0)
	{
    strip.setPixelColor(x-width, 0);
	}
	else
	{
	strip.setPixelColor(strip.numPixels()-(x-width), 0);
	}
    x++;
    strip.show();
   
    return false;
  }
};
class PinkSwag : public Animation
{
  uint32_t c;
  uint32_t cc;
  int curBright;
  static const int amountStep = 2;
  bool forward;
  Adafruit_NeoPixel& strip;
  int t;
 
public: 
  PinkSwag(uint32_t color, uint8_t wait, Adafruit_NeoPixel& stp): strip(stp) {
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
  
    fillStrip(gradientColor(c,strip.Color(255,0,136),curBright,strip), strip);
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
	//255,0,136
	//i++;
    strip.show();
    return false;
  
  }
};