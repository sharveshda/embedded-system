@echo off
REM Replace firmware.bin with the compiled ESP32 binary path.
python -m esptool --chip esp32 --port COM3 --baud 460800 write_flash -z 0x1000 firmware.bin
pause
