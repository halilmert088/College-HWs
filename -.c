#include <stdio.h>
#include <string.h>
#include <string.h>
#include <ctype.h>

void projectFunction(char a[], char b, int c, int d)
{
	char matrix[c][d], encode[100];
	int i, j, k=0, l=0;
	
	assign://Put a jump point here for easier matrix assignment
		for(i=0; i<c; i++)
		{
			for(j=0; j<d; j++)
			{
				matrix[i][j]=a[k];//Enters the input string into the matrix in row-wise order
				k++;
			}
		}
		
		for(j=0; j<d; j++)
		{
			for(i=0; i<c; i++)
			{
				encode[l]=matrix[i][j];//Reads the matrix in column-wise order and assigns each character to another string
				l++;
			}
		}
		
	
	if(encode[l-1]!='\0')
	goto assign;//Goes to the jump point above if the string is not finished
	
	
	if(b=='E')
	{
		printf("Encoded string: %s\n", encode);
	}
	
	if(b=='D')
	{
		printf("Decoded string: %s\n", encode);
	}
}

void main()
{
	int m, n;
	char string[100], method;
	do
	{
		printf("Enter M and N values for matrix: ");
		scanf("%d%d", &m, &n);
	}while((m>5) || (n>5));//Takes input until M and N are both less than five
	
	printf("Matrix size is %dx%d\n", m, n);
	
	
	printf("Enter method(E for Encode, D for Decode): ");
	scanf(" %c", &method);
	getchar();//Put a getchar function here to clear the input buffer
	while(method!='Q')//Keeps getting input until the user enters 'Q'
	{
		printf("Enter string: ");
		gets(string);
		projectFunction(string, method, m, n);
		printf("Enter method(E for Encode, D for Decode): ");
		scanf(" %c", &method);
		getchar();
	}
	
	printf("Have a nice day.\n");
	system("PAUSE");
}

