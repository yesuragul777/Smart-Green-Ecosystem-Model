/*
  Smart Green Ecosystem – Composting System
  Author: Yesu Ragul
  Reg No: 24MCB0042
  Description: Automates drying and grinding of kitchen waste using sensors and relays
*/

#include <DHT.h>

#define DHTPIN 2            // Pin where DHT11 is connected
#define DHTTYPE DHT11
#define TRIG_PIN 3          // Ultrasonic sensor TRIG
#define ECHO_PIN 4          // Ultrasonic sensor ECHO

#define RELAY_FAN 5         // Relay for cooling/drying fan
#define RELAY_GRINDER 6     // Relay for grinder
#define RELAY_EXTRA 7       // Relay for extra mechanism (optional)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(RELAY_FAN, OUTPUT);
  pinMode(RELAY_GRINDER, OUTPUT);
  pinMode(RELAY_EXTRA, OUTPUT);

  digitalWrite(RELAY_FAN, LOW);
  digitalWrite(RELAY_GRINDER, LOW);
  digitalWrite(RELAY_EXTRA, LOW);
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  long duration;
  float distance;

  // Read distance from ultrasonic sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2; // in cm

  Serial.print("Temp: "); Serial.print(temperature);
  Serial.print(" C, Humidity: "); Serial.print(humidity);
  Serial.print(" %, Distance: "); Serial.print(distance); Serial.println(" cm");

  // Logic for drying (fan control)
  if (humidity > 70) {
    digitalWrite(RELAY_FAN, HIGH);  // Fan ON
  } else {
    digitalWrite(RELAY_FAN, LOW);   // Fan OFF
  }

  // Logic for grinding (only when waste is low moisture and bin not full)
  if (humidity < 50 && distance > 10 && distance < 30) {
    digitalWrite(RELAY_GRINDER, HIGH); // Grinder ON
    delay(5000); // Run grinder for 5 sec
    digitalWrite(RELAY_GRINDER, LOW);
  }

  delay(2000); // Delay before next reading
}
