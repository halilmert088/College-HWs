#include <stdio.h>
#include <stdlib.h>

int health_init = 100;
int damage_init = 10;
int pot_init = 5;
int level_init = 1;
int xp_init = 0;
int gold_init = 500;
int comp_health; 
int comp_damage; 
int comp_heal;
int comp_mana;
char companion = 'N';

void assign (void)
{
     companion = 'Y';
     comp_health = 74 + level_init;
     comp_damage = 9 + level_init;
     comp_heal = 49 + level_init;
     comp_mana = 99 + level_init;
}

void pot_shop(void)
{
     int price = 10 * level_init;
     char a;
     printf("You enter the potion shop. You greet the raven haired woman with a nod and look at the potions on the wall.\nWould you like to buy a healing potion for %d gold?\tCurrent gold: %d\n>", price, gold_init);
     scanf(" %c", &a);
     
     while (( a != 'Y') && (a != 'N'))
          {
                printf("You need to decide if you want to buy a potion or not. > ");
                scanf(" %c", &a);
          }
     
     while ( (a == 'Y') && (gold_init >= price) )
     {
         gold_init = gold_init - price;
         pot_init++;
         price = price + 5;
         printf("Your potions have increased to %d!\n", pot_init);
         printf("Would you like to buy a healing potion for %d gold?\tCurrent gold: %d\n>", price, gold_init);
         scanf(" %c", &a);
         
         while (( a != 'Y') && (a != 'N'))
          {
                printf("You need to decide if you want to buy a potion or not. > ");
                scanf(" %c", &a);
          }
     }
     
     if  ( (a == 'Y') && (gold_init < price) )
     {
          printf("Insufficent gold.\n");
     }
     
     else if ( (a == 'N') )
     {
          printf("You decide not to buy anything and leave the store.");
     }
}

void loot (void)
{
     char b;
     srand (time(0));
     int a = rand () % 3 + 1;
     int stat = (rand() % ((2 * damage_init) - damage_init + 1)) + damage_init;
     int gold = (rand() % (50 - 25 + 1)) + 25;  
     switch (a)
     {
            case(0):
                    {printf("You found a sword that does %d damage.\n Would you like to equip the sword?\tCurrent damage : %d\n>", stat, damage_init);
                    scanf(" %c", &b);
                    
                    if ( b == 'Y')
                    {damage_init = damage_init + stat;
                    printf("You have equipped the sword.\tCurrent damage : %d.\n", damage_init);
                    break;}
                    
                    else if ( b == 'N')
                    {printf("You didn't equip the sword.\tCurrent damage : %d.\n", damage_init);
                    break;}
                    
                    }
            
            case (1):
                 {gold_init = gold_init + gold;
                 printf("You found a pouch with %d gold in it!\tCurrent gold : %d.\n", gold, gold_init);
                 break;}
                 
            case (2):
                 {pot_init++;
                 printf("You found a healing potion!\tCurrent potions: %d.\n", pot_init);
                 break;}
                 
            case (3):
                 {break;}
     }
}

void town(void);
void blacksmith(void)
{
     char a;
     int price = 200 * level_init;
     int stat = 2 * level_init;
     printf("You enter the blacksmith. Town's local blacksmith greets you from the anvil he's working at. You take a glance at the swords hanged on the wall.\nWould you like to buy a sword for 200 gold?\tCurrent gold: %d\n>", gold_init);
     scanf(" %c", &a);
     
     while (( a != 'Y') && (a != 'N'))
     {
           printf("You need to decide if you want to buy a sword or not. > ");
           scanf(" %c", &a);
     }
     
     while( (a == 'Y') && (gold_init >= price) )
     {
         gold_init = gold_init - price;
         damage_init = damage_init + stat;
         price = price + 50;
         printf("Your damage has increased to %d!\n", damage_init);
         printf("Would you like to buy a sword for %d gold?\tCurrent gold: %d\n>", price, gold_init);
         scanf(" %c", &a);
         
         while (( a != 'Y') && (a != 'N'))
         {
           printf("You need to decide if you want to buy a sword or not. > ");
           scanf(" %c", &a);
         }
     
     }
     
     if  ( (a == 'Y') && (gold_init < price) )
     {
          printf("Insufficent gold.\n");
     }
     
     if ( (a == 'N') )
     {
          printf("You decide not to buy anything and leave the store.");
     }
     
}

