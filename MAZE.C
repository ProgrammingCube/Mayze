/*
   Maze Game for CP/M-80
                           Patrick Jackson
   There isn't a proper    11/30/20
   maze game for CP/M,
   so I decided to make
   my own.
*/

extern double ran();  /* "random" number generator
                         use this to get random list */
#include "CONIO.H"
#include "MAINSCR.H"
#include "PERFMAZ.H"

#define   DEBUG      0

#define   WIDTH     77
#define   HEIGHT    19

printMaze(maze)
char *maze;
{
     int x, y;
     for (y = 0; y < HEIGHT; y++)
     {
          printf(" ");
          for (x = 0; x < WIDTH; x++)
          {
               switch(maze[y * WIDTH + x])
               {
                    case 1:  printf("#"); break;
                    case 2:  printf(","); break;
                    default: printf(" "); break;
               }
          }
          printf("\n");
     }
}

printMessage()
{
     printf("  Welcome to ");
     textcolor(LRED);
     printf("Mayze");
     textmode(RESET);
     printf("!\n\n");
}

struct Player
{
     int x;
     int y;
     int px;
     int py;
     char state;
};

main()
{
     int i, j;
     char maze[HEIGHT][WIDTH];
     char user[3];
     struct Player player;

     player.x = player.px = 1;
     player.y = player.py = 0;
     player.state = '@';

     for (i = 0; i < 3; i++)
          user[i] = 0;

     mainScreen();
     /* genMaze(maze); */
     genMaze(maze);
     printf("\nGenerating maze...\n");
     clrscr();
     printMessage();

#if  DEBUG == 0
     printMaze(maze);
#else
     for (i = 0; i < HEIGHT; i++)
     {
          printf(" ");
          for (j = 0; j < WIDTH; j++)
               printf("%d", maze[i][j]);
          printf("\n");
     }
#endif

     for(;;)
     {
          gotoxy(2 + player.x, 3 + player.y);
          textcolor(YELLOW);
          putchar(player.state);
          textmode(RESET);
          user[0] = getch();
          if (user[0] == ESC);
          {
               user[1] = kbhit();
               if (user[1] == 0)  /* ESC key pressed */
                    break;
               if (user[1] == '[')
               {
                    user[2] = kbhit();
                    gotoxy(player.x + 2, player.y + 3);
                    putchar(' ');
                    switch(user[2])
                    {
                         case 'A': player.py = player.y;
                                   player.px = player.x; player.y -= 1; break;
                         case 'B': player.py = player.y;
                                   player.px = player.x; player.y += 1; break;
                         case 'C': player.px = player.x;
                                   player.py = player.y; player.x += 1; break;
                         case 'D': player.px = player.x;
                                   player.py = player.y; player.x -= 1; break;
                         default : break;
                    }
               }
          }
          for (i = 0; i < 3; i++)
               user[i] = 0;
          /* Movement check */
          
          if (maze[player.y][player.x] == 1)
          {
               player.x = player.px;
               player.y = player.py;
          }
          if ((player.x == (WIDTH - 2)) && (player.y == HEIGHT - 1))
          {
               gotoxy(player.px + 2, player.py + 3);
               putchar(' ');
               gotoxy(player.x + 2, player.y + 3);
               textcolor(YELLOW);
               putchar(player.state);
               textmode(RESET);
               gotoxy(1,23);
               printf("You won!\n");
               getch();
               break;
          }
/*
          gotoxy(1,23);
          printf("X: %d; Y: %d\n", player.x, player.y);
*/
#if  DEBUG == 1
          gotoxy(1,23);
          printf("%d\n", maze[player.y][player.x]);
#endif
     }
     clrscr();
}