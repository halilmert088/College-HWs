#include <stdio.h>
#include <stdlib.h>

char testchar;
int testint;

void printer (void);
int main (void)
{
    printf("Enter an integer and a character : ");
    scanf("%d %c", &testint, &testchar);
    printer();
    return(0);
}

void printer (void)
{
     printf("%d\n%c\n", testint, testchar);
     system("PAUSE");
}
