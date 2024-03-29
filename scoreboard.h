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
#include "player.h"
#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#define MAX_SCORES 10
typedef struct player score;

void init_scoreboard(score scores[MAX_SCORES]);
BOOLEAN add_to_scoreboard(score scores[MAX_SCORES], struct player * winner);
void display_scores(score scores[MAX_SCORES]);
#endif /* ifndef SCOREBOARD_H */