void movement (char a);
void forest (int a);
void town_hub (char a)
{
     char b;
     switch(a)
     {
              case('N'):
              {
              printf("You arrive at the town's blacksmith. Would you like to enter? >");
              scanf(" %c", &b);
              
              if (b == 'Y')
              {blacksmith ();
              break;}
              
              else if (b == 'N')
              {town ();
              break;}
              
              else
              {printf("You need to decide if you want to go in or not.\nWould you like to go in? >");
              scanf(" %c", &b);
              break;}
              }
              
              case('S'):
              {
              printf("You arrive at the potion shop. Would you like to enter? > ");
              scanf(" %c", &b);
              
              if( b == 'Y')
              {pot_shop();
              break;}
              
              else if ( b == 'N')
              {town();
              break;}
              
              else
              {printf("You need to decide if you want to go in or not.\nWould you like to go in? > ");
              scanf(" %c", &b);
              break;}
              }
              
              case('E'):
              {
              printf("You arrive at the local tavern. Would you like to go in? >");
              scanf(" %c", &b);
              
              if( b == 'Y' )
              {
              printf("You enjoy a pint of beer and some hot food, then head out again.");
              break;
              }
              
              else if ( b == 'N')
              {town();
              break;}
              
              else
              {printf("You need to decide if you want to go in or not.\nWould you like to go in? > ");
              scanf(" %c", &b);
              break;}
              }
              
              case('W'):
                        {
                        if(companion == 'N')
                        {printf("You see Beyza. She wants to travel with you. Do you accept? >");
                         scanf(" %c", &b);
                         
                         if(b == 'Y')
                         {printf("Beyza is now travelling with you.\n");
                         assign();
                         break;}
                         
                         else
                         {printf("Beyza isn't travelling with you.\n");
                         break;}}
                         
                         else if (companion == 'Y')
                         {printf("You see nothing interesting...\n");
                         break;}
                         
                         }
                        
              default:
                      {printf("You just stay stationary...\n\n");
                      printf("Which way would you like to go? >");
                      scanf(" %c", &a);}
     }
}

void town (void)
{
     char dir, k;
     printf("You are in the town now.\nWhere do you want to go? > ");
     scanf(" %c", &dir);
     
     while ((dir != 'Q') &&  (dir != 'K'))
     {movement(dir);
     town_hub(dir);
     printf("You are in the town now.\nWhere do you want to go? > ");
     scanf(" %c", &dir); }
     
     if (dir == 'Q')
     {printf("You head out of town to the jungle...\n");
     forest(level_init);}
     
     else if (dir == 'K')
     {printf("Are you sure you want to exit the game? > ");
     scanf(" %c", &k);
     
     if(k == 'Y')
     {printf("Bye :)\n");
     system("PAUSE");
     exit (0);}
     
     else
     town();}
}

void forest (int a)
{
    char dir, dng;
    int k;
    printf("Where would you like to go? > ");
    scanf(" %c", &dir);
    do
    {
    movement(dir);
    srand (time(0));
    k = rand () % 2 + 1;
    
     if ( k == 0 )
     {
          printf("You found a healing potion! In the roads, nontheless...\n\n");
          pot_init++;
     }
     
     else if ( k == 1 )
     {
          printf("You found a dungeon! Would you like to enter the dungeon? > ");
          scanf(" %c", &dng);
           
           if (dng == 'Y')
           {
              a = dungeon (pot_init, a);
           }
           
           else if (dng == 'N')
           printf("You didn't enter the dungeon and kept walking..."); 
           
           while ( (dng != 'Y') && (dng != 'N') )
           {
                 printf("You just stand at the entrance of the dungeon (not sure why)\nWould you like to enter the dungeon? > ");
                 scanf(" %c", &dng);
           }
      }
      
      else if ( k == 2 )
      {       
              srand (time(0));
              int ct = rand () % 2 + 1;
              
              int z = combat(playerhealth (level_init, health_init) , health_init, pot_init, playerdamage (level_init,damage_init), ct);
              xp_init = xp_init + z;
              
              if ( z == 0 )
              printf("You didn't gain any XP!\n");
              else if ( z > 0 )
              {printf("You gained %d XP!\n\n", z);
              loot();
              a = level (xp_init, a);
              if ((a) =! (level_init))
              xp_init = level_xp (xp_init, level_init);}
      
      }
      
    printf("Where would you like to go? > ");
    scanf(" %c", &dir);         
    
    } while (dir != 'Q');
    
    printf("You returned to the town...\n");
    system("PAUSE");
    return ( town ());
}

