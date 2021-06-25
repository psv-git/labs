#! /bin/bash

SRC=$(find ./src/ -name *.cpp)
HDR=$(find ./src/ -name *.hpp)

for file in $SRC
do
  clang-format -i -style=file $file
done

for file in $HDR
do
  clang-format -i -style=file $file
done
