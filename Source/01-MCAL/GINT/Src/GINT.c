/*
 * GINT.c
 *
 *  Created on: Sep 3, 2022
 *      Author: Eng_Fawzi
 */
#include "GINT_Reg.h"
#include "Bit_Math.h"

void GINT_vidEnableAllInterrupts(void)
{
	SET_BIT(GINT_SREG_REG,7);
}
void GINT_vidDisableAllInterrupts(void)
{
	CLEAR_BIT(GINT_SREG_REG,7);
}
