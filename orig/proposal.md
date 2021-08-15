# Playstation/Discord Audio Mixer Box

## Problem Statement
I'm an avid "Destiny" gamer.  This game spans multiple platforms, and I've got people I play with on both the PC and Playstation platforms.
Communication is key when running this game; there are actions that need to be communicated precisely.  While Desitiny supports an "in-game" chat, 
the quality of the voice is severly lacking.  Because of this, most Destiny players run a different application for voice chat:
* Discord for the PC
* "Party Chat" on the Playstation

There is currently no cross-play functionality.  If you are on a PC, you must play with other PC players; you can't play with people running Destiny on a Playstation.  
However, cross-play has been announced, and will arrive in September, allowing PC and Playstation players to play together.

The problem is that there is no cross-play voice chat functionality (except for the limited game-chat).  My proposal is to make a box that allows a Playstation player to 
hook into Discord, mixing the audio from both Discord and the Game into the player's headset.

## Proposed Implementation
System Block Diagram below:
![Discord Box Block Diagram](https://user-images.githubusercontent.com/43499190/122586510-0239c680-d01a-11eb-942d-d9af317a9647.jpg)

The "Discord" box can be any device using Discord...phone, tablet, laptop, desktop, etc.

The audio channels will be mixed passively between the Playstation controller and Discord box.

Microphone signals only need to go to the Discord app, as we won't be using Playstation Party Chat.  While we could rely on mute from the Discord box, we'll implement a hardwired mute switch in the microphone path for convenience.

To "spice up" the look of the box, we're going to design in a Destiny "ghost" with a light-up eye.  We'll have a simple Microprocessor driving that eye with two modes:
* In normal mode, the colors will cycle.
* When the box is muted, the eye will flash red

To power this processor, we'll use a simple coin-cell battery.
