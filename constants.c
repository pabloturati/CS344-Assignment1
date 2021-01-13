// User interface messages

char *MISSING_FILE_PARAM_MSG = "Missing file to read\n";
char *LIST_CREATION_SUCCESS = "Processed file %s and parsed data for %zu movies\n\n";
char *USER_OPTIONS = "1. Show movies released in the specified year.\n2. Show highest rated movie for each year.\n3. Show the title and year of release of all movies in a specific language.\n4. Exit from the program.\n";
char *OPTION_PROMPT = "Enter a choice from 1 to 4: ";
char *INVALID_USER_INPUT_MSG = "************************************\nInvalid input. Please select a valid option\n************************************\n";
char *GOODBYE_MSG = "Thank you, good bye!\n";

// Year inputs
char *INPUT_YEAR_MSG = "Enter the year for which you want to see movies: ";
char *NO_YEAR_RESULT_MSG = "No data about movies released in the year %hu\n\n";
char *SELECTED_YEAR_MSG = "You selected %hu\n\n";
char *TOTAL_RECORDS_FOUND_IN_YEAR = "\n%hu total records found in year %hu\n\n";

int arrayContainsValue(int *arr, int arrSize, int val)
{
  for (int i = 0; i < arrSize; i++)
  {
    if (arr[i] == val)
      return 1;
  }
  return 0;
}
