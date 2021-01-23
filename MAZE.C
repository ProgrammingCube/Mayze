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
#define   ALTAIR     0
#define   DEBUG      0

#include "CONIO.H"
#include "MAINSCR.H"
#include "PERFMAZ.H"

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

carveMaze(maze, x, y)
char *maze;
int x;
int y;
{
     int x1, y1, x2, y2, dx, dy;

     int dir = (int)(ran() * 10000) % 4;
     int count = 0;
     while(count < 4)
     {
          dx = 0; dy = 0;
          switch(dir)
          {
               case 0:  dx = 1;  break;
               case 1:  dy = 1;  break;
               case 2:  dx = -1; break;
               default: dy = -1; break;
          }
          x1 = x + dx;
          y1 = y + dy;
          x2 = x1 + dx;
          y2 = y1 + dy;
          if(x2 > 0 && x2 < WIDTH && y2 > 0 && y2 < HEIGHT
             && maze[y1 * WIDTH + x1] == 1 && maze[y2 * WIDTH + x2] == 1)
          {
               maze[y1 * WIDTH + x1] = 0;
               maze[y2 * WIDTH + x2] = 0;
               x = x2; y = y2;
               dir = (int)(ran() * 10000) % 4;
               count = 0;
          }
          else
          {
               dir = (dir + 1) % 4;
               count += 1;
          }
     }
}

genMaze(maze)
char *maze;
{
     int x, y;
     /* initialize maze */
     for (x = 0; x < WIDTH * HEIGHT; x++)
          maze[x] = 1;
     maze[1 * WIDTH + 1] = 0;
     for (y = 1; y < HEIGHT; y += 2)
          for (x = 1; x < WIDTH; x += 2)
               carveMaze(maze, x, y);
     maze[0 * WIDTH + 1] = 0;
     maze[(HEIGHT - 1) * WIDTH + (WIDTH - 2)] = 0;
}

printMessage()
{
     printf("  Welcome to ");
#if  ALTAIR == 0
     textcolor(LRED);
#endif
     printf("Mayze");
#if  ALTAIR == 0
     textmode(RESET);
#endif
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
#if  ALTAIR == 0
          textcolor(YELLOW);
#endif
          putchar(player.state);
          textmode(RESET);
          user[0] = getch();
#if ALTAIR == 0
          if (user[0] == ESC)
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
#else
          if (user[0] == ESC)
               break;
          gotoxy(player.x + 2, player.y + 3);
          putchar(' ');
          switch(user[0])
          {
             case 56: player.py = player.y;
                      player.px = player.x; player.y -= 1; break;
             case 50: player.py = player.y;
                      player.px = player.x; player.y += 1; break;
             case 54: player.py = player.y;
                      player.px = player.x; player.x += 1; break;
             case 52: player.py = player.y;
                      player.px = player.x; player.x -= 1; break;
             default: break;
          }
#endif
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
#if  ALTAIR == 0
               textcolor(YELLOW);
#endif
               putchar(player.state);
#if  ALTAIR == 0
               textmode(RESET);
#endif
               gotoxy(1,23);
               printf("You won!\n");
               getch();
               break;
          }
#if  DEBUG == 1
          gotoxy(1,23);
          printf("%d\n", maze[player.y][player.x]);
#endif
     }
     clrscr();
}
