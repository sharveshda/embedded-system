#include <LPC214x.h>
#include "sevenseg.h"

static const unsigned char code[10] =
 {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67};

void sevenseg_init(void) {
    PINSEL1 &= ~0x00FF0000u;     // P0.16-P0.23 GPIO (board dependent mux)
    IO0DIR |= 0x00FF3000u;       // segment bus + digit select P0.12/P0.13
    IO0CLR = 0x00FF0000u;
}

void sevenseg_show(unsigned int digit) {
    if (digit > 9) digit = 0;
    IO0CLR = 0x00FF0000u;
    IO0SET = ((unsigned int)code[digit] << 16);
    // Example: enable DS4 on P0.12 (active-low selection).
    IO0CLR = (1u << 12);
}

void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for (i=0; i<ms; i++)
        for (j=0; j<6000; j++) { __asm { NOP } }
}
