#include <reg51.h>
#include <stdio.h>

char putchar(char c)
{
    SBUF = c;

    while (TI == 0);

    TI = 0;

    return c;
}

void serial_ISR(void) interrupt 4
{
    if (RI)
    {
        RI = 0;

        printf("\r\n>>> INTERRUPT RECEIVED <<<\r\n");
    }
}

void UART_Init(void)
{
    SCON = 0x50;       // UART Mode 1, receiver enabled

    TMOD = 0x20;       // Timer 1 Mode 2

    TH1 = 0xFD;        // 9600 baud @ 11.0592 MHz
    TL1 = 0xFD;

    TR1 = 1;            // Start Timer 1

    ES = 1;             // Enable UART interrupt
    EA = 1;             // Enable global interrupt
}

void main(void)
{
    UART_Init();

    while (1)
    {
        printf("Hello World\r\n");

        {
            unsigned int i;
            unsigned int j;

            for (i = 0; i < 500; i++)
            {
                for (j = 0; j < 100; j++);
            }
        }
    }
}