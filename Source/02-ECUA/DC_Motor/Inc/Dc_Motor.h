/*
 * Dc_Motor.h
 *
 *  Created on: Sep 13, 2022
 *      Author: Eng_Fawzi
 */

#ifndef SOURCE_02_ECUA_DC_MOTOR_INC_DC_MOTOR_H_
#define SOURCE_02_ECUA_DC_MOTOR_INC_DC_MOTOR_H_

#include "Dc_Motor_Types.h"

void DcMotor_vidInit(void);
void DcMotor_vidStart(dcMotor_dir_t dir);
void Dc_Motor_vidStop(void);

#endif /* SOURCE_02_ECUA_DC_MOTOR_INC_DC_MOTOR_H_ */
