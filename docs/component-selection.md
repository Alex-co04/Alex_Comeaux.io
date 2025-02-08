# Component Selection

## Introduction
The purpose of this project is to create an interactive and educational product for k-12 students to learn about weather and the weather cycle. In order to accomplish this, my subsystem comprises of a solar tracking array, consisting of a microcontroller, motor, motor driver, and light sensor. These components will all interface with the other subsystems and actively track either the most intense light in the environment, or track the position of the sun itself via local weather data.


## Criteria

In order for this project to be successful, there are many criteria that must be met. Most importantly, the device must be functional and functional for long enough to serve as a useful teaching tool. In order to accomplish this, parts must be selected with quality and robustness in mind. Furthermore, the budget must be taken into consideration as well. If parts get too expensive, it is easy to exceed the projected budget. But most importantly, the parts were selected with compatability in mind. If the parts struggle to interface with each other, we will create unnecessary roadblocks for our team further down the line. Overall, the criteria for each selected part included quality, cost, and compatability among other things. 

# Components 

## Microcontroller
### Option 1
| **Option** | **Pros** | **Cons** | **Unit Cost & Link** |
| --- | --- | --- | --- |
| **PIC16F18875**   | Multiple timers, hardware PWM, and various communication peripherals  |No WiFi/Bluetooth | $1.82 (DigiKey)(https://www.digikey.com/en/products/detail/microchip-technology/PIC16F18875-I-PT/5803538)
| |  Supports I2C  |Limited RAM compared to ESP32
| | Reliable MPLAB XC8 & MCC support  |
| | 5V operation (compatible with most motor drivers)|

### Option 2
| **Option** | **Pros** | **Cons** | **Unit Cost & Link** |
| --- | --- | --- | --- |
| **PIC18F47Q10**   | includes multiple timers, Configurable Logic Cells (CLC), ADCs, comparators, and communication modules (I2C, SPI, EUSART)  |No WiFi/Bluetooth | $2.52 (DigiKey)(https://www.digikey.com/en/products/detail/microchip-technology/PIC18F47Q10-I-P/10187785)
| |  better power management modes and improved performance  |Limited RAM compared to ESP32
| | supported by the MPLAB® Snap In-Circuit Debugger/Programmer  |
| | 5V operation (compatible with most motor drivers)|

### Option 3
| **Option** | **Pros** | **Cons** | **Unit Cost & Link** |
| --- | --- | --- | --- |
| **PIC16F877A**   | You can program and debug it via ICSP |No WiFi/Bluetooth | $1.82 (DigiKey)(https://www.digikey.com/en/products/detail/microchip-technology/PIC16F877A-I-P/446143)
| |  Very popular MCU to use, a lot of support online  |may need to write lower-level code to manage interrupts or to generate precise step timing
| | Can run on very little power  |
| | 5V operation (compatible with most motor drivers)|

## Final Selection: PIC16F18875 (Option 3)
#### Rationale:
The microcontroller I decided to use for this project was the PIC16F18875, as there is an abundance of resources and information online,  There also more examples online on how to use a stepper driver with this PIC controller than any other PIC controller. In addition to this, although a slightly older model, the microcontroller is fully compatible with MPLabX and the Snap debugger.


## Actuator
### Option 1
| **Option** | **Pros** | **Cons** | **Unit Cost & Link** |
| --- | --- | --- | --- |
| **1528-1367-ND**   | Very common and widely supported by a variety of stepper drivers like the A4988 |Slightly expensive| $14.00 (Adafruit) (https://www.adafruit.com/product/324)
| |  Offers a good balance between torque and size/weight  |Potentially No Integrated Gearbox
| | Mid range torque  |
| | 9-12V (compatible with most motor drivers)|


### Option 2
| **Option** | **Pros** | **Cons** | **Unit Cost & Link** |
| --- | --- | --- | --- |
| **N20 DC Motor with Magnetic Encoder**   | Common low-torque DC motor, online resources |Requires a microcontroller with interrupts or high-speed polling to read the encoder signals correctly.| 12.50 (Adafruit) (https://www.adafruit.com/product/4638)
| |  Cheaper than other options | More difficult to make precise movements, coding may be trickier
| | 1:50 gearbox significantly increases torque output while reducing speed  | 
| | 6V operational voltage|

## Final Selection: 1528-1367-ND (Option 1)
#### Rationale:
The actuator I decided to go with for this project is option 1, the Nema 14 stepper motor. This option is the most realistic as it will be easiest to interface with a stepper driver and PIC microcontroller. Additonally, this actuator is the easiest to use in terms of precise movement.  

## Motor Driver
### Option 1
![Image:A4988](docs\assets\images\620~28QFN-1-5X5~ET~28_web(640x640).jpg)
| **Option** | **Pros** | **Cons** | **Unit Cost & Link** |
| --- | --- | --- | --- |
| **A4988**   | Designed for bipolar stepper motors |Overheats quickly at higher currents| $4.26 (Digikey) (https://www.digikey.com/en/products/detail/allegro-microsystems/A4988SETTR-T/2237991?s=N4IgTCBcDaIIIBYCcAOFIC6BfIA) 
| |  Requires only two control signals | No reverse voltage protection 
 | | Functional with a wide range of motors  | 
| | 8-35V | 

### Option 2
| **Option** | **Pros** | **Cons** | **Unit Cost & Link** |
| --- | --- | --- | --- |
| **ULN2003**   | Can drive multiple loads |Overheats very quickly at higher currents| $.43 (Digikey) (https://www.digikey.com/en/products/detail/stmicroelectronics/ULN2003A/599603)
| |  Protects against voltage spikes from inductive loads | Designed only for unipolar motors
| | Cost effective  |
| | 6-50V |

## Final Selection: A4988 (Option 1)
#### Rationale:
I concluded that this driver was the most suitable for my project because most of the online resources on how to control stepper motors used this particular driver. Additionally, although it lacks reverse voltage protection, it is not difficult to implement flyback diodes. 

## Light Detection 
### Option 1
| **Option** | **Pros** | **Cons** | **Unit Cost & Link** |
| --- | --- | --- | --- |
| **PDV-P9203 Photo-resistor**   | Cost effective |Tolerance in resistance varies, requires tuning| $1.15 (Digikey) (https://www.digikey.com/en/products/detail/advanced-photonix/PDV-P9203/480628?s=N4IgTCBcDaIAoBEBqBaOBOMAGAzCAugL5A)
| |  Simple to interface | Slow response time
| | Wide dynamic range, good for detecting most visible wavelengths  |
| 

### Option 2
| **Option** | **Pros** | **Cons** | **Unit Cost & Link** |
| --- | --- | --- | --- |
| **TEPT4400 Phototransistor**   | Faster response time |More difficult to implement, more surrounding circuitry| $.48 (Digikey) (https://www.digikey.com/en/products/detail/stmicroelectronics/ULN2003A/599603)
| |  More linear and consistent readings | Designed only for unipolar motors
| | Extremely cost effective  | Narrower wavelength sensitivity
| 

## Final Selection: PDV-P9203 Photo-resistor (Option 1)
#### Rationale:
I decided that the best visible light detector for the solar array is the PDV-P9203 Photo-resistor. This is because it will be the easiest to interface with the PIC microcontroller. Additionally, there are many example project online using the same photo-resistor. 

## Basic MCC Setup
![Image:MCC](docs\assets\images\image_2025-02-07_183502901.png)

This is my rudamentary setup for the microcontroller's MCC in MPLabX. As you can see, there are pins designated for the ADC (sensor reading), PWM (motor control) and UART (communication with other subsystems)