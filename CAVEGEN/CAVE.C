/*
 * Cave Generator
 */
#define WIDTH   78
#define HEIGHT  21

#define STEPS   600

extern double ran();

#include "CONIO.H"

struct Traveler
{
    int x;
    int y;
    int px;
    int py;
};

void genCave(maze)
char *maze;
{
	int i;
    int k = 0;
    struct Traveler traveler;

    traveler.px = traveler.x = WIDTH  / 2;
    traveler.py = traveler.y = HEIGHT / 2;

    do
    {
        /* move 1 tile */
		i = (int)ran() % 8;
        switch(i)
        {
            case 0: traveler.px = traveler.x; traveler.x++; break;  /* right */
            case 1: traveler.py = traveler.y; traveler.y++; break;  /* down */
            case 2: traveler.px = traveler.x; traveler.x--; break;  /* left */
            case 3: traveler.py = traveler.y; traveler.y--; break;  /* up */
            case 4: traveler.px = traveler.x; traveler.x++;
                    traveler.py = traveler.y; traveler.y++; break;  /* low-right */
            case 5: traveler.px = traveler.x; traveler.x--;
                    traveler.py = traveler.y; traveler.y--; break;  /* low-left */
            case 6: traveler.px = traveler.x; traveler.x--;
                    traveler.py = traveler.y; traveler.y++; break;  /* up-left */
            case 7: traveler.px = traveler.x; traveler.x++;
                    traveler.py = traveler.y; traveler.y--; break;  /* up-right */
        }

        if (maze[traveler.y * WIDTH + traveler.x] == '#')
            maze[traveler.y * WIDTH + traveler.x] = '.';

        if (traveler.x == WIDTH - 2 || traveler.y == HEIGHT - 2 ||
            traveler.x == 1 || traveler.y == 1)
        {
			i = (int)ran() % 3;
            if (i == 0)
            {
                traveler.px = traveler.x = WIDTH  / 2;
                traveler.py = traveler.y = HEIGHT / 2;
            }
            else
            {
                traveler.x = traveler.px;
                traveler.y = traveler.py;
            }
        }
        k++;
    }
    while (k < STEPS);
}

void printMap(maze)
char *maze;
{
    int i, j;
    for (i = 0; i < HEIGHT; i++)
    {
        printf(" ");
        for (j = 0; j < WIDTH; j++)
            putchar(maze[i * WIDTH + j]);
        printf("\n");
    }
}

void main()
{
	int i, j;
    char maze[HEIGHT][WIDTH];
	for (i = 0; i < HEIGHT; i++)
	{
		for (j = 0; j < WIDTH; j++)
		{
			maze[i][j] = '#';
		}
	}
	
	printf("Press Enter:\n");
	while (kbhit() != 0x0D)
    {
        ran();
    }
	
	printf("\n");
    genCave(maze);

    printMap(maze);
}
