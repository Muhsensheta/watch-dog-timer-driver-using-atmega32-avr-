/*
 * LCD_priv.h
 *
 *  Created on: ٠٥‏/٠٢‏/٢٠٢٣
 *      Author: houras
 */

#ifndef HAL_LCD_LCD_PRIV_H_
#define HAL_LCD_LCD_PRIV_H_

#define LCD_4BIT_MODE				0
#define LCD_8BIT_MODE				1


#define LCD_8BIT_MODE_2LINES_5X7	0x38
#define LCD_4BIT_MODE_2LINES_5X7	0x28
#define LCD_CLEAR_DISPLAY   0x01
#define LCD_DISPON_CURS0N_BLINKOFF  0x0E
#define LCD_ENTRY_MODE_SET          0x06  //increment position and disabled shift
#define LCD_R0C0                    0x80
#define LCD_R1C0                    0xC0



static void H_LCD_void_writeNLatch(u8 copy_u8Byte);



#endif /* HAL_LCD_LCD_PRIV_H_ */
