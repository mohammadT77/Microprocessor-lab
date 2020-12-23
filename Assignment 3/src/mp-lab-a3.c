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

void show_hello_world(){
    lcd_puts("> hello world! <");
    lcd_gotoxy(0,1);
    lcd_puts("A3: Problem1"); // Assignment3: Problem 1
}

void main(void)
{
 
DDRA= 0xFF; 

lcd_init(16);
show_hello_world();

while (1);
}
