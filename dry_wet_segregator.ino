#include <Servo.h>

Servo servo1;

const int trigPin = 12;
const int echoPin = 11;
const int irSensorPin = 9;      // Pin for IR sensor input

const int potPin = A0;           // Input pin for soil moisture sensor


long duration;
int distance = 0;
int soil = 0;
int fsoil = 0;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(irSensorPin, INPUT); 
  pinMode(irSensorLEDPin, OUTPUT); 
  pinMode(potPin, INPUT); 
  pinMode(ledPin, OUTPUT); 
  servo1.attach(8);
}

void loop() {
  // Read the output from the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // Read the output from the IR sensor
  int irSensorState = digitalRead(irSensorPin);

  // Control the IR sensor LED based on its state
  digitalWrite(irSensorLEDPin, irSensorState);

  // If both ultrasonic and IR sensors detect an object
  if (distance < 15 && distance > 1 && irSensorState == HIGH) {
    delay(1000); 

    // Read soil moisture sensor
    for (int i = 0; i < 3; i++) {
      soil = analogRead(potPin);
      soil = constrain(soil, 485, 1023);
      fsoil = map(soil, 485, 1023, 100, 0) + fsoil;
      delay(75);
    }
    fsoil = fsoil / 3;

    // Print soil moisture reading
    Serial.print("Soil Moisture: ");
    Serial.print(fsoil);
    Serial.println("%");

    // Perform actions based on soil moisture level
    if (fsoil > 3) {
      Serial.println("WET");
      servo1.write(180); // Move servo motor to water the plant
      delay(3000);
    } else {
      Serial.println("DRY");
      servo1.write(0); // Move servo motor to stop watering
      delay(3000);
    }
    servo1.write(90); // Return servo motor to neutral position
  }
}
