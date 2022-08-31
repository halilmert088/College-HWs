#include <stdio.h>
#include <stdlib.h>

int main ()
{
int n, i, f = 1, inp;
do    
{
    printf("Enter a number : ");
    scanf("%d", &n);
    
    for ( i = 1; n >= i; i++)
    {
        f = f*i;
    }
    
    printf("%d! = %d\n", n, f);
    f = 1;
    printf("Enter 1 to run the program again: ");
    scanf("%d", &inp);
} while (inp == 1);

system("PAUSE");
return(0);
}
