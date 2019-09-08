/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : Alex R***
 * Student Number   : S***
 * Course Code      : BP094
 * Program Code     : COSC1076
 * Start up code provided by Paul Miller 
 **********************************************************************/
 
#include "player.h"
#include "game.h"

/**
 * These two functions initialise the player structure at the beginning of the 
 * game. In both cases, you should initialise the whole structure to known safe
 * values and then prompt the user for their name. In the init_first_player() 
 * function you should then select a color at random for this player using the 
 * rand() function. This token should be assigned to the first player's token and
 * also returned via the token pointer. In init_second_player() you should just
 * test the value of token and assign the opposite color to the second player.
 **/
BOOLEAN init_first_player(struct player* first, enum cell * token)
{
	/* Randomly assigns color */
	int color;
	/* not nearly random */
	color = rand();
	/* used to check for new line */
	char *nameChecker;
	first->score = 2;
	if(color%2 == 0)
	{
		first->token = BLUE;
		*token = BLUE;
	}
	else
	{
		first->token = RED;
		*token = RED;
	}
	/* gets and validates player name */
	while(TRUE)
	{
		printf("\nPlease enter a name for Player 1: ");
		/* Gets name and catches ctrl D */
		if(fgets(first->name, (PLAYERNAMELENGTH + EXTRACHARS), stdin) == 0)
		{
			return FALSE;
		}
		/* Makes sure the string isn't null */
		nameChecker = first->name;
		if('\n' == nameChecker[0])
		{
			return FALSE;
		}
		if(first->name[strlen(first->name) - 1] != '\n')
		{
			printf("Input was too long, try again. \n\n");
			read_rest_of_line();
			continue;
		}

		return TRUE;
	}
}

BOOLEAN init_second_player(struct player * second, enum cell token)
{
	/* used to check for new line */
	char *nameChecker;

	second->score = 2;
	if(token == RED)
	{
		second->token = BLUE;
	}
	else
	{
		second->token = RED;
	}
	/* gets and validates player name */
	while(TRUE)
	{
		printf("\nPlease enter a name for Player 2: ");

		if(fgets(second->name, (PLAYERNAMELENGTH + EXTRACHARS), stdin) == 0)
		{
			return FALSE;
		}
		/* Makes sure the string isn't null */
		nameChecker = second->name;
		if('\n' == nameChecker[0])
		{
			return FALSE;
		}
		if(second->name[strlen(second->name) - 1] != '\n')
		{
			printf("Input was too long, try again. \n\n");
			read_rest_of_line();
			continue;
		}
		return TRUE;
	}

}

/**
 * prompts the user for a comma-separate pair of coordinates for a move in the
 * game. Each move, if valid, must capture at least one enemy piece by 
 * surrounding a sequence of one or more enemy pieces with two pieces of our 
 * own: one being the new piece to be placed and the other a piece already 
 * on the board. This function then validates that a valid move has been entered
 * calls the apply_move function to do the actual work of capturing pieces.
 **/
BOOLEAN make_move(struct player * human, game_board board)
{
	int x, y;
	char move[COORDSLENGTH];
	while(TRUE)
	{
		printf("\nIt is %.*s's turn", (strlen(human->name) - 1), human->name);
		printf("\nPlease enter the Co-Ordinates of your move in the form x,y\n");

		/* Ensures they want to keep playing */
		if(fgets(move, (COORDSLENGTH + EXTRACHARS), stdin) == 0)
		{
			return FALSE;
		}
		if('\n' == move[0])
		{
			return FALSE;
		}
		/* Validates Length */
		if(move[strlen(move) - 1] != '\n')
		{
			read_rest_of_line();
			printf("Input was too long, try again in the form x,y. \n");
			continue;
		}

		/* Ensures it is separated by comma */
		if(move[1] != ',')
		{
			printf("You are required to separate x and y using a comma (,)\n");
			continue;
		}

		/* Checks x to make sure it is a number between 1-8 */
		if(!isdigit(move[0]) || move[0] == '0' || move[0] == '9')
		{
			printf("The x value must be a number between 1-8\n");
			continue;
		}

		/* Checks y to make sure it is a number between 1-8 */
		if(!isdigit(move[2]) || move[2] == '0' || move[2] == '9')
		{
			printf("The y value must be a number between 1-8\n");
			continue;
		}
		char* token;
		token = strtok(move,",");
		/* assigns x */
		x = *token - '0';
		token = strtok(NULL,"\0");
		/* assigns y */
		y = *token -'0';

		/* Start Checking for moves */

		if(findAMove(board, x, y, human->token) == FALSE)
		{
			continue;
		}
		if(apply_move(board, y, x, human->token) == FALSE)
		{
			continue;
		}
		/* End Checking for moves */

		/*Start Applying moves and capturing pieces */

		/*end applying moves and capturing pieces */

		return TRUE;
	}
}

BOOLEAN findAMove(game_board board, int width, int height, enum cell tokenColor)
{
	int right, up;
	int checkHorizontal, checkVertical;
	int dynBoundX, dynBoundY;
	height--;
	width--;
	enum cell defense;
	/* Lets the computer know who you want to destroy */
	if(tokenColor == RED)
	{
		defense = BLUE;
	}
	else
	{
		defense = RED;
	}

	if(board[width][height] != BLANK)
	{
		printf("\nThere is already a piece there (nice try though), please make a legal move\n");
		return FALSE;
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
		for(up = -1, dynBoundY = -1; up <= 1; up++, dynBoundY +=9)
		{
			checkHorizontal = width + (right * 2);

			if(right==0){dynBoundX=-1;}


			checkVertical = height + (up * 2);
			if(up == 0 ){dynBoundY = -1;}
			if(right == 0 && up == 0)
			{
				continue;
			}

			if(board[(width + right)][(height + up)] == defense)
			{


				while(checkVertical != (dynBoundY) && checkHorizontal != (dynBoundX))
				{
					if(board[checkHorizontal][checkVertical] == BLANK)
					{
						break;
					}
					if(board[checkHorizontal][checkVertical] == defense)
					{
						checkVertical += up;
						checkHorizontal += right;
						continue;
					}
					if(board[checkHorizontal][checkVertical] == tokenColor)
					{

						return TRUE;
					}
					checkVertical += up;
					checkHorizontal += right;
				}
			}

		}
	}
	printf("\nInvalid move\n");
	return FALSE;

}
