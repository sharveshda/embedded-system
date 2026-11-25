#include <Wire.h>

const byte LM75_ADDR = 0x48;
const byte PULSE_PIN = 8;
volatile unsigned long pulseCount = 0;

void pulseISR() { pulseCount++; }

float readLM75C() {
  Wire.beginTransmission(LM75_ADDR);
  Wire.write(0x00);                 // temperature register
  if (Wire.endTransmission(false) != 0) return -999.0;
  Wire.requestFrom(LM75_ADDR, (byte)2);
  if (Wire.available() < 2) return -999.0;
  int raw = (Wire.read() << 8) | Wire.read();
  raw >>= 7;                        // LM75 9-bit temperature format
  return raw * 0.5f;
}

void setup() {
  Serial.begin(9600);
  Wire.begin();
  pinMode(PULSE_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(PULSE_PIN), pulseISR, RISING);
  Serial.println("I2C HEALTH MONITOR");
  Serial.println("LM75AD address: 0x48");
}

void loop() {
  noInterrupts();
  unsigned long pulses = pulseCount;
  pulseCount = 0;
  interrupts();

  // Count pulses for a 10-second window; BPM = pulses x 6.
  unsigned long start = millis();
  while (millis() - start < 10000UL) {
    delay(10);
  }
  noInterrupts();
  pulses = pulseCount;
  pulseCount = 0;
  interrupts();

  float tempC = readLM75C();
  Serial.print("Temperature: ");
  if (tempC == -999.0) Serial.println("I2C read error");
  else { Serial.print(tempC, 1); Serial.println(" C"); }
  Serial.print("Pulse count (10 s): "); Serial.println(pulses);
  Serial.print("Pulse rate: "); Serial.print(pulses * 6); Serial.println(" BPM");
}
