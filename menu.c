/* File  : menu.c
   By    : Nathan Lam 
   Login : nathancy
   Team  : Hot Wings
   Date  : 4/25/2015  */

#include <stdio.h>
#include "display.h"
#include "functions.h"
#include "huggers.h"
#include "colors.h"
#define DEBUG

/* This file contains the main driver that loads the splash screen
   and opens the simulator of the desired level. */

/* *************************** */
/* Define if want to use display */
#define DISPLAY
/* *************************** */

main()
{
int level;

/* Print splash screen */
printf("\t\t\t\t\t\t\t\t\t     +++\n");
printf("\v\v\v");
printf("\t\t\t       WELCOME TO MAZERUNNER\n\n\n");
printf("The Levels are: \n\n");
printf( C "\tLevel 0: Drive the Mouse.\n" RESET);
printf("\t\tYou may use the a,s,d,w commands in the predefined\n");
printf("\t\tvisible maze.\n");
printf("\n");
printf( G "\tLevel 1: Mouse Discovers.\n" RESET);
printf("\t\tYou may use Level 0 commands, r, l, and m commands in the\n");
printf("\t\tpredefined hidden maze.\n\n");
printf( B "\tLevel 2: Mouse Explores.\n" RESET);
printf("\t\tYou may use Level 1 commands and the n command.\n\n");
printf( R "\tLevel 3: Da Frills.\n" RESET);
printf("\t\tYou may use all above commands and the space command.\n\n");
printf( M "\t\tAdditional Frills: \n" RESET);
printf("\t\t    - Default level is 0.\n");
printf("\t\t    - In level 2 and above, a new maze map is available.\n");
printf("\t\t    - The space command is drunken mouse. Moves the mouse\n");
printf("\t\t      randomly across the map.\n");
printf("\t\t    - Hidden easter eggs.\n");
printf("\v\v\v\v\v\v\v\v\v\v\vNote: Maze-runner runs best in a 80 col x 48 line window. If you do not see +++ in the upper right and lower left of the screen, your window is too small.\n");
printf("\v\v\v\v\n");

printf("+++   What level do you want to run? ");

/* Default level zero */
level = 0;

/* Get level */
scanf("%d", &level);

#ifdef DEBUG
printf("DEBUG: %d\n", level);
#endif

/* Simulator level 1 */
if(level == 1)
{
	#ifdef DISPLAY
	level1(level);
	//printf("Display lv1\n");
	#else
	printf("No display Lv1\n");
	#endif
}

/* Simulator level 2 */
else if (level == 2)
{
	#ifdef DISPLAY
	level2(level);
	//printf("Display lv2\n");
	#else
	printf("No display lv2\n");
	#endif
}

/* Simulator level 3 */
else if (level >= 3)
{
	#ifdef DISPLAY
	level3(level);
	//printf("Display Lv3\n");
	#else
	printf("No display Lv3\n");
	#endif
}

/* Simulator level 0 */
else
{
	#ifdef DISPLAY
	level0(level);
	//printf("Display Lv0\n");
	#else
	printf("No display Lv0\n");
	#endif
}
}
