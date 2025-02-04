#include <stdio.h>
#include <string.h>

#define ROW 10
#define SEATS_IN_ROW 20
#define NUMBER_OF_LETTER 26
#define LETTER_IN_SENTENS 500

/*
cheack if if pangram by cheack if the word has alphabet in it add to the arr alphabet
Input: 	sentence
Output: cheack
*/
int isPangram(char sentence[]) 
{
    int i, j;
	int cheack=1;
    int alphabet[NUMBER_OF_LETTER] = {0};

    for (i = 0; i < strlen(sentence); i++) 
	{
        if (sentence[i] >= 'a' && sentence[i] <= 'z') 
		{
            alphabet[sentence[i] - 'a']++;
			
        }
    }

    for (j = 0; j < NUMBER_OF_LETTER; j++) 
	{
        if (alphabet[j] == 0) 
		{
            cheack = 0;
			j=NUMBER_OF_LETTER;
        }
    }
    return cheack;
}

int main() 
{
    char words[SEATS_IN_ROW][ROW];
    char sentence[LETTER_IN_SENTENS] = "";
    int wordCount = 0;

    printf("Enter up to 10 words (separated by spaces):\n");
    
    while (wordCount < ROW) 
	{
		fgets(words[wordCount], SEATS_IN_ROW, stdin);
        strcat(sentence, words[wordCount]);
        strcat(sentence, " ");
        wordCount++;
		if (isPangram(sentence)) 
		{
			printf("Yes\n");
			wordCount = ROW;
		} 
    }

	if (!isPangram(sentence)) 
	{
        printf("No\n");
    }

    return 0;
}
