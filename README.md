# Attendance using Arduino RFID

A sample idea on how to make a attendance system with the use of Arduino and RFID module. This sends data through serial connection then by received by a Python script listening on the serial port with the corresponding baud rate.

## Installation

### Python

Install [Python](https://www.python.org/) from its official site then install the [requirements.txt](https://github.com/deyibukayo/arduino-rfid-attendance/blob/main/py/requirements.txt) with [pip](https://pip.pypa.io/en/stable/)
 - ```openpyxl```
 - ```pyserial```

Install [Arduino IDE](https://www.arduino.cc/) and add the libraries found on the [libraries.txt](https://github.com/deyibukayo/arduino-rfid-attendance/blob/main/ino/libraries.txt)
- LiquidCrystal I2C
- MFRC522

## Usage

Open the Arduino [sketch](https://github.com/deyibukayo/arduino-rfid-attendance/blob/main/ino/attendance.ino) inside the ino folder, plug the Arduino board to computer and upload the sketch to the Arduino board.
Then, run the Python [script](https://github.com/deyibukayo/arduino-rfid-attendance/blob/main/py/attendance.py) using Command Prompt with command: ```python attendance.py```. 

Note: Make sure that the command prompt instance is running on the correct or same directory of the Python script. 
