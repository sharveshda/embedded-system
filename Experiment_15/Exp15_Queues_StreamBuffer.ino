QueueHandle_t dataQueue;
QueueHandle_t mailbox;
StreamBufferHandle_t streamBuf;

void producerTask(void *p) {
  int value = 1;
  const char msg[] = "DATA";
  for (;;) {
    xQueueSend(dataQueue, &value, portMAX_DELAY);
    Serial.printf("Producer queued: %d\\n", value);
    xQueueOverwrite(mailbox, &value);   // mailbox: queue length one
    xStreamBufferSend(streamBuf, msg, sizeof(msg), portMAX_DELAY);
    value++;
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}
void consumerTask(void *p) {
  int value;
  char bytes[16];
  for (;;) {
    if (xQueueReceive(dataQueue, &value, portMAX_DELAY) == pdTRUE)
      Serial.printf("Queue consumer received: %d\\n", value);
    if (xQueuePeek(mailbox, &value, 0) == pdTRUE)
      Serial.printf("Mailbox latest value: %d\\n", value);
    size_t n = xStreamBufferReceive(streamBuf, bytes, sizeof(bytes), pdMS_TO_TICKS(100));
    if (n > 0) Serial.printf("Stream buffer received %u bytes\\n", (unsigned)n);
  }
}
void setup() {
  Serial.begin(115200);
  dataQueue = xQueueCreate(5, sizeof(int));
  mailbox = xQueueCreate(1, sizeof(int));
  streamBuf = xStreamBufferCreate(32, 1);
  if (!dataQueue || !mailbox || !streamBuf) {
    Serial.println("Communication object creation failed");
    while (1) delay(1000);
  }
  xTaskCreate(producerTask, "Producer", 3072, NULL, 2, NULL);
  xTaskCreate(consumerTask, "Consumer", 3072, NULL, 2, NULL);
  Serial.println("Queue, mailbox and stream buffer created");
}
void loop() { vTaskDelay(portMAX_DELAY); }
