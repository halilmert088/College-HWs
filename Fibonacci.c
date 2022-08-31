#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int x = 1, y = 1, i, n, z;
    printf("Enter a number: ");
    scanf("%d", &n);
    
    for(i = 1; n >=i; i++)
    {
          z = x + y;
          printf("%d\n", x);
          x = y;
          y = z;
    }
    
    system("PAUSE");
    return(0);
}
          
