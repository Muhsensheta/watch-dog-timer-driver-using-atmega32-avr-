/*
 * WDT_prog.c
 *
 *  Created on: ١٥‏/٠٢‏/٢٠٢٣
 *      Author: houras
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"DIO_int.h"

#include"WDT_priv.h"
#include"WDT_config.h"
#include"WDT_int.h"

void M_WDT_void_enable(void)// open watcchdog
{
	SET_BIT(WDTCR_REG,WDE_BIT);
}
void M_WDT_void_disable(void)//turnoff WDT
{
	/* Write logical one to WDTOE and WDE */
	WDTCR_REG |= (1<<WDTOE_BIT) | (1<<WDE_BIT);
	/* Turn off WDT */
	WDTCR_REG = 0x00;
}
void M_WDT_void_sleep(u8 copy_timeout)//time out
    {

	if((copy_timeout <= WDT_TIMEOUT_2_0_S ) &&(copy_timeout >= WDT_TIMEOUT_16_3_MS))
	    {
       //step 1 apply mask
		//WDTCR_REG & = WDT_PRESCALER_MASK ;

	   // step 2 insert value
	   WDTCR_REG|=copy_timeout;
	     }

}
void M_WDT_void_Refresh(void)
{
  asm("WDR");
}
