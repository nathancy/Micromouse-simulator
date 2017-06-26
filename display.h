/*  File:  display.h
    By:    Tep Dobry
    login: tep
    Date:
 */

/*  This file contains the prototypes for useful funcitons in the display.o
	  library  */

#define MAXR 16
#define MAXC 16

#define TRUE 99
#define FALSE 98

#define NORTH 0
#define EAST  1
#define WEST  2
#define SOUTH 3
#define CRASH 4

/* This function initializes the display environment and clears the screen
   and draws the template maze from the local file maze.template.  The
   parameter, level, determines the level of difficulty (see the spec).
   For Level 0 and 1 it also initializes the maze from the local file
   maze.dat.
 */
void init_display(int level);

/* This function shows the mouse at the row and col position headed in
   the direction dir. Available at all levels.
 */
void show_mouse(int dir, int row, int col);

/* This function writes the given message at one of the lines (0 to 10)
   on the bottom of the screen.  The string is truncated at 64 characters.
   Available at all levels.
 */
void write_message(char str[], int line);

/* This function clears the screen and shuts down the display environment
   Available at all levels.
 */
void clear_screen(void);

/*  This functions displays the position under the X and Y on the right
    of the screen.  Available at all levels.
 */
void show_position(int y, int x);

/*  This function displays the number of cells explored under CELLS on the
    right of the screen.  Available at Level 1 and higher.
 */
void show_cells(int cells);

/*  This function displays the number of unique cells explored under
    UNIQUE CELLS on the right of the screen. Available at Level 2 or higher.
 */
void show_unique_cells(int cells);

/*  This functions displays the mouse view of left, front and side walls
     under MOUSE CAM on the right side of the screen. Available at all
     levels.
 */
void mouse_cam(int left, int front, int right);

/*  This function indirectly returns the walls (1 for present, 0 of absent)
    in the cell y, x from the internal maze.  Avaliable only at Level 0
    or 1.
 */
void lvl0_get_walls(int y, int x, int *North, int *East, int *West, int *South);

/*  This function shows the given North, East, West and South walls
    (1 for present, 0 for absent) for the cell y, x on the screen.
    Avaliable only at Level 1 or higher.
 */
void put_walls(int y, int x, int North, int East, int West, int South);
