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
#include "gameboard.h"
#include "utility.h"

#ifndef PLAYER_H
#define PLAYER_H
/* the maximum length of a player name */
#define NAMELEN 20
/* the number of characters allowed when the user is entering the coordinates
 * for a game
 */

/* what are the attributes of a player? They have a score, a token (either BLUE
 * or RED), and a score
 */
struct player
{
    char name[NAMELEN + 1];
    enum cell token;
    unsigned score;
};

BOOLEAN init_first_player(struct player* first, enum cell * token);
BOOLEAN init_second_player(struct player * second, enum cell token);
BOOLEAN make_move(struct player * human, game_board board);
BOOLEAN findAMove(game_board board, int width, int height, enum cell tokenColor);
BOOLEAN makeAMove(game_board board, int width, int height, enum cell tokenColor);

#endif /* ifndef PLAYER_H */
