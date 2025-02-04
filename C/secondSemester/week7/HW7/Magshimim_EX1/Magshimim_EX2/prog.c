/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORD_LENGTH 100

/*
func reset the word
input:word,len of word
output:none
*/
void resetArr(char* arr, int length) {
	for (int i = 0; i < length; i++) {
		arr[i] = '\0';
	}
}


/*
func copy from source to des text file
input:char* sourceFile,char* destinationFile
output:none
*/
int countString(char* str, char findWorded[])
{
	FILE* file = fopen(str, "r");
	char ch;
	int count = 0;
	char word[MAX_WORD_LENGTH] = { 0 };
	if (file == NULL)
	{
		printf("Error opening file");
		return 1;
	}
	while ((ch = (char)fgetc(file)) != EOF)
	{
		if (ch == '\n'||ch==',')
		{
			if (strcmp(word, findWorded)==0)
			{
				count++;
			}
			resetArr(word, MAX_WORD_LENGTH);
		}
		strncpy(word, &ch, 1);
	}
	fclose(file);
	return count;
}

/*
func print menu
input:none
output:none
*/
void menu()
{
	printf("1 - Search a term in the document.\n2 - change a value in a specific place.\n3 - copy a value from one place to another\n4 - Exit\n");
}


int main(int argc, char** argv)
{
	FILE* source = NULL;
	char word[MAX_WORD_LENGTH] = { 0 };
	bool flag = true;
	int choies = 0;
	if (argc != 2) 
	{
		printf("Usage: CsvExample <csv file path>\n");
		return -1;
	}
	source = fopen(argv[1], "r");
	if (source == NULL)
	{
		printf("Usage: CsvExample <csv file path>\n");
		return -1;
	}

	while (flag)
	{
		menu();
		printf("enter choies:");
		scanf("%d", &choies);
		getchar();
		switch (choies)
		{
		case 1:
			printf("Enter string to search:");
			scanf("%s", &word);
			getchar();
			printf("Value appears %d times\n",countString(argv[1], word));
			menu();
			break;
		case 2:
			flag = false;
			break;
		case 3:
			flag = false;
			break;
		case 4:
			flag = false;
			printf("good bye!");
			break;
		default:
			break;
		}
	}
	fclose(source);
	getchar();
	return 0;
}
