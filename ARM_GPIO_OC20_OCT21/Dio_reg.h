/*
 * Dio_reg.h
 *
 *  Created on: Aug 27, 2022
 *      Author: Eng_Fawzi
 */

#ifndef DIO_REG_H_
#define DIO_REG_H_

#define DIO_PORTA_BASE           (0x40004000)
#define DIO_PORTB_BASE           (0x40005000)
#define DIO_PORTC_BASE           (0x40056000)
#define DIO_PORTD_BASE           (0x40007000)
#define DIO_PORTE_BASE           (0x40024000)
#define DIO_PORTF_BASE           (0x40025000)
#define DIO_RCGC2_BASE                    (0x400FE000)

#define DIO_GPIODATA_OFFSET                  (0x000)
#define DIO_GPIODIR_OFFSET                   (0x400)
#define DIO_GPIODEN_OFFSET                   (0x51C)
#define DIO_RCGC2_OFFSET                     (0x108)

    /*   Data Register   */
#define DIO_GPIODATA_PORTB_REG        (*(u32*)(DIO_PORTA_BASE + DIO_GPIODATA_OFFSET))
#define DIO_GPIODATA_PORTA_REG        (*(u32*)(DIO_PORTB_BASE + DIO_GPIODATA_OFFSET))
#define DIO_GPIODATA_PORTC_REG        (*(u32*)(DIO_PORTC_BASE + DIO_GPIODATA_OFFSET))
#define DIO_GPIODATA_PORTD_REG        (*(u32*)(DIO_PORTD_BASE + DIO_GPIODATA_OFFSET))
#define DIO_GPIODATA_PORTE_REG        (*(u32*)(DIO_PORTE_BASE + DIO_GPIODATA_OFFSET))
#define DIO_GPIODATA_PORTF_REG        (*(u32*)(DIO_PORTF_BASE + DIO_GPIODATA_OFFSET))

/*     Direction Register   */
#define DIO_GPIODIR_PORTA_REG        (*(u32*)(DIO_PORTA_BASE + DIO_GPIODIR_OFFSET))
#define DIO_GPIODIR_PORTB_REG        (*(u32*)(DIO_PORTB_BASE + DIO_GPIODIR_OFFSET))
#define DIO_GPIODIR_PORTC_REG        (*(u32*)(DIO_PORTC_BASE + DIO_GPIODIR_OFFSET))
#define DIO_GPIODIR_PORTD_REG        (*(u32*)(DIO_PORTD_BASE + DIO_GPIODIR_OFFSET))
#define DIO_GPIODIR_PORTE_REG        (*(u32*)(DIO_PORTE_BASE + DIO_GPIODIR_OFFSET))
#define DIO_GPIODIR_PORTF_REG        (*(u32*)(DIO_PORTF_BASE + DIO_GPIODIR_OFFSET))

/*     Digital Enable Register */
#define DIO_GPIODEN_PORTA_REG        (*(u32*)(DIO_PORTA_BASE + DIO_GPIODEN_OFFSET))
#define DIO_GPIODEN_PORTB_REG        (*(u32*)(DIO_PORTB_BASE + DIO_GPIODEN_OFFSET))
#define DIO_GPIODEN_PORTC_REG        (*(u32*)(DIO_PORTC_BASE + DIO_GPIODEN_OFFSET))
#define DIO_GPIODEN_PORTD_REG        (*(u32*)(DIO_PORTD_BASE + DIO_GPIODEN_OFFSET))
#define DIO_GPIODEN_PORTE_REG        (*(u32*)(DIO_PORTE_BASE + DIO_GPIODEN_OFFSET))
#define DIO_GPIODEN_PORTF_REG        (*(u32*)(DIO_PORTF_BASE + DIO_GPIODEN_OFFSET))

/*     RCGC2 Register */
#define DIO_RCGC2_REG               (*(u32*)(DIO_RCGC2_BASE + DIO_RCGC2_OFFSET))

#endif /* DIO_REG_H_ */
