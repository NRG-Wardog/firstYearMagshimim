#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define MAX_GUSSES_EASY 20
#define MAX_GUSSES_MODERATE 15
#define MAX_GUSSES_HARD 10
#define MAX_GUSSES_CRAZY 25
#define MIN_GUSSES_CRAZY 5
#define MAX_NUMBER_GUSSED '6'
#define MIN_NUMBER_GUSSED '1'
#define END_GAME_GUSSES 0
#define ADD_ASCII_FOR_NUM 48
enum difucalteLeveal{easy=1,moderate,hard,crazy};
char numberFirstLetter=' ';
char numberSecLetter=' ';
char numberThreeLetter=' ';
char numberFourLetter=' ';
/*
printing starting game message
input:none
output:none
*/
void welcome()
{
	printf("Welcome to MAGSHIMIM CODE-BREAKER!!! \n A secret password was chosen to protect the credit card of Pancratius,the descendant of Antiochus. \n Your mission is to stop Pancratius by revealing his secret password.\n ");
	printf("he rules are as follows: \n 1. In each round you try to guess the secret password (4 distinct digits) \n 2. After every guess you'll receive two hints about the password \n   HITS:   The number of digits in your guess which were exactly right.\n   MISSES: The number of digits in your guess which belongs to");
	printf("the password but were miss-placed. \n 3. If you'll fail to guess the password after a certain number of rounds \n   Pancratius will buy all the gifts for Hanukkah!!!\n Please choose the game level: \n 1 - Easy (20 rounds) \n 2 - Moderate (15 rounds) \n 3 - Hard (10 rounds)\n 4 - Crazy (random number of rounds 5-25) \n");
}
/*
randomls 4 number 
input:none
output:none
*/
void numberCreate()
{
	numberFirstLetter = (char)((rand() % 6) + 49);
	do{
		numberSecLetter = (char)((rand() % 6) + 49);
	}while(numberSecLetter==numberFirstLetter);
	do{
		numberThreeLetter = (char)((rand() % 6) + 49);
	}while(numberSecLetter==numberThreeLetter||numberThreeLetter==numberFirstLetter);
	do{
		numberFourLetter = (char)((rand() % 6) + 49);
	}while(numberFourLetter==numberSecLetter||numberFourLetter==numberFirstLetter||numberFourLetter==numberThreeLetter);
	
}
/*
chack if the difucalte are at the range
input:difucalte
output:chack
*/
int chackDif(int difucalte)
{
    bool chack = true;
    if (difucalte > crazy + ADD_ASCII_FOR_NUM || difucalte < easy + ADD_ASCII_FOR_NUM)
    {
        chack = false; 
    }
    return chack;
}
/*
chaek if the gusses got to 0 and print end
input:gusses
output:end
*/
bool gussesCheack(int gusses)
{
	bool end= false;
	if(gusses == END_GAME_GUSSES)
	{
		end = true;
		printf("OOOOHHHH!!! Pancratius won and bought all of Hanukkah's gifts. \n");
		printf("Nothing left for you...\n");
		printf("The secret password was %c%c%c%c     \n",numberFirstLetter,numberSecLetter,numberThreeLetter,numberFourLetter);
		printf("        \\|\\||\n"
       "       -' |||/\n"
       "      /7   |||/\n"
       "     /    |||||/\n"
       "     \\-' |||||||/`-.____________\n"
       "      -|||||||||           /    `.\n"
       "        |/||||             \\      \\\n"
       " _______/    /_       ______\\      |__________-\n"
       "(,__________/  `-.___(,_____________----------_)\n");	
	}
	return end;
}
/*
get and chack(by gusses) if you got to the num ask for again
input:difucalte
output:endGame
*/
bool game(char difucalte)
{
	int gusses =0;
	int exactlyGusses=0;
	int notExaclyGusses=0;
	int doubleLetter=0;
	bool stopGame=false;
	bool endGame=false;
	char gameStop=' ';
	char firstGusseLetter=' ';
	char secGusseLetter=' ';
	char threeGusseLetter=' ';
	char fourGusseLetter = ' ';
	int startGusses=0;
	switch(difucalte-ADD_ASCII_FOR_NUM)
	{
		case easy:
			gusses=MAX_GUSSES_EASY;
			break;
		case moderate:
			gusses=MAX_GUSSES_MODERATE;
			break;
		case hard:
			gusses=MAX_GUSSES_HARD;
			break;
		case crazy:
			gusses=((rand() %(MAX_GUSSES_CRAZY-MIN_GUSSES_CRAZY+1)) + MIN_GUSSES_CRAZY);
			break;
		default:
			break;
	}
	startGusses = gusses;
	while(!stopGame)
	{
		exactlyGusses=0;
		notExaclyGusses=0;
		doubleLetter=0;
		printf("Write your guess (only 1-6, no ENTER is needed) \n");
		if(difucalte!=crazy)
		{
			printf("%d guesses left \n",gusses);
		}
		firstGusseLetter = getch();
		printf("%c",firstGusseLetter);
		secGusseLetter = getch();
		printf("%c",secGusseLetter);
		threeGusseLetter = getch();
		printf("%c",threeGusseLetter);
		fourGusseLetter = getch();
		printf("%c \n",fourGusseLetter);
		while(firstGusseLetter>MAX_NUMBER_GUSSED||firstGusseLetter<MIN_NUMBER_GUSSED||secGusseLetter>MAX_NUMBER_GUSSED||secGusseLetter<MIN_NUMBER_GUSSED||threeGusseLetter>MAX_NUMBER_GUSSED||threeGusseLetter<MIN_NUMBER_GUSSED||fourGusseLetter>MAX_NUMBER_GUSSED||fourGusseLetter<MIN_NUMBER_GUSSED||firstGusseLetter==secGusseLetter||firstGusseLetter==threeGusseLetter||firstGusseLetter==fourGusseLetter||secGusseLetter== threeGusseLetter|| secGusseLetter== fourGusseLetter|| threeGusseLetter== fourGusseLetter)
		{
			printf("Only 1-6 are allowed and not double numbers, try again! \n Write your guess (only 1-6, no ENTER is needed)");
			if(difucalte!=crazy)
			{
				printf("%d guesses left \n",gusses);
			}
			firstGusseLetter = getch();
			printf("%c",firstGusseLetter);
			secGusseLetter = getch();
			printf("%c",secGusseLetter);
			threeGusseLetter = getch();
			printf("%c",threeGusseLetter);
			fourGusseLetter = getch();
			printf("%c  \n",fourGusseLetter);
		}
		if(firstGusseLetter==numberFirstLetter)
		{
			exactlyGusses+=1;
		}
		if(secGusseLetter==numberSecLetter)
		{
			exactlyGusses+=1;
		}
		if(threeGusseLetter==numberThreeLetter)
		{
			exactlyGusses+=1;
		}
		if(fourGusseLetter==numberFourLetter)
		{
			exactlyGusses+=1;
		}

		if(firstGusseLetter==numberSecLetter||firstGusseLetter==numberThreeLetter||firstGusseLetter==numberFourLetter)
		{
			notExaclyGusses+=1;
		}
		if(secGusseLetter==numberFirstLetter||secGusseLetter==numberThreeLetter||secGusseLetter==numberFourLetter)
		{
			notExaclyGusses+=1;
		}
		if(threeGusseLetter==numberFirstLetter||threeGusseLetter==numberSecLetter||threeGusseLetter==numberFourLetter)
		{
			notExaclyGusses+=1;
		}
		if(fourGusseLetter==numberFirstLetter||fourGusseLetter==numberSecLetter||fourGusseLetter==numberThreeLetter)
		{
			notExaclyGusses+=1;
		}
		printf("You got    %d HITS    %d MISSES. \n",exactlyGusses,notExaclyGusses);
		
		if(exactlyGusses==4)
		{
			stopGame=true;
			printf("4 HITS YOU WON!!!\n");
			printf("It took you only %d guesses, you are a professional code breaker! \n",startGusses-gusses);
		}
		else
		{
			gusses = gusses-1;
			stopGame = gussesCheack(gusses);
		}
	}
	printf("Would you like to play again? (y/n): \n");
	scanf(" %c",&gameStop);
	getchar();
	if(gameStop=='n')
	{
		endGame = true;
	}
	return endGame;
}
int main() 
{
	char difucalte=' ';
	bool endGame=false;
	srand(time(NULL));
	while(!endGame)
	{
		welcome();
		numberCreate();
		do{
			printf("Make a choice:");
			scanf("%c",&difucalte);
		}while(!chackDif(difucalte));
		endGame = game(difucalte);
	}
    return 0;
}