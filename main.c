#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "movieList.h"

void filteByYear(struct movie *head)
{
  unsigned short year;
  printf("%s", INPUT_YEAR_MSG);
  scanf("%hu", &year);
  printf(SELECTED_YEAR_MSG, year);

  size_t count = 0;
  struct movie *curr = head;
  while (curr != NULL)
  {
    if (curr->year == year)
    {
      printf("%s\n", curr->title);
      ++count;
    }
    curr = curr->next;
  }
  if (count == 0)
  {
    printf(NO_YEAR_RESULT_MSG, year);
  }
  else
  {
    printf(TOTAL_RECORDS_FOUND_IN_YEAR, count, year);
  }
}

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("%s", MISSING_FILE_PARAM_MSG);
    return EXIT_FAILURE;
  }

  struct movie *movieList = createMovieList(argv[1]);
  size_t size = getListSize(movieList);

  printf(LIST_CREATION_SUCCESS, argv[1], size);

  // User inteface handler
  int option;
  do
  {
    puts(USER_OPTIONS);
    printf("%s", OPTION_PROMPT);
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      filteByYear(movieList);
      break;
    case 2:
      printf("is two");
      break;
    case 3:
      printf("is three");
      break;
    case 4:
      printf("%s", GOODBYE_MSG);
      return EXIT_SUCCESS;
      break;
    default:
      puts(INVALID_USER_INPUT_MSG);
    }
  } while (TRUE);
}