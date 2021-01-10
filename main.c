#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#define TRUE 1

struct movie
{
  char *title;
  unsigned short year;
  char *languages;
  float rating;
  struct movie *next;
};

struct movie *createMovieList(char *);
struct movie *createMovieNode(char *);
size_t getListSize(struct movie *);

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

  // Title
  char *token = strtok_r(currLine, ",", &rest);
  currMovie->title = calloc(strlen(token) + 1, sizeof(char));
  strcpy(currMovie->title, token);

  // Year
  token = strtok_r(NULL, ",", &rest);
  currMovie->year = atoi(token);

  // Languages
  token = strtok_r(NULL, ",", &rest);
  currMovie->languages = calloc(strlen(token) + 1, sizeof(char));
  strcpy(currMovie->languages, token);

  // Rating
  token = strtok_r(NULL, ",", &rest);
  currMovie->rating = strtof(token, NULL);

  // Set next movie ptr
  currMovie->next = NULL;
  return currMovie;
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