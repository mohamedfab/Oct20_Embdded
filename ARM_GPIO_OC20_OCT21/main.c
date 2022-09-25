/**
 * main.c
 */

#include "Dio.h"
void delay_ms(u32 delayMs)
{
    u32 delay;
    u32 count;
    for (delay = 0; delay < delayMs; delay++)
    {
        for (count = 0; count < 1590; count++)
        {
            ; /*   delay for 1 MS */
        }
    }
}
void main(void)
{
    Dio_vidClockEnable(DIO_PORTF);
    Dio_vidDigitalEnable(DIO_PORTF, DIO_PIN1);
    Dio_vidConfigChanel(DIO_PORTF, DIO_PIN1, DIO_OUTPUT);

   while (1)
   {
       Dio_vidWriteChanel(DIO_PORTF, DIO_PIN1, DIO_HIGH);
       /*    delay   */
       delay_ms(500);
       Dio_vidWriteChanel(DIO_PORTF, DIO_PIN1, DIO_LOW);
       /*    delay   */
       delay_ms(500);
   }
}
