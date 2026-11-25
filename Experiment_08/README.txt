EXPERIMENT 08: SystemC SC_THREAD and Clock-Edge Simulation

REQUIRED SOFTWARE / HARDWARE
Ubuntu on WSL/Linux; g++; SystemC development package (libsystemc-dev).

FILES IN THIS FOLDER
- exp08_clock_thread.cpp
- build.sh
- expected_software_output.txt : representative expected terminal/Virtual Terminal output.

HOW TO USE
1. Open the source file(s) in the software listed above.
2. Select the correct board/device and communication settings.
3. Build/compile the program.
4. Run it on the board or in the specified simulator.
5. Compare the real output with expected_software_output.txt.

IMPORTANT
The output text is representative, not a captured screenshot or proof of an actual run. Hardware pin polarity, clock settings, library versions and trainer-board wiring may require adjustment.

The source practical record specifies final simulation time 5 ns but does not state the clock period. This sample explicitly assumes a 1 ns clock period to show five positive edges.
