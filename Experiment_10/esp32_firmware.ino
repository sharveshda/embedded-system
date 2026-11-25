void setup() {
  Serial.begin(115200);
  Serial.println("ESP32 TEST FIRMWARE READY");
}
void loop() {
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\\n');
    cmd.trim();
    if (cmd == "TEST_SIGNAL") Serial.println("TEST_SIGNAL_OK");
    else Serial.println("UNKNOWN_COMMAND");
  }
}
