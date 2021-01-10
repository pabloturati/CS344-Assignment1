#! /bin/bash

# Conditional cleanup space from previously compiled files
rm -f movies constants.o lib_movies.a

# Creates
gcc --std=c99 -c constants.c

# Creates external file archive
ar -r lib_movies.a constants.o

# Compiles main
gcc --std=c99 -o movies main.c lib_movies.a

# Removes temporary files
rm -f constants.o lib_movies.a

# REMVOE gcc --std=c99 -o test main.c constants.c
./movies movies_sample_1.csv
