### Team members:

* Martin Kováč 
  (responsible for programing, creating video and simulation in SimulIde)
* Lukáš Kudrna 
  (responsible for project documentation, flowcharts)
##  Project assignment

Precise generation of several PWM channels. Application of two (or more) Servo motors SG90.

## GitHub repository structure

   ```c
   Project1       // PlatfomIO project
   ├── include         // Included files
           └── timer.h
   ├── lib             // Libraries
        └── gpio
              └── gpio.c
              └── gpio.h
        └── lcd
              └── lcd.c
              └── lcd.h
              └── lcd_definitions.h
        └── uart
              └── uart.c
              └── uart.h
   ├── src             // Source file(s)
   │   └── main.c
   ├── platformio.ini  // Project Configuration File
   └── README.md       // Report of this project
   ```

## Hardware description

### Arduino UNO

Arduino UNO is main part of our project for practical solution. The board is based on ATMega328 microcontroller and was developed by [Arduino.cc](https://www.arduino.cc/). The pinout consist of 14 digital I/O pins, 6 analog pins and power pins.

#### Arduino UNO pinout
![ArduinoUNO pinout](https://user-images.githubusercontent.com/99397107/206240652-9ad594d9-998e-4e33-b061-4f60213628ff.png)

#### In Project we are using these pins:

Button: Pin (8)

Servomotor 1: Pin (9)

Servomotor 2: Pin (9)

Ground,Vcc: Power pins (+5V, GND)

### Servo motor SG90

![image](https://user-images.githubusercontent.com/99397107/208475296-6c30ba24-3230-40fc-b43e-f81d56fa7923.png)

## Software description

### SimulIDE
Our project is created with help of using free to use software [SimulIDE](https://www.simulide.com/).

<img width="689" alt="Snímka obrazovky 2022-12-20 o 20 33 32" src="https://user-images.githubusercontent.com/99388246/208751347-dfae1fe9-9d9e-4f8b-bdec-0ff0257522d8.png">

In the software we can simulate many virtual processes. We used it especially for simulating Arduino Uno microcontroller and other components.
The simulators virtual components served the purpose as real hardware parts.
 
#### Flowchart when button is pressed

![image](https://user-images.githubusercontent.com/99397107/208764260-d91511ac-0e73-4ae4-8827-4dce693f1f3a.png)

#### Flowchart for PCINT0_vect interupt
![image](https://user-images.githubusercontent.com/99397107/208769777-12fc2d50-8d07-4206-9259-e8857f3967ad.png)

In the code we used several libraries, which we used in computer exercises, e.g. timer, gpio and lcd.

1. **Timer:** [timer.h](https://github.com/xsedla1y/digital-electronics-2/blob/main/Project2/include/timer.h)
 2. **Gpio:** [gpio.c](https://github.com/LukerCZ/digital-electronics-2/blob/main/Project2/lib/gpio/gpio.c), [gpio.h](https://github.com/LukerCZ/digital-electronics-2/blob/main/Project2/lib/gpio/gpio.h)
 3. **LCD:** [lcd.c](https://github.com/LukerCZ/digital-electronics-2/blob/main/Project2/lib/lcd/lcd.c), [lcd.h](https://github.com/LukerCZ/digital-electronics-2/blob/main/Project2/lib/lcd/lcd.h), [lcd_definitions.h](https://github.com/LukerCZ/digital-electronics-2/blob/main/Project2/lib/lcd/lcd_definitions.h)
 4. **Source:** [main.c](https://github.com/LukerCZ/digital-electronics-2/blob/main/Project2/src/main.c)

## Video

[YOUTUBE](https://youtu.be/c5YOwA-SAN4)

## References

1. [doc.Tomas Fryza - Github repository](https://github.com/tomas-fryza/digital-electronics-2) 
2. [Analog Joystick](https://www.electronicwings.com/arduino/analog-joystick-interfacing-with-arduino-uno)
3. [Servomotor](https://navody.dratek.cz/arduino-projekty/servo-motor.html)


