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
//static unsigned int timer0_count = 0;
static unsigned int timer1_count = 0;
static int active_port = 0;
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
     case 7:    return 0b0000111;
     case 8:    return 0b1111111;
     case 9:    return 0b1101111;
    }
}

void timer0_tick_procedure(){
     if (active_port>=4)
        active_port = 0;
    PORTC = 0x0F & ~(1<<active_port); 
    active_port++;
}

void timer1_tick_procedure(){
    PORTD = bcd_encode(timer++);
    if (timer>=10)
        timer=0;
}

// Timer 0 overflow interrupt service routine
interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{

    TCNT0=256-100; // Timer overflow : 0.1 ms                                  
    //timer0_tick_procedure();
    
}

// Timer 1 overflow interrupt service routine
interrupt [TIM1_OVF] void timer1_ovf_isr(void)
{

    TCNT1H=0xE0;
    TCNT1L=0xC0;          
    ++timer1_count;                      
    
    if (timer1_count==1000) {  // Timer tick : 1s    
        timer1_tick_procedure();    
        timer1_count=0;
    }


}


void main(void)
{
// Declare your local variables here

DDRC= 0x0F; 
DDRD= 0xFF; 

PORTC=0xFE;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 1000.000 kHz
// Mode: Normal top=0xFF
// OC0 output: Disconnected
// Timer Period: 0.1 ms
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (1<<CS01) | (0<<CS00);
TCNT0=256-100;


// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: 8000.000 kHz
// Mode: Normal top=0xFFFF
// Timer Period: 1 ms
// Timer1 Overflow Interrupt: On
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (0<<CS11) | (1<<CS10);
TCNT1H=0xE0;
TCNT1L=0xC0;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (1<<TOIE1) | (0<<OCIE0) | (1<<TOIE0);

//MCUCR=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
//MCUCSR=(0<<ISC2);

// Global enable interrupts
#asm("sei")

while (1);
}
