/*   File  : functions.h
     By    : Nathan Lam
     Login : nathancy
     Date  : 5/2/2015
     Team  : Hot Wings  */

#include <stdio.h>

/* This file contains the prototypes for the additional features 
   as determined by the choosen maze level. */

void level0(int level);
/* Function is given '0' and returns nothing. Function sends the mouse to 
   THE DEPTHS OF MAZE LEVEL 0. Allows the user user to navigate 
   using a,s,d,w and keeps track of the X and Y coordinates as
   the mouse travels until it dies from the CHEESE GRATER. */


void level1(int level);
/* Function is given '1' and returns nothing. The function sends the 
   mouse to THE DEPTHS OF MAZE LEVEL 1. In addition to all of the 
   features in level 0, allows the user to use the r, l, and m 
   commands, keeps a counter of passed cells and has a "mouse cam". */


void level2(int level);
/* Function is given '2' and returns nothing. Function sends the 
   mouse to THE DEPTHS OF MAZE LEVEL 2. Allows the user to 
   utilize the n command and keeps a counter of "unique" cells 
   in addition to all of the features of previous levels. */


void level3(int level);
/* Function is given '3' and returns nothing. Function sends the 
   mouse to THE DEPTHS OF MAZE LEVEL 3. Allows the user to use 
   any previous commands in addition to the the "space" 
   command which hacks the map and teleports the mouse to CHEESE LAND. */


int getdirection(char input, int direction);
/* Function is given the input (a,s,d) and the previous direction.  
   It determines the new direction that the mouse heads in and returns 
   that value. Available at all levels. */


void movemouse(int dir, int *x, int *y);
/* Given the direction and previous coordinates. Returns nothing. 
   Changes the x and y coordinates indirectly through pointers 
   to the next cell. Available at all levels. */ 


int checkcrash(int dir, int *north, int *south, int *west, int *east);
/* Function is given the direction and the surrounding walls. It checks if 
   there is wall in the desired direction. If the mouse crashes in the 
   desired direction, returns TRUE. If there is no wall, returns 
   FALSE. Available at all levels. */


void cheese_scope(void);
/* Given nothing and returns nothing. Function uses the power of the 
   cheesescope located at mouse-headquarters to scout out the 
   location of surrounding cheese mines. When m is pressed, the 
   cheesescope will come to the aid of any adventerous cheese hunter 
   by revealing the entire maze. Available at levels 1 and higher. */


void getwall_newmaze(int y, int x, int *north, int *east, int *west, int *south); 
/* Given the coordinates and walls. Function draws the walls for the 
   new maze. The mouse is teleported to a new dungeon where its goal 
   is to find the cheese stash in the center of the maze. It maps 
   the walls for each x and y coordinate according to newmaze.dat. 
   Available at level 2 and higher. */


void cheese_scope_v2(void);
/* Given nothing and returns nothing. Function uses mouse space cam 
   technology to scout the entire maze. When the user presses "m", 
   the whole map is revealed. Available	at level 2 and higher. */


void hide_me_cheese(int maze[MAXR][MAXC]);
/* Given an array and returns nothing. Function hides the map of the 
   new maze utilizing a remodeled version of cheese_scope. It clears 
   the current maze, checks each coordinate to see if it was passed 
   through, and prints the walls of passed coordinates. Available at 
   level 2 and higher. */


void starcraft_cheesemap_editor(int maze[][MAXC]);
/* Given an array and returns nothing. Function clears the current 
   map and initiates unqiue cell flags to 0 (unpassed cells). Available 
   at level 2 and higher. */

