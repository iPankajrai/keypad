#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#define lcd PORTC
#include<ilibrary/lcd_library.h>

//unsigned int val[10]= {0x3, 0x9f,0x25, 0xd, 0x99, 0x49, 0x41, 0x1f, 0x1, 0x9};  //for 7seg display

void main()
{ DDRC=0xff;
  DDRB= 0xff;
  DDRA= 0b11110000;
  PORTA=0b00001111; //PULL UP 
  DDRD= 0b11111111;
  while(1)
  {
   PORTB= keypad();
   
  }
}

   int keypad()
  { 
    lcd_init();
    while(1)
	{
      PORTD= 0b11111110;
	  _delay_ms(5);
      lcd_command(0x87);
      if((PINA & 0b00000001)==0)                         // key will give the output till it is pressed for computer type
	 {
       PORTB= 1;   //'or' :- { return '1' ; _delay_ms(90);}   // delay is used for computer type keypad program 
	                                       // or
										// ; break;	                 // in case of delay:-when we release our finger from the keypad then only the key will work
	   lcd_data('1');                                                 // for break :- it will not work when the key is pressed continously
     }
     if((PINA & 0b00000010)==0)
     {
	   PORTB= 2;  // or PORTB= 0b00000010
	  
	   lcd_data('2');
	 }
	 if((PINA & 0b00000100)==0)
	 {
      PORTB= 3;
	 
	  lcd_data('3');
	 }
	if((PINA & 0b00001000)==0)
	{
      PORTB= 4;
	  lcd_data('4');
	}

    
	PORTD= 0b11111101;
	_delay_ms(5);
   	
	if((PINA & 0b00000001)==0)
	 {
      PORTB= 5;
	  lcd_data('5');
	}
	if((PINA & 0b00000010)==0)
	{
	PORTB= 6;
	lcd_data('6');
	}
	if((PINA & 0b00000100)==0)
	{
	PORTB= 7;
	lcd_data('7');
	}
	if((PINA & 0b00001000)==0)
	{
	PORTB= 8;
	lcd_data('8');
	}
	
  
	PORTD= 0b11111011;
	_delay_ms(5);
   	
	if((PINA & 0b00000001)==0)
	{
	PORTB= 9;
	lcd_data('9');
	}
	if((PINA & 0b00000010)==0)
	{
	PORTB= 0b00001010;  //10
	lcd_data('A');
	}
	if((PINA & 0b00000100)==0)
	{
	PORTB= 0b00001011;  //11
	lcd_data('B');
	}
	if((PINA & 0b00001000)==0)
	{
	PORTB= 0b00001100;  //12
	lcd_data('C');
	}
	
   
	PORTD= 0b11110111;
	_delay_ms(5);
  
	  if((PINA & 0b00000001)==0)
	{
	PORTB=0b00001101;  //13
	lcd_data('D');
	}
	if((PINA & 0b00000010)==0)
	{
	PORTB= 0b00001110;  //14
	lcd_data('E');
	}
	if((PINA & 0b00000100)==0)
	{
	PORTB= 0b00001111;  //15
	lcd_data('F');
	}
	if((PINA & 0b00001000)==0)
	{
	PORTB= 0b00000000;  //0
	lcd_data('0');
	}
	
  	
   }
  
 }
