#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "movieList.h"

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

  int yearSize = 0;
  int *uniqueMovieYears = createUniqueMovieYearsArr(movieList, &yearSize);

  char *language = requestLanguageFromUser();
  printMoviesOfCertainLanguage(movieList, language);

  // User inteface handler
  // int option;
  // do
  // {
  //   puts(USER_OPTIONS);
  //   printf("%s", OPTION_PROMPT);
  //   scanf("%d", &option);

  //   switch (option)
  //   {
  //   case 1:
  //     filteMoviesByYear(movieList);
  //     break;
  //   case 2:
  //     printMoviesWithHighestRatingsPerYear(movieList, uniqueMovieYears, yearSize);
  //     break;
  //   case 3:
  //     requestLanguageFromUser();
  //     break;
  //   case 4:
  //     printf("%s", GOODBYE_MSG);
  //     return EXIT_SUCCESS;
  //     break;
  //   default:
  //     puts(INVALID_USER_INPUT_MSG);
  //   }
  // } while (TRUE);
}