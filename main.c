#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"

struct movie
{
  char *title;
  short year;
  // char *languages[MAX_NUMBER_OF_LANGUAGES];
  // float rating;
  struct movie *next;
};

struct movie *createMovieList(char *);
struct movie *createMovie(char *);

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

  // For use with strtok_r
  char *rest;

  // Title
  char *token = strtok_r(currLine, ",", &rest);
  currMovie->title = calloc(strlen(token) + 1, sizeof(char));
  strcpy(currMovie->title, token);

  // Year
  token = strtok_r(NULL, ",", &rest);
  currMovie->year = atoi(token);

  // Set next movie ptr
  currMovie->next = NULL;

  return currMovie;
}

void printList(struct movie *list)
{
  printf("Printing");
  while (list != NULL)
  {
    printf("Title:  %s", list->title);
    printf("Year:  %d", list->year);
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