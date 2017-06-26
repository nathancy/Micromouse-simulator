/* File  : level0.c
   By    : Nathan Lam 
   Login : nathancy
   Team  : Hot Wings
   Date  : 4/25/2015  */

/* This file contains the function that loads the simulator to level 0 with all of its features and capabilities */

#include <stdio.h>
#include "display.h"
#include "functions.h"
#define DEBUG

/* Function is given '0'. It sends the mouse to the level 0 simulator
   with its features as determined in the spec. */
void level0(int level)
{
  /* Declare variables */
  int north, east, ready, south, west, x, y, dir, direction, row, col,
      spaceerror, d_error, checker, win;
  char input, ch, restart, flagrestart;

  /* Write strings to arrays */
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

  /* Initiate values for simulator */
  x = 0;
  y = 0;

  /* Set initial flags */
  flagrestart = FALSE;
  win = FALSE;
  d_error = TRUE;
  ready = TRUE;
  dir = NORTH;

  /* Initiate the display to level 0*/
  init_display(level);

  /* Show the mouse in starting position */
  show_mouse(dir, x, y);

  /* Show the initial x and y coordinates */
  show_position(x, y);

  /* Write the initial ready message */
  write_message(str, 10);

  /* Initiate the walls */
  lvl0_get_walls(x, y, &north, &east, &west, &south);

  /* Get command */
  input = getchar();
  if(input == '\n')
  {
    input = getchar();
  }

  /* As long as command is not quit */
  while (input != 'q')
  {

    /* Clear win message when flag is triggered */
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
      case 'a' :
                 dir = getdirection(input, dir);
                 break;
      case 's' :
                 dir = getdirection(input, dir);
                 break;
      case 'd' :
                 dir = getdirection(input, dir);
                 break;
      /* Move in direction */
      case 'w' :
                 /* Print initial ready message */
                 if(ready == TRUE)
                 {
                    write_message(blank, 10);
                    ready = FALSE;
                 }

                 /* Clear win message if user restarts */
                 if(flagrestart == TRUE)
                 {
                    write_message(blank, 10);
                    flagrestart == FALSE;
                 }
                 /* Clear error message for default error */
                 if(d_error == TRUE || spaceerror == TRUE)
                 {
                    write_message(blank, 2);
                    d_error = FALSE;
                    spaceerror = FALSE;
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

      /* Print error messages */
      case 'm' :
                 write_message(m, 9);
                 break;
      case 'n' :
                 write_message(n, 9);
                 break;
      case 'r' :
      case 'l' :
                 write_message(lr, 9);
                 break;
      case ' ' : write_message(space, 9);
                 write_message(error, 2);
                 spaceerror = TRUE;
                 break;
      default  :
                 if (d_error == FALSE)
                 {
                    write_message(error, 2);
                 }
                 d_error = TRUE;
    }

    /* Show mouse on display */
    show_mouse(dir, x, y);

    /* Show change of x and y coordinates */
    show_position(x, y);

    /* Print win messages if win */
    if ((x == 8 || x == 7) && (y == 8 || y == 7))
    {
      write_message("WIN!!", 3);
      write_message("    WIN!!", 2);
      write_message("        WIN!!",1);
      win = TRUE;
    }

    /* Print crash messages if crash */
    if (dir == CRASH)
    {
      write_message(crash1, 3);
      write_message(crash2, 2);
      write_message(crash3, 1);
      write_message(res, 10);

      /* If user wants to restart */
      if((getchar()) == 'y')
      {
        /* Initiate game to beginning */
        x = 0;
        y = 0;
        dir = NORTH;

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

        /* Show coordinates at start position */
        show_position(x, y);
      }

      /* Close game if user does not want to restart */
      else
      {
        break;
      }
    }

    /* Get walls for next coordinate */
    lvl0_get_walls(x, y, &north, &east, &west, &south);

    /* Get next command */
    input = getchar();
  }

  /* Close the maze */
  clear_screen();
}
