// Timer1 interrupt generates a 10 ms software-PWM period (100 x 100 us).
const byte LM35_PIN = A0;
const byte FAN_PIN = 9;
volatile byte pwmDuty = 0;
volatile byte pwmTick = 0;

ISR(TIMER1_COMPA_vect) {
  pwmTick++;
  if (pwmTick >= 100) pwmTick = 0;
  digitalWrite(FAN_PIN, (pwmTick < pwmDuty) ? HIGH : LOW);
}

void setupTimer1_100us() {
  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  OCR1A = 199;                     // 100 us at 16 MHz / 8
  TCCR1B |= (1 << WGM12) | (1 << CS11);
  TIMSK1 |= (1 << OCIE1A);
  sei();
}

void setup() {
  pinMode(FAN_PIN, OUTPUT);
  Serial.begin(9600);
  setupTimer1_100us();
  Serial.println("HVAC TEMPERATURE CONTROL");
}

void loop() {
  int adc = analogRead(LM35_PIN);
  float voltage = adc * (5.0f / 1023.0f);
  float tempC = voltage * 100.0f;  // LM35: 10 mV per degree C

  if (tempC < 25.0) pwmDuty = 0;
  else if (tempC < 30.0) pwmDuty = 30;
  else if (tempC < 35.0) pwmDuty = 60;
  else pwmDuty = 90;

  Serial.print("Temperature: "); Serial.print(tempC, 1); Serial.print(" C");
  Serial.print(" | PWM Duty: "); Serial.print(pwmDuty); Serial.println("%");
  delay(1000);
}
