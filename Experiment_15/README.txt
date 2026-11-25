EXPERIMENT 15: FreeRTOS Queues, Mailbox and Stream Buffer Producer-Consumer

REQUIRED SOFTWARE / HARDWARE
Arduino IDE 2.x; ESP32 board package; FreeRTOS queue and stream-buffer APIs; Serial Monitor 115200.

FILES IN THIS FOLDER
- Exp15_Queues_StreamBuffer.ino
- expected_software_output.txt : representative expected terminal/Virtual Terminal output.

HOW TO USE
1. Open the source file(s) in the software listed above.
2. Select the correct board/device and communication settings.
3. Build/compile the program.
4. Run it on the board or in the specified simulator.
5. Compare the real output with expected_software_output.txt.

IMPORTANT
The output text is representative, not a captured screenshot or proof of an actual run. Hardware pin polarity, clock settings, library versions and trainer-board wiring may require adjustment.

The mailbox is implemented as a queue of length one and xQueueOverwrite keeps the latest value. The stream buffer carries the byte sequence including the terminating null character.
