#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void main ()
{
    FILE *f1;
    f1=fopen("save.txt", "r+");
    int input, save, test, test1;
    
    fscanf(f1, "%d %d %d", &save, &test, &test1);
    
    menu:
    printf("1- New Game\n2- Load game\n3- Exit\n\n>");
    
    scanf("%d",&input);
    getchar();
    
    if(input==1)
    {
        save=1;
        fprintf(f1, "%d", save);

        printf("Test values: %d %d\n\n", test, test1);
        
        printf("Enter the new test values: ");
        scanf("%d %d", &test, &test1);
        getchar();

        fprintf(f1, "%d %d %d", save, test, test1);
        printf("\n");
        
        goto menu;
    }

    if(input==2)
    {
        if(save==0)
        {
            printf("No saved data\n\n");
        }

        if(save==1)
        {
        
        printf("Test values: %d %d\n\n", test, test1);
        
        printf("Enter the new test values: ");
        scanf("%d %d", &test, &test1);
        getchar();

        fprintf(f1, "%d %d %d", save, test, test1);
        printf("\n");   
        
        }

        goto menu;

    }

    if(input==3)
    {
		exit(0);
    }
}
