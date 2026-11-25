EXPERIMENT 17: FreeRTOS ISR Deferred Processing and Interrupt Notification

REQUIRED SOFTWARE / HARDWARE
Arduino IDE 2.x; ESP32 board package; FreeRTOS task notification and GPIO interrupt APIs; Serial Monitor 115200.

FILES IN THIS FOLDER
- Exp17_ISR_Deferred.ino
- expected_software_output.txt : representative expected terminal/Virtual Terminal output.

HOW TO USE
1. Open the source file(s) in the software listed above.
2. Select the correct board/device and communication settings.
3. Build/compile the program.
4. Run it on the board or in the specified simulator.
5. Compare the real output with expected_software_output.txt.

IMPORTANT
The output text is representative, not a captured screenshot or proof of an actual run. Hardware pin polarity, clock settings, library versions and trainer-board wiring may require adjustment.

Connect a normally-open pushbutton between GPIO4 and GND. The ISR only notifies the task; deferred work and serial output happen in task context. ESP32 interrupt pin and IRAM/FreeRTOS API constraints can vary by board-core version.
