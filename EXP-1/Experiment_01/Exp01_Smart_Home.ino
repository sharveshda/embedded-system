const int GAS_PIN = A0;
const int PIR_PIN = 2;
const int TRIG_PIN = 3;
const int ECHO_PIN = 4;
const int LED_PIN = 5;
const int BUZZER_PIN = 6;
const int GAS_LIMIT = 500;

float readDistanceCm() {
  digitalWrite(TRIG_PIN, LOW); delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH); delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  unsigned long us = pulseIn(ECHO_PIN, HIGH, 30000UL);
  if (us == 0) return -1.0;
  return (us * 0.0343f) / 2.0f;
}

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("SMART HOME SAFETY SYSTEM");
}

void loop() {
  int gas = analogRead(GAS_PIN);
  int motion = digitalRead(PIR_PIN);
  float distance = readDistanceCm();
  bool gasAlert = gas > GAS_LIMIT;

  digitalWrite(LED_PIN, motion ? HIGH : LOW);
  digitalWrite(BUZZER_PIN, gasAlert ? HIGH : LOW);

  Serial.print("Gas ADC: "); Serial.println(gas);
  Serial.print("PIR: "); Serial.println(motion ? "DETECTED" : "NOT DETECTED");
  Serial.print("Distance: ");
  if (distance < 0) Serial.println("No echo");
  else { Serial.print(distance, 1); Serial.println(" cm"); }
  if (gasAlert) Serial.println("GAS ALERT - BUZZER ON");
  else Serial.println("SYSTEM SAFE");
  if (motion) Serial.println("OCCUPANCY DETECTED - LED ON");
  Serial.println("--------------------");
  delay(1000);
}
