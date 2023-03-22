/*
 * LCD_int.h
 *
 *  Created on: ٠٥‏/٠٢‏/٢٠٢٣
 *      Author: houras
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

void H_LCD_void_Init(void);
void H_LCD_void_sendData(u8 copy_u8data);
void H_LCD_void_sendCommand(u8 copy_u8command);
void H_LCD_void_sendString(const u8 *pstr);
void H_LCD_void_clear(void);
void H_LCD_void_sendIntNum(s32 copy_s32_Num);
void H_LCD_void_gotXY(u8 copy_u8Row,u8 copy_u8Col);
void H_LCD_void_creatCustomChar(const u8 *ArrPattern,u8 copy_u8char);
void H_LCD_void_displayCustomChar(u8 copy_u8char);
f32  calculator_App(f32 a,f32 b,u8 operator);


#endif /* HAL_LCD_LCD_INT_H_ */
