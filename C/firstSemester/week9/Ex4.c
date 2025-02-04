#include <stdio.h>
enum months { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
enum days { sun = 1, mon, tue, wed, thu, fri, sat };
/*caclating the day number
input:day , month , startday
output:number of day
*/
int dayOfWeek(int day, int month, int startDay) 
{
    int totalDays = day - 1;
    return (totalDays + startDay - 1) % 7 + 1;
}

/*caclating how many day  in month
input:month 
output:number of day in month
*/
int checkMonthDay(int month) 
{
    switch (month) 
	{
        case jan: case mar: case may: case jul: case aug: case oct: case dec:
            return 31;
        case apr: case jun: case sep: case nov:
            return 30;
        case feb:
            return 28;
    }
    return 0;
}
/*caclating the day number
input: day , month 
output:1/0 
*/
int checkInput(int month, int dayInMonth) 
{
    if (month > 12 || month < 1 || dayInMonth > checkMonthDay(month) || dayInMonth < 1) 
	{
        return 0;
    }
    return 1;
}

int main()
{
    int day, month, dayFirst, result;
    printf("Hello! welcome to the day calculator! \n");
    printf("Enter the month check(1-jun,2-feb,etc): ");
    scanf("%d", &month);
    printf("Enter the day to check: ");
    scanf("%d", &day);
    while (checkInput(month, day) == 0) 
	{
        printf("Invalid input, try again\n");
        printf("Enter the month check(1-jun,2-feb,etc): ");
        scanf("%d", &month);
        printf("Enter the day to check: ");
        scanf("%d", &day);
    }
    do {
        printf("Enter the day of the week for the 1st day of the month (1-SUN, 2-MON, etc): ");
        scanf("%d", &dayFirst);
    } while (dayFirst > 7 || dayFirst < 1);
    result = dayOfWeek(day, month, dayFirst);
    printf("The day of the week for %d.%d is: ", day, month);
	switch (result)
    {
        case sun:
            printf("Sunday");
            break;
        case mon:
            printf("Monday");
            break;
        case tue:
            printf("Tuesday");
            break;
        case wed:
            printf("Wednesday");
            break;
        case thu:
            printf("Thursday");
            break;
        case fri:
            printf("Friday");
            break;
        case sat:
            printf("Saturday");
            break;
        default:
            printf("Invalid day");
            break;
    }
    return 0;
}
