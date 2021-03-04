# ps_discord_audio
My notes for a playstation/discord audio mixer

Plugs are TRRS.  From the specs, sometimes Shield is GND, sometimes Mic.  Gonna need to measure phones (android and apple), PC, and playstation.  Just in case, could design in a jumper to route those two...

```
Mac, HTC headset, HTC phone:
------------------
Tip is L audio
R1  is R audio
R2 is GND
S  is Mic
```

## Simple Audio Mix:  a bunch of 470 ohm resistors:
<img width="793" alt="Screen Shot 2021-03-04 at 4 13 15 PM" src="https://user-images.githubusercontent.com/43499190/110043543-cb5ad180-7d04-11eb-9ea3-f7a5ee9c64b0.png">

## Next Steps
I'm gonna want gain.  I *could* use a 324, but the LM386 looks like it's custom made for what I want.  Cool amplifier link here:
https://www.circuitbasics.com/build-a-great-sounding-audio-amplifier-with-bass-boost-from-the-lm386/

Prototype with two channels, then summed with the resistors as above.  Implementation will have a dual gang potentiometers to hit both channels.

Will need to make a bunch of TRRS cables.  Buying them is $10 a pop, and each setup needs 2...or maybe even 3 if their headset doesn't have one.
Could do cable connected directly outta box to Discord and Playstation Controller, but I think I like the connector instead...seems like it's more robust as the cable will come out under stress (rather than breaking)

Want Mute Switch.

And, if we're doing this, I should have cool lights...an ATTINY85 and a couple LEDs.

