/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : Alex R***
 * Student Number   : S***
 * Course Code      : BP094
 * Program Code     : COSC1076
 * Start up code provided by Paul Miller 
 **********************************************************************/

#include "shared.h"
#include <limits.h>
#ifndef UTILITY_H
#define UTILITY_H

/* the default line length for input / output */
#define LINELEN 80
/* Max player name size */
#define PLAYERNAMELENGTH 20
/* Defines the max length of a co-ords string */
#define COORDSLENGTH 3
/* the last two characters required in a string as returned from fgets */
#define EXTRACHARS 2

/* The number of character the main menu expects */
#define MENULENGTH 1

/* newline character required for I/O functions */
#define NEWLINE '\n'

#define STARTINGPIECES 4

#define MAXTURNS 60

void read_rest_of_line(void);
#endif /* ifndef UTILITY_H */
