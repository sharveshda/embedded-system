#include <LPC214x.h>

#define SWITCH_MASK 0x00FF0000u  // P0.16-P0.23
#define LED_MASK    0x0000FF00u  // P0.8-P0.15

int main(void) {
    unsigned int switches;
    PINSEL1 &= ~0x0000FFFFu;     // P0.16-P0.23 as GPIO
    IO0DIR |= LED_MASK;          // LEDs as outputs
    IO0DIR &= ~SWITCH_MASK;      // switches as inputs

    while (1) {
        switches = (IO0PIN & SWITCH_MASK) >> 16;
        IO0SET = (switches << 8) & LED_MASK;
        IO0CLR = ((~switches << 8) & LED_MASK);
    }
}
