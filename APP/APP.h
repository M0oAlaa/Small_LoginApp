#include "STD_TYPES.h"

#include "../MCAL/PORT/PORT_interface.h"
#include "../MCAL/DIO/DIO_interface.h"

#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/KEYPAD/KEYPAD_interface.h"

uint8_t Data(void)
{
	/*A local variable to hold the pressed key initialized by 0*/
	uint8_t local_u8PressedKey='0';

	/*Get pressed key*/
	local_u8PressedKey=KPD_u8GetPressedKey();

	/*Pooling to avoid the hold press*/
	while(local_u8PressedKey=='0')
	{
		local_u8PressedKey=KPD_u8GetPressedKey();
	}

	/*check the pressed key and send its number to LCD*/
	if(local_u8PressedKey==1)
	{
		return '1';
	}
	else if(local_u8PressedKey==2)
	{
		return '2';
	}
	else if(local_u8PressedKey==3)
	{
		return '3';
	}
	else if(local_u8PressedKey==4)
	{
		return '4';
	}
	else if(local_u8PressedKey==5)
	{
		return '5';
	}
	else if(local_u8PressedKey==6)
	{
		return '6';
	}
	else if(local_u8PressedKey==7)
	{
		return '7';
	}
	else if(local_u8PressedKey==8)
	{
		return '8';
	}
	else if(local_u8PressedKey==9)
	{
		return '9';
	}
	else
	{

	}
}

void APP_init(void)
{
	/*Initialization of port to declare the pins' direction and initial value*/
	PORT_INIT();
	/*Initialization of LCD*/
	LCD_init();
}

void APP_prog(void)
{
	/*A local varialble to hold the key pressed initialized by 0*/
	uint8_t local_u8DATA='0';

	/*Write a string at line 1 in LCD*/
	LCD_sendStrData("Enter your ID");
	/*Go to the beginning of line 2*/
	LCD_GoToXY(1,0);
	/*convert the number of key pressed to char*/
	local_u8DATA=Data();
	/*make sure that any button pressed and the pressed button not the enter button "9"*/
	while(local_u8DATA != '9' && local_u8DATA !='0')
	{
		/*chek if the number read one of keypad buttons' numbers*/
		if(local_u8DATA>'0' && local_u8DATA<='9')
		{
			/*Write the number at LCD*/
			LCD_sendData(local_u8DATA);
		}
		else
		{

		}
		/*Take a data until enter button pressed*/
		local_u8DATA=Data();
	}
	/*Clear LCD*/
	LCD_CLR();
	/*Go to the beginning of line 1*/
	LCD_GoToXY(0,0);
	/*Write a string at line 1 in LCD*/
	LCD_sendStrData("Enter Password");
	/*Go to the beginning of line 2*/
	LCD_GoToXY(1,0);
	/*convert the number of key pressed to char*/
	local_u8DATA=Data();
	/*make sure that the pressed button not the enter button "9"*/
	while(local_u8DATA != '9')
	{
		/*chek if the number read one of keypad buttons' numbers*/
		if(local_u8DATA>'0' && local_u8DATA<='9')
		{
			/*Write the number at LCD*/
			LCD_sendData(local_u8DATA);
		}
		else
		{

		}
		/*Take a data until enter button pressed*/
		local_u8DATA=Data();
	}
	/*Clear the LCD lines*/
	LCD_CLR();
	/*Go to the beginning of line 1*/
	LCD_GoToXY(0,0);
	/*Write finish*/
	LCD_sendStrData("Finish");

	while(1)
	{

	}

}

