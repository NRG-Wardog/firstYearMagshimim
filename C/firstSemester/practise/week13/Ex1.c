#include <stdio.h>
#define SIZE_TOR 8
#define SIZE_WIDE 8
#define BLACK 'b'
#define WHITE 'w'
int main() {
    char borad[SIZE_TOR][SIZE_WIDE]={0};
	int j=0;
	int i=0;
	for(i=0;i<SIZE_TOR;i++)
	{
		for(j=0;j<SIZE_WIDE;j++)
		{
			if((j+i)%2==0)
			{
				borad[i][j]=BLACK;
			}
			else
			{
				borad[i][j]=WHITE;
			}
			printf("%c",borad[i][j]);
		}
		printf("\n");
	}
    return 0;
}