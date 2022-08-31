#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char arr[10][8] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', 'T'}, {' ', ' ', ' ', ' ', ' ', ' ', 'T', 'E'}, {' ', ' ', ' ', ' ', ' ', 'T', 'E', 'L'}, {' ', ' ', ' ', ' ', 'T', 'E', 'L', ' '}, {' ', ' ', ' ', 'T', 'E', 'L', ' ', ' '}, {' ', ' ', 'T', 'E', 'L', ' ', ' ', ' '}, {' ', 'T', 'E', 'L', ' ', ' ', ' ', ' '}, {'T', 'E', 'L', ' ', ' ', ' ', ' ', ' '}, {'E', 'L', ' ', ' ', ' ', ' ', ' ', ' '}, {'L', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};//Initialized every scrolled word as a part of the 2d array
    int i, j, k;
    
    
    for (k = 0; (k % 2) != 3; k++)//Since an integer's modulus with 2 can never be equal to three, this loop will run infinitely
    {
        for(i = 0; i < 10; i++)
        {
              for(j = 0; j < 8; j++)
              {
                    printf("%c", arr[i][j]);
              }
            sleep(1);
            printf("\n");
        }
        
        printf("\n\n");//For the single blank line
    }
    
    return(0);
}
