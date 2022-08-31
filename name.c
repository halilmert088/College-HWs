#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    char one[60];
    char two[60];
    char three[60];
    printf("What's your name? > ");
    scanf("%s%s%s" &one, &two, &three);
    printf("Your name is %s.\n", one, two, three);
    system("PAUSE");
    return(0);
}