int xp_gain (int a, char b)
{
    int xpgain;
    switch (b)
    {
           case('G'):
                     xpgain = (20 * a);
                     break;
           case('U'):
                     xpgain = (40 * a);
                     break;
           case('O'):
                     xpgain = (80 * a);
                     break;
           case('L'):
                     xpgain = (160 * a);
                     break;
           default:
                   xpgain = 100;
                   break;
                   
    }
    return (xpgain);
}
                     
int playerdamage(int a, int b)
{
    if ( a > 1 )
    {b = b + a;
    return(b);}
    else if (a == 1)
    return (b);
}
int combat(int a, int c, int d, int e, int h);
int dungeon(int b, int c);
void message(char a, int b);

int level (int a, int b)
{
     if ( (a) >= ( b * 100 ) )
     {
          a = (a) - (b * 100);
          b++;
          printf("Congratulations! You leveled up to level %d\n\n", b);
     }
     
     return (b);
}

int playerhealth (int a, int b)
{
    if ( a > 1 )
    {b = b + (10 * a);
    return (b);}
    else if ( a == 1)
    return (b);
}

int level_xp (int a, int b)
{
     if ( (a) >= ( b * 100 ) )
     {
          a = (a) - (b * 100);
     }
     
     return (a);
}

void movement (char a)
{
     switch(a)
       {
                case ('N'):

                printf("You head north...\n\n");
                break;


                case ('S'):

                printf("You head south...\n\n");
                break;


                case ('E'):

                printf("You head east...\n\n");
                break;


                case ('W'):

                printf("You head west...\n\n");
                break;

                case('Q'):
                printf("You have walked away...\n\n");
                break;

                default:

                printf("You stay at where you are (not sure why...)\n");
                break;

       }
}

void encounter_message(char a, int b)
{
     switch(a)
     {
              case('G'):
                        if( b > 1 )
                        {printf("You have encountered %d goblins!\n", b);
                        break;}
                        else if( b == 1 )
                        {printf("You have encountered a goblin!\n");
                        break;}
              case('U'):
                        if( b > 1 )
                        {printf("You have encountered %d undead soldiers!\n", b);
                        break;}
                        else if( b == 1 )
                        {printf("You have encountered an undead soldier!\n");
                        break;}
              case('O'):
                        if( b > 1 )
                        {printf("You have encountered %d goblin overlords!\n", b);
                        break;}
                        else if( b == 1)
                        {printf("You have encountered a goblin overlord!\n");
                        break;}
              case('L'):
                        if( b > 1 )
                        {printf("You have encountered %d undead lieutenants!\n", b);
                        break;}
                        else if( b == 1 )
                        {printf("You have encountered an undead lieutenant!\n");
                        break;}
     }
}

int type_damage(char a)
{
     int damage;
     switch(a)
     {
              case('G'):
                        damage = 5;
                        break;
              case('U'):
                        damage = 10;
                        break;
              case('O'):
                        damage = 15;
                        break;
              case('L'):
                        damage = 20;
                        break;
     }
     
     return(damage);
}
int type_health(char a)
{
     int health;
     switch(a)
     {
              case('G'):
                        health = 50;
                        break;
              case('U'):
                        health = 100;
                        break;
              case('O'):
                        health = 150;
                        break;
              case('L'):
                        health = 200;
                        break;
     }
     
     return(health);
}
                        
int main (void)
{
    char enter;
    printf("Welcome to my beta test for an unnamed project!. \n");
    town () ;
    return (0);
}

