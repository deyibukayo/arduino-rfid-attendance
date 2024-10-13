#include <SPI.h>
#include <MFRC522.h> // MFRC522 by GithubCommunity v1.4.11
#include <Wire.h>
#include <LiquidCrystal_I2C.h> // LiquidCrystal I2C by Frank de Brabander v1.1.2

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN); // RFID Object
// LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD I2C Object

String uidString = ""; // Global var for RFID UID value

void setup() {
  // Start serial at 9600 baud rate
  Serial.begin(9600);
  SPI.begin();

  // Initialize MFRC Sensor
  mfrc522.PCD_Init();
  Serial.println("Place your RFID tag on the reader...");

  // Initialize the LCD
  // lcd.init();
  // lcd.backlight();
  // lcd.clear();
  // lcd.setCursor(0, 0);
}

void loop() {
  // Check if data is available to read from the serial port
  // if (Serial.available() > 0) {
  //   String receivedData = Serial.readStringUntil('\n');  // Read the incoming data until a newline character
  //   lcd.clear();
  //   lcd.setCursor(0, 0);
  //   lcd.print("Hello!");
  //   lcd.setCursor(0, 1);
  //   lcd.print(receivedData);  // Print the received data back to the Serial Monitor
  // }

  if (!mfrc522.PICC_IsNewCardPresent()) { return; } // Check for card
  if (!mfrc522.PICC_ReadCardSerial()) { return; } // Read card if found

  // Save the RFID UID and print
  uidString = "";  // Clear previous UID
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    // Append each byte of the UID in hexadecimal format
    if (mfrc522.uid.uidByte[i] < 0x10) {
      uidString += "0";  // Add leading zero for single-digit hex values
    }
    uidString += String(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println(uidString); // Print to serial
  mfrc522.PICC_HaltA(); // Stops the sensor from reading further
}
