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

/*
func copy from source to des file in binray
input:char* sourceFile,char* destinationFile
output:none
*/
void binaryCopy(char* sourceFile,char* destinationFile)
{
	FILE* source = fopen(sourceFile, "rb");
	FILE* dest = fopen(destinationFile, "wb");
	char* buffer;
	long lSize = 0;

	fseek(source, 0, SEEK_END);
	lSize = ftell(source);
	fseek(source, 0, SEEK_SET);
	buffer = (char*)malloc(lSize);
	buffer = fread(buffer, 1, lSize, source);
	
	fwrite(buffer, sizeof(char), sizeof(buffer), dest);
	free(buffer);
	fclose(source);
	fclose(dest);
}

/*
func copy from source to des text file
input:char* sourceFile,char* destinationFile
output:none
*/
void textCopy(char* sourceFile, char* destinationFile)
{
	FILE* source = fopen(sourceFile, "r");
	FILE* dest = fopen(destinationFile, "w");

	char ch;
	while ((ch = fgetc(source)) != EOF) {
		fputc(ch, dest);
	}

	fclose(source);
	fclose(dest);
}

/*
func check the exiten of the file and get respond returing any issues
input:char* sourceFile,char* destinationFile
output:none
*/
bool check(char** argv,char* response)
{
	FILE* source = fopen(argv[2], "r");
	FILE* dest = fopen(argv[3], "r");
	if (source == NULL) {
		printf("Error: Source file does not exist.\n");
		return false;
	}
	if (dest != NULL) {
		fclose(dest);
		printf("Destination file exists. Overwrite? (y/n): ");
		scanf("%c", response);
		getchar();
		if (*response != 'y') {
			printf("Copying aborted.\n");
			return false;
		}
	}
	fclose(source);
	fclose(dest);
}


int main(int argc, char** argv)
{
	char respond = 0;
	if (argc != 4) {
		printf("Incorrect number of parameters.\n");
		return -1;
	}
	if (!strcmp(argv[1], "textCopy") || !strcmp(argv[1], "binaryCopy")) {
		if (check(argv, &respond) == false ) 
		{
			return -1;
		}
		if (respond == 'y') {
			if (!strcmp(argv[1], "textCopy")) {
				textCopy(argv[2], argv[3]);
			}
			else {
				binaryCopy(argv[2], argv[3]);
			}
			printf("File copied successfully.\n");
		}
	}
	else {
		printf("Invalid option. Choose 'textCopy' or 'binaryCopy'.\n");
		return -1;
	}

	getchar();  
	return 0;
}
