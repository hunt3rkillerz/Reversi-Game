/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : Alex R***
 * Student Number   : S***
 * Course Code      : BP094
 * Program Code     : COSC1076
 * Start up code provided by Paul Miller 
 **********************************************************************/

#include "game.h"

/**
 * The heart of the game itself. You should do ALL initialisation required 
 * for the game in here or call function required for that purpose. For example
 * both players should be initialised from here, you should seed the random 
 * number generator, that kind of thing. 
 *
 * Next, you should set the initial player - the initial player is the player 
 * whose token was set by initialisation to RED. 
 *
 * Next, you will need to manage the game loop in here. In each loop of the 
 * game, you should display the game board, including player scores 
 * display whose turn it is, etc in the format specified in the assignment
 * specification. Finally at the end of each turn you will calculate the score 
 * for each player you will calculate their score and store it and then you 
 * will need to swap the current player and other player 
 * using the swap_player() function. 
 * 
 * A game will end when either player presses enter or ctrl-d on a newline. 
 * 
 * When you detect a request to end the game, you should do a final calculation
 * of the scores for the two players and return the player with the highest
 * score.
 **/
struct player *play_game(struct player * first, struct player * second)
{
	game_board board;
	enum cell token;
	int count, totalPieces;
	/* seeding the random number generator */
    srand(time(NULL));
    count = 1;
	struct player *current, *other, *winner;

    if(!init_first_player(first, &token))
    {
    	return NULL;
    }
    if(!init_second_player(second, token))
    {
    	return NULL;
    }


    if(token == RED)
	{
    	current = first;
    	other = second;
	}
    else
    {
    	current = second;
     	other = first;
    }

	init_game_board(board);
    while(TRUE)
    {
        display_board(board, first, second);
        /* makes move */
        if(!make_move(current, board))
        {
        	/* Winner is the person who didn't quit */
        	return other;
        }

        current->score = game_score(board, current->token);

        totalPieces = STARTINGPIECES + count;

        other->score = (totalPieces - current->score);

        count++;
        if(count == MAXTURNS+1)
        {
        	break;
        }

        swap_players(&current, &other);
    }

    if(current->score > other->score)
    {
    	return current;
    }
    else
    {
    	return other;
    }
}

/**
 * does the work of applying the move requested by the user to the game board.
 * It iterates over all the directions from the coordinate specified to see
 * whether there are any pieces that can be captured. If there are no pieces
 * that can be captured in any direction, it is an invalid move.
 **/
BOOLEAN apply_move(game_board board, unsigned y, unsigned x,
                   enum cell player_token)
{
	/* Used to keep the later parts clear */
	int width = x;
	int height = y;
	/* Used for Loop control */
	int right, up;
	/* Used to calc relative distance to end point of calculation */
	int checkHorizontal, checkVertical;
	int endX, endY;
	/* Temporary variable used to hold check vertical and check horizontal without effecting program logic on later cycles */
	int tempH;
	int dynBoundX, dynBoundY;
	height--;
	width--;
	enum cell defense;
	/* Lets the computer know who you want to destroy */
	if(player_token == RED)
	{
		defense = BLUE;
	}
	else
	{
		defense = RED;
	}

	/*
	 * Really Ugly and really complex double loop structure,
	 * essentially what this does is we are setting the starting
	 * position to NW then incrementing it down vertically, so it will go
	 * NW, W, SW. After that we increment it 1 to the right so it goes
	 * N, then we continue the loop as we don't want to check the position of the block,
	 * then we check S and the we increment right again and check
	 * NE, E, SE.
	 * Hopefully this clarifies what is going on here
	 */

	/*
	 * CheckHorizontal and CheckVertical are supposed to find the distance between the
	 * edge and the piece
	 */

	for(right = -1, dynBoundX = -1; right <= 1; right++, dynBoundX += 9)
	{
		checkHorizontal = width + (right * 2);
		if(right==0){dynBoundX=-1;}
		for(up = -1, dynBoundY = -1; up <= 1; up++, dynBoundY += 9)
		{
			checkVertical = height + (up * 2);
			if(up == 0){dynBoundY = -1;}
			/* skipping the location of the actual token that has been placed */
			if(right == 0 && up == 0)
			{
				continue;

			}

			if(board[(width + right)][(height + up)] == defense)
			{


				tempH = checkHorizontal;
				while(checkVertical != (dynBoundY) && tempH != (dynBoundX))
				{
					endX = width;
					endY = height;
					/* kills it if it is next to a blank square */
					if(board[tempH][checkVertical] == BLANK)
					{
						break;
					}
					/* detects all the captureable squares */
					if(board[tempH][checkVertical] == defense)
					{
						checkVertical += up;
						tempH += right;
						continue;
					}
					/* captures squares */
					if(board[tempH][checkVertical] == player_token)
					{
						if(up == 0){checkVertical = -1;}
						if(right == 0){tempH = -1;}
						while(endX != tempH && endY != checkVertical && endX >= 0 && endY >= 0)
						{
							board[endX][endY] = player_token;
							endX += right;
							endY += up;
						}

					}
					break;
				}
			}
		}
	}
	return TRUE;
}

/**
 * simply count up how many locations contain the player_token 
 * specified on the game_board.
 **/
unsigned game_score(game_board board, enum cell player_token)
{
    int i, j, points;
    /* Counting the amount of different colors */
    points = 0;
    for (i = 0; i < BOARD_HEIGHT; i++)
    {

        for (j = 0; j < BOARD_WIDTH; j++)
        {

            if(board[i][j] == player_token)
            {
            	points++;
            }
        }

    }
    return points;
}

/**
 * swap the two player pointers passed in so that first points to the player
 * pointer that originally contained the second player and vice versa.
 **/
void swap_players(struct player ** first, struct player ** second)
{
	struct player *change;
	change = *first;
	*first = *second;
	*second = change;

}
