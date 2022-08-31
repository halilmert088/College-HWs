#include <stdio.h>
#include <stdlib.h>

void projectFunction(char a[], char b, int c, int d)
{
	char matrix[c][d], encode[100];
	int i, j, k=0, l=0;
	
	while(a[l]!='\0')
	{
		for(i=0; i<c; i++)
		{
			for(j=0; j<d; j++)
			{
				matrix[i][j]=a[k++];
			}
		}
		
		for(j=0; j<d; j++)
		{
			for(i=0; i<c; i++)
			{
				encode[l++]=matrix[i][j];
			}
		}
	}
	
	encode[l]='\0';
	
	if(b == 'E')
	{
		printf("Encoded string: %s\n", encode);
	}
	
	if(b == 'D')
	{
		printf("Decoded string: %s\n", encode);
	}
}

void main ()
{
	int m, n;
	char method, string[100];
	
	do
	{
		printf("Enter MxN for the matrix: ");
		scanf("%d %d", &m, &n);
	}while((m>5) || (n>5));
	
	while(1){
	
		printf("Enter E for encode, D for decode:");
		scanf(" %c",&method);
		if(method=='Q')
		 {
		 	break;
		  } 
		else
		{
		printf("Enter a string:");
		scanf("%s",&string);
		projectFunction(string, method, m, n);
	   }
}
}
