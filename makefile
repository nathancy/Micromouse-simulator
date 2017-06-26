# Makefile for compiling the maze

mazerunner: menu.o display.o level0.o level1.o functions.o huggers.o mousecam.o level2.o level3.o frills.o
	cc menu.o display.o level0.o functions.o level1.o huggers.o mousecam.o level2.o level3.o frills.o -o mazerunner -lncurses

level0.o: display.h functions.h 

level1.o: display.h functions.h huggers.h mousecam.h

level2.o: display.h functions.h huggers.h mousecam.h 

level3.o: display.h functions.h huggers.h mousecam.h 

mousecam.o: display.h functions.h mousecam.h

functions.o: functions.h display.h mousecam.h

frills.o: functions.h display.h mousecam.h huggers.h frills.h

huggers.o: functions.h display.h huggers.h mousecam.h

menu.o: display.h functions.h huggers.h colors.h

display.o: display.h

clean:
	rm frills.o
	rm functions.o
	rm huggers.o
	rm level0.o
	rm level1.o
	rm level2.o
	rm level3.o
	rm menu.o
	rm mousecam.o
	rm mazerunner
