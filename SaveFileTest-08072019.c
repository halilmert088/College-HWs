#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void main ()
{
    int save, data=46, test;
    FILE *f1, *f2;
    f1=fopen("save1","w");
    fprintf(f1, "%d %d", save, data);
    f2=fopen("save","r+");
    
    menu:
    printf("1- New file\n2- Load file\n3- Exit\n>");
    scanf("%d",&test);

    fprintf(f1, "%d %d", save, data);
    fprintf(f2, "%d %d", save, data);

    if(test==1)
    {
        save=1;
        fprintf(f1, "%d %d", save, data);
        
        printf("Old data: %d, enter new data: ", data);
        scanf("%d", &data);
        getchar();

        fprintf(f1, "%d %d", save, data);

        printf("\n");
        goto menu;
    }
    
    
    if(test==2)
    {
        f2=fopen
        fscanf(f2, "%d %d", &save, &data);
        
        if(save!=1)
        {
            printf("No previous save file exists.\n");
        }

        if(save==1)
        {
            printf("Old data: %d, enter new data: ", data);
            scanf("%d", &data);
            getchar();

            fprintf(f2, "%d %d", save, data);
        }

        printf("\n");
        goto menu;
    }

    if(test==3)
    {
        fprintf(f1, "%d %d", save, data);
        fclose(f1);
        exit(0);
    }

}