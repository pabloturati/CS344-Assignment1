#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movieList.h"

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