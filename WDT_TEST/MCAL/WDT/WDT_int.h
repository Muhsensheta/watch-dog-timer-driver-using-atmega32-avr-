/*
 * WDT_int.h
 *
 *  Created on: ١٥‏/٠٢‏/٢٠٢٣
 *      Author: houras
 */

#ifndef WDT_WDT_INT_H_
#define WDT_WDT_INT_H_


#define   WDT_TIMEOUT_16_3_MS      0
#define   WDT_TIMEOUT_32_5_MS      1
#define   WDT_TIMEOUT_65_MS        2
#define   WDT_TIMEOUT_0_13_S       3
#define   WDT_TIMEOUT_0_26_S       4
#define   WDT_TIMEOUT_0_52_S       5
#define   WDT_TIMEOUT_1_0_S        6
#define   WDT_TIMEOUT_2_0_S        7


void M_WDT_void_enable(void);// open watcchdog
void M_WDT_void_disable(void);//turnoff WDT
void M_WDT_void_sleep(u8 copy_timeout);//time out
void M_WDT_void_Refresh(void);


#endif /* WDT_WDT_INT_H_ */
