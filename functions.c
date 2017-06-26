/*   File  : functions.c
     By    : Nathan Lam
     Login : nathancy
     Date  : 5/2/2015
     Team  : Hot Wings  */

/* This file contains the functions that do the additional features
   as determined by the choosen maze level. */

#include <stdio.h>
#include "display.h"
#include "mousecam.h"
#define TRUE 99
#define FALSE 98
#define ROW 16
#define COl 16

/* Given the user command in addition to the previous direction. This
   function then returns the new direction. */
int getdirection(char input, int direction)
{
	switch(direction)
	{

	  /* If previous direction was north */
		case NORTH:   if(input == 'a')
			      	direction = WEST;
			    
			      if(input == 's')
				direction = SOUTH;

			      if(input == 'd')
				direction = EAST;

			      return direction;
			      break;

	  /* If previous direction was south */
		case SOUTH:   if(input == 'a')
				direction = EAST;

			      if(input == 's')
				direction = NORTH;

			      if(input == 'd')
				direction = WEST;

			      return direction;
			      break;

	  /* If previous direction was east */
		case EAST : if(input == 's')
				direction = WEST;

			      if(input == 'a')
				direction = NORTH;

			      if(input == 'd')
				direction = SOUTH;
			
			      return direction;
			      break;

	  /* If previous direction was west */
		case WEST : if(input == 'd')
				direction = NORTH;

			      if(input == 'a')
				direction = SOUTH;

			      if(input == 's')
				direction = EAST;
				
			      return direction;
			      break;
	}
}

/* This function is given the desired direction and the surrounding walls.
   The function returns true if there is a wall (mouse crashed) and
   false if there is no wall (mouse did not crash). It uses pointers. */
int checkcrash(int dir, int *north, int *east, int *west, int *south)
{

  /* If direction is north */
	if(dir == NORTH && (*north == 1))
	{
		return TRUE;
	}

  /* If direction is south */
	else if(dir == SOUTH && (*south == 1))
	{
		return TRUE;
	}

  /* If direction is east */
	else if(dir == EAST && (*east == 1))
	{
		return TRUE;
	}

  /* If direction is west */
	else if(dir == WEST && (*west == 1))
	{
		return TRUE;
	}

  /* If there is no wall */
	else
	{
		return FALSE;
	}
}

/* This function is given the direction and the previous x and y
   coordinates. This function changes the coordinates of the mouse
   indirectly depending on the given direction. It uses pointers. */
void movemouse(int dir, int *y, int *x)
{

  /* Increment y coordinate if north */
	if(dir == NORTH)
	{
		*x += 1;
	}

  /* Decrement y coordinate if south */
	if(dir == SOUTH)
	{
		*x -= 1;
	}

  /* Increment x coordinate if east */
	if(dir == EAST)
	{
		*y += 1;
	}

  /* Decrement x coordinate if west */
	if(dir == WEST)
	{
		*y -= 1;
	}
}

/* This function is given nothing and returns nothing. It reveals the
   entire maze in level 1 by obtaining the walls for each cell
   then prints the walls to the display. */
void cheese_scope(void)
{
int j, i;
int north, east, south, west;

	for(i = 0; i < 16; i++)
	{
		for(j = 0; j < 16; j++)
		{
		  /* Obtain walls for respective x and y coordinate */
			lvl0_get_walls(i, j, &north, &east, &west, &south);

	 	  /* Print walls to display */
			put_walls(i, j, north, east, west, south);
		}
	}
}

/* This function is given the x & y coordinates and indirectly given
   the walls. It "draws" the walls for the maze in level 2 and level 3
   according to newmaze.dat. This function essentially creates the new maze
   and uses pointers to map the walls for each x and y coordinate. */
