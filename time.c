#include <stdio.h>
#include <stdlib.h>

void calc_time (int a)
{
    int hours = a / 3600;
    a = a % 3600;
    int min = a / 60;
    a = a % 60;
    int sec = a;
    printf("The total time is ");
    if ( hours > 1 )
    printf("%d hours ", hours);
    else if ( hours == 1 )
    printf("1 hour ");
    if ( min > 1 )
    printf("%d minutes ", min);
    else if ( min == 1 )
    printf("1 minute ");
    if ( sec > 1 )
    printf("%d seconds", sec);
    else if ( sec == 1 )
    printf("1 second");
}

int main (void)
{
    int time;
    printf("Enter the time in seconds > ");
    scanf("%d", &time);
    calc_time (time);
    printf("\n");
    system("PAUSE");
    return(0);
}
