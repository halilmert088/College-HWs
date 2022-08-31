#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void main ()
{
    char n1[5], n2[5];
    int i, j;
    
    printf("Enter a name: ");
    gets(n1);
    printf("Enter a name: ");
    gets(n2);
    printf("Common characters: ");

    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            if(n1[i] == n2[j])
            printf("%c ", n1[i]);
        }
    }

    printf("\n");
    system("PAUSE");
}