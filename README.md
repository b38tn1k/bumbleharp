# Bumble Harp

# Build Notes

## init / Jan 14 2025

This is very early.

The idea is an arduino based & 3D printed velocity sensitive MIDI controller built without any particularily special or hard to track down components.

I am planning a hexagonal layout for 12 buttons, facilitating a [Tonnetz](https://en.wikipedia.org/wiki/Tonnetz) assisted approach to improvised melody & harmony, along with an interesting ergonomic setup for percussive controllerism. The goal is to integrate the harmony engine from [Chord Toy](https://github.com/b38tn1k/chordtoy), along with a linear pot (or some other 1-D motion signal generator) to provide something like an omnichord or what I imagine one of those accordians with the button lay out plays like. Combine the bee hive hexagon shapes with the omnichord strumming idea and you get Bumble Harp. I know bumble bees don't live in hives. 

The velocity tracking is pretty oldschool but works really nice - each 3D printed button hits two keyboard switches on press. The keyboard switches have a z offset between them, so one always closes before the other - the time between Switch 1 and Switch 2 closing can be used to make up a velocity value.

### BOM

- a pile of 6x2mm circle magnets
- some keyboard switches, like for a mechanical keyboard. Reccomend 'silent' ones without any bump or click. probably a keyboards worth
- filament and a 3D printer. I am trying to use my smaller printer for everything, print envelope to follow


### CAD

[CAD is available in Onshape](https://cad.onshape.com/documents/0926d3b181919805e37e47c7/w/9472cb1f4be91defec4fba22/e/4f739bf295eab5d1871a2a5f)
 
