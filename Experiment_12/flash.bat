@echo off
REM Use the correct firmware binary and flash address for your ESP32 build.
python -m esptool --chip esp32 --port COM3 --baud 460800 write_flash -z 0x1000 firmware.bin
pause
