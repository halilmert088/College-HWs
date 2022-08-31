#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

static char d1 [] = "NORTH";
static char d2 [] = "SOUTH";
static char d3 [] = "EAST";
static char d4 [] = "WEST";
static char d0 [] = "MENU";
static char shutdown [] = "EXIT";
char name [];
char cmd [];
char move [];
char convo [];

int health = 100;
int level = 1;
int xp = 0;
int health_pot = 0;
int mana_pot = 0;
int money = 250;
int defense = 0;
int atk = 10;

void menu (void);
void mainmenu (void);
void start (void);
void movement (void);

int main (void)
{
     start();
     printf("%s\n", name);
     system("PAUSE");
     return(0);
}

void start (void)
{
     printf("Hello there! Please enter your name : ");
     scanf("%s", &name);
}

void movement (void)
{
     do
     {
          printf("Which way would you like to go?");
          printf("\n> ");
          scanf("%s", &move);
          if (strcmp (move, d1) == 0)
          printf("You head north\n\n");
          else if (strcmp(move, d2) == 0)
          printf("You head south\n\n");
          else if (strcmp(move, d3) == 0)
          printf("You head east\n\n");
          else if (strcmp(move, d4) == 0)
          printf("You head west\n\n");
          else if (strcmp (move, d0) == 0)
          menu();
     } while (strcmp (move, shutdown) != 0);
     
     mainmenu();
     
}

void menu (void)
{
     int select;
     printf("1 - Stats\n");
     printf("2 - Resume\n\n");
     printf("> ");
     scanf("%d", &select);
     if("select == 1")
     {
          printf("Name : %s\n", name);
          printf("Health : %d\n", health);
          printf("Damage : %d\n", atk);
          printf("Level : %d\n", level);
          printf("Current XP: %d\n", xp);
          printf("XP until next level : %d\n" (level * 100) - xp);
     }
}