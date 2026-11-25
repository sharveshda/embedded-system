#include "sevenseg.h"

int main(void) {
    unsigned int digit;
    sevenseg_init();
    while (1) {
        for (digit = 0; digit <= 9; digit++) {
            sevenseg_show(digit);
            delay_ms(1000);
        }
    }
}
