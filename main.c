#include <at89c5131.h>
//#include<reg51.h>
#include "lcd.h"		//Header file with LCD interfacing functions
#include "serial.c"	//C file with UART interfacing functions
//sbit LED=P1^7;


void incorrect(void)
	
{    lcd_init();
	lcd_write_string("Invalid input");
//	lcd_cmd(0xc0);
	//	 lcd_write_string("Pass correct number\r\n");
		 msdelay(2000);
   	lcd_cmd(0x01);
}
void dash(void)
{
	 msdelay(1000);
//	 lcd_cmd(0x80);
	// lcd_write_string("-");
	// P1 = 0x1;
	 tone(2000);    
    
  	//two sec => dash
	// lcd_cmd(0x01);
}	
void dot(void)
{  msdelay(1000);
//	 lcd_cmd(0x80);
//	 lcd_write_string(".");
	//P1 = 0x1;
	 tone(1000);        
//P1= 0x0;	// one sec => dot
	// lcd_cmd(0x01);
}	



//Main function
void main(void)
{
	unsigned char ch=0;
	
	//Initialize port P1 for output from P1.7-P1.4
	P0 = 0x0F;
	
	//Call initialization functions
	lcd_init();
	uart_init();
	
	//These strings will be printed in terminal software
	transmit_string("************************\r\n");
	transmit_string("This is the morse code !\r\n");
	transmit_string("Type any alphabet or numbers to hear the corresponding morse code\r\n");
	transmit_string("************************\r\n");
	lcd_write_string("Input please");
	ch = receive_char();
	lcd_cmd(0x01);
	while(1)
	{

      //Displays the typed character on the terminal software
		transmit_char(ch); 
			SCON = 0; //to ensure that the key being pressed in between is getting ignored.
			switch(ch)  // all the cases and corresponding tones.
			{

				case 'a' : case 'A' :
					dot();
				  dash();
				  break;
				
				case 'b' : case 'B' :
					dash();
				  dot();
				  dot();
				  break;
				
				case 'c' : case 'C' :
					dash();
				  dot();
				  dash();
				  dot();
				  break;
					
				case 'd' : case 'D' :
					dash();
				  dot();
				  dot();
				  break;
					
				case 'e' : case 'E' :
					dot();
					break;
				
				case 'f' : case 'F' :
					dot();
				  dot();
				  dash();
				  dot();
				  break;
				case 'g' : case 'G' :
					dash();
				  dash();
					dot();
				  break;
				case 'h' : case 'H' :
					dot();
					dot();
					dot();
					dot();
				  break;
				case 'i' : case 'I' :
					dot();
					dot();
				  break;
				case 'j' : case 'J' :
					dot();
				  dash();
				  dash();
				  dash();
				  break;
				case 'k' : case 'K' :
					dash();
					dot();
				  dash();
				  break;
				case 'l' : case 'L' :
					dot();
				  dash();
					dot();
					dot();
				  break;
				case 'm' : case 'M' :
					dash();
				  dash();
				  break;
				case 'n' : case 'N' :
					dash();
					dot();
				  break;
				case 'o' : case 'O' :
					dash();
				  dash();
				  dash();
				  break;
				case 'p' : case 'P' :
					dot();
				  dash();
				  dash();
					dot();
				  break;
				case 'q' : case 'Q' :
					dash();
				  dash();
					dot();
				  dash();
				  break;
				case 'r' : case 'R' :
					dot();
				  dash();
					dot();
				  break;
				case 's' : case 'S' :
					dot();
					dot();
					dot();
					break;
				case 't' : case 'T' :
					dash();
					break;
				case 'u' : case 'U' :
					dot();
					dot();
					dash();
					break;
				case 'v' : case 'V' :
					dot();
					dot();
					dot();
					dash();
					break;
				case 'w' : case 'W' :
					dot();
					dash();
					dash();
					break;
				case 'x' : case 'X' :
					dash();
					dot();
					dot();
					dash();
					break;
				case 'y' : case 'Y' :
					dash();
					dot();
					dash();
					dash();
					break;
				case 'z' : case 'Z' :
					dash();
					dash();
					dot();
					dot();
					break;
				case '1' :
					
					dot();
					dash();
					dash();
					dash();
					dash();
					break;
				case '2' :
					dot();
					dot();
					dash();
					dash();
					dash();
					break;
				case '3' :
					dot();
					dot();
					dot();
					dash();
					dash();
					break;
				case '4' :
					dot();
					dot();
					dot();
					dot();
					dash();
					break;
				case '5' :
					dot();
					dot();
					dot();
					dot();
					dot();
					break;
				case '6' :
					dash();
					dot();
					dot();
					dot();
					dot();
					break;
				case '7' :
					dash();
					dash();
					dot();
					dot();
					dot();
					break;
				case '8' :
					dash();
					dash();
					dash();
					dot();
					dot();
					break;
				case '9' :
					dash();
					dash();
					dash();
					dash();
					dot();
					break;
				case '0' :
					dash();
					dash();
					dash();
					dash();
					dash();
					break;
				default:transmit_string("Incorrect test. Pass correct number\r\n");
				        incorrect();
				      
								 break;

			}
			SCON=0x50;
			lcd_cmd(0x80);
			lcd_write_string("Input please");
			
			ch = receive_char();
			lcd_init();
			lcd_cmd(0x01);
			
			
	}
}
