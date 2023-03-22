/*
 * LCD_int.c
 *
 *  Created on: ٠٥‏/٠٢‏/٢٠٢٣
 *      Author: houras
 */

#include "STD_TYPES.h"
#include"BIT_MATH.h"
#include "DIO_int.h"

#include "LCD_priv.h"
#include "LCD_config.h"
#include "LCD_int.h"
#include<util/delay.h>


void H_LCD_void_Init(void)
{
	//set direction
	//set direction RS,EN
	M_DIO_void_setPinDir(LCD_RS_PORT,LCD_RS_PIN, OUT);
	M_DIO_void_setPinDir(LCD_EN_PORT,LCD_EN_PORT, OUT);
	//set direction D4....D7
	M_DIO_void_setPinDir(LCD_D7_PORT,LCD_D7_PIN,OUT);
	M_DIO_void_setPinDir(LCD_D6_PORT,LCD_D6_PIN,OUT);
	M_DIO_void_setPinDir(LCD_D5_PORT,LCD_D5_PIN,OUT);
	M_DIO_void_setPinDir(LCD_D4_PORT,LCD_D4_PIN,OUT);
#if (LCD_MODE== LCD_8BIT_MODE)
	//set direction D3....D0
	M_DIO_void_setPinDir(LCD_D3_PORT,LCD_D3_PIN,OUT);
	M_DIO_void_setPinDir(LCD_D2_PORT,LCD_D2_PIN,OUT);
	M_DIO_void_setPinDir(LCD_D1_PORT,LCD_D1_PIN,OUT);
	M_DIO_void_setPinDir(LCD_D0_PORT,LCD_D0_PIN,OUT);

#endif
	//send init sequence
#if(LCD_MODE== LCD_8BIT_MODE)
	_delay_ms(35);
	H_LCD_void_sendCommand(LCD_8BIT_MODE_2LINES_5X7);


#elif(LCD_MODE== LCD_4BIT_MODE)
	_delay_ms(35);
	//rs=command=0
	M_DIO_void_setPinValue(LCD_RS_PORT, LCD_RS_PIN,HIGH);
//EN=0, disabled
	M_DIO_void_setPinValue(LCD_EN_PORT, LCD_EN_PIN,LOW);
	//Prepare data
	M_DIO_void_setPinValue(LCD_D7_PORT,LCD_D7_PIN,0);
	M_DIO_void_setPinValue(LCD_D6_PORT,LCD_D6_PIN,0);
	M_DIO_void_setPinValue(LCD_D5_PORT,LCD_D5_PIN,1);
	M_DIO_void_setPinValue(LCD_D4_PORT,LCD_D4_PIN,0);
	//EN=1
	M_DIO_void_setPinValue(LCD_EN_PORT, LCD_EN_PIN,HIGH);
	_delay_ms(35);
	//EN=0;
	M_DIO_void_setPinValue(LCD_EN_PORT, LCD_EN_PIN,LOW);
	_delay_ms(35);
	H_LCD_void_sendCommand(LCD_4BIT_MODE_2LINES_5X7);


#else
#error("wrong lcd mood")
#endif
	//display ON ,OFF
	H_LCD_void_sendCommand(LCD_DISPON_CURS0N_BLINKOFF);
	//display clear
	H_LCD_void_sendCommand(LCD_CLEAR_DISPLAY);
	//entry mode set
	H_LCD_void_sendCommand(LCD_ENTRY_MODE_SET);
}
void H_LCD_void_sendData(u8 copy_u8data)
{
	//step 1 RS=1;
	M_DIO_void_setPinValue(LCD_RS_PORT, LCD_RS_PIN, HIGH);

	//step 2   write data
	H_LCD_void_writeNLatch( copy_u8data);
}
void H_LCD_void_sendCommand(u8 copy_u8command)
{
	//step 1 RS=0
	M_DIO_void_setPinValue(LCD_RS_PORT, LCD_RS_PIN, LOW);
	//step 2 write command
	H_LCD_void_writeNLatch( copy_u8command)	;
}
void H_LCD_void_sendString(const u8 *pstr)
{
	while(*pstr)
	{
		H_LCD_void_sendData(*pstr);
		pstr++;

	}

}
void H_LCD_void_clear(void)
{
	H_LCD_void_sendCommand(LCD_CLEAR_DISPLAY);
}
void H_LCD_void_sendIntNum(s32 copy_s32_Num)
{
  u8 loc_Arr[10]={0};
  s8 i;
  if(copy_s32_Num==0)
  {
	  H_LCD_void_sendData('0');

  }
  else if (copy_s32_Num<0)
  {
	  H_LCD_void_sendData('-');
	  copy_s32_Num*=-1;
  }
  while (copy_s32_Num!=0)
  {
	  loc_Arr[i]=(copy_s32_Num%10)+48;
	  copy_s32_Num=copy_s32_Num/10;
	  i++;
  }
  i--;
  while(i>=0)
  {
	  H_LCD_void_sendData(loc_Arr[i]+'0');
	  i--;
  }
}
void H_LCD_void_gotXY(u8 copy_u8Row,u8 copy_u8Col)
{
 if (copy_u8Row==0||copy_u8Row==1)
 {
	 if(copy_u8Col >= 0 &&copy_u8Col <=15)
	 {
		 switch(copy_u8Row)
		 {
		 case 0 :
			 H_LCD_void_sendCommand(LCD_R0C0+copy_u8Col);
			 break;

		 case 1:
			 H_LCD_void_sendCommand(LCD_R1C0+copy_u8Col);
			 break;

		 }
	 }
 }
}
void H_LCD_void_creatCustomChar(const u8 *ArrPattern,u8 copy_u8char)
{

}
void H_LCD_void_displayCustomChar(u8 copy_u8char)
{

}
f32  calculator_App(f32 a,f32 b,u8 operator)
{
	f32 result;
	switch(operator)
	{
	case('+'):
			result=a+b;
	        break;
	case('-'):
			result=a-b;
		     break;
	case('*'):
			result=a*b;
		     break;
	case('/'):
			result=a/b;
		      break;

	}
	return result;

}
static void H_LCD_void_writeNLatch(u8 copy_u8Byte)
{
#if(LCD_MODE== LCD_8BIT_MODE)
	//EN=0, disabled
		M_DIO_void_setPinValue(LCD_EN_PORT, LCD_EN_PIN,LOW);
	//step1 prepare data (DB7...DB0)

	M_DIO_void_setPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(copy_u8Byte,7));
	M_DIO_void_setPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(copy_u8Byte,6));
	M_DIO_void_setPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(copy_u8Byte,5));
	M_DIO_void_setPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(copy_u8Byte,4));
	M_DIO_void_setPinValue(LCD_D3_PORT,LCD_D3_PIN,GET_BIT(copy_u8Byte,3));
	M_DIO_void_setPinValue(LCD_D2_PORT,LCD_D2_PIN,GET_BIT(copy_u8Byte,2));
	M_DIO_void_setPinValue(LCD_D1_PORT,LCD_D1_PIN,GET_BIT(copy_u8Byte,1));
	M_DIO_void_setPinValue(LCD_D0_PORT,LCD_D0_PIN,GET_BIT(copy_u8Byte,0));
	//step2 activate enable ,(E=1)
	M_DIO_void_setPinValue(LCD_RS_PORT, LCD_RS_PIN, HIGH);

	//step3 : delay for 1msec
	_delay_ms(1);

	//step4 :deactivate enable (E=10)
	M_DIO_void_setPinValue(LCD_RS_PORT, LCD_RS_PIN, LOW);
	_delay_ms(5);
