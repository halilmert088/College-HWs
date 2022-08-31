#include <stdio.h>
#include <stdlib.h>

int math (int a, int b, char c)
{
    switch (c)
    {
           case ( ' + ' ):
                return ( a + b );
                break;
           case ( ' - ' ):
                return ( a - b );
                break;
           case ( ' * ' ):
                return ( a * b );
                break;
           case ( ' / ' ):
                if ( b > 0 )
                {return ( a / b );
                break;}
                else
                {printf("ERROR");
                break;}
           default:
                   printf("ERROR");
                   break;
     }
}

int main (void)
{
    int a, b;
    char op;
    printf("Enter two numbers > ");
    scanf("%d %d", &a, &b);
    printf("Enter a math operand > ");
    scanf(" %c", &op);
    int result = math (a, b, op);
    printf("%d\n", result);
    system("PAUSE");
    return(0);
}
