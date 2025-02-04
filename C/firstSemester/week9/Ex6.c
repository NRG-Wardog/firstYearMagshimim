#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
updating Square of the player
input:int :squarePlayer(old square),added(in the cube what got)
output:int : updated(new square)
*/
int updatingSquare(int squarePlayer, int added)
{
    char answer = 'n';
    int updating = 0;
    printf("Is there a snake in your square? (enter y or n)\n");
    scanf(" %c", &answer); 
    getchar(); 
    if (answer == 'y')
    {
		printf("Where do you fall?\n");
        scanf("%d", &updating);
		do{
			printf("Where do you fall?(the  number need to be lower than your squre)\n");
			scanf("%d", &updating);
		}while(updating>=squarePlayer);
    }
    else
    {
        printf("Is there a ladder in your square? (enter y or n)\n");
        scanf(" %c", &answer); 
        getchar(); 

        if (answer == 'y')
        {
            printf("Where do you get?\n");
            scanf("%d", &updating);
			do{
			printf("Where do you get?(the  number need to be higher than your squre)\n");
			scanf("%d", &updating);
			}while(updating<=squarePlayer);
        }
        else
        {
            updating = squarePlayer + added;
        }
    }

    if (updating > 100)
    {
        updating = 100 - (updating - 100);
    }

    return updating;
}
/*
printing starting game message
input:none
output:none
*/
void welcome()
{
	printf("Welcome to my game of ladders and snakes i hop you you will enjoy. \n");
}
int main() 
{
    srand(time(NULL));
	int squarePlayerA=1;
	int squarePlayerB=1;
	int added=0;
	welcome();
	while(squarePlayerA!=100&&squarePlayerB!=100)
	{
		added = (rand()%6 )+1;
		printf("player a got in the cubes you got %d \n",added);
		squarePlayerA = updatingSquare(squarePlayerA,added);
		printf("a player updated squre is: %d \n",squarePlayerA);
		if(squarePlayerA!=100)
		{
			added = (rand()%6 )+1;
			printf("player b got in the cubes you got %d \n",added);
			squarePlayerB = updatingSquare(squarePlayerB,added);
			printf("b player your updated squre is: %d \n",squarePlayerB);
			if(squarePlayerB==100)
			{
				printf("player b won");
			}
		}	
		else
		{
			printf("player a won");
		}
	}
    return 0;
}