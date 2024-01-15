#!/bin/bash

gcc -c -fPIC *.c
gcc -shared -fPIC -o liball.so *.o
