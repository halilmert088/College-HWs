#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void main()
{
    char n1[100], n2 [100];
    int i, j, ct = 0;
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
            ct++;
            if(ct == 1)
            printf("%c", n1[i]);
        }
        ct=0;
    }
    system("PAUSE");
}