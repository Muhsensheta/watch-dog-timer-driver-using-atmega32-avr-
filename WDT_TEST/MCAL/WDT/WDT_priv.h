/*
 * WDT_priv.h
 *
 *  Created on: ١٥‏/٠٢‏/٢٠٢٣
 *      Author: houras
 */

#ifndef WDT_WDT_PRIV_H_
#define WDT_WDT_PRIV_H_


#define WDTCR_REG     (*((volatile u8*)0x41))

//bits

#define WDE_BIT      3   //watchdog enable
#define WDTOE_BIT    4   //watchdog turn off  enable

//PRESCALER
#define WDT_PRESCALER_MASK     0b11111000//0xF8



#endif /* WDT_WDT_PRIV_H_ */
