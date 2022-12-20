/* Includes ----------------------------------------------------------*/
#include "Arduino.h"
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include <util/delay.h>     // Functions for busy-wait delay loops
#include <gpio.h>           // GPIO library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <stdlib.h>         // C library. Needed for number conversions

// Define pins for servo
#define servo1 PB1 
#define servo2 PB2

// JOYSTICK button
#define button PB0 

// Servo default values
# define Servo_zero 124
# define Servo_90 260

uint32_t servo1_position = Servo_90;
uint32_t servo2_position = Servo_90;
uint8_t servo_move = 0;

int main(void)
{
  //Set pins with gpio library
  GPIO_mode_output(&DDRB, servo1);        // First servo motor
  GPIO_mode_output(&DDRB, servo2);        // Second servo motor
  GPIO_mode_input_pullup(&DDRB,button);  // Button with enabled pull-up resistor

  // Set PWM registers, PWM mode
  TCCR1A &= ~((1 << COM1A0) | (1 << COM1B0));
  TCCR1A |= (1 << WGM11) | (1 << COM1A1) | (1 << COM1B1);
  TCCR1B |= (1 << WGM13);
  // PWM period
  ICR1 = 20000;
  OCR1A = servo1_position;
  OCR1B = servo2_position;
  // Set prescalar
  TCCR1B |= (1 << CS11);


  // Set timer 0, enable interrupt
  TIM0_overflow_1ms();
  TIM0_overflow_interrupt_enable();

  sei();
    
    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines, ISRs */
    }

    // Will never reach this
    return 0;

}


ISR(TIMER0_OVF_vect)
{
    //Setup default direction for servo
    static uint8_t servo1_direction = 0;        
    static uint8_t servo2_direction = 0;
   
   //Servo 1
    if (servo_move == 0)                                                      
    {
        // Direction
        if (servo1_position == Servo_90)       
            {
                servo1_direction = 1;           
            }
        else if (servo1_position == Servo_zero) 
            {
                servo1_direction = 0;           
            }
        // Motion
        if (servo1_direction == 0)
        {
            servo1_position += 2;               
        }
        if (servo1_direction == 1)
        {
            servo1_position -= 2;                 
        }
        OCR1A = servo1_position;                
        }

    //Servo 2    
    if (servo_move == 1) 
    {
        // Direction
        if (servo2_position == Servo_90)       
        {
            servo2_direction = 1;               
        }
        else if (servo2_position == Servo_zero) 
        {
            servo2_direction = 0;               
        }
        // Motion
        if (servo2_direction == 0)
        {
            servo2_position += 2;                
        }
        if (servo2_direction == 1)
        {
            servo2_position -= 2;                  
        }
        OCR1B = servo2_position;                
    }
}

//Define which servo motor should move
ISR(PCINT0_vect)
{
    uint8_t sw1 = GPIO_read(&PINB, button);     
    if (sw1 == LOW)                                
    {
        if (servo_move == 1) 
        { 
            servo_move = 0;                            
        }
        else if (servo_move == 0) 
        { 
            servo_move = 1;
        }
    } 
}
