#include "STD_TYPES.h"
#include <util/delay.h>

#include "DIO_interface.h"
#include "CLCD_interface.h"


void main(void)
{

	/* Pattern for --> Character*/
	uint8 Local_u8Pattern0[8]={
			0b00000,
			0b00100,
			0b01110,
			0b11111,
			0b00100,
			0b00100,
			0b00100,
			0b00100
	};
	/* Pattern for CLR digit Character*/
	uint8 Local_u8Pattern1[8]={
			0b00000,
			0b00000,
			0b00000,
			0b00000,
			0b00000,
			0b00000,
			0b00000,
			0b00000
	};

	uint8 Local_u8UpSwitch, Local_u8DownSwitch, Local_u8EnterSwitch, Local_u8Counter3=1, Local_u8Operation;
	sint8 Local_s8Counter1=1, Local_s8Counter2=1, Local_s8Result=0;

	/*Set port direction*/
	DIO_u8SetPortDirection(DIO_u8PORTA,DIO_u8PORT_OUTPUT);

	/*enable pull up  resistance*/
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN3,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN4,DIO_u8PIN_INPUT);

	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN3,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN4,DIO_u8PIN_HIGH);




	CLCD_voidInit();


	while(1)
	{
		/*Get reading of buttons & set delay for Debouncing*/
		DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN4,&Local_u8EnterSwitch);
		DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN3,&Local_u8DownSwitch);
		DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN2,&Local_u8UpSwitch);
		_delay_ms(200);
		DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN4,&Local_u8EnterSwitch);
		DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN3,&Local_u8DownSwitch);
		DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN2,&Local_u8UpSwitch);

		Local_s8Counter1=1;
		Local_s8Counter2=1;
		/*Set initial screen */
		CLCD_voidSendNumber(1);
		CLCD_voidSendData('+');
		CLCD_voidSendNumber(1);
		CLCD_u8SendSpecialCharacter(0,Local_u8Pattern0,0,1);
		CLCD_voidGoToXY(0,0);

		/*get the 1st number*/
		while(Local_u8EnterSwitch==1)
		{
			/*Get reading of buttons & set delay for Debouncing*/
			DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN4,&Local_u8EnterSwitch);
			DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN3,&Local_u8DownSwitch);
			DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN2,&Local_u8UpSwitch);
			_delay_ms(200);
			DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN4,&Local_u8EnterSwitch);
			DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN3,&Local_u8DownSwitch);
			DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN2,&Local_u8UpSwitch);

			if((Local_s8Counter1>=0)&&(Local_s8Counter1<=9))
			{
				if(Local_u8UpSwitch==0)
				{
					Local_s8Counter1++;
				}
				else if (Local_u8DownSwitch==0)
				{
					Local_s8Counter1--;
				}
			}

			if(Local_s8Counter1==10)
			{
				Local_s8Counter1=0;
			}
			else if(Local_s8Counter1==-1)
			{
				Local_s8Counter1=9;
			}

			CLCD_voidSendNumber(Local_s8Counter1);
			CLCD_voidGoToXY(0,0);

		}
		/*Get reading of buttons & set delay for Debouncing*/
		DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN4,&Local_u8EnterSwitch);
		DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN3,&Local_u8DownSwitch);
		DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN2,&Local_u8UpSwitch);
		_delay_ms(200);
		DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN4,&Local_u8EnterSwitch);
		DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN3,&Local_u8DownSwitch);
		DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN2,&Local_u8UpSwitch);

		CLCD_u8SendSpecialCharacter(1,Local_u8Pattern1,0,1);
		CLCD_u8SendSpecialCharacter(0,Local_u8Pattern0,1,1);
		CLCD_voidGoToXY(1,0);

		/*get the operation*/
		while(Local_u8EnterSwitch==1)
		{
			/*Get reading of buttons & set delay for Debouncing*/
			DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN4,&Local_u8EnterSwitch);
			DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN3,&Local_u8DownSwitch);
			DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN2,&Local_u8UpSwitch);
			_delay_ms(200);
			DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN4,&Local_u8EnterSwitch);
			DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN3,&Local_u8DownSwitch);
			DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN2,&Local_u8UpSwitch);

			if((Local_u8Counter3>0)&&(Local_u8Counter3<5))
			{
				if(Local_u8UpSwitch==0)
				{
					Local_u8Counter3++;
				}
				else if (Local_u8DownSwitch==0)
				{
					Local_u8Counter3--;
				}
			}

			if(Local_u8Counter3==5)
			{
				Local_u8Counter3=1;
			}
			else if(Local_u8Counter3==0)
			{
				Local_u8Counter3=4;
			}

			switch(Local_u8Counter3)
			{
			case 1:Local_u8Operation='+'; break;
			case 2:Local_u8Operation='-'; break;
			case 3:Local_u8Operation='*'; break;
			case 4:Local_u8Operation='/'; break;
			}
			CLCD_voidSendData(Local_u8Operation);
			CLCD_voidGoToXY(1,0);
		}
		/*Get reading of buttons & set delay for Debouncing*/
		DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN4,&Local_u8EnterSwitch);
		DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN3,&Local_u8DownSwitch);
		DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN2,&Local_u8UpSwitch);
		_delay_ms(200);
		DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN4,&Local_u8EnterSwitch);
		DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN3,&Local_u8DownSwitch);
		DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN2,&Local_u8UpSwitch);

		CLCD_u8SendSpecialCharacter(1,Local_u8Pattern1,0,1);
		CLCD_u8SendSpecialCharacter(1,Local_u8Pattern1,1,1);
		CLCD_u8SendSpecialCharacter(0,Local_u8Pattern0,2,1);
		CLCD_voidGoToXY(2,0);

		/*get the 2nd number*/
		while(Local_u8EnterSwitch==1)
		{
			/*Get reading of buttons & set delay for Debouncing*/
			DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN4,&Local_u8EnterSwitch);
			DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN3,&Local_u8DownSwitch);
			DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN2,&Local_u8UpSwitch);
			_delay_ms(200);
			DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN4,&Local_u8EnterSwitch);
			DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN3,&Local_u8DownSwitch);
			DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN2,&Local_u8UpSwitch);

			if((Local_s8Counter2>=0)&&(Local_s8Counter2<=9))
			{
				if(Local_u8UpSwitch==0)
				{
					Local_s8Counter2++;
				}
				else if (Local_u8DownSwitch==0)
				{
					Local_s8Counter2--;
				}
			}

			if(Local_s8Counter2==10)
			{
				Local_s8Counter2=0;
			}
			else if(Local_s8Counter2==-1)
			{
				Local_s8Counter2=9;
			}

			CLCD_voidSendNumber(Local_s8Counter2);
			CLCD_voidGoToXY(2,0);

		}
		CLCD_voidGoToXY(3,0);

		CLCD_voidSendData('=');

		switch(Local_u8Counter3)
		{
		case 1:Local_s8Result=Local_s8Counter1+Local_s8Counter2;   break;
		case 2:Local_s8Result=Local_s8Counter1-Local_s8Counter2;   break;
		case 3:Local_s8Result=Local_s8Counter1*Local_s8Counter2;   break;
		case 4:Local_s8Result=(float)Local_s8Counter1/(float)Local_s8Counter2;   break;
		}
		if((Local_u8Counter3==4)&&Local_s8Counter2==0)
		{
			CLCD_u8SendString("Math Error!");
		}else
		{
			if(Local_u8Counter3==4)
			{

				CLCD_voidSendNumber(Local_s8Result);
				CLCD_voidSendData('.');
				/*Get the floating part of number*/
				CLCD_voidSendNumber((((float)Local_s8Counter1*10/(float)Local_s8Counter2)-10));

			}else
			{
				CLCD_voidSendNumber(Local_s8Result);

			}

		}



		DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN4,&Local_u8EnterSwitch);
		_delay_ms(200);
		DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN4,&Local_u8EnterSwitch);


		while(Local_u8EnterSwitch==1)
		{
			DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN4,&Local_u8EnterSwitch);
			_delay_ms(200);
			DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN4,&Local_u8EnterSwitch);

		}


		CLCD_voidSendCmd(1);

	}
}




