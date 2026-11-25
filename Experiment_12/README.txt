EXPERIMENT 12: PySerial Command/Response Automation and Firmware Flashing

REQUIRED SOFTWARE / HARDWARE
Python 3; pyserial; esptool; Arduino IDE 2.x with ESP32 board package; serial terminal.

FILES IN THIS FOLDER
- esp32_firmware.ino
- serial_test.py
- flash.bat
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

Upload the firmware before running the Python test. For flashing, replace firmware.bin with the binary generated for your exact ESP32 board and use the appropriate bootloader/partition/application offsets if flashing all images.
