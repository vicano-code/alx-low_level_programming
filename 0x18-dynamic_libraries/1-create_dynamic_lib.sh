#!/bin/bash

gcc -c -fPIC *.c
gcc -shared -fPIC -o liball.so *.o
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
