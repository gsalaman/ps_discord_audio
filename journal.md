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
Got the boards back from JLCPCB!!!  Assembly pics below.

### The board:
![image](https://user-images.githubusercontent.com/43499190/129492856-9f4f2acf-d090-43e7-8322-fa1b654f796a.png)

### The other components:
![image](https://user-images.githubusercontent.com/43499190/129492897-9d98392c-cfc7-423a-904b-9a246235f63f.png)

Note that the rocker switch for the mute is already in the case...I did a test fit, as this one "snaps in".  Made soldering it a little more challenging...more on that below.

### The ghost:  
![image](https://user-images.githubusercontent.com/43499190/129492932-4366bc5d-5247-4945-b553-ab6f11d51835.png)
I used a black sharpie to "darken" the eye.

I used 5 minute epoxy to glue it all together...I'm gonna want to tweak the eye size (make it bigger) and "shield" size (make it even bigger) to make everything fit well.

### TRRS Jacks
The TRRS jacks were tricky.  They've got a 1-4 number on each pin, corresponding to which of the Tip/Ring/Shield they're connected to.  You'd think that 1 would be tip, 2 the next ring, 3 the next, and 4 shield....but no!  Here's the actual pinout:
| pin | name | color | 
|-----|-----|-----|
| 2 | L | White |
| 3 | R | Red |
| 4 | Gnd | Black |
| 1 | Mic | Green |

```
 2  3  4  1  ___
 __ __ __ __|
(__|__|__|__|
            |___
            
```
Here they are, prior to assembly:

![image](https://user-images.githubusercontent.com/43499190/129493174-9309836d-1bae-449c-8fda-ace06440c065.png)

Soldering the wires onto the pins without them shorting is tricky...I found it best to bend the wire into a "J", thread it into the jack hole so the wire is in the middle/core, do the soldering, then trim the excess of the J.  That gives you this:

![image](https://user-images.githubusercontent.com/43499190/129493232-c5667de3-2945-4fe6-9cdd-78e4e8f85a55.png)

### Board Front
Do through-hole soldering for the mixing and pull-up resistors, and solder on the 3 jacks:

![image](https://user-images.githubusercontent.com/43499190/129493284-4464afe5-22ff-4678-a504-fafd1ac3e955.png)

LED board and power switch go on next...some of those wires are under the battery holder.  

![image](https://user-images.githubusercontent.com/43499190/129493310-7a7ec8e2-14ed-4127-ba52-cd328a616619.png)

Note that I've also done 4 wires on the two poles of the mute switch...a little tricky to get into the case to hit these.  Next time, I do that soldering first, then snap the switch into place.

### Board Back
Then do the battery holder and socket for the ATTINY on the other side.

![image](https://user-images.githubusercontent.com/43499190/129493322-1d48dae7-3958-40ec-852d-c74bce6f122f.png)

### Last Steps
Next, test fit the board into the case.  Get the bends for all the wires about right...and then you can solder on the other side of the mute switch.

Do a "final positioning" of the LED to make sure it's centered in the diffusing plastic, and then glue the ghost on top of the case.

The final product:

![image](https://user-images.githubusercontent.com/43499190/129493059-a28e9654-4668-4736-af4b-a14f2844e8ee.png)

# 4/27/21
Today's mission:  Plastics colors!

I'm going to need to print at least 6 more cases for the clan...so that's a fair amount of plastics.

The uPrint is definitly the most solid, dependable printer.  Dawson has Orange, Red, Yellow, and Green...and you can order black.   Trouble here:  the spools are $180 each...a little pricey.

You can get LOADS of colors from Matterhackers for the Raise3d....and they're much cheaper...$20 a spool.  Here's what I'm gonna do:
* use [grey](https://www.matterhackers.com/store/l/175mm-pla-filament-grey-1-kg/sk/MPL0Q8ZD) for the case
* There's a cool [silver/blue](https://www.matterhackers.com/store/l/silky-teal-mh-build-series-pla-filament-175mm-1kg/sk/M4042W07) for the ghost.

I'll need support for the case, but the Raise3D can do water-soluable PVA.

# 5/12/21
Started printing in bulk.  Got one grey top done:

![image](https://user-images.githubusercontent.com/43499190/129494318-81669e6a-0141-4724-936b-555746525f3d.png)

Sizing looks good; ready to go in bulk!

# 5/16/21
Lara offered to help with assembly...we soldered up a bunch of boards today.  Still waiting for the plastics for full assembly.  Pics below:

![image](https://user-images.githubusercontent.com/43499190/129494419-bc56b650-97c0-4129-b26f-0e197e8b635d.png)

![image](https://user-images.githubusercontent.com/43499190/129494424-a2e46b4d-d7e1-4eac-9833-46a111831642.png)


# 5/19/21
Print failures!!! 

![image](https://user-images.githubusercontent.com/43499190/129494365-f9cf269c-ad9b-490f-9dfc-8e810b0d6697.png)

![image](https://user-images.githubusercontent.com/43499190/129494372-90304f5e-fbef-48eb-a76f-795bbdaa749a.png)

I think its cause I did 50% infill and the layers didn't quite bond.  Gonna try 100% next time...

# 5/21/21
More assembly!  Still don't have the cases, but were able to put together a bunch more boards.  Pics:

![image](https://user-images.githubusercontent.com/43499190/129494468-3dc9c812-1d6e-4f4a-8ec8-6e5ef2934f98.png)

![image](https://user-images.githubusercontent.com/43499190/129494496-a74f7128-ea11-4355-90f7-92b2496f3e3c.png)

# 5/28/21
Tried another print...and had another failure!  Much like the one from the 19th...so it's not infill.  Hmmmm...

# 6/1/21
Tried another case print with Raise3D brand white just to change a variable...it mostly worked:

![image](https://user-images.githubusercontent.com/43499190/129494917-2abfa627-1749-4c01-b642-e3099a44bd10.png)

A little stringy-ness with the PVA...but the case is mostly smooth.

# 6/4/21
More print issues!  Tried just doing the ghost with the silky blue, and it stops extruding about half way through.  (second time caused a big jam)

Here's a pic of where one of them failed:

![image](https://user-images.githubusercontent.com/43499190/129494833-c8a2018a-7eff-43d2-9fe6-0905e1944d35.png)

Plan:  do full printer calibration with Chris on monday.

# 6/7/21
Chris and I are doing a full printer calibration...left-and-right nozzle heights, offsets, build leveling...anything that needs to be done.

Had some challenges:
* the Z-offset thumbscrew doesn't seem to do anything...there's a pin that goes to a sensor, but changing the thumbscrew doesn't change the pin.  Chris and I did the "coarse adjust" (not recommended) to get everything happy.
* When doing right nozzle height, it wasn't able to go up  high enough.
* The silky blue PLA still has the extrude problem...gets part way through the print, then jams.

I put in tickets with Raise3D and MatterHackers.

# 6/8/21
Matterhackers ticket response was to change temp and flowrate.  Tried that, same effect...material stops extruding.

Raise3D answers:
* Pin sometimes gets stuck.  Yup...that was it.
* Played around with heatsink position on right nozzle...got that happy as well.

Can now get the offset prints happy via dual extrude...so hopefully that'll help with the PVA.

# 6/10/21
Matterhackers had more experiments for me to try....but none of them were happy.  They refunded my $ on the spool.  Raise3D confirmed that matterhackers was having issues.  

Soooooo....I've got Raise3D filament in grey and blue ($35 each) to build out the ghosts.  Not the cool silky-blue, but if it extracts well, I'll deal...


# 6/13/21
Raise3D filament arrived.  And it just works:

![image](https://user-images.githubusercontent.com/43499190/129495089-3362fa6d-c0d5-489f-8cb9-1d8c6d262830.png)

Had some dual extrude thoughts:
* Instead of using wood for the ghost eye, I can do a blue/black dual extrude to do the whole ghost at once...which will mean I shouldn't have a gap between the eye and ghost
* I can use dual extrude for the jack labels...and if I'm going that route, I can use that to personalize the cases!!!!
* This means I need to use PLA as support rather than PVA....but that should be doable.

Ordering black PLA for the eyes...

# 6/17/21
Notes on support:  0.2 mm offset seems to be about right to make the fillet happy.  However, that makes taking out the jack holes hard...you have to drill them.  I'm okay with that.

# 6/23/21
Printing ghosts:
![image](https://user-images.githubusercontent.com/43499190/129495221-8da77b3a-6eec-4d93-a43d-2ff5d0dcf7f6.png)

The harvest:
![image](https://user-images.githubusercontent.com/43499190/129495232-9a1922fb-c442-4b03-b011-344fe58f7f58.png)


# 6/25/21
Time lapse of Pocket's case:
https://glennsalaman.smugmug.com/Other/n-FVHJP5/Dawson/i-Tjtmr7S

# 7/09/21
Finished assembly...here's the final output:

![image](https://user-images.githubusercontent.com/43499190/129495374-bbfd8e8e-f170-4468-a711-72f9c8ebb50a.png)


![image](https://user-images.githubusercontent.com/43499190/129495398-ab5ab243-c3f7-4d40-93b9-6dfc556d7ebd.png)

And...in action:
https://drive.google.com/file/d/1iL1jrGGfeoajQjLoZIwszLVyoZmZPBB2/view?usp=sharing


# 7/13/21
Cases shipped!



