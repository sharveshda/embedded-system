EXPERIMENT 01: Arduino UNO Smart Home Safety and Occupancy Monitoring

REQUIRED SOFTWARE / HARDWARE
Arduino IDE 2.x; Proteus 8 (Arduino UNO, gas sensor model, PIR, HC-SR04, LED, buzzer, Virtual Terminal).

FILES IN THIS FOLDER
- Exp01_Smart_Home.ino
- expected_software_output.txt : representative expected terminal/Virtual Terminal output.

HOW TO USE
1. Open the source file(s) in the software listed above.
2. Select the correct board/device and communication settings.
3. Build/compile the program.
4. Run it on the board or in the specified simulator.
5. Compare the real output with expected_software_output.txt.

IMPORTANT
The output text is representative, not a captured screenshot or proof of an actual run. Hardware pin polarity, clock settings, library versions and trainer-board wiring may require adjustment.

Connect the gas sensor analog output to A0. The gas sensor model may need calibration; 500 is the threshold specified in the practical record. Use a transistor driver if the buzzer current exceeds the Arduino pin rating.
