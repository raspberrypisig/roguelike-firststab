# Roguelike Tutorial 2021 C++

Largely tried to follow Python Roguelike 2021 tutorial, but veered on tangents at times.

File structure based on https://gitlab.com/libtcod-tutorials/libtcod-tutorials
This really helped me "port" the python tutorials to C++ and it is really well written.

## Setup

https://github.com/raspberrypisig/roguelike-firststab/tree/setup

## Tutorials

### Tutorial 0

Just confirming the setup/plumbing is working OK.

### Tutorial 1

Get the @ symbol appear in the middle of the screen, with arrow keys able to move the player around.

### Tutorial 2

I've veered a little bit from the offical python tutorial. Wanted to get a better feel for

- loading files from RexPaint
- loading tilesheets/tilesets/custom fonts
- character encoding mapping (EASCII/Code Page 437 to Unicode)
- using ASCII instead of colored tiles

### Tutorial 2a

Loaded file from RexPaint. Using default font in Rexpaint, not using a tilesheet in libtcod, which means that a fallback system font is used (Lucida on Windows?). Using # symbol for wall, . symbol for floor, @ for player.

### Tutorial 2b

Loaded file from RexPaint. Using default font in Rexpaint, but this time loaded default terminal tilesheet provided by libtcod. Instead of the . symbol for floor , using EASCII character 249 (centered dot). Whereas normal ASCII translates 1-to-1 with Unicode codepoints perfectly, the same is not the case for the extended characters in EASCII. As a result, need to use a character mapping provided by libtcod.

### Tutorial 2c

Here, used a custom font in Rexpaint, and also used the same font as the tilesheet to draw the graphics.
