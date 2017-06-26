/*   File  : mousecam.h
     By    : Nathan Lam
     Login : nathancy
     Date  : 5/2/2015
     Team  : Hot Wings  */

/* This file contains the prototype for getting the direction of the
   mousecam. */

#include <stdio.h>
#include "display.h"
#define TRUE 99
#define FALSE 98

/* Function is indirectly given the direction and directly given the walls.
   It tests all possible scenarios and indirectly returns the view
   of the mouse by pointers. */
void dir_mousecam(int *dir, int *northcam, int *eastcam, int *westcam, int north, int south, int east, int west);
