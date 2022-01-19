# Roguelike Tutorial 2021 C++

Largely tried to follow Python Roguelike 2021 tutorial, but veered on tangents at times.

File structure based on https://gitlab.com/libtcod-tutorials/libtcod-tutorials
This really helped me "port" the python tutorials to C++ and it is really well written.

## Setup

https://github.com/raspberrypisig/roguelike-firststab/tree/setup

## Tutorials

### Tutorial 0

Just confirming the setup/plumbing is working OK.

![Tutorial 0](https://github.com/raspberrypisig/roguelike-firststab/raw/main/images/tutorial0.jpg)

### Tutorial 1

Get the @ symbol appear in the middle of the screen, with arrow keys able to move the player around.

![Tutorial 1](https://github.com/raspberrypisig/roguelike-firststab/raw/main/images/tutorial1.jpg)

### Tutorial 2

I've veered a little bit from the offical python tutorial. Wanted to get a better feel for

- loading files from RexPaint
- loading tilesheets/tilesets/custom fonts
- character encoding mapping (EASCII/Code Page 437 to Unicode)
- using ASCII instead of colored tiles

### Tutorial 2a

Loaded file from RexPaint. Using default font in Rexpaint, not using a tilesheet in libtcod, which means that a fallback system font is used (Lucida on Windows?). Using # symbol for wall, . symbol for floor, @ for player.

![Tutorial 2a](https://github.com/raspberrypisig/roguelike-firststab/raw/main/images/tutorial2a.jpg)

### Tutorial 2b

Loaded file from RexPaint. Using default font in Rexpaint, but this time loaded default terminal tilesheet provided by libtcod. Instead of the . symbol for floor , using EASCII character 249 (centered dot). Whereas normal ASCII translates 1-to-1 with Unicode codepoints perfectly, the same is not the case for the extended characters in EASCII. As a result, need to use a character mapping provided by libtcod.

![Tutorial 2b](https://github.com/raspberrypisig/roguelike-firststab/raw/main/images/tutorial2b.jpg)

### Tutorial 2c

Here, used a custom font in Rexpaint, and also used the same font as the tilesheet to draw the graphics.

![Tutorial 2c](https://github.com/raspberrypisig/roguelike-firststab/raw/main/images/tutorial2c.jpg)

### Tutorial 3

Inspired by

https://github.com/bradJM/heck

Veered of the python tutorial part 3 to implement same result using BSP trees

### Tutorial 3a

Getting started with BSP Trees in libtcod

![Tutorial 3a](https://raw.githubusercontent.com/raspberrypisig/roguelike-firststab/main/images/tutorial3a.jpg)

We can then judiciously choose to put rooms in those location, in the safe knowledge that they cannot overlap.

### Tutorial 3b

Three step process.

First step is to create random sized rooms in each BSP partition.

![Tutorial 3b part 1](https://raw.githubusercontent.com/raspberrypisig/roguelike-firststab/main/images/tutorial3b-part1.jpg)

Second step is to cull the number of rooms to a visually acceptable number and ensure no overlaps between rooms.

![Tutorial 3b part 2](https://raw.githubusercontent.com/raspberrypisig/roguelike-firststab/main/images/tutorial3b-part2.jpg)

Third step is to put walls around the rooms.

![Tutorial 3b part 3](https://raw.githubusercontent.com/raspberrypisig/roguelike-firststab/main/images/tutorial3b-part3.jpg)

### Tutorial 3c

Inspired by the following to create corridors using the original simplified Rogue algorithm.

https://gamedev.stackexchange.com/questions/50570/creating-and-connecting-rooms-for-a-roguelike

Didn't implement it, though! Tried something quick and dirty. Not perfect, not bad for first go.

![Tutorial 3c](https://raw.githubusercontent.com/raspberrypisig/roguelike-firststab/main/images/tutorial3c.jpg)
