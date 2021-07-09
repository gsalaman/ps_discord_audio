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

#### LED
I'm using a custom board with a single WS2812 LED.  It's able to be driven by the coin cell and the ATTINY.  The WS2812 will let me change colors on the LED.

### PCB Layout
The final PCB layout is as follows:
<img width="1009" alt="Screen Shot 2021-07-09 at 9 51 16 AM" src="https://user-images.githubusercontent.com/43499190/125105089-4f4e0d00-e09b-11eb-9d6f-4b0acd7992e0.png">

Note I'm only going Through-Hole parts here; no SMT assembly from the PCB vendor.

## Software
The ATTINY will have two modes of operation:
* When the mute switch is active (Muted), it'll blink the LED red.
* When the mute switch is not active (Not Muted), it'll cycle the LED through colors.

I'll be using the Arduino environment to program the ATTINY85.

### High Level Software Overview
I'll use Adafruit's NeoPixel library to program the LED.  

I'm going to use a global "tick_number" indicator to count time.   

I'll have globals for the Red/Green/Blue pixel values for when we're cycling through colors.  

The "setup" function will set up the  pins for Mute and LED.  

The "loop" function will read the Mute button, and choose between the following functions:
* Flash the LED red (muted)
* cycle through colors (non-muted)

"Loop" will also need to keep track of the last state of the mute button.  This is because when we first turn OFF mute (Un-mute), we want the cycle colors to reset to a known starting point.

### Muted Operation
We'll use the "tick_number" and a modulus funcition to alternate between setting the LED to all red or off.  I'll experiement with time values to see what looks good.

### Un-Muted Operatoin
This one will be a little tricker.  Here's the cycle algorithm:
```
Start with the LED Blue.
Step 1: Slowly decrease the Blue RGB value and increase the Green RGB value until the LED is all Green.
Step 2: Slowly decrease the Green RGB value and increase the Red RGB value until the LED is all Red.
Step 3:  Slowly Decrease the Red RGB value and increase the Blue RGB value until the LED is all Blue.
```
To determine which "step" we're on, I'll cycle the tick number.  Since each color value is going from 255 to 0 (or vice versa), I have 256 "ticks" in each step.

## Plastics
I'm going to design the case in three pieces:
* The "shell" will be the walls and the top, with holes for switches, heat-sets (to attach the bottom), jacks and the ghost.  I'll label the Jacks via embossed letters.
* The "bottom" will be a simple rectange that gets screwed onto the bottom of the case (and gives the user access to replacing the battery).
* The "Ghost" will be a contrasting color, modelled after destiny's Ghost.  I'll use a seperate piece of diffusing acrylic (laser-cut) to "spread out" the light of the led.  This will be glued onto the top.

Onshape files can be found here:
https://cad.onshape.com/documents/8eac8258773643f40666c139/w/5a93e26a0a6b1984f3ee80b1/e/b21e37a20e72b8d13801b5df

