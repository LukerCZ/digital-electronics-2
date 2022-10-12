#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include <gpio.h>           // GPIO library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC

#define LED_GREEN PB5
#define LED_RED PB0

int main(void)
{
    GPIO_mode_output(&DDRB, LED_GREEN);  
    GPIO_mode_output(&DDRB, LED_RED); 
    // Enable overflow interrupt
    TIM1_overflow_1s();
    TIM1_overflow_interrupt_enable();
    
    TIM0_overflow_4ms();
    TIM0_overflow_interrupt_enable();
    // Enables interrupts by setting the global interrupt mask
    sei();
    
    while (1)
    {
    
    }
}

// Interrupt service routines
ISR(TIMER1_OVF_vect)
{
   PORTB = PORTB ^ (1<<LED_GREEN);
  
}
/*ISR(TIMER0_OVF_vect)
{
   
   PORTB = PORTB ^ (1<<LED_RED);
}*/

ISR(TIMER0_OVF_vect)
{
    static uint8_t no_of_overflows = 0;

    no_of_overflows++;
    if (no_of_overflows >= 4)
    {
      PORTB = PORTB ^ (1<<LED_RED);   
        // Do this every 6 x 16 ms = 100 ms
        no_of_overflows = 0;
        
    }
    TCNT0 = 128;
    // Else do nothing and exit the ISR
}