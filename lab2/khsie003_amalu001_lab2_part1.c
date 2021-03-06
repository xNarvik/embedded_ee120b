/**
 * khsie003_amalu001_lab1_part4.c
 * Kevin Hsieh, khsie003@ucr.edu
 * Alyza Malunao, amalu001@ucr.edu
 * Section 23
 * Lab 1 Exercise 4
 * A car has a fuel-level sensor that sets PA3..PA0 to a value between 0 (empty) and
 * 15 (full). A series of LEDs connected to PC5..PC0 should light to graphically
 * indicate the fuel level. If the fuel level is 1 or 2, PC5 lights. If the level is 3 or 4,
 * PC5 and PC4 light. Level 5-6 lights PC5..PC3. 7-9 lights PC5..PC2. 10-12 lights
 * PC5..PC1. 13-15 lights PC5..PC0. Also, PC6 connects to a "Low fuel" icon, which
 * should light if the level is 4 or less. (The example below shows the display for a
 * fuel level of 3). In this laboratory exercise, we will not actually use LEDS; just use
 * the simulator and set inputs to 0 and 1 as needed and observe the output.
 * Created: 1/6/2015 7:37:38 PM
 *  Author: student
 * I acknowledge all content contained herein, excluding template or example code,
 * is my own original work.
 */ 

#include <avr/io.h>

//x is the word to be modified, k-th bit to modify, b is the new bit
unsigned char SetBit(unsigned char x, unsigned char k, unsigned b){
	return(b?x|(0x01<<k):x&~(0x01<<k));
}

int main(void)
{
	unsigned char lights = 0;
	unsigned char button = 0;
	//unsigned char PC = 0;
	
	DDRC = 0x00; PORTC = 0xFF; //input
	DDRA = 0xFF; PORTA = 0x00; //output // flipped... sorry!!
	
    while(1)
    {
        //PC = PINC & 0x0F;
		
		button = ~PINC & 0x0F;
		lights = 0;
		lights = SetBit(lights, 0, button >= 13);
		lights = SetBit(lights, 1, button >= 10);
		lights = SetBit(lights, 2, button >= 7);
		lights = SetBit(lights, 3, button >= 5);
		lights = SetBit(lights, 4, button >= 3);
		lights = SetBit(lights, 5, button >= 1);
		lights = SetBit(lights, 6, button <= 4);
		
		PORTA = lights;
		
    }
	return 0;
}