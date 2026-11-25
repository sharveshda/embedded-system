#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"
#include "freertos/event_groups.h"

#define EVENT_TIMER_BIT  (1 << 0)
#define EVENT_BUTTON_BIT (1 << 1)

TimerHandle_t periodicTimer;
EventGroupHandle_t events;

void timerCallback(TimerHandle_t timer) {
  Serial.println("Timer callback: periodic event");
  xEventGroupSetBits(events, EVENT_TIMER_BIT);
}
void eventTask(void *p) {
  for (;;) {
    EventBits_t bits = xEventGroupWaitBits(
      events, EVENT_TIMER_BIT | EVENT_BUTTON_BIT,
      pdTRUE, pdFALSE, portMAX_DELAY);
    if (bits & EVENT_TIMER_BIT) Serial.println("Task received TIMER event bit");
    if (bits & EVENT_BUTTON_BIT) Serial.println("Task received BUTTON event bit");
  }
}
void setup() {
  Serial.begin(115200);
  events = xEventGroupCreate();
  periodicTimer = xTimerCreate("Periodic", pdMS_TO_TICKS(2000),
                               pdTRUE, NULL, timerCallback);
  xTaskCreate(eventTask, "EventTask", 3072, NULL, 2, NULL);
  if (periodicTimer != NULL) xTimerStart(periodicTimer, 0);
  Serial.println("Periodic timer (2 s) and event group started");
}
void loop() {
  // Simulate a second event source every 5 seconds.
  static unsigned long last = 0;
  if (millis() - last >= 5000) {
    last = millis();
    xEventGroupSetBits(events, EVENT_BUTTON_BIT);
  }
  delay(20);
}
