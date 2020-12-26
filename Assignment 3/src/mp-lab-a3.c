/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
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
#include <stdlib.h>

#define ICP_EN PINC.0

static unsigned int timer0_counter = 0;
static int alpha_pointer = -1;
const char* ALPHABETS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

static unsigned int timer1_counter = 0;
const unsigned long TIMER1_VALUE = 0xE0C0;  
 

void show_hello_world(){
    lcd_puts("> hello world! <");
    lcd_gotoxy(0,1);
    lcd_puts("A3: Problem1"); // Assignment3: Problem 1
}

void timer0_procedure(){  // Assignment3: Problem 2
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
    if (timer0_counter==1000){ // Timer0 Tick period = 1 sec
        timer0_procedure();
        timer0_counter=0;   
    }
}

interrupt [TIM1_OVF] void timer1_ovf_isr(void)
{
    TCNT1=TIMER1_VALUE;
    ++timer1_counter;
}

interrupt [TIM1_CAPT] void timer1_capt_isr(void)
{
    char str_period[10];
    char str_freq[10];
    unsigned long period;
    unsigned int lcr1;  
    
    lcr1 = (ICR1H*256)+ICR1L;
    period = ((unsigned long)(((float)lcr1)/((float)(0xffff-TIMER1_VALUE)))) 
            + ((unsigned long) timer1_counter) ;
  
    
    timer1_counter = 0;         
    TCNT1=TIMER1_VALUE;
                         
    itoa(period,str_period);
    ftoa(1/((float)period/1000),3,str_freq);    
    
    lcd_clear();              
    lcd_puts("Period: ");
    lcd_puts(str_period);
    lcd_puts(" ms");
    lcd_gotoxy(0,1);     
    lcd_puts("Freq: ");       
    lcd_puts(str_freq);
    lcd_puts(" MHz");
}


void main(void)
{

DDRA= 0xFF;
DDRC= 0xF0;
PORTC.7 = 0; 

TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (1<<CS01) | (1<<CS00);
TCNT0=0x83;

TCCR1A= 0;
TCCR1B=(1<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (0<<CS11) | (1<<CS10);
TCNT1=TIMER1_VALUE;
ICR1H=0x00;
ICR1L=0x00;

TIMSK=(0<<OCIE2) | (0<<TOIE2) | (1<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (1<<TOIE1) | (0<<OCIE0) | (1<<TOIE0);

lcd_init(16);
show_hello_world();

#asm("sei");

while (1){
 if (ICP_EN){
     TIMSK |= (1<<TICIE1) | (1<<TOIE1);
     TIMSK &= ~(1<<TOIE0);
     alpha_pointer = -1;
 } else {
     TIMSK &= ~(1<<TICIE1);
     TIMSK &= ~(1<<TOIE1);
     TIMSK |= (1<<TOIE0);
 } 
}
}
