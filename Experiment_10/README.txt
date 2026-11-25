EXPERIMENT 10: ESP32 PySerial Automated Test and Scripted Flashing

REQUIRED SOFTWARE / HARDWARE
Arduino IDE 2.x with ESP32 board package; Python 3; pyserial; esptool; serial port COM3 at 115200 baud.

FILES IN THIS FOLDER
- esp32_firmware.ino
- test_esp32.py
- flash_firmware.bat
- requirements.txt
- expected_software_output.txt : representative expected terminal/Virtual Terminal output.

HOW TO USE
1. Open the source file(s) in the software listed above.
2. Select the correct board/device and communication settings.
3. Build/compile the program.
4. Run it on the board or in the specified simulator.
5. Compare the real output with expected_software_output.txt.

IMPORTANT
The output text is representative, not a captured screenshot or proof of an actual run. Hardware pin polarity, clock settings, library versions and trainer-board wiring may require adjustment.

Compile and upload esp32_firmware.ino first. Change PORT in Python if Windows assigns another COM port. Flashing requires the correct board-specific firmware binary; do not run the batch file until firmware.bin exists.
