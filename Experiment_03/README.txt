EXPERIMENT 03: I2C Health Monitoring: LM75AD Temperature and Pulse

REQUIRED SOFTWARE / HARDWARE
Arduino IDE 2.x; Proteus 8 (Arduino UNO, LM75AD at 0x48, pulse source on D8, Virtual Terminal).

FILES IN THIS FOLDER
- Exp03_I2C_Health.ino
- expected_software_output.txt : representative expected terminal/Virtual Terminal output.

HOW TO USE
1. Open the source file(s) in the software listed above.
2. Select the correct board/device and communication settings.
3. Build/compile the program.
4. Run it on the board or in the specified simulator.
5. Compare the real output with expected_software_output.txt.

IMPORTANT
The output text is representative, not a captured screenshot or proof of an actual run. Hardware pin polarity, clock settings, library versions and trainer-board wiring may require adjustment.

LM75AD temperature register is read over I2C. The practical record expects approximately 72 BPM; 12 pulses in 10 seconds gives 12 x 6 = 72 BPM. In Proteus, provide a pulse train to D8.
