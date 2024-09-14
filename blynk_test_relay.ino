#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

/*#define BLYNK_TEMPLATE_ID "TMPL3Dr93qE8M"
#define BLYNK_TEMPLATE_NAME "led controll"
#define BLYNK_AUTH_TOKEN "XqXgnT9bgFRf0Fe646biPujbWlZDIg-2"*/ 

#define BLYNK_TEMPLATE_ID "TMPL3eAPkAUJx"
#define BLYNK_TEMPLATE_NAME "home automation"
#define BLYNK_AUTH_TOKEN "5JLTEPDzc9KLriJbFqYcpvkGh-I_xz5_"

char auth[] = "5JLTEPDzc9KLriJbFqYcpvkGh-I_xz5_";

// Your WiFi credentials
char ssid[] = "Abcd";
char pass[] = "12345678";

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
