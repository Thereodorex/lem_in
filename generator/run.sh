#!/bin/bash
make
for (( a = 1; a < $1; a++ ))
do
for (( b = 2; b < $2; b++ ))
do
echo "ANT = $a NODE = $b"
./generator/lem-in_gen $a $b > test$a+$b.txt; cat test$a+$b.txt | ./lem-in
echo ""
done
done