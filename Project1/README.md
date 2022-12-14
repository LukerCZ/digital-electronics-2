### Team members:

* Martin Kováč 
  (responsible for programing encoder, joystick, flowchart diagrams, editing video documentation)
* Lukáš Kudrna 
  (responsible for programing LCD display, creating video, hardware description)
##  Project assignment

Application of analog joy-stick (2 ADC channels), rotary encoder, and Digilent PmodCLP LCD module.

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
- for sending data to LCD display

Pins 8,9:
- used for command signals and read or write decisions 

Pins 10,11:
- used for figuring direction of rotation from rotary encoder

Pins A0,A1:
- used for figuring direction of X and Y axis from joystick

### Rotary Encoder

A rotary encoder is a type of position sensor which is used for determining the angular position of a rotating shaft.
#### How is it working?


![image](https://user-images.githubusercontent.com/99397107/206248116-1297b669-9691-44b1-a153-a8a07bf2b787.png)

On the picture above there are two output signals which are phased by 90 degrees between each other.
If we compare both signals at the moment there can be two states: 

Opposite values (A != B): Encoder is rotating clockwise 

Same values (A = B): Encoder is rotating counter-clockwise

For better imagination you can see picture below:

![image](https://user-images.githubusercontent.com/99397107/206248205-ba340ce6-1494-4b53-9a13-c28b3af4bf72.png)

#### Picture of Rotary encoder

![image](https://user-images.githubusercontent.com/99397107/206244784-1666e0fa-362f-454a-a951-e469fa56a3ee.png)


### Joystick

Joystick consist of two potenciometers which decide on what position is joystick turned. By reading a values from potenciometers we can convert this into position of X and Y axis.  

#### Picture of Joystick

![image](https://user-images.githubusercontent.com/99397107/206244863-2d7fd3a4-f4a9-4f3d-81b2-08b04868e658.png)


### Digilent PmodCLP LCD module

The Digilent Pmod CLP  is a 16×2 character LCD module that uses a 8-bit parallel data interface to let system boards display up to 32 different characters out of over 200 possible options.

LDC (liquid-crystal display) is a flat-panel display that uses the light-modulating properties of liquid crystals combined with polarizers. Liquid crystals do not emit light directly but instead use a backlight or reflector to produce images in color or monochrome.


#### Picture of Digilent PmodCLP LCD module

![image](https://user-images.githubusercontent.com/99397107/206245679-0a12edba-6958-43a8-bd3e-b9093a0d50b6.png)


### Schematic done in SimulIDE (see below)
![image](https://user-images.githubusercontent.com/99388246/206135543-d520f35a-fe99-46e8-9b13-a4d9bda0a5a3.png)

## Software description

### SimulIDE
Our project is created with help of using free to use software [SimulIDE](https://www.simulide.com/).

In the software we can simulate many virtual processes. We used it especially for simulating Arduino Uno microcontroller and other components.
The simulators virtual components served the purpose as real hardware parts.

#### Joystick flowchart 
![joystick drawio](https://user-images.githubusercontent.com/99397107/206262503-7c842613-7dab-4721-96d7-a3c62a214442.png)


#### Encoder flowchart
![Encoder_flowchart](https://user-images.githubusercontent.com/99388246/206261689-cbcd090a-0ae1-46d7-9212-aeac0e6bc2cd.png)

In the code we used several libraries, which we used in computer exercises, e.g. timer, gpio and lcd.

1. **Timer:** [timer.h](https://github.com/xsedla1y/digital-electronics-2/blob/main/Project1/include/timer.h)
 2. **Gpio:** [gpio.c](https://github.com/LukerCZ/digital-electronics-2/blob/main/Project1/lib/gpio/gpio.c), [gpio.h](https://github.com/LukerCZ/digital-electronics-2/blob/main/Project1/lib/gpio/gpio.h)
 3. **LCD:** [lcd.c](https://github.com/LukerCZ/digital-electronics-2/blob/main/Project1/lib/lcd/lcd.c), [lcd.h](https://github.com/LukerCZ/digital-electronics-2/blob/main/Project1/lib/lcd/lcd.h), [lcd_definitions.h](https://github.com/LukerCZ/digital-electronics-2/blob/main/Project1/lib/lcd/lcd_definitions.h)
 4. **Source:** [main.c](https://github.com/LukerCZ/digital-electronics-2/blob/main/Project1/src/main.c)

## Video

[YOUTUBE] (https://youtu.be/-ML_NZQIerQ)

## References

1. [Rotary encoder](https://howtomechatronics.com/tutorials/arduino/rotary-encoder-works-use-arduino/)  
2. [Analog Joystick](https://www.electronicwings.com/arduino/analog-joystick-interfacing-with-arduino-uno)
3. [doc.Tomas Fryza - Github repository](https://github.com/tomas-fryza/digital-electronics-2)
4. [LCD Display TME.eu](https://www.tme.eu/en/details/410-142p/add-on-boards/digilent/pmodclp/)
5. [Pmod CLP Digilent.com](https://digilent.com/reference/pmod/pmodclp/start)
