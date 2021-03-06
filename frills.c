/*   File  : frills.c
     By    : Nathan Lam
     Login : nathancy
     Date  : 5/7/2015
     Team  : Hot Wings  */

/* Additional frills:
   - Default level is 0.
   - In level 2 and above, a new maze map is available.
   - The space command is drunken mouse. Moves the mouse randomly across
     the map.
   - Hidden easter eggs. */

/* This file contains the function for generating random mouse movement. */

#include <stdio.h>
#include "display.h"
#include "mousecam.h"
#include "huggers.h"
#include "functions.h"
#include "frills.h"

/* Given nothing, function returns either '1' or '2'. Used to generate
   random mouse movement. */
int random_mouse(void)
{
    /* Change the seed */
    srand(time(NULL));
    int random_value;

    /* Get value of 1 or 2 */
    random_value = (rand() % 2 + 1);

    return random_value;
}
