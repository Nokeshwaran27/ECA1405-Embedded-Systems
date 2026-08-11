#include <reg51.h>

void serial_interrupt(void) interrupt 4
{
    if (RI == 1)
    {
        RI = 0;              // Clear Receive Interrupt flag

        P1 = SBUF;           // Put received character on Port 1
    }

    if (TI == 1)
    {
        TI = 0;              // Clear Transmit Interrupt flag
    }
}

void main(void)
{
    TMOD = 0x20;             // Timer 1, Mode 2

    TH1 = 0xFD;              // 9600 baud for 11.0592 MHz crystal
    TL1 = 0xFD;

    SCON = 0x50;             // UART Mode 1, 8-bit UART, receiver enabled

    TR1 = 1;                 // Start Timer 1

    ES = 1;                  // Enable Serial Interrupt
    EA = 1;                  // Enable Global Interrupt

    P1 = 0x00;               // Initial Port 1 value

    while (1)
    {
        P1 = 0x00;           // Main program keeps running
    }
}