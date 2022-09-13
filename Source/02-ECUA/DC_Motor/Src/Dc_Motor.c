/*
 * Dc_Motor.c
 *
 *  Created on: Sep 13, 2022
 *      Author: Eng_Fawzi
 */
#include "Dc_Motor_Types.h"
#include <util/delay.h>

void DcMotor_vidInit(void)
{
	/*	Configure Pins Directions	*/

	/*	Make Sure Motor Stopped	*/

}

void DcMotor_vidStart(dcMotor_dir_t dir)
{
	/*	Set Enable Pin	*/
	if (dir == MOT_DIR_CW)
	{
		/*	Set IN1	*/

		/*	Clear IN2	*/
	}
	else
	{
		/*	Clear IN1	*/

		/*	Set IN2	*/
	}
}

void Dc_Motor_vidStop(void)
{
	/*	Clear En Pin	*/

	_delay_ms(3000);
}
