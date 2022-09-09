/*
 * Adc_Reg.h
 *
 *  Created on: Sep 9, 2022
 *      Author: Eng_Fawzi
 */

#ifndef SOURCE_01_MCAL_ADC_INC_ADC_REG_H_
#define SOURCE_01_MCAL_ADC_INC_ADC_REG_H_

#include "Std_Types.h"

/*	ADC Registers	*/
#define ADC_ADMUX_REG       (*(u8*)0x27)
#define ADC_ADCSRA_REG		(*(u8*)0x26)
#define ADC_ADCH_REG		(*(u8*)0x25)
#define ADC_ADCL_REG		(*(u8*)0x24)

#endif /* SOURCE_01_MCAL_ADC_INC_ADC_REG_H_ */
