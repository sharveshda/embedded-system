EXPERIMENT 07: LPC2148 UART0 Interrupt-Driven Character Echo

REQUIRED SOFTWARE / HARDWARE
Keil µVision 4/5; LPC2148 board; Flash Magic; serial terminal (PuTTY/Tera Term) at 19200 baud, 8N1.

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

Baud divisor assumes a 60 MHz peripheral clock (VPBDIV=1). If your board uses a different CCLK/PCLK, recalculate the divisor. Ensure the Keil startup file and IRQ vector table are configured for LPC2148.
