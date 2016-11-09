// Tala HAIDAR
// Gabrielle MARTINEAU
// Whack-a-Light
// Octobre 2016


#include <NewPing.h>

// SENSOR CASE 1
#define TRIGGER_PIN  12  // Pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Pin tied to echo pin on the ultrasonic sensor.

// SENSOR CASE 2
#define TRIGGER_PIN2  8  
#define ECHO_PIN2     9  

// SENSOR CASE 3
#define TRIGGER_PIN3  2 
#define ECHO_PIN3     3  

#define MAX_DISTANCE 150 // Maximum distance (in centimeters).

// ULTRASONIC SENSOR HC-SR04
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);.
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE); 
NewPing sonar3(TRIGGER_PIN3, ECHO_PIN3, MAX_DISTANCE);


#include <Adafruit_NeoPixel.h>

// Pin connected to the NeoPixels
#define PIN            6

// Number of NeoPixels attached to the Arduino
#define NUMPIXELS      60

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

boolean state1 = false;
boolean state2 = false;
boolean state3 = false;

int r;


void setup() {
  Serial.begin(115200);
  pixels.begin(); // This initializes the NeoPixel library.
  pinMode(7,OUTPUT); // Pin for LEDs inside the game box.

}

void loop() {
  digitalWrite(7,HIGH); 


  // CASE 1

  if ( r == 0) {
    for (int i = 8; i < 23; i++) {

      pixels.setPixelColor(i, pixels.Color(34, 4, 63));
      pixels.show(); // This sends the updated pixel color to the hardware.
      delay(0);
    }
  }

  if (sonar3.ping_cm() >= 2 && sonar3.ping_cm() <= 30) {
    state1 = false;

    for (int i = 8; i < 23; i++) {

      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      pixels.show();
      delay(0);
    }
    
    delay(500);
    r = random (0, 3); 
  }


  // CASE 2

  if (r == 1) {
    for (int i = 23; i < 38; i++) {

      pixels.setPixelColor(i, pixels.Color(67, 128, 121));
      pixels.show();
      delay(0);
    }
  }

  if (sonar2.ping_cm() >= 2 && sonar2.ping_cm() <= 30) {
    state2 = false;

    for (int i = 23; i < 38; i++) {

      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      pixels.show();
      delay(0);
    }
    
    delay(500);
    r = random (0, 3);
  }


  // CASE 3

  if (r == 2) {
    for (int i = 38; i < 54; i++) {

      pixels.setPixelColor(i, pixels.Color(134, 17, 124));
      pixels.show(); 
      delay(0);
    }
  }

  if (sonar.ping_cm() >= 2 && sonar.ping_cm() <= 30) {
    state3 = false;

    for (int i = 38; i < 54; i++) {

      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      pixels.show();
      delay(0);
    }
    
    delay(500);
    r = random (0, 3);
  }
}
