#include <stdio.h>
#include <stdlib.h>

int gold (int a, char b)
{
    switch(b)
    {
             case ('P'):
                  {if ( a >= 50 )
                  a = a - 50;
                  break;
                  
                  else
                  printf("Insufficent funds.\n");
                  break;}
             
             case ('S'):
                  {if ( a >= 100 )
                  a = a - 100;
                  break;
                  
                  else
                  printf("Insufficent funds.\n");
                  break;}
             
             default:
                  a = a;
                  break;
    }
    return ( a );
}

int ct(int a, int b, int c, char d)
{
    switch(d)
    {
             case ('P'):
                  {if(c >= 50)
                  {a ++;
                  return ( a );
                  break;}
                  else
                  {a = a;
                  return ( a );
                  break;}}
             case ('S'):
                  {if(c >= 100)
                  {b = b + 5;
                  return ( b );
                  break;}
                  else
                  {b = b;
                  return ( b );
                  break;}}
                

int main (void)
{
    char input;
    int a;
    printf("Press P to buy a health potion, or press S to buy a sword. > ");
    scanf("%c", &input);
    int gold = 500, ptn = 5, dmg = 10;
    int b = ct(ptn, dmg, gold, input);
    int a = gold(coin, input);
    printf("%d\n", a);
    system("PAUSE");
    return(0);
}
     
