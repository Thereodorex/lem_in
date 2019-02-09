#!/bin/bash
make
./generator/lem-in_gen $1 $2 > test.txt; cat test.txt | time ./lem-in