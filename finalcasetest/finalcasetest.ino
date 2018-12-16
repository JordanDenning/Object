#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 10

Adafruit_NeoPixel strip = Adafruit_NeoPixel(120, PIN, NEO_GRB + NEO_KHZ800);
uint32_t green = strip.Color(0,255,0);
uint32_t red = strip.Color(255,0,0);
uint32_t blue = strip.Color(0,0,255);
uint32_t cyan = strip.Color(2,247,255);
uint32_t purple = strip.Color(109,0,171);
uint32_t orange = strip.Color(255,89,0);
uint32_t yellow = strip.Color(255,242,0);



int count = 0;
int switchOn = 12;
byte incomingByte;
byte note;
byte velocity;
int chan = 1;  //specify what MIDI channel we're listing to
 
int action=2; //0 =note off ; 1=note on ; 2= null
const int lowNote = 36; //what's the first note?  36 is C1 in Ableton
void setup() 
{
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  pinMode(switchOn, INPUT);
  strip.begin();
  strip.setBrightness(10);
  strip.show();


//strip.setPixelColor(19,green);
//strip.setPixelColor(50,cyan);
//strip.setPixelColor(20,blue);
//strip.setPixelColor(39,red);
//strip.setPixelColor(59,purple);
//strip.setPixelColor(100,yellow);
//strip.setPixelColor(119,orange);


      strip.setPixelColor(6,red);
      strip.setPixelColor(27,red);

      strip.setPixelColor(18,orange);
      strip.setPixelColor(24,orange);

       strip.setPixelColor(67,yellow);
      strip.setPixelColor(57,yellow);

      strip.setPixelColor(79,green);
      strip.setPixelColor(45,green);

      strip.setPixelColor(87,cyan);
      strip.setPixelColor(118,cyan);

      strip.setPixelColor(96,blue);
      strip.setPixelColor(100,blue);

      strip.setPixelColor(2,purple);
      strip.setPixelColor(110,purple);
      
strip.show();
  

}  


void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
    incomingByte = Serial.read();
    if(incomingByte==143+chan)
    {
      action = 1;
    }
    else if(incomingByte==127+chan)
    {
      action = 0;
    }
    else if((action==0)&&(note==0))
    {
      note=incomingByte;
      lightsOff(note);
      note=0;
      action=2;
    }
    else if((action==1)&&(note==0))
    {
      note=incomingByte;
    }
    else if((action==1)&&(note!=0))
    {
      velocity=incomingByte;
      lightsOn(note,velocity);
      note=0;
      velocity=0;
      action=0;
    }
    else
    {
      //nothing
    }
  }

}

