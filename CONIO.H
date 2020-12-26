/* CONIO.H
   This file is a homebrew implementation
   of MS-DOS TurboC CONIO.H
   This version is specifically formatted
   for use with the Aztec C 1.06d Compiler
*/
#ifndef CONIO_H
#define CONIO_H

/* CONIO.H Defines
 * I don't have a really great way
 * to do this in another way right
 * now. So hooray for global defines!
 */
#define   ESC  27

#define   RESET     0
#define   BRIGHT    1
#define   DIM       2
#define   USCORE    4
#define   BLINK     5
#define   REVERSE   7
#define   HIDDEN    8

#define   BLACK     0
#define   BLUE      1
#define   GREEN     2
#define   CYAN      3
#define   RED       4
#define   MAGENTA   5
#define   BROWN     6
#define   LGRAY     7
#define   GRAY      8
#define   LBLUE     9
#define   LGREEN    10
#define   LCYAN     11
#define   LRED      12
#define   LMAGENTA  13
#define   YELLOW    14
#define   WHITE     15

int kbhit()
{
     return bdos(6, 255);
}

gotoxy(x, y)
int x;
int y;
{
     printf("%c[%d;%dH", ESC, y, x);
}

textcolor(x)
int x;
{
     switch(x)
     {
          case 0:
               printf("%c[0;30m", ESC);
               break;
          case 1:
               printf("%c[0;34m", ESC);
               break;
          case 2:
               printf("%c[0;32m", ESC);
               break;
          case 3:
               printf("%c[0;36m", ESC);
               break;
          case 4:
               printf("%c[0;31m", ESC);
               break;
          case 5:
               printf("%c[0;35m", ESC);
               break;
          case 6:
               printf("%c[0;33m", ESC);
               break;
          case 7:
               printf("%c[0;37m", ESC);
               break;
          case 8:
               printf("%c[1;30m", ESC);
               break;
          case 9:
               printf("%c[1;34m", ESC);
               break;
          case 10:
               printf("%c[1;32m", ESC);
               break;
          case 11:
               printf("%c[1;36m", ESC);
               break;
          case 12:
               printf("%c[1;31m", ESC);
               break;
          case 13:
               printf("%c[1;35m", ESC);
               break;
          case 14:
               printf("%c[1;33m", ESC);
               break;
          case 15:
               printf("%c[1;37m", ESC);
               break;
     }
}

textbackground(x)
int x;
{
     switch(x)
     {
          case 0:
               printf("%c[0;40m", ESC);
               break;
          case 1:
               printf("%c[0;44m", ESC);
               break;
          case 2:
               printf("%c[0;42m", ESC);
               break;
          case 3:
               printf("%c[0;46m", ESC);
               break;
          case 4:
               printf("%c[0;41m", ESC);
               break;
          case 5:
               printf("%c[0;45m", ESC);
               break;
          case 6:
               printf("%c[0;43m", ESC);
               break;
          case 7:
               printf("%c[0;47m", ESC);
               break;
          case 8:
               printf("%c[1;40m", ESC);
               break;
          case 9:
               printf("%c[1;44m", ESC);
               break;
          case 10:
               printf("%c[1;42m", ESC);
               break;
          case 11:
               printf("%c[1;46m", ESC);
               break;
          case 12:
               printf("%c[1;41m", ESC);
               break;
          case 13:
               printf("%c[1;45m", ESC);
               break;
          case 14:
               printf("%c[1;43m", ESC);
               break;
          case 15:
               printf("%c[1;47m", ESC);
               break;
     }
}

textmode(x)
int x;
{
     switch(x)
     {
          case RESET:
               printf("%c[0m", ESC);
               break;
          case BRIGHT:
               printf("%c[1m", ESC);
               break;
          case DIM:
               printf("%c[2m", ESC);
               break;
          case USCORE:
               printf("%c[4m", ESC);
               break;
          case BLINK:
               printf("%c[5m", ESC);
               break;
          case REVERSE:
               printf("%c[7m", ESC);
               break;
          case HIDDEN:
               printf("%c[8m", ESC);
               break;
     }
}

cgets()
{
     
}

cscanf()
{
     
}

int putch(a)
{
     bdos(2,a);
     return a;
}

int cputs(a)
char *a;
{
     int i;
     i = 0;
     while(a[i] != '\0')
          bdos(2,a[i]);
     return 0;
}

cprintf()
{
     
}

clrscr()
{
     printf("%c[2J", ESC);
     printf("%c[H", ESC);
}

int getch()
{
     int a = 0;
     while (a == 0)
          a = bdos(6, 255);
     return a;
}

int getche()
{
     int a;
     a = getch();
     putch(a);
     return a;
}

/*
 * Custom Functions
 * These functions are not strictly part
 * of conio.h (or maybe they are, I don't
 * know all of them)
 * Very handy to have.
 */

#endif