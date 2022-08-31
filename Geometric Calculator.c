#include <stdio.h>
#include <stdlib.h>

void geo (int a, int b, int c)
{
    int area_bottom = a * b;
    int area_side = a * c;
    int volume = area_bottom * c;
    int area_total = 2 * ( ( a * b ) + ( a * c ) + ( b * c ) );
    printf("The bottom area is %d\nThe side area is %d\nThe total area is %d\nThe volume is %d\n", area_bottom, area_side, area_total, volume);
}

int main (void)
{
    int a, b, c;
    do
    {
         printf("Enter the sides of the shape > ");
         scanf("%d %d", &a, &b);
         printf("Enter the height of the shape > ");
         scanf("%d", &c);
    }while (( a < 0 ) && ( b < 0 ) && ( c < 0 ) );
    
    geo (a, b, c);
    system("PAUSE");
    exit(0);
}
         
