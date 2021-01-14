#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "movieList.h"

int main(int argc, char *argv[])
{
  if (!hasRequiredParams(argc))
  {
    return EXIT_FAILURE;
  }

  struct movie *movieList = createMovieList(argv[1]);

  if (!listHasContent(movieList, argv[1]))
  {
    return EXIT_FAILURE;
  }

  // Create array of unique movie years
  int yearSize = 0;
  int *uniqueMovieYears = createUniqueMovieYearsArr(movieList, &yearSize);

  // User inteface handler
  char *language;
  int option;
  do
  {
    option = promptUserForOption();
    switch (option)
    {
    case 1:
      filteMoviesByYear(movieList);
      break;
    case 2:
      printMoviesWithHighestRatingsPerYear(movieList, uniqueMovieYears, yearSize);
      break;
    case 3:
      language = requestLanguageFromUser();
      printMoviesOfCertainLanguage(movieList, language);
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