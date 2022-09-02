/*
 * Keypad.h
 *
 *  Created on: Sep 2, 2022
 *      Author: Eng_Fawzi
 */

#ifndef SOURCE_02_ECUA_KEYPAD_INC_KEYPAD_H_
#define SOURCE_02_ECUA_KEYPAD_INC_KEYPAD_H_

#include "Keypad_Types.h"
#include "Std_Types.h"

void Keypad_vidinit(void);
kp_row_t Keypad_udtgetRow(void);
kp_col_t Keypad_udtgetCol(kp_row_t);
u8 Keypad_u8GetButton(void);


#endif /* SOURCE_02_ECUA_KEYPAD_INC_KEYPAD_H_ */
