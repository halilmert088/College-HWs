#include <stdio.h>
#include <stdlib.h>

int specform(int a, int b);
int main ()
{
	int n, result;
	printf("Enter a number: ");
	scanf("%d", &n);
	int a = n;
	while (n >= 0)
	{
	    while ((n % 1000) == n)
		{
			printf("%d is not a four digit number.\n",n);
			printf("\nEnter a number: ");
			scanf("%d", &n);
		}
		
		result = specform(n/100 , n % 100);
		
		if (result == n)
		printf("%d has a special form\n", n);
		else
		printf("%d has not a special form\n", n);
		
		result = 0;
		printf("\nEnter a number: ");
		scanf("%d", &n);
		a = n;
	}
	printf("Bye..\n");
	system("PAUSE");
	return (0);
}


int specform(int a, int b)
{
	return ((a + b) * (a + b));
}
