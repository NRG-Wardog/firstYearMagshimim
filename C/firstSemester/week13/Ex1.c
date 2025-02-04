#include <stdio.h>
#define ROWS 5
#define SEATS_IN_ROW 3
#define CHEAP_TICKET_PRICE 25
#define NORMAL_TICKET_PRICE 35
#define VIP_TICKET_PRICE 50
enum choises{printHall =1 ,buyTk,numberOfUnavilbaleP,findChep,saleP,exit};
/*
fun print options
input:none
output:none
*/
void walcome()
{
	printf("1)print hall \n2)buy  tk \n3)number of unavilbale place \n4)find cheaps place \n5)sale \n6)exit \n");
}
/*
put sale on all avilbale ticket prices
Input: 	hall, and number of rows sale price
Output: None
*/
void sales(int mat[][SEATS_IN_ROW], int rowss, int sale)
{
	int row = 0;
	int col = 0;
	int i =0;
	for(row=0;row<rowss;row++)
	{
		for(col=0;col<SEATS_IN_ROW;col++)
		{
			if(mat[row][col]!=-1)
			{
				if(mat[row][col]  > sale)
				{
					mat[row][col]-=sale;
				}
				else 
				{
					mat[row][col]=0;
				}
			}
		}
	}
	
}

/**
Print a cinema hall ticket prices
Input: 	hall, and number of rows
Output: None
*/
void printCinema(int mat[][SEATS_IN_ROW], int rowss)
{
	int row = 0;
	int col = 0;
	int i =0;
	for(row=0;row<rowss;row++)
	{
		for(col=0;col<SEATS_IN_ROW;col++)
		{
			printf("%d ",mat[row][col]);
		}
		printf("\n");
	}
}
/**
check the smallest price place avilbale if there is
Input: 	hall, and number of rows
Output: -1 or price tk
*/
int buyTikPick(int mat[][SEATS_IN_ROW], int rowss)
{
	int price = -1;
	int row=0;
	int col=0;
	for(row=0;row<rowss;row++)
	{
		for(col=0;col<SEATS_IN_ROW;col++)
		{
			if(mat[row][col]!=-1)
			{
				price=mat[row][col];
			}
		}
	}
	return price;
}
/**
check if the place wanted is avilbale
Input: 	hall, and number of rows ,wanted row and place in row 
Output: 1/0 avilbale or not (buy)
*/
int buyTik(int mat[][SEATS_IN_ROW], int rowss,int row,int place)
{
	int buy = 0;
	if(mat[row][place]!=-1)
	{
		buy=1;
		mat[row][place]=-1;
	}
	return buy;
}
/**
count how much place unavilbale
Input: 	hall, and number of rows  
Output: count of unavilbale places
*/
int lockedPlace(int mat[][SEATS_IN_ROW])
{
	int row = 0;
	int counter=0;
	int col = 0;
	int i =0;
	for(row=0;row<ROWS;row++)
	{
		for(col=0;col<SEATS_IN_ROW;col++)
		{
			if(mat[row][col]==-1)
			{
				counter++;
			}
		}
	}
	return counter;
}
/*


*/

void menu(int cinema[][SEATS_IN_ROW],int rowss)
{
	int choise = 0;
	int flag =1;
	int sale=0;
	int row=0;
	int buyed=0;
	int place=0;
	do{
		do{
			walcome();
			printf("enter choise :");
			scanf("%d",&choise);
		}while(choise>6||choise<1);
		switch(choise)
		{
			case printHall:
				printCinema(cinema, ROWS);
				break;
			case buyTk:
				printf("enter row wanted(0-4)");
				scanf("%d",&row);
				printf("enter place in row(0-2)");
				scanf("%d",&place);
				buyed = buyTik(cinema,ROWS,row,place);
				if(buyed==1)
				{
					printf("buy tk \n");
				}
				else
				{
					printf("locked already \n");
				}
				break;
			case numberOfUnavilbaleP:
				printf("locked place is %d \n",lockedPlace(cinema));
				break;
			case findChep:
				printf("We picked a seat, the price is %d \n",buyTikPick(cinema,ROWS));
				break;
			case saleP:
				printf("enter sale:");
				scanf("%d",&sale);
				sales(cinema,ROWS,sale);
				break;
			case exit:
				flag=0;
				break;
			default:
				printf("wrong choise enter agian \n");
				break;
		}		
	}while(flag!=0);
}
int main(void)
{
	int cinema[ROWS][SEATS_IN_ROW] = {{CHEAP_TICKET_PRICE, CHEAP_TICKET_PRICE, CHEAP_TICKET_PRICE},
									  {NORMAL_TICKET_PRICE, NORMAL_TICKET_PRICE, NORMAL_TICKET_PRICE},
									  {NORMAL_TICKET_PRICE, VIP_TICKET_PRICE, NORMAL_TICKET_PRICE},
									  {NORMAL_TICKET_PRICE, NORMAL_TICKET_PRICE, NORMAL_TICKET_PRICE},
									  {CHEAP_TICKET_PRICE, CHEAP_TICKET_PRICE, CHEAP_TICKET_PRICE}};
	menu(cinema,ROWS);
	return 0;
}