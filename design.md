# Playstation/Discord Audio Mix Box Design

## High Level Overview

## Hardware
Since I'm making multiple boxes, I'm going to do the hardware board as a custom PCB.  The various blocks:
* Battery and Power switch
* Audio Mixing
* Light Control 
* Microphone Routing and Mute Switch

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


#### Power Switch:
https://www.amazon.com/gp/product/B08JYV8HZ7/ref=ppx_yo_dt_b_asin_title_o01_s00?ie=UTF8&psc=1

#### Mute Switch:
https://www.amazon.com/gp/product/B07QS8K8T2/ref=ppx_yo_dt_b_asin_title_o09_s00?ie=UTF8&psc=1


### Schematic and Block Descriptions
<img width="525" alt="Screen Shot 2021-07-09 at 9 18 10 AM" src="https://user-images.githubusercontent.com/43499190/125100867-d1880280-e096-11eb-8e85-d1c7bcaf3b77.png">



### PCB Layout

## Software

## Plastics