void lightsOn(byte note, byte velocity)
{
      switch(note)
    {
  case(31):
    uint32_t color;
    //green
    //red
    //blue
    //cyan
    //purple
    //orange
    //yellow
      if((velocity >= 15) && (velocity < 24))
      {
         color = red;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = green;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = blue;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = orange;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = yellow;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = purple;
      }
       else if((velocity >=60))
      {
        color = cyan;
      }
      strip.setPixelColor(0,color);
      strip.setPixelColor(38,color);
      strip.show();
      break;
  case(32):
//   red,green,blue,purple,orange,yellow,cyan
      if((velocity >= 15) && (velocity < 24))
      {
         color = red;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = blue;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = orange;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = purple;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = cyan;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = green;
      }
       else if((velocity >=60))
      {
        color = yellow;
      }
      strip.setPixelColor(3,color);
      strip.setPixelColor(34,color);
      strip.show();
      break;
 case(33):
//  uint32_t color;
            if((velocity >= 15) && (velocity < 24))
      {
         color = red;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = green;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = blue;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = orange;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = yellow;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = purple;
      }
       else if((velocity >=60))
      {
        color = cyan;
      }
      strip.setPixelColor(6,color);
      strip.setPixelColor(27,color);
      strip.show();
      break;
  case(34):
//   uint32_t color;
      if((velocity >= 15) && (velocity < 24))
      {
         color = green;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = orange;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = red;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = yellow;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = cyan;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = blue;
      }
       else if((velocity >=60))
      {
        color = purple;
      }
      strip.setPixelColor(10,color);
      strip.setPixelColor(39,color);
      strip.show();
      break;
  case(35):
//   uint32_t color;
        if((velocity >= 15) && (velocity < 24))
      {
         color = blue;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = red;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = yellow;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = cyan;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = green;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = orange;
      }
       else if((velocity >=60))
      {
        color = purple;
      }
      strip.setPixelColor(5,color);
      strip.setPixelColor(25,color);
      strip.show();
      break;
  case(36):
//   uint32_t color;
        if((velocity >= 15) && (velocity < 24))
      {
         color = orange;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = blue;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = red;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = yellow;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = cyan;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = green;
      }
       else if((velocity >=60))
      {
        color = purple;
      }
      strip.setPixelColor(16,color);
      strip.setPixelColor(20,color);
      strip.show();
      break;
  case(37):
        if((velocity >= 15) && (velocity < 24))
      {
         color = yellow;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = red;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = purple;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = blue;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = cyan;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = orange;
      }
       else if((velocity >=60))
      {
        color = green;
      }
      strip.setPixelColor(11,color);
      strip.setPixelColor(35,color);
      strip.show();
      break;
  case(38):
        if((velocity >= 15) && (velocity < 24))
      {
         color = purple;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = green;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = red;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = orange;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = blue;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = yellow;
      }
       else if((velocity >=60))
      {
        color = cyan;
      }
      strip.setPixelColor(2,color);
      strip.setPixelColor(28,color);
      strip.show();
      break;
  case(39):
        if((velocity >= 15) && (velocity < 24))
      {
         color = cyan;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = red;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = yellow;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = blue;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = purple;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = green;
      }
       else if((velocity >=60))
      {
        color = orange;
      }
      strip.setPixelColor(7,color);
      strip.setPixelColor(29,color);
      strip.show();
      break;
  case(40):
        if((velocity >= 15) && (velocity < 24))
      {
         color = red;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = orange;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = green;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = yellow;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = purple;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = blue;
      }
       else if((velocity >=60))
      {
        color = cyan;
      }
      strip.setPixelColor(1,color);
      strip.setPixelColor(37,color);
      strip.show();
      break;
  case(41):
        if((velocity >= 15) && (velocity < 24))
      {
         color = red;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = orange;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = blue;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = green;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = yellow;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = purple;
      }
       else if((velocity >=60))
      {
        color = cyan;
      }
      strip.setPixelColor(4,color);
      strip.setPixelColor(36,color);
      strip.show();
      break;
  case(42):
        if((velocity >= 15) && (velocity < 24))
      {
         color = green;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = orange;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = cyan;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = blue;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = purple;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = red;
      }
       else if((velocity >=60))
      {
        color = yellow;
      }
      strip.setPixelColor(8,color);
      strip.setPixelColor(33,color);
      strip.show();
      break;
  case(43):
        if((velocity >= 15) && (velocity < 24))
      {
         color = blue;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = red;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = green;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = purple;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = yellow;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = orange;
      }
       else if((velocity >=60))
      {
        color = cyan;
      }
      strip.setPixelColor(9,color);
      strip.setPixelColor(31,color);
      strip.show();
      break;
  case(44):
        if((velocity >= 15) && (velocity < 24))
      {
         color = orange;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = green;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = blue;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = red;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = cyan;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = yellow;
      }
       else if((velocity >=60))
      {
        color = purple;
      }
      strip.setPixelColor(12,color);
      strip.setPixelColor(32,color);
      strip.show();
      break;
  case(45):
        if((velocity >= 15) && (velocity < 24))
      {
         color = red;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = yellow;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = cyan;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = orange;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = purple;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = green;
      }
       else if((velocity >=60))
      {
        color = blue;
      }
      strip.setPixelColor(19,color);
      strip.setPixelColor(26,color);
      strip.show();
      break;
  case(46):
        if((velocity >= 15) && (velocity < 24))
      {
         color = red;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = green;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = blue;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = orange;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = yellow;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = purple;
      }
       else if((velocity >=60))
      {
        color = cyan;
      }
      strip.setPixelColor(13,color);
      strip.setPixelColor(30,color);
      strip.show();
      break;
  case(47):
        if((velocity >= 15) && (velocity < 24))
      {
         color = yellow;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = green;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = purple;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = blue;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = cyan;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = red;
      }
       else if((velocity >=60))
      {
        color = orange;
      }
      strip.setPixelColor(14,color);
      strip.setPixelColor(22,color);
      strip.show();
      break;
  case(48):
        if((velocity >= 15) && (velocity < 24))
      {
         color = purple;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = orange;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = red;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = blue;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = cyan;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = green;
      }
       else if((velocity >=60))
      {
        color = yellow;
      }
      strip.setPixelColor(18,color);
      strip.setPixelColor(24,color);
      strip.show();
      break;
  case(49):
        if((velocity >= 15) && (velocity < 24))
      {
         color = cyan;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = red;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = green;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = purple;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = yellow;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = blue;
      }
       else if((velocity >=60))
      {
        color = orange;
      }
      strip.setPixelColor(15,color);
      strip.setPixelColor(23,color);
      strip.show();
      break;
  case(50):
        if((velocity >= 15) && (velocity < 24))
      {
         color = orange;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = purple;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = blue;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = cyan;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = yellow;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = red;
      }
       else if((velocity >=60))
      {
        color = green;
      }
      strip.setPixelColor(17,color);
      strip.setPixelColor(21,color);
      strip.show();
      break;
  case(51):
        if((velocity >= 15) && (velocity < 24))
      {
         color = green;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = yellow;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = orange;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = blue;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = red;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = purple;
      }
       else if((velocity >=60))
      {
        color = cyan;
      }
      strip.setPixelColor(6,color);
      strip.setPixelColor(30,color);
      strip.show();
      break;
  case(52):
        if((velocity >= 15) && (velocity < 24))
      {
         color = orange;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = red;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = green;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = cyan;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = purple;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = blue;
      }
       else if((velocity >=60))
      {
        color = yellow;
      }
      strip.setPixelColor(11,color);
      strip.setPixelColor(32,color);
      strip.show();
      break;
  case(53):
        if((velocity >= 15) && (velocity < 24))
      {
         color = blue;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = cyan;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = red;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = purple;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = yellow;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = green;
      }
       else if((velocity >=60))
      {
        color = orange;
      }
      strip.setPixelColor(8,color);
      strip.setPixelColor(27,color);
      strip.show();
      break;
  case(54):
        if((velocity >= 15) && (velocity < 24))
      {
         color = yellow;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = blue;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = green;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = cyan;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = red;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = orange;
      }
       else if((velocity >=60))
      {
        color = purple;
      }
      strip.setPixelColor(79,color);
      strip.setPixelColor(45,color);
      strip.show();
      break;
  case(55):
        if((velocity >= 15) && (velocity < 24))
      {
         color = purple;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = orange;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = cyan;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = yellow;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = green;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = red;
      }
       else if((velocity >=60))
      {
        color = blue;
      }
      strip.setPixelColor(41,color);
      strip.setPixelColor(75,color);
      strip.show();
      break;
 case(56):
       if((velocity >= 15) && (velocity < 24))
      {
         color = blue;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = yellow;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = purple;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = red;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = cyan;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = green;
      }
       else if((velocity >=60))
      {
        color = orange;
      }
      strip.setPixelColor(44,color);
      strip.setPixelColor(77,color);
      strip.show();
      break;
 case(57):
       if((velocity >= 15) && (velocity < 24))
      {
         color = orange;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = blue;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = green;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = cyan;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = purple;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = red;
      }
       else if((velocity >=60))
      {
        color = yellow;
      }
      strip.setPixelColor(40,color);
      strip.setPixelColor(74,color);
      strip.show();
      break;
  case(58):
        if((velocity >= 15) && (velocity < 24))
      {
         color = yellow;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = red;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = green;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = orange;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = cyan;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = blue;
      }
       else if((velocity >=60))
      {
        color = purple;
      }
      strip.setPixelColor(78,color);
      strip.setPixelColor(46,color);
      strip.show();
      break;
  case(59):
        if((velocity >= 15) && (velocity < 24))
      {
         color = red;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = blue;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = yellow;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = cyan;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = orange;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = green;
      }
       else if((velocity >=60))
      {
        color = purple;
      }
      strip.setPixelColor(76,color);
      strip.setPixelColor(47,color);
      strip.show();
      break;
  case(60):
        if((velocity >= 15) && (velocity < 24))
      {
         color = green;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = blue;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = cyan;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = orange;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = purple;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = red;
      }
       else if((velocity >=60))
      {
        color = yellow;
      }
      strip.setPixelColor(43,color);
      strip.setPixelColor(73,color);
      strip.show();
      break;
  case(61):
        if((velocity >= 15) && (velocity < 24))
      {
         color = red;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = green;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = blue;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = orange;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = yellow;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = purple;
      }
       else if((velocity >=60))
      {
        color = cyan;
      }
      strip.setPixelColor(48,color);
      strip.setPixelColor(70,color);
      strip.show();
      break;
  case(62):
        if((velocity >= 15) && (velocity < 24))
      {
         color = red;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = cyan;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = purple;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = blue;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = yellow;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = green;
      }
       else if((velocity >=60))
      {
        color = orange;
      }
      strip.setPixelColor(49,color);
      strip.setPixelColor(72,color);
      strip.show();
      break;
  case(63):
        if((velocity >= 15) && (velocity < 24))
      {
         color = green;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = blue;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = red;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = cyan;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = yellow;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = orange;
      }
       else if((velocity >=60))
      {
        color = purple;
      }
      strip.setPixelColor(52,color);
      strip.setPixelColor(71,color);
      strip.show();
      break;
  case(64):
        if((velocity >= 15) && (velocity < 24))
      {
         color = blue;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = orange;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = yellow;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = green;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = purple;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = red;
      }
       else if((velocity >=60))
      {
        color = cyan;
      }
      strip.setPixelColor(50,color);
      strip.setPixelColor(68,color);
      strip.show();
      break;
  case(65):
        if((velocity >= 15) && (velocity < 24))
      {
         color = orange;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = red;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = cyan;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = yellow;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = blue;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = green;
      }
       else if((velocity >=60))
      {
        color = purple;
      }
      strip.setPixelColor(53,color);
      strip.setPixelColor(69,color);
      strip.show();
      break;
  case(66):
        if((velocity >= 15) && (velocity < 24))
      {
         color = yellow;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = blue;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = purple;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = orange;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = cyan;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = red;
      }
       else if((velocity >=60))
      {
        color = green;
      }
      strip.setPixelColor(51,color);
      strip.setPixelColor(63,color);
      strip.show();
      break;
  case(67):
        if((velocity >= 15) && (velocity < 24))
      {
         color = purple;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = green;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = yellow;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = orange;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = cyan;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = red;
      }
       else if((velocity >=60))
      {
        color = blue;
      }
      strip.setPixelColor(67,color);
      strip.setPixelColor(57,color);
      strip.show();
      break;
  case(68):
        if((velocity >= 15) && (velocity < 24))
      {
         color = cyan;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = blue;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = green;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = purple;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = red;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = orange;
      }
       else if((velocity >=60))
      {
        color = yellow;
      }
      strip.setPixelColor(59,color);
      strip.setPixelColor(65,color);
      strip.show();
      break;
  case(69):
        if((velocity >= 15) && (velocity < 24))
      {
         color = cyan;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = orange;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = yellow;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = blue;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = green;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = red;
      }
       else if((velocity >=60))
      {
        color = purple;
      }
      strip.setPixelColor(58,color);
      strip.setPixelColor(64,color);
      strip.show();
      break;
  case(70):
        if((velocity >= 15) && (velocity < 24))
      {
         color = red;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = blue;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = yellow;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = purple;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = orange;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = green;
      }
       else if((velocity >=60))
      {
        color = cyan;
      }
      strip.setPixelColor(55,color);
      strip.setPixelColor(62,color);
      strip.show();
      break;
  case(71):
        if((velocity >= 15) && (velocity < 24))
      {
         color = green;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = blue;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = red;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = purple;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = orange;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = yellow;
      }
       else if((velocity >=60))
      {
        color = cyan;
      }
      strip.setPixelColor(54,color);
      strip.setPixelColor(61,color);
      strip.show();
      break;
  case(72):
        if((velocity >= 15) && (velocity < 24))
      {
         color = blue;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = orange;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = red;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = green;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = cyan;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = yellow;
      }
       else if((velocity >=60))
      {
        color = purple;
      }
      strip.setPixelColor(56,color);
      strip.setPixelColor(60,color);
      strip.show();
      break;
  case(73):
        if((velocity >= 15) && (velocity < 24))
      {
         color = cyan;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = blue;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = yellow;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = orange;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = purple;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = red;
      }
       else if((velocity >=60))
      {
        color = green;
      }
      strip.setPixelColor(51,color);
      strip.setPixelColor(71,color);
      strip.show();
      break;
  case(74):
        if((velocity >= 15) && (velocity < 24))
      {
         color = orange;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = red;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = cyan;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = yellow;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = purple;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = blue;
      }
       else if((velocity >=60))
      {
        color = green;
      }
      strip.setPixelColor(46,color);
      strip.setPixelColor(68,color);
      strip.show();
      break;
  case(75):
        if((velocity >= 15) && (velocity < 24))
      {
         color = yellow;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = blue;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = green;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = purple;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = orange;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = red;
      }
       else if((velocity >=60))
      {
        color = cyan;
      }
      strip.setPixelColor(82,color);
      strip.setPixelColor(118,color);
      strip.show();
      break;
  case(76):
        if((velocity >= 15) && (velocity < 24))
      {
         color = purple;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = orange;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = green;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = yellow;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = cyan;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = blue;
      }
       else if((velocity >=60))
      {
        color = red;
      }
      strip.setPixelColor(98,color);
      strip.setPixelColor(110,color);
      strip.show();
      break;
  case(77):
        if((velocity >= 15) && (velocity < 24))
      {
         color = red;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = green;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = blue;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = orange;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = yellow;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = purple;
      }
       else if((velocity >=60))
      {
        color = cyan;
      }
      strip.setPixelColor(95,color);
      strip.setPixelColor(101,color);
      strip.show();
      break;
  case(78):
        if((velocity >= 15) && (velocity < 24))
      {
         color = cyan;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = yellow;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = red;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = green;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = orange;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = purple;
      }
       else if((velocity >=60))
      {
        color = blue;
      }
      strip.setPixelColor(102,color);
      strip.setPixelColor(91,color);
      strip.show();
      break;
  case(79):
        if((velocity >= 15) && (velocity < 24))
      {
         color = orange;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = blue;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = purple;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = cyan;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = green;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = red;
      }
       else if((velocity >=60))
      {
        color = yellow;
      }
      strip.setPixelColor(93,color);
      strip.setPixelColor(103,color);
      strip.show();
      break;
  case(80):
        if((velocity >= 15) && (velocity < 24))
      {
         color = blue;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = cyan;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = red;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = green;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = orange;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = yellow;
      }
       else if((velocity >=60))
      {
        color = purple;
      }
      strip.setPixelColor(94,color);
      strip.setPixelColor(107,color);
      strip.show();
      break;
  case(81):
          if((velocity >= 15) && (velocity < 24))
      {
         color = purple;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = orange;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = green;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = yellow;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = cyan;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = blue;
      }
       else if((velocity >=60))
      {
        color = red;
      }
      strip.setPixelColor(99,color);
      strip.setPixelColor(105,color);
      strip.show();
      break;
  case(82):
        if((velocity >= 15) && (velocity < 24))
      {
         color = red;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = green;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = blue;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = orange;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = yellow;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = purple;
      }
       else if((velocity >=60))
      {
        color = cyan;
      }
      strip.setPixelColor(96,color);
      strip.setPixelColor(100,color);
      strip.show();
      break;
  case(83):
       if((velocity >= 15) && (velocity < 24))
      {
         color = red;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = green;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = blue;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = orange;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = yellow;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = purple;
      }
       else if((velocity >=60))
      {
        color = cyan;
      }
      strip.setPixelColor(97,color);
      strip.setPixelColor(106,color);
      strip.show();
      break;
  case(84):
       if((velocity >= 15) && (velocity < 24))
      {
         color = blue;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = red;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = green;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = purple;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = yellow;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = orange;
      }
       else if((velocity >=60))
      {
        color = cyan;
      }
      strip.setPixelColor(90,color);
      strip.setPixelColor(104,color);
      strip.show();
      break;
  case(85):
             if((velocity >= 15) && (velocity < 24))
      {
         color = cyan;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = blue;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = green;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = purple;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = red;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = orange;
      }
       else if((velocity >=60))
      {
        color = yellow;
      }
      strip.setPixelColor(92,color);
      strip.setPixelColor(111,color);
      strip.show();
      break;
  case(86):
         if((velocity >= 15) && (velocity < 24))
      {
         color = red;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = cyan;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = purple;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = blue;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = yellow;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = green;
      }
       else if((velocity >=60))
      {
        color = orange;
      }
      strip.setPixelColor(86,color);
      strip.setPixelColor(108,color);
      strip.show();
      break;
  case(87):
          if((velocity >= 15) && (velocity < 24))
      {
         color = blue;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = orange;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = red;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = green;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = cyan;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = yellow;
      }
       else if((velocity >=60))
      {
        color = purple;
      }
      strip.setPixelColor(89,color);
      strip.setPixelColor(113,color);
      strip.show();
      break;
  case(88):
          if((velocity >= 15) && (velocity < 24))
      {
         color = orange;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = blue;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = red;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = yellow;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = cyan;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = green;
      }
       else if((velocity >=60))
      {
        color = purple;
      }
      strip.setPixelColor(87,color);
      strip.setPixelColor(109,color);
      strip.show();
      break;
  case(89):
           if((velocity >= 15) && (velocity < 24))
      {
         color = blue;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = orange;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = red;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = green;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = cyan;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = yellow;
      }
       else if((velocity >=60))
      {
        color = purple;
      }
      strip.setPixelColor(88,color);
      strip.setPixelColor(114,color);
      strip.show();
      break;
  case(90):
            if((velocity >= 15) && (velocity < 24))
      {
         color = yellow;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = red;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = green;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = orange;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = cyan;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = blue;
      }
       else if((velocity >=60))
      {
        color = purple;
      }
      strip.setPixelColor(83,color);
      strip.setPixelColor(112,color);
      strip.show();
      break;
  case(91):
   if((velocity >= 15) && (velocity < 24))
      {
         color = green;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = orange;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = red;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = yellow;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = cyan;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = blue;
      }
       else if((velocity >=60))
      {
        color = purple;
      }
      strip.setPixelColor(118,color);
      strip.setPixelColor(83,color);
      strip.show();
      break;
  case(92):
        if((velocity >= 15) && (velocity < 24))
      {
         color = yellow;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = red;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = purple;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = blue;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = cyan;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = orange;
      }
       else if((velocity >=60))
      {
        color = green;
      }
      strip.setPixelColor(80,color);
      strip.setPixelColor(116,color);
      strip.show();
      break;
  case(93):
      if((velocity >= 15) && (velocity < 24))
      {
         color = cyan;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = blue;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = green;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = purple;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = red;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = orange;
      }
       else if((velocity >=60))
      {
        color = yellow;
      }
      strip.setPixelColor(84,color);
      strip.setPixelColor(119,color);
      strip.show();
      break;
  case(94):
   if((velocity >= 15) && (velocity < 24))
      {
         color = purple;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = green;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = yellow;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = orange;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = cyan;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = red;
      }
       else if((velocity >=60))
      {
        color = blue;
      }
      strip.setPixelColor(85,color);
      strip.setPixelColor(117,color);
      strip.show();
      break;
  case(95):
        if((velocity >= 15) && (velocity < 24))
      {
         color = red;
      }
      else if((velocity >=24)&&(velocity < 33))
      {
        color = green;
      }
       else if((velocity >=33)&&(velocity < 32))
      {
        color = blue;
      }
       else if((velocity >=32)&&(velocity < 41))
      {
        color = orange;
      }
       else if((velocity >=41)&&(velocity < 50))
      {
        color = yellow;
      }
       else if((velocity >=50)&&(velocity < 59))
      {
        color = purple;
      }
       else if((velocity >=60))
      {
        color = cyan;
      }
      strip.setPixelColor(81,color);
      strip.setPixelColor(115,color);
      strip.show();
      break;      
    }
}


