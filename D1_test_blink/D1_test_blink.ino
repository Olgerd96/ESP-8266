//#include <ESP8266WiFi.h>
//#include <ESP8266WiFiAP.h>
//#include <ESP8266WiFiGeneric.h>
//#include <ESP8266WiFiMulti.h>
//#include <ESP8266WiFiScan.h>
//#include <ESP8266WiFiSTA.h>
//#include <ESP8266WiFiType.h>
//#include <WiFiClient.h>
//#include <WiFiClientSecure.h>
//#include <WiFiServer.h>
//#include <WiFiUdp.h>

int blinkdelay = 1;

/*
 ESP8266 Blink by Simon Peter
 Blink the blue LED on the ESP-01 module
 This example code is in the public domain
 
 The blue LED on the ESP-01 module is connected to GPIO1 
 (which is also the TXD pin; so we cannot use Serial.print() at the same time)
 
 Note that this sketch uses LED_BUILTIN to find the pin with the internal LED
*/

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
                                    // but actually the LED is on; this is because 
                                    // it is acive low on the ESP-01)
  Serial.begin(115200);
  
  delay(blinkdelay);                      // Wait for a second
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(150);
  digitalWrite(LED_BUILTIN, LOW);
  delay(blinkdelay);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(150);
  digitalWrite(LED_BUILTIN, LOW);
  delay(blinkdelay);
  digitalWrite(LED_BUILTIN, HIGH);
  //SerString = 
  Serial.println("Blink " + String(blinkdelay) + " ms.");
  // Вариант 1: увеличиваю время включеного состояния
  //blinkdelay+=1;
  //if (blinkdelay=99)  blinkdelay = 1; 
  
  // Вариант 2: случайне время включенного состояния
  blinkdelay = random(10);
  
  delay(2000);                      // Wait for two seconds (to demonstrate the active low LED)
}
