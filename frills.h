/*   File  : frills.h
     By    : Nathan Lam
     Login : nathancy
     Date  : 5/7/2015
     Team  : Hot Wings  */

/* This file contains frills. */
/* FRILLS ************************************************* */

/* Additional frills:
   - Default level is 0.
   - In level 2 and above, a new maze map is available.
   - The space command is drunken mouse. Moves the mouse randomly across 
     the map.
   - Hidden easter eggs. */

int random_mouse(void);
/* Given nothing, used when the user presses ' '. Returns either 1 or 2.
   The returned value is used to call on right or left hugger in Level 3 
   and generates random mouse movement. */



