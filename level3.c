/* File  : level3.c
   By    : Nathan Lam 
   Login : nathancy
   Team  : Hot Wings
   Date  : 5/7/2015  */

#include <stdio.h>
#include "display.h"
#include "functions.h"
#include "huggers.h"
#include "mousecam.h"
#include "frills.h"
#define DEBUG

/* This file contains the function that loads the simulator to level 3 
   with all of its features and capabilities. */

void level3(int level)
/* Function is given '3'. It sends the mouse to the level 3 simulator with
   all of the features from past levels, any other features as stated 
   from the spec, and frills (random mouse movement and easter eggs). */
{

/* Declare variables */
int maze[MAXR][MAXC], *northcam, *southcam, *eastcam, *westcam, ncam, 
    ecam, wcam, north, east, ready, south, west, x, y, dir, direction, 
    row, col, d_error, checker, win, cells, unique_c, random, frillflag, 
    tep_flag, kellen_flag;
char input, ch, restart, flagrestart;

/* Write strings to arrays (shortcut) */
char blank[64] = "                   ";
char str[64] = "Ready?";
char error[64] = "What??";
char m[64] = "Maze cheat now available at Level 0";
char n[64] = "Maze uncheat not available below Level 2";
char lr[64] = "Wall hugger not available at Level 0";
char space[64] = "No mouse's choice";
char crash1[64] = "CRASH";
char crash2[64] = "   CRASH";
char crash3[64] = "      CRASH";	
char res[64] = "Restart (y/n)?";
char rand[64] = "Random mouse activated";

/* Initiate values for the simulator */
unique_c = 0;
x = 0;
y = 0;
cells = 0;

/* Set initial flags */
flagrestart = FALSE;
win = FALSE;
d_error = TRUE;
ready = TRUE;
dir = NORTH;

    /* Initiate the display to level 3 */
	init_display(level);

    /* Show the mouse in starting position */
	show_position(x, y);

    /* Write initial ready message */
	write_message(str, 10);

    /* Initiate mouse cam to starting position */
	mouse_cam(1,0,1);
 
    /* Show initial number of cells on display */
	show_cells(cells);
    
    /* Show number of unqiue cells on display */
	show_unique_cells(0);

    /* Initiate unique flags */
	starcraft_cheesemap_editor(maze);

    /* Initiate walls for new maze */
	getwall_newmaze(x, y, &north, &east, &west, &south);

    /* Display the walls on the screen */
	put_walls(x, y, north, east, west, south);

    /* Show the mouse in starting position */
	show_mouse(dir, x, y);

    /* Get command */		
	input = getchar();
	if(input == '\n')
	{
		input = getchar();
	} 
	
    /* As long as command is not quit */
	while (input != 'q')
	{
	    /* Clear win messages when flag is triggered */
		if (win == TRUE)
		{
			write_message(blank, 3);
			write_message(blank, 2);
			write_message(blank, 1);
			win == FALSE;
		}

		switch(input)
		{
		    /* Change direction */
			case 'a' : dir = getdirection(input, dir);
				   break; 
			case 's' : dir = getdirection(input, dir);
				   break;
			case 'd' : dir = getdirection(input, dir);
				   break;
		    /* Move forward in new direction */
			case 'w' : 
			       /* Increment number of cells */
				   cells ++;

			       /* Clear initial ready message */
				   if(ready == TRUE)
				   {
				   	write_message(blank, 10);
				        ready = FALSE;
				   }
		
			       /* Clear message if user uses spacebar */
				   if(frillflag == TRUE)
				   {
					write_message(blank, 8);
					frillflag = FALSE;
				   }

			       /* Clear win message if user restarts */
				   if(flagrestart == TRUE)
				   {
					write_message(blank, 10);
				        flagrestart == FALSE;
				   }
		
			       /* Clear error message for default errors */
			 	   if(d_error == TRUE)
				   {
					write_message(blank, 2);
				 	d_error = FALSE;
				   }

			       /* Clear message for MVP flags */
				   if(tep_flag == TRUE) 
				   {
					write_message(blank, 8);
					tep_flag = FALSE;
				   }

				   if(kellen_flag == TRUE)
				   {
					write_message(blank, 8);
					kellen_flag = FALSE;
				   }

			       /* Check for crash */
				   checker = checkcrash(dir, &north, &east, &west, &south);
			       
			       /* If crash, change direction to crash */
				   if (checker == TRUE)
				   { 
			           	dir = CRASH;
				   }
			
			       /* If did not crash, move the mouse */
				   else
				   {
					movemouse(dir, &y, &x); 
				   }
				   break;

		    /* Reveal the maze */ 
			case 'm' : cheese_scope_v2();
				   break;

		    /* Hide the maze */
			case 'n' : hide_me_cheese(maze);
				   break;

		    /* Right wall hugger */
			case 'r' : 
			       /* Clear messages if flags were triggered */
				   if(ready == TRUE)
				   {
				   	write_message(blank, 10);
				        ready = FALSE;
				   }
		
				   if(flagrestart == TRUE)
				   {
					write_message(blank, 10);
				        flagrestart == FALSE;
				   }
			 	   if(d_error == TRUE)
				   {
					write_message(blank, 2);
				 	d_error = FALSE;
				   }

				   if(tep_flag == TRUE)
				   {
					write_message(blank, 8);
					tep_flag = FALSE;
				   }

			           if(kellen_flag == TRUE)
				   {
					write_message(blank, 8);
					kellen_flag = FALSE;
				   }	

				   if(frillflag == TRUE)
				   {
					write_message(blank, 8);
					frillflag = FALSE;
				   }

			      /* Move mouse along right wall */
				   right_hugger(&dir, &x, &y, north, east, west, south);
			      /* Increment numbre of cells */
				   cells ++;
				   break;

		    /* Left wall hugger */
			case 'l' : 
			      /* Clear messages if flags were triggered */
				   if(ready == TRUE)
				   {
				   	write_message(blank, 10);
				        ready = FALSE;
				   }
		
				   if(tep_flag == TRUE)
				   {
					write_message(blank, 8);
					tep_flag = FALSE;
				   }

			           if(kellen_flag == TRUE)
				   {
					write_message(blank, 8);
					kellen_flag = FALSE;
				   }	

				   if(flagrestart == TRUE)
				   {
					write_message(blank, 10);
				        flagrestart == FALSE;
				   }

			           if(d_error == TRUE)
				   {
					write_message(blank, 2);
				 	d_error = FALSE;
				   }

				   if(frillflag == TRUE)
				   {
					write_message(blank, 8);
					frillflag = FALSE;
				   }

			       /* Move mouse along left wall */
				   left_hugger(&dir, &x, &y, north, east, west, south);
			       /* Increment number of cells */
				   cells ++;
				   break;

		    /* Random mouse movement (mouse's choice to move) */
			case ' ' : 
			       /* Increment number of cells */
				   cells ++;

			       /* Change flag */
				   frillflag = TRUE;

			       /* Clear messages if flags were triggered */ 
				   if(ready == TRUE)
				   {
				   	write_message(blank, 10);
				        ready = FALSE;
				   }
		
				   if(tep_flag == TRUE)
				   {
					write_message(blank, 8);
					tep_flag = FALSE;
				   }

			           if(kellen_flag == TRUE)
				   {
					write_message(blank, 8);
					kellen_flag = FALSE;
				   }	

				   if(flagrestart == TRUE)
				   {
					write_message(blank, 10);
				        flagrestart == FALSE;
				   }

			 	   if(d_error == TRUE)
				   {
					write_message(blank, 2);
				 	d_error = FALSE;
				   }

			       /* Get random number */
				   random = random_mouse();

			       /* Move mouse along right wall */
				   if(random == 1)
				   {
					right_hugger(&dir, &x, &y, north, east, west, south);
				   }

			       /* Move mouse along left wall */
				   else
				   {
					left_hugger(&dir, &x, &y, north, east, west, south);
				   }

			       /* Print frill message */
				   write_message(rand, 8);
				   break;

		    /* Print easter eggs messages */
			case 't' : write_message("HI PROFESSOR TEP! :D", 8);
				   tep_flag = TRUE;
				   break;

			case 'k' : write_message("HI KELLEN! :D", 8);
				   kellen_flag = TRUE;
				   break;	
		
		    /* Print error messages */
			default  : if (d_error == FALSE)
				   {
					write_message(error, 2);
				   }
				   d_error = TRUE;
		}

	    /* Get walls for next coordinate in newmaze */
		getwall_newmaze(x, y, &north, &east, &west, &south);

	    /* Get direction for mousecam */
		dir_mousecam(&dir, &ncam, &ecam, &wcam, north, south, east, west);

	    /* Show mousecam to display */
		mouse_cam(wcam, ncam, ecam);

	    /* Print win messages */	
		if ((x == 8 || x == 7) && (y == 8 || y == 7))
		{	
			write_message("WIN!!", 3);
			write_message("    WIN!!", 2);
			write_message("        WIN!!",1);
			win = TRUE;
		}
	
	    /* Print crash messages */
		if (dir == CRASH)
		{
		    /* Show crashed mouse */
			show_mouse(dir, x, y);

			write_message(crash1, 3);
			write_message(crash2, 2);
			write_message(crash3, 1);
			write_message(res, 10);

		    /* If user wants to restart */		
			if((getchar()) == 'y')
			{
			    /* Initiate maze to beginning */
				x = 0;
				y = 0;
				cells = 0;
				dir = NORTH;
				mouse_cam(1,0,1);
				
			    /* Initiate walls in newmaze to beginning */
				getwall_newmaze(x, y, &north, &east, &west, &south);
			    /* Clear old crash messages */
				write_message(blank, 3);
				write_message(blank, 2);
				write_message(blank, 1);
				write_message(blank, 10);
				write_message(str, 10);

			    /* Set restart flag */
				flagrestart = TRUE;
		 
	  		    /* Show mouse at start position */
				show_mouse(dir, x, y);
			  
	   	 	    /* Show corrdinates at start position */
				show_position(x, y);
				
			}

		    /* Close game if user does not want to restart */
			else
			{
				break;
			}
		}

	    /* Change unique cell flag from unpassed to passed */
		if (maze[x][y] == 0)
	        {
			maze[x][y] = 1;

		    /* Increment unique cell counter */
			unique_c++;
                }

	    /* Show number of unique cells on display */
		show_unique_cells(unique_c);

	    /* Show number of cells on display */
		show_cells(cells);

	    /* Show mouse on display */
		show_mouse(dir, x, y);

	    /* Place walls onto display */
		put_walls(x, y, north, east, west, south);
		
	    /* Show new coordinates on display */
		show_position(x, y);

	    /* Get next command */
		input = getchar();
	}

    /* Close the maze */
	clear_screen();
}
