/*
  Main screen for CP/M-80 Maze
*/
#ifndef MAINSCR_H
#define MAINSCR_H

#include "CONIO.H"

mainScreen()
{
     char a = 178;
     int i;
     clrscr();
     textcolor(LRED);
     printf("\n                  ____\n");
     printf("                ,\'  , `.\n");
     printf("             ,-+-,.\' _ |                            ,---- ,\n");
     printf("          ,-+-. ;   , ||                          .\'   .`|\n");
     printf("         ,--.\'|\'   |  || ,--.--.        .--,   .\'   .\'  .\'   ,---.\n");
     printf("        |   |  ,\', |  |,/       \\     /_ ./| ,---, \'   ./   /     \\\n");
     printf("        |   | /  | |--\'.--.  .-. | , \' , \' : ;   | .\'  /   /    /  |\n");
     printf("        |   : |  | ,    \\__\\/: . ./___/ \\: | `---\' /  ;- -,.    \' /\n");
     printf("        |   : |  |/     ,\" .--.; | .  \\  \' |   /  /  / .`|\'   ;   /|\n");
     printf("        |   | |`-\'     /  /  ,.  |  \\  ;   : ./__;     .\' \'   |  / |\n");
     printf("        |   ;/        ;  :   .\'   \\  \\  \\  ; ;   |  .\'    |   :    |\n");
     printf("        \'---\'         |  ,     .-./   :  \\  \\`---\'         \\   \\  /\n");
     printf("                       `--`---\'        \\  \' ;               `----\'\n");
     printf("                                        `--`\n");
     textmode(RESET);
     printf("\n                                  Press enter!\n");
     while (kbhit() != 0x0D)
     {
          ran();
     }
     textcolor(LGREEN);
     printf("\n                               Generating maze...\n");
     textmode(RESET);
}
#endif