EXPERIMENT 13: FreeRTOS Task Creation, States and Priorities

REQUIRED SOFTWARE / HARDWARE
Arduino IDE 2.x; ESP32 board package (FreeRTOS is included in ESP32 Arduino core); Serial Monitor 115200.

FILES IN THIS FOLDER
- Exp13_FreeRTOS_Tasks.ino
- expected_software_output.txt : representative expected terminal/Virtual Terminal output.

HOW TO USE
1. Open the source file(s) in the software listed above.
2. Select the correct board/device and communication settings.
3. Build/compile the program.
4. Run it on the board or in the specified simulator.
5. Compare the real output with expected_software_output.txt.

IMPORTANT
The output text is representative, not a captured screenshot or proof of an actual run. Hardware pin polarity, clock settings, library versions and trainer-board wiring may require adjustment.

ESP32 Arduino core supplies FreeRTOS. Higher-priority tasks are scheduled ahead of lower-priority ready tasks; the delay calls place tasks in the Blocked state. Serial print order can vary slightly with scheduling.
