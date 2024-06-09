Aim
To develop an Android application that uses fingerprint authentication to securely control an LED and a buzzer connected to an Arduino via Bluetooth.

Components Needed
Arduino Uno or compatible board
Bluetooth module (e.g., HC-05 or HC-06)
LED
Buzzer
Resistors (220Ω for the LED)
Breadboard and jumper wires
Android smartphone
MIT App Inventor for app development
Circuit Diagram
Here's the connection diagram:

LED to Arduino:

Connect the anode (long leg) of the LED to Digital Pin 10 via a 220Ω resistor
Connect the cathode (short leg) of the LED to GND
Buzzer to Arduino:

Connect the positive pin of the buzzer to Digital Pin 11
Connect the negative pin of the buzzer to GND
Bluetooth Module to Arduino:

VCC to 5V on Arduino
GND to GND on Arduino
TXD to Digital Pin 9 (Arduino RX)
RXD to Digital Pin 8 (Arduino TX)
Arduino Code
cpp
Copy code
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
Steps to Create the Android App Using MIT App Inventor
1. Set Up MIT App Inventor
Open MIT App Inventor: Go to MIT App Inventor and log in with your Google account.
Start a New Project: Click on "Projects" and then "Start new project". Name your project (e.g., "FingerprintControlApp").
2. Design the Interface
Add a ListPicker for Bluetooth Device Selection:

From the "User Interface" palette, drag a ListPicker onto the viewer. Rename it to ListPicker1 and set its Text to "Select Bluetooth Device".
Add Buttons for Controlling the LED and Buzzer:

Drag two Button components onto the viewer. Rename them to ButtonOn and ButtonOff.
Set the Text property of ButtonOn to "Turn On" and ButtonOff to "Turn Off".
Add a Label for Status Display:

Drag a Label component onto the viewer. Rename it to LabelStatus and set its Text to "Status: Not Connected".
Add Bluetooth Client:

From the "Connectivity" palette, drag a BluetoothClient onto the viewer. It will appear under "Non-visible components".
Add Fingerprint Authentication Extension:

Download the Taifun Fingerprint Extension and upload it to your project.
From the "Extensions" palette, drag the Fingerprint component onto the viewer. It will also appear under "Non-visible components".
3. Configure the Blocks
Initialize Bluetooth Connection:
Go to the "Blocks" tab.
Add the following blocks to handle the Bluetooth connection:
text
Copy code
When ListPicker1.BeforePicking:
    Call ListPicker1.Elements to BluetoothClient1.AddressesAndNames

When ListPicker1.AfterPicking:
    Call BluetoothClient1.Connect Address ListPicker1.Selection
    If BluetoothClient1.IsConnected:
        Set LabelStatus.Text to "Connected to " + ListPicker1.Selection
    Else:
        Set LabelStatus.Text to "Connection Failed"
Fingerprint Authentication and Send Commands:
text
Copy code
When ButtonOn.Click:
    Call Fingerprint1.StartAuthentication

When Fingerprint1.GotAuthenticated(success):
    If success:
        Call BluetoothClient1.SendText "1"
        Set LabelStatus.Text to "LED and Buzzer ON"
    Else:
        Set LabelStatus.Text to "Authentication Failed"

When ButtonOff.Click:
    Call Fingerprint1.StartAuthentication

When Fingerprint1.GotAuthenticated(success):
    If success:
        Call BluetoothClient1.SendText "0"
        Set LabelStatus.Text to "LED and Buzzer OFF"
    Else:
        Set LabelStatus.Text to "Authentication Failed"
Final Steps
Upload Arduino Code: Ensure the Arduino code provided is uploaded to your Arduino board.
Assemble Circuit: Connect the components as per the provided circuit diagram.
Pair Bluetooth Module: Pair the Bluetooth module with your Android device.
Test the App: Use the MIT AI2 Companion app on your Android device to test your app.
Conclusion
By following these steps, you will create an Android application that uses fingerprint authentication to securely control an LED and a buzzer connected to an Arduino via Bluetooth. This ensures that only authenticated users can control the devices.
