/*
 * Dio.h
 * Created on: Aug 26, 2022
 * Author: Eng_Fawzi
 */

#ifndef DIO_H_
#define DIO_H_

#include "Std_Types.h"
#include "Dio_reg.h"
#include "Dio_Types.h"

void Dio_vidClockEnable(dio_port_t port);
void Dio_vidDigitalEnable(dio_port_t port, dio_pin_t pin);
void Dio_vidConfigChanel(dio_port_t port, dio_pin_t pin, dio_dir_t dir);
void Dio_vidWriteChanel(dio_port_t port, dio_pin_t pin, dio_level_t level);
dio_level_t Dio_udtReadChanel(dio_port_t port, dio_pin_t pin);



#endif /* DIO_H_ */
