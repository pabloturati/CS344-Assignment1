#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"

// User interface messages
char *MISSING_FILE_PARAM_MSG = "Missing file to read\n";
char *LIST_CREATION_SUCCESS = "Processed file %s and parsed data for %zu movies\n\n";
char *USER_OPTIONS = "1. Show movies released in the specified year.\n2. Show highest rated movie for each year.\n3. Show the title and year of release of all movies in a specific language.\n4. Exit from the program.\n";
char *OPTION_PROMPT = "Enter a choice from 1 to 4: ";
char *INVALID_USER_INPUT_MSG = "\nYou entered an incorrect choice. Try again.\n";
char *GOODBYE_MSG = "Thank you, good bye!\n";

// Year inputs
char *INPUT_YEAR_MSG = "Enter the year for which you want to see movies: ";
char *NO_YEAR_RESULT_MSG = "No data about movies released in the year %hu\n\n";
char *SELECTED_YEAR_MSG = "You selected %hu\n\n";
char *TOTAL_RECORDS_FOUND_IN_YEAR = "\n%hu total records found in year %hu\n\n";

// Language inputs
char *INPUT_LANGUAGE = "Enter the language for which you want to see movies:";
char *LANGUAGE_CONFIRM_MSG = "You selected %s.\n\n";
char *LANGUAGE_RECORDS_MSG = "\nFound %d records in %s\n";
char *LANGUAGE_EMPTY_RECORDS_MSG = "No data about movies released in %s\n\n";

int arrayContainsValue(int *arr, int arrSize, int val)
{
  for (int i = 0; i < arrSize; i++)
  {
    if (arr[i] == val)
      return 1;
  }
  return 0;
}

char *requestLanguageFromUser()
{
  char *language = (char *)calloc(MAX_LANGUAGE_LENGTH + 1, sizeof(char));
  printf("%s", INPUT_LANGUAGE);
  scanf("%s", language);
  printf(LANGUAGE_CONFIRM_MSG, language);
  return language;
}

int hasRequiredParams(int argc)
{
  if (argc < 2)
  {
    printf("%s", MISSING_FILE_PARAM_MSG);
    return 0;
  }
  return 1;
}

int promptUserForOption()
{
  int option;
  puts(USER_OPTIONS);
  printf("%s", OPTION_PROMPT);
  scanf("%d", &option);
  return option;
}