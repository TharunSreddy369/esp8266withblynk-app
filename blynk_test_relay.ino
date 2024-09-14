#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


#define BLYNK_TEMPLATE_ID "----------"
#define BLYNK_TEMPLATE_NAME "---------"
#define BLYNK_AUTH_TOKEN "--------------------"

char auth[] = "------------------------";

// Your WiFi credentials
char ssid[] = "xxxxxxxxx"; //  your Wifi name
char pass[] = "xxxxxxxxxx"; // your Wifi passward

// GPIO pin connected to the relay
#define RELAY_PIN 5  // GPIO5 (D1 on NodeMCU)

void setup()
{
  // Debug console
  Serial.begin(115200);

  // Set the relay pin as output
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Set relay to off initially

  // Connect to Blynk
  Blynk.begin(auth, ssid, pass);
}

BLYNK_WRITE(V1)  // Virtual Pin V1 in the Blynk App
{
  int pinValue = param.asInt(); // Get the value sent from the app

  if(pinValue == 1) {
    digitalWrite(RELAY_PIN, LOW); // Turn relay on (LED on)
  } else {
    digitalWrite(RELAY_PIN, HIGH); // Turn relay off (LED off)
  }
}

void loop()
{
  Blynk.run(); // Run the Blynk process
}
