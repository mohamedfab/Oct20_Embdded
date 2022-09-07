/*
 * EXTINT_Types.h
 *
 *  Created on: Sep 6, 2022
 *      Author: Eng_Fawzi
 */

#ifndef SOURCE_01_MCAL_EXTINT_INC_EXTINT_TYPES_H_
#define SOURCE_01_MCAL_EXTINT_INC_EXTINT_TYPES_H_

typedef enum
{
	EXT_INT0,
	EXT_INT1,
	EXT_INT2
}extint_intId_t;



typedef enum
{
	LOW_LEVEL,
	FAILING,
	RISING,
	BOTH
}extint_sensId_t;

#endif /* SOURCE_01_MCAL_EXTINT_INC_EXTINT_TYPES_H_ */