#elif(LCD_MODE== LCD_4BIT_MODE)
	//EN=0, disabled
	M_DIO_void_setPinValue(LCD_EN_PORT, LCD_EN_PIN,LOW);
	//devide bte to 2
	//step1  send high order bit on pins (DB7...DB4)
	M_DIO_void_setPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(copy_u8Byte,7));
	M_DIO_void_setPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(copy_u8Byte,6));
	M_DIO_void_setPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(copy_u8Byte,5));
	M_DIO_void_setPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(copy_u8Byte,4));
		//step2 activate enable ,(E=1)
		M_DIO_void_setPinValue(LCD_EN_PORT, LCD_EN_PIN, HIGH);

		//step3 : delay for 1msec
		_delay_ms(1);

		//step4 :deactivate enable (E=10)
		M_DIO_void_setPinValue(LCD_EN_PORT, LCD_EN_PIN, LOW);
		_delay_ms(5);
		//step 6 send lower order bits on pins (D7...D4)
		M_DIO_void_setPinValue(LCD_EN_PORT, LCD_EN_PIN, LOW);
		M_DIO_void_setPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(copy_u8Byte,3));
		M_DIO_void_setPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(copy_u8Byte,2));
		M_DIO_void_setPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(copy_u8Byte,1));
		M_DIO_void_setPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(copy_u8Byte,0));
		//activate enable
		M_DIO_void_setPinValue(LCD_EN_PORT, LCD_EN_PIN, HIGH);

		//delay
		_delay_ms(1);
		//deactivate enable
		M_DIO_void_setPinValue(LCD_EN_PORT, LCD_EN_PIN, LOW);
		//delay
		_delay_ms(5);
#else
  #error("wrong lcd mode")
#endif

}
