#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct {
  char user[16];
  char pass[16];
  char planet[16];
  int amount;
} add,check; //variable

// char *input_str;
// char *wormhole;
// char *wormhole2;

void new_traveler();
void loan();
void log_in();
void menu();

void new_traveler(void)
{
  FILE *ptr;
  ptr = fopen("data.dat", "a+");

  printf("\n\tDo you know that the Orian constellation is visible\
 throughout the local universe? ");
  printf("\n\n\t\t\t\tNew username: \n\n\n\n\n\n\n\n\n\n\t\t\t\t");
  scanf("%s", add.user);
  printf("\n\n\tAdded user: %s", add.user);
  printf("\n\n\t\tThe creatures near Betelgeuse remember their passwords.");
  printf("\n\n\t\t\t\tNew password: \n\n\n\n\n\n\n\n\n\n\t\t\t\t");
  scanf("%s", add.pass);
  printf("\n\tAdded pass: %s\t\t", add.pass);
  printf("\n\n\t\tThe black holes hold the answer to\
 the origin of the universe.");
  printf("\n\n\t\t\t\tNew planet: \n\n\n\n\n\n\n\n\n\n\t\t\t\t");
  scanf("%s", add.planet);
  printf("\n\tAdded planet: %s\t\t", add.planet);
  printf("\n\n\t\t\tPlease enter an int num, dear: ");
  printf("\n\n\t\t\tThe amount you want to loan: \n\n\n\n\n\n\n\n\n\n\t\t\t\t");

  // & val to pointer
  // "%d" int to arg
  scanf("%d", &add.amount);

  fprintf(ptr, "%s %s %s %d", add.user, add.pass, add.planet, add.amount);
  fclose(ptr);
  printf("\n\n\t\tYou're more than ready to do business with us.\n\n\n\n\n");

  loan();

}

void loan(void)
{
  int input_val;
  int loan_duration, rate, interest, total_amount, spaceship_amount;

  loan_duration = 1000000;
  rate = 1000;
  interest = (int)(add.amount * loan_duration * rate);
  total_amount = (int)(add.amount * interest);
  // total_amount = ceilf(add.amount * (1 + interest));
  spaceship_amount = (int)(add.amount / 100);
  // spaceship_amount = ceilf(add.amount / 1000000);

  printf("\n\t\tThe dimension you entered: ");
  printf("\n\n\t\t\t\t\t%d", add.amount);
  printf("\n\n\t\twill need %d", interest);
  printf(" interest amount to repay,\
  \n\n\t\twhich equals to 10,000,000 dogecoins.");
  printf("\n\n\t\tThe total amount will be %d", total_amount);
  printf(".\n\n\t\tThat is the equal worth of %d", spaceship_amount);
  printf(" spaceship(s) to build.\
  \n\n\t\tGo ahead with the engineering build.");
  printf("\n\n\n\t\tMore things coming up?\
  \n\n\t\t1.Go back to menu.\
  \n\t\t2.Exit.\n\n\n\n\n\n\n\t\t\t\t");

  scanf("%d", &input_val);
  if (input_val == 1) {
    menu();
  }
  else {
    exit(0);
  }

}

void log_in(void)
{
    FILE *ptr;
    ptr = fopen("data.dat", "w+");

    printf("\n\tDo you know that the Orian constellation is visible\
 throughout the local universe? ");
    printf("\n\n\t\t\tDear cutomer, please enter your space username: \n\n\n\n\n\n\n\n\n\n\t\t\t\t");
    scanf("%s", check.user);
    //placeholder for str
    //while (fscanf(ptr, "%s %s %s", add.user, add.pass, add.planet)!=EOF) {
    if (strcasecmp(add.user, check.user) == 0) {
      return_to_login:
      printf("\n\n\t\t\t\tWelcome back.");
      printf("\n\n\t\tThe creatures near Betelgeuse remember their passwords.");
      printf("\n\n\t\t\tDear cutomer, please enter your password: \n\n\n\n\n\n\n\n\n\n\t\t\t\t");
      scanf("%s", check.pass);
        if (strcasecmp(add.pass, check.pass) == 0) {
          return_to_last:
          printf("\n\n\t\tThe black holes hold the answer to\
 the origin of the universe.");
          printf("\n\n\t\tDear cutomer, please enter your planet:\n\n\n\n\n\n\n\n\n\n\t\t\t\t");
          scanf("%s", check.planet);
              if (strcasecmp(add.planet, check.planet) == 0) {
                printf("\n\n\t\t\t\tTime for business. \n\n\t\t\t\tLoading...\n\n\n\n\n\n\n\n\n\n\t\t\t\t");
                printf("\n\n\t\t\tThe amount you want to loan: \n\n\n\n\n\n\n\n\n\n\t\t\t\t");
                scanf("%d", &add.amount);
                fprintf(ptr, "%s %s %s %d", add.user, add.pass, add.planet, add.amount);
                fclose(ptr);
                loan();
              }
              else {
                fscanf(ptr, "%s", check.planet);
                fclose(ptr);
                printf("\n\n\t\tExoplanet creatures are called nomads here.\n");
                goto return_to_last;
              }
          }
          else {
            fscanf(ptr, "%s", check.pass);
            fclose(ptr);
            printf("\n\n\t\tThe black holes hold the answer to\
 the origin of the universe.\n");
            goto return_to_login;
          }
    }
    else {
      fscanf(ptr, "%s", check.user);
      fclose(ptr);
      printf("\n\n\t\tThe creatures near Betelgeuse\
 is plotting a rebellion against the universe system.\n");
      menu();
    }
}

void menu(void)
{
  int input_value;

  printf("\n\n\t\t\t\tSpace Grand Bank Program");
  printf("\n\n\tNow it's the one millionth\
 light year of you traveling thru the space,\
 \nand you run low on money for food.\
 Time to visit the only bank in the space\
 \n'Space Grand Bank', where you can loan\
 some money to build spaceships in\
 \nexchange for food. ");
  printf("\n\n\t\t\t1.LOGIN");
  printf("\n\t\t\t2.Fist time doing business with us?");
  printf("\n\n\t\t\tPlease enter the num, traveler: \n\n\n\n\n\n\n\n\n\n\t\t\t");
  scanf("%d", &input_value);

  switch (input_value) {

    case 1:
      log_in();
      break;
    case 2:
      new_traveler();
      break;
    default:
      printf("\n\n\t\t\tWe're running out of options but to exit.\n\n\n\n\n\n\n\n\n\n\t\t\t");
      exit(0);
      break;
  }
}



int main(void)
{
  menu();
}
