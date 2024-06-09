#include <SoftwareSerial.h>

SoftwareSerial btSerial(8, 9); // RX, TX

const int ledPin = 10;
const int buzzerPin = 11;

void setup() {
  Serial.begin(9600);
  btSerial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);
}

void loop() {
  if (btSerial.available()) {
    char command = btSerial.read();
    if (command == '1') { // Command to turn on the LED and Buzzer
      digitalWrite(ledPin, HIGH);
      digitalWrite(buzzerPin, HIGH);
      Serial.println("LED and Buzzer ON");
    } else if (command == '0') { // Command to turn off the LED and Buzzer
      digitalWrite(ledPin, LOW);
      digitalWrite(buzzerPin, LOW);
      Serial.println("LED and Buzzer OFF");
    }
  }
}
