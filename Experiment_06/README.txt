EXPERIMENT 06: LPC2148 Modular Seven-Segment Display Driver

REQUIRED SOFTWARE / HARDWARE
Keil µVision 4/5; LPC2148 trainer board with seven-segment display; Flash Magic.

FILES IN THIS FOLDER
- sevenseg.h
- sevenseg.c
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

Segment codes follow the practical record (0x3F for 0, 0x06 for 1, 0x67 for 9). The exact DS4 polarity and segment wiring are trainer-board-specific; verify the kit schematic. The P0.16-P0.23 pin-mux register selection should be checked against the LPC2148 board schematic.
