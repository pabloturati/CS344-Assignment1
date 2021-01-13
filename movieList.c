#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movieList.h"
#include "constants.h"

struct movie *createMovieList(char *filePath)
{
  // Opens file for reading
  FILE *movieFile = fopen(filePath, "r");
  char *currLine = NULL;
  size_t len = 0;
  ssize_t nread;
  char *token;

  struct movie *head = NULL;
  struct movie *tail = NULL;

  // Read and ignore first line (header line)
  getline(&currLine, &len, movieFile);

  // Parse each line to linkedlist objects
  while ((nread = getline(&currLine, &len, movieFile)) != -1)
  {
    struct movie *newNode = createMovieNode(currLine);

    if (head == NULL)
    {
      head = newNode;
      tail = newNode;
    }
    else
    {
      tail->next = newNode;
      tail = newNode;
    }
  }
  free(currLine);
  return head;
}

struct movie *createMovieNode(char *currLine)
{
  struct movie *currMovie = malloc(sizeof(struct movie));

  // Pointer to curr strtok_r position
  char *rest;

  // Set title
  char *token = strtok_r(currLine, ",", &rest);
  currMovie->title = calloc(strlen(token) + 1, sizeof(char));
  strcpy(currMovie->title, token);

  // Set year
  token = strtok_r(NULL, ",", &rest);
  currMovie->year = atoi(token);

  // Set languages
  token = strtok_r(NULL, ",", &rest);
  currMovie->languages = calloc(strlen(token) + 1, sizeof(char));
  strcpy(currMovie->languages, token);

  // Set rating
  token = strtok_r(NULL, ",", &rest);
  currMovie->rating = strtof(token, NULL);

  // Set next movie ptr
  currMovie->next = NULL;
  return currMovie;
}

int *createUniqueMovieYearsArr(struct movie *head, int *size)
{
  int *uniqueYearArr = (int *)calloc(MOVIE_YEARS, sizeof(int));
  struct movie *curr = head;
  while (curr != NULL)
  {
    if (!arrayContainsValue(uniqueYearArr, *size, curr->year))
    {
      uniqueYearArr[*size] = curr->year;
      ++(*size);
    }
    curr = curr->next;
  }
  return uniqueYearArr;
}

void printMoviesWithHighestRatingsPerYear(struct movie *head, int *uniqueYears, int arrSize)
{
  for (int i = 0; i < arrSize; i++)
  {
    struct movie *curr = head;
    struct movie *highest = NULL;
    while (curr)
    {
      if (curr->year == uniqueYears[i])
      {
        if (highest == NULL)
        {
          highest = curr;
        }
        else if (curr->rating > highest->rating)
        {
          highest = curr;
        }
      }
      curr = curr->next;
    }
    printf("%d %.1f %s\n", uniqueYears[i], highest->rating, highest->title);
  }
  printf("\n");
}

void printMoviesOfCertainLanguage(struct movie *head, char *language)
{
  struct movie *curr = head;
  int count = 0;
  while (curr)
  {
    char *ptrToStrMatch = strstr(curr->languages, language);
    if (ptrToStrMatch != NULL)
    {
      printf("%d %s\n", curr->year, curr->title);
      ++count;
    }
    curr = curr->next;
  }
  if (count == 0)
  {
    printf(LANGUAGE_EMPTY_RECORDS_MSG, language);
  }
  else
  {
    printf(LANGUAGE_RECORDS_MSG, count, language);
  }
}

void filteMoviesByYear(struct movie *head)
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

size_t getListSize(struct movie *list)
{
  size_t listLength = 0;
  printf("Printing List\n");
  while (list != NULL)
  {
    // printf("%s\t", list->title);
    // printf("%d\t", list->year);
    // printf("%s\t", list->languages);
    // printf("%.1f\n", list->rating);
    list = list->next;
    ++listLength;
  }
  return listLength;
}