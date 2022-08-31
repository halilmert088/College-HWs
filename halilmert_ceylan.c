#include <stdio.h>
#include <stdlib.h>

int fact (int a)
{
     if ((a == 1) && (a == 0))
     return (1);
     
     if(a > 1)
     {
          a = a * fact(a - 1);
     }

     return(a);
}

void calc (int n, int r, int *combination, int *permutation)
{
     *permutation = (fact (n)) / (fact (n - r));
     *combination = (fact (n)) / ((fact (r)) * fact (n - r));
}

int main (void)
{
     int n, r, combination, permutation;
     do{
     
     printf("Enter N value: ");
     scanf("%d", &n);
     printf("Enter R value: ");
     scanf("%d", &r);

     while((n < r) && (n > 0) && (r > 0))
     {
          printf("N value should be greater than R value! Try again !\n\n");
          printf("Enter N value: ");
          scanf("%d", &n);
          printf("Enter R value: ");
          scanf("%d", &r);
     }

     if ((n > 0) && (r > 0))
     {
          calc (n, r, &combination, &permutation);
          printf("Combination : C (%d, %d) = %.2f\n", n, r, (float) combination);
          printf("Permutation : P (%d, %d) = %.2f\n", n, r, (float) permutation);
          printf("\n");
     }
     } while ((n > 0) && (r > 0));

     printf("Error : N or R value should be equal or greater than zero. Bye!\n");
     system("PAUSE");
     return(0);
}
