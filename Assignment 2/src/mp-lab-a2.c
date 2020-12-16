/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
� Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 12/16/2020
Author  : 
Company : 
Comments: 


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <mega16.h>

// Declare your global variables here
static unsigned int timer_count = 0;
static unsigned int timer = 0;

char bcd_encode(int num){
    switch (num){
     case 0:    return 0b0111111;
     case 1:    return 0b0000110;
     case 2:    return 0b1011011;
     case 3:    return 0b1001111;
     case 4:    return 0b1100110;
     case 5:    return 0b1101101;
     case 6:    return 0b1111101;
     case 7:    return 0b0000000;
     case 8:    return 0b0111111;
     case 9:    return 0b1111111;
    }
}

void timer_tick_procedure(){
    
}

// Timer 0 overflow interrupt service routine
interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{

    TCNT0=0x9C; // Timer overflow : 1 ms            
    ++timer_count;                      
    
    if (timer_count==1000) {  // Timer tick : 1s    
        timer_tick_procedure();    
        //PORTD = bcd_encode(++timer);
        timer_count=0;
    }


}

void main(void)
{
// Declare your local variables here

DDRC= 0x0F; 
DDRD= 0xFF; 

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 1000.000 kHz
// Mode: Normal top=0xFF
// OC0 output: Disconnected
// Timer Period: 0.1 ms
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (1<<CS01) | (0<<CS00);
TCNT0=0x9C;
OCR0=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (1<<TOIE0);

//MCUCR=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
//MCUCSR=(0<<ISC2);

// Global enable interrupts
#asm("sei")

while (1)
      {
      // Place your code here
        PORTC = 0;        
        PORTD = bcd_encode(6);
      }
}
