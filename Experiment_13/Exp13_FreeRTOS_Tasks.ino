void lowTask(void *p) {
  for (;;) {
    Serial.println("Low priority task running");
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}
void highTask(void *p) {
  for (;;) {
    Serial.println("High priority task running");
    vTaskDelay(pdMS_TO_TICKS(500));
  }
}
void setup() {
  Serial.begin(115200);
  delay(1000);
  xTaskCreate(lowTask, "LowTask", 2048, NULL, 1, NULL);
  xTaskCreate(highTask, "HighTask", 2048, NULL, 2, NULL);
  Serial.println("Tasks created: LowTask priority 1, HighTask priority 2");
}
void loop() { vTaskDelay(portMAX_DELAY); }
