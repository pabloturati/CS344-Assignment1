#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"

struct movie
{
  char *title;
  int year;
  char *str;
  float rating;
  struct movie *next;
};

int main(int argc, char *argv[])
{
  // if (argc < 2)
  // {
  //   printf("Missing file to process");
  //   return EXIT_FAILURE;
  // }

  printf("%d", MAX_NUMBER_OF_LANGUAGES);
  return 0;
}