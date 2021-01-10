#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "movieList.h"

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("Missing file to read");
    return EXIT_FAILURE;
  }

  struct movie *movieList = createMovieList(argv[1]);
  size_t size = getListSize(movieList);

  printf("Processed file %s and parsed data for %zu movies\n\n", argv[1], size);

  int option;
  do
  {
    puts(USER_OPTIONS);
    printf("%s", OPTION_PROMPT);
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      printf("is one");
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
  return EXIT_FAILURE;
}