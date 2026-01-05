#!/bin/bash
echo "8 9 * 9 - 9 - 9 - 4 - 1 +"
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
echo $''
echo "7 7 * 7 -"
./RPN "7 7 * 7 -"
echo $''
echo "1 2 * 2 / 2 * 2 4 - +"
./RPN "1 2 * 2 / 2 * 2 4 - +"
echo $''
echo "(1 + 1)"
./RPN "(1 + 1)"
echo $''
echo "1 + 1"
./RPN "1 + 1"
echo $''
echo "1 +"
./RPN "1 +"
echo $''
echo "1 1 +"
./RPN "1 1 +"
echo $''
echo "+ 1"
./RPN "+ 1"
echo $''
echo "1 2 + 3"
./RPN "1 2 + 3"
echo $''
echo "1 2 3"
./RPN "1 2 3"
