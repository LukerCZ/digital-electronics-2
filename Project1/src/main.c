/***********************************************************************
 * 
 * Use Analog-to-digital conversion to read push buttons on LCD keypad
 * shield and display it on LCD screen.
 * 
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2018 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/


/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include <gpio.h>           // GPIO library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <lcd.h>            // Peter Fleury's LCD library
#include <stdlib.h>         // C library. Needed for number conversions

// ENCODER
#define CLK PB2
#define DT PB3

//Global integers
static int8_t counter = 0; 
static uint8_t aState;
static uint8_t aLastState;

/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Use Timer/Counter1 and start ADC conversion every 100 ms.
 *           When AD conversion ends, send converted value to LCD screen.
 * Returns:  none
 **********************************************************************/
int main(void)
{
   //Setup of pins to input
    GPIO_mode_input_nopull(&DDRB,CLK);
    GPIO_mode_input_nopull(&DDRB,DT);

    aLastState = GPIO_read(&PINB,CLK);

    // Initialize display
    lcd_init(LCD_DISP_ON);

    /*---------------------------------------------------------------------------*/
    // Configure Analog-to-Digital Convertion unit
    // Select ADC voltage reference to "AVcc with external capacitor at AREF pin"
    ADMUX = ADMUX | (1<<REFS0);
    // Enable ADC module
    ADCSRA = ADCSRA | (1<<ADEN);
    // Enable conversion complete interrupt
    ADCSRA = ADCSRA | (1<<ADIE);
    // Set clock prescaler to 128
    ADCSRA = ADCSRA | (1<<ADPS2 | 1<<ADPS1 | 1<<ADPS0);
    // Configure 16-bit Timer/Counter1/0 to start ADC conversion
    // Set prescaler to 33 ms, 1s and enable overflow interrupt
    TIM1_overflow_33ms();
    TIM1_overflow_interrupt_enable();
    TIM0_overflow_1s();
    TIM0_overflow_interrupt_enable();
    /*---------------------------------------------------------------------------*/

    // Enables interrupts by setting the global interrupt mask
    sei();

    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines ISRs */
    }

    // Will never reach this
    return 0;
}


ISR(TIMER0_OVF_vect)
{
  char string[4]; // String for converted numbers by itoa()
  aState = GPIO_read(&PINB,CLK); // Reads the "current" state of the CLK
  
  lcd_gotoxy(0, 1);
  lcd_puts("ENKODER:");

  itoa(counter, string, 10);

  // If the CLK state is different to the DT state, that means the encoder is rotating clockwise
  if (aState != aLastState && aState == 1){
    
      if (GPIO_read(&PINB,DT) != aState) {
      counter ++;
      }
      else {
      counter --;
      }

      //Encoder limit
      if(counter>20)
        counter = 20;
      else if(counter < 0)
        counter = 0;

      // Convert "value" to "string" and display it
      itoa(counter, string, 10);
      lcd_gotoxy(8, 1);
      lcd_puts("     ");
      lcd_gotoxy(8, 1);
      lcd_puts(string);
  }

  aLastState = aState; // Updates the previous state of the CLK with the current state

}

/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Use Single Conversion mode and start conversion every 100 ms.
 **********************************************************************/
ISR(TIMER1_OVF_vect)
{
    // Start ADC conversion
    ADCSRA = ADCSRA | (1<<ADSC);
}

/**********************************************************************
 * Function: ADC complete interrupt
 * Purpose:  Display converted value on LCD screen.
 **********************************************************************/
ISR(ADC_vect)
{
  char stringX[4]; // String for converted numbers by itoa()
  char stringY[4]; // String for converted numbers by itoa()
  
  uint16_t valueX;
  uint16_t valueY;
  uint8_t channel = 0;
  
  lcd_gotoxy(0, 0);
  lcd_puts("JOY");
  /* address shifting ADMUX -----------------------------------------*/

  if (channel == 0){
    // Select input channel ADC0 (voltage divider pin)
    ADMUX = ADMUX & ~( 1<<MUX3 | 1<<MUX2 | 1<<MUX0 | 1<<MUX1);
    ADCSRA = ADCSRA | (1<<ADSC);
    // Read converted value
    // Note that, register pair ADCH and ADCL can be read as a 16-bit value ADC
    valueX = ADC;

     // Convert "value" to "string" and display it
    itoa(valueX, stringX, 10);
    lcd_gotoxy(4,0);
    lcd_puts("       ");
    lcd_gotoxy(4,0);
    lcd_puts("X:");
    lcd_gotoxy(6,0);
    lcd_puts(stringX);

    channel = 1;
  }
  if (channel == 1){
    // Select input channel ADC1 (voltage divider pin)
    ADMUX &= ~((1<<MUX3 | 1<<MUX2 | 1<<MUX1)); ADMUX |= (1<<MUX0);
    ADCSRA = ADCSRA | (1<<ADSC);
    // Read converted value
    // Note that, register pair ADCH and ADCL can be read as a 16-bit value ADC
    valueY = ADC;
    
    // Convert "value" to "string" and display it
    itoa(valueY, stringY, 10);
    lcd_gotoxy(10,0);
    lcd_puts("       ");
    lcd_gotoxy(10,0);
    lcd_puts("Y:");
    lcd_gotoxy(12,0);
    lcd_puts(stringY);

    channel = 0;
  }
  
}
