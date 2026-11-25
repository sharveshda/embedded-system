const byte NS_RED = 2, NS_YELLOW = 3, NS_GREEN = 4;
const byte EW_RED = 5, EW_YELLOW = 6, EW_GREEN = 7;

void showState(const char *name, byte a, byte b, byte c,
               byte d, byte e, byte f, unsigned long durationMs) {
  digitalWrite(NS_RED, a); digitalWrite(NS_YELLOW, b); digitalWrite(NS_GREEN, c);
  digitalWrite(EW_RED, d); digitalWrite(EW_YELLOW, e); digitalWrite(EW_GREEN, f);
  Serial.print("STATE "); Serial.print(name);
  Serial.print(" | duration = "); Serial.print(durationMs / 1000);
  Serial.println(" s");
  delay(durationMs);
}

void setup() {
  for (byte p = 2; p <= 7; p++) pinMode(p, OUTPUT);
  Serial.begin(9600);
  Serial.println("FOUR STATE TRAFFIC LIGHT FSM");
}

void loop() {
  // S0: North-South green, East-West red
  showState("S0: NS GREEN / EW RED", LOW, LOW, HIGH, HIGH, LOW, LOW, 10000);
  // S1: North-South yellow, East-West red
  showState("S1: NS YELLOW / EW RED", LOW, HIGH, LOW, HIGH, LOW, LOW, 3000);
  // S2: North-South red, East-West green
  showState("S2: NS RED / EW GREEN", HIGH, LOW, LOW, LOW, LOW, HIGH, 10000);
  // S3: North-South red, East-West yellow
  showState("S3: NS RED / EW YELLOW", HIGH, LOW, LOW, LOW, HIGH, LOW, 3000);
}
