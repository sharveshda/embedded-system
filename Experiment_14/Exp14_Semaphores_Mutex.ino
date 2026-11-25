SemaphoreHandle_t binarySem, countingSem, dataMutex;
int sharedCounter = 0;

void eventProducer(void *p) {
  for (;;) {
    vTaskDelay(pdMS_TO_TICKS(1000));
    xSemaphoreGive(binarySem);
    Serial.println("Producer: binary semaphore given");
  }
}
void eventConsumer(void *p) {
  for (;;) {
    if (xSemaphoreTake(binarySem, portMAX_DELAY) == pdTRUE)
      Serial.println("Consumer: binary semaphore taken");
  }
}
void resourceTask(void *p) {
  const char *name = (const char*)p;
  for (;;) {
    if (xSemaphoreTake(countingSem, portMAX_DELAY) == pdTRUE) {
      Serial.printf("%s acquired one of 3 resources\\n", name);
      vTaskDelay(pdMS_TO_TICKS(300));
      xSemaphoreGive(countingSem);
    }
    vTaskDelay(pdMS_TO_TICKS(200));
  }
}
void counterTask(void *p) {
  const char *name = (const char*)p;
  for (;;) {
    if (xSemaphoreTake(dataMutex, portMAX_DELAY) == pdTRUE) {
      sharedCounter++;
      Serial.printf("%s updated sharedCounter=%d\\n", name, sharedCounter);
      xSemaphoreGive(dataMutex);
    }
    vTaskDelay(pdMS_TO_TICKS(700));
  }
}
void setup() {
  Serial.begin(115200);
  binarySem = xSemaphoreCreateBinary();
  countingSem = xSemaphoreCreateCounting(3, 3);
  dataMutex = xSemaphoreCreateMutex();
  xTaskCreate(eventProducer, "Producer", 2048, NULL, 2, NULL);
  xTaskCreate(eventConsumer, "Consumer", 2048, NULL, 2, NULL);
  xTaskCreate(resourceTask, "ResourceA", 2048, (void*)"TaskA", 1, NULL);
  xTaskCreate(counterTask, "CounterA", 2048, (void*)"TaskA", 1, NULL);
  xTaskCreate(counterTask, "CounterB", 2048, (void*)"TaskB", 1, NULL);
  Serial.println("Binary semaphore, counting semaphore (max 3), mutex created");
}
void loop() { vTaskDelay(portMAX_DELAY); }
