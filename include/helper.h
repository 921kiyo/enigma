#ifndef HELPER_H
#define HELPER_H

// Is this necessary??
#include <iostream>
using namespace std;

int getArrayLength(const char* path);

void mapInputToArray(const char* path, int* array);

bool isNumberRangeCorrect(int num);

bool isDuplicateInt(int* array, int range);

bool isAppearedBefore(int* array, int num, int length);

#endif
