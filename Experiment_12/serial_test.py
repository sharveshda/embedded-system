import time
import serial

PORT = "COM3"       # change to the detected port
BAUD = 115200
COMMAND = "PING"
EXPECTED = "PONG"
CYCLES = 5

passed = failed = 0
with serial.Serial(PORT, BAUD, timeout=2) as ser:
    time.sleep(2)
    ser.reset_input_buffer()
    print("Serial port opened:", PORT)
    print("Baud rate:", BAUD)
    for i in range(1, CYCLES + 1):
        ser.write((COMMAND + "\\n").encode())
        reply = ser.readline().decode(errors="replace").strip()
        ok = (reply == EXPECTED)
        passed += ok
        failed += not ok
        print(f"Cycle {i}: TX={COMMAND}, RX={reply or 'NO RESPONSE'} -> {'PASS' if ok else 'FAIL'}")

print("PASS count:", passed)
print("FAIL count:", failed)