int combat(int a, int c, int d, int e, int h)
{
     int g;
     char type;
     type = "GUOL"[rand () % 4];
     int b = type_health(type);
     int f = type_damage(type);
     encounter_message (type, h);
     int j = h;
     while((a > 0) && (b > 0) && (h != 0))
     {
              srand (time(0));
              int playerluck = rand () % 100 + 1;
              int enemyluck = rand () % 100 + 1;
              printf("\nPlayer health: %d\tEnemy health: %d\n", a, b);
              printf("1 - Light attack : Low damage, high chance to hit\t2 - Strong attack : Higher damage, higher chance to miss\n3 - Healing potion: Restore a portion of your health\t 4 - Flee: Run away from the fight\n> ");
              scanf("%d", &g);
              
              switch (g)
              {
                     case (1):

                              if ((playerluck > 15) && (playerluck <=100))
                              {printf("You strike the enemy and deal %d damage!\n", e);
                              b = b - e;
                              break;}
                              else if ((playerluck <= 15))
                              {printf("You missed!\n");
                              break;}

                     case (2) :

                              if((playerluck > 35) && (playerluck <= 100))
                              {printf("You strike the enemy and deal %d damage!\n", e * 2);
                              b = b - (e * 2);
                              break;}
                              else if ((playerluck <= 35))
                              {printf("You missed!\n");
                              break;}

                     case (3) :

                              {

                               if ( d == 0 )
                               {
                                    printf("You don't have any potions left!\n");
                                    break;
                               }
                               else if ( a == c )
                               {
                                    printf("You are already at max health!\n");
                                    break;
                               }
                               else
                               {
                                   printf("You used a healing potion!\n");
                                   d--;
                                   a = a + 20;
                                   break;
                               }

                              }
                              
                              case(4):
                                        {printf("You ran away...\n");
                                        return (0);
                                        break;}
                              
                              default:

                                  printf("You didn't make any moves this turn, now its the enemy's turn to strike!\n");
                                  break;
              }

              if((enemyluck > 20) && (enemyluck <= 100))
              {printf("The enemy strikes you and deals %d damage!\n", f);
              a = a - f;}
              
              else if((enemyluck <= 20))
              printf("The enemy missed!\n"); 

              if((b <= 0) && (h > 0) && (a != 0))
              {
                    b = type_health(type);
                    h--;
                    
                    if( h > 1 )
                    printf("%d enemies left!\n", h);
                    else if( h == 1 )
                    printf("%d enemy left!\n", h);
              }
     }
     
     if ( a <= 0 )
     {
          printf("DEFEAT\n");
          printf("GAME OVER :(\n");
          system("PAUSE");
          exit (0);
     }
     
     else if ( (b <= 0) && (h == 0) )
     printf("VICTORY!\n\n");
     
     return(xp_gain (j, type));
}

int dungeon (int b, int c)
{
     int a, ct, pot_count, gold_count;
     char dir;
     
do{
     printf("Which direction would you like to go? > ");
     scanf(" %c", &dir);
     movement (dir); 

       if (dir != 'Q')
       {
       srand (time(0));
       ct = rand () % 2 + 1;
       a = rand () % 3 + 1;
       pot_count = rand () % 9 + 1;
       gold_count = rand () % 12 + 1;

       if ( a == 1 )
       {
          printf("You found a healing potion!\n\n");
          pot_init++;
          pot_count--;
          
          if (pot_count == 0)
          {
                        printf("You have found all the potions in this dungeon!\n\n");
          }
          
       }
       
       else if ( a == 2 )
       {
          if( ct != 0 )
          {
              int k = combat(playerhealth (c, health_init) , health_init, pot_init, playerdamage (c,damage_init), ct);
              xp_init = xp_init + k;
              
              if(k == 0)
              printf("You didn't gain any XP!\n");
              else if ( k > 0 )
              {printf("You gained %d XP!\n\n", k);
              loot ();
              int lvl = c;
              c = level (xp_init, c);
              if ((lvl) =! (c))
              xp_init = level_xp (xp_init, c);}
          }

          else
          printf("You found an enemy corpse. This is worrying...\n\n");
       }
       
       else if ( a == 3 )
       {
            if(gold_count > 0)
            {
                          printf("You found a pouch full of gold!\n");
                          gold_init = gold_init + 50;
                          gold_count--;
                          printf("Current gold: %d\n", gold_init);
            }
       }
       }
       
} while (dir != 'Q');

     system("PAUSE");
     return (c);
}
