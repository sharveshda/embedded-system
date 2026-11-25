EXPERIMENT 05: LPC2148 GPIO Switch Input and LED Output

REQUIRED SOFTWARE / HARDWARE
Keil µVision 4/5 with ARM7TDMI toolchain; LPC2148 board; Flash Magic for programming.

FILES IN THIS FOLDER
- main.c
- expected_software_output.txt : representative expected terminal/Virtual Terminal output.

HOW TO USE
1. Open the source file(s) in the software listed above.
2. Select the correct board/device and communication settings.
3. Build/compile the program.
4. Run it on the board or in the specified simulator.
5. Compare the real output with expected_software_output.txt.

IMPORTANT
The output text is representative, not a captured screenshot or proof of an actual run. Hardware pin polarity, clock settings, library versions and trainer-board wiring may require adjustment.

Example output assumes switches are active-high. If the trainer board uses active-low switches, invert the sampled value: switches = (~IO0PIN >> 16) & 0xFF. Confirm the board pin mapping before wiring.
