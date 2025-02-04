#include<stdio.h>
int main()
{
    int hour=0;
	int min=0;
	int sec=0;
	int sec1=0;
	int sec2=0;
	int min1 = 0;
	int min2 = 0;
    int hour1 = 0;
	int hour2 = 0;
	printf("enter by the format hh:mm:ss");
	scanf("%d:%d:%d",&hour,&min,&sec);
	sec2 = sec/10;
	sec1=sec%10;
	min2 = min/10;
	min2=min%10;
	hour2 = hour/10;
	hour1=hour%10;
	if(hour<=23&&hour>=0 && min<=59&&min>=0 && sec>=0&&sec<=59)
	{
		if(sec ==59)
		{
			if(sec==59)
			{
				sec1=0;
				sec2=0;
				min++;
				min2 = min/10;
				min2=min%10;
				if(min==59||min==60)
				{
					min1=0;
					min2=0;
					hour++;
					hour2 = hour/10;
					hour1=hour%10;
					if(hour==24)
					{
						hour1 =0;
						hour2=0;
					}	
				}
			}
			printf("%d%d:%d%d:%d%d",hour2,hour1,min2,min1,sec2,sec1);
		}
		else
		{
			sec++;
			printf("%d:%d:%d",hour,min,sec);
		}
	}
	else
	{
		printf("The time isn't valid");
	}
	return 0;
}
