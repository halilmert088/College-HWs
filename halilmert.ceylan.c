//Halil Mert CEYLAN, 18243510049, CMPE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct ure
{
	int car;
	int city_code;
	char three_char[3];
	int three_dig;
	char arr;
}input[7], car_park[7];

void hash (struct ure a[], struct ure b[])
{
	int i;
	FILE *myFile;
	myFile = fopen("licenseplates.txt", "r");
	
	while(!feof(myFile))
	{
		fscanf(myFile, "%d %s %d %c\n", &a[i].city_code, &a[i].three_char, &a[i].three_dig, &a[i].arr);
		i++;
	}
	
	for(i=0; i<7; i++)
	{
		b[i].car=0;
		a[i].car=0;
	}
	
	int mod;
	
	for(i=0; i<7; i++)
	{
		mod=a[i].three_dig % 7;
		
		search://Created a jump point to continually search for an empty space
			if((a[i].arr == 'A')&&(b[mod].car!=0))
			{
				mod++;
				if(mod >= 7)
				mod = 0;
				goto search;
			}
			
		else if((a[i].arr=='A') && (b[mod].car==0))
		{
			b[mod]=a[i];
			b[mod].car=1;
		}
		
		else if(a[i].arr=='D')
		{
			b[mod].car=0;
		}
		
	}
}

void main ()
{
	int i, full=0, empty=0;
	hash(input, car_park);
	
	for(i=0; i<7; i++)
	{
		printf("Space %d: ", i+1);
		
		if(car_park[i].car==1)
		{
			if(car_park[i].city_code <= 9)
			printf("0");//So we can see 01 ABC 234 on the screen instead of 1 ABC 234
			printf("%d %s %d\n", car_park[i].city_code, car_park[i].three_char, car_park[i].three_dig);
			full++;
		}
		
		else if(car_park[i].car==0)
		{
			printf("EMPTY\n");
			empty++;
		}
    }
    
    printf("\nFULL SPACES: %d EMPTY SPACES: %d\n", full, empty);
}

