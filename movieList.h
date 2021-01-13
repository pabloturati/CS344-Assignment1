#ifndef MOVIE_LIST
#define MOVIE_LIST

struct movie
{
  char *title;
  int year;
  char *languages;
  float rating;
  struct movie *next;
};

struct movie *createMovieList(char *);
struct movie *createMovieNode(char *);
size_t getListSize(struct movie *);
int *createUniqueMovieYearsArr(struct movie *, int *);
void printMoviesWithHighestRatingsPerYear(struct movie *, int *, int);
void filteMoviesByYear(struct movie *);
void printMoviesOfCertainLanguage(struct movie *, char *language);

#endif