void lightsOff(byte note)
{
      switch(note)
    {
    case(31):
        strip.setPixelColor(0,0);
        strip.setPixelColor(38,0);
        strip.show();
      break;
   case(32):
      strip.setPixelColor(3,0);
      strip.setPixelColor(34,0);
      strip.show();
      break;
   case(33):
      strip.setPixelColor(6,0);
      strip.setPixelColor(27,0);
      strip.show();
      break;
  case(34):
      strip.setPixelColor(10,0);
      strip.setPixelColor(39,0);
      strip.show();
      break;
  case(35):
      strip.setPixelColor(5,0);
      strip.setPixelColor(25,0);
      strip.show();
      break;
  case(36):
      strip.setPixelColor(16,0);
      strip.setPixelColor(20,0);
      strip.show();
      break;
  case(37):
      strip.setPixelColor(11,0);
      strip.setPixelColor(35,0);
      strip.show();
      break;
  case(38):
      strip.setPixelColor(2,0);
      strip.setPixelColor(28,0);
      strip.show();
      break;
  case(39):
      strip.setPixelColor(7,0);
      strip.setPixelColor(29,0);
      strip.show();
      break;
  case(40):
      strip.setPixelColor(1,0);
      strip.setPixelColor(37,0);
      strip.show();
      break;
  case(41):
      strip.setPixelColor(4,0);
      strip.setPixelColor(36,0);
      strip.show();
      break;
  case(42):
      strip.setPixelColor(8,0);
      strip.setPixelColor(33,0);
      strip.show();
      break;
  case(43):
      strip.setPixelColor(9,0);
      strip.setPixelColor(31,0);
      strip.show();
      break;
  case(44):
      strip.setPixelColor(12,0);
      strip.setPixelColor(32,0);
      strip.show();
      break;
  case(45):
      strip.setPixelColor(19,0);
      strip.setPixelColor(26,0);
      strip.show();
      break;
  case(46):
      strip.setPixelColor(13,0);
      strip.setPixelColor(30,0);
      strip.show();
      break;
  case(47):
      strip.setPixelColor(14,0);
      strip.setPixelColor(22,0);
      strip.show();
      break;
  case(48):
      strip.setPixelColor(18,0);
      strip.setPixelColor(24,0);
      strip.show();
      break;
  case(49):
      strip.setPixelColor(15,0);
      strip.setPixelColor(23,0);
      strip.show();
      break;
  case(50):
      strip.setPixelColor(17,0);
      strip.setPixelColor(21,0);
      strip.show();
      break;
  case(51):
      strip.setPixelColor(6,0);
      strip.setPixelColor(30,0);
      strip.show();
      break;
  case(52):
      strip.setPixelColor(11,0);
      strip.setPixelColor(32,0);
      strip.show();
      break;
  case(53):
      strip.setPixelColor(8,0);
      strip.setPixelColor(27,0);
      strip.show();
      break;
  case(54):
      strip.setPixelColor(79,0);
      strip.setPixelColor(45,0);
      strip.show();
      break;
  case(55):
      strip.setPixelColor(41,0);
      strip.setPixelColor(75,0);
      strip.show();
      break;
   case(56):
      strip.setPixelColor(44,0);
      strip.setPixelColor(77,0);
      strip.show();
      break;
   case(57):
      strip.setPixelColor(40,0);
      strip.setPixelColor(74,0);
      strip.show();
      break;
  case(58):
      strip.setPixelColor(78,0);
      strip.setPixelColor(46,0);
      strip.show();
      break;
  case(59):
      strip.setPixelColor(76,0);
      strip.setPixelColor(47,0);
      strip.show();
      break;
  case(60):
      strip.setPixelColor(43,0);
      strip.setPixelColor(73,0);
      strip.show();
      break;
  case(61):
      strip.setPixelColor(48,0);
      strip.setPixelColor(70,0);
      strip.show();
      break;
  case(62):
      strip.setPixelColor(49,0);
      strip.setPixelColor(72,0);
      strip.show();
      break;
  case(63):
      strip.setPixelColor(52,0);
      strip.setPixelColor(71,0);
      strip.show();
      break;
  case(64):
      strip.setPixelColor(50,0);
      strip.setPixelColor(68,0);
      strip.show();
      break;
  case(65):
      strip.setPixelColor(53,0);
      strip.setPixelColor(69,0);
      strip.show();
      break;
  case(66):
      strip.setPixelColor(51,0);
      strip.setPixelColor(63,0);
      strip.show();
      break;
  case(67):
      strip.setPixelColor(67,0);
      strip.setPixelColor(57,0);
      strip.show();
      break;
  case(68):
      strip.setPixelColor(59,0);
      strip.setPixelColor(65,0);
      strip.show();
      break;
  case(69):
      strip.setPixelColor(58,0);
      strip.setPixelColor(64,0);
      strip.show();
      break;
  case(70):
      strip.setPixelColor(55,0);
      strip.setPixelColor(62,0);
      strip.show();
      break;
  case(71):
      strip.setPixelColor(54,0);
      strip.setPixelColor(61,0);
      strip.show();
      break;
  case(72):
      strip.setPixelColor(56,0);
      strip.setPixelColor(60,0);
      strip.show();
      break;
  case(73):
      strip.setPixelColor(51,0);
      strip.setPixelColor(71,0);
      strip.show();
      break;
  case(74):
      strip.setPixelColor(46,0);
      strip.setPixelColor(68,0);
      strip.show();
      break;
  case(75):
      strip.setPixelColor(82,0);
      strip.setPixelColor(118,0);
      strip.show();
      break;
  case(76):
      strip.setPixelColor(98,0);
      strip.setPixelColor(110,0);
      strip.show();
      break;
  case(77):
      strip.setPixelColor(95,0);
      strip.setPixelColor(101,0);
      strip.show();
      break;
  case(78):
      strip.setPixelColor(102,0);
      strip.setPixelColor(91,0);
      strip.show();
      break;
  case(79):
      strip.setPixelColor(93,0);
      strip.setPixelColor(103,0);
      strip.show();
      break;
  case(80):
      strip.setPixelColor(94,0);
      strip.setPixelColor(107,0);
      strip.show();
      break;
  case(81):
      strip.setPixelColor(99,0);
      strip.setPixelColor(105,0);
      strip.show();
      break;
  case(82):
      strip.setPixelColor(96,0);
      strip.setPixelColor(100,0);
      strip.show();
      break;
  case(83):
      strip.setPixelColor(97,0);
      strip.setPixelColor(106,0);
      strip.show();
      break;
  case(84):
      strip.setPixelColor(90,0);
      strip.setPixelColor(104,0);
      strip.show();
      break;
  case(85):
      strip.setPixelColor(92,0);
      strip.setPixelColor(111,0);
      strip.show();
      break;
  case(86):
      strip.setPixelColor(86,0);
      strip.setPixelColor(108,0);
      strip.show();
      break;
  case(87):
      strip.setPixelColor(89,0);
      strip.setPixelColor(113,0);
      strip.show();
      break;
  case(88):
      strip.setPixelColor(87,0);
      strip.setPixelColor(109,0);
      strip.show();
      break;
  case(89):
      strip.setPixelColor(88,0);
      strip.setPixelColor(114,0);
      strip.show();
      break;
  case(90):
      strip.setPixelColor(83,0);
      strip.setPixelColor(112,0);
      strip.show();
      break;
  case(91):
      strip.setPixelColor(118,0);
      strip.setPixelColor(83,0);
      strip.show();
      break;
  case(92):
      strip.setPixelColor(80,0);
      strip.setPixelColor(116,0);
      strip.show();
      break;
  case(93):
      strip.setPixelColor(84,0);
      strip.setPixelColor(119,0);
      strip.show();
      break;
  case(94):
      strip.setPixelColor(85,0);
      strip.setPixelColor(117,0);
      strip.show();
      break;
  case(95):
      strip.setPixelColor(81,0);
      strip.setPixelColor(115,0);
      strip.show();
      break;      
          
    }
}
