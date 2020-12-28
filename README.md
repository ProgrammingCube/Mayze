# Mayze
CP/M 2.2 Maze game, because there don't seem to be a lot of good ones out there.

## Compiling

This progam is written specifically for use with the Aztec C Compiler (1.06D). This is done in order to maintain maximum compatability with CP/M systems, 8080/85/Z80.

In order to compile the program, you must copy all source files over to your CP/M device. Use the Aztec Compiler (installed on drive C: for our example):

`C:cc` or `C:cz maze`

`C:as maze`

`C:ln maze.o C:m.lib C:c.lib`

## Playing

Simply run the game by runing `MAZE`. It is ideal to wait until *after* the `Press enter...` shows up to press enter, as this starts the random number generator.

Arrow keys are used for navigation, ESC is used to exit.

Right now, the game only generates perfect mazes 77x19 characters in size. It is possible to change the size by changing the `HEIGHT` and `WIDTH` #defines in `maze.c`