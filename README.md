# Micromouse-simulator
Micromouse simulator with four levels

[![Video](http://img.youtube.com/vi/Nb8YTFCTzjM/0.jpg)](https://www.youtube.com/watch?v=Nb8YTFCTzjM)

### Level 0: Drive the Mouse
You may use w,s,a,d commands in the predefined visible maze to control the mouse. Features:

* w - up
* s - down
* a - left
* d - right
* Entire maze is visible

### Level 1: Mouse Discovers
You may use Level 0 commands, r, l, and m, commands in the predefined hidden maze. Features:

* r - right wall hugger
* l - left wall hugger
* m - show maze 
* Mousecam
* Cell counter

### Level 2: Mouse Explores
You may use Level 1 commands and the n command.

* n - hide maze
* Unique cell count

### Level 3: Da Frills
You may use all above commands and the space command.

* Space - random movement (drunken mouse)

Additional Frills:
  - Default level is 0
  - In level 2 and above, a new maze map is available
  - Hidden easter eggs

# Developers Guide
Clone the repository with:
```
git clone https://github.com/nathancy/Micromouse-simulator.git
cd Micromouse-simulator
```
Build the simulator with:
```
make mazerunner
```
Run the simulator with:
```
mazerunner
```

Note: The simulator runs best in a 80 col x 48 line window. If your screen is too small, the maze may not appear correctly. 
