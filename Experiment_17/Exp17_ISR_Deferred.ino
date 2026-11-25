const int INTERRUPT_PIN = 4;
TaskHandle_t deferredTaskHandle = NULL;

void IRAM_ATTR inputISR() {
  BaseType_t higherPriorityTaskWoken = pdFALSE;
  vTaskNotifyGiveFromISR(deferredTaskHandle, &higherPriorityTaskWoken);
  if (higherPriorityTaskWoken) portYIELD_FROM_ISR();
}

void deferredTask(void *p) {
  for (;;) {
    ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
    // Longer processing is performed in task context, not inside the ISR.
    Serial.println("Deferred task: interrupt event processed");
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(INTERRUPT_PIN, INPUT_PULLUP);
  xTaskCreate(deferredTask, "DeferredTask", 3072, NULL, 3, &deferredTaskHandle);
  attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), inputISR, FALLING);
  Serial.println("ISR attached to GPIO 4; press button to GND");
}
void loop() {
  delay(1000);
}
