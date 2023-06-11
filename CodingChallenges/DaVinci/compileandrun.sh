#!/bin/sh

# g++ -std=c++11 -pthread intro_threading.cpp
#g++ gmockTest.cpp -std=c++11 -lgtest -lgtest_main ++66++6 -pthread -o test
#RESULT=$( g++ -o exe $1 )

#RESULT=$( g++ -lpthread -o exe $1)
#RESULT=$( clang++ -std=c++11 -stdlib=libc++ -Weverything $1 ) #MACOS choice #1 with warnings
#RESULT=$(g++ -std=c++11 -stdlib=libc++ $1)

RESULT=$(g++ -std=c++20 $1 -o davinci)

sleep 1

#if [ -z $RESULT ]; then
#echo input001.txt >>davinci
#fi
