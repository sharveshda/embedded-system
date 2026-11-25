EXPERIMENT 04: LM35 HVAC Control with Timer-Interrupt Software PWM

REQUIRED SOFTWARE / HARDWARE
Arduino IDE 2.x; Proteus 8 (Arduino UNO, LM35 on A0, fan/LED load through transistor, Virtual Terminal).

FILES IN THIS FOLDER
- Exp04_HVAC_TimerPWM.ino
- expected_software_output.txt : representative expected terminal/Virtual Terminal output.

HOW TO USE
1. Open the source file(s) in the software listed above.
2. Select the correct board/device and communication settings.
3. Build/compile the program.
4. Run it on the board or in the specified simulator.
5. Compare the real output with expected_software_output.txt.

IMPORTANT
The output text is representative, not a captured screenshot or proof of an actual run. Hardware pin polarity, clock settings, library versions and trainer-board wiring may require adjustment.

Timer1 is used by this sketch; do not combine it with libraries that also require Timer1. Connect the fan through a suitable transistor/MOSFET and flyback diode, not directly to the Arduino pin.
