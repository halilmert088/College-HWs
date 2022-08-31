#include <stdio.h>
#include <stdlib.h>

int level (int a, int b)
{
  if ( (a) >= ( b * 100 ) )
  {
       a = a - ( a * 100 );
       b++;
       printf("Congratulations! You have leveled up to level %d!\n", b);
  }
  
  return (b);
}

int main (void)
{
    int lvl = level (9000, 90);  
    system("PAUSE");
    return(0);
}
