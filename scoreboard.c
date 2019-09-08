/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : Alex R***
 * Student Number   : S***
 * Course Code      : BP094
 * Program Code     : COSC1076
 * Start up code provided by Paul Miller 
 **********************************************************************/

#include "scoreboard.h"

/**
 * initalise the scoreboard so that the scores for each element of the array
 * is set to 0.
 **/
void init_scoreboard(score scores[MAX_SCORES])
{
	int allScores;
	/*Sets all scores equal to 0 */
	for(allScores = 0; allScores < MAX_SCORES; allScores++)
	{
		scores[allScores].score = 0;
		strcpy(scores[allScores].name, "\n");
	}
}


/**
 * insert the top scorer from the last game played in sorted order according
 * to their score 
 **/
BOOLEAN add_to_scoreboard(score scores[MAX_SCORES], struct player * winner)
{
	score tempScore[MAX_SCORES];

	printf("\n");
	/* scoreBreak defines a break point where a new highscore must be inserted
	 * tracker remembers the position in the temp array, scoreWrite
	 * remembers the position in the original array
	 */
	int scoreBreak, scoreWrite, tracker;
	for(scoreBreak = 0; scoreBreak < MAX_SCORES; scoreBreak++)
	{
		if(winner->score > scores[scoreBreak].score)
		{
			break;
		}
	}

	/* Kills the function if it wasn't a new high score */

	if(scoreBreak == 10)
	{
		return FALSE;
	}

	scoreWrite = 0;
	tracker = 0;
	while(tracker < MAX_SCORES)
	{
		if(tracker == scoreBreak)
		{
			tempScore[tracker].score = winner->score;
			strcpy(tempScore[tracker].name, winner->name);
			tracker++;
			continue;
		}

		tempScore[tracker].score = scores[scoreWrite].score;
		strcpy(tempScore[tracker].name, scores[scoreWrite].name);

		tracker++;
		scoreWrite++;

	}

	for(tracker = 0; tracker < MAX_SCORES; tracker++)
	{
		scores[tracker] = tempScore[tracker];
	}

	return TRUE;
}

/**
 * display the scores in the scoreboard according to their order. Your output
 * should match that provided in the assignment specification.
 **/
void display_scores(score scores[MAX_SCORES])
{
	int allScores, score;
	char *name;
	printf("\nHigh Scores\n");
	for(allScores = 0; allScores < MAX_SCORES; allScores++)
	{
		/* allScores + 1 is used so as to have the first position be 1 and the last
		 * position be 10 as opposed to 0 and 9 respectively
		 */
		name = scores[allScores].name;
		if('\n' != name[0])
		{
			score = (int) (scores[allScores].score);
			if(allScores < 9)
			{
				printf("%d.  Name:%.*s Score:%d \n", (allScores + 1), (strlen(name) -1), name, score);
			}
			else
			{
				printf("%d. Name:%.*s Score:%d \n", (allScores + 1), (strlen(name) -1), name, score);
			}
		}

	}
	printf("\n");
}
