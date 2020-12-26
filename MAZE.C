/*
   Maze Game for CP/M-80
                           Patrick Jackson
   There isn't a proper    11/30/20
   maze game for CP/M,
   so I decided to make
   my own.
*/
#include "CONIO.H"
#include "MAINSCR.H"

#define   WIDTH     77
#define   HEIGHT    19

extern double ran();  /* "random" number generator
                         use this to get random list */

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
     textcolor(LRED);
     printf("Mayze");
     textmode(RESET);
     printf("!\n\n");
}

struct Player
{
     int x;
     int y;
     char state;
};

main()
{
     char maze[HEIGHT][WIDTH];
     char user[3];
     memset(user, 0, 3);
     struct Player player;

     player.x = 0;
     player.y = 0;
     player.state = '@';

     genMaze(maze);

     mainScreen();
     getchar();
     clrscr();
     printMessage();
     printMaze(maze);

     for(;;)
     {
          user[0] = getch();
          if (user[0] == ESC);
          {
               if (bdos(6, 255) == 0)  /* ESC key pressed */
                    break;
               user[1] = getch();
               if (user[1] == '[')
               {
                    user[2] = getch();
                    switch(user[2])
                    {
                         case 'A': player.y -= 1; break;  /* UP */
                         case 'B': player.x += 1; break;  /* RIGHT */
                         case 'C': player.y += 1; break;  /* DOWN */
                         case 'D': player.x -= 1; break;  /* LEFT */
                         default : break;
                    }
               }
          }
          memset(user, 0, 3);
     /* Movement */
     }
}