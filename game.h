/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : Alex R***
 * Student Number   : S***
 * Course Code      : BP094
 * Program Code     : COSC1076
 * Start up code provided by Paul Miller 
 **********************************************************************/

#include <time.h>
#include "shared.h"
#include "player.h"
#include "gameboard.h"


#ifndef GAME_H
#define GAME_H

struct player * play_game(struct player * first, struct player * second);
BOOLEAN apply_move(game_board board, unsigned y, unsigned x,
                   enum cell player_token);
unsigned game_score(game_board board, enum cell player_token);
void swap_players(struct player ** first, struct player ** second);

#endif /* ifndef GAME_H */
