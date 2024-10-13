import serial  # For serial communication with Arduino
import openpyxl  # For creating and managing Excel files
from datetime import datetime  # For getting the current timestamp
import time

# Set up the serial connection to the Arduino
# Replace 'COM3' with your Arduino's port
arduino_port = 'COM3'  # Arduino's port
baud_rate = 9600  # Ensure this matches the baud rate used in your Arduino sketch
ser = serial.Serial(arduino_port, baud_rate, timeout = 1)
time.sleep(2) # Delay the startup of program

# Simple dictionary as database
student_data = {'43c09e0c': 'Student One',
                '8c534df1': 'Student Two',}
                # 'dcd63a23': 'Student Three'}

# Create a new Excel workbook and add a sheet
workbook = openpyxl.Workbook()
sheet = workbook.active
sheet.title = "Attendance Data"
# Add header row: Timestamp and Name
sheet.append(["Timestamp", "Name"])

# Run an infinite loop to read from the serial port and save to Excel
try:
    while True:
        if ser.in_waiting > 0:  # Check if there is data to read from the serial port
            line = ser.readline().decode('utf-8').strip()  # Read and decode the serial data
            if line:  # If the line is not empty, process it
                # Get the current timestamp
                timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
                
                if line in student_data:
                    line = student_data[line]
                else:
                    line = 'Student Unknown'
                
                # Print the received UID and timestamp to the console
                print(f"Received UID: {line} at {timestamp}")

                # Append the data to the Excel sheet: First column is timestamp, second is UID data
                sheet.append([timestamp, line])

                # Save the workbook after each entry
                workbook.save("Attendance.xlsx")

except KeyboardInterrupt:
    # If the user interrupts the program, save the workbook and close the serial port
    print("Program interrupted. Saving the Excel file and closing the serial port.")
    workbook.save("RFID_Data_Timestamped.xlsx")
    ser.close()
