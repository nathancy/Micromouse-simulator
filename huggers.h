/* File  : huggers.h
   By    : Nathan Lam 
   Login : nathancy
   Team  : Hot Wings
   Date  : 5/6/2015  */

#include <stdio.h>

/* This file contains the prototypes for the right and left wall
   hugger functions. */


void right_hugger(int *dir, int *x, int *y, int north, int east, int west, int south);
/* Function is indirectly given the direction and coordinates, and directly    given the walls. It checks the surrounding walls in the next direction
   for each scenario and moves the mouse by hugging the right wall. */


void left_hugger(int *dir, int *x, int *y, int north, int east, int west, int south);
/* Function is indirectly given the direction and coordinates, and directly    given the walls. It checks the surrounding walls in the next direction
   for each scenario and moves the mouse by hugging the left wall. */

