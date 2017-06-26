/* File  : huggers.c
   By    : Nathan Lam 
   Login : nathancy
   Team  : Hot Wings
   Date  : 5/6/2015  */

/* This file contains the functions that control right and left
   wall huggers. */

#include <stdio.h>
#include "display.h"
#include "functions.h"
#include "huggers.h"
#include "mousecam.h"
#define DEBUG

/* Function is indirectly given the direction and coordinates, and directly given the walls. It checks the surrounding walls in the next direction
   for each scenario and moves the mouse by hugging the right wall. */
void right_hugger(int *dir, int *x, int *y, int north, int east, int west, int south)
{
  int d;

	if(*dir == NORTH && north == 1 && east == 1 && west == 1)
	{
		*dir = SOUTH;
		d = SOUTH;
		movemouse(d, y, x);
	}
	else if(*dir == WEST && north == 1 && west == 1 && south == 1)
	{	
		*dir = EAST;
		d = EAST;
		movemouse(d, y, x);
	}
	else if(*dir == SOUTH && west == 1 && south == 1 && east == 1)
	{
		*dir = NORTH;
		d = NORTH;
		movemouse(d, y, x);
	}
	else if(*dir == EAST && north == 1 && south == 1 && east == 1)
	{
		*dir = WEST;
		d = WEST;
		movemouse(d, y, x);
	}


	else if(*dir == NORTH && west == 1 && east == 1)
	{
		*dir = NORTH;
		d = NORTH;
		movemouse(d, y, x);
	}
	else if(*dir == SOUTH && west == 1 && east == 1)
	{
		*dir = SOUTH;
		d = SOUTH;
		movemouse(d, y, x);
	}
	else if(*dir == WEST && north == 1 && south == 1)
	{
	 	*dir = WEST;
		d = WEST;
		movemouse(d, y, x);
	}
	else if(*dir == EAST && north == 1 && south == 1)
	{
		*dir = EAST;
		d = EAST;
		movemouse(d, y, x);
	}
	

	else if(*dir == NORTH && north == 1 && east == 1)
	{
		*dir = WEST;
		d = WEST;
		movemouse(d, y, x);
	}
	else if(*dir == WEST && north == 1 && west == 1)
	{
		*dir = SOUTH;
		d = SOUTH;
		movemouse(d, y, x);
	}
	else if(*dir == SOUTH && west == 1 && south == 1)
	{
		*dir = EAST;
		d = EAST;
		movemouse(d, y, x);
	}
	else if(*dir == EAST && south == 1 && east == 1)
	{
		*dir = NORTH;
		d = NORTH;
		movemouse(d, y, x);
	}
	

	else if(*dir == EAST && north == 1 && east == 1)
	{
		*dir = SOUTH;
		d = SOUTH;
		movemouse(d, y, x);
	}
	else if(*dir == NORTH && west == 1 & north == 1)
	{
		*dir = EAST;
		d = EAST;
		movemouse(d, y, x);
	}
	else if(*dir == WEST && west == 1 && south == 1)
	{
		*dir = NORTH;
		d = NORTH;
		movemouse(d, y, x);
	}
	else if(*dir == SOUTH && east == 1 && south == 1)
	{
		*dir = WEST;
		d = WEST;
		movemouse(d, y, x);
	}
	
	
	else if(*dir == EAST && east == 1)
	{
		*dir = SOUTH;
		d = SOUTH;
		movemouse(d, y, x);
	}
	else if(*dir == NORTH && east == 1)
	{
		*dir = NORTH;	
		d = NORTH;
		movemouse(d, y, x);
	}
	else if(*dir == WEST && east == 1)
	{
		*dir = NORTH;	
		d = NORTH;
		movemouse(d, y, x);
	}
	else if(*dir == SOUTH && east == 1)
	{
		*dir = WEST;
		d = WEST;
		movemouse(d, y, x);
	}


	else if(*dir == EAST && north == 1)
	{
		*dir = SOUTH;
		d = SOUTH;
		movemouse(d, y, x);
	}
	else if(*dir == NORTH && north == 1)
	{
		*dir = EAST;
		d = EAST;
		movemouse(d, y, x);
	}
	else if(*dir == WEST && north == 1)
	{
		*dir = WEST;
		d = WEST;
		movemouse(d, y, x);
	}
	else if(*dir == SOUTH && north == 1)
	{
		*dir = WEST;
		d = WEST;
		movemouse(d, y, x);
	}

	
	else if(*dir == EAST && south == 1)
	{
		*dir = EAST;
		d = EAST;
		movemouse(d, y, x);
	}
	else if(*dir == NORTH && south == 1)
	{
		*dir = EAST;
		d = EAST;
		movemouse(d, y, x);
	}
	else if(*dir == WEST && south == 1)
	{
		*dir = NORTH;
		d = NORTH;
		movemouse(d, y, x);
	}
	else if(*dir == SOUTH && south == 1)
	{
		*dir = WEST;
		d = WEST;
		movemouse(d, y, x);
	}

	
	else if(*dir == EAST && west == 1)
	{
		*dir = SOUTH;
		d = SOUTH;
		movemouse(d, y, x);
	}
	else if(*dir == NORTH && west == 1)
	{
		*dir = EAST;
		d = EAST;
		movemouse(d, y, x);
	}
	else if(*dir == WEST && west == 1)
	{
		*dir = NORTH;
		d = NORTH;
		movemouse(d, y, x);
	}
	else if(*dir == SOUTH && west == 1)
	{
		*dir = SOUTH;
		d = SOUTH;
		movemouse(d, y, x);
	} 


	else if(*dir == EAST && north == 0 && east == 0 && south == 0 && west == 0)
	{
		*dir = SOUTH;
		d = SOUTH;
		movemouse(d, y, x);
	}
	else if(*dir == SOUTH && north == 0 && east == 0 && south == 0 && west == 0)
	{
		*dir = WEST;
		d = WEST;
		movemouse(d, y, x);
	}
	else if(*dir == WEST && north == 0 && east == 0 && south == 0 && west == 0)
	{
		*dir = NORTH;
		d = NORTH;
		movemouse(d, y, x);
	}
	else if(*dir == NORTH && north == 0 && east == 0 && south == 0 && west == 0)	
	{
		*dir = EAST;
		d = EAST;
		movemouse(d, y, x);
	}
}

