### Team members:

* Martin Kováč 
  (responsible for )
* Lukáš Kudrna 
  (responsible for )
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

Pins (4 to 7):

### LCD Display

In project we use Digilent Pmod CLP type of display.

![image](https://user-images.githubusercontent.com/99397107/208475575-fb0275c5-837c-48a2-95b8-ad3fa28e1195.png)


### Servo motor SG90

![image](https://user-images.githubusercontent.com/99397107/208475296-6c30ba24-3230-40fc-b43e-f81d56fa7923.png)

![image](https://user-images.githubusercontent.com/99397107/208473686-af5cdb99-ddcb-4c06-9ea9-8a25f7682b6b.png)

## Software description

### SimulIDE
Our project is created with help of using free to use software [SimulIDE](https://www.simulide.com/).

In the software we can simulate many virtual processes. We used it especially for simulating Arduino Uno microcontroller and other components.
The simulators virtual components served the purpose as real hardware parts.

#### Servomotor flowchart 
![joystick drawio](https://user-images.githubusercontent.com/99397107/206262503-7c842613-7dab-4721-96d7-a3c62a214442.png)




In the code we used several libraries, which we used in computer exercises, e.g. timer, gpio and lcd.

1. **Timer:** [timer.h](https://github.com/xsedla1y/digital-electronics-2/blob/main/Project2/include/timer.h)
 2. **Gpio:** [gpio.c](https://github.com/LukerCZ/digital-electronics-2/blob/main/Project2/lib/gpio/gpio.c), [gpio.h](https://github.com/LukerCZ/digital-electronics-2/blob/main/Project2/lib/gpio/gpio.h)
 3. **LCD:** [lcd.c](https://github.com/LukerCZ/digital-electronics-2/blob/main/Project2/lib/lcd/lcd.c), [lcd.h](https://github.com/LukerCZ/digital-electronics-2/blob/main/Project2/lib/lcd/lcd.h), [lcd_definitions.h](https://github.com/LukerCZ/digital-electronics-2/blob/main/Project2/lib/lcd/lcd_definitions.h)
 4. **Source:** [main.c](https://github.com/LukerCZ/digital-electronics-2/blob/main/Project2/src/main.c)

## Video

[YOUTUBE] (https://youtu.be/-ML_NZQIerQ)

## References

1. [Rotary encoder](https://howtomechatronics.com/tutorials/arduino/rotary-encoder-works-use-arduino/)  
2. [Analog Joystick](https://www.electronicwings.com/arduino/analog-joystick-interfacing-with-arduino-uno)
3. [doc.Tomas Fryza - Github repository](https://github.com/tomas-fryza/digital-electronics-2)
4. [LCD Display TME.eu](https://www.tme.eu/en/details/410-142p/add-on-boards/digilent/pmodclp/)
5. [Pmod CLP Digilent.com](https://digilent.com/reference/pmod/pmodclp/start)
