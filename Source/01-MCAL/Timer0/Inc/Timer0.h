/*
 * Timer0.h
 *
 *  Created on: Sep 13, 2022
 *      Author: Eng_Fawzi
 */

#ifndef SOURCE_01_MCAL_TIMER0_INC_TIMER0_H_
#define SOURCE_01_MCAL_TIMER0_INC_TIMER0_H_

/*	Set Mode	*/
/*	Enable OV0 Interrupt*/
/*	Enable OC0 Interrupt*/
void Timer0_vidInit(void);

/*	Timer as a Timer	*/
void Timer0_vidSetTime(u32 time);
void Timer0_vidStartTimer(prescaler);
void Timer0_vidStopTimer(void);

/*	Timer as PWM	*/
void Timer0_vidPWMSetFrequency(frequency);
void Timer0_vidPWMSetDutyCycle(u8 dutyCycle);

#endif /* SOURCE_01_MCAL_TIMER0_INC_TIMER0_H_ */
