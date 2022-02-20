#! /bin/sh

BASEDIR=$(dirname "$0")

g++ -std=c++17 ${BASEDIR}/prob/$1.cpp -o ${BASEDIR}/binary/$1

