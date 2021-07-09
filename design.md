# Playstation/Discord Audio Mix Box Design

## High Level Overview

## Hardware
Since I'm making multiple boxes, I'm going to do the hardware board as a custom PCB.  The various blocks:
* Battery and Power switch
* Audio Mixing
* Light Control 
* Microphone Routing and Mute Switch

### Overall Schematic
<img width="525" alt="Screen Shot 2021-07-09 at 9 18 10 AM" src="https://user-images.githubusercontent.com/43499190/125100867-d1880280-e096-11eb-8e85-d1c7bcaf3b77.png">

Note that I've got two different grounds:  
*  GND for the audio signal
*  GNDREF for power
This should help isolate the audio from "pops and clicks" due to any fluctuations on the power circuit.

The top section is our audio mix circut; almost identical to the prototype version, with the exception that the Mic signal goes through a mute switch (SW1).  The other pole of this mute switch goes to the ATTINY85 processor.

The bottom section is our ATTINY85 processor, with power and LED.

### Component Selection
#### Battery
I'm going to use a standard 2032 coin cell.  The following battery holders are available on Amazon:
https://www.amazon.com/gp/product/B08SQJJJNK/ref=ppx_yo_dt_b_asin_title_o09_s00?ie=UTF8&psc=1

#### Audio Cables and Jacks
All of the audio cables are going to be TRRS cables (Tip/Ring/Ring/Shield).  The following jacks are available on Amazon:
https://www.amazon.com/gp/product/B089222S84/ref=ppx_yo_dt_b_asin_title_o07_s00?ie=UTF8&psc=1

The pinout is as follows:
| pin | name | color | 
|-----|-----|-----|
| 2 | L | white |
| 3 | R | red |
| 4 | Gnd | Black |
| 1 | Mic | Green |

```
 2  3  4  1  ___
 __ __ __ __|
(__|__|__|__|
            |___
            
```


#### Power Switch
I'm using a simple SPST switch for power:
https://www.amazon.com/gp/product/B08JYV8HZ7/ref=ppx_yo_dt_b_asin_title_o01_s00?ie=UTF8&psc=1

#### Mute Switch
I need the mute switch to do two things:
* break the microphone path
* give the ATTINY a signal to detect whether we're muted or not.

Because of this, I'm choosing a Dual-Pole-Single-Throw switch.  One end goes through the Mic path, one end goes to the ATTINY.
https://www.amazon.com/gp/product/B07QS8K8T2/ref=ppx_yo_dt_b_asin_title_o09_s00?ie=UTF8&psc=1

Note that the ATTINY does not have pull-up resistors on it's input, so I've got R5 on the board for that purpose.

### PCB Layout
The final PCB layout is as follows:
<img width="1009" alt="Screen Shot 2021-07-09 at 9 51 16 AM" src="https://user-images.githubusercontent.com/43499190/125105089-4f4e0d00-e09b-11eb-9d6f-4b0acd7992e0.png">

Note I'm only going Through-Hole parts here; no SMT assembly from the PCB vendor.

## Software

## Plastics
