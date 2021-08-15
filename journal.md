# 3/1/21
First order of buisness: see how the plugs are wired.  

From the specs, sometimes Shield is GND, sometimes Mic. Gonna need to measure phones (android and apple), PC, and playstation. Just in case, could design in a jumper to route those two.  Diagram below:

```
 T  R1 R2  S ___
 __ __ __ __|
(__|__|__|__|
            |___
            

Measured on my Mac and HTC headset:
------------------ 
Tip is L audio
R1  is R audio
R2 is GND
S  is Mic
```
I'm a little worried that the iPhone is gonna be wired differently, as Apple tends to do things their own way...but the Mac is wired the same as the android phone (and playstation controller), so that's less risk.  Will send a prototype out to Lamonte (who has iPhone) and let him test it.

# 3/4/21

Before I jump into my design, there are some prototyping things I need to do.

I'm comfortable with the ATTINY driving an LED and also using a mute switch.  Ready to go to design on those.

I need to figure out how to mix the audio signals together.  I have two options, listed below.

### Simple Audio Mix:  a bunch of 470 ohm resistors
The easiest solution is to do passive mixing...basically connecting each channel together with resistors.  Looking online, the resisitor value is dependent on the output impedence, and looks like 470 ohm will do the trick for my headphone example.  
Here is the circuit:
<img width="793" alt="Screen Shot 2021-03-04 at 4 13 15 PM" src="https://user-images.githubusercontent.com/43499190/110043543-cb5ad180-7d04-11eb-9ea3-f7a5ee9c64b0.png">

Pros:  Very simple!  Not too many components.  Doesn't require power.

Cons:  I'm going to lose a little volume from each channel.

### Mix with Gain
If I want to add gain to the system, I'm going to need an amplifier.  In the past I've used a generic LM324 Op Amp, but the LM386 looks like it's custom made for what I want.  Cool amplifier link here:
https://www.circuitbasics.com/build-a-great-sounding-audio-amplifier-with-bass-boost-from-the-lm386/

I'm going to do a bread-boarded prototype with two channels, then summed with the resistors as above.  Implementation will have a dual gang potentiometers to hit both channels.

Pros:  able to control gain via the knobs on the box rather than going to PS & Discord to seperately tweak the levels.

Cons:  MUCH more complicated.  Requires a bigger battery to drive (9v?).

## Simple Audio Mix Prototype:
Picture of the breadboarded circuit:
![image](https://user-images.githubusercontent.com/43499190/129491882-0654f6c9-808d-4524-b53c-f12bdc97f64a.png)


Results: worked well.  Audio loss was able to be compensated by Discord and PS apps on either side...but there still was loss.

# 3/7/21
Next iteration: single channel gain stage combining.  Specifically, taking the R channel from two sources (PS and Discord), applying seperate gains (controlled by the two knobs), and then combining the output signal like in the previous experiment.  Picture of the breadboarded prototype:
![image](https://user-images.githubusercontent.com/43499190/129492040-3f090b2a-572e-473c-9bac-581dabf5c007.png)

Results:  worked fairly well....but going to two channels means circuitry gets a little more complicated...and I'm worried about pops and clicks (got a few just on the breadboard)  

Plan:  I'm gonna shelve this one, and proceed with the simple mix for our product.

# 3/11/21
Soldered up prototype to send out to Lamonte for iPhone testing:
![image](https://user-images.githubusercontent.com/43499190/129492160-e8814de0-2c37-4701-bde0-f22fd5ced333.png)

# 3/20/21
Spun a simple case...pics below:
![image](https://user-images.githubusercontent.com/43499190/129492234-872ef8e3-7fdd-4971-ab38-52e311f8b740.png)

![image](https://user-images.githubusercontent.com/43499190/129492241-6c5cddb9-f984-414a-bc37-70d06bb38001.png)

# 3/30/21
Prototype box mailed out to Lamonte!

# 4/2/21
Tested the box with Lamonte...me on the breadboarded version, him with the prototype via iPhone.

IT WORKED!!!

Now, time to spin the schematic via kicad.

# 4/10/21
Board spin complete; sent to JLCPCB.

# 4/11/21
Plastics thoughts:
* Gotta be able to get to the battery...meaning I want the bottom removable via heat-sets.
* Need to label the jacks.  In a pinch, I can do the label maker like with Lamonte's board...but I want something a little "better".  Gonna try embossing the letters vertically...I think the uPrint can deal with that.
* Ideally, I want the "ghost" a different color...meaning a different plastic print.  I'll design it in so that there's a "shelf" on the top for it to fit into....and I need a square hole for the LED board to shine through.
* For the ghost "eye", I'm just gonna cut a piece of 1/8 wood from the laser cutter (cheaper!) and glue it in place.  If I need it, I'll use a piece of that whiteish LED diffusing acrylic.

# 4/12/21
Stopped by Dawson:  printed outer shell.  Yellow is the color in the printer.

# 4/13/21
Shell happy...uPrint in use by others, so I printed the ghost on the Raise3D.  

Now I just need the boards to come back...

# 4/15/21
JLCPCB build complete...boards on their way back to me.

# 4/21/21
Got the boards back from JLCPCB!!!  First assembly pics:


