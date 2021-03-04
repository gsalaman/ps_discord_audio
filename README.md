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

Simple Audio Mix:  a bunch of 470 ohm resistors:
<img width="793" alt="Screen Shot 2021-03-04 at 4 13 15 PM" src="https://user-images.githubusercontent.com/43499190/110043543-cb5ad180-7d04-11eb-9ea3-f7a5ee9c64b0.png">
