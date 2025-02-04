#include <stdio.h>

int programmingJoke()
{
	printf("Your Joke: \n ---------------- \n Why do Java developers wear glasses? Because they don't C#! \n Press any key to continue . . .");
	getchar();
}
int KnockKnockJoke()
{
	printf("Your Joke: \n ----------------");
	printf("Knock, knock. \n Who is there? \n  Leaf. \n Leaf who? \n Leaf me alone! ");
	printf("Press any key to continue . . .");
	getchar();
}
int wordPlayJoke()
{
	printf("Your Joke: /n ----------------");
	printf("Why did the scarecrow keep getting promoted? \n Because he was outstanding in his field! \n");
	printf("Press any key to continue . . .");
	getchar();
}
void printJoke(int joke)
{
	switch (joke)
	{
		case 0:
			programmingJoke();
			break;
		case 1:
			KnockKnockJoke();
			break;
		case 2:
			wordPlayJoke();
			break;
		default:
			break;
	}
}
void userChoice()
{
	int joke =3;
	printf("Welcome to the Comedy Store!\n What kind of a joke would you like? \n Programming joke - 0 \n Knock-knock joke - 1 \n Wordplay joke - 2 \n");
	scanf("%d",&joke);
	while(joke>2 || joke <0)
	{
		printf("(0-2) What kind of a joke would you like? \n Programming joke - 0 \n Knock-knock joke - 1 \n Wordplay joke - 2 \n");
		scanf("%d",&joke);
	}
	printJoke(joke);
}
int main() {
    userChoice();
    return 0;
}