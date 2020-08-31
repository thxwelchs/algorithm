#!/bin/bash

set -e

if [[ $1 == "force" ]]; then
    rm -rf ./solving/*
    exit 0;
fi

grep -rEc "(백준|프로그래머스|leetcode)[ ][0-9]+[ ][0-9a-zA-Z가-힣ㄱ-ㅎㅏ-ㅣ_-]+|(etc)[ ][0-9a-zA-Z가-힣ㄱ-ㅎㅏ-ㅣ_-]+" ./solving | grep -E ':0' | sed 's/:0//' | xargs rm

find . -type d -empty -delete
find . -name "*.out.dSYM" | xargs rm -r
find . -name "*.out" | xargs rm

if [ ! -d "./solving" ]; then
    mkdir ./solving
fi


