/* File  : mousecam.c
   By    : Nathan Lam 
   Login : nathancy
   Team  : Hot Wings
   Date  : 5/6/2015  */

/* This file contains the function that obtains the north, west, and east
   view of the mouse. */

#include <stdio.h>
#include "display.h"
#include "functions.h"
#include "huggers.h"
#include "mousecam.h"
#define DEBUG

/* Function is indirectly given the direction and directly given the walls.
   It tests all possible scenarios and indirectly returns the view
   of the mouse by pointers. */
void dir_mousecam(int *dir, int *northcam, int *eastcam, int *westcam, int north, int south, int east, int west)
{

	if(*dir == NORTH && north == 1 && east == 1 && west == 1)
	{
		*northcam = 1;
		*eastcam = 1;
		*westcam = 1;
	}
	else if(*dir == WEST && north == 1 && west == 1 && south == 1)
	{	
		*northcam = 1;
		*eastcam = 1;
		*westcam = 1;
	}
	else if(*dir == SOUTH && west == 1 && south == 1 && east == 1)
	{
		*northcam = 1; 
		*eastcam = 1;
		*westcam = 1;
	}
	else if(*dir == EAST && north == 1 && south == 1 && east == 1)
	{
		*northcam = 1;
		*eastcam = 1;
		*westcam = 1;
	}


	else if(*dir == NORTH && west == 1 && east == 1)
	{
		*northcam = 0;
		*eastcam = 1;
		*westcam = 1;
	}
	else if(*dir == SOUTH && west == 1 && east == 1)
	{
		*northcam = 0;
		*eastcam = 1;
		*westcam = 1;
	}
	else if(*dir == WEST && east == 1 && south == 1)
	{
		*northcam = 0;
		*eastcam = 0;
		*westcam = 1;
	}
	else if(*dir == WEST && north == 1 && south == 1)
	{
		*northcam = 0;
		*eastcam = 1;
		*westcam = 1;
	}
	else if(*dir == EAST && north == 1 && south == 1)
	{
		*northcam = 0;
		*eastcam = 1;
		*westcam = 1;
	}
	

	else if(*dir == NORTH && north == 1 && east == 1)
	{
		*northcam = 1;
		*eastcam = 1;
		*westcam = 0;
	}
	else if(*dir == WEST && north == 1 && west == 1)
	{
		*northcam = 1;
		*eastcam = 1;
		*westcam = 0;
	}
	else if(*dir == SOUTH && north == 1 && west == 1)
	{
		*northcam = 0;
		*eastcam = 1;
		*westcam = 0;
	}
	else if(*dir == SOUTH && west == 1 && south == 1)
	{
		*northcam = 1;
		*eastcam = 1;
		*westcam = 0;
	}
	else if(*dir == EAST && south == 1 && east == 1)
	{
		*northcam = 1;
		*eastcam = 1;
		*westcam = 0;
	}
	

	else if(*dir == EAST && north == 1 && east == 1)
	{
		*northcam = 1; 
		*eastcam = 0;
		*westcam = 1;
	}
	else if(*dir == NORTH && west == 1 && north == 1)
	{
		*northcam = 1;
		*eastcam = 0;
		*westcam = 1;
	}
	else if(*dir == NORTH && west == 1 && south == 1)
	{
		*northcam = 0;	
		*eastcam = 0;
		*westcam = 1;
	}
	else if(*dir == WEST && west == 1 && south == 1)
	{
		*northcam = 1;
		*eastcam = 0;
		*westcam = 1;
	}
	else if(*dir == SOUTH && east == 1 && south == 1)
	{
		*northcam = 1;
		*eastcam = 0;
		*westcam = 1;
	}
	else if(*dir == WEST && east == 1 && north == 1)
	{
		*northcam = 0;
		*eastcam = 1;
		*westcam = 0;
	}
	
	
	else if(*dir == EAST && east == 1)
	{
		*northcam = 1;
		*eastcam = 0;
		*westcam = 0;
	}
	else if(*dir == NORTH && east == 1)
	{
		*northcam = 0;
		*eastcam = 1;
		*westcam = 0;
	}
	else if(*dir == WEST && east == 1)
	{
		*northcam = 0;
		*eastcam = 0;
		*westcam = 0;
	}
	else if(*dir == SOUTH && east == 1)
	{
		*northcam = 0;
		*eastcam = 0;
		*westcam = 1;
	}


	else if(*dir == EAST && north == 1)
	{
		*northcam = 0;
		*eastcam = 0;
		*westcam = 1;
	}
	else if(*dir == NORTH && north == 1)
	{
		*northcam = 1;
		*eastcam = 0;
		*westcam = 0;
	}
	else if(*dir == WEST && north == 1)
	{
		*northcam = 0;
		*eastcam = 1;
		*westcam = 0;
	}
	else if(*dir == SOUTH && north == 1)
	{
		*northcam = 0;
		*eastcam = 0;
		*westcam = 0;
	}

	
	else if(*dir == EAST && south == 1)
	{
		*northcam = 0;
		*eastcam = 1;
		*westcam = 0;
	}
	else if(*dir == NORTH && south == 1)
	{
		*northcam = 0;
		*eastcam = 0;
		*westcam = 0;
	}
	else if(*dir == WEST && south == 1)
	{
		*northcam = 0;
		*eastcam = 0;
		*westcam = 1;
	}
	else if(*dir == SOUTH && south == 1)
	{
		*northcam = 1;
		*eastcam = 0;
		*westcam = 0;
	}
	

	else if(*dir == EAST && west == 1)
	{
		*northcam = 0;
		*eastcam = 0;
		*westcam = 0;
	}
	else if(*dir == NORTH && west == 1)
	{
		*northcam = 0;
		*eastcam = 0;
		*westcam = 1;
	}
	else if(*dir == WEST && west == 1)
	{
		*northcam = 1;
		*eastcam = 0;
		*westcam = 0;
	}
	else if(*dir == SOUTH && west == 1)
	{
		*northcam = 0;
		*eastcam = 1;
		*westcam = 0;
	}


	else if(*dir == EAST && north == 0 && east == 0 && south == 0 && west == 0)
	{
		*northcam = 0;
		*eastcam = 0;
		*westcam = 0;
	}
	else if(*dir == SOUTH && north == 0 && east == 0 && south == 0 && west == 0)
	{
		*northcam = 0;
		*eastcam = 0;
		*westcam = 0;
	}
	else if(*dir == WEST && north == 0 && east == 0 && south == 0 && west == 0)
	{
		*northcam = 0;
		*eastcam = 0;
		*westcam = 0;
	}
	else if(*dir == NORTH && north == 0 && east == 0 && south == 0 && west == 0)	
	{
		*northcam = 0;
		*eastcam = 0;
		*westcam = 0;
	}
}

