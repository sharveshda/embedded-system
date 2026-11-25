void setup() {
  Serial.begin(115200);
  Serial.println("BOARD READY");
}
void loop() {
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\\n');
    cmd.trim();
    if (cmd == "PING") Serial.println("PONG");
    else Serial.println("ERROR");
  }
}
