/*
 * Led.h
 *  Created on: Aug 27, 2022
 *  Author: Eng_Fawzi
 */

#ifndef SOURCE_02_ECUA_LED_INC_LED_H_
#define SOURCE_02_ECUA_LED_INC_LED_H_

#include "Led_Types.h"

void Led_vidledInit(void);
void Led_vidledOn(led_ledId_t led);
void Led_vidledOff(led_ledId_t led);
void Led_vidledToggle(led_ledId_t ledId);

#endif /* SOURCE_02_ECUA_LED_INC_LED_H_ */
