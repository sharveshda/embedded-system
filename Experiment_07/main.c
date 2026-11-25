#include <LPC214x.h>

void __irq UART0_ISR(void) {
    unsigned int iir = U0IIR;
    unsigned char ch;
    if ((iir & 0x0E) == 0x04 || (iir & 0x0E) == 0x0C) {
        ch = (unsigned char)U0RBR;     // read received byte
        while ((U0LSR & 0x20) == 0) { }
        U0THR = ch;                   // echo received byte
    }
    VICVectAddr = 0;
}

void uart0_init(void) {
    PINSEL0 |= 0x00000005;             // P0.0 TXD0, P0.1 RXD0
    VPBDIV = 0x01;                     // PCLK = CCLK (assume 60 MHz)
    U0LCR = 0x83;                      // DLAB=1, 8 data, no parity, 1 stop
    U0DLL = 195; U0DLM = 0;            // approx. 19200 baud at 60 MHz PCLK
    U0FDR = 0x10;                      // MULVAL=1, DIVADDVAL=0
    U0LCR = 0x03;                      // DLAB=0, 8N1
    U0IER = 0x01;                      // receive data available interrupt
    VICIntSelect &= ~(1u << 6);        // UART0 as IRQ
    VICVectAddr0 = (unsigned long)UART0_ISR;
    VICVectCntl0 = 0x20 | 6;
    VICIntEnable = (1u << 6);
}

int main(void) {
    uart0_init();
    while (1) { }
}
