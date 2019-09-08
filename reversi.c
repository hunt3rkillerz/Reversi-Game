/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : Alex R***
 * Student Number   : S***
 * Course Code      : BP094
 * Program Code     : COSC1076
 * Start up code provided by Paul Miller 
 **********************************************************************/

#include "reversi.h"

/**
 * the heart of the program. The main() function in particular should
 * manage the main menu for the program.
 **/

int main(void)
{
	char option[LINELEN];
    /* Declaration of scoreboard and player */
	score scrboard[MAX_SCORES];
    struct player player1, player2, *winner = NULL;
    /* initialise the scoreboard */
    init_scoreboard(scrboard);
    /* Menu loop control structure */
	while(TRUE) {
        /* Make the menu for the user */
    	printf("Reversi\n===================\nSelect an option:\n"
    	"1. Play a game\n2. Display High Scores\n3. Quit the game\nPlease select an option: ");
        /* variables for menu */

        /* Get user input */
    	fgets(option, MENULENGTH+EXTRACHARS, stdin);

    	/* menu data processing */

    	/* Takes care of null input eg ctrl D */
    	if(strlen(option) == 0)
    	{
    		printf("\n\nPlease enter a valid selection.\n\n");
    		continue;
    	}
    	/* Clears the buffer */
		if(option[strlen(option) - 1] != '\n')
		{
			read_rest_of_line();
			printf("\n\nPlease enter a valid selection.\n\n");
			continue;
		}
		/* Processes valid input */
		switch ((int) strtol(option, NULL, 10))
		{

			/* Play a game and add the winner to the scoreboard */
			case 1:
				winner = play_game(&player1, &player2);
				if(winner == NULL)
				{
					printf("\n");
				}
				else
				{
					printf("WINNER Score: %d, Name: %s\n", winner->score, winner->name);
					add_to_scoreboard(scrboard, winner);
				}

				break;
			/* Display scores */
			case 2:
				display_scores(scrboard);
				break;
			/* quit */
			case 3:
				return EXIT_SUCCESS;
				break;

			default :
				printf("\n\nPlease enter a valid selection.\n\n");
				break;

		}
    	continue;
	}
}
