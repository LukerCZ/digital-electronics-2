# Lab 1: Lukáš Kudrna

### Morse code

1. Listing of C code which repeats one "dot" and one "comma" (BTW, in Morse code it is letter `A`) on a LED. Always use syntax highlighting, meaningful comments, and follow C guidelines:

```c
/* Defines -----------------------------------------------------------*/
#define LED_RED PB0   // PB5 is AVR pin where red on-board LED 
                        // is connected
#define SHORT_DELAY 400 // Delay in milliseconds
#define PAUSE 300 // Delay in milliseconds
#define LONG_DELAY 600 // Delay in milliseconds
#ifndef F_CPU
# define F_CPU 16000000 // CPU frequency in Hz required for delay funcs
#endif

int main(void)
{
    // Set pin where on-board LED is connected as output
    pinMode(LED_RED, OUTPUT);

    // Infinite loop
    while (1)
    {
        // Generate a letter `A` Morse code

        // Change LED value
        digitalWrite(LED_RED, HIGH);
        _delay_ms(SHORT_DELAY);
        digitalWrite(LED_RED, LOW);
         _delay_ms(PAUSE);
        digitalWrite(LED_RED, HIGH);
        _delay_ms(LONG_DELAY);
        digitalWrite(LED_RED, LOW);
        _delay_ms(PAUSE);
        

    }

    // Will never reach this
    return 0;
}
```

2. Scheme of Morse code application, i.e. connection of AVR device, LED, resistor, and supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values!


![image](https://user-images.githubusercontent.com/99397107/193883745-95ea8745-7ec5-4557-a7ef-8934230da848.png)


![image](https://user-images.githubusercontent.com/99397107/193882626-76f157fc-156d-401a-9e00-6a86cf10355c.png)
