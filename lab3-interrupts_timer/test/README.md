# Lab 3: Lukáš Kudrna

### Overflow times

1. Complete table with overflow times.

   | **Module** | **Number of bits** | **1** | **8** | **32** | **64** | **128** | **256** | **1024** |
   | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |
   | Timer/Counter0 | 8  | 16u | 128u | -- | 1024u | -- | 4096u | 16384u |
   | Timer/Counter1 | 16 | 4096u | 32768u | -- | 262144u | -- | 1048576u | 4194304u |
   | Timer/Counter2 | 8  | 16u | 128u | 512u | 1024u | 2048u | 4096u | 16384u |

### Interrupts

2. In `timer.h` header file, define macros also for Timer/Counter2. Listing of part of the header file with settings for Timer/Counter2. Always use syntax highlighting, meaningful comments, and follow C guidelines:

   ```c
   /** @brief Stop timer, prescaler 000 --> STOP */
   #define TIM0_stop()  TCCR0B &= ~((1<<CS02) | (1<<CS01) | (1<<CS00));

   /** @brief Set overflow 16ms, prescaler // 101 --> 1024 */
   #define TIM0_overflow_16ms()    TCCR0B &= ~(1<<CS01); TCCR0B |= (1<<CS02) | (1<<CS00);

   /** @brief Set overflow 4ms, prescaler 100 --> 256 */
   #define TIM0_overflow_4ms()    TCCR0B &= ~((1<<CS01) | (1<<CS00)); TCCR0B |= (1<<CS02);

   /** @brief Enable overflow interrupt, 1 --> enable */
   #define TIM0_overflow_interrupt_enable()  TIMSK0 |= (1<<TOIE0);
   /** @brief Disable overflow interrupt, 0 --> disable */
   #define TIM0_overflow_interrupt_disable() TIMSK0 &= ~(1<<TOIE0);
   ```
