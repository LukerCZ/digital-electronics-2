/***********************************************************************
 * 
 * Blink a LED in Arduino-style and use function from the delay library.
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2022 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/
/* Defines -----------------------------------------------------------*/
#define LED_GREEN PB5 // PB5 is AVR pin where green on-board LED 
#define BUTTON PD2                       // is connected
//#define SHORT_DELAY 250 // Delay in milliseconds
#ifndef F_CPU
# define F_CPU 16000000 // CPU frequency in Hz required for delay funcs
#endif

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>     // AVR device-specific IO definitions
#include <util/delay.h> // Functions for busy-wait delay loopshalo
#include <gpio.h>
#include <stdio.h>
// 
// This part is needed to use Arduino functions but also physical pin
// names. We are using Arduino-style just to simplify the first lab.
#include "Arduino.h"
#define PB5 13          // In Arduino world, PB5 is called "13"
#define PD2// -----


/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Toggle one LED and use delay library.
 * Returns:  none
 **********************************************************************/
int main(void)
{
      GPIO_mode_input_pullup(&DDRD, BUTTON);
      GPIO_mode_output(&DDRB, LED_GREEN);  // Set output mode in DDRB reg
    // Set pin where on-board LED is connected as output
    ///pinMode(LED_GREEN, OUTPUT);
    //pinMode(LED_GREEN, OUTPUT);
    // Infinite loop
    while (1)
    {
      GPIO_read(&PIND, BUTTON)
      if ( BUTTON == 1)
      
        GPIO_write_high(&PORTB, LED_GREEN);   // Set output high in PORTB reg
      else
        GPIO_write_low(&PORTB, LED_GREEN);   // Set output low in PORTB reg  
    }

    // Will never reach this
    return 0;
}