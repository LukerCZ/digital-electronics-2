#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include <gpio.h>           // GPIO library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC

int main(void)
{
    ...
    // Enable overflow interrupt
    TIM1_overflow_interrupt_enable();
    ...
    // Enables interrupts by setting the global interrupt mask
    sei();
    ...
}

// Interrupt service routines
ISR(TIMER1_OVF_vect)
{
    ...
}