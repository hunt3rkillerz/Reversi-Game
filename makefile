all:
	gcc -ansi -pedantic -Wall reversi.c game.c gameboard.c scoreboard.c utility.c player.c -o reversi

withLove:
	gcc -ansi -pedantic reversi.c game.c gameboard.c scoreboard.c utility.c player.c -o reversi


clean:
	rm reversi
