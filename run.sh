#! /bin/bash

rm -f movies constants.o lib_movies.a
gcc --std=c99 -c constants.c
ar -r lib_movies.a constants.o
gcc --std=c99 -o movies main.c lib_movies.a
rm -f movies constants.o lib_movies.a

# gcc --std=c99 -o test main.c constants.c
