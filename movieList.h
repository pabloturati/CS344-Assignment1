#ifndef MOVIE_LIST
#define MOVIE_LIST

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

#endif