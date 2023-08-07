#include <NewPing.h>
#include <LiquidCrystal_I2C.h>
#define TRIGGER_PIN 11 // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN 10 // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 20 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int pin_relay=12; 

void setup() {
Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
lcd.begin();
pinMode(pin_relay,OUTPUT);
lcd.setCursor(1,0); 
lcd.print("Selamat Datang");
lcd.setCursor(1,0); 
lcd.print("Adnan M Nur    ");
delay(5000);
lcd.clear();
}

void loop() {
delay(50); // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  int cm = sonar.ping_cm(); // Send out the ping, get the results in centimeters.
lcd.setCursor(0,0); 
lcd.print("Tinggi Air: ");
if(cm<10){
lcd.setCursor(12,0); 
lcd.print("0");
lcd.setCursor(13,0);
lcd.print(cm); 
}

if(cm>=10){
lcd.setCursor(12,0);
lcd.print(cm); 
}
lcd.setCursor(14,0); 
lcd.print("cm");

if(cm>=13) {
  digitalWrite(pin_relay,LOW);
}
if(cm<=1) {
  digitalWrite(pin_relay,HIGH);
}


}
