/*===========================================================
 * Single LED control for Ghost Mix Case.
 * Cycle through colors on LED unless Muted...then
 * Flash Red.
 */
 
#if defined(__AVR_ATmega328P__)
//#define PLATFORM_UNO
#elif defined(__AVR_ATtiny85__)
#define PLATFORM_TINY
#else
#error "PLATFORM UNSUPPORTED"
#endif
#include <Adafruit_NeoPixel.h>

// Which pin to use for DualRingLED control
#ifdef PLATFORM_TINY
#define LED_PIN    4 // tiny pin 3 = D4
#define MUTE_PIN   0  // tiny pin 6 = D0
#else
#define LED_PIN    5
#define MUTE_PIN   4
#endif

#define NUMPIXELS  1



Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LED_PIN, NEO_GRB+NEO_KHZ800);

#define COLOR_RED     0xFF0000
#define COLOR_GREEN   0x00FF00
#define COLOR_BLUE    0x0000FF
#define COLOR_MAGENTA 0xFF00FF
#define COLOR_YELLOW  0xFFFF00
#define COLOR_CYAN    0x00FFFF
#define COLOR_BLACK   0
#define COLOR_WHITE   0xFFFFFF

// GLENN:  should these be uint8_ts?
int red=0;
int blue=0xff;
int green=0;

int tick_number=0;

void setup()
{

    #ifdef PLATFORM_UNO
    Serial.begin(9600);
    Serial.println("Inited");
    #endif

    pinMode(MUTE_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    
    pixels.begin();

    pixels.setPixelColor(0,COLOR_BLUE);
    pixels.show();
}

#define COLOR_DELAY_US 10000
void cycle_colors(int tick_number)
{ 
  // Function gets called every 10 ms, with a tick index.
  // Ticks 0 to 255 go from blue to green.
  // Then we pause for 1 second (100 more ticks...256 to 356)
  // Then 357 to 612 we go from green to red.
  // Then we pause for 1 second (100 more ticks...613 to 713)
  // Then 714 to 969 we go red to blue.
  // Then 970 to 1070 we pause.

  // reset
  if (tick_number == 0)
  {
    #ifdef PLATFORM_UNO
    Serial.println("RESET");
    #endif
    
    green = 0;
    blue = 0xff;
    red = 0;
  }
  // step 1:  blue to green
  if ((tick_number > 0) && (tick_number < 256))
  {
    green++;
    blue--;
    pixels.setPixelColor(0, red, green, blue);
    pixels.show();

    #ifdef PLATFORM_UNO
    Serial.print("b-g: ");
    Serial.print(red); Serial.print(" "); 
    Serial.print(green); 
    Serial.print(" "); 
    Serial.println(blue);
    #endif
  }

  // step 2:  green to red.
  if ((tick_number > 356) && (tick_number < 612))
  {
    green--;
    red++;
    pixels.setPixelColor(0, red, green, blue);
    pixels.show();

    #ifdef PLATFORM_UNO
    Serial.print("g-r: ");
    Serial.print(red); Serial.print(" "); 
    Serial.print(green); 
    Serial.print(" "); 
    Serial.println(blue);
    #endif
    
  }

  // step 3:  red back to blue
  if ((tick_number > 713) && (tick_number < 969))
  {
    blue++;
    red--;
    pixels.setPixelColor(0, red, green, blue);
    pixels.show();

    #ifdef PLATFORM_UNO
    Serial.print("r-b: ");
    Serial.print(red); Serial.print(" "); 
    Serial.print(green); 
    Serial.print(" "); 
    Serial.println(blue);
    #endif
  }

  // any other tick number, we don't do anything.
}

void flash_red(int tick_number)
{
  int tick_mod;

  tick_mod = tick_number % 200;
  if (tick_mod < 100)
  {
     pixels.setPixelColor(0, 0, 0, 0);
  }
  else
  {
    pixels.setPixelColor(0,255,0,0);
  }
  pixels.show();
}

void loop(void)
{ 
  static int last_mute=HIGH;
  int        curr_mute;

  curr_mute = digitalRead(MUTE_PIN);
  
  if (curr_mute == HIGH)
  {
    flash_red(tick_number);
    tick_number++;
    if (tick_number > 400) tick_number == 400;
  }
  else
  {  
    if (last_mute == HIGH)
    {
      // Just turned off the mute.  Reset our eye vars
      last_mute = LOW;
      tick_number = 0;
      red = 0;
      green = 0;
      blue = 0xFF;
    }
    cycle_colors(tick_number);
    tick_number++;
    if (tick_number > 1070) tick_number = 0;
  }

  delay(5);
}
