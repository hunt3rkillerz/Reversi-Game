/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : Alex R***
 * Student Number   : S***
 * Course Code      : BP094
 * Program Code     : COSC1076
 * Start up code provided by Paul Miller 
 **********************************************************************/

#include "gameboard.h"
#include "player.h"

/**
 * initialise the game board to be consistent with the screenshot provided
 * in your assignment specification. 
 *
 * All squares should be initialised to be blank other than the four
 * squares in the middle of the board. In that case they are initialised to 
 * appropriate colored tokens
 **/

void init_game_board(game_board board)
{

    int i, j;
    /* Setting all the squares to blank */
    for (i = 0; i < BOARD_HEIGHT; i++)
    {
        
        for (j = 0; j < BOARD_WIDTH; j++)
        {
    
            board[j][i] = BLANK;
        }
    
    }
    board[3][3] = RED;
    board[3][4] = BLUE;
    board[4][4] = RED;
    board[4][3] = BLUE;

   /* board[2][0] = RED;
    board[3][0] = RED;
    board[4][0] = RED;
    board[5][0] = RED;
    board[6][0] = RED;
    board[7][0] = RED;
    board[0][1] = RED;
    board[1][1] = RED;
    board[2][1] = RED;
    board[3][1] = RED;
    board[4][1] = RED;
    board[5][1] = RED;
    board[6][1] = RED;
    board[2][2] = BLUE;
    board[3][2] = BLUE;
    board[4][2] = BLUE;
    board[5][2] = RED;
    board[6][2] = RED;
    board[2][3] = RED;
    board[3][3] = BLUE;
    board[4][3] = BLUE;
    board[5][3] = BLUE;
    board[6][3] = RED;
    board[2][4] = RED;
    board[3][4] = RED;
    board[4][4] = BLUE;
    board[5][4] = RED;
    board[6][4] = BLUE;
    board[2][5] = RED;
    board[3][5] = RED;
    board[4][5] = BLUE;
    board[5][5] = BLUE;
    board[1][6] = RED;
    board[4][6] = BLUE;
    board[0][7] = RED;*/
    return;
}

/**
 * display the board as specified in the assignment specification. You should 
 * make every effort to create a board consistent with the screenshots in the 
 * assignment specification. 
 **/

void display_board(game_board board, struct player * first, struct player * second)
{
	/* Controls the board loop */
    int pControl;
    /* used to print player info */
    int isRed = 0;
    /* keeps track of the height value */
    int height = 0;
    /* keeps track of the width value */
    int width;


    /* Start Declaring Who is Who */
    if(first->token == RED)
    {
    	isRed = 1;
    }
    printf("----------\nPlayer 1:\nName: %.*s\nColor: ", (strlen(first->name) - 1), first->name);
    if(isRed == 1)
    {
    	printf("Red");
    }
    else
    {
    	printf("Blue");
    }
    printf("\nScore: %d\n----------\nPlayer 2:\nName: %.*s\nColor: ",first->score, (strlen(second->name) - 1), second->name);
    if(isRed == 1)
    {
    	printf("Blue");
    }
    else
    {
    	printf("Red");
    }
    printf("\nScore: %d\n----------\n", second->score);

    /* End Declaring Who is Who */
    printf("|     |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |\n");
    for (pControl = 0; pControl < (2 * BOARD_HEIGHT); pControl++)
    {
       
        if (pControl % 2 == 1)
        {
            
           printf("|  %d  ", (pControl/2 + 1));
           width = 0;
           while (width < (BOARD_WIDTH))
           {
                
                /* needs to add tokens */ 
                if(board[width][height] == RED)
                {
                	printf("|"COLOR_RED "  0  " COLOR_RESET);
                }
                else if(board[width][height] == BLUE)
                {
                	printf( "|"COLOR_BLUE"  0  " COLOR_RESET);
                }
                else
                {
                    printf("|     ");
                }
                width++;
            }
            height++;
        }

        else
        {
        	width=0;
            while (width < (BOARD_WIDTH + 1))
            {
            
                printf("|-----");
                width++;
            
            }



        }
        printf("|");
        printf("\n");
    }

}
