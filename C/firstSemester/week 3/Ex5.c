#include <stdio.h>
int main(void)
{
	int i = 65537;
	unsigned short s  = (unsigned short)i;
	float f = (float)i;
	char c = (char)i;
	printf("s = %u ,i=%d , f= %f c=%d\n", s,i,f,c);
	return 0; 
}
