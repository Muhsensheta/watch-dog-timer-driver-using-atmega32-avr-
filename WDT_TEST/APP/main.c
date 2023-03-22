/*
 * main.c
 *
 *  Created on: ١٥‏/٠٢‏/٢٠٢٣
 *      Author: houras
 */

#include<util/delay.h>
#include"STD_TYPES.h"
#include"LED_int.h"
#include"LCD_int.h"
#include"WDT_int.h"


#if(1)

void main()
{
  H_LCD_void_Init();
  H_LCD_void_sendData("H");
	while (1)
	{

	}
}
#endif

#if(0)
void main()
{
//INIT LCD
	H_LCD_void_Init();
	H_Led_void_ledInit(RED_LED);
	H_Led_void_setON(RED_LED);
	_delay_ms(1000);
	H_Led_void_setOFF(RED_LED);
	//WDT enanle


	M_WDT_void_sleep(WDT_TIMEOUT_2_0_S );
	M_WDT_void_enable();

	while (1)
	{
		H_LCD_void_sendString("HELLO");
		_delay_ms(1000);
		H_LCD_void_clear();
		M_WDT_void_Refresh();
	}
}
#endif
