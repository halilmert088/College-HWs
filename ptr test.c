#include <stdio.h>
#include <stdlib.h>

void lulz (int a, int *b)
{
    *b = 80;
}

int main (void)
{
    int a, b;
    printf(">");
    scanf("%d %d", &a, &b);
    lulz (a, &b);
    printf("%d %d\n",a, b);
    system("PAUSE");
    return(0);
}