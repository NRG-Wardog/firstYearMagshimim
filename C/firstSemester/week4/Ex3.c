#include <stdio.h>
#define pie 3.14
int main()
{
	float radios = 1.0;
	float sum = 0;
	printf("The radoios ");
	scanf(" %f", &radios);
	sum = (pie*radios*radios*radios*4)/3 ;
	printf("The volume : %.2f \n", sum);
	return 0; 
}
 