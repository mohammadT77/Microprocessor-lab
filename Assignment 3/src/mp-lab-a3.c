/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
� Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 12/23/2020
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

#asm
    .equ __lcd_port= 0x1B; // LCD I/O Port: PORTA
#endasm

#include <lcd.h>

static unsigned int timer0_counter = 0;
static int alpha_pointer = -1;
const char* ALPHABETS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void show_hello_world(){
    lcd_puts("> hello world! <");
    lcd_gotoxy(0,1);
    lcd_puts("A3: Problem1"); // Assignment3: Problem 1
}

void timer0_procedure(){
    if (alpha_pointer>=25){
        alpha_pointer=-1;
    }
    if (alpha_pointer==-1){
        lcd_clear();
        lcd_gotoxy(0,0);
    }                         
    lcd_putchar(ALPHABETS[++alpha_pointer]);
}

interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
    TCNT0=0x83;
    ++timer0_counter;
    if (timer0_counter==1000){ // For 1s Timer0 Tick
        timer0_procedure();
        timer0_counter=0;   
    }


}

void main(void)
{
 
DDRA= 0xFF; 

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 125.000 kHz
// Mode: Normal top=0xFF
// OC0 output: Disconnected
// Timer Period: 1 ms
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (1<<CS01) | (1<<CS00);
TCNT0=0x83;

TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (1<<TOIE0);

lcd_init(16);
show_hello_world();

#asm("sei");

while (1);
}