/* This function is indirectly given the direction and coordinates and
   directly given the walls. It checks the surrounding walls in the next
   direction for each scenario and moves the mouse by hugging the
   left wall. */
void left_hugger(int *dir, int *x, int *y, int north, int east, int west, int south)
{
  int d;

	if(*dir == NORTH && north == 1 && east == 1 && west == 1)
	{
		*dir = SOUTH;
		d = SOUTH;
		movemouse(d, y, x);
	}
	else if(*dir == WEST && north == 1 && west == 1 && south == 1)
	{	
		*dir = EAST;
		d = EAST;
		movemouse(d, y, x);
	}
	else if(*dir == SOUTH && west == 1 && south == 1 && east == 1)
	{
		*dir = NORTH;
		d = NORTH;
		movemouse(d, y, x);
	}
	else if(*dir == EAST && north == 1 && south == 1 && east == 1)
	{
		*dir = WEST;
		d = WEST;
		movemouse(d, y, x);
	}


	else if(*dir == NORTH && west == 1 && east == 1)
	{
		*dir = NORTH;
		d = NORTH;
		movemouse(d, y, x);
	}
	else if(*dir == SOUTH && west == 1 && east == 1)
	{
		*dir = SOUTH;
		d = SOUTH;
		movemouse(d, y, x);
	}
	else if(*dir == WEST && north == 1 && south == 1)
	{
	 	*dir = WEST;
		d = WEST;
		movemouse(d, y, x);
	}
	else if(*dir == EAST && north == 1 && south == 1)
	{
		*dir = EAST;
		d = EAST;
		movemouse(d, y, x);
	}


	else if(*dir == NORTH && north == 1 && east == 1)
	{
		*dir = WEST;
		d = WEST;
		movemouse(d, y, x);
	}
	else if(*dir == WEST && north == 1 && west == 1)
	{
		*dir = SOUTH;
		d = SOUTH;
		movemouse(d, y, x);
	}
	else if(*dir == SOUTH && west == 1 && south == 1)
	{
		*dir = EAST;
		d = EAST;
		movemouse(d, y, x);
	}
	else if(*dir == EAST && south == 1 && east == 1)
	{
		*dir = NORTH;
		d = NORTH;
		movemouse(d, y, x);
	}


	else if(*dir == EAST && north == 1 && east == 1)
	{
		*dir = SOUTH;
		d = SOUTH;
		movemouse(d, y, x);
	}
	else if(*dir == NORTH && west == 1 & north == 1)
	{
		*dir = EAST;
		d = EAST;
		movemouse(d, y, x);
	}
	else if(*dir == WEST && west == 1 && south == 1)
	{
		*dir = NORTH;
		d = NORTH;
		movemouse(d, y, x);
	}
	else if(*dir == SOUTH && east == 1 && south == 1)
	{
		*dir = WEST;
		d = WEST;
		movemouse(d, y, x);
	}


	else if (*dir == EAST && east == 1)
	{
		*dir = NORTH;
		d = NORTH;
		movemouse(d, y, x);
	}
	else if (*dir == NORTH && east == 1)
	{
		*dir = WEST;
		d = WEST;			
		movemouse(d, y, x);
	}
	else if (*dir == WEST && east == 1)
	{
		*dir = SOUTH;
		d = SOUTH;
		movemouse(d, y, x);
	}
	else if (*dir == SOUTH && east == 1)
	{
		*dir = SOUTH;
		d = SOUTH;	
		movemouse(d, y, x);
	}


	else if (*dir == EAST && north == 1)
	{
		*dir = EAST;
		d = EAST;
		movemouse(d, y, x);
	}
	else if (*dir == NORTH && north == 1)
	{
		*dir = WEST;
		d = WEST;
		movemouse(d, y, x);
	}
	else if (*dir == WEST && north == 1)
	{
		*dir = SOUTH;
		d = SOUTH;
		movemouse(d, y, x);
	}
	else if (*dir == SOUTH && north == 1)
	{
		*dir = EAST;
		d = EAST;
		movemouse(d, y, x);
	}


	else if (*dir == EAST && west == 1)
	{
		*dir = NORTH;
		d = NORTH;
		movemouse(d, y, x);
	}
	else if (*dir == NORTH && west == 1)
	{
		*dir = NORTH;
		d = NORTH;
		movemouse(d, y, x);
	}
	else if (*dir == WEST && west == 1)
	{
		*dir = SOUTH;
		d = SOUTH;
		movemouse(d, y, x);
	}
	else if (*dir == SOUTH && west == 1)
	{
		*dir = EAST;
		d = EAST;
		movemouse(d, y, x);
	}


	else if (*dir == EAST && south == 1)
	{
		*dir = NORTH;
		d = NORTH;
		movemouse(d, y, x);
	}
	else if (*dir == NORTH && south == 1)
	{
		*dir = WEST;
		d = WEST;	
		movemouse(d, y, x);
	}
	else if (*dir == WEST && south == 1)
	{
		*dir = WEST;
		d = WEST;
		movemouse(d, y, x);
	}
	else if (*dir == SOUTH && south == 1)
	{
		*dir = EAST;
		d = EAST;
		movemouse(d, y, x);
	}


	else if (*dir == EAST && north == 0 && south == 0 && east == 0 && west == 0)
	{
		*dir = NORTH;
		d = NORTH;
		movemouse(d, y, x);
	}
	else if (*dir == SOUTH && north == 0 && south == 0 && east == 0 && west == 0)
	{
		*dir = EAST;
		d = EAST;
		movemouse(d, y, x);
	}
	else if (*dir == WEST && north == 0 && south == 0 && east == 0 && west == 0)
	{
		*dir = SOUTH;
		d = SOUTH;
		movemouse(d, y, x);
	}
	else if (*dir == NORTH && north == 0 && south == 0 && east == 0 && west == 0)
	{
		*dir = WEST;
		d = WEST;
		movemouse(d, y, x);
	}
}
