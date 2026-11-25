import time
import serial

PORT = "COM3"
BAUD = 115200
TESTS = 5

passed = failed = 0
with serial.Serial(PORT, BAUD, timeout=2) as ser:
    time.sleep(2)                 # allow ESP32 to reset after port opens
    ser.reset_input_buffer()
    print(f"Connected: {PORT} at {BAUD} baud")
    for n in range(1, TESTS + 1):
        ser.write(b"TEST_SIGNAL\\n")
        response = ser.readline().decode(errors="replace").strip()
        ok = response == "TEST_SIGNAL_OK"
        passed += int(ok)
        failed += int(not ok)
        print(f"Test {n}: {response or 'NO RESPONSE'} - {'PASS' if ok else 'FAIL'}")

print(f"PASS: {passed}")
print(f"FAIL: {failed}")
print(f"Success rate: {passed * 100 / TESTS:.0f}%")
