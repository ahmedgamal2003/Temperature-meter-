/*
 * negative_temperature.c
 *
 * Created: 9/16/2024 5:05:04 PM
 *  Author: AHMED GAMAL
 */ 


#include <avr/io.h>
#include "ADC_driver.h"
#include "LCD.h"
unsigned short temp,volt;

int main(void)
{
	LCD_clearscreen();
	LCD_vInit();
	ADC_vinit();
	LCD_vSend_string("Temp:");
    while(1)
    {
		volt=ADC_u16Read()*2.5;
		if(volt>=1000)
		{
			temp=(volt-1000)/10;
			if (temp<10)
			{
				LCD_movecursor(1,6);
				LCD_vSend_char('0');
				LCD_vSend_char(temp+48);
				LCD_vSend_char(0xDF);
				LCD_vSend_char('C');
				LCD_vSend_char(0x20);
			}
			else if (temp<100)
			{
				LCD_movecursor(1,6);
				LCD_vSend_char((temp/10)+48);
				LCD_vSend_char((temp%10)+48);
				LCD_vSend_char(0xDF);
				LCD_vSend_char('C');
				
			}
		}
		else
		{
			temp=(1000-volt)/10;
			if (volt<10)
			{
				LCD_movecursor(1,6);
				LCD_vSend_char(' ');
				LCD_vSend_char('-');
				LCD_vSend_char(temp+48);
				LCD_vSend_char(0xDF);
				LCD_vSend_char('C');
				LCD_vSend_char(0x20);
			}
			else if (temp<100)
			{
				LCD_movecursor(1,6);
				LCD_vSend_char('-');
				LCD_vSend_char((temp/10)+48);
				LCD_vSend_char((temp%10)+48);
				LCD_vSend_char(0xDF);
				LCD_vSend_char('C');
			}
		}
        //TODO:: Please write your application code 
    }
}