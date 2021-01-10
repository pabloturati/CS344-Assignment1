#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"

struct movie
{
  char *title;
  unsigned short year;
  char *languages;
  float rating;
  struct movie *next;
};

struct movie *createMovieList(char *);
struct movie *createMovie(char *);
void printList(struct movie *);

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
    struct movie *newNode = createMovie(currLine);

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

struct movie *createMovie(char *currLine)
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
  printf("%s\n", token);
  currMovie->languages = calloc(strlen(token) + 1, sizeof(char));
  strcpy(currMovie->languages, token);

  // Rating
  token = strtok_r(NULL, ",", &rest);
  currMovie->rating = strtof(token, NULL);

  // Set next movie ptr
  currMovie->next = NULL;
  return currMovie;
}

void printList(struct movie *list)
{
  printf("Printing List\n");
  while (list != NULL)
  {
    printf("%s\t", list->title);
    printf("%d\t", list->year);
    printf("%s\t", list->languages);
    printf("%.1f\n", list->rating);
    list = list->next;
  }
}

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("Missing file to process");
    return EXIT_FAILURE;
  }

  struct movie *movieList = createMovieList(argv[1]);
  printList(movieList);
  return EXIT_SUCCESS;
}