void getwall_newmaze(int y, int x, int *north, int *east, int *west, int *south)
{
  int hold;

  /* Draw the maze */
  int newmaze[MAXR][MAXC] = {

  { 7, 10, 13, 3, 9, 9, 9, 9, 3, 3, 9, 9, 9, 9, 9, 10 },
  { 6, 5, 9, 8, 13, 3, 10, 14, 6, 12, 7, 9, 9, 3, 11, 6 },
  { 5, 10, 7, 10, 7, 2, 5, 2, 5, 9, 8, 7, 10, 6, 7, 8},
  { 7, 8, 4, 8, 6, 4, 11, 6, 7, 9, 9, 0, 8, 6, 6, 14},
  { 4, 9, 2, 7, 8, 4, 10, 6, 4, 10, 14, 4, 9, 0, 0, 2},
  { 4, 11 ,6, 12, 7, 0, 8, 6, 6, 5, 2, 5, 3, 8, 6, 6},
  { 6, 14, 6, 7, 2, 6, 7, 8, 5, 10, 5, 10, 6, 13, 1, 8},
  { 6, 4, 0, 8, 12, 6, 6, 7, 10, 6, 7, 8, 4, 9, 10, 14},
  { 5, 8, 6, 7, 9, 2, 12, 5, 2, 12, 5, 10, 6, 7, 8, 6},
  { 7, 9, 8, 6, 14, 12, 7, 9, 8, 7, 9, 2, 5, 2, 7, 8},
  { 6, 14, 13, 8, 4, 9, 2, 7, 3, 8, 14, 5, 10, 4, 8, 14},
  { 4, 1, 11, 7, 1, 11, 4, 2, 12, 7, 8, 7, 1, 8, 7, 2},
  { 6, 7, 11, 5, 10, 7, 2, 5, 11, 6, 13, 0, 9, 3, 8, 12},
  { 6, 6, 14, 7, 8, 6, 12, 7, 10, 5, 10, 5, 9, 0 ,11, 14},
  { 5, 0, 8, 6, 7, 8, 7, 8, 4, 10, 6, 7, 11, 6, 13, 2},
  { 13, 8, 13, 8, 5, 9, 8, 13, 8, 5, 1, 1, 9, 1, 9, 8}     };

  /* Store the "maze code" to determine the walls */
  hold = newmaze[y][x];

  /* If the "maze code" has a north wall, draw a wall */
  if (hold == 1 || hold == 5 || hold == 8 || hold == 9 || hold == 11 || hold == 12 || hold == 13)
  {
    *north = 1;
  }
  else
  {
    *north = 0;
  }

  /* If the "maze code" has a east wall, draw a wall */
  if (hold == 2 || hold == 6 || hold == 8 || hold == 10 || hold == 11 || hold == 12 || hold == 14)
  {
    *east = 1;
  }
  else
  {
    *east = 0;
  }

  /* If the "maze code" has a west wall, draw a wall */
  if (hold == 4 || hold == 5 || hold == 6 || hold == 7 || hold == 12 || hold == 13 || hold == 14)
  {
    *west = 1;
  }
  else
  {
    *west = 0;
  }

  /* If the "maze code" has a south wall, draw a wall */
  if (hold == 3 || hold == 7 || hold == 9 || hold ==  10 || hold == 11 || hold == 13 || hold == 14)
  {
    *south = 1;
  }
  else
  {
    *south = 0;
  }
}

/* This function is given nothing and returns nothing. It reveals the
   entire display of the maze in level 2 and in level 3. It gets the walls
   for each coordinate then prints the walls to the display. */
void cheese_scope_v2(void)
{
  int x, y;
  int north, east, south, west;

  for(x = 0; x < 16; x++)
  {
    for(y = 0; y < 16; y++)
    {
      /* Obtain walls for respective x and y coordinate */
      getwall_newmaze(x, y, &north, &east, &west, &south);

      /* Print the walls to the display */
      put_walls(x, y, north, east, west, south);
    }
  }
}

/* Function is given an array and returns nothing. It restores the
   state of the maze before 'm' was pressed. It clears the current maze,
   checks each coordinate to see if it was passed through, and prints
   the walls of passed coordinates. Available at level 2 and higher. */
void hide_me_cheese(int maze[MAXR][MAXC])
{
  int x, y;
  int north, east, south, west;

  /* Clears current display */
  init_display(2);

  for(x = 0; x < 16; x++)
  {
    for(y = 0; y < 16; y++)
    {
      /* If coordinate was passed through */
      if (maze[x][y] == 1)
      {
        /* Obtain walls for respective coordinate */
        getwall_newmaze(x, y, &north, &east, &west, &south);

        /* Prints the walls to the display */
        put_walls(x, y, north, east, west, south);
      }
    }
  }
}

/* This function is given an array and returns nothing. It initiates unique
   cell flags to 0 (unpassed cells). Available at level 2 and higher. */
void starcraft_cheesemap_editor(int maze[][MAXC])
{
  int i, j;
  for (i = 0; i < 16; i++)
  {
    for (j = 0; j < 16; j++)
    {
      /* Set coordinate to zero */
      maze[i][j] = 0;
    }
  }
}
