#include <reg51.h>
#include <stdio.h>

void main(void)
{
    SCON = 0x50;      /* SCON: mode 1, 8-bit UART, enable rcvr */
    TMOD = 0x20;      /* TMOD: Timer 1, mode 2, 8-bit auto reload */
    TH1  = 0xFD;      /* TH1: reload value for 9600 baud rate */

    TR1 = 1;          /* TR1: Timer 1 run */
    TI  = 1;          /* TI: Set TI to send first character of UART */

    while (1)
    {
        printf("Hello World ! \n");
    }
}