/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
� Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 1/9/2021
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

#asm
    .equ __lcd_port= 0x18; // LCD I/O Port: PORTB
#endasm

#include <mega16.h>
#include <lcd.h>
#include <stdlib.h>


const short int STEPS[8] = {0b00001001,0b00001000,0b000001010,0b00000010,0b00000110,0b00000100,0b00000101,0b00000001};
const int MAX_SPEED=940;
const int MAX_TIMER=1000;

static int timer_counter = 0;
short int state = -1;
short int dir=0;

unsigned int step_count =0;
int speed=0;
int acc=100;

void print_speed_acc(){
    char str_speed[10];
    char str_acc[10];
    ftoa(1000/(float)(MAX_TIMER-speed),2,str_speed);
    itoa(acc,str_acc);
    lcd_clear();
    lcd_gotoxy(0,0);        
    lcd_puts("Speed: ");
    lcd_puts(str_speed);
    lcd_puts(" RPS");
    lcd_gotoxy(0,1); 
    lcd_puts("Acc:  ");
    lcd_puts(str_acc);
    lcd_puts(" stp/s");
}

void timer_procedure(){
    if (!dir){ // STOP motor
        PORTA = 0;
        return;    
    }
    state += dir; 
    if (state>=8 || state<0)
        state = dir==1?0:7;
    PORTA = STEPS[state];  
    
}
void timer_procedure_speed(){    
    if (!dir) {
        return;
    }
    if (speed<=0){
        speed = 0;       
        dir *= -1;
        acc *= -1;
    }
    if (speed>=MAX_SPEED){
        speed = MAX_SPEED;
        acc *= -1;   
    }             
    speed += acc;   
    print_speed_acc();
}

interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
    TCNT0=0x83; 
    timer_counter++;
    if (dir)
       step_count++;
    else{
        step_count=0;
    }
                             
        
    if (step_count>=MAX_TIMER-speed){
        timer_procedure(); 
        step_count = 0;
    } 
    if (timer_counter>=MAX_TIMER) {
        timer_procedure_speed();
        timer_counter=0;
    }

}

void main(void)
{

char btn_hold = 0;

DDRA=0x1F;
PORTA = 0x00;
DDRB=0xFF;
DDRC=(0<<DDC7) | (0<<DDC6) | (0<<DDC5) | (0<<DDC4) | (0<<DDC3) | (0<<DDC2) | (0<<DDC1) | (0<<DDC0);
DDRD=(0<<DDD7) | (0<<DDD6) | (0<<DDD5) | (0<<DDD4) | (0<<DDD3) | (0<<DDD2) | (0<<DDD1) | (0<<DDD0);


// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 125.000 kHz
// Mode: Normal top=0xFF
// OC0 output: Disconnected
// Timer Period: 1 ms
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (1<<CS01) | (1<<CS00);
TCNT0=0x83;
OCR0=0x00;

TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (1<<TOIE0);

lcd_init(16);

#asm("sei")

lcd_puts("Motor: OFF");
lcd_gotoxy(0,1);
lcd_puts("M.A Tehrani");

while (1)
  {        
      PORTA.4 = (dir==-1?0:1);   
      
      if (!btn_hold&&!PINC.2){  
        lcd_clear(); 
        btn_hold = 1;
        TCNT0=0x83;         
        timer_counter=0;
        if (!dir){
            speed=1;
            dir=1;
        }
        else {
            dir=0;
            lcd_puts("Motor: OFF");
            lcd_gotoxy(0,1);
            lcd_puts("M.A Tehrani");
        }
        //timer_counter=500;            
        //TIMSK=0;
        //delay_ms(5);
        //PORTA = 0;
        //delay_ms(5);
        //TIMSK=1;
      } else if(PINC.2) {
        btn_hold=0;
      }

  }
}
