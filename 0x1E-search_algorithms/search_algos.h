#ifndef __SEARCH_ALGOS__
#define __SEARCH_ALGOS__

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);

#endif
