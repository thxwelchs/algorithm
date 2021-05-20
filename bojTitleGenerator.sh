#!/bin/bash

for file in $(ls ./백준 | grep -e "^\d"); do
 PROBLEM_NUMBER=$(echo $file | grep -oEi '^\d+')
 PROBLEM_TITLE=$(curl "https://www.acmicpc.net/problem/$PROBLEM_NUMBER" | grep "problem_title" | sed 's/<\/*[^>]*>//g' | sed 's/ - //g' | sed 's/[$&+,:;=?@#|<>.^*()%!-]//g' | sed 's/[ ]//g')

 mv ./백준/$file $PROBLEM_NUMBER"_"$PROBLEM_TITLE

done

