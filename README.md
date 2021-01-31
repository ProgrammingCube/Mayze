# Mayze
CP/M 2.2 Maze game, because there don't seem to be a lot of good ones out there.

## Compiling

This progam is written specifically for use with the Aztec C Compiler (1.06D). This is done in order to maintain maximum compatability with CP/M systems, 8080/85/Z80.

In order to compile the program, you must copy all source files over to your CP/M device. Use the Aztec Compiler (installed on drive C: for our example):

`C:cc` or `C:cz maze`

`C:as maze`

`C:ln maze.o C:m.lib C:c.lib`

### Adwater ALTAIR 8800 Integrated VT-100 Emulator
If you want, you can compile this game for use with the internal VT100 card of the Adwater Altair 8800. This is a "valid" VT100 emulator, but the default firmware doesn't allow for multi color, nor does the base circuitry. If you want, you can go into `MAZE.C` and switch `#define ALTAIR 0` to `1` to enable support. (I plan to move these compiling defines to a separate file later.)

***NOTE***
The Adwater Altair version currently has problems with the arrow keys. Use the number pad to navigate. Currently, only up/down/left/right are implemented because of the nature of the maze.

## Playing

Simply run the game by runing `MAZE`. It is ideal to wait until *after* the `Press enter...` shows up to press enter, as this starts the random number generator.

Arrow keys are used for navigation, ESC is used to exit.

Right now, the game only generates perfect mazes 77x19 characters in size. It is possible to change the size by changing the `HEIGHT` and `WIDTH` #defines in `maze.c`

# CAVEGEN

This is a dungeon cave generator written in C. It contains my own algorithm, but its fairly simple. Basically it fills the map with wall tiles, then places a floor tile in the center. Then, for `k` iterations, it spreads floor tiles out in a random walk. If it comes upon a map boundary, it has a 1/3 chance of moving back to the center and running again, or a 2/3 chance of backing up to the previous tile and going again.

## Compiling
This program compiles pretty much the same way as `maze.c`. It does need `CONIO.H` in its drive though. An interesting note is that the Aztec C compiler isn't very optimized for functions that it doesn't use, so it compiles and includes the ENTIRE conio.h instead of just the kbhit() it uses.