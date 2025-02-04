#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIDE 8
#define VISITED 1
#define NOT_VISITED 0

#define GOAL_X1 7
#define GOAL_Y1 0
#define GOAL_X2 0
#define GOAL_Y2 7
#define GOAL_X3 7
#define GOAL_Y3 7

#define FALSE 0
#define TRUE !FALSE

void printBoard(int board[][SIDE]);
int goHorsie(int board[][SIDE], int x, int y, int step);

int main(void)
{
	int board[SIDE][SIDE] = { NOT_VISITED };
	if (goHorsie(board, 0, 0, 1))
	{
		printf("Yes,there is a path from 0,0 through all corners! Here it is:\n");
		printBoard(board);
	}
	else
	{
		printf("No path from 0,0 through all the corners");
	}
	getchar();
	return 0;
}


/*
Function checks if knight can travel from top left corner and travel through all corners
input: the board, and current step
output: whether a path was found
*/
int goHorsie(int board[][SIDE], int x, int y, int step)
{
	int res = FALSE;
	if (board[GOAL_X1][GOAL_Y1] != NOT_VISITED && board[GOAL_X2][GOAL_Y2] != NOT_VISITED && board[GOAL_X3][GOAL_Y3] != NOT_VISITED)
	{
		res = TRUE;
	}
	else if (x >= SIDE || y >= SIDE || x < 0 || y < 0 || // out of the board
		board[x][y] != NOT_VISITED) // we were here already!
	{
		res = FALSE;
	}
	else
	{
		board[x][y] = step;
		step++;
		// changing order here will change the path, because once a condition is verified (TRUE) the rest aren't checked
		res = goHorsie(board, x + 2, y + 1, step) ||
			goHorsie(board, x + 2, y - 1, step) ||
			goHorsie(board, x + 1, y + 2, step) ||
			goHorsie(board, x + 1, y - 2, step) ||
			goHorsie(board, x - 2, y + 1, step) ||
			goHorsie(board, x - 2, y - 1, step) ||
			goHorsie(board, x - 1, y + 2, step) ||
			goHorsie(board, x - 1, y - 2, step);
		if (!res)
		{
			board[x][y] = NOT_VISITED;
		}
	}

	return res;
}


/*
Function prints the board
input: board to print
output: none
*/
void printBoard(int board[][SIDE])
{
	int i = 0, j = 0;
	for (i = 0; i < SIDE; i++)
	{
		for (j = 0; j < SIDE; j++)
		{
			printf("%3d", board[i][j]);
		}
		printf("\n");
	}